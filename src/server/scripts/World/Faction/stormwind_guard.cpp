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

/************************************
**Chevaucheur de griffon de Hurlevent
*************************************/
#define spell_resolution_de_grisetete 96161 // Résolution de Grisetete
#define spell_tir 6660 // Tir
class mob_chevaucheur_de_griffon_de_hurlevent: public CreatureScript
{
public:
 mob_chevaucheur_de_griffon_de_hurlevent() : CreatureScript("mob_chevaucheur_de_griffon_de_hurlevent") {}

struct mob_chevaucheur_de_griffon_de_hurleventAI : public ScriptedAI
{
        mob_chevaucheur_de_griffon_de_hurleventAI(Creature *c) : ScriptedAI(c) {}
		
		uint32 resolution_de_grisetete;
		uint32 tir;
		
		void Reset ()
		{
		        resolution_de_grisetete = 360000;
				tir = 5000;
		}
		
		void UpdateAI(const uint32 diff)
		{
		        if (!UpdateVictim())
				return;
				
				if (resolution_de_grisetete<= diff)
				{
				        DoCast(me, spell_resolution_de_grisetete);
						resolution_de_grisetete = 360000;
				} else resolution_de_grisetete -= diff;
				
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
		return new mob_chevaucheur_de_griffon_de_hurleventAI(pCreature);
	}
};

/*******************
**Garde de Hurlevent
********************/
#define spell_tir 95826 // tir
class mob_garde_de_hurlevent: public CreatureScript
{
public:
 mob_garde_de_hurlevent() : CreatureScript("mob_garde_de_hurlevent") {}
 
struct mob_garde_de_hurleventAI : public ScriptedAI
{
        mob_garde_de_hurleventAI(Creature *c) : ScriptedAI(c) {}
		
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
		return new mob_garde_de_hurleventAI(pCreature);
	}
};

/***************************
**Garde du port de Hurlevent
****************************/
#define spell_tir 95826 // tir
class mob_garde_du_port_de_hurlevent: public CreatureScript
{
public:
 mob_garde_du_port_de_hurlevent() : CreatureScript("mob_garde_du_port_de_hurlevent") {}
 
struct mob_garde_du_port_de_hurleventAI : public ScriptedAI
{
        mob_garde_du_port_de_hurleventAI(Creature *c) : ScriptedAI(c) {}
		
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
		return new mob_garde_du_port_de_hurleventAI(pCreature);
	}
};

/**************************
**Patrouilleur de Hurlevent
***************************/
#define spell_tir 95826 // tir
class mob_patrouilleur_de_hurlevent: public CreatureScript
{
public:
 mob_patrouilleur_de_hurlevent() : CreatureScript("mob_patrouilleur_de_hurlevent") {}
 
struct mob_patrouilleur_de_hurleventAI : public ScriptedAI
{
        mob_patrouilleur_de_hurleventAI(Creature *c) : ScriptedAI(c) {}
		
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
		return new mob_patrouilleur_de_hurleventAI(pCreature);
	}
};

/*************************
**Garde Royal de Hurlevent
**************************/
#define spell_cracher 58519 // Cracher
#define spell_odeur_de_banane_pourrie 58514 // Odeur De Banane pourrie
#define spell_odeur_de_pomme_pourrie 58511 // Odeur de pomme pourrie
#define spell_tir 95826 // tir
class mob_garde_royal_de_hurlevent: public CreatureScript
{
public:
 mob_garde_royal_de_hurlevent() : CreatureScript("mob_garde_royal_de_hurlevent") {}
 
struct mob_garde_royal_de_hurleventAI : public ScriptedAI
{
        mob_garde_royal_de_hurleventAI(Creature *c) : ScriptedAI(c) {}
		
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
		return new mob_garde_royal_de_hurleventAI(pCreature);
	}
};


void AddSC_mob_hurlevent()
{
    new mob_chevaucheur_de_griffon_de_hurlevent();
    new mob_garde_de_hurlevent();
    new mob_garde_du_port_de_hurlevent();
    new mob_patrouilleur_de_hurlevent();
    new mob_garde_royal_de_hurlevent();
}