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
#include "blackwing_descent.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

#define SAY_AGGRO "Hmm... the Omnotron Defense System. Centuries ago these constructs were considered the Dwarves greatest technical achievements. With so many counters to each construct's attacks. I''ll have to rectify these designs for them to provide me any entertainement."
#define SAY_STORY "Stupid Dwarnes and you fascination with runes! Why would you create something that would help your enemy?"
#define SAY_LIGHTNING "Lightning conductor works much better in a crowd, yes?"
#define SAY_TOXITRON_CHEMICAL "Were you planning on using Toxitron's chemical to damage the other construcs? Clever plan, let me ruin that for you."
#define SAY_TOO_BAD "You would like to move away from that, wouldn't you? Too bad."
#define SAY_DEATH "Defense systems obliterated. Powering down...."

#define SAY_SHIELD_POISON "Toxitron unit shield system onlines."
#define SAY_SHIELD_FLAMME "Magmatron unit shield system onlines."
#define SAY_SHIELD_ELECTRON "Electron unit shield system onlines."
#define SAY_SHIELD_ARCANOTRON "Arcanotron unit shield system onlines."
#define SAY_ACTIVATION_TOXITRON "Toxitron unit activated."
#define SAY_ACTIVATION_MAGMATRON "Magmatron unit activated."
#define SAY_ACTIVATION_ELECTRON "Electron unit activated."
#define SAY_ACTIVATION_ARCANOTRON "Arcanotron unit activated."
#define SAY_REROUTING_ENERGY "Defense systems obliterated. Powering down...."

enum Spells
{
    // Omnotron
    SPELL_INACTIVE = 78726,
    SPELL_SHUTTING_DOWN = 78746,
    SPELL_ACTIVATED = 78740,
    SPELL_REGEN_EFFECT_MAGMATRON = 95025,
    SPELL_REGEN_EFFECT_TOXITRON = 95022,
    SPELL_REGEN_EFFECT_ELECTRON = 95019,
    SPELL_REGEN_EFFECT_ARCANOTRON = 95028,
    // Electron
    SPELL_LIGHTNING_CONDUCTOR = 79888,
    SPELL_ELECTRICAL_DISCHARGE = 91465,
    SPELL_UNSTABLE_SHIELD = 91447,
    // Toxitron
    SPELL_SUMMON_CHEMICAL_BOMB = 80159,
    SPELL_CHEMICAL_BOMB = 80157, // ZONE
    SPELL_POISON_SOAKED_SHELL = 91501,
    SPELL_POISON_PROTOCOL = 91513,
    // Magmatron
    SPELL_BARRIER = 79582,
    SPELL_ACQUIRING_TARGET = 79501,
    SPELL_FLAMETHROWER = 79504,
    SPELL_INCINERATION_SECURITY_MEASURE = 79023,
    // Arcanotron
    SPELL_SUMMON_POWER_GENERATOR = 79626, 
    SPELL_POWER_GENERATOR = 79624,
    SPELL_ARCANE_ANNIHILATOR = 79710, // Decast
    SPELL_POWER_CONVERSION = 79729,
    // Bombe de Poison
    SPELL_FIXER = 80094,
    SPELL_BOMBE = 80092, // ZONE
    SPELL_FLAC = 80097, // ZONE
    // Summon Spell
    // Chemical Bomb
    SPELL_MIND_FOG_AURA = 76230,
    SPELL_MIND_FOG_VISUAL = 76231,
    SPELL_FOG_DEGAT = 91554,
    // Mode Heroic
    SPELL_GRIP_OF_DEATH = 91849,
    SPELL_ENCASING_SHADOWS = 92023,
    SPELL_OVERCHARGED_POWER_GENERATOR = 91857,
    SPELL_ARCANE_BLOWBACK = 91879,
    SPELL_SHADOW_INFUSION = 92048,
};

// Summon Power Generator = 42733
// Summon Chemical Bomb = 42934
// Omnitron System = 42186
// Actived Spell drain 2 Power Mana / 1s
// Regen Effect add 2 Power Mana / 1s

enum Summons
{
    MOB_POISON_BOMB = 42897, // Aucune imune
};

enum Events
{
    // General
    EVENT_SHUT_DOWN = 1,

    // Omnotron
    EVENT_ACTIVATE_NEXT_CONSTRUCT,
    EVENT_UPDATE_HEALTH,

