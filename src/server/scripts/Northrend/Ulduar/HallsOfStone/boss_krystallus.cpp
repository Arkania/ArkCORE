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

enum Spells
{
    SPELL_BOULDER_TOSS                             = 50843,
    SPELL_GROUND_SPIKE                             = 59750,
    SPELL_GROUND_SLAM                              = 50827,
    SPELL_GROUND_SLAM_TRIGGERED                    = 50833,
    SPELL_SHATTER                                  = 50810,
    SPELL_SHATTER_EFFECT                           = 50811,
    H_SPELL_SHATTER_EFFECT                         = 61547,
    SPELL_STONED                                   = 50812,
    SPELL_STOMP                                    = 50868,
    H_SPELL_STOMP                                  = 59744
};

enum Yells
{
    SAY_AGGRO                                   = -1599007,
    SAY_KILL                                    = -1599008,
    SAY_DEATH                                   = -1599009,
    SAY_SHATTER                                 = -1599010
};

enum Events
{
    EVENT_BOULDER_TOSS = 1,
    EVENT_GROUND_SPIKE,
    EVENT_GROUND_SLAM,
    EVENT_STOMP,
    EVENT_SHATTER_CAST,
    EVENT_SHATTER
};

class boss_krystallus : public CreatureScript
{
public:
    boss_krystallus() : CreatureScript("boss_krystallus") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_krystallusAI (creature);
    }

    struct boss_krystallusAI : public ScriptedAI
    {
        boss_krystallusAI(Creature* c) : ScriptedAI(c)
        {
            _instance = c->GetInstanceScript();

            //temporary to let ground slam effect not be interrupted
            SpellEntry* spell = (SpellEntry*)sSpellStore.LookupEntry(SPELL_GROUND_SLAM_TRIGGERED);
            if (spell)
                spell->InterruptFlags = 0;
        }

        void Reset()
        {
            IsSlam = false;
            events.Reset();

            if (_instance)
                _instance->SetData(DATA_KRYSTALLUS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            events.ScheduleEvent(EVENT_BOULDER_TOSS, urand(3000, 9000));
            events.ScheduleEvent(EVENT_GROUND_SLAM, urand(20000, 23000));
            events.ScheduleEvent(EVENT_STOMP, urand(15000, 20000));

            if (IsHeroic())
                events.ScheduleEvent(EVENT_GROUND_SPIKE, urand(6000, 11000));

            if (_instance)
                _instance->SetData(DATA_KRYSTALLUS_EVENT, IN_PROGRESS);
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_GROUND_SPIKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_GROUND_SPIKE);
                        events.ScheduleEvent(EVENT_GROUND_SPIKE, urand(7000, 12000));
                        break;
                    case EVENT_BOULDER_TOSS:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_BOULDER_TOSS);
                        events.ScheduleEvent(EVENT_BOULDER_TOSS, urand(9000, 15000));
                        break;
                    case EVENT_STOMP:
                        DoCast(DUNGEON_MODE(SPELL_STOMP, H_SPELL_STOMP));
                        events.ScheduleEvent(EVENT_STOMP, urand(12000, 18000));
                        break;
                    case EVENT_GROUND_SLAM:
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                        IsSlam = true;
                        DoCast(SPELL_GROUND_SLAM);
                        events.DelayEvents(13000);
                        events.ScheduleEvent(EVENT_SHATTER_CAST, 11000);
                        break;
                    case EVENT_SHATTER_CAST:
                        DoCast(SPELL_SHATTER);
                        DoScriptText(SAY_SHATTER, me);
                        events.ScheduleEvent(EVENT_SHATTER, 1100);
                        break;
                    case EVENT_SHATTER:
                        _instance->DoCastSpellOnPlayers(DUNGEON_MODE(SPELL_SHATTER_EFFECT, H_SPELL_SHATTER_EFFECT));
                        _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STONED);
                        if (IsSlam)
                        {
                            IsSlam = false;
                            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                            {
                                if (me->getVictim())
                                    me->GetMotionMaster()->MoveChase(me->getVictim());
                            }
                        }
                        events.ScheduleEvent(EVENT_GROUND_SLAM, urand(15000, 20000));
                        break;
                    default:
                        break;
                }
            }

            if (!IsSlam)
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (_instance)
            {
                _instance->SetData(DATA_KRYSTALLUS_EVENT, DONE);
                _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STONED);
                _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GROUND_SLAM);
                _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GROUND_SLAM_TRIGGERED);
            }
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;

            DoScriptText(SAY_KILL, me);
        }

    private:
        InstanceScript* _instance;
        EventMap events;
        bool IsSlam;
    };
};

void AddSC_boss_krystallus()
{
    new boss_krystallus();
}
