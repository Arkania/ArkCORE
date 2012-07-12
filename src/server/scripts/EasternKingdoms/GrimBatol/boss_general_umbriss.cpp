/*
 * Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
 *
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum Archivement
{
    ARCH_ANSCHISS_FUER_UMBRISS    = 100,
};

enum Yells
{
    SAY_AGGRO               = -1800000,
    SAY_DEATH               = -1800001,
    SAY_SUMMON_1            = -1800002,
    SAY_SUMMON_2            = -1800003,
    SAY_SLAY_1              = -1800004,
};

enum CreatureIds
{
    BOSS_GENERAL_UMBRISS    = 39625,
    MOB_TROGG_MAL           = 39984,
    MOB_TROGG_HAB           = 45467,
};

enum Spells
{
    //General Umbriss
    SPELL_BERSERK           = 74853,
    SPELL_SECOUSS           = 74634,      //bodenbelagerung
    SPELL_SECOUSS_H         = 90249,
    SPELL_ECLAIR            = 74670,      //blitz
    SPELL_ECLAIR_H          = 90250,
    SPELL_PLAIE             = 74846,      //blutende wunde
    SPELL_PLAIE_H           = 91939,
    SPELL_APPARITION        = 74859,
    //Trogs
    SPELL_MAL               = 90169,
    SPELL_MODGUD            = 74837,
    SPELL_GRIFFE            = 90212,
};

enum Events
{
    //Umbriss
    EVENT_BERSERK           = 0,
    EVENT_SECOUSS           = 1,
    EVENT_ECLAIR            = 2,
    EVENT_PLAIE             = 3,
    EVENT_SUMMON            = 4,
    //Trogg
    EVENT_GRIFFE            = 5,
    EVENT_MAL               = 6,
    EVENT_MOGUD             = 7,
};

enum SummonIds
{
    NPC_TROGG_MAL           = 39984,
    NPC_TROGG_HAB           = 45467,
};

const Position aSpawnLocations[3] =
{
    {-721.551697f, -439.109711f, 268.767456f, 0.814808f},
    {-700.411255f, -454.676971f, 268.767395f, 1.388150f},
    {-697.920105f, -435.002228f, 269.147583f, 1.470617f},
};

class boss_general_umbriss : public CreatureScript
{
    public:
        boss_general_umbriss() : CreatureScript("boss_general_umbriss") {}

        struct boss_general_umbrissAI : public ScriptedAI
        {
            boss_general_umbrissAI(Creature* creature) : ScriptedAI(creature), Summons(me)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            SummonList Summons;

            void EnterCombat(Unit * /*who*/)
            {
                EnterPhaseGround();
                DoScriptText(SAY_AGGRO, me);
            }

//            void JustDied(Unit* /*killer*/)
//            {
//                DoScriptText(SAY_DEATH, me);
//            }

            void JustSummoned(Creature *pSummoned)
            {
                pSummoned->SetInCombatWithZone();
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                pSummoned->AI()->AttackStart(pTarget);

                Summons.Summon(pSummoned);
            }

            void SummonedCreatureDespawn(Creature *summon)
            {
                Summons.Despawn(summon);
            }

            void EnterPhaseGround()
            {
                events.ScheduleEvent(EVENT_SECOUSS, 30000);
                events.ScheduleEvent(EVENT_ECLAIR, 25000);
                events.ScheduleEvent(EVENT_PLAIE, 20000);
                events.ScheduleEvent(EVENT_SUMMON, 60000);
                events.ScheduleEvent(EVENT_BERSERK, 180000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_SECOUSS:
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, IsHeroic() ? SPELL_SECOUSS_H : SPELL_SECOUSS);
                                events.ScheduleEvent(EVENT_SECOUSS, 20000);
                                return;
                            case EVENT_ECLAIR:
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, IsHeroic() ? SPELL_ECLAIR_H : SPELL_ECLAIR);
                                events.ScheduleEvent(EVENT_ECLAIR, 25000);
                                return;
                            case EVENT_PLAIE:
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, IsHeroic() ? SPELL_PLAIE_H : SPELL_PLAIE);
                                events.ScheduleEvent(EVENT_PLAIE, 20000);
                                return;
                            case EVENT_BERSERK:
                                if (!HealthAbovePct(30))
                                    {
                                        DoCast(me, SPELL_BERSERK);
                                    }
                                return;
                            case EVENT_SUMMON:
                                me->SummonCreature(NPC_TROGG_MAL, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                                me->SummonCreature(NPC_TROGG_HAB, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                                events.ScheduleEvent(EVENT_SUMMON, 60000);
                                DoScriptText(RAND(SAY_SUMMON_1, SAY_SUMMON_2), me);
                                return;
                        }
                    }
                DoMeleeAttackIfReady();
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(SAY_SLAY_1, me);
            }
        };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_general_umbrissAI(creature);
    }
};

/*******************
** Trogg Malveillant
*******************/
class npc_malveillant: public CreatureScript
{
public:
 npc_malveillant() : CreatureScript("npc_malveillant") { }

 struct npc_malveillantAI : public ScriptedAI
    {
        npc_malveillantAI(Creature *c) : ScriptedAI(c) {}

        EventMap events;

        void EnterCombat(Unit * /*who*/)
        {
            EnterPhaseGround();
        }

        void EnterPhaseGround()
        {
            events.ScheduleEvent(EVENT_GRIFFE, 2000);
            events.ScheduleEvent(EVENT_MAL, 6000);
            events.ScheduleEvent(EVENT_MOGUD, 12000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GRIFFE:
                            DoCastVictim(SPELL_GRIFFE);
                            events.ScheduleEvent(EVENT_GRIFFE, 2000);
                            return;
                        case EVENT_MAL:
                            DoCastVictim(SPELL_MAL);
                            events.ScheduleEvent(EVENT_MAL, 6000);
                            return;
                        case EVENT_MOGUD:
                            DoCastVictim(SPELL_MODGUD);
                            events.ScheduleEvent(EVENT_MOGUD, 12000);
                            return;
                    }
                }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_malveillantAI (creature);
    }
};

/****************
** Trogg Habitant
****************/
class npc_habitant: public CreatureScript
{
public:
 npc_habitant() : CreatureScript("npc_habitant") { }

 struct npc_habitantAI : public ScriptedAI
    {
        npc_habitantAI(Creature *c) : ScriptedAI(c) {}

        EventMap events;

        void EnterCombat(Unit * /*who*/)
        {
            EnterPhaseGround();
        }

        void EnterPhaseGround()
        {
            events.ScheduleEvent(EVENT_GRIFFE, 5000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GRIFFE:
                            DoCastVictim(SPELL_GRIFFE);
                            events.ScheduleEvent(EVENT_GRIFFE, 5000);
                            return;
                    }
                }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_habitantAI (creature);
    }
};

void AddSC_boss_general_umbriss()
{
    new boss_general_umbriss();
    new npc_habitant();
    new npc_malveillant();
}