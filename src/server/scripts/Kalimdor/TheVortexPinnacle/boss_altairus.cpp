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
#include "the_vortex_pinnacle.h"

enum Spells
{
    SPELL_CALL_THE_WIND = 88772,
    SPELL_STOP_CALL_THE_WIND = 88244,
    SPELL_UPWIND_OF_ALTAIRUS = 88282,
    SPELL_DOWNWIND_OF_ALTAIRUS = 88286,
    SPELL_CIILLING_BREATH_N = 88308,
    SPELL_CIILLING_BREATH_H = 93989,
    SPELL_LIGHTING_BLAST = 88357,
    SPELL_TWISTING_WINDS = 88314, // Twister Spell
    SPELL_TWISTING_WINDS_AURA = 88313 // Aura Twister
};

#define MOB_TWISTER 57521

Position const SummonPositions[18] =
{
    {-1190.87f, 67.249f, 734.174f, 0.0f},
    {-1202.65f, 77.3934f, 734.174f, 0.0f},
    {-1186.58f, 57.6621f, 734.174f, 0.0f},
    {-1190.17f, 47.1428f, 734.174f, 0.0f},
    {-1195.54f, 40.7106f, 734.174f, 0.0f},
    {-1218.18f, 45.7043f, 734.174f, 0.0f},
    {-1219.88f, 36.4537f, 734.174f, 0.0f},
    {-1228.9f, 48.8937f, 734.174f, 0.0f},
    {-1220.78f, 57.976f, 734.174f, 0.0f},
    {-1213.21f, 67.642f, 734.174f, 0.0f},
    {-1223.93f, 76.656f, 734.174f, 0.0f},
    {-1229.16f, 69.2413f, 734.174f, 0.0f},
    {-1232.79f, 60.4921f, 734.174f, 0.0f},
    {-1236.71f, 42.6489f, 734.174f, 0.0f},
    {-1230.61f, 33.2781f, 734.174f, 0.0f},
    {-1203.83f, 45.8517f, 734.174f, 0.0f},
    {-1208.48f, 58.4752f, 734.174f, 0.0f},
    {-1200.49f, 64.5953f, 734.174f, 0.0f},
};

Creature* pTwister;

/***********
** Altairus
************/
class boss_altairus : public CreatureScript
{
public:
    boss_altairus() : CreatureScript("boss_altairus") {}
	
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_altairusAI(pCreature);
    }
    
    struct boss_altairusAI : public ScriptedAI
    {
        boss_altairusAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }
			
	 InstanceScript *pInstance;
        bool isCTW;
        bool VortexTimer;
        bool check_in;
        float windOrientation;
	
        uint32 ChillingBreathTimer;
        uint32 LightningBlastTimer;
        uint32 m_uiSpellTimerCTW;
        uint32 m_uiSpellTimerCTW_stop;
			
        void Reset ()
        {
            ChillingBreathTimer = 15000;
            LightningBlastTimer = urand(10000,20000);
            m_uiSpellTimerCTW = urand(10000,15000);
            m_uiSpellTimerCTW_stop = urand(2000,5000);
			
            check_in = false;
            isCTW = false;
            VortexTimer = false;
			
            if (pInstance && (pInstance->GetData(DATA_ALTAIRUS_EVENT) != DONE && !check_in))
                pInstance->SetData(DATA_ALTAIRUS_EVENT, NOT_STARTED);
        }
			
        void JustDied(Unit* /*Kill*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_ALTAIRUS_EVENT, DONE);

            Creature* Slipstream = me->SummonCreature(NPC_SLIPSTREAM, -1190.88f, 125.20f, 737.62f, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            Slipstream->SetUInt32Value(UNIT_NPC_FLAGS,UNIT_NPC_FLAG_GOSSIP);
        }
		
        void EnterCombat(Unit* /*Ent*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_ALTAIRUS_EVENT, IN_PROGRESS);

            VortexTimer = 0;

            DoZoneInCombat();
        }
		
        void SummonVortex()
        {
            for (uint32 i = 0; i < 17; i++)
            me->SummonCreature(MOB_TWISTER, SummonPositions[i]);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if(!VortexTimer)
            {
                SummonVortex();
                VortexTimer = true;
            }

            if (ChillingBreathTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    me->CastSpell(target, DUNGEON_MODE(SPELL_CIILLING_BREATH_N, SPELL_CIILLING_BREATH_H), true);

                ChillingBreathTimer = urand(12000,17000);
            } else ChillingBreathTimer -= diff;
			
            if (LightningBlastTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_LIGHTING_BLAST);
                LightningBlastTimer = urand(10000,20000);
            } else LightningBlastTimer -= diff;
			
            if (m_uiSpellTimerCTW <= diff && isCTW)
            {
                if (me->HasAura(SPELL_CALL_THE_WIND))
                me-> RemoveAurasDueToSpell(SPELL_CALL_THE_WIND);
                DoCast(me, SPELL_STOP_CALL_THE_WIND);
                m_uiSpellTimerCTW_stop = urand(2000,5000);
                isCTW = false;
            } else if(isCTW) m_uiSpellTimerCTW -= diff;
			
            if (m_uiSpellTimerCTW_stop <= diff && !isCTW)
            {
                DoCast(me, SPELL_CALL_THE_WIND);
                windOrientation = me->GetOrientation();
                m_uiSpellTimerCTW = urand(10000,20000);
                isCTW = true;
            } else if(!isCTW) m_uiSpellTimerCTW_stop -= diff;
			
            Map* pMap = me->GetMap();
            Map::PlayerList const &PlayerList = pMap->GetPlayers();
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* i_pl = i->getSource())
            if (i_pl->isAlive())
            if ( i_pl->isInFrontInMap(NULL , 4 , windOrientation ) )
                DoCast(i_pl,  SPELL_UPWIND_OF_ALTAIRUS);
            else 
                DoCast(i_pl,  SPELL_DOWNWIND_OF_ALTAIRUS);

            DoMeleeAttackIfReady();
        }
    };

};

/*********
** Tornado
**********/
class npc_twister : public CreatureScript
{
public:
    npc_twister() : CreatureScript("npc_twister") { }

    struct npc_twisterAI : public ScriptedAI
    {
        npc_twisterAI(Creature * pCreature) : ScriptedAI(pCreature) 
        {
            me = pTwister;
        }

        bool uiTwistingWindFixe;
        uint32 uiWindsAura;
			
        void Reset()
        {
            uiTwistingWindFixe = false;
            uiWindsAura = 1000;
            me->AddAura(SPELL_TWISTING_WINDS_AURA, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
            return;

            if(uiWindsAura <= diff)
            {
                DoCast(me, SPELL_TWISTING_WINDS_AURA);
                uiWindsAura = 1000;
            } else uiWindsAura -= diff;
				
            if(!uiTwistingWindFixe)
            {
                DoCast(SPELL_TWISTING_WINDS);
                uiTwistingWindFixe = true;
            }
       }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_twisterAI(creature);
    }
};

void AddSC_boss_altairus()
{
    new boss_altairus();
    new npc_twister();
}