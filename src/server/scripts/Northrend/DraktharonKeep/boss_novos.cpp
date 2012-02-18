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
#include "drak_tharon_keep.h"

#define SPELL_ARCANE_BLAST                          DUNGEON_MODE(49198,59909)
#define SPELL_ARCANE_FIELD                          47346
#define SPELL_BLIZZARD                              DUNGEON_MODE(49034,59854)
#define SPELL_FROSTBOLT                             DUNGEON_MODE(49037,59855)
#define SPELL_WARTH_OF_MISERY                       DUNGEON_MODE(50089,59856)
#define SPELL_SUMMON_MINIONS                        59910

//not in db
enum Yells
{
    SAY_AGGRO                                     = -1600000,
    SAY_KILL                                      = -1600001,
    SAY_DEATH                                     = -1600002,
    SAY_NECRO_ADD                                 = -1600003,
    SAY_REUBBLE_1                                 = -1600004,
    SAY_REUBBLE_2                                 = -1600005
};

enum Creatures
{
    CREATURE_RISEN_SHADOWCASTER                   = 27600,
    CREATURE_FETID_TROLL_CORPSE                   = 27598,
    CREATURE_HULKING_CORPSE                       = 27597,
    CREATURE_CRYSTAL_HANDLER                      = 26627
};

enum CombatPhase
{
    IDLE,
    PHASE_1,
    PHASE_2
};

#define ACTION_MINION_REACHED                     1
#define DATA_OH_NOVOS                             2

enum Events
{
    EVENT_NONE,
    EVENT_CRYSTAL,
    EVENT_SUMMON,
    EVENT_BLIZZARD,
    EVENT_BLAST,
    EVENT_BOLT,
    EVENT_CURSE,
    EVENT_HERO_SUMMON,
};

#define MAX_SUMMONS                            5

static Position AddSpawnPoint = { -379.20f, -816.76f, 59.70f };
static Position CrystalHandlerSpawnPoint = { -326.626343f, -709.956604f, 27.813314f };
static Position AddDestinyPoint = { -379.314545f, -772.577637f, 28.58837f };

class boss_novos : public CreatureScript
{
public:
    boss_novos() : CreatureScript("boss_novos") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_novosAI (creature);
    }

    struct boss_novosAI : public Scripted_NoMovementAI
    {
        boss_novosAI(Creature* c) : Scripted_NoMovementAI(c), lSummons(me)
        {
            instance = c->GetInstanceScript();
        }

        bool ohNovos;

        SummonList lSummons;
        EventMap events;

        std::list<uint64> luiCrystals;

        CombatPhase Phase;

        InstanceScript* instance;

        void Reset()
        {
            Phase = IDLE;
            luiCrystals.clear();
            ohNovos = true;
            me->CastStop();
            lSummons.DespawnAll();
            events.Reset();

            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (instance)
            {
                instance->SetData(DATA_NOVOS_EVENT, NOT_STARTED);
                for (uint8 n = 0; n < 4; ++n)
                    luiCrystals.push_back(instance->GetData64(DATA_NOVOS_CRYSTAL_1 + n));
                for (std::list<uint64>::const_iterator itr = luiCrystals.begin(); itr != luiCrystals.end(); ++itr)
                {
                    if (GameObject* temp = instance->instance->GetGameObject(*itr))
                        temp->SetGoState(GO_STATE_READY);
                }
            }
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_AGGRO, me);
            Phase = PHASE_1;
            events.ScheduleEvent(EVENT_CRYSTAL,30000);
            events.ScheduleEvent(EVENT_SUMMON,1000);

            me->RemoveAllAuras();
            DoCast(SPELL_ARCANE_FIELD);
            if (instance)
            {
                for (std::list<uint64>::const_iterator itr = luiCrystals.begin(); itr != luiCrystals.end(); ++itr)
                {
                    if (GameObject* temp = instance->instance->GetGameObject(*itr))
                        temp->SetGoState(GO_STATE_ACTIVE);
                }
                instance->SetData(DATA_NOVOS_EVENT, IN_PROGRESS);
            }
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            DoAttackerAreaInCombat(who,100);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING) && Phase!=PHASE_1)
                return;

            Creature* pCrystalHandler;
            Creature* summon;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_CRYSTAL:
                    DoScriptText(SAY_NECRO_ADD, me);
                    pCrystalHandler = me->SummonCreature(CREATURE_CRYSTAL_HANDLER, CrystalHandlerSpawnPoint, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20*IN_MILLISECONDS);
                    pCrystalHandler->GetMotionMaster()->MovePoint(0, AddDestinyPoint);
                    events.ScheduleEvent(EVENT_CRYSTAL,20000);
    //                events.ScheduleEvent(EVENT_CRYSTAL,urand(20000,30000));
                    break;
                case EVENT_SUMMON:
                    summon = me->SummonCreature(RAND(CREATURE_FETID_TROLL_CORPSE,CREATURE_HULKING_CORPSE,CREATURE_RISEN_SHADOWCASTER), AddSpawnPoint, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20*IN_MILLISECONDS);
                    summon->GetMotionMaster()->MovePoint(0, AddDestinyPoint);
                    events.ScheduleEvent(EVENT_SUMMON,4000);
    //                events.ScheduleEvent(EVENT_SUMMON,DUNGEON_MODE(3000,2000));
                    break;
                case EVENT_HERO_SUMMON:
                    for (int i=1;i<=MAX_SUMMONS;i++)
                        me->SummonCreature(CREATURE_FETID_TROLL_CORPSE,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,1000);
                    events.ScheduleEvent(EVENT_HERO_SUMMON,urand(20000,30000));
    //                events.ScheduleEvent(EVENT_HERO_SUMMON,urand(5000,15000));
                case EVENT_BLIZZARD:
                    if (Unit* target=SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                        DoCast(target,SPELL_BLIZZARD);
                    events.ScheduleEvent(EVENT_BLIZZARD,15000);
    //                events.ScheduleEvent(EVENT_BLIZZARD,7500);
                    break;
                case EVENT_BOLT:
                    if (Unit* target=SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                        if (!me->HasUnitState(UNIT_STAT_CASTING))
                            DoCast(target,SPELL_FROSTBOLT);
                        events.ScheduleEvent(EVENT_BOLT,2500);
                    break;
                case EVENT_CURSE:
                    if (Unit* target=SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                        if (!me->HasUnitState(UNIT_STAT_CASTING))
                            DoCast(target,SPELL_WARTH_OF_MISERY);
                        events.ScheduleEvent(EVENT_CURSE,9000);
                    break;
                case EVENT_BLAST:
                    if (Unit* target=SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                        if (!me->HasUnitState(UNIT_STAT_CASTING))
                            DoCast(target,SPELL_ARCANE_BLAST);
                        events.ScheduleEvent(EVENT_BLAST,urand(20000,30000));
                    break;
                }
            }

            /*
            if (!me->hasUnitState(UNIT_STAT_CASTING))
            {
                uint8 cast=(urand(0,100));
                if (cast<=65)
                    events.ScheduleEvent(EVENT_BOLT,0);
                if (cast<90 && cast>65)
                    events.ScheduleEvent(EVENT_CURSE,0);
                if (cast>=90)
                    events.ScheduleEvent(EVENT_BLAST,0);
            } */
        }
        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            if (instance)
                instance->SetData(DATA_NOVOS_EVENT, DONE);
            lSummons.DespawnAll();
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;
            DoScriptText(SAY_KILL, me);
        }

        void JustSummoned(Creature* summon)
        {
            lSummons.Summon(summon);
        }

        void DoAction(int32 const action)
        {
            if (action == ACTION_MINION_REACHED)
                ohNovos = false;
        }

        uint32 GetData(uint32 type)
        {
            if (type == DATA_OH_NOVOS)
                return ohNovos ? 1 : 0;

            return 0;
        }

        void RemoveCrystal()
        {
            if (!luiCrystals.empty())
            {
                if (instance)
                    if (GameObject* temp = instance->instance->GetGameObject(luiCrystals.back()))
                        temp->SetGoState(GO_STATE_READY);
                luiCrystals.pop_back();
            }
            if (luiCrystals.empty())
            {
                me->CastStop();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                Phase = PHASE_2;
                events.Reset();
                events.ScheduleEvent(EVENT_BLIZZARD,0);
                events.ScheduleEvent(EVENT_BLAST,urand(20000,30000));
                events.ScheduleEvent(EVENT_CURSE,5000);
                events.ScheduleEvent(EVENT_BOLT,2000);

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_HERO_SUMMON,0);
            }
        }

        Unit* GetRandomTarget()
        {
            return SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
        }
    };
};

