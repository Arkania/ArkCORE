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

enum Spells
{
    // troll form
    SPELL_DETERMINED_STAB                         = 55104,
    SPELL_GROUND_TREMOR                           = 55142,
    SPELL_NUMBING_SHOUT                           = 55106,
    SPELL_MOJO_FRENZY                             = 55163,
    SPELL_MOJO_FRENZY_HASTE                       = 55096,
    SPELL_TRANSFORMATION                          = 55098, //Periodic, The caster transforms into a powerful mammoth, increasing Physical damage done by 25% and granting immunity to Stun effects.
    // mammoth
    SPELL_DETERMINED_GORE                         = 55102,
    H_SPELL_DETERMINED_GORE                       = 59444,
    SPELL_QUAKE                                   = 55101,
    SPELL_NUMBING_ROAR                            = 55100
};

enum Says
{
    SAY_AGGRO                                     = -1604011,
    SAY_QUAKE                                     = -1604012,
    SAY_TRANSFORM                                 = -1604013,
    SAY_SLAY_1                                    = -1604014,
    SAY_SLAY_2                                    = -1604015,
    SAY_SLAY_3                                    = -1604016,
    SAY_DEATH                                     = -1604017,
    EMOTE_TRANSFORM                               = -1604018,
    EMOTE_TRANSFORMED          = -1604029
};

enum Events
{
    EVENT_QUAKE = 1,
    EVENT_SHOUT,
    EVENT_STAB,
    EVENT_TRANSFORM,
    DATA_LESS_RABI
};

class boss_moorabi : public CreatureScript
{
public:
        boss_moorabi() : CreatureScript("boss_moorabi")
    {
    }

    struct boss_moorabiAI : public ScriptedAI
    {
        boss_moorabiAI(Creature* creature) : ScriptedAI(creature)
        {
                _instance = creature->GetInstanceScript();

            // make 55098 interruptable
            SpellEntry* spell = (SpellEntry*)sSpellStore.LookupEntry(SPELL_TRANSFORMATION);
            if (spell)
                spell->InterruptFlags |= SPELL_INTERRUPT_FLAG_INTERRUPT;
        }

        void Reset()
        {
                _events.Reset();
                _transformed = false;

                if (_instance)
                    _instance->SetData(DATA_MOORABI_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            DoCast(me, SPELL_MOJO_FRENZY, true);

                _events.ScheduleEvent(EVENT_QUAKE, 18*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_SHOUT, 15*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_STAB, 10*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_TRANSFORM, 12*IN_MILLISECONDS);

                if (_instance)
                    _instance->SetData(DATA_MOORABI_EVENT, IN_PROGRESS);
         }

        uint32 GetData(uint32 type)
        {
            if (type == DATA_LESS_RABI)
                    return !_transformed ? 1 : 0;

            return 0;
        }

         void JustDied(Unit* /*killer*/)
         {
            DoScriptText(SAY_DEATH, me);

                if (_instance)
                    _instance->SetData(DATA_MOORABI_EVENT, DONE);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;

            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), me);
        }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                     return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_QUAKE:
                            DoScriptText(SAY_QUAKE, me);
                            DoCastVictim(_transformed ? SPELL_GROUND_TREMOR : SPELL_QUAKE);
                            _events.ScheduleEvent(EVENT_QUAKE, urand(10, 15) *IN_MILLISECONDS);
                            break;
                        case EVENT_SHOUT:
                            DoCastVictim(_transformed ? SPELL_NUMBING_ROAR : SPELL_NUMBING_SHOUT);
                            _events.ScheduleEvent(EVENT_SHOUT, 10*IN_MILLISECONDS);
                            break;
                        case EVENT_STAB:
                            DoCastVictim(_transformed ? DUNGEON_MODE(SPELL_DETERMINED_GORE, H_SPELL_DETERMINED_GORE) : SPELL_DETERMINED_STAB);
                            _events.ScheduleEvent(EVENT_STAB, 7*IN_MILLISECONDS);
                            break;
                        case EVENT_TRANSFORM:
                            DoScriptText(EMOTE_TRANSFORM, me);
                            DoScriptText(SAY_TRANSFORM, me);
                            DoCast(me, SPELL_TRANSFORMATION);
                            _events.ScheduleEvent(EVENT_TRANSFORM, 10*IN_MILLISECONDS);
                            break;
                    }
                }

                if (!_transformed && me->HasAura(SPELL_TRANSFORMATION))
                {
                    _transformed = true;
                    _events.CancelEvent(EVENT_TRANSFORM);
                    me->RemoveAura(SPELL_MOJO_FRENZY);
                    DoScriptText(EMOTE_TRANSFORMED, me);
                }

                DoMeleeAttackIfReady();
             }

        private:
            InstanceScript* _instance;
            EventMap _events;
            bool _transformed;
    };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_moorabiAI(creature);
        }
};

class achievement_less_rabi : public AchievementCriteriaScript
{
    public:
        achievement_less_rabi() : AchievementCriteriaScript("achievement_less_rabi")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* moorabi = target->ToCreature())
                if (moorabi->AI()->GetData(DATA_LESS_RABI))
                    return true;

            return false;
        }
};

void AddSC_boss_moorabi()
{
    new boss_moorabi();
    new achievement_less_rabi();
}