    // Magmatron
    EVENT_ACQUIRING_TARGET,
    EVENT_INCINERATION_SECURITY_MEASURE,
    EVENT_BARRIER,
    // Toxitron
    EVENT_CHEMICAL_BOMB,
    EVENT_POISON_PROTOCOL,
    EVENT_POISON_SOAKED_SHELL,
    // Electron
    EVENT_LIGHTNING_CONDUCTOR,
    EVENT_ELECTRICAL_DISCHARGE,
    EVENT_UNSTABLE_SHIELD,
    // Arcanotron
    EVENT_POWER_CONVERSION,
    EVENT_POWER_GENERATOR,
    EVENT_ARCANE_ANNIHILATOR,
};

enum Actions
{
    ACTION_OMNOTRON_START_EVENT,
    ACTION_OMNOTRON_RESET,
    ACTION_OMNNOTRON_EVENT_FINISHED,

    ACTION_TRON_ACTIVATE,
    ACTION_EVENT_FAILED,
    ACTION_DEACTIVATE,
};

enum Misc
{
    DATA_IS_FIRST_TRON,
};

Position const wayPos[2] =
{
    {-315.853f, -400.56f, 213.974f,0},
    {-334.152f, -400.321f, 214.005f,0},
};

/**********
** Omnotron
***********/
class boss_omnotron : public CreatureScript
{
public:
    boss_omnotron() : CreatureScript("boss_omnotron") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_omnotronAI (creature);
    }

    struct boss_omnotronAI : public ScriptedAI
    {
        boss_omnotronAI(Creature* creature) : ScriptedAI(creature), eventActive(false), intialized(false)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        bool intialized;
        bool isEncounterDone;

        Creature* trons[4];

        uint8 activateTron;
        bool eventActive;

        void UpdateAI(const uint32 diff)
        {
            if(!intialized)
            {
                trons[0] = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_MAGMATRON));
                trons[1] = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_ELECTRON));
                trons[2] = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_ARCANOTRON));
                trons[3] = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_TOXITRON));

                for(uint8 i = 0; i<=3; i++)
                    if(trons[i] == NULL)
                        return;

                me->SetMaxHealth(trons[0]->GetMaxHealth());

                eventActive = true;
                intialized = true;
                DoAction(ACTION_OMNOTRON_RESET);
            }else
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {

                    case EVENT_ACTIVATE_NEXT_CONSTRUCT:
                        ActivateNextTron();

                        events.ScheduleEvent(EVENT_ACTIVATE_NEXT_CONSTRUCT, 45000);
                        break;

                    case EVENT_UPDATE_HEALTH:
                        for(uint8 i = 0; i<=3; i++)
                            trons[i]->SetHealth(me->GetHealth());

                        events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
                        break;

                    default:
                        break;
                    }
                }		
            }
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case ACTION_OMNOTRON_START_EVENT:

                if (instance)
                    instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, IN_PROGRESS);

                eventActive = true;

                if(me->GetMap()->IsHeroic())
                    me->SummonCreature(NPC_NEFARIAN_HELPER_HEROIC,-302.121f, -349.35f, 220.48f, 4.682203f,TEMPSUMMON_MANUAL_DESPAWN);

                events.ScheduleEvent(EVENT_ACTIVATE_NEXT_CONSTRUCT, 45000);
                events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
                break;

                case ACTION_OMNOTRON_RESET:

                if(eventActive)
                {
                    me->SetFullHealth();
                    eventActive = false;

                    DespawnMinions();
                    events.Reset();

                    ResetTrons();

                    if (instance)
                    instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, FAIL);
                }
                break;

                case ACTION_OMNNOTRON_EVENT_FINISHED:

                DespawnMinions();

                if (instance)
                    instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, DONE);
                
                instance->SetBossState(DATA_MAGMAW, DONE);

                events.Reset();
                eventActive = false;
                break;

            default:
                break;
            }
        }

        void ResetTrons()
        {
            for(uint8 i = 0; i<=3; i++)
                if(trons[i] == NULL)
                    return;

            for(uint8 i = 0; i<=3; i++)
                trons[i]->AI()->SetData(DATA_IS_FIRST_TRON, 0);

            uint8 a = urand(15,25);
            Creature* tronCache;
            for(uint8 i = 0; i<=a; i++)
            {
                uint8 moveDest = urand(0,3);
                uint8 moveTarget = urand(0,3);

                tronCache = trons[moveTarget];
                trons[moveTarget] = trons[moveDest];
                trons[moveDest] = tronCache;
            }

            trons[0]->AI()->SetData(DATA_IS_FIRST_TRON, 1);

            for(uint8 i = 0; i<=3; i++)
                trons[i]->AI()->DoAction(ACTION_EVENT_FAILED);
        };

        void ActivateNextTron()
        {
            for(uint8 i = 0; i<=3; i++)
                if(trons[i] == NULL)
                    return;

            Creature* tronCache = trons[0];

            for(uint8 i = 1; i<=3; i++)
                trons[i-1] = trons[i];

            trons[3] = tronCache;

            trons[0]->AI()->DoAction(ACTION_TRON_ACTIVATE);
            return;
        }

    private:
        inline void DespawnMinions()
        {
            DespawnCreatures(NPC_POISON_BOMB);
            DespawnCreatures(NPC_POISON_CLOUD);
            DespawnCreatures(NPC_NEFARIAN_HELPER_HEROIC);
            DespawnCreatures(NPC_POWER_GENERATOR);
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 100.0f);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }
    };
};

