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

#define spell_brulure_de_mana 33385 // Brûlure_de_Mana
#define spell_charme_de_masse 33384 // Charme_de_Masse
#define spell_enchainement 15284 // Enchaînement
#define spell_horions_des_arcanes 59715 // Horion_des_Arcanes
#define spell_fleches_multiples 21390 // Flèches_Multiples
#define spell_tir 15620 // Tir
#define spell_armure_brulante 79849 // Armure_Brûlante
#define spell_armure_de_la_fournaise 79848 // Armure_de_la_Fournaise
#define spell_boule_de_feu 81029 // Boule_de_Feu
#define spell_choc_de_flammes 81030 // Choc_de_Flammes

#define SAY_AGGRO "Glory for the Horde!"
#define SAY_DIED "Oh No ...."

/**************************
** lor_themar_theron
**************************/
class boss_lor_themar_theron: public CreatureScript
{
public: 
 boss_lor_themar_theron() : CreatureScript("boss_lor_themar_theron") { } 

 struct boss_lor_themar_theronAI : public ScriptedAI
    {
        boss_lor_themar_theronAI(Creature *c) : ScriptedAI(c) {}

        uint32 brulure_de_mana;
		uint32 charme_de_masse;
		uint32 enchainement;
		uint32 horions_des_arcanes;

        void Reset()
        {
            brulure_de_mana = 45000; 
			charme_de_masse = 90000;
			enchainement = 25000;
			horions_des_arcanes = 35000;
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

            if (brulure_de_mana<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_brulure_de_mana);								
                brulure_de_mana = 45000; 
            }
            else
                brulure_de_mana -= diff;

		    if (charme_de_masse<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_charme_de_masse);
				
                charme_de_masse = 90000; 
            }
            else
                charme_de_masse -= diff;

			if (enchainement<= diff)
			{
                DoCastVictim(spell_enchainement);
				
				enchainement  = 25000;							
            }
		    else
			    enchainement -= diff;
			
			if (horions_des_arcanes<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_horions_des_arcanes);
				
                horions_des_arcanes = 35000; 
            }
            else
                horions_des_arcanes -= diff;

				
							if (!UpdateVictim())
                    return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_lor_themar_theronAI(pCreature);
    }

};

/******************
**halduron_luisaile
******************/
class boss_halduron_luisaile: public CreatureScript
{
public: 
 boss_halduron_luisaile() : CreatureScript("boss_halduron_luisaile") { } 

 struct boss_halduron_luisaileAI : public ScriptedAI
    {
        boss_halduron_luisaileAI(Creature *c) : ScriptedAI(c) {}

        uint32 fleches_multiples;
		uint32 tir;

        void Reset()
        {
            fleches_multiples = 35000; 
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
					
			 if (fleches_multiples<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_fleches_multiples);
												
                fleches_multiples = 35000; 
            }
            else
                fleches_multiples -= diff;

		    if (tir<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_tir);
				
                tir = 25000; 
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
        return new boss_halduron_luisaileAI(pCreature);
    }

};

/*************************
**grand_magistère_rommath
*************************/
class boss_grand_magistere_rommath: public CreatureScript
{
public: 
 boss_grand_magistere_rommath() : CreatureScript("boss_grand_magistere_rommath") { } 

 struct boss_grand_magistere_rommathAI : public ScriptedAI
    {
        boss_grand_magistere_rommathAI(Creature *c) : ScriptedAI(c) {}

        uint32 armure_brulante;
		uint32 armure_de_la_fournaise;
		uint32 boule_de_feu;
		uint32 choc_de_flammes;

        void Reset()
        {
            armure_brulante = 100000; 
			armure_de_la_fournaise = 30000;
			boule_de_feu = 15000;
			choc_de_flammes = 60000;
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

            if (armure_brulante<= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_armure_brulante);
												
                armure_brulante = 100000; 
            }
            else
                armure_brulante -= diff;

		    if (armure_de_la_fournaise<= diff)
            {
                  DoCast(me, spell_armure_de_la_fournaise);                         
				
                armure_de_la_fournaise = 30000; 
            }
            else
                armure_de_la_fournaise -= diff;

			if (boule_de_feu<= diff)
			{
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_boule_de_feu);
				
				boule_de_feu  = 15000;							
            }
		    else
			    boule_de_feu -= diff;
				
			if (choc_de_flammes<= diff)
			{
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                                DoCast(pTarget, spell_choc_de_flammes);
				
				choc_de_flammes  = 60000;							
            }
		    else
			    choc_de_flammes -= diff;	
			
				
							if (!UpdateVictim())
                    return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_grand_magistere_rommathAI(pCreature);
    }

};

void AddSC_boss_grand_magistere_rommath()
{
    new boss_grand_magistere_rommath();
	new boss_halduron_luisaile();
	new boss_lor_themar_theron();
};