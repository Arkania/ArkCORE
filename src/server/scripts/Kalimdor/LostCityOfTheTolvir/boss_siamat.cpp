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
#include "WorldPacket.h"
#include "the_lost_city_of_tol_vir.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

// Minion Of Siamat 44704
// Servant Of Siamat 45269
// Cloud Burst 44541

enum Texts
{
    SAY_INTRO = 0,
    SAY_AGGRO = 1,
    SAY_EVENT_1 = 2,
    SAY_EVENT_2 = 2,
    SAY_EVENT_3 = 2,
    SAY_KILL = 3,
    SAY_DEATH = 4,
};

enum Spells
{
    // Siamat
    SPELL_DEFLECTING_WINDS = 84589, // Initial shield
    SPELL_STORM_BOLT_CASTING = 73564,
    SPELL_STORM_BOLT_RANDOM = 91853,
    H_SPELL_STORM_BOLT_RANDOM =95180 ,
    SPELL_ABSORB_STORMS = 83151, // AOE
    SPELL_CLOUD_BURST_SUMMON = 83790,
    SPELL_WAILING_WINDS = 90031,

    // Minion Of Siamat
    SPELL_DEPLETION = 84550, // Aura
    SPELL_TEMPEST_STORM = 83446,
    H_SPELL_TEMPEST_STORM = 90030,
    SPELL_TEMPEST_STORM_FORM =83170, // Form Tempest
    SPELL_TEMPEST_STORM_AURA = 83406, // Aura Tempest
    SPELL_TEMPEST_STORM_ROOT = 84616, // Pre summon Tempest
    SPELL_TEMPEST_STORM_SUMMON = 83414,
    SPELL_CHAIN_LIGHTNING = 83455,
    H_SPELL_CHAIN_LIGHTNING = 90027,

    // Servant Of Siamat
    SPELL_THUNDER_CRASH = 84522,
    H_SPELL_THUNDER_CRASH = 90016,
    SPELL_LIGHTNING_NOVA = 84544,
    H_SPELL_LIGHTNING_NOVA = 90015,
    SPELL_LIGHTNING_CHARGE = 91872,

    // Cloud
    SPELL_CLOUD_BURST_VISUAL = 83048, // Aura Cloud
    SPELL_CLOUD_BURST = 83051,
    H_SPELL_CLOUD_BURST = 90032,

    // Wind Tunnel
    SPELL_VISUAL_WIND = 89698,
};

enum Events
{
    // Siamat Event
    EVENT_DEFLECTING_WINDS = 1,
    EVENT_STORM_BOLT_RANDOM = 2,
    EVENT_REMOVE_DEFLECTIVE_WINGS = 4,
    EVENT_SUMMON_NPC_SERVANT_OF_SIAMAT = 5,
    EVENT_SUMMON_NPC_MINION_OF_SIAMAT = 6,
    EVENT_SUMMON_NPC_MINION_OF_SIAMAT_STORM = 7,
    EVENT_WAILING_WINDS = 8,
    EVENT_ABSORB_STORMS = 9,

    // Servant Of Siamat Event
    EVENT_THUNDER_CRASH = 10,
    EVENT_LIGHTNING_NOVA = 11,
    EVENT_LIGHTNING_CHARGE = 12,
    EVENT_SERVANT_DEATH = 13,

    // Cloud Event
    EVENT_CLOUD_BURST_SUMMON = 14,
    EVENT_CLOUD_BURST = 15,
    EVENT_CLOUD_BURST_VISUAL = 16,
    EVENT_DESPAWN_CLOUD_BURST = 17,
    
    // Minion Of Siamat Event
    EVENT_TEMPEST_STORM = 18,
    EVENT_TEMPEST_STORM_SUMMON = 19,
    EVENT_DEPLETION = 20,
    EVENT_DESPAWN_STORMS = 21,

};

enum Timers
{
    TIME_BETWEEN_SERVANT_RESPAWN = 45000,
    TIME_BETWEEN_MINION_RESPAWN = 25000,
};

Position const SummonPositions[6] =
{
    {-10932.976563f, -1412.421875f, 38.000f, 2.3993f}, // Servant position 1
    {-10944.905273f, -1379.742554f, 38.000f, 4.4963f}, // Servant position 2
    {-10966.986328f, -1406.212524f, 38.000f, 0.4218f}, // Servant position 3
    {-10920.614000f, -1389.605000f, 38.000f, 3.5585f}, // minion position 1
    {-10970.000000f, -1380.000000f, 38.000f, 5.6060f}, // minion position 2
    {-10953.592700f, -1427.816000f, 38.000f, 1.3327f}, // minion position 3
};

