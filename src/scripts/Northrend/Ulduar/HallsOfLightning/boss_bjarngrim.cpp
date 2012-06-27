/*
 * Copyright (C) 2008 - 2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "halls_of_lightning.h"

enum Enums
{
    SAY_AGGRO                               = -1602000,
    SAY_SLAY_1                              = -1602001,
    SAY_SLAY_2                              = -1602002,
    SAY_SLAY_3                              = -1602003,
    SAY_DEATH                               = -1602004,
    SAY_BATTLE_STANCE                       = -1602005,
    EMOTE_BATTLE_STANCE                     = -1602006,
    SAY_BERSEKER_STANCE                     = -1602007,
    EMOTE_BERSEKER_STANCE                   = -1602008,
    SAY_DEFENSIVE_STANCE                    = -1602009,
    EMOTE_DEFENSIVE_STANCE                  = -1602010,

    SPELL_PUMMEL                            = 12555,
    SPELL_IRONFORM                          = 52022,
    SPELL_SLAM                              = 52026,
    SPELL_CHARGE_UP                         = 56458,
    SPELL_TEMPORARY_ELECTRICAL_CHARGE       = 52092,

    SPELL_DEFENSIVE_STANCE                  = 53790,
    SPELL_SPELL_REFLECTION                  = 36096,
    SPELL_INTERCEPT                         = 58769,
    SPELL_KNOCK_AWAY                        = 52029,

    SPELL_BERSEKER_STANCE                   = 53791,
    SPELL_WHIRLWIND                         = 52027,
    SPELL_MORTAL_STRIKE                     = 16856,

    SPELL_BATTLE_STANCE                     = 53792,
    SPELL_CLEAVE                            = 15284,

    SPELL_ARC_WELD                          = 59085,
    SPELL_RENEW_STEEL_N                     = 52774,
    SPELL_RENEW_STEEL_H                     = 59160,

    NPC_STORMFORGED_LIEUTENANT              = 29240,
    NPC_TRIGGER                             = 30298,

    EQUIP_SWORD                             = 37871,
    EQUIP_SHIELD                            = 35642,
    EQUIP_MACE                              = 43623,

    STANCE_DEFENSIVE                        = 0,
    STANCE_BERSERKER                        = 1,
    STANCE_BATTLE                           = 2,

    EVENT_CHANGE_STANCE                     = 1,
    EVENT_REFLECTION                        = 2,
    EVENT_KNOCK_AWAY                        = 3,
    EVENT_PUMMEL                            = 4,
    EVENT_IRONFORM                          = 5,
    EVENT_INTERCEPT                         = 6,
    EVENT_WHIRLWIND                         = 7,
    EVENT_CLEAVE                            = 8,
    EVENT_MORTAL_STRIKE                     = 9,
    EVENT_SLAM                              = 10,
    EVENT_ARC_WELD                          = 11,
    EVENT_RENEW_STEEL                       = 12,

    DATA_LIGHTNING_STRUCK                   = 1
};

/*######
## boss_bjarngrim
######*/

class boss_bjarngrim : public CreatureScript
{
public:
    boss_bjarngrim() : CreatureScript("boss_bjarngrim") { }

    struct boss_bjarngrimAI : public ScriptedAI
    {
        boss_bjarngrimAI(Creature* creature) : ScriptedAI(creature)
        {
                _instance = creature->GetInstanceScript();
                _stance = STANCE_DEFENSIVE;
        }

        void Reset()
        {
                _events.Reset();
                _charged = false;

                while (Creature* stormforgedLieutenant = me->FindNearestCreature(NPC_STORMFORGED_LIEUTENANT, 200.0f, false))
                    stormforgedLieutenant->Respawn();

                if (_stance != STANCE_DEFENSIVE)
                    RemoveStance(_stance);

                DoCast(me, SPELL_DEFENSIVE_STANCE, true);
            SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_SHIELD, EQUIP_NO_CHANGE);
                _stance = STANCE_DEFENSIVE;

