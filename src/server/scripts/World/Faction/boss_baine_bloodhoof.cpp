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

#define spell_choc_martial 59705 // Choc_Martial
#define spell_enchainement 15284 // Enchaînement
#define spell_frappe_mortelle 32736 // Frappe_Mortelle
#define spell_uppercut 22916 // Uppercut

#define SAY_AGGRO "For the Horde!"
#define SAY_DIED "Aaaaahhhh"

class boss_baine_sabot_de_sang: public CreatureScript
{
public: 
 boss_baine_sabot_de_sang() : CreatureScript("boss_baine_sabot_de_sang") { } 

 struct boss_baine_sabot_de_sangAI : public ScriptedAI
    {
        boss_baine_sabot_de_sangAI(Creature *c) : ScriptedAI(c) {}

        uint32 choc_martial;
		uint32 enchainement;
		uint32 frappe_mortelle;
		uint32 uppercut;

        void Reset()
        {
            choc_martial= 30000; 
			enchainement = 20000;
			frappe_mortelle = 25000;
			uppercut = 50000;
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

            if (choc_martial<= diff)
            {
                DoCast(spell_choc_martial);
				
                choc_martial = 30000; 
            }
            else
                choc_martial-= diff;

		    if (enchainement<= diff)
            {
                DoCast(spell_enchainement);
				
                enchainement = 20000; 
            }
            else
                enchainement-= diff;

			if (frappe_mortelle<= diff)
			{
                DoCast(spell_frappe_mortelle);
				
				frappe_mortelle  = 25000;							
            }
		    else
			    frappe_mortelle-= diff;
				
			if (uppercut<= diff)
			{
			    DoCast(spell_uppercut);
				
				 uppercut = 50000;
			}
			else
			    uppercut -= diff;
				
							if (!UpdateVictim())
                    return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_baine_sabot_de_sangAI(pCreature);
    }

};

void AddSC_boss_baine_sabot_de_sang()
{
    new boss_baine_sabot_de_sang();
}