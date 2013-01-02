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
#include "blackwing_descent.h"
#include "ObjectMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

/*
Onyxia = 41270
Nefarian = 41376
Prototype = 41948
Warrior bone = 41918
*/

enum Texts
{
    SAY_INTRO                     = 0,
    SAY_AGGRO                     = 1,
    SAY_KILL_1                    = 2,
    SAY_KILL_2                    = 3,
    SAY_EVENT_ONYXIA              = 4,
    SAY_EVENT_PROTOTYPE           = 5,
    SAY_EVENT_P3                  = 6,
    SAY_DEATH                     = 7,
};

enum Spells
{
    // Nefarian
    SPELL_ELECTROCUTE             = 94089,
    SPELL_SHADOWFLAME_BREATH      = 77826,
    SPELL_TAIL_LASH               = 23364,
    SPELL_SHADOW_OF_COWARDICE     = 79353, // All Phases
    // Heroic Mode
    SPELL_EXPLOSIVE_CINDERS       = 79339,
    //P1
    SPELL_CHILDREN_OF_DEATHWING   = 78619,
    SPELL_HAIL_OF_BONES           = 78684,
    SPELL_DOMINION                = 79318,
    //P2
    SPELL_SHADOWFLAME_BARRAGE     = 78621,
    //P3
    SPELL_SHADOWBLAZE_SPARK       = 81031,
	
    // Onyxia
    SPELL_SHADOW_BREATH           = 77826,
    SPELL_LIGHTNING_DISCHARGE     = 94107,
    SPELL_OVERLOAD                = 78999,
	
    // Animated Bone Warrior
    SPELL_EMPOWER                 = 79330,
    SPELL_HURL_BONE               = 81586,
	
    // Prototype Chromatique
    SPELL_BLAST_NOVA              = 80734,
};

enum NefarianActions
{
    ACTION_ONYXIA_RESET,
    ACTION_ONYXIA_DIED,
    ACTION_PROTOTYPE_RESET,
    ACTION_PROTOTYPE_DIED
};

struct sNefaMove
{
    uint32 uiLocId;
    uint32 uiLocIdEnd;
    uint32 uiSpellId;
    float fX, fY, fZ;
};

// Position Sud - Est - Ouest
const Position aSpawnLocations[] = 
{
    {-138.410339f, -250.865982f, 25.165585f, 0.00f},
    {-71.121140f, -235.487427f, 35.362190f, 0.00f},
    {-118.801903f, -183.530136f, 31.782761f, 0.00f},
};

// Point de pop War Ossement
const Position OsSpawnLocations[] = 
{
    {-135.034927f, -195.426865f, 20.359344f, 0.00f},
    {-133.972275f, -246.354782f, 20.359377f, 0.00f},
    {-111.243645f, -182.850723f, 20.358669f, 0.00f},
    {-113.298744f, -261.105133f, 20.359344f, 0.00f},
};

const Position MiddleRoomLocation = {-103.057961f, -222.698685f, 18.374910f, 0.0f};

const Position Phase2Location = {-103.057961f, -222.698685f, 36.959911f, 0.0f};

const Position OnyxiaLocation = {-102.864f, -222.71f, 18.3749f, 3.1601f};

Creature* pOnyxia;
Creature* pPrototype;
Creature* pNefarian;

/***********
** Nefarian
************/
class boss_bd_nefarian : public CreatureScript
{
public:
    boss_bd_nefarian() : CreatureScript("boss_bd_nefarian") { }

    struct boss_bd_nefarianAI : public BossAI
    {
        boss_bd_nefarianAI(Creature* pCreature) : BossAI(pCreature, BOSS_NEFARIAN)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
            pNefarian = me;
            pInstance = pCreature->GetInstanceScript();
        }

        std::list<uint64> SummonList;

        InstanceScript *pInstance;

        uint32 Phase;
        uint8 SpawnCount;

        uint32 ShadowCowardiceTimer;
        uint32 ShadowflameBreathTimer;
        uint32 TailLashTimer;
        uint32 HailOfBonesTimer;
        uint32 ShadowflameBarrageTimer;
        uint32 ShadowblazeSparkimer;
        uint32 ExplosiveCindersTimer;