/*************
** Boss Siamat
**************/
class boss_siamat : public CreatureScript
{
    public:
        boss_siamat() : CreatureScript("boss_siamat") {}

        CreatureAI* GetAI(Creature* pCreature) const
        {
           return new boss_siamatAI(pCreature);
        }
        struct boss_siamatAI : public ScriptedAI
        {
            boss_siamatAI(Creature* creature) : ScriptedAI(creature), Summons(me)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            uint32 DATA_REMOVE_DEFLECTIVE_WINGS;
            uint32 timer[2];
            SummonList Summons;

            void Reset ()
            {
                timer[0] = 0;
                timer[1] = 0;
                DATA_REMOVE_DEFLECTIVE_WINGS = 1;
                events.Reset();
                Summons.DespawnAll();
                events.CancelEvent(EVENT_DEFLECTING_WINDS);
                events.ScheduleEvent(EVENT_STORM_BOLT_RANDOM, urand(10000, 17000));
                events.ScheduleEvent(EVENT_CLOUD_BURST, urand(10000, 15000));
                events.ScheduleEvent(EVENT_DEFLECTING_WINDS, 0);
                events.ScheduleEvent(EVENT_SUMMON_NPC_SERVANT_OF_SIAMAT, 0);
                events.ScheduleEvent(EVENT_SUMMON_NPC_MINION_OF_SIAMAT, urand(0, 4 * IN_MILLISECONDS));

                if (pInstance && pInstance->GetData(DATA_SIAMAT_EVENT) != DONE)
                    pInstance->SetData(DATA_SIAMAT_EVENT, NOT_STARTED);
            }

