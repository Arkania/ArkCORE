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

#define NPC_STALACTITE_TRIGGER 43159
#define NPC_LAVA_FISSURE 43242

enum Spells
{
	SPELL_CRYSTAL_STORM_H   = 92301,
	SPELL_SAND_BLAST        = 80807,
	SPELL_SAND_BLAST_H      = 92656,
	SPELL_LAVA_FISSURE      = 80803,
	SPELL_STALACTITE        = 80650,
};

Position const StalactitePositions[2][12] =
{
{ // Zone 1
{1298.623047f, 1224.074219f, 273.778992f, 0.00f},
{1291.949585f, 1215.446411f, 273.778992f, 0.00f},
{1294.813110f, 1209.369385f, 273.778992f, 0.00f},
{1287.097900f, 1204.876465f, 273.778992f, 0.00f},
{1276.908569f, 1203.576172f, 273.778992f, 0.00f},
{1267.234009f, 1204.380371f, 273.778992f, 0.00f},
{1262.221313f, 1213.552246f, 273.778992f, 0.00f},
{1264.838623f, 1222.959961f, 273.778992f, 0.00f},
{1272.419800f, 1223.891113f, 273.778992f, 0.00f},
{1286.559570f, 1225.560181f, 273.778992f, 0.00f},
{1278.142212f, 1227.792603f, 273.778992f, 0.00f},
{1276.007690f, 1216.315796f, 273.778992f, 0.00f},
},
{ // Zone 2
{1274.722046f, 1208.965332f, 273.778992f, 0.00f},
{1256.191528f, 1203.906982f, 273.778992f, 0.00f},
{1294.813110f, 1209.369385f, 273.778992f, 0.00f},
{1287.097900f, 1204.876465f, 273.778992f, 0.00f},
{1276.908569f, 1203.576172f, 273.778992f, 0.00f},
{1267.234009f, 1204.380371f, 273.778992f, 0.00f},
{1262.221313f, 1213.552246f, 273.778992f, 0.00f},
{1264.838623f, 1222.959961f, 273.778992f, 0.00f},
{1272.419800f, 1223.891113f, 273.778992f, 0.00f},
{1286.559570f, 1225.560181f, 273.778992f, 0.00f},
{1278.142212f, 1227.792603f, 273.778992f, 0.00f},
{1276.007690f, 1216.315796f, 273.778992f, 0.00f},
}
};

/**********
** Slabhide
***********/
class boss_slabhide : public CreatureScript
{
public:
    boss_slabhide() : CreatureScript("boss_slabhide") {}
	
	CreatureAI* GetAI(Creature* pCreature) const
	{
	    return new boss_slabhideAI (pCreature);
	}
	
	struct boss_slabhideAI : public ScriptedAI
	{
	    boss_slabhideAI(Creature *c) : ScriptedAI(c), Summons(me) {}
		
		InstanceScript* instance;
		SummonList Summons;
		
		uint32 LavaFissureTimer;
		uint32 SandBlastTimer;
		uint32 CrystalStormTimer;
		uint32 SummonsStalactiteTimer;
	    
	    void Reset()
	    {
            Summons.DespawnAll();
			
			LavaFissureTimer = 5000;
			SandBlastTimer = 8000;
			SummonsStalactiteTimer = 20000;
			CrystalStormTimer = 16000;
        }
		
		void EnterCombat() {}
		
		void JustDied()
		{
		    Summons.DespawnAll();
		}