        void Reset()
        {
            Phase = 1;
            RemoveSummons();

            SpawnCount = 3;

            ShadowCowardiceTimer = urand(19000, 27000);
            ShadowflameBreathTimer = urand(22000, 35000);
            TailLashTimer = urand(15000, 22000);
            HailOfBonesTimer = urand(19000, 27000);
            ShadowflameBarrageTimer = urand(14000, 26000);
            ShadowblazeSparkimer = urand(10000, 20000);
            ExplosiveCindersTimer = urand(18000, 23000);

            //me->SummonCreature(41270, -102.864f, -222.71f, 18.3749f, 3.1601f, TEMPSUMMON_CORPSE_DESPAWN);
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            switch(summon->GetEntry())
            {
                case NPC_PROTOTYPE:
                    SpawnCount--;
                    break;
            }
        }

        void RemoveSummons()
        {
            if (SummonList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
            {
                if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                    if (pTemp)
                        pTemp->DisappearAndDie();
            }
            SummonList.clear();
        }

        void KilledUnit(Unit* victim)
        {
            Talk(RAND(SAY_KILL_1,SAY_KILL_2));
        }

        void JustSummoned(Creature* pSummon)
        {
            switch (pSummon->GetEntry())
            {
                case NPC_PROTOTYPE:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        pSummon->AI()->AttackStart(pTarget);
                    SummonList.push_back(pSummon->GetGUID());
                    break;
            }
        }

	    void EnterCombat(Unit* who)
        {
            Talk(SAY_AGGRO);		
        	_EnterCombat();
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            _JustDied();
            //DespawnMinions();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            switch(Phase)
            {
                case 1:
                    if (!HealthAbovePct(90)) DoCast(SPELL_ELECTROCUTE);
                    if (!HealthAbovePct(80)) DoCast(SPELL_ELECTROCUTE);
                    if (!HealthAbovePct(70)) DoCast(SPELL_ELECTROCUTE);
                    break;
                case 2:
                    if (!HealthAbovePct(60)) DoCast(SPELL_ELECTROCUTE);
                    break;
                case 3:
                    if (!HealthAbovePct(50)) DoCast(SPELL_ELECTROCUTE);
                    if (!HealthAbovePct(40)) DoCast(SPELL_ELECTROCUTE);
                    if (!HealthAbovePct(30)) DoCast(SPELL_ELECTROCUTE);
                    if (!HealthAbovePct(20)) DoCast(SPELL_ELECTROCUTE);
                    if (!HealthAbovePct(10)) DoCast(SPELL_ELECTROCUTE);
                    break;
            }

            if (((me->GetHealth()*100 / me->GetMaxHealth()) < 70) && (Phase == 1))
            {
                Phase = 2;
            }

            if (((me->GetHealth()*100 / me->GetMaxHealth()) < 60) && (Phase == 2))
            {
                Phase = 3;
            }

            if (Phase == 1)
            {
                // Ici Script P1
                instance->DoSendNotifyToInstance("INSTANCE MESSAGE: Nefarian Phase 1");

                if (ShadowCowardiceTimer <= diff)
                {
				    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                    DoCast(pTarget, SPELL_SHADOW_OF_COWARDICE);
                    ShadowCowardiceTimer = urand(19000, 27000);
                } else ShadowCowardiceTimer -= diff;
				
                if (HailOfBonesTimer <= diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 200, true))
                    DoCast(pTarget, SPELL_HAIL_OF_BONES);
                    me->SummonCreature(NPC_WAR_OS, OsSpawnLocations[0].GetPositionX(), OsSpawnLocations[0].GetPositionY(), OsSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_WAR_OS, OsSpawnLocations[1].GetPositionX(), OsSpawnLocations[1].GetPositionY(), OsSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_WAR_OS, OsSpawnLocations[2].GetPositionX(), OsSpawnLocations[2].GetPositionY(), OsSpawnLocations[2].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_WAR_OS, OsSpawnLocations[3].GetPositionX(), OsSpawnLocations[3].GetPositionY(), OsSpawnLocations[3].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    HailOfBonesTimer = urand(19000, 27000);
                } else HailOfBonesTimer -= diff;
				
                if (ShadowflameBreathTimer <= diff)
                {
                    DoCastVictim(SPELL_SHADOWFLAME_BREATH);
                    ShadowflameBreathTimer = urand(22000, 35000);
                } else ShadowflameBreathTimer -= diff;
				
                if (TailLashTimer <= diff)
                {
                    DoCastAOE(SPELL_TAIL_LASH);
                    TailLashTimer = urand(15000, 22000);
                } else TailLashTimer -= diff;
            }
			
            if (Phase == 2)
            {
                // Ici Script P2
                me->RemoveAllAuras();
				
                Talk(SAY_EVENT_PROTOTYPE);
                instance->DoSendNotifyToInstance("INSTANCE MESSAGE: Nefarian Call Prototype");
                instance->DoSendNotifyToInstance("INSTANCE MESSAGE: Nefarian Phase 2");

                SetCombatMovement(false);
                me->SetFlying(true);
                float x, y, z, o;
                me->GetMotionMaster()->MovePoint(x, y, 2, o);

                me->SummonCreature(NPC_PROTOTYPE, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(NPC_PROTOTYPE, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(NPC_PROTOTYPE, aSpawnLocations[2].GetPositionX(), aSpawnLocations[2].GetPositionY(), aSpawnLocations[2].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                return;
				
                if (IsHeroic())
                {
                    if (ExplosiveCindersTimer <= diff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                        DoCast(pTarget, SPELL_EXPLOSIVE_CINDERS);
                        ExplosiveCindersTimer = urand(18000, 23000);
                    } else ExplosiveCindersTimer -= diff;
                }
				
                if (ShadowCowardiceTimer <= diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                    DoCast(pTarget, SPELL_SHADOW_OF_COWARDICE);
                    ShadowCowardiceTimer = urand(19000, 27000);
                } else ShadowCowardiceTimer -= diff;
					
                if (ShadowflameBarrageTimer <= diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                    DoCast(pTarget, SPELL_SHADOWFLAME_BARRAGE);
                    ShadowflameBarrageTimer = urand(14000, 26000);
                } else ShadowflameBarrageTimer -= diff;
            }
			
            if (Phase == 3)
            {
                // Ici Script P3
                me->RemoveAllAuras();

                SetCombatMovement(true);
                me->SetFlying(false);
                float x, y, z, o;
                me->GetMotionMaster()->MovePoint(x, y, 0, o);

                Talk(SAY_EVENT_P3);
                instance->DoSendNotifyToInstance("INSTANCE MESSAGE: Nefarian Phase 3");

                if (ShadowblazeSparkimer <= diff)
                {
                    DoCastAOE(SPELL_SHADOWBLAZE_SPARK);
                	ShadowblazeSparkimer = urand(10000, 20000);
                } else ShadowblazeSparkimer -= diff;

                if (ShadowCowardiceTimer <= diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 200, true))
                    DoCast(pTarget, SPELL_SHADOW_OF_COWARDICE);
                    ShadowCowardiceTimer = urand(19000, 27000);
                } else ShadowCowardiceTimer -= diff;

                if (ShadowflameBreathTimer <= diff)
                {
                    DoCastVictim(SPELL_SHADOWFLAME_BREATH);
                    ShadowflameBreathTimer = urand(22000, 35000);
                } else ShadowflameBreathTimer -= diff;

                if (TailLashTimer <= diff)
                {
                    DoCastAOE(SPELL_TAIL_LASH);
                    TailLashTimer = urand(15000, 22000);
                } else TailLashTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature *pCreature) const
    {
        return new boss_bd_nefarianAI (pCreature);
    }
};

/*********
** Onyxia
**********/
enum Events
{
    // Onyxia
    EVENT_TAIL_LASH,
    EVENT_SHADOWFLAME_BREATH,
    EVENT_LIGHTNING_DISCHARGE,
    EVENT_OVERLOAD,
};

class npc_bwd_onyxia : public CreatureScript
{
public:
    npc_bwd_onyxia() : CreatureScript("npc_bwd_onyxia") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_bwd_onyxiaAI (pCreature);
    }

    struct npc_bwd_onyxiaAI : public ScriptedAI
    {
        npc_bwd_onyxiaAI(Creature *c) : ScriptedAI(c) 
        {
            instance = c->GetInstanceScript();
            pOnyxia = me;
			
            me->RemoveFlag(UNIT_FIELD_FLAGS_2,UNIT_FLAG2_REGENERATE_POWER);
            me->setPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 0);
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            me->SetPower(POWER_MANA,0);
            events.Reset();

            DespawnMinions();
			
            if (instance)
          {
                if (Creature *pNefarian = me->GetCreature(*me, instance->GetData64(DATA_NEFARIAN)))
              {
                        if (pNefarian->AI())
                          pNefarian->AI()->DoAction(ACTION_ONYXIA_RESET);
                      pNefarian->SetPhaseMask(2, true);
              }
          }
        }
		
        void EnterCombat(Unit* who)
        {
            events.ScheduleEvent(EVENT_LIGHTNING_DISCHARGE, urand(24000,51000));
            events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, urand(24000,44000));
            events.ScheduleEvent(EVENT_TAIL_LASH, urand(15000,22000));

            //Position pos;
            //me->GetPosition(&pos);
            //me->SummonCreature(41376, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
            pNefarian->SetPhaseMask(1, true);
        }
		
