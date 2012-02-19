/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2012 ArkCORE <http://www.arkania.net/>
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

/* ScriptData
SDName: Boss_Ingvar_The_Plunderer
SD%Complete: 95
SDComment: Some Problems with Annhylde Movement, Blizzlike Timers
SDCategory: Utgarde Keep
EndScriptData */

#include "ScriptPCH.h"
#include "utgarde_keep.h"

enum Yells
{
    //Yells Ingvar
    YELL_AGGRO_1                                = -1574005,
    YELL_AGGRO_2                                = -1574006,

    YELL_DEAD_1                                 = -1574007,
    YELL_DEAD_2                                 = -1574008,

    YELL_KILL_1                                 = -1574009,
    YELL_KILL_2                                 = -1574010,

    YELL_RESSURECT                              = -1574023,
};

enum Creatures
{
    NPC_INGVAR_HUMAN                            = 23954,
 // NPC_ANNHYLDE_THE_CALLER                     = 24068,
    NPC_INGVAR_UNDEAD                           = 23980,
    NPC_THROW_TARGET                            = 23996,
};

enum Spells
{
    //Ingvar Spells human form
    SPELL_CLEAVE                                = 42724,
    SPELL_SMASH                                 = 42669,
    H_SPELL_SMASH                               = 59706,
    SPELL_STAGGERING_ROAR                       = 42708,
    H_SPELL_STAGGERING_ROAR                     = 59708,
    SPELL_ENRAGE                                = 42705,
    H_SPELL_ENRAGE                              = 59707,

    SPELL_INGVAR_FEIGN_DEATH                    = 42795,
    SPELL_SUMMON_BANSHEE                        = 42912,
    SPELL_SCOURG_RESURRECTION                   = 42863, // Spawn resurrect effect around Ingvar

    //Ingvar Spells undead form
    SPELL_DARK_SMASH                            = 42723,
    H_SPELL_DARK_SMASH                          = 59709,
    SPELL_DREADFUL_ROAR                         = 42729,
    H_SPELL_DREADFUL_ROAR                       = 59734,
    SPELL_WOE_STRIKE                            = 42730,
    H_SPELL_WOE_STRIKE                          = 59735,

    SPELL_SHADOW_AXE_SUMMON                     = 42749,
    SPELL_SHADOW_AXE_DAMAGE                     = 42750,
    H_SPELL_SHADOW_AXE_DAMAGE                   = 59719,

    // Annhylde
    SPELL_SCOURG_RESURRECTION_HEAL              = 42704, // Heal Max + DummyAura
    SPELL_SCOURG_RESURRECTION_BEAM              = 42857, // Channeling Beam of Annhylde
    SPELL_SCOURG_RESURRECTION_DUMMY             = 42862, // Some Emote Dummy?
    SPELL_INGVAR_TRANSFORM                      = 42796
};

enum Events
{
    EVENT_SUMMON_ANNHYLDE = 1,
    EVENT_CLEAVE,
    EVENT_PRE_SMASH,
    EVENT_SMASH,
    EVENT_ENRAGE,
    EVENT_SHADOW_AXE,
    EVENT_ROAR
};

class boss_ingvar_the_plunderer : public CreatureScript
{
public:
    boss_ingvar_the_plunderer() : CreatureScript("boss_ingvar_the_plunderer") { }

    struct boss_ingvar_the_plundererAI : public ScriptedAI
    {
        boss_ingvar_the_plundererAI(Creature* c) : ScriptedAI(c)
        {
                _instance = c->GetInstanceScript();
        }

        void Reset()
        {
                if (_isUndead)
                    me->UpdateEntry(NPC_INGVAR_HUMAN);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetStandState(UNIT_STAND_STATE_STAND);

                _events.Reset();
                _isUndead = false;
                _eventInProgress = false;
                _targetGUID = 0;

                _events.ScheduleEvent(EVENT_CLEAVE, 5*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_PRE_SMASH, 12*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_ENRAGE, 10*IN_MILLISECONDS);

                if (_instance)
                    _instance->SetData(DATA_INGVAR_EVENT, NOT_STARTED);
        }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage)
            {
                if (damage >= me->GetHealth() && !_isUndead)
                {
                    // DoCast(me, SPELL_INGVAR_FEIGN_DEATH, true);
                    // visual hack
                me->SetHealth(0);
                me->InterruptNonMeleeSpells(true);
                me->RemoveAllAuras();
                    me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                me->GetMotionMaster()->MovementExpired(false);
                me->GetMotionMaster()->MoveIdle();
                me->SetStandState(UNIT_STAND_STATE_DEAD);
                    // visual hack end

                    _events.Reset();
                    _events.ScheduleEvent(EVENT_SUMMON_ANNHYLDE, 3*IN_MILLISECONDS);
                    _eventInProgress = true;
                    _isUndead = true;

                DoScriptText(YELL_DEAD_1, me);
            }

                if (_eventInProgress)
            {
                damage = 0;
            }
        }

