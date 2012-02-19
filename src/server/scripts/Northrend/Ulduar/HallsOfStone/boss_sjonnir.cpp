/*
 * Copyright (C) 2008 - 2012 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
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
#include "halls_of_stone.h"

#define SPELL_LIGHTING_RING                                 DUNGEON_MODE(51849,59861) //Periodic Trigger (interval 2s) spell = 50841/59849
#define SPELL_LIGHTING_RING_1                               DUNGEON_MODE(50840,59848) //Periodic Trigger (interval 2s) spell = 50841/59849
#define SPELL_STATIC_CHARGE                                 DUNGEON_MODE(50834,59846) //Periodic Trigger /interval 2s) spell = 50835/50847
#define SPELL_CHAIN_LIGHTING                                DUNGEON_MODE(50830,59844)
#define SPELL_LIGHTING_SHIELD                               DUNGEON_MODE(50831,59845)
#define SPELL_TOXIC_VOLLEY                                  DUNGEON_MODE(50838,59853)
#define SPELL_FRENZY                                        28747

enum Yells
{
    SAY_AGGRO                                              = -1599011,
    SAY_SLAY_1                                             = -1599012,
    SAY_SLAY_2                                             = -1599013,
    SAY_SLAY_3                                             = -1599014,
    SAY_DEATH                                              = -1599015
};

#define EMOTE_GENERIC_FRENZY                               -1000002

enum SjonnirCreatures
{
    CREATURE_FORGED_IRON_DWARF                             = 27982,
    CREATURE_FORGED_IRON_TROGG                             = 27979,
    CREATURE_MALFORMED_OOZE                                = 27981,
    CREATURE_IRON_SLUDGE                                   = 28165,
    CREATURE_EARTHEN_DWARF                                 = 27980
};

#define DATA_TIME_BEFORE_OOZE                              150000 //2min 30 secs

enum Misc
{
    ACHIEV_ABUSE_THE_OOZE                                  = 2155,
    NPC_BRANN                                              = 28070
};

struct Locations
{
    float x, y, z;
};

static Locations PipeLocations[] =
{
  {1295.44f, 734.07f, 200.3f}, //left
  {1297.7f,  595.6f,  199.9f} //right
};

#define ACTION_OOZE_DEAD                                   1
#define DATA_ABUSE_THE_OOZE                                2

static Locations CenterPoint = {1295.21f, 667.157f, 189.691f};

class boss_sjonnir : public CreatureScript
{
public:
    boss_sjonnir() : CreatureScript("boss_sjonnir") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_sjonnirAI (creature);
    }

    struct boss_sjonnirAI : public ScriptedAI
    {
        boss_sjonnirAI(Creature* c) : ScriptedAI(c), lSummons(me)
        {
            pInstance = c->GetInstanceScript();
        }

        bool bIsFrenzy;

        uint32 uiChainLightningTimer;
        uint32 uiStaticChargeTimer;
        uint32 uiLightningRingTimer;
        uint32 uiLightningShieldTimer;
        uint32 uiSummonTimer;
        uint32 uiCheckPhaseTimer;
        uint8 abuseTheOoze;
        uint32 uiSummonEntry;
        uint8 uiSummonPhase;

        SummonList lSummons;

        InstanceScript* pInstance;

        void Reset()
        {
            bIsFrenzy = false;

            uiChainLightningTimer = urand(5000, 8000);
            uiStaticChargeTimer = urand(15000, 20000);
            uiLightningRingTimer = urand(25000, 30000);
            uiLightningShieldTimer = urand(10000, 15000);
            uiSummonTimer = 1000;
            uiCheckPhaseTimer = 1000;
            abuseTheOoze = 0;
            uiSummonPhase = 1;
            uiSummonEntry = CREATURE_FORGED_IRON_DWARF;

            lSummons.DespawnAll();

            if (pInstance)
                pInstance->SetData(DATA_SJONNIR_EVENT, NOT_STARTED);

            CheckLightningShield();
        }

        void CheckLightningShield()
        {
            if (IsHeroic())
                me->RemoveAurasDueToSpell(50831);

            if (!me->HasAura(SPELL_LIGHTING_SHIELD))
                DoCast(me, SPELL_LIGHTING_SHIELD);
        }

        void JustReachedHome()
        {
            CheckLightningShield();
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
            {
                if (GameObject* pDoor = pInstance->instance->GetGameObject(pInstance->GetData64(DATA_SJONNIR_DOOR)))
                    if (pDoor->GetGoState() == GO_STATE_READY)
                    {
                        EnterEvadeMode();
                        return;
                    }

                pInstance->SetData(DATA_SJONNIR_EVENT, IN_PROGRESS);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiChainLightningTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, SPELL_CHAIN_LIGHTING);
                    uiChainLightningTimer = urand(12000, 15000);
                }
            } else uiChainLightningTimer -= diff;

            if (uiStaticChargeTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, SPELL_STATIC_CHARGE);
                    uiStaticChargeTimer = 25000;
                }
            } else uiStaticChargeTimer -= diff;

            if (uiLightningRingTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                DoCast(me, SPELL_LIGHTING_RING);
                    uiLightningRingTimer = urand(30000, 35000);
                }
            } else uiLightningRingTimer -= diff;

            if (uiLightningShieldTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    CheckLightningShield();
                    uiLightningShieldTimer = urand(45000, 55000);
                }
            } else uiLightningShieldTimer -= diff;

            if (uiCheckPhaseTimer <= diff)
            {
                if (HealthBelowPct(75) && uiSummonPhase == 1)
                {
                    uiSummonEntry = CREATURE_FORGED_IRON_TROGG;
                    uiSummonTimer = 1000;
                    uiSummonPhase = 2;
                }
                else if (HealthBelowPct(50) && uiSummonPhase == 2)
                {
                    uiSummonEntry = CREATURE_MALFORMED_OOZE;
                    uiSummonTimer = 1000;
                    uiSummonPhase = 3;
                }
                else if (HealthBelowPct(25) && uiSummonPhase == 3)
                {
                    uiSummonEntry = CREATURE_EARTHEN_DWARF;
                    uiSummonTimer = 1000;
                    uiSummonPhase = 4;
                }

                uiCheckPhaseTimer = 1000;
            } else uiCheckPhaseTimer -= diff;

            if (uiSummonTimer <= diff)
            {
                    uint32 rnd = urand(0, 1);

                    if (uiSummonEntry)
                        me->SummonCreature(uiSummonEntry, PipeLocations[rnd].x, PipeLocations[rnd].y, PipeLocations[rnd].z, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);

                    switch (uiSummonPhase)
                    {
                        case 1: uiSummonTimer = 20000; break;
                    case 2: uiSummonTimer = 7500; break;
                        case 3: uiSummonTimer = 2500; break;
                    case 4: uiSummonTimer = 5000; break;
                    }
            } else uiSummonTimer -= diff;

            if (!bIsFrenzy)
                if (HealthBelowPct(25))
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        //DoScriptText(EMOTE_GENERIC_FRENZY, me);
                  DoCast(me, SPELL_FRENZY);
                  bIsFrenzy = true;
              }

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon)
        {
            switch (summon->GetEntry())
            {
                case CREATURE_EARTHEN_DWARF:
                    summon->AI()->AttackStart(me);
                    break;
                case CREATURE_FORGED_IRON_DWARF:
                case CREATURE_FORGED_IRON_TROGG:
                    if (Unit* pTarget = me->getVictim())
                        summon->AI()->AttackStart(pTarget);
                    break;
                case CREATURE_MALFORMED_OOZE:
                    summon->SetReactState(REACT_PASSIVE);
            summon->GetMotionMaster()->MovePoint(0, CenterPoint.x, CenterPoint.y, CenterPoint.z);
                    break;
            }

            if (summon->GetEntry()!=NPC_BRANN)
            lSummons.Summon(summon);

            if (summon->GetEntry() == CREATURE_FORGED_IRON_TROGG) // DB?
                summon->setFaction(16);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            lSummons.DespawnAll();

            me->SummonCreature(NPC_BRANN,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ());

            if (pInstance)
                pInstance->SetData(DATA_SJONNIR_EVENT, DONE);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }

        void DoAction(int32 const action)
        {
            if (action == ACTION_OOZE_DEAD)
                ++abuseTheOoze;
        }

        uint32 GetData(uint32 type)
        {
            if (type == DATA_ABUSE_THE_OOZE)
                return abuseTheOoze;

            return 0;
        }
    };
};

class mob_malformed_ooze : public CreatureScript
{
public:
    mob_malformed_ooze() : CreatureScript("mob_malformed_ooze") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_malformed_oozeAI(creature);
    }

    struct mob_malformed_oozeAI : public ScriptedAI
    {
        mob_malformed_oozeAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 uiMergeTimer;

        void Reset()
        {
            uiMergeTimer = 7500;
        }

        void JustSummoned(Creature* pSummon)
        {
            if (pInstance)
                if (Creature* pSjonnir = Unit::GetCreature(*me, pInstance->GetData64(DATA_SJONNIR)))
                    if (Unit* pTarget = CAST_AI(boss_sjonnir::boss_sjonnirAI, pSjonnir->AI())->SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        pSummon->AI()->AttackStart(pTarget);
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiMergeTimer <= diff)
            {
                if (Creature* pTemp = me->FindNearestCreature(CREATURE_MALFORMED_OOZE, 5.0f, true)) // can return self?
                    if (pTemp != me)
                {
                        DoSpawnCreature(CREATURE_IRON_SLUDGE, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);

                    pTemp->DisappearAndDie();
                    me->DisappearAndDie();
                }

                uiMergeTimer = 7500;
            } else uiMergeTimer -= diff;
        }
    };
};

class mob_iron_sludge : public CreatureScript
{
public:
    mob_iron_sludge() : CreatureScript("mob_iron_sludge") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_iron_sludgeAI(creature);
    }

    struct mob_iron_sludgeAI : public ScriptedAI
    {
        mob_iron_sludgeAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 uiToxicVolleyTimer;

        void Reset()
        {
            uiToxicVolleyTimer = 2000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiToxicVolleyTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_TOXIC_VOLLEY);
                uiToxicVolleyTimer = urand(5000, 10000);
            } else uiToxicVolleyTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (pInstance)
                if (Creature* Sjonnir = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_SJONNIR)))
                    Sjonnir->AI()->DoAction(ACTION_OOZE_DEAD);
        }
    };
};

class achievement_abuse_the_ooze : public AchievementCriteriaScript
{
    public:
        achievement_abuse_the_ooze() : AchievementCriteriaScript("achievement_abuse_the_ooze")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Sjonnir = target->ToCreature())
                if (Sjonnir->AI()->GetData(DATA_ABUSE_THE_OOZE) >= 5)
                    return true;

            return false;
        }
};

void AddSC_boss_sjonnir()
{
    new boss_sjonnir();
    new mob_malformed_ooze();
    new mob_iron_sludge();
    new achievement_abuse_the_ooze();
}