/*******************************************
** Magmatron, Toxitron, Arcanotron, Electron
********************************************/
class boss_trons : public CreatureScript
{
public:
    boss_trons() : CreatureScript("boss_trons") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_tronsAI (creature);
    }

    struct boss_tronsAI : public ScriptedAI
    {
        boss_tronsAI(Creature* creature) : ScriptedAI(creature), activated(false), isFirstTron(false)
        {
            instance = creature->GetInstanceScript();

            creature->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            creature->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
            creature->RemoveFlag(UNIT_FIELD_FLAGS_2,UNIT_FLAG2_REGENERATE_POWER);
            creature->setPowerType(POWER_MANA);
            creature->SetMaxPower(POWER_MANA, 100);

            homePosition = creature->GetHomePosition();
        }

        InstanceScript* instance;
        EventMap events;
        bool activated;
        bool isFirstTron;
        bool isMovingHome;
        Position homePosition;
        Creature* omnotron;

        void EnterCombat(Unit * who)
        {
            if(isFirstTron)
            {
                if (Creature* omnotron = ObjectAccessor::GetCreature(*me,instance->GetData64(BOSS_OMNOTRON)))
                    omnotron->AI()->DoAction(ACTION_OMNOTRON_START_EVENT);

                DoAction(ACTION_TRON_ACTIVATE);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            me->MonsterYell(SAY_DEATH, 0, 0);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id > 2)
                return;

            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);

            switch(id)
            {
            case 0:
                if(!isFirstTron && isMovingHome)
                {
                    isMovingHome = false;
                    me->NearTeleportTo(homePosition.GetPositionX(),homePosition.GetPositionY(),homePosition.GetPositionZ(),homePosition.GetOrientation());
                    me->SetOrientation(homePosition.GetOrientation());
                    me->AddAura(SPELL_INACTIVE, me);
                    WorldPacket data;
                    me->BuildHeartBeatMsg(&data);
                    me->SendMessageToSet(&data, false);
                }
                break;
            case 1: 
                me->GetMotionMaster()->MovePoint(2, wayPos[1]);
                break;
            case 2:
                me->GetMotionMaster()->MovePoint(1, wayPos[0]);
                break;
            }

        }

        void Reset()
        {
            if (Creature* omnotron = ObjectAccessor::GetCreature(*me,instance->GetData64(BOSS_OMNOTRON)))
                omnotron->AI()->DoAction(ACTION_OMNOTRON_RESET);

            me->SetPower(POWER_MANA, 100);
        };

        void DoAction(const int32 action)
        {
            events.Reset();

            switch(action)
            {
            case ACTION_TRON_ACTIVATE:
                me->RemoveAllAuras();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me);
                me->AddAura(SPELL_ACTIVATED, me);
                activated = true;
                isMovingHome = false;

                omnotron = ObjectAccessor::GetCreature(*me,instance->GetData64(BOSS_OMNOTRON));

                switch(me->GetEntry())
                {
                    case NPC_MAGMATRON:
                        if (me->GetPower(POWER_MANA)*100 / me->GetMaxPower(POWER_MANA) < 51)
                        {
                            DoCast(me, SPELL_BARRIER);
                            me->MonsterYell(SAY_SHIELD_FLAMME, 0, 0);
                        }
                        events.ScheduleEvent(EVENT_ACQUIRING_TARGET, 15000);
                        events.ScheduleEvent(EVENT_INCINERATION_SECURITY_MEASURE, 27000);
                        break;

                    case NPC_TOXITRON:
                        if (me->GetPower(POWER_MANA)*100 / me->GetMaxPower(POWER_MANA) < 51)
                        {
                            DoCast(me, SPELL_POISON_SOAKED_SHELL);
                            me->MonsterYell(SAY_SHIELD_POISON, 0, 0);
                        }
                        events.ScheduleEvent(EVENT_CHEMICAL_BOMB, 25000);
                        events.ScheduleEvent(EVENT_POISON_PROTOCOL, 3800);
                        break;

                    case NPC_ELECTRON:
                        if (me->GetPower(POWER_MANA)*100 / me->GetMaxPower(POWER_MANA) < 51)
                        {
                            DoCast(me, SPELL_UNSTABLE_SHIELD);
                            me->MonsterYell(SAY_SHIELD_ELECTRON, 0, 0);
                        }
                        events.ScheduleEvent(EVENT_LIGHTNING_CONDUCTOR, 10000);
                        events.ScheduleEvent(EVENT_ELECTRICAL_DISCHARGE, 25000);
                        break;

                    case NPC_ARCANOTRON:
                        if (me->GetPower(POWER_MANA)*100 / me->GetMaxPower(POWER_MANA) < 51)
                        {
                            DoCast(me, SPELL_POWER_CONVERSION);
                            me->MonsterYell(SAY_SHIELD_ARCANOTRON, 0, 0);
                        }
                        events.ScheduleEvent(EVENT_POWER_GENERATOR, 30000);
                        events.ScheduleEvent(EVENT_ARCANE_ANNIHILATOR, 8000);
                        break;
                }
                return;
                break;

            case ACTION_EVENT_FAILED:
                if(!isFirstTron)
                {
                    DoAction(ACTION_DEACTIVATE);
                }else
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveAllAuras();
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    me->GetMotionMaster()->MovePoint(1, wayPos[0]);
                    activated = true;
                    isMovingHome = false;
                }
                break;

            case ACTION_DEACTIVATE:
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->RemoveAllAuras();
                me->GetMotionMaster()->MovePoint(0, homePosition);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                activated = false;
                isMovingHome = true;

                switch(me->GetEntry())
                {
                    case NPC_MAGMATRON:
                        me->CastSpell(me, SPELL_REGEN_EFFECT_MAGMATRON, true);
                        break;

                    case NPC_TOXITRON:
                        me->CastSpell(me, SPELL_REGEN_EFFECT_TOXITRON, true);
                        break;

                    case NPC_ELECTRON:
                        me->CastSpell(me, SPELL_REGEN_EFFECT_ELECTRON, true);
                        break;

                    case NPC_ARCANOTRON:
                        me->CastSpell(me, SPELL_REGEN_EFFECT_ARCANOTRON, true);
                        break;
                }
                return;
                break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || !activated)
                return;

            if(!me->HasAura(SPELL_ACTIVATED) && !isMovingHome)
            {
                DoAction(ACTION_DEACTIVATE);
                return;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    // Magmatron
                case EVENT_ACQUIRING_TARGET:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 200, true))
                        DoCast(pTarget, SPELL_ACQUIRING_TARGET);
                    me->MonsterYell(SAY_REROUTING_ENERGY, 0, 0);
                    events.ScheduleEvent(EVENT_ACQUIRING_TARGET, 15000);
                    return;
                case EVENT_INCINERATION_SECURITY_MEASURE:
                    DoCastAOE(SPELL_INCINERATION_SECURITY_MEASURE);
                    events.ScheduleEvent(EVENT_INCINERATION_SECURITY_MEASURE, 27000);
                    return;

                    // Toxitron
                case EVENT_CHEMICAL_BOMB:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SUMMON_CHEMICAL_BOMB);
                    events.ScheduleEvent(EVENT_CHEMICAL_BOMB, 30000);
                    return;

                case EVENT_POISON_PROTOCOL:
                    for (uint32 i10 = 0; i10 < 8; ++i10)
                        DoCast(me, SPELL_POISON_PROTOCOL+i10);
                    if (Is25ManRaid())
                        for (uint32 i25 = 0; i25 < 15; ++i25)
                            DoCast(me, SPELL_POISON_PROTOCOL+i25);
                    events.ScheduleEvent(EVENT_POISON_PROTOCOL, 38000);
                    return;

                    // Electron
                case EVENT_LIGHTNING_CONDUCTOR:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_LIGHTNING_CONDUCTOR);
                    me->MonsterYell(SAY_LIGHTNING, 0, 0);
                    events.ScheduleEvent(EVENT_LIGHTNING_CONDUCTOR,10000);
                    return;
                case EVENT_ELECTRICAL_DISCHARGE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_ELECTRICAL_DISCHARGE);
                    events.ScheduleEvent(EVENT_ELECTRICAL_DISCHARGE, 25000);
                    return;

                    // Arcanotron
                case EVENT_POWER_GENERATOR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 200, true))
                        DoCast(target, SPELL_SUMMON_POWER_GENERATOR);
                    events.ScheduleEvent(EVENT_POWER_GENERATOR, 30000);
                    return;
                case EVENT_ARCANE_ANNIHILATOR:
                    me->InterruptNonMeleeSpells(true);
                    if (Is25ManRaid())
                    {
                        std::list<Unit*> targets;
                        SelectTargetList(targets, 3, SELECT_TARGET_RANDOM, 0.0f, true);
                        if (!targets.empty())
                        for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                            DoCast(*itr, SPELL_ARCANE_ANNIHILATOR);
                    } 
                    else						
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, true))
                            DoCast(target, SPELL_ARCANE_ANNIHILATOR);
                    }
                    events.ScheduleEvent(EVENT_ARCANE_ANNIHILATOR, 8000);
                    return;
                }
            }

            DoMeleeAttackIfReady();
        }

        void SetData(uint32 Type, uint32 Data)
        {
            if(Type != DATA_IS_FIRST_TRON)
                return;

            me->SetFullHealth();

            isFirstTron = (Data == 0) ? false : true;
        }

        void DamageTaken(Unit* /*who*/, uint32& damage)
        {
            if(omnotron)
                if(damage >= omnotron->GetHealth())
                {
                    omnotron->AI()->DoAction(ACTION_OMNNOTRON_EVENT_FINISHED);

                    Creature* trons[4];
                    trons[0] = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_MAGMATRON));
                    trons[1] = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_ELECTRON));
                    trons[2] = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_ARCANOTRON));
                    trons[3] = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_TOXITRON));

                    for(uint8 i = 0; i<=3; i++)
                        if(trons[i] != me)
                            trons[i]->ForcedDespawn();
                }
                else
                    omnotron->SetHealth(omnotron->GetHealth()-damage);

        }

        void JustSummoned(Creature* summon)
        {
            summon->setFaction(me->getFaction());
            summon->SetInCombatWithZone();
        }

    };
};