        void StartZombiePhase()
        {
                _isUndead = true;
                _eventInProgress = false;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                me->UpdateEntry(NPC_INGVAR_UNDEAD);
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me);
                if (me->getVictim())
                {
            me->SetInCombatWith(me->getVictim());
            me->GetMotionMaster()->MoveChase(me->getVictim());
                }

                _events.ScheduleEvent(EVENT_CLEAVE, 3*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_PRE_SMASH, 7*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_SHADOW_AXE, 15*IN_MILLISECONDS);
        }

        void EnterCombat(Unit* /*who*/)
        {
                DoScriptText(_isUndead ? YELL_AGGRO_2 : YELL_AGGRO_1, me);

                if (_instance)
                    _instance->SetData(DATA_INGVAR_EVENT, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(YELL_DEAD_2, me);

                if (_instance)
                    _instance->SetData(DATA_INGVAR_EVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
                DoScriptText(_isUndead ? YELL_KILL_1 : YELL_KILL_2, me);
        }

            void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

                if (me->HasReactState(REACT_PASSIVE) && !_eventInProgress && !me->getVictim())
                    me->SetReactState(REACT_AGGRESSIVE);

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_ANNHYLDE:
                        DoCast(me, SPELL_SUMMON_BANSHEE); // Summons directly on caster position
                        // DoCast(me, SPELL_SCOURG_RESURRECTION, true); // Not needed ?
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(_isUndead ? DUNGEON_MODE(SPELL_WOE_STRIKE, H_SPELL_WOE_STRIKE) : SPELL_CLEAVE);
                            _events.ScheduleEvent(EVENT_CLEAVE, urand(4, 7) *IN_MILLISECONDS);
                            break;
                        case EVENT_PRE_SMASH:
                        {
                            // some workaround due to ingvar always trying to face victim when casting smash
                    float x, y, z;
                    z = me->GetPositionZ();
                            me->GetNearPoint2D(x, y, 3.0f, me->GetOrientation());

                            if (Creature* target = me->SummonCreature(22515, x, y, z + 2.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 4000))
                            {
                                _targetGUID = target->GetGUID();
                                target->SetMaxHealth(100000);
                                target->SetHealth(100000);
                                target->SetReactState(REACT_PASSIVE);
                                target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_PASSIVE);
                                AttackStart(target);
                                me->SetReactState(REACT_PASSIVE);
                                me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                            }
                            _events.ScheduleEvent(EVENT_SMASH, 700);
                            return;
                        }
                        case EVENT_SMASH:
                        {
                            if (Creature* target = ObjectAccessor::GetCreature(*me, _targetGUID))
                            {
                                DoCast(target, _isUndead ? DUNGEON_MODE(SPELL_DARK_SMASH, H_SPELL_DARK_SMASH)
                                                         : DUNGEON_MODE(SPELL_SMASH, H_SPELL_SMASH));
                                me->SetFacingToObject(target);
                            }
                            _targetGUID = 0;
                            _events.ScheduleEvent(EVENT_ROAR, urand(4, 5) *IN_MILLISECONDS);
                            _events.ScheduleEvent(EVENT_PRE_SMASH, 14300);
                            return;
                        }
                        case EVENT_ENRAGE:
                DoCast(me, DUNGEON_MODE(SPELL_ENRAGE,H_SPELL_ENRAGE));
                            _events.ScheduleEvent(EVENT_ENRAGE, 10*IN_MILLISECONDS);
                            break;
                        case EVENT_SHADOW_AXE:
                        // Spawn target for Axe
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                        {
                                me->SummonCreature(NPC_THROW_TARGET, *target, TEMPSUMMON_TIMED_DESPAWN, 2000);
                            DoCast(me, SPELL_SHADOW_AXE_SUMMON);
                        }
                            _events.ScheduleEvent(EVENT_SHADOW_AXE, 30*IN_MILLISECONDS);
                            break;
                        case EVENT_ROAR:
                            DoCast(me, _isUndead ? DUNGEON_MODE(SPELL_DREADFUL_ROAR, H_SPELL_DREADFUL_ROAR)
                                                 : DUNGEON_MODE(SPELL_STAGGERING_ROAR, H_SPELL_STAGGERING_ROAR));
                            break;
                        default:
                            break;
                    }
                }

                if (!_eventInProgress)
            DoMeleeAttackIfReady();
        }

        private:
            InstanceScript* _instance;
            EventMap _events;
            uint64 _targetGUID;
            bool _isUndead;
            bool _eventInProgress;
    };

        CreatureAI* GetAI(Creature* creature) const
{
            return new boss_ingvar_the_plundererAI(creature);
        }
};

class mob_annhylde_the_caller : public CreatureScript
{
public:
    mob_annhylde_the_caller() : CreatureScript("mob_annhylde_the_caller") { }

    struct mob_annhylde_the_callerAI : public ScriptedAI
    {
        mob_annhylde_the_callerAI(Creature* c) : ScriptedAI(c)
        {
                _instance = c->GetInstanceScript();
        }