enum CrystalHandlerSpells
{
    SPELL_FLASH_OF_DARKNESS                       = 49668,
    H_SPELL_FLASH_OF_DARKNESS                     = 59004
};

class mob_crystal_handler : public CreatureScript
{
public:
    mob_crystal_handler() : CreatureScript("mob_crystal_handler") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_crystal_handlerAI (creature);
    }

    struct mob_crystal_handlerAI : public ScriptedAI
    {
        mob_crystal_handlerAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiFlashOfDarknessTimer;

        InstanceScript* instance;

        void Reset()
        {
            uiFlashOfDarknessTimer = 5*IN_MILLISECONDS;
        }

        void JustDied(Unit* /*killer*/)
        {
            if (Creature* pNovos = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_NOVOS) : 0))
                CAST_AI(boss_novos::boss_novosAI, pNovos->AI())->RemoveCrystal();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiFlashOfDarknessTimer <= diff)
            {
                DoCast(me->getVictim(), DUNGEON_MODE(SPELL_FLASH_OF_DARKNESS, H_SPELL_FLASH_OF_DARKNESS));
                uiFlashOfDarknessTimer = 5*IN_MILLISECONDS;
            } else uiFlashOfDarknessTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != 0)
                return;
            if (Creature* pNovos = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_NOVOS) : 0))
                if (Unit* target = CAST_AI(boss_novos::boss_novosAI, pNovos->AI())->GetRandomTarget())
                    AttackStart(target);
        }
    };
};

class mob_novos_minion : public CreatureScript
{
public:
    mob_novos_minion() : CreatureScript("mob_novos_minion") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_novos_minionAI (creature);
    }

    struct mob_novos_minionAI : public ScriptedAI
    {
        mob_novos_minionAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        InstanceScript* instance;

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id !=0)
                return;
            if (Creature* Novos = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(DATA_NOVOS) : 0))
            {
                Novos->AI()->DoAction(ACTION_MINION_REACHED);
                if (Unit* target = CAST_AI(boss_novos::boss_novosAI, Novos->AI())->GetRandomTarget())
                    AttackStart(target);
            }
        }
    };
};

class achievement_oh_novos : public AchievementCriteriaScript
{
    public:
        achievement_oh_novos() : AchievementCriteriaScript("achievement_oh_novos")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Novos = target->ToCreature())
                if (Novos->AI()->GetData(DATA_OH_NOVOS))
                    return true;

            return false;
        }
};

void AddSC_boss_novos()
{
    new boss_novos();
    new mob_crystal_handler();
    new mob_novos_minion();
    new achievement_oh_novos();
}