                if (_instance)
                    _instance->SetData(TYPE_BJARNGRIM, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
                me->SetInCombatWithZone();
            DoScriptText(SAY_AGGRO, me);

            //must get both lieutenants here and make sure they are with him
        me->CallForHelp(40.0f);

                if (me->HasAura(SPELL_TEMPORARY_ELECTRICAL_CHARGE))
                    _charged = true;

                _events.ScheduleEvent(EVENT_CHANGE_STANCE, urand(20, 25) * IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_SLAM, 15*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_PUMMEL, 10*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_IRONFORM, 25*IN_MILLISECONDS);

                _events.ScheduleEvent(EVENT_REFLECTION, 8*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_KNOCK_AWAY, urand(10, 20) * IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_INTERCEPT, urand(5, 10) * IN_MILLISECONDS);

                if (_instance)
                    _instance->SetData(TYPE_BJARNGRIM, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }

        void JustDied(Unit* /*killer*/)
        {
                _events.Reset();

            DoScriptText(SAY_DEATH, me);

                if (_instance)
                    _instance->SetData(TYPE_BJARNGRIM, DONE);
        }

            void RemoveStance(uint8 stance)
        {
                switch (stance)
            {
                case STANCE_DEFENSIVE:
                    me->RemoveAurasDueToSpell(SPELL_DEFENSIVE_STANCE);
                        _events.CancelEvent(EVENT_REFLECTION);
                        _events.CancelEvent(EVENT_KNOCK_AWAY);
                        _events.CancelEvent(EVENT_INTERCEPT);
                    break;
                case STANCE_BERSERKER:
                    me->RemoveAurasDueToSpell(SPELL_BERSEKER_STANCE);
                        _events.CancelEvent(EVENT_WHIRLWIND);
                        _events.CancelEvent(EVENT_MORTAL_STRIKE);
                    break;
                case STANCE_BATTLE:
                    me->RemoveAurasDueToSpell(SPELL_BATTLE_STANCE);
                        _events.CancelEvent(EVENT_CLEAVE);
                    break;
            }
        }

            void SwitchStance()
            {
                uint8 tempStance = urand(0, 2);

                if (tempStance == _stance)
                    ++tempStance;

                if (tempStance > 2)
                    tempStance = 0;

                _stance = tempStance;

                switch (_stance)
                {
                    case STANCE_DEFENSIVE:
                        DoScriptText(SAY_DEFENSIVE_STANCE, me);
                        DoScriptText(EMOTE_DEFENSIVE_STANCE, me);
                        DoCast(me, SPELL_DEFENSIVE_STANCE);
                        _events.ScheduleEvent(EVENT_REFLECTION, 7*IN_MILLISECONDS);
                        _events.ScheduleEvent(EVENT_KNOCK_AWAY, urand(5, 20) * IN_MILLISECONDS);
                        _events.ScheduleEvent(EVENT_INTERCEPT, urand(5, 10) * IN_MILLISECONDS);
                        SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_SHIELD, EQUIP_NO_CHANGE);
                        break;
                    case STANCE_BERSERKER:
                        DoScriptText(SAY_BERSEKER_STANCE, me);
                        DoScriptText(EMOTE_BERSEKER_STANCE, me);
                        DoCast(me, SPELL_BERSEKER_STANCE);
                        _events.ScheduleEvent(EVENT_WHIRLWIND, 8*IN_MILLISECONDS);
                        _events.ScheduleEvent(EVENT_MORTAL_STRIKE, 5*IN_MILLISECONDS);
                        SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_SWORD, EQUIP_NO_CHANGE);
                        break;
                    case STANCE_BATTLE:
                        DoScriptText(SAY_BATTLE_STANCE, me);
                        DoScriptText(EMOTE_BATTLE_STANCE, me);
                        DoCast(me, SPELL_BATTLE_STANCE);
                        _events.ScheduleEvent(EVENT_CLEAVE, 5*IN_MILLISECONDS);
                        SetEquipmentSlots(false, EQUIP_MACE, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_LIGHTNING_STRUCK)
                    return _charged ? 1 : 0;

                return 0;
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
                        case EVENT_CHANGE_STANCE:
                            RemoveStance(_stance);
                            SwitchStance();
                            _events.ScheduleEvent(EVENT_CHANGE_STANCE, urand(20, 25) * IN_MILLISECONDS);
                            return;
                        case EVENT_SLAM:
                            DoCastVictim(SPELL_SLAM);
                            _events.ScheduleEvent(EVENT_SLAM, urand(10, 14) * IN_MILLISECONDS);
                            break;
                        case EVENT_PUMMEL:
                            DoCastVictim(SPELL_PUMMEL);
                            _events.ScheduleEvent(EVENT_PUMMEL, urand(5, 10) * IN_MILLISECONDS);
                            break;
                        case EVENT_IRONFORM:
                            DoCast(me, SPELL_IRONFORM);
                            _events.ScheduleEvent(EVENT_IRONFORM, urand(20, 25) * IN_MILLISECONDS);
                            break;
                        case EVENT_REFLECTION:
                        DoCast(me, SPELL_SPELL_REFLECTION);
                            _events.ScheduleEvent(EVENT_REFLECTION, urand(8, 9) * IN_MILLISECONDS);
                            break;
                        case EVENT_KNOCK_AWAY:
                        DoCast(me, SPELL_KNOCK_AWAY);
                            _events.ScheduleEvent(EVENT_KNOCK_AWAY, urand(10, 20) * IN_MILLISECONDS);
                    break;
                        case EVENT_INTERCEPT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -8.0f))
                                DoCast(target, SPELL_INTERCEPT);
                            _events.ScheduleEvent(EVENT_INTERCEPT, 10*IN_MILLISECONDS);
                            break;
                        case EVENT_WHIRLWIND:
                        DoCast(me, SPELL_WHIRLWIND);
                            _events.ScheduleEvent(EVENT_WHIRLWIND, urand(10, 11) * IN_MILLISECONDS);
                    break;
                        case EVENT_MORTAL_STRIKE:
                            DoCastVictim(SPELL_MORTAL_STRIKE);
                            _events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(7, 10) * IN_MILLISECONDS);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            _events.ScheduleEvent(EVENT_CLEAVE, urand(5, 10) * IN_MILLISECONDS);
                            break;
                        default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            InstanceScript* _instance;
            EventMap _events;
            uint8 _stance;
            bool _charged;
    };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_bjarngrimAI(creature);
        }
};

