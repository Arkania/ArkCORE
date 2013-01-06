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

#define spell_avatar 19135 // Avatar
#define spell_eclair_de_tempete 84831 // Eclair_de_Tempête
#define spell_repousser_au_loin 20686 // Repousser_au_Loin
#define spell_attaque_mentale 84825 // Attaque_Mentale
#define spell_renovation 84824 // Rénovation
#define spell_soins 84822 // Soins
#define spell_chaine_d_eclairs 84829 // Chaîne_d_éclairs
#define spell_enchainement 15284 // Enchaînement
#define spell_marteau_tempete 84828 // Marteau_Tempête
#define spell_tir 84833 // Tir

#define SAY_AGGRO "Glory to the Alliance!"
#define SAY_DIED "Oh No ...."

/**************************
** muradin_barbe_de_bronze
**************************/
class boss_muradin_barbe_de_bronze: public CreatureScript
{
public: 
 boss_muradin_barbe_de_bronze() : CreatureScript("boss_muradin_barbe_de_bronze") { } 

 struct boss_muradin_barbe_de_bronzeAI : public ScriptedAI
    {
        boss_muradin_barbe_de_bronzeAI(Creature *c) : ScriptedAI(c) {}

        uint32 avatar;
		uint32 eclair_de_tempete;
		uint32 repousser_au_loin;

        void Reset()
        {
            avatar = 60000; 
			eclair_de_tempete = 30000;
			repousser_au_loin = 45000;
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

            if (avatar<= diff)
            {
                DoCast(me, spell_avatar);
												
                avatar = 60000; 
            }
            else
                avatar -= diff;

		    if (eclair_de_tempete<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_eclair_de_tempete);
				
                eclair_de_tempete = 30000; 
            }
            else
                eclair_de_tempete -= diff;

			if (repousser_au_loin<= diff)
			{
                DoCast(spell_repousser_au_loin);
				
				repousser_au_loin  = 45000;
            }
		    else
			    repousser_au_loin -= diff;
			
				
							if (!UpdateVictim())
                    return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_muradin_barbe_de_bronzeAI(pCreature);
    }

};

/******************
**moira_thaurissan
******************/
class boss_moira_thaurissan: public CreatureScript
{
public: 
 boss_moira_thaurissan() : CreatureScript("boss_moira_thaurissan") { } 

 struct boss_moira_thaurissanAI : public ScriptedAI
    {
        boss_moira_thaurissanAI(Creature *c) : ScriptedAI(c) {}

        uint32 attaque_mentale;
		uint32 renovation;
		uint32 soins;

        void Reset()
        {
            attaque_mentale = 10000; 
			renovation = 15000;
			soins = 20000;
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
					
			 if (attaque_mentale<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_attaque_mentale);
												
                attaque_mentale = 10000; 
            }
            else
                attaque_mentale -= diff;

		    if (renovation<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_renovation);
				
                renovation = 15000; 
            }
            else
                renovation -= diff;

			if (soins<= diff)
			{
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_soins);
				
				soins  = 20000;						
            }
		    else
			    soins -= diff;
			
				
							if (!UpdateVictim())
                    return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_moira_thaurissanAI(pCreature);
    }

};

/************************
**falstad_marteau_hardi
************************/
class boss_falstad_marteau_hardi: public CreatureScript
{
public: 
 boss_falstad_marteau_hardi() : CreatureScript("boss_falstad_marteau_hardi") { } 

 struct boss_falstad_marteau_hardiAI : public ScriptedAI
    {
        boss_falstad_marteau_hardiAI(Creature *c) : ScriptedAI(c) {}

        uint32 chaine_d_eclairs;
		uint32 enchainement;
		uint32 marteau_tempete;
		uint32 tir;

        void Reset()
        {
            chaine_d_eclairs = 50000; 
			enchainement = 30000;
			marteau_tempete = 45000;
			tir = 25000;
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

            if (chaine_d_eclairs<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_chaine_d_eclairs);
												
                chaine_d_eclairs = 50000; 
            }
            else
                chaine_d_eclairs -= diff;

		    if (enchainement<= diff)
            {
                  DoCastVictim(spell_enchainement);                         
				
                enchainement = 30000; 
            }
            else
                enchainement -= diff;

			if (marteau_tempete<= diff)
			{
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_marteau_tempete);
				
				marteau_tempete  = 45000;
            }
		    else
			    marteau_tempete -= diff;
				
			if (tir<= diff)
			{
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_tir);
				
				tir  = 25000;							
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
        return new boss_falstad_marteau_hardiAI(pCreature);
    }

};

void AddSC_boss_falstad_marteau_hardi()
{
    new boss_falstad_marteau_hardi();
	new boss_muradin_barbe_de_bronze();
	new boss_moira_thaurissan();
};