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

#include "the_vortex_pinnacle.h"
#include "ScriptPCH.h"

enum text
{
    SAY_AGGRO                        = 1,
    SAY_EVENT                        = 2,
    SAY_DIED                         = 3,
};

enum eSpells
{
    SPELL_LIGHTNING_BOLT = 86331,
    H_SPELL_LIGHTNING_BOLT = 93990,
    SPELL_CYCLONE_SHIELD = 86267,
    H_SPELL_SUMMON_TEMPEST = 86340,
    SPELL_STORMS_EDGE = 86309,
    H_SPELL_STORMS_EDGE = 93992,
};

enum events
{
    EVENT_SUMMON_CYCLONE_SHIELD = 1,
    EVENT_ROTATE_CYCLONE_SHIELD = 2,
    EVENT_STORMS_EDGE = 3,
    EVENT_SUMMON_TEMPEST = 4,
    EVENT_CALL_CYCLONE_SHIELD = 5,
    EVENT_UNCALL_CYCLONE_SHIELD = 6,
};

Position const SummonPositions[9] =
{
    {-702.169861f, -13.464818f, 635.700000f, 0.0f},
    {-720.039978f, -20.697706f, 635.700000f, 0.0f},
    {-737.383118f, -13.578897f, 635.700000f, 0.0f},
    {-744.619812f, 4.043463f, 635.700000f, 0.0f},
    {-737.378174f, 21.446815f, 635.700000f, 0.0f},
    {-719.915649f, 28.839144f, 635.700000f, 0.0f},
    {-702.138977f, 21.651012f, 635.700000f, 0.0f},
    {-694.838196f, 3.924702f, 635.700000f, 0.0f},
    {-719.558196f, 3.944702f, 635.700000f, 0.0f},
};

/*************************
** Boss Grand Vizir Ertan
*************************/
class boss_vizir_ertan : public CreatureScript
{
public:
    boss_vizir_ertan() : CreatureScript("boss_vizir_ertan") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_vizir_ertanAI (creature);
    }

    struct boss_vizir_ertanAI : public ScriptedAI
    {
        boss_vizir_ertanAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;
        SummonList Summons;
        uint32 DATA_CYCLONE_SHIELD_POSITION;
        uint32 TIMER_STORM_RAGE;

        void Reset()
        {
            Summons.DespawnAll();
            TIMER_STORM_RAGE = 1 * IN_MILLISECONDS;
        }

        void JustSummoned(Creature* pSummoned)
        {
            Summons.Summon(pSummoned);

            if (pSummoned->GetEntry() == NPC_CYCLONE_SHIELD)
            {
                pSummoned->AI()->DoCast(pSummoned, SPELL_CYCLONE_SHIELD);
            }
        }

        void SummonCyclones()
        {
            for (uint32 i = 0; i < 8; i++)
                me->SummonCreature(NPC_CYCLONE_SHIELD, SummonPositions[i]);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_SUMMON_CYCLONE_SHIELD, 0);
            TIMER_STORM_RAGE = 1 * IN_MILLISECONDS;

            if(pInstance)
                pInstance->SetData(DATA_GRAND_VIZIER_ERTAN_EVENT, IN_PROGRESS);

            DoZoneInCombat();
        }

        void JustDied(Unit* /*Killer*/)
        {
            Talk(SAY_DIED);
            Summons.DespawnAll();
            pInstance->SetData(DATA_GRAND_VIZIER_ERTAN, DONE);

            Creature * Slipstream = me->SummonCreature(NPC_SLIPSTREAM, -775.51f, -70.93f, 640.31f, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            Slipstream->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (TIMER_STORM_RAGE <= 0) 
            {
                TIMER_STORM_RAGE = 1 * IN_MILLISECONDS;
                Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                    if (i->getSource()->GetDistance2d(me->GetPositionX(), me->GetPositionY()) >= me->GetDistance2d(SummonPositions[0].GetPositionX(), SummonPositions[0].GetPositionY()))
                        DoCast(i->getSource(), DUNGEON_MODE(SPELL_STORMS_EDGE, H_SPELL_STORMS_EDGE), true);
            } else TIMER_STORM_RAGE -= diff;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_SUMMON_CYCLONE_SHIELD:
                    Talk(SAY_EVENT);
                    SummonCyclones();
                    break;
                
                    default:
                        break;
                }
            }

            DoSpellAttackIfReady(DUNGEON_MODE(SPELL_LIGHTNING_BOLT, H_SPELL_LIGHTNING_BOLT));
			DoMeleeAttackIfReady();
        }
    };
};