/**************
** Poison Bomb
**************/
class npc_poison_bomb : public CreatureScript
{
    public:
        npc_poison_bomb() : CreatureScript("npc_poison_bomb") { }

        struct npc_poison_bombAI : public ScriptedAI
        {
            npc_poison_bombAI(Creature * pCreature) : ScriptedAI(pCreature) {}

            uint32 uiFixe;
            bool uiBombeFixe;

            void Reset()
            {
                uiFixe = 2000;
                uiBombeFixe = false;
            }

            void Entercombat(Unit * /*who*/)
            {
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                DoZoneInCombat();
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
				
                if(uiFixe <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_FIXER);
                    uiFixe = 2000;
                } else uiFixe -= uiDiff;

                if(!uiBombeFixe)
                {
                    DoCast(me, SPELL_BOMBE, true);
                    DoCast(me, SPELL_FLAC, true);
                    uiBombeFixe = true;
                }

                me->DespawnOrUnsummon(60000);
            }
        };

    CreatureAI* GetAI(Creature* creature) const
	{
        return new npc_poison_bombAI(creature);
    }
};

/******************
** Power Generator
******************/
class mob_power_generator : public CreatureScript
{
public:
    mob_power_generator() : CreatureScript("mob_power_generator") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_power_generatorAI(pCreature);
    }

    struct mob_power_generatorAI : public Scripted_NoMovementAI
    {
        mob_power_generatorAI(Creature* c) : Scripted_NoMovementAI(c)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->AddAura(SPELL_OVERCHARGED_POWER_GENERATOR, me);
            if (IsHeroic())
            {
                me->AddAura(SPELL_SHADOW_INFUSION, me);
            }

            me->ForcedDespawn(60000);
        }
    };
};

