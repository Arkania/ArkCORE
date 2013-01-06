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

#define spell_fleche_noire 59712 // Flèche_Noire
#define spell_fleche_multiples 59713 // Flèche_Multiples
#define spell_invoquation_d_un_squelette 59711 // Invoquation_d_un_Squelette
#define spell_oubli 20672 // Oubli
#define spell_tir 59710 // Tir

class boss_dame_sylvanas_coursevent: public CreatureScript
{
public: 
 boss_dame_sylvanas_coursevent() : CreatureScript("boss_dame_sylvanas_coursevent") { } 

 struct boss_dame_sylvanas_courseventAI : public ScriptedAI
    {
        boss_dame_sylvanas_courseventAI(Creature *c) : ScriptedAI(c) {}

        uint32 fleche_noire;
		uint32 fleche_multiples;
		uint32 invoquation_d_un_squelette;
		uint32 oubli;
		uint32 tir;

        void Reset()
        {
            fleche_noire = 45000; 
			fleche_multiples = 30000;
			invoquation_d_un_squelette = 60000;
			oubli = 50000;
			tir = 7000;
        }

        void EnterCombat(Unit* /*who*/) 
        {
			/*me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);*/
        }

        void JustDied(Unit* /*killer*/)
        {
			/*me->MonsterYell(SAY_DIED, LANG_UNIVERSAL, NULL);*/
        }

        void UpdateAI(const uint32 diff)
        {
                if (!UpdateVictim())
                    return;

            if (fleche_noire<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_fleche_noire);
				
                fleche_noire  = 45000; 
            }
            else
                fleche_noire -= diff;

		    if (fleche_multiples<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_fleche_multiples);
				
                fleche_multiples = 30000; 
            }
            else
                fleche_multiples-= diff;

			if (invoquation_d_un_squelette<= diff)
			{
                DoCast(spell_invoquation_d_un_squelette);
				
				invoquation_d_un_squelette  = 60000;
            }
		    else
			    invoquation_d_un_squelette-= diff;
				
			if (oubli<= diff)
			{
			    DoCast(me, spell_oubli);
				
				 oubli = 50000;
			}
			else
			    oubli -= diff;
				
			if (tir<= diff)
			{
			    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_tir);
					
				tir = 7000;
				
			}
			else
			    tir -= diff;
				
							if (!UpdateVictim())
                    return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_dame_sylvanas_courseventAI(pCreature);
    }

};

void AddSC_boss_dame_sylvanas_coursevent()
{
    new boss_dame_sylvanas_coursevent();
}