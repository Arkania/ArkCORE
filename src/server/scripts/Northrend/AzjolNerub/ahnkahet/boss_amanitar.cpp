/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
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

/*
 * Comment:  Find correct mushrooms spell
 */

#include "ScriptPCH.h"
#include "ahnkahet.h"

enum Spells
{
    SPELL_BASH                                    = 57094, // Victim
    SPELL_ENTANGLING_ROOTS                        = 57095, // Random Victim 100Y
    SPELL_MINI                                    = 57055, // Self
    SPELL_VENOM_BOLT_VOLLEY                       = 57088, // Random Victim 100Y
    SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS          = 56648, // Killer 3Y
    SPELL_POISONOUS_MUSHROOM_POISON_CLOUD         = 57061, // Self - Duration 8 Sec
    SPELL_POISONOUS_MUSHROOM_VISUAL_AREA          = 61566, // Self
    SPELL_POISONOUS_MUSHROOM_VISUAL_AURA          = 56741, // Self
    SPELL_POWER_MUSHROOM_VISUAL_AURA              = 56740,
    SPELL_PUTRID_MUSHROOM                         = 31690
};

enum Creatures
{
    NPC_HEALTHY_MUSHROOM                          = 30391,
    NPC_POISONOUS_MUSHROOM                        = 30435,
    NPC_HELPER                                    = 19656
};

class boss_amanitar : public CreatureScript
{
public:
    boss_amanitar() : CreatureScript("boss_amanitar") { }

    struct boss_amanitarAI : public ScriptedAI
    {
        boss_amanitarAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 uiRootTimer;
        uint32 uiBashTimer;
        uint32 uiBoltTimer;
        uint32 uiSpawnTimer;
        uint32 uiMiniTimer;

        void Reset()
        {
            uiRootTimer = urand(5*IN_MILLISECONDS,9*IN_MILLISECONDS);
            uiBashTimer = urand(10*IN_MILLISECONDS,14*IN_MILLISECONDS);
            uiBoltTimer = urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS);
            uiMiniTimer = urand(12*IN_MILLISECONDS, 18*IN_MILLISECONDS);
            uiSpawnTimer = 5*IN_MILLISECONDS;

            me->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);

            if (pInstance)
            {
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
                pInstance->SetData(DATA_AMANITAR_EVENT, NOT_STARTED);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (pInstance)
            {
                pInstance->SetData(DATA_AMANITAR_EVENT, DONE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_AMANITAR_EVENT, IN_PROGRESS);
        }

        void SpawnAdds()
        {
            uint8 u = 0;

            for (uint8 i = 0; i < 100; ++i)
                {
                    Position pos;
                me->GetPosition(&pos);
                me->GetRandomNearPosition(pos, 45.0f);
                pos.m_positionZ = me->GetMap()->GetHeight(pos.GetPositionX(), pos.GetPositionY(), MAX_HEIGHT) + 2.0f;

                if (Creature* pHelp = me->SummonCreature(NPC_HELPER, pos))
                {
                    Creature* temp1 = pHelp->FindNearestCreature(NPC_HEALTHY_MUSHROOM, 6.0f, true);
                    Creature* temp2 = pHelp->FindNearestCreature(NPC_POISONOUS_MUSHROOM, 6.0f, true);
                    if (temp1 || temp2)
                    {
                        pHelp->DisappearAndDie();
                    }
                    else  // found good place to spawn
                    {
                        u = 1 - u;
                        pHelp->DisappearAndDie();
                        me->SummonCreature(u > 0 ? NPC_POISONOUS_MUSHROOM : NPC_HEALTHY_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60*IN_MILLISECONDS);
                    }
                }
            }
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (uiSpawnTimer <= diff)
            {
                SpawnAdds();
                uiSpawnTimer = 20*IN_MILLISECONDS;
            } else uiSpawnTimer -= diff;

            if (uiMiniTimer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(SPELL_MINI);
                    uiMiniTimer = urand(25*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                }
            } else uiMiniTimer -= diff;

            if (uiRootTimer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_ENTANGLING_ROOTS);
                    uiRootTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
                }
            } else uiRootTimer -= diff;

            if (uiBashTimer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                DoCastVictim(SPELL_BASH);
                    uiBashTimer = urand(7*IN_MILLISECONDS, 12*IN_MILLISECONDS);
                }
            } else uiBashTimer -= diff;

            if (uiBoltTimer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_VENOM_BOLT_VOLLEY);
                    uiBoltTimer = urand(18*IN_MILLISECONDS, 22*IN_MILLISECONDS);
                }
            } else uiBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_amanitarAI(creature);
    }
};

class mob_amanitar_mushrooms : public CreatureScript
{
public:
    mob_amanitar_mushrooms() : CreatureScript("mob_amanitar_mushrooms") { }

    struct mob_amanitar_mushroomsAI : public Scripted_NoMovementAI
    {
        mob_amanitar_mushroomsAI(Creature* c) : Scripted_NoMovementAI(c) {}

        uint32 uiAuraTimer;

        void Reset()
        {
            me->SetDisplayId(26981);
            DoCast(SPELL_PUTRID_MUSHROOM);

            if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
                DoCast(SPELL_POISONOUS_MUSHROOM_VISUAL_AURA);
            else
                DoCast(SPELL_POWER_MUSHROOM_VISUAL_AURA);

            uiAuraTimer = 1*IN_MILLISECONDS;
        }

        void JustDied(Unit* killer)
        {
            if (me->GetEntry() == NPC_HEALTHY_MUSHROOM)
                DoCast(me, SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS, true);
        }

        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*victim*/) {}

        void UpdateAI(uint32 const diff)
        {
            if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
            {
                if (uiAuraTimer <= diff)
                {
                    DoCast(me, SPELL_POISONOUS_MUSHROOM_POISON_CLOUD);
                    uiAuraTimer = 7*IN_MILLISECONDS;
                } else uiAuraTimer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_amanitar_mushroomsAI(creature);
    }
};

void AddSC_boss_amanitar()
{
    new boss_amanitar();
    new mob_amanitar_mushrooms();
}
