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
#include "ScriptedCreature.h"

enum
{
    SPELL_FLORAISON        = 76043,
	SPELL_CONSO            = 75790,
	NPC_FLORE              = 40592,
};

#define MOB_TRASH RAND(40668,40669,40715)

enum Texts
{
    SAY_AGGRO = 0,
	SAY_EVENT = 1,
    SAY_SLAY = 2,
    SAY_DEATH = 3,
};

enum Events
{
    EVENT_FLORAISON,
    EVENT_CONSO,
    EVENT_FLORE,
    EVENT_SLAY,
    EVENT_SUMMON
};

// Spawn des adds
const Position addSpawnLocations[2][3] =
{{
    {-707.553467f, 207.223602f, 343.937927f, 0.00f},
	{-707.664124f, 179.188828f, 343.938049f, 0.00f},
	{-691.666321f, 193.310364f, 343.945282f, 0.00f},
},{
    {-707.553467f, 207.223602f, 343.937927f, 0.00f},
	{-707.664124f, 179.188828f, 343.938049f, 0.00f},
	{-691.666321f, 193.310364f, 343.945282f, 0.00f},
}};

/*********
** Ammunae
**********/
class boss_ammunae: public CreatureScript
{
public: 
 boss_ammunae() : CreatureScript("boss_ammunae") { } 

 struct boss_ammunaeAI : public ScriptedAI
    {
        boss_ammunaeAI(Creature *pCreature) : ScriptedAI(pCreature), Summons(me)
        {
		    pInstance = pCreature->GetInstanceScript();
		}

		InstanceScript* pInstance;
        EventMap events;
		SummonList Summons;
		
        void Reset() 
		{
		    Summons.DespawnAll();
		}

        void EnterCombat(Unit* /*who*/) 
        {
			Talk(SAY_AGGRO);
			EnterPhaseGround();
        }
		
		void EnterPhaseGround()
		{
		    events.ScheduleEvent(EVENT_FLORAISON, urand(6000,12000));
		    events.ScheduleEvent(EVENT_CONSO, urand(20000,32000));
		    events.ScheduleEvent(EVENT_SLAY, 10000);
		    events.ScheduleEvent(EVENT_SUMMON, 32000);
		}

        void JustDied(Unit* /*killer*/)
        {
			Talk(SAY_DEATH);
			Summons.DespawnAll();
        }
		
		void JustSummoned(Creature *pSummoned)
		{
			pSummoned->SetInCombatWithZone();
			if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
			pSummoned->AI()->AttackStart(pTarget);
			Summons.Summon(pSummoned);
		}
			
		void SummonedCreatureDespawn(Creature *summon)
		{
			Summons.Despawn(summon);
		}

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch(eventId)
				{
				    case EVENT_FLORAISON:
					    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_FLORAISON);
					    events.ScheduleEvent(EVENT_FLORAISON, urand(6000,12000));
					return;

					case EVENT_CONSO:
					    DoCast(SPELL_CONSO);
						events.ScheduleEvent(EVENT_CONSO, urand(20000,32000));
					return;
					
					case EVENT_SLAY:
					    Talk(SAY_SLAY);
					    events.ScheduleEvent(EVENT_SLAY, 10000);
					return;
					
					case EVENT_SUMMON:
					    Talk(SAY_EVENT);
						uint8 side = urand(0,1);
                        for(uint8 i=0; i<2 ; i++)
					    me->SummonCreature(MOB_TRASH, addSpawnLocations[side][i].GetPositionX(),addSpawnLocations[side][i].GetPositionY(),addSpawnLocations[side][i].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
					    events.ScheduleEvent(EVENT_SUMMON, 32000);
					return;
				}
			}
			DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ammunaeAI (pCreature);
    }

};

/**********
** Bourgeon
***********/
class mob_flore: public CreatureScript
{
    public:
        mob_flore() : CreatureScript("mob_flore") { }

        struct mob_floreAI : public ScriptedAI
        {
			mob_floreAI(Creature * pCreature) : ScriptedAI(pCreature) {}
			
			uint32 event;
						
			void reset()
			{
				event = 10000;
				me->DespawnOrUnsummon(10000);
			}

			void UpdateAI(const uint32 diff)
			{
                if (!UpdateVictim())
                    return;
					
				if (event<= diff)
				{
					me->SummonCreature(MOB_TRASH, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
					event   = 10000; 
				} else event -= diff;
					
			}
		};

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_floreAI(creature);
        }
};

void AddSC_boss_ammunae() 
{
    new boss_ammunae();
	new mob_flore();
}