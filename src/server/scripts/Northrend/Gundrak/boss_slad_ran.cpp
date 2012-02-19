/*
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008 - 2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "gundrak.h"

//Spells
enum Spells
{
    SPELL_POISON_NOVA                             = 55081,
    H_SPELL_POISON_NOVA                           = 59842,
    SPELL_POWERFULL_BITE                          = 48287,
    H_SPELL_POWERFULL_BITE                        = 59840,
    SPELL_VENOM_BOLT                              = 54970,
    H_SPELL_VENOM_BOLT                            = 59839
};

//Yell
enum Yells
{
    SAY_AGGRO                                     = -1604000,
    SAY_SUMMON_SNAKES                             = -1604001,
    SAY_SUMMON_CONSTRICTORS                       = -1604002,
    SAY_SLAY_1                                    = -1604003,
    SAY_SLAY_2                                    = -1604004,
    SAY_SLAY_3                                    = -1604005,
    SAY_DEATH                                     = -1604006,
    EMOTE_NOVA                                    = -1604007
};

//Creatures
enum Creatures
{
    CREATURE_SNAKE                                = 29680,
    CREATURE_CONSTRICTORS                         = 29713,
    CREATURE_SNAKE_WRAP                           = 29742
};

//Creatures' spells
enum ConstrictorSpells
{
    SPELL_GRIP_OF_SLAD_RAN                        = 55093,
    SPELL_SNAKE_WRAP                              = 55099,
    SPELL_SNAKE_WRAP_STUN                         = 55126,
    SPELL_VENOMOUS_BITE                           = 54987,
    H_SPELL_VENOMOUS_BITE                         = 58996
};

enum Achievements
{
    ACHIEV_SNAKES                                 = 2058
};

static Position SpawnLoc[]=
{
  {1783.81f, 646.637f, 133.948f, 3.71755f},
  {1775.03f, 606.586f, 134.165f, 1.43117f},
  {1717.39f, 630.041f, 129.282f, 5.96903f},
  {1765.66f, 646.542f, 134.02f,  5.11381f},
  {1716.76f, 635.159f, 129.282f, 0.191986f}
};

class boss_slad_ran : public CreatureScript
{
public:
    boss_slad_ran() : CreatureScript("boss_slad_ran") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_slad_ranAI (creature);
    }

    struct boss_slad_ranAI : public ScriptedAI
    {
        boss_slad_ranAI(Creature* c) : ScriptedAI(c), lSummons(me)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 uiPoisonNovaTimer;
        uint32 uiPowerfullBiteTimer;
        uint32 uiVenomBoltTimer;
        uint32 uiSpawnTimer;

        uint8 uiPhase;

        std::set<uint64> lUnWrappedPlayers;

        SummonList lSummons;

        InstanceScript* pInstance;

        void Reset()
        {
            uiPoisonNovaTimer = 10*IN_MILLISECONDS;
            uiPowerfullBiteTimer = 3*IN_MILLISECONDS;
            uiVenomBoltTimer = 15*IN_MILLISECONDS;
            uiSpawnTimer = 5*IN_MILLISECONDS;
            uiPhase = 0;

            lSummons.DespawnAll();
            lUnWrappedPlayers.clear();

            if (pInstance)
                pInstance->SetData(DATA_SLAD_RAN_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
            {
                pInstance->SetData(DATA_SLAD_RAN_EVENT, IN_PROGRESS);

            Map::PlayerList const &players = pInstance->instance->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                lUnWrappedPlayers.insert(itr->getSource()->GetGUID());
            }
        }

        void GotWrapped(Unit* unit)
        {
            if (unit && unit->GetTypeId() == TYPEID_PLAYER)
                lUnWrappedPlayers.erase(unit->GetGUID());
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiPhase)
            {
                if (uiSpawnTimer <= diff)
                {
                    if ((uiPhase == 1) || (uiPhase == 2))
                        for (uint8 i = 0; i < DUNGEON_MODE(1, 2); ++i)
                            me->SummonCreature(CREATURE_SNAKE, SpawnLoc[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN,1*IN_MILLISECONDS);
                    if (uiPhase == 2)
                        for (uint8 i = 0; i < DUNGEON_MODE(1, 2); ++i)
                            me->SummonCreature(CREATURE_CONSTRICTORS, SpawnLoc[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN,1*IN_MILLISECONDS);
                    uiSpawnTimer = 10000;
                } else uiSpawnTimer -= diff;
            }

            if (uiPhase == 0 && HealthBelowPct(90))
            {
                DoScriptText(SAY_SUMMON_SNAKES,me);
                uiPhase = 1;
            }

            if (uiPhase == 1 && HealthBelowPct(75))
            {
                DoScriptText(SAY_SUMMON_CONSTRICTORS,me);
                uiPhase = 2;
            }

            // do not interrupt self
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (uiPoisonNovaTimer <= diff)
            {
                DoCast(me->getVictim(), DUNGEON_MODE(SPELL_POISON_NOVA, H_SPELL_POISON_NOVA));
                DoScriptText(EMOTE_NOVA,me);
                uiPoisonNovaTimer = 23*IN_MILLISECONDS;
            } else uiPoisonNovaTimer -= diff;

            if (uiPowerfullBiteTimer <= diff)
            {
                DoCast(me->getVictim(), DUNGEON_MODE(SPELL_POWERFULL_BITE, H_SPELL_POWERFULL_BITE));
                uiPowerfullBiteTimer = 10*IN_MILLISECONDS;
            } else uiPowerfullBiteTimer -= diff;

            if (uiVenomBoltTimer <= diff)
            {
                DoCast(me->getVictim(), DUNGEON_MODE(SPELL_VENOM_BOLT, H_SPELL_VENOM_BOLT));
                uiVenomBoltTimer = 10*IN_MILLISECONDS;
            } else uiVenomBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            AchievementEntry const *achievSnakes = GetAchievementStore()->LookupEntry(ACHIEV_SNAKES);
            if (achievSnakes && IsHeroic())
            {
                for (std::set<uint64>::const_iterator itr = lUnWrappedPlayers.begin(); itr != lUnWrappedPlayers.end(); ++itr)
                {
                    Player* temp = Unit::GetPlayer(*me, *itr);
                    if (temp && temp->isAlive() && (temp->GetDistance2d(me) < 100))
                        temp->CompletedAchievement(achievSnakes);
                }
            }

            if (pInstance)
                pInstance->SetData(DATA_SLAD_RAN_EVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }

        void JustSummoned(Creature* summoned)
        {
            summoned->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            lSummons.Summon(summoned);
        }
    };
};

class mob_slad_ran_constrictor : public CreatureScript
{
public:
    mob_slad_ran_constrictor() : CreatureScript("mob_slad_ran_constrictor") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_slad_ran_constrictorAI (creature);
    }

    struct mob_slad_ran_constrictorAI : public ScriptedAI
    {
        mob_slad_ran_constrictorAI(Creature* c) : ScriptedAI(c) {}

        uint64 uiWrapTarget;
        uint32 uiGripOfSladRanTimer;
        uint32 uiEnwrapTimer;
        bool bEnwrapping;

        void Reset()
        {
            uiGripOfSladRanTimer = 1*IN_MILLISECONDS;
            uiEnwrapTimer = 3*IN_MILLISECONDS;
            uiWrapTarget = 0;
            bEnwrapping = false;
        }

        void CastGrip(Unit* target) // workaround
        {
            uint8 stackcount = 0;

            if (target->HasAura(SPELL_GRIP_OF_SLAD_RAN)) //if aura exists
            {
                 if (Aura* pGripAura = target->GetAura(SPELL_GRIP_OF_SLAD_RAN))
                 {
                     stackcount = pGripAura->GetStackAmount();

                     pGripAura->SetStackAmount(stackcount + 1); // add one stack
                     pGripAura->SetDuration(pGripAura->GetMaxDuration()); // reset aura duration

                     //if now stacked 5 times
                     if (stackcount >= 4)
                     {
                          target->RemoveAurasDueToSpell(SPELL_GRIP_OF_SLAD_RAN);

                          me->AddUnitState(UNIT_STAT_ROOT); //dont interrupt channelling by moving
                          DoCast(target, SPELL_SNAKE_WRAP);

                          bEnwrapping = true;
                          uiWrapTarget = target->GetGUID();
                     }
                 }
            }
            else DoCast(target, SPELL_GRIP_OF_SLAD_RAN);  //else add aura
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiGripOfSladRanTimer <= diff)
            {
                Unit* target = me->getVictim();

                CastGrip(target);

                uiGripOfSladRanTimer = 5*IN_MILLISECONDS;
            } else uiGripOfSladRanTimer -= diff;

            if (bEnwrapping)
            {
                if (uiEnwrapTimer <= diff)
                {
                    if (Unit* target = Unit::GetUnit((*me), uiWrapTarget))
                    {
                        target->CastSpell(target, SPELL_SNAKE_WRAP_STUN, true);

                        // replace with Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_SLADRAN) : 0) later
                        if (Creature* pSladran = GetClosestCreatureWithEntry(me, CREATURE_SLAD_RAN, 100.0f))
                            CAST_AI(boss_slad_ran::boss_slad_ranAI, pSladran->AI())->GotWrapped(target);

                        me->DisappearAndDie();
                        uiWrapTarget = 0;
                    }
                    bEnwrapping = false;
                    uiEnwrapTimer = 3*IN_MILLISECONDS;
                } else uiEnwrapTimer -= diff;
            }
        }
    };
};

class mob_slad_ran_viper : public CreatureScript
{
public:
    mob_slad_ran_viper() : CreatureScript("mob_slad_ran_viper") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_slad_ran_viperAI (creature);
    }

    struct mob_slad_ran_viperAI : public ScriptedAI
    {
        mob_slad_ran_viperAI(Creature* c) : ScriptedAI(c) {}

        uint32 uiVenomousBiteTimer;

        InstanceScript* pInstance;

        void Reset()
        {
            uiVenomousBiteTimer = 2*IN_MILLISECONDS;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiVenomousBiteTimer <= diff)
            {
                DoCast(me->getVictim(), DUNGEON_MODE(SPELL_VENOMOUS_BITE, H_SPELL_VENOMOUS_BITE));
                uiVenomousBiteTimer = 10*IN_MILLISECONDS;
            } else uiVenomousBiteTimer -= diff;
        }
    };
};

class mob_snake_wrap : public CreatureScript
{
public:
    mob_snake_wrap() : CreatureScript("mob_snake_wrap") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_snake_wrapAI(pCreature);
    }

    struct mob_snake_wrapAI : public ScriptedAI
    {
        mob_snake_wrapAI(Creature *c) : ScriptedAI(c) {}
        uint64 WrapTargetGUID;
        void Reset()
        {
            WrapTargetGUID = 0;
        }

        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}

        void JustDied(Unit *killer)
        {
            if (WrapTargetGUID)
            {
                Unit* target = Unit::GetUnit((*me), WrapTargetGUID);
                if (target)
                    target->RemoveAurasDueToSpell(SPELL_SNAKE_WRAP_STUN);
            }
            me->RemoveCorpse();
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if(!me->ToTempSummon())
                return;

            if (Unit *summoner = me->ToTempSummon()->GetSummoner())
                WrapTargetGUID = summoner->GetGUID();

            Unit* temp = Unit::GetUnit((*me), WrapTargetGUID);
            if ((temp && temp->isAlive() && !temp->HasAura(SPELL_SNAKE_WRAP_STUN)) || !temp)
                me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }
    };
};

void AddSC_boss_slad_ran()
{
    new boss_slad_ran();
    new mob_slad_ran_constrictor();
    new mob_slad_ran_viper();
    new mob_snake_wrap();
}