        void JustDied(Unit * /*killer*/)
        {
            if (instance)
                if (Creature *pNefarian = me->GetCreature(*me, instance->GetData64(DATA_NEFARIAN)))
                    if (pNefarian->AI())
                        pNefarian->AI()->DoAction(ACTION_ONYXIA_DIED);
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
                    case EVENT_LIGHTNING_DISCHARGE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 10.0f, true))
                        DoCast(target, SPELL_LIGHTNING_DISCHARGE);
                    events.ScheduleEvent(EVENT_LIGHTNING_DISCHARGE, urand(24000,51000));
                    break;
					
                    case EVENT_SHADOWFLAME_BREATH:
                        DoCast(me->getVictim(), SPELL_SHADOW_BREATH);
                    events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, urand(24000,44000));
                    break;
					
                    case EVENT_TAIL_LASH:
                        DoCast(me, SPELL_TAIL_LASH);
                    events.ScheduleEvent(EVENT_TAIL_LASH, urand(15000,22000));
                    break;
					
                    /*case EVENT_OVERLOAD:
                    instance->DoSendNotifyToInstance("INSTANCE MESSAGE: Electrical Overload"); // Notification du WHYPE ^^
                    if (me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA))
                        DoCastAOE(SPELL_OVERLOAD);
                    events.ScheduleEvent(EVENT_OVERLOAD, true);
                    break;*/
					
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        inline void DespawnMinions()
        {
            DespawnCreatures(NPC_WAR_OS);
            DespawnCreatures(NPC_PROTOTYPE);
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

/***********************
** Chromatic Prototype
************************/
class npc_chromatic_prototype : public CreatureScript
{
public:
    npc_chromatic_prototype() : CreatureScript("npc_chromatic_prototype") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_chromatic_prototypeAI (pCreature);
    }

    struct npc_chromatic_prototypeAI : public ScriptedAI
    {
        npc_chromatic_prototypeAI(Creature *c) : ScriptedAI(c) 
        {
            pPrototype = me;
            instance = c->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 uiBlast_Nova;

        void Reset()
        {
            uiBlast_Nova = 12000;
			
            if (instance)
            if (Creature *pNefarian = me->GetCreature(*me, instance->GetData64(DATA_NEFARIAN)))
                if (pNefarian->AI())
                    pNefarian->AI()->DoAction(ACTION_PROTOTYPE_RESET);
        }
		
        void JustDied(Unit* /*killer*/)
        {
            me->DespawnOrUnsummon(5000);
			
            if (instance)
            if (Creature *pNefarian = me->GetCreature(*me, instance->GetData64(DATA_NEFARIAN)))
                if (pNefarian->AI())
                    pNefarian->AI()->DoAction(ACTION_PROTOTYPE_DIED);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            
            if(uiBlast_Nova <= diff)
            {
                me->InterruptNonMeleeSpells(true);
                DoCastAOE(SPELL_BLAST_NOVA);
                uiBlast_Nova = 12000;
            } else uiBlast_Nova -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

/***********************
** Animated Bone Warrior
************************/
class npc_animated_bone_warrior : public CreatureScript
{
public:
    npc_animated_bone_warrior() : CreatureScript("npc_animated_bone_warrior") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_animated_bone_warriorAI (pCreature);
    }

    struct npc_animated_bone_warriorAI : public ScriptedAI
    {
        npc_animated_bone_warriorAI(Creature *c) : ScriptedAI(c) {}

        uint32 uiEmpower;
        uint32 uiHurl_Bone;

        void Reset()
        {
            uiEmpower = 20000;
            uiHurl_Bone = 10000;
        }

        void JustDied(Unit* /*killer*/)
        {
            me->DespawnOrUnsummon(5000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            
            if(uiEmpower <= diff)
            {
                DoCast(me, SPELL_EMPOWER);
                uiEmpower = 20000;
            } else uiEmpower -= diff;
			
            if(uiHurl_Bone <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                DoCast(target, SPELL_HURL_BONE);
                uiHurl_Bone = 10000;
            } else uiHurl_Bone -= diff;
			
            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_bwd_nefarian()
{
    new boss_bd_nefarian();
    new npc_bwd_onyxia();
    new npc_animated_bone_warrior();
    new npc_chromatic_prototype();
}