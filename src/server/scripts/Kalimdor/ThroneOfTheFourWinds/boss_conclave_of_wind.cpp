/*
 * Copyright (C) 2011 True Blood <http://www.trueblood-servers.com/>
 * By Asardial
 *
 * Copyright (C) 2011 - 2013 ArkCORE <http://www.arkania.net/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "throne_of_the_four_winds.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

enum Spells
{
    // Anshal
    SPELL_SOOTHING_BREEZE           = 86205,
    SPELL_SOOTHING_BREEZE_SUMMON    = 86204,
    SPELL_SOOTHING_BREEZE_VISUAL    = 86208,

    SPELL_NURTURE                   = 85422,
    SPELL_NURTURE_DUMMY_AURA        = 85428,
    SPELL_NURTURE_CREEPER_SUMMON    = 85429,

    SPELL_ZEPHYR_ULTIMATE           = 84638,

    SPELL_WITHERING_WIND            = 85576,

    // Nezir
    SPELL_ICE_PATCH                 = 86122,
    SPELL_ICE_PATCH_VISUAL          = 86107,
    SPELL_ICE_PATCH_AURA            = 86111,

    SPELL_PERMAFROST                = 86082,
    SPELL_WIND_CHILL                = 84645,
    SPELL_CHILLING_WINDS            = 85578,

    SPELL_SLEET_STORM_ULTIMATE      = 84644,

    // Rohash
    SPELL_SLICING_GALE              = 86182,

    SPELL_WIND_BLAST                = 86193,
    SPELL_WIND_BLAST_EFFECT         = 85483,

    SPELL_HURRICANE_ULTIMATE        = 84643,

    SPELL_DEAFING_WINDS             = 85573,
};

enum Events
{
    // Anshal
    EVENT_SOOTHING_BREEZE           = 1,
    EVENT_NURTURE,

    // Nezir
    EVENT_ICE_PATCH,
    EVENT_PERMAFROST,
    EVENT_WIND_CHILL,
    EVENT_SLEET_STORM_ULTIMATE,

    // Rohash
    EVENT_SLICING_GALE,
    EVENT_WIND_BLAST,
    EVENT_HURRICANE,
};

#define TARGETS_10 2
#define TARGETS_25 4

/***************
** Boss Conclave
****************/
/*************
** Boss Anshal
**************/
class boss_anshal : public CreatureScript
{
public:
    boss_anshal() : CreatureScript("boss_anshal") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_anshalAI (creature);
    }

    struct boss_anshalAI : public ScriptedAI
    {
        boss_anshalAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            creature->setPowerType(POWER_MANA);
            creature->SetMaxPower(POWER_MANA, 90);
        }

        InstanceScript* instance;
        EventMap events;
        uint32 uiRegentimer;

        void Reset()
        {
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, NOT_STARTED);

            DespawnMinions();

            events.Reset();
            me->GetMotionMaster()->MoveTargetedHome();

            uiRegentimer = 1000;
            me->SetPower(POWER_MANA,0);
        }

        void EnterCombat(Unit* who)
        {
            me->SetPower(POWER_MANA,0);
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_SOOTHING_BREEZE, urand(13000,15000));
            events.ScheduleEvent(EVENT_NURTURE, urand(15000,17000));
        }

        void UpdateAI(const uint32 diff)
        {
            if(!instance)
                return;

            if(instance->GetData(DATA_CONCLAVE_OF_WIND_EVENT) == IN_PROGRESS)
            {
                if(uiRegentimer <= diff)
                {
                    if(me->GetPower(POWER_MANA) == 90)
                    {
                        DoCastVictim(SPELL_ZEPHYR_ULTIMATE);
                        me->SetPower(POWER_MANA,0);
                    }
                    else
                        me->SetPower(POWER_MANA,me->GetPower(POWER_MANA)+1);

                    uiRegentimer = 1000;
                }                
                else uiRegentimer -= diff;

                if(!SelectTarget(SELECT_TARGET_NEAREST, 0, 10, true))
                {
                    if (!me->HasAura(SPELL_WITHERING_WIND))
                        DoCast(me, SPELL_WITHERING_WIND, true);

                }else if (me->HasAura(SPELL_WITHERING_WIND))
                    me->RemoveAura(SPELL_WITHERING_WIND);

            }else if (me->HasAura(SPELL_WITHERING_WIND))
                me->RemoveAura(SPELL_WITHERING_WIND);

            if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {

                case EVENT_SOOTHING_BREEZE:
                    DoCastAOE(SPELL_SOOTHING_BREEZE_SUMMON);

                    events.ScheduleEvent(EVENT_SOOTHING_BREEZE, urand(17000,19000));
                    break;

                case EVENT_NURTURE:
                    DoCastAOE(SPELL_NURTURE);

                    events.ScheduleEvent(EVENT_NURTURE, urand(15000,17000));
                    break;

                default:
                    break;
                }
            }		

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon)
        {
            summon->AI()->SetMinionInCombat();
        }

        void JustDied(Unit* killer)
        {
            DespawnMinions();
        }

    private:
        inline void DespawnMinions()
        {
            DespawnCreatures(NPC_SOOTHING_BREEZE);
            DespawnCreatures(NPC_RAVENOUS_CREEPER);
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 200.0f);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }
    };
};