            void JustSummoned(Creature* pSummoned)
            {
                Summons.Summon(pSummoned);

                if (pSummoned->GetEntry() == NPC_MINION_OF_SIAMAT_STORM)
                {
                    pSummoned->GetAI()->DoCast(me, SPELL_TEMPEST_STORM_AURA);
                    pSummoned->GetAI()->DoCast(me, SPELL_TEMPEST_STORM_FORM);
                }
                
                pSummoned->GetAI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM));
            }

            void SummonedCreatureDies(Creature *pSummoned, Unit* /*killer*/)
            {
                if (pSummoned->GetEntry() == NPC_SERVANT_OF_SIAMAT_FINAL)
                {
                    events.ScheduleEvent(EVENT_REMOVE_DEFLECTIVE_WINGS, 0);
                    events.ScheduleEvent(EVENT_WAILING_WINDS, 0);
                }
                else if (pSummoned->GetEntry() == NPC_SERVANT_OF_SIAMAT_NORMAL || pSummoned->GetEntry() == NPC_SERVANT_OF_SIAMAT_HEROIC)
                {
                    events.ScheduleEvent(EVENT_SUMMON_NPC_SERVANT_OF_SIAMAT, 0);
                }
                else if (pSummoned->GetEntry() == NPC_MINION_OF_SIAMAT)
                {
                    events.ScheduleEvent(EVENT_TEMPEST_STORM_SUMMON, 0);
                }   
            }

            void JustDied(Unit* /*Kill*/)
            {
                Talk(SAY_DEATH);
                Summons.DespawnAll();

                if(pInstance)
                    pInstance->SetData(DATA_SIAMAT_EVENT, DONE);
            }

            void EnterCombat(Unit* /*Ent*/)
            {
                Talk(SAY_INTRO);
                Talk(SAY_AGGRO);
			
                if(pInstance)
                    pInstance->SetData(DATA_SIAMAT_EVENT, IN_PROGRESS);

                DoZoneInCombat();
            }
			
            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_KILL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if(timer[0] >= TIME_BETWEEN_SERVANT_RESPAWN)
                {
                    timer[0] = 0;
                    events.ScheduleEvent(EVENT_SUMMON_NPC_SERVANT_OF_SIAMAT, 0);
                } else timer[0] += uiDiff;

                if (timer[1] >= TIME_BETWEEN_MINION_RESPAWN)
                {
                    timer[1] = 0;
                    events.ScheduleEvent(EVENT_SUMMON_NPC_MINION_OF_SIAMAT, 0);
                } else timer[1] += uiDiff;

                events.Update(uiDiff);
                
                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_DEFLECTING_WINDS:
                            DoCast(me, SPELL_DEFLECTING_WINDS);
                            break;
                        case EVENT_REMOVE_DEFLECTIVE_WINGS:
                            me->RemoveAurasDueToSpell(SPELL_DEFLECTING_WINDS);
                            break;
                        case EVENT_SUMMON_NPC_SERVANT_OF_SIAMAT:
                            Talk(SAY_EVENT_3);
                            if (DATA_REMOVE_DEFLECTIVE_WINGS < 3)
                            {
                                me->SummonCreature(DUNGEON_MODE(NPC_SERVANT_OF_SIAMAT_NORMAL, NPC_SERVANT_OF_SIAMAT_HEROIC), SummonPositions[urand(0,2)]);
                                DATA_REMOVE_DEFLECTIVE_WINGS++;
                            }
                            else if (DATA_REMOVE_DEFLECTIVE_WINGS == 3)
                            {
                                me->SummonCreature(NPC_SERVANT_OF_SIAMAT_FINAL, SummonPositions[urand(0,2)]);
                                DATA_REMOVE_DEFLECTIVE_WINGS = -1; // Stop Summons
                            }
                            break;
                        case EVENT_SUMMON_NPC_MINION_OF_SIAMAT:
                            Talk(SAY_EVENT_2);
                            me->SummonCreature(NPC_MINION_OF_SIAMAT, SummonPositions[urand(3,5)]);
                            break;
                        case EVENT_STORM_BOLT_RANDOM:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM,0), DUNGEON_MODE(SPELL_STORM_BOLT_RANDOM, H_SPELL_STORM_BOLT_RANDOM), true);
                            events.ScheduleEvent(EVENT_STORM_BOLT_RANDOM, urand(20000, 25000));
                            break;
                        case EVENT_CLOUD_BURST:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_CLOUD_BURST_SUMMON, true);
                            events.ScheduleEvent(EVENT_CLOUD_BURST, urand(15000, 20000));
                            break;
                        case EVENT_WAILING_WINDS:
                            DoCast(SPELL_WAILING_WINDS);
                            events.ScheduleEvent(EVENT_ABSORB_STORMS, urand(0, 10 * IN_MILLISECONDS));
                            break;
                        case EVENT_TEMPEST_STORM_SUMMON:
                            Talk(SAY_EVENT_1);
                            DoCast(SPELL_TEMPEST_STORM_SUMMON);
                            break;
                        case EVENT_ABSORB_STORMS:
                            DoCast(me, SPELL_ABSORB_STORMS, true);
                            events.ScheduleEvent(EVENT_ABSORB_STORMS, 25 * IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_DESPAWN_STORMS, 0);
                            break;
                        case EVENT_DESPAWN_STORMS:
                            Summons.DespawnAll();
                            break;
                        default:
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_STORM_BOLT_CASTING);
                DoMeleeAttackIfReady();
            }
        };
};

/***************
** Minion Siamat
****************/
class npc_minion_of_siamat : public CreatureScript
{
    public:
        npc_minion_of_siamat() : CreatureScript("npc_minion_of_siamat") {}

        CreatureAI* GetAI(Creature* pCreature) const
        {
           return new npc_minion_of_siamatAI(pCreature);
        }

        struct npc_minion_of_siamatAI : public ScriptedAI
        {
            npc_minion_of_siamatAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            bool DATA_TEMPEST_STORM;

            void Reset ()
            {
                DATA_TEMPEST_STORM = false;
                events.Reset();
                events.ScheduleEvent(EVENT_DEPLETION, 0);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if(me->HealthBelowPct(10) && !DATA_TEMPEST_STORM)
                {
                    DATA_TEMPEST_STORM = true;
                    events.ScheduleEvent(EVENT_TEMPEST_STORM, 0);
                }

                events.Update(uiDiff);

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_TEMPEST_STORM:
                            DoCast(DUNGEON_MODE(SPELL_TEMPEST_STORM, H_SPELL_TEMPEST_STORM));
                            break;
                        case EVENT_DEPLETION:
                            DoCast(me, SPELL_DEPLETION);
                            break;
                        default:
                            break;
                    }
                 }