/****************
** Cyclone shield
*****************/
class npc_cyclone_shield : public CreatureScript
{
public:
    npc_cyclone_shield() : CreatureScript("npc_cyclone_shield") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_cyclone_shieldAI (creature);
    }

    struct npc_cyclone_shieldAI : public ScriptedAI
    {
        npc_cyclone_shieldAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;
        SummonList Summons;
        uint32 DATA_CYCLONE_SHIELD_POSITION;
        uint32 TIMER_CALL_STORM;
        bool STORM_BUSY;
        
        void DoMoveToPoint(Position pos)
        {
            me->GetMotionMaster()->Clear();
	        me->GetMotionMaster()->MovePoint(0, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        }

        void Reset()
        {
            STORM_BUSY = false;
            TIMER_CALL_STORM = 20 * IN_MILLISECONDS;
            float x, y, z;
            me->GetPosition(x, y, z);
            Position temp;
            temp.Relocate(x, y, z, 0);

            for (uint32 i = 0; i < 8; i++)
                if (temp.GetPositionX() == SummonPositions[i].GetPositionX() && temp.GetPositionY() == SummonPositions[i].GetPositionY() && temp.GetPositionZ() == SummonPositions[i].GetPositionZ())
                    DATA_CYCLONE_SHIELD_POSITION = i;
        }

        void EnterCombat(Unit* /*who*/)
        {
            TIMER_CALL_STORM = 20 * IN_MILLISECONDS;
        } 

        void UpdateAI(const uint32 diff)
        {           
            TIMER_CALL_STORM -= diff; 
            if (me->GetPositionX() == SummonPositions[(DATA_CYCLONE_SHIELD_POSITION) % 8].GetPositionX())
            {
                if (TIMER_CALL_STORM <= 0)
                {
                    me->StopMoving();
                    STORM_BUSY = true;
                    events.Reset();
                    events.ScheduleEvent(EVENT_CALL_CYCLONE_SHIELD, 0);
                    //TIMER_CALL_STORM = 20 * IN_MILLISECONDS;
                }
                else
                {
                    if (!STORM_BUSY)
                        events.ScheduleEvent(EVENT_ROTATE_CYCLONE_SHIELD, 0);
                }                  
            }
            
            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_ROTATE_CYCLONE_SHIELD:
                    DoMoveToPoint(SummonPositions[(++DATA_CYCLONE_SHIELD_POSITION) % 8]);
                    break;
                case EVENT_CALL_CYCLONE_SHIELD:
                    DoMoveToPoint(SummonPositions[8]);
                    events.ScheduleEvent(EVENT_UNCALL_CYCLONE_SHIELD, 15 * IN_MILLISECONDS);
                    break;
                case EVENT_UNCALL_CYCLONE_SHIELD:
                    DoMoveToPoint(SummonPositions[(DATA_CYCLONE_SHIELD_POSITION) % 8]);
                    STORM_BUSY = false;
                    TIMER_CALL_STORM = 20 * IN_MILLISECONDS;
                    break;
                default:
                    break;
                }
            }

        }
    };
};

void AddSC_boss_vizir_ertan()
{
    new boss_vizir_ertan();
    new npc_cyclone_shield();
}