/************
** Boss Nezir
*************/
class boss_nezir : public CreatureScript
{
public:
    boss_nezir() : CreatureScript("boss_nezir") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_nezirAI (creature);
    }

    struct boss_nezirAI : public ScriptedAI
    {
        boss_nezirAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            creature->setPowerType(POWER_MANA);
            creature->SetMaxPower(POWER_MANA, 90);
        }

        InstanceScript* instance;
        EventMap events;
        uint32 uiRegentimer;

        void Reset()
        {
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, NOT_STARTED);

            DespawnMinions();

            events.Reset();
            me->GetMotionMaster()->MoveTargetedHome();

            uiRegentimer = 1000;
            me->SetPower(POWER_MANA,0);
        }

        void EnterCombat(Unit* who)
        {
            me->SetPower(POWER_MANA,0);
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_ICE_PATCH, urand(10000,12000));
            events.ScheduleEvent(EVENT_PERMAFROST, urand(20000,23000));
            events.ScheduleEvent(EVENT_WIND_CHILL, 15000);
            events.ScheduleEvent(EVENT_SLEET_STORM_ULTIMATE, 30000);
        }

        void UpdateAI(const uint32 diff)
        {
            if(!instance)
                return;

            if(instance->GetData(DATA_CONCLAVE_OF_WIND_EVENT) == IN_PROGRESS)
            {
                if(uiRegentimer <= diff)
                {
                    if(me->GetPower(POWER_MANA) == 90)
                    {
                        DoCastVictim(SPELL_SLEET_STORM_ULTIMATE);
                        me->SetPower(POWER_MANA,0);
                    }
                    else
                        me->SetPower(POWER_MANA,me->GetPower(POWER_MANA)+1);     

                    uiRegentimer = 1000;
                }                
                else uiRegentimer -= diff;

                if(!SelectTarget(SELECT_TARGET_NEAREST, 0, 10, true))
                {
                    if (!me->HasAura(SPELL_CHILLING_WINDS))
                        DoCast(me, SPELL_CHILLING_WINDS, true);

                }else if (me->HasAura(SPELL_CHILLING_WINDS))
                    me->RemoveAura(SPELL_CHILLING_WINDS);

            }else if (me->HasAura(SPELL_CHILLING_WINDS))
                me->RemoveAura(SPELL_CHILLING_WINDS);

            if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ICE_PATCH:
                    if(Unit * target = SelectTarget(SELECT_TARGET_RANDOM,0 ,10.0f,true))
                        DoCast(target, SPELL_ICE_PATCH);

                    events.ScheduleEvent(EVENT_ICE_PATCH, urand(10000,12000));
                    break;

                case EVENT_PERMAFROST:
                    DoCastVictim(SPELL_PERMAFROST);

                    events.ScheduleEvent(EVENT_PERMAFROST, urand(20000,23000));
                    break;

                case EVENT_WIND_CHILL:
                    //DoCastAOE(SPELL_WIND_CHILL);
                    if(Unit * target = SelectTarget(SELECT_TARGET_RANDOM,0 ,10.0f,true))
                        DoCast(target, SPELL_WIND_CHILL, true);
                    events.ScheduleEvent(EVENT_WIND_CHILL, 15000);
                    break;

                default:
                    break;
                }
            }		

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* killer)
        {
            DespawnMinions();
        }

    private:
        inline void DespawnMinions()
        {
            DespawnCreatures(NPC_ICE_PATCH);
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 200.0f);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }
    };
};

