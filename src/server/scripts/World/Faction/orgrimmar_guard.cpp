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

/*****************************
**Coursier du vent d'Orgrimmar
******************************/
#define spell_tir 95826 // tir
class mob_coursier_du_vent_dorgrimmar: public CreatureScript
{
public:
 mob_coursier_du_vent_dorgrimmar() : CreatureScript("mob_coursier_du_vent_dorgrimmar") {}
 
struct mob_coursier_du_vent_dorgrimmarAI : public ScriptedAI
{
        mob_coursier_du_vent_dorgrimmarAI(Creature *c) : ScriptedAI(c) {}
		
		uint32 tir;
		
		void Reset()
		{
		        tir = 5000;
		}
		
		void UpdateAI(const uint32 diff)
		{
		        if (!UpdateVictim())
				return;
				
				if (tir<= diff)
				{
				        DoCast(me->getVictim(), spell_tir);
						tir = 5000;
				} else tir -= diff;
				DoMeleeAttackIfReady();
		}
};

	CreatureAI* GetAI(Creature* pCreature) const
	{
		return new mob_coursier_du_vent_dorgrimmarAI(pCreature);
	}
};

/******************
**Grunt d'Orgrimmar
*******************/
#define spell_tir 95826 // tir
#define spell_enchainement 40505 // Enchainement
class mob_grunt_dorgrimmar: public CreatureScript
{
public:
 mob_grunt_dorgrimmar() : CreatureScript("mob_grunt_dorgrimmar") {}
 
struct mob_grunt_dorgrimmarAI : public ScriptedAI
{
        mob_grunt_dorgrimmarAI(Creature *c) : ScriptedAI(c) {}
		
		uint32 enchainement;
		uint32 tir;
		
		void Reset()
		{
		        tir = 5000;
				enchainement = 5000;
		}
		
		void UpdateAI(const uint32 diff)
		{
		        if (!UpdateVictim())
				return;
				
				if (tir<= diff)
				{
				        DoCast(me->getVictim(), spell_tir);
						tir = 5000;
				} else tir -= diff;
				
				if (enchainement<= diff)
				{
				        DoCast(me->getVictim(), spell_enchainement);
						enchainement = 5000;
				} else enchainement -= diff;
				DoMeleeAttackIfReady();
		}
};

	CreatureAI* GetAI(Creature* pCreature) const
	{
		return new mob_grunt_dorgrimmarAI(pCreature);
	}
};

/********************
**Eclaireur Fortemain
*********************/
#define spell_cracher 58519 // Cracher
#define spell_odeur_de_banane_pourrie 58514 // Odeur De Banane pourrie
#define spell_odeur_de_pomme_pourrie 58511 // Odeur de pomme pourrie
#define spell_tir 95826 // tir
class mob_eclaireur_fortemain: public CreatureScript
{
public:
 mob_eclaireur_fortemain() : CreatureScript("mob_eclaireur_fortemain") {}
 
struct mob_eclaireur_fortemainAI : public ScriptedAI
{
        mob_eclaireur_fortemainAI(Creature *c) : ScriptedAI(c) {}
		
		uint32 cracher;
		uint32 odeur_de_banane_pourrie;
		uint32 odeur_de_pomme_pourrie;
		uint32 tir;
		
		void Reset ()
		{
		        cracher = 45000;
				odeur_de_banane_pourrie = 45000;
				odeur_de_pomme_pourrie = 45000;
				tir = 5000;
		}
		
		void UpdateAI(const uint32 diff)
		{
		        if (!UpdateVictim())
				return;
				
				if (cracher<= diff)
				{
				        DoCast(me->getVictim(), spell_cracher);
						cracher = 45000;
				} else cracher -= diff;
				
				if (odeur_de_banane_pourrie<= diff)
				{
				        DoCast(me->getVictim(), spell_odeur_de_banane_pourrie);
						odeur_de_banane_pourrie = 45000;
				} else odeur_de_banane_pourrie -= diff;
				
				if (odeur_de_pomme_pourrie<= diff)
				{
				        DoCast(me->getVictim(), spell_odeur_de_pomme_pourrie);
						odeur_de_pomme_pourrie = 45000;
				}
				
				if (tir<= diff)
				{
				        DoCast(me->getVictim(), spell_tir);
						tir = 5000;
				} else tir -= diff;
				DoMeleeAttackIfReady();
		}
};

	CreatureAI* GetAI(Creature* pCreature) const
	{
		return new mob_eclaireur_fortemainAI(pCreature);
	}
};

void AddSC_mob_orgrimmar()
{
    new mob_coursier_du_vent_dorgrimmar();
    new mob_grunt_dorgrimmar();
    new mob_eclaireur_fortemain();
}