/*
 * Copyright (C) 2005 - 2013 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2013 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2013 ArkCORE <http://www.arkania.net/>
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
#include "oculus.h"

enum Spells
{
    SPELL_MAGIC_PULL                = 51336,
    SPELL_THUNDERING_STOMP          = 50774,
    SPELL_UNSTABLE_SPHERE_PASSIVE   = 50756,
    SPELL_UNSTABLE_SPHERE_PULSE     = 50757,
    SPELL_UNSTABLE_SPHERE_TIMER     = 50758,
    NPC_UNSTABLE_SPHERE             = 28166
};

enum Yells
{
    SAY_AGGRO      = -1578005,
    SAY_KILL_1     = -1578006,
    SAY_KILL_2     = -1578007,
    SAY_KILL_3     = -1578008,
    SAY_DEATH      = -1578009,
    SAY_PULL_1     = -1578010,
    SAY_PULL_2     = -1578011,
    SAY_PULL_3     = -1578012,
    SAY_PULL_4     = -1578013,
    SAY_STOMP_1    = -1578014,
    SAY_STOMP_2    = -1578015,
    SAY_STOMP_3    = -1578016
};

enum DrakosAchievement
{
    ACHIEV_TIMED_START_EVENT = 18153
};

enum DrakosEvents
{
    EVENT_MAGIC_PULL = 1,
    EVENT_STOMP,
    EVENT_BOMB_SUMMON
};

class boss_drakos : public CreatureScript
{
    public:
        boss_drakos() : CreatureScript("boss_drakos") { }

        struct boss_drakosAI : public BossAI
        {
            boss_drakosAI(Creature* creature) : BossAI(creature, DATA_DRAKOS_EVENT) {}

            void Reset()
            {
                _Reset();

                events.ScheduleEvent(EVENT_MAGIC_PULL, 15000);
                events.ScheduleEvent(EVENT_STOMP, 17000);
                events.ScheduleEvent(EVENT_BOMB_SUMMON, 2000);

                _postPull = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                DoScriptText(SAY_AGGRO, me);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);
                _DoAggroPulse(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BOMB_SUMMON:
                            Position position;
                            me->GetPosition(&position);
                            for (uint8 i = 0; i <= (_postPull ? 3 : 0); ++i)
                            {
                                me->GetRandomNearPosition(position, float(urand(0, 10)));
                                me->SummonCreature(NPC_UNSTABLE_SPHERE, position);
                            }
                            events.ScheduleEvent(EVENT_BOMB_SUMMON, 3000);
                            break;
                        case EVENT_MAGIC_PULL:
                            DoScriptText(RAND(SAY_PULL_1, SAY_PULL_2, SAY_PULL_3, SAY_PULL_4), me);
                            DoCast(SPELL_MAGIC_PULL);
                            _postPull = true;
                            events.ScheduleEvent(EVENT_MAGIC_PULL, 15000);
                            break;
                        case EVENT_STOMP:
                            DoScriptText(RAND(SAY_STOMP_1, SAY_STOMP_2, SAY_STOMP_3), me);
                            DoCast(SPELL_THUNDERING_STOMP);
                            events.ScheduleEvent(EVENT_STOMP, 17000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                DoScriptText(SAY_DEATH, me);

                // start achievement timer (kill Eregos within 20 min)
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2, SAY_KILL_3), me);
            }

        private:
            bool _postPull;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_drakosAI(creature);
        }
};

class npc_unstable_sphere : public CreatureScript
{
    public:
        npc_unstable_sphere() : CreatureScript("npc_unstable_sphere") { }

        struct npc_unstable_sphereAI : public ScriptedAI
        {
            npc_unstable_sphereAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MoveRandom(40.0f);

                me->AddAura(SPELL_UNSTABLE_SPHERE_PASSIVE, me);
                me->AddAura(SPELL_UNSTABLE_SPHERE_TIMER, me);

                _pulseTimer = 3000;
                _deathTimer = 19000;
            }

            void UpdateAI(uint32 const diff)
            {
                if (_pulseTimer <= diff)
                {
                    DoCast(SPELL_UNSTABLE_SPHERE_PULSE);
                    _pulseTimer = 3*IN_MILLISECONDS;
                }
                else
                    _pulseTimer -= diff;

                if (_deathTimer <= diff)
                    me->DisappearAndDie();
                else
                    _deathTimer -= diff;
            }

        private:
            uint32 _pulseTimer;
            uint32 _deathTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_unstable_sphereAI(creature);
        }
};

void AddSC_boss_drakos()
{
    new boss_drakos();
    new npc_unstable_sphere();
}