/*************
** Boss Rohash
**************/
class boss_rohash : public CreatureScript
{
public:
    boss_rohash() : CreatureScript("boss_rohash") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_rohashAI (creature);
    }

    struct boss_rohashAI : public ScriptedAI
    {
        boss_rohashAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            creature->setPowerType(POWER_MANA);
            creature->SetMaxPower(POWER_MANA, 90);
        }

        InstanceScript* instance;
        EventMap events;
        uint32 uiRegentimer;

        bool IsCastingWindBlast;

        void Reset()
        {
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, NOT_STARTED);

            IsCastingWindBlast = false;

            events.Reset();
            me->GetMotionMaster()->MoveTargetedHome();

            uiRegentimer = 1000;
            me->SetPower(POWER_MANA,0);
        }

        void EnterCombat(Unit* who)
        {
            me->SetPower(POWER_MANA,0);
            instance->SetData(DATA_CONCLAVE_OF_WIND_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_SLICING_GALE, 10000);
            events.ScheduleEvent(EVENT_WIND_BLAST, 30000);
            events.ScheduleEvent(EVENT_HURRICANE, 20000);
        }

        void UpdateAI(const uint32 diff)
        {
            if(!instance)
                return;

            if(instance->GetData(DATA_CONCLAVE_OF_WIND_EVENT) == IN_PROGRESS)
            {
                if(uiRegentimer <= diff)
                {
                    if(me->GetPower(POWER_MANA) == 90)
                    {
                        DoCastVictim(SPELL_HURRICANE_ULTIMATE);
                        me->SetPower(POWER_MANA,0);
                    }
                    else
                        me->SetPower(POWER_MANA,me->GetPower(POWER_MANA)+1);     

                    uiRegentimer = 1000;
                }                
                else uiRegentimer -= diff;

                if(!SelectTarget(SELECT_TARGET_NEAREST, 0, 10, true))
                {
                    if (!me->HasAura(SPELL_DEAFING_WINDS))
                        DoCast(me, SPELL_DEAFING_WINDS, true);

                }else if (me->HasAura(SPELL_DEAFING_WINDS))
                    me->RemoveAura(SPELL_DEAFING_WINDS);

            }else if (me->HasAura(SPELL_DEAFING_WINDS))
                me->RemoveAura(SPELL_DEAFING_WINDS);

            if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if(IsCastingWindBlast)
            {
                IsCastingWindBlast=false;
                DoCastAOE(SPELL_WIND_BLAST_EFFECT);
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {

                case EVENT_WIND_BLAST:
                    DoCastAOE(SPELL_WIND_BLAST);
                    IsCastingWindBlast = true;
                    events.ScheduleEvent(EVENT_WIND_BLAST, 30000); // 60s cd
                    break;

                case EVENT_SLICING_GALE:
                    DoCastVictim(SPELL_SLICING_GALE);
                    events.ScheduleEvent(EVENT_SLICING_GALE, 10000);
                    break;

                case EVENT_HURRICANE:
                    DoCastAOE(SPELL_HURRICANE_ULTIMATE);
                    events.ScheduleEvent(EVENT_HURRICANE, 45000);
                    break;

                default:
                    break;

                }
            }		
        }
    };
};

/********
** Spells
*********/
/********************
** Spell Nurture Aura
*********************/
class spell_nurture_aura : public SpellScriptLoader
{
public:
    spell_nurture_aura() : SpellScriptLoader("spell_nurture_aura") {}

    class spell_nurture_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_nurture_aura_AuraScript);

        void HandleEffectCalcPeriodic(AuraEffect const * /*aurEff*/, bool & isPeriodic, int32 & amplitude)
        {
            isPeriodic = true;
            amplitude = 1920;
        }

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster,SPELL_NURTURE_CREEPER_SUMMON,true);
        }

        void Register()
        {
            DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_nurture_aura_AuraScript::HandleEffectCalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_nurture_aura_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_nurture_aura_AuraScript();
    }
};

void AddSC_boss_conclave_of_wind()
{
    new boss_anshal();
    new boss_nezir();
    new boss_rohash();
    new spell_nurture_aura();
}