        void UpdateAI(const uint32 diff)
		{
		    if (!UpdateVictim())
            return;
			
            if (LavaFissureTimer <= diff)
            {
			    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
			    DoCast(pTarget, SPELL_LAVA_FISSURE);
			    LavaFissureTimer = 5000;
			} else LavaFissureTimer -= diff;

            if (SandBlastTimer <= diff)
            {
			    DoCastVictim(DUNGEON_MODE(SPELL_SAND_BLAST,SPELL_SAND_BLAST_H));
				SandBlastTimer = 8000;
			} else SandBlastTimer -= diff;


			if (IsHeroic())
            {
                if (CrystalStormTimer <= diff)
				{
				    DoCastAOE(SPELL_CRYSTAL_STORM_H);
					CrystalStormTimer = 16000;
                } else CrystalStormTimer -= diff;
			}

			if (SummonsStalactiteTimer <= diff)
            {
			    CastStalactite();
				SummonsStalactiteTimer = 20000;
			} else SummonsStalactiteTimer -= diff;
				
            DoMeleeAttackIfReady();
        }
		
		void CastStalactite()
        {
			uint8 side = urand(0,1);
			for(uint8 i=0; i<12 ; i++)
			me->SummonCreature(NPC_STALACTITE_TRIGGER,StalactitePositions[side][i].GetPositionX(),StalactitePositions[side][i].GetPositionY(),StalactitePositions[side][i].GetPositionZ(),TEMPSUMMON_CORPSE_DESPAWN);
		}
    };
};

/********************
** Stalactite Trigger
*********************/
#define SPELL_STALACTITE_AURA 92653
#define SPELL_STALACTITE_VISUAL 80647
#define GO_STALACTITE_VISUEL 204337

class npc_stalactite_trigger : public CreatureScript
{
    public:
        npc_stalactite_trigger() : CreatureScript("npc_stalactite_trigger") { }

        struct npc_stalactite_triggerAI : public ScriptedAI
        {
			npc_stalactite_triggerAI(Creature * pCreature) : ScriptedAI(pCreature) {}

		    uint32 uiStalactiteDamage;
			
			void Reset()
			{
				uiStalactiteDamage = 1000;
				
				DoCast(me, SPELL_STALACTITE_AURA);
			}

			void UpdateAI(const uint32 diff)
			{
                if (!UpdateVictim())
                    return;
				
				if (uiStalactiteDamage <= diff)
                {
			        DoCast(SPELL_STALACTITE_VISUAL);
                    //Position pos;
                    //me->GetPosition(&pos);
                    //me->SummonGameObject(GO_STALACTITE_VISUEL, pos, 0, 0, 0, 0, TEMPSUMMON_CORPSE_DESPAWN);
				    uiStalactiteDamage = 1000;
			    } else uiStalactiteDamage -= diff;
				
				me->DespawnOrUnsummon(30000);
			}
		};

    CreatureAI* GetAI(Creature* creature) const
	{
        return new npc_stalactite_triggerAI(creature);
    }
};

/**********************
** Lava fissure Trigger
***********************/
#define SPELL_LAVA_AURA 76628
#define SPELL_LAVA_DAMAGE 78095

class npc_lava_trigger : public CreatureScript
{
    public:
        npc_lava_trigger() : CreatureScript("npc_lava_trigger") { }

        struct npc_lava_triggerAI : public ScriptedAI
        {
			npc_lava_triggerAI(Creature * pCreature) : ScriptedAI(pCreature) {}

			uint32 LavaDamageTimer;
			
			void Reset()
			{
				LavaDamageTimer = 1000;
				
				DoCast(me, SPELL_LAVA_AURA);
			}

			void UpdateAI(const uint32 diff)
			{
                if (!UpdateVictim())
                    return;
				
				if (LavaDamageTimer <= diff)
                {
			        DoCastAOE(SPELL_LAVA_DAMAGE);
				    LavaDamageTimer = 1000;
			    } else LavaDamageTimer -= diff;
				
				me->DespawnOrUnsummon(10000);
			}
		};

    CreatureAI* GetAI(Creature* creature) const
	{
        return new npc_lava_triggerAI(creature);
    }
};

void AddSC_boss_slabhide()
{
    new boss_slabhide();
	new npc_stalactite_trigger();
	new npc_lava_trigger();
}