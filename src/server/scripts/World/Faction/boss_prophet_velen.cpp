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

#define spell_chatiment_sacre 59703 // Châtiment_Sacré
#define spell_coup_de_baton 84647 // Coup_de_Bâton
#define spell_deflagration_sacree 59700 // Déflagration_Sacrée
#define spell_nova_sacree 59701 // Nova_Sacrée
#define spell_priere_de_soin 59698 // Prière_de_Soins

#define SAY_AGGRO "Glory to the Alliance!"
#define SAY_DIED "Oh No ...."

class boss_prophete_velen: public CreatureScript
{
public: 
 boss_prophete_velen() : CreatureScript("boss_prophete_velen") { } 

 struct boss_prophete_velenAI : public ScriptedAI
    {
        boss_prophete_velenAI(Creature *c) : ScriptedAI(c) {}

        uint32 chatiment_sacre;
		uint32 coup_de_baton;
		uint32 deflagration_sacree;
		uint32 nova_sacree;
		uint32 priere_de_soin;

        void Reset()
        {
            chatiment_sacre = 45000; 
			coup_de_baton = 35000;
			deflagration_sacree = 90000;
			nova_sacree = 40000;
			priere_de_soin = 60000;
        }

        void EnterCombat(Unit* /*who*/) 
        {
			me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
        }

        void JustDied(Unit* /*killer*/)
        {
			me->MonsterYell(SAY_DIED, LANG_UNIVERSAL, NULL);
        }

        void UpdateAI(const uint32 diff)
        {
                if (!UpdateVictim())
                    return;

            if (chatiment_sacre<= diff)
            {
                DoCast(spell_chatiment_sacre);
				
                chatiment_sacre  = 45000; 
            }
            else
                chatiment_sacre -= diff;

		    if (coup_de_baton<= diff)
            {
                DoCast(spell_coup_de_baton);
				
                coup_de_baton  = 35000; 
            }
            else
                coup_de_baton -= diff;

			if (deflagration_sacree<= diff)
			{
			    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_deflagration_sacree);
				deflagration_sacree  = 90000;							
            }
		    else
			    deflagration_sacree -= diff;
				
			if (nova_sacree<= diff)
			{
			    DoCastAOE(spell_nova_sacree);
				
				nova_sacree  = 40000;
			}
			else
			    nova_sacree -= diff;
				
			if (priere_de_soin<= diff)
			{
			    DoCast(me, spell_priere_de_soin);
				
				priere_de_soin  = 60000;
			}
			else
			    priere_de_soin -= diff;
				
							if (!UpdateVictim())
                    return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_prophete_velenAI(pCreature);
    }

};

void AddSC_boss_prophete_velen()
{
    new boss_prophete_velen();
}