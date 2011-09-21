/* 
 * Copyright (C) 2010-2011 Project SkyFire <http://www.projectskyfire.org/>
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

#include"ScriptPCH.h"
#include"WorldPacket.h"
#include"blackwing_descent.h"
#include"ScriptMgr.h"
#include"ScriptedCreature.h"
#include"SpellScript.h"
#include"SpellAuraEffects.h"

enum Spells
{
    SPELL_BERSERK = 26662,
	SPELL_LAVA_SPEW_H10 = 91931,
	SPELL_LAVA_SPEW_N25 = 91919,
	SPELL_LAVA_SPEW_H25 = 91932,
	SPELL_LAVA_SPEW_N10 = 77690,
    SPELL_MAGMA_SPIT_H10 = 91927,
	SPELL_MAGMA_SPIT_H25 = 91928,
	SPELL_MAGMA_SPIT_N25 = 91917,
	SPELL_MAGMA_SPIT_N10 = 78068,
    SPELL_MANGLE_N10 = 89773,
	SPELL_MANGLE_H25 = 94617,
	SPELL_MANGLE_H10 = 94616,
	SPELL_MANGLE_N25 = 91912,
    SPELL_MOLTEN_TANTRUM = 78403,
    SPELL_PILLAR_OF_FLAME = 78006,
    };

class boss_magmaw : public CreatureScript
{
public:
    boss_magmaw() : CreatureScript("boss_magmaw") {}
	
    CreatureAI* GetAI(Creature* pCreature) const
    {
       return new boss_magmawAI(pCreature);
    }
    struct boss_magmawAI : public ScriptedAI
	{
		boss_magmawAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript *pInstance;
        EventMap events;
        SummonList Summons;
        bool check_in;

        uint32 m_uiSayTimer;                                    // Timer for random chat
        uint32 m_uiRebuffTimer;                                 // Timer for rebuffing
        uint32 m_uiSpellTimerCTW;                               // Timer for start spell Call The Wind when in combat
        uint32 m_uiSpellTimerCTW_stop;                          // Timer for stop spell Call The Wind when in combat

        uint32 m_uiSpellTimerLB;                                 // Timer for spell 1 when in combat
        uint32 m_uiSpellTimerCB;                                 // Timer until we go into Beserk (enraged) mode

		uint32 m_uiSpellTimerSummTwister;

        uint32 m_uiPhase;                                       // The current battle phase we are in
        uint32 m_uiPhaseTimer;                                  // Timer until phase transition
		bool isCTW;
		float windOrientation;
		float windDiffOrientation;

        void Reset()
        {
            events.Reset();
			
			m_uiPhase = 1;                                      // Start in phase 1
            m_uiPhaseTimer = 60000;                             // 60 seconds

            m_uiSpellTimerCTW = urand(10000,15000);            // between 10 and 15 seconds
			m_uiSpellTimerCTW_stop = urand(2000,5000);         // between 2 and 5 seconds
			
            m_uiSpellTimerLB = urand(10000,20000);               // between 10 and 20 seconds
            m_uiSpellTimerCB = urand(10000,20000);               // between 10 and 20 seconds

            m_uiSpellTimerSummTwister = 10000;                           //  2 minutes
                            
            if (pInstance && (pInstance->GetData(DATA_MAGMAW_EVENT) != DONE && !check_in))
                pInstance->SetData(DATA_MAGMAW_EVENT, NOT_STARTED);
            
            check_in = false;
			isCTW = false;
		}
		
        void JustDied(Unit* /*Kill*/)
        {

            if (pInstance)
                pInstance->SetData(DATA_MAGMAW_EVENT, DONE);
        }
        void KilledUnit(Unit* /*Killed*/)
        {
//            DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
        }

        void EnterCombat(Unit* /*Ent*/)
        {

            DoZoneInCombat();

			if (pInstance)
                pInstance->SetData(DATA_MAGMAW_EVENT, IN_PROGRESS);
			
		}

        void UpdateAI(const uint32 uiDiff)
        {

            if (!UpdateVictim())  /* No target to kill */
                return;
							
			events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

                //Spell CTW timer
                if ( m_uiSpellTimerCTW <= uiDiff )
                {
					if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
						DoCast(pTarget, SPELL_LAVA_SPEW_N10);
					
					DoCast(me, SPELL_LAVA_SPEW_N10);
					windOrientation = me->GetOrientation();
					
					m_uiSpellTimerCTW = 19000;
					isCTW = true;
                }
                else  
				{
                    m_uiSpellTimerCTW -= uiDiff;
					me->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
					me->setActive(true);
					//me->GetMotionMaster()->MoveIdle();
				}

				//Spell STOP CTW timer
                // if (m_uiSpellTimerCTW <= uiDiff && isCTW)
                // {
                        // DoCast(me, SPELL_STOP_CALL_THE_WIND);
						// m_uiSpellTimerCTW_stop = urand(2000,5000);
						// isCTW = false;
                // }
                // else if ( isCTW ) 
                    // m_uiSpellTimerCTW -= uiDiff;

                //Spell CB timer
                if (m_uiSpellTimerCB <= uiDiff)
                {
                    //Cast spell two on our current target.
                    DoCast(me->getVictim(), SPELL_MAGMA_SPIT_N10);
                    m_uiSpellTimerCB = urand(10000,20000);
                }
                else
                    m_uiSpellTimerCB -= uiDiff;

				//Spell LB timer
				if (m_uiSpellTimerLB <= uiDiff)
				{
					//Cast spell one on our current target.
					DoCast(me->getVictim(), SPELL_MOLTEN_TANTRUM);

					m_uiSpellTimerLB = urand(10000,20000);
				}
				else
					m_uiSpellTimerLB -= uiDiff;

				//Spell m_uiSpellTimerSummTwister timer
				if (m_uiSpellTimerSummTwister <= uiDiff)
				{
					//Cast spell one on our current target.
					me->SummonCreature(41806, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    DoCast(me->getVictim(), SPELL_PILLAR_OF_FLAME);

					m_uiSpellTimerSummTwister = 10000;
				}
				else
					m_uiSpellTimerSummTwister -= uiDiff;

				Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();
				for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
					if (Player *pPlayer = i->getSource())
					{
						//DoCast(pPlayer,  78068);
						if ( windDiffOrientation < 1.5f )
							DoCast(pPlayer,  SPELL_MAGMA_SPIT_N10);
						else 
							DoCast(pPlayer,  SPELL_MAGMA_SPIT_N10);
					}

            					
        DoMeleeAttackIfReady();
    }
};
            
};

void AddSC_boss_magmaw()
{
    new boss_magmaw();
}