/*######
## mob_stormforged_lieutenant
######*/

class mob_stormforged_lieutenant : public CreatureScript
{
public:
    mob_stormforged_lieutenant() : CreatureScript("mob_stormforged_lieutenant") { }

        struct mob_stormforged_lieutenantAI : public ScriptedAI
        {
            mob_stormforged_lieutenantAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                _events.Reset();
            }

            void EnterCombat(Unit* who)
            {
                if (_instance)
                    if (Creature* bjarngrim = _instance->instance->GetCreature(_instance->GetData64(DATA_BJARNGRIM)))
                        if (bjarngrim->isAlive() && !bjarngrim->getVictim())
                            bjarngrim->AI()->AttackStart(who);

                _events.ScheduleEvent(EVENT_ARC_WELD, urand(5, 20) * IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_RENEW_STEEL, urand(10, 25) * IN_MILLISECONDS);
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
                        case EVENT_ARC_WELD:
                            DoCastVictim(SPELL_ARC_WELD);
                            _events.ScheduleEvent(EVENT_ARC_WELD, urand(15, 20) * IN_MILLISECONDS);
                            break;
                        case EVENT_RENEW_STEEL:
                            if (_instance)
                                if (Creature* bjarngrim = _instance->instance->GetCreature(_instance->GetData64(DATA_BJARNGRIM)))
                                    if (bjarngrim->isAlive())
                                        DoCast(bjarngrim, DUNGEON_MODE(SPELL_RENEW_STEEL_N, SPELL_RENEW_STEEL_H));
                            _events.ScheduleEvent(EVENT_RENEW_STEEL, urand(15, 25) * IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
        };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_stormforged_lieutenantAI(creature);
    }
    };

class spell_bjarngrim_charge_up : public SpellScriptLoader
{
    public:
        spell_bjarngrim_charge_up() : SpellScriptLoader("spell_bjarngrim_charge_up") { }

        class spell_bjarngrim_charge_up_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_bjarngrim_charge_up_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (Creature* trigger = caster->FindNearestCreature(NPC_TRIGGER, 200.0f))
                        trigger->CastSpell(caster, SPELL_CHARGE_UP, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_bjarngrim_charge_up_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_bjarngrim_charge_up_AuraScript();
        }
};

class achievement_lightning_struck : public AchievementCriteriaScript
{
    public:
        achievement_lightning_struck() : AchievementCriteriaScript("achievement_lightning_struck")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* bjarngrim = target->ToCreature())
                if (bjarngrim->AI()->GetData(DATA_LIGHTNING_STRUCK))
                    return true;

            return false;
        }
};

void AddSC_boss_bjarngrim()
{
    new boss_bjarngrim();
    new mob_stormforged_lieutenant();
    new spell_bjarngrim_charge_up();
    new achievement_lightning_struck();
}