/****************
** Chemical Bomb
****************/
class mob_chemical_bomb : public CreatureScript
{
public:
    mob_chemical_bomb() : CreatureScript("mob_chemical_bomb") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_chemical_bombAI(pCreature);
    }

    struct mob_chemical_bombAI : public Scripted_NoMovementAI
    {
        mob_chemical_bombAI(Creature* c) : Scripted_NoMovementAI(c)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            DoCast(SPELL_CHEMICAL_BOMB);
            DoCast(me, SPELL_FOG_DEGAT);
            me->CastSpell(me,SPELL_MIND_FOG_AURA, false);
            me->CastSpell(me,SPELL_MIND_FOG_VISUAL, false);
            if (IsHeroic())
            {
                if (Is25ManRaid())
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 25, SELECT_TARGET_RANDOM, 0.0f, true);
                    if (!targets.empty())
                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        DoCast(*itr, SPELL_GRIP_OF_DEATH);
                } 
                else
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 10, SELECT_TARGET_RANDOM, 0.0f, true);
                    if (!targets.empty())
                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        DoCast(*itr, SPELL_GRIP_OF_DEATH);
                }
            }

            me->ForcedDespawn(60000);
        }
    };
};

/*********************
** Spell Actvated Tron
**********************/
class spell_trons_activated_power : public SpellScriptLoader
{
    public:
        spell_trons_activated_power() : SpellScriptLoader("spell_trons_activated_power") { }