                DoSpellAttackIfReady(DUNGEON_MODE(SPELL_CHAIN_LIGHTNING, H_SPELL_CHAIN_LIGHTNING));
                DoMeleeAttackIfReady();
            }
        };
};

/****************
** Servant Siamat
*****************/
class npc_servant_of_siamat : public CreatureScript
{
    public:
        npc_servant_of_siamat() : CreatureScript("npc_servant_of_siamat") {}

        CreatureAI* GetAI(Creature* pCreature) const
        {
           return new npc_servant_of_siamatAI(pCreature);
        }

        struct npc_servant_of_siamatAI : public ScriptedAI
        {
            npc_servant_of_siamatAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            bool DATA_THUNDER_CRASH;
            
            void Reset ()
            {
                DATA_THUNDER_CRASH = false;
                events.Reset();
                events.ScheduleEvent(EVENT_LIGHTNING_NOVA, urand(10000, 15000));
                events.ScheduleEvent(EVENT_LIGHTNING_CHARGE, urand(15000, 20000));
                
            }

            void DamageTaken(Unit* /*damageDealer*/, uint32& damage)
            {
                if (damage >= me->GetMaxHealth())
                    if (!DATA_THUNDER_CRASH)
                    {
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->RemoveAllAuras();
                    }
                    else
                        me->SetFlag(UNIT_FIELD_FLAGS, 0);

            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if(me->HealthBelowPct(15))                
                        DATA_THUNDER_CRASH = true;

                events.Update(uiDiff);

                 while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_LIGHTNING_CHARGE:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_LIGHTNING_CHARGE);
                            events.ScheduleEvent(EVENT_LIGHTNING_CHARGE, urand(15000, 20000));
                            break;
                        case EVENT_LIGHTNING_NOVA:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM), DUNGEON_MODE(SPELL_LIGHTNING_NOVA, H_SPELL_LIGHTNING_NOVA));
                            events.ScheduleEvent(EVENT_LIGHTNING_NOVA, urand(10000, 15000));
                            break;
                        case EVENT_THUNDER_CRASH:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM), DUNGEON_MODE(SPELL_THUNDER_CRASH, H_SPELL_THUNDER_CRASH));                            
                            break;  
                        default:
                            break;
                    }
                 }

                DoMeleeAttackIfReady();
            }
        };
};

/*************
** Cloud Burst
**************/
class npc_cloud_burst : public CreatureScript
{
    public:
        npc_cloud_burst() : CreatureScript("npc_cloud_burst") {}

        CreatureAI* GetAI(Creature* pCreature) const
        {
           return new npc_cloud_burstAI(pCreature);
        }

        struct npc_cloud_burstAI : public Scripted_NoMovementAI
        {
            npc_cloud_burstAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset ()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_CLOUD_BURST_VISUAL, 0);
                events.ScheduleEvent(EVENT_CLOUD_BURST, 3 * IN_MILLISECONDS);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
                
                events.Update(uiDiff);

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                    case EVENT_CLOUD_BURST_VISUAL:
                        DoCast(me, SPELL_CLOUD_BURST_VISUAL);
                        break;
                    case EVENT_CLOUD_BURST:
                        DoCast(DUNGEON_MODE(SPELL_CLOUD_BURST, H_SPELL_CLOUD_BURST));
                        events.ScheduleEvent(EVENT_DESPAWN_CLOUD_BURST, 2 * IN_MILLISECONDS);
                        break;
                    case EVENT_DESPAWN_CLOUD_BURST:
                        me->DespawnOrUnsummon();
                        break;
                        default:
                            break;
                    }
                 }

            }
        };
};

/*************
** Wind Tunnel
**************/
class npc_wind_tunnel : public CreatureScript
{
public:
    npc_wind_tunnel() : CreatureScript("npc_wind_tunnel") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_shokwave_spike_visualAI (pCreature);
    }

    struct mob_shokwave_spike_visualAI : public Scripted_NoMovementAI
    {
        mob_shokwave_spike_visualAI(Creature *c) : Scripted_NoMovementAI(c)
        {
        }

        void Reset()
        {
            me->AddAura(SPELL_VISUAL_WIND, me);
        }
    };
};

void AddSC_boss_siamat()
{
    new boss_siamat();
    new npc_minion_of_siamat();
    new npc_servant_of_siamat();
    new npc_cloud_burst();
    new npc_wind_tunnel();
}