        void Reset()
        {
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING | MOVEMENTFLAG_HOVER);
            me->SetSpeed(MOVE_SWIM, 1.0f);
            me->SetSpeed(MOVE_RUN, 1.0f);
            me->SetSpeed(MOVE_WALK, 1.0f);
            //me->SetSpeed(MOVE_FLIGHT, 1.0f);

                me->GetPosition(_x, _y, _z);
                DoTeleportTo(_x + 1, _y, _z + 30);

                if (Unit* ingvar = ObjectAccessor::GetUnit(*me, _instance ? _instance->GetData64(DATA_INGVAR) : 0))
                    me->GetMotionMaster()->MovePoint(1, _x, _y, _z + 15);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

                if (Unit* ingvar = ObjectAccessor::GetUnit(*me, _instance ? _instance->GetData64(DATA_INGVAR) : 0))
            {
                switch (id)
                {
                case 1:
                            DoScriptText(YELL_RESSURECT, me);
                    ingvar->RemoveAura(SPELL_SUMMON_BANSHEE);
                    ingvar->CastSpell(ingvar, SPELL_SCOURG_RESURRECTION_DUMMY, true);
                    DoCast(ingvar, SPELL_SCOURG_RESURRECTION_BEAM);
                            _resurectTimer = 8000;
                            _resurectPhase = 1;
                    break;
                case 2:
                    me->SetVisible(false);
                    me->DealDamage(me, me->GetHealth());
                    me->RemoveCorpse();
                    break;
                }
            }
        }

        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void EnterCombat(Unit* /*who*/) {}

            void UpdateAI(uint32 const diff)
            {
                if (_resurectTimer)
                {
                    if (_resurectTimer <= diff)
                    {
                        if (_resurectPhase == 1)
                        {
                            if (Unit* ingvar = ObjectAccessor::GetUnit(*me, _instance ? _instance->GetData64(DATA_INGVAR) : 0))
                        {
                            ingvar->SetStandState(UNIT_STAND_STATE_STAND);
                            ingvar->CastSpell(ingvar, SPELL_SCOURG_RESURRECTION_HEAL, false);
                        }
                            _resurectTimer = 3000;
                            _resurectPhase = 2;
                    }
                        else if (_resurectPhase == 2)
                    {
                            if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance ? _instance->GetData64(DATA_INGVAR) : 0))
                        {
                            ingvar->RemoveAurasDueToSpell(SPELL_SCOURG_RESURRECTION_DUMMY);

                            if (boss_ingvar_the_plunderer::boss_ingvar_the_plundererAI* pAI = CAST_AI(boss_ingvar_the_plunderer::boss_ingvar_the_plundererAI, ingvar->AI()))
                                pAI->StartZombiePhase();

                                me->GetMotionMaster()->MovePoint(2, _x + 1, _y, _z + 30);
                                ++_resurectPhase;
                                _resurectTimer = 0;
                            }
                        }
                    }
                    else
                        _resurectTimer -= diff;
                }
            }

        private:
            float _x, _y, _z;
            InstanceScript* _instance;
            uint32 _resurectTimer;
            uint8 _resurectPhase;
    };

        CreatureAI* GetAI(Creature* creature) const
{
            return new mob_annhylde_the_callerAI(creature);
        }
};

class mob_ingvar_throw_dummy : public CreatureScript
{
public:
    mob_ingvar_throw_dummy() : CreatureScript("mob_ingvar_throw_dummy") { }

    struct mob_ingvar_throw_dummyAI : public ScriptedAI
    {
        mob_ingvar_throw_dummyAI(Creature* c) : ScriptedAI(c) { }

        void Reset()
        {
                if (Unit* target = me->FindNearestCreature(NPC_THROW_TARGET, 50.0f))
            {
                float x, y, z;
                target->GetPosition(x, y, z);
                me->GetMotionMaster()->MovePoint(1, x, y, z);
            }
                _reachedTarget = false;
                _despawnTimer = 10000;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

                _reachedTarget = true;
            DoCast(me, DUNGEON_MODE(SPELL_SHADOW_AXE_DAMAGE,H_SPELL_SHADOW_AXE_DAMAGE));
        }

        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void EnterCombat(Unit* /*who*/) {}

            void UpdateAI(uint32 const diff)
        {
                if (_reachedTarget)
                    if (_despawnTimer <= diff)
            {
                me->DealDamage(me, me->GetHealth());
                me->RemoveCorpse();
                    }
                    else
                        _despawnTimer -= diff;
            }

        private:
            bool _reachedTarget;
            uint32 _despawnTimer;
    };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ingvar_throw_dummyAI(creature);
        }
};

void AddSC_boss_ingvar_the_plunderer()
{
    new boss_ingvar_the_plunderer();
    new mob_annhylde_the_caller();
    new mob_ingvar_throw_dummy();
}