        class spell_trons_activated_power_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_trons_activated_power_SpellScript);

            void ModAuraValue()
            {
                if (Aura* aura = GetHitAura())
                    aura->RecalculateAmountOfEffects();
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_trons_activated_power_SpellScript::ModAuraValue);
            }
        };

        class spell_trons_activated_power_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_trons_activated_power_AuraScript);

            void RecalculateHook(AuraEffect const* /*aurEffect*/, int32& amount, bool& canBeRecalculated)
            {
                amount = int32(GetUnitOwner()->GetPower(POWER_MANA) - 2);
                canBeRecalculated = true;
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_trons_activated_power_AuraScript::RecalculateHook, EFFECT_0, SPELL_AURA_MOD_SCALE);
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_trons_activated_power_AuraScript::RecalculateHook, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
            }

            bool Load()
            {
                if (GetUnitOwner()->getPowerType() != POWER_MANA, - 2)
                    return false;
                return true;
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_trons_activated_power_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_trons_activated_power_AuraScript();
        }
};

/***************************
** Effect Regen Energy Trons
** 95022, 95025, 95028, 95019
*****************************/
class spell_trons_regen_power : public SpellScriptLoader
{
    public:
        spell_trons_regen_power() : SpellScriptLoader("spell_trons_regen_power") { }

        class spell_trons_regen_power_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_trons_regen_power_SpellScript);

            void ModAuraValue()
            {
                if (Aura* aura = GetHitAura())
                    aura->RecalculateAmountOfEffects();
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_trons_regen_power_SpellScript::ModAuraValue);
            }
        };

        class spell_trons_regen_power_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_trons_regen_power_AuraScript);

            void RecalculateHook(AuraEffect const* /*aurEffect*/, int32& amount, bool& canBeRecalculated)
            {
                amount = int32(GetUnitOwner()->GetPower(POWER_MANA) + 2);
                canBeRecalculated = true;
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_trons_regen_power_AuraScript::RecalculateHook, EFFECT_0, SPELL_AURA_MOD_SCALE);
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_trons_regen_power_AuraScript::RecalculateHook, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
            }

            bool Load()
            {
                if (GetUnitOwner()->getPowerType() != POWER_MANA, + 2)
                    return false;
                return true;
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_trons_regen_power_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_trons_regen_power_AuraScript();
        }
};

/***********
** Haut Fait
************/
class achievement_death_omnotron_heroic : public AchievementCriteriaScript
{
    public:
        achievement_death_omnotron_heroic() : AchievementCriteriaScript("achievement_death_omnotron_heroic") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target)
                return false;

            return !target->GetAI()->GetData(DATA_TOXITRON);
        }
};

void AddSC_boss_omnotron_defense_system()
{
    new boss_omnotron();
    new boss_trons();
    new npc_poison_bomb();
    new mob_power_generator();
    new mob_chemical_bomb();
    new spell_trons_activated_power();
    new spell_trons_regen_power();
    new achievement_death_omnotron_heroic();
}
