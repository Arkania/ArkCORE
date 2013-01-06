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

#define spell_eclat_lunaire 20690 // Eclat_Lunaire
#define spell_enchainement 20691 // Enchainement
#define spell_fleche_de_feu 20688 // Flèche_de_Feu
#define spell_meteores 20687 // Météores

#define SAY_AGGRO "Glory to the Alliance!"
#define SAY_DIED "Oh No ...."

class boss_tyrande_murmevent: public CreatureScript
{
public: 
 boss_tyrande_murmevent() : CreatureScript("boss_tyrande_murmevent") { } 

 struct boss_tyrande_murmeventAI : public ScriptedAI
    {
        boss_tyrande_murmeventAI(Creature *c) : ScriptedAI(c) {}

        uint32 eclat_lunaire;
		uint32 enchainement;
		uint32 fleche_de_feu;
		uint32 meteores;

        void Reset()
        {
            eclat_lunaire = 45000; 
			enchainement = 25000;
			fleche_de_feu = 30000;
			meteores = 80000;
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

            if (eclat_lunaire<= diff)
            {
                DoCast(spell_eclat_lunaire);
				
                eclat_lunaire  = 45000; 
            }
            else
                eclat_lunaire -= diff;

		    if (enchainement<= diff)
            {
                DoCast(spell_enchainement);
				
                enchainement = 25000; 
            }
            else
                enchainement-= diff;

			if (fleche_de_feu<= diff)
			{
			    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_fleche_de_feu);
				fleche_de_feu  = 30000;							
            }
		    else
			    fleche_de_feu-= diff;
				
			if (meteores<= diff)
			{
			    DoCastAOE(spell_meteores);
				
				 meteores = 80000;
			}
			else
			    meteores -= diff;
				
							if (!UpdateVictim())
                    return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_tyrande_murmeventAI(pCreature);
    }

};

void AddSC_boss_tyrande_murmevent()
{
    new boss_tyrande_murmevent();
}