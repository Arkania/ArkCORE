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

/********************
**Envahisseur Naz'jar
*********************/
#define spell_bulle_bouclier 76790 // Bulle_Bouclier
#define spell_lacerer 76807
class mob_envahisseur_nazjar: public CreatureScript
{
public:
 mob_envahisseur_nazjar() : CreatureScript("mob_envahisseur_nazjar") {}
 
struct mob_envahisseur_nazjarAI : public ScriptedAI
{
	mob_envahisseur_nazjarAI(Creature *c) : ScriptedAI(c) {}

	uint32 bulle_bouclier;
	uint32 lacerer;

	void Reset()
	{
		bulle_bouclier = 12000;
		lacerer = 5000;
	}

	void UpdateAI(const uint32 diff)
	{
		if (!UpdateVictim())
		return;
 
		if (bulle_bouclier<= diff)
		{
			DoCast(me, spell_bulle_bouclier);
			bulle_bouclier = 12000;
		} else bulle_bouclier -= diff;

		if (lacerer<= diff)
		{
			DoCast(me->getVictim(), spell_lacerer);
			lacerer = 5000;
		} else lacerer -= diff;

		DoMeleeAttackIfReady();
	}
 
};

	CreatureAI* GetAI(Creature* pCreature) const
	{
		return new mob_envahisseur_nazjarAI(pCreature);
	}
};

 
 /*******************
 **Soignesprit Nazjar
 ********************/
 
 #define spell_colere 91434 // Colère
 #define spell_malefice 91435 // Maléfice
 #define spell_vague_de_soins 76813 // Vague_de_Soins
 
 class mob_soignesprit_nazjar: public CreatureScript
 {
 public:
  mob_soignesprit_nazjar() : CreatureScript("mob_soignesprit_nazjar") {}
  
 struct mob_soignesprit_nazjarAI : public ScriptedAI
 {
 mob_soignesprit_nazjarAI(Creature *c) : ScriptedAI(c) {}
 
 uint32 colere;
 uint32 malefice;
 uint32 vague_de_soins;
 
 void Reset()
 {
 colere = 5000;
 malefice = 12000;
 vague_de_soins = 17000;
 }
 
 void UpdateAI(const uint32 diff)
 {
 if (!UpdateVictim())
 return;
 
 if (colere<= diff)
 {
 DoCast(me->getVictim(), spell_colere);
 colere = 5000;
 } else colere-= diff;
 
 if (malefice<= diff)
 {
 if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
DoCast(pTarget, spell_malefice);
malefice = 12000;
 } else malefice-= diff;

if (vague_de_soins<= diff)
{
DoCast(me, spell_vague_de_soins);
vague_de_soins = 17000;
} else vague_de_soins-= diff;

DoMeleeAttackIfReady();
 }
 };
 
 CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_soignesprit_nazjarAI(pCreature);
 }
 };
 


/******************************
**Sorcière des Tempêtes Naz'jar
*******************************/

#define spell_chaine_declairs 91450 // Chaine_d'Eclairs
#define spell_explosion_de_foudre 75992 // Explosion_de_Foudre

class mob_sorciere_des_tempetes_nazjar: public CreatureScript
{
public:
 mob_sorciere_des_tempetes_nazjar() : CreatureScript("mob_sorciere_des_tempetes_nazjar") {}
 
struct mob_sorciere_des_tempetes_nazjarAI : public ScriptedAI
{
mob_sorciere_des_tempetes_nazjarAI(Creature *c) : ScriptedAI(c) {}

uint32 chaine_declairs;
uint32 explosion_de_foudre;

void Reset()
{
chaine_declairs = 7000;
explosion_de_foudre = 10000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (chaine_declairs<= diff)
{
DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_chaine_declairs);
chaine_declairs = 7000;
} else chaine_declairs-= diff;

if (explosion_de_foudre<= diff)
{
DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_explosion_de_foudre);
explosion_de_foudre = 10000;
} else explosion_de_foudre-= diff;

DoMeleeAttackIfReady();
 }
 };
 
CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_sorciere_des_tempetes_nazjarAI(pCreature);
 }
 
 };
 

 
/*******************
**Sentinelle Naz'jar
********************/

#define spell_trempe 91443 // Trempé

class mob_sentinelle_nazjar: public CreatureScript
{
public:
 mob_sentinelle_nazjar() : CreatureScript("mob_sentinelle_nazjar") {}
 
struct mob_sentinelle_nazjarAI : public ScriptedAI
{
mob_sentinelle_nazjarAI(Creature *c) : ScriptedAI(c) {}

	uint32 trempe;

	void Reset()
	{
		trempe = 20000;
	}

	void UpdateAI(const uint32 diff)
	{
	 if (!UpdateVictim())
	 return;
 
		if (trempe<= diff)
		{
		DoCast(me, spell_trempe);
		trempe = 20000;
		} else trempe-= diff;

		DoMeleeAttackIfReady();
	 }
};
 
	CreatureAI* GetAI(Creature* pCreature) const
	{
		return new mob_sentinelle_nazjarAI(pCreature);
	}
 
};
 

 
/********************
**Corruption Instable
*********************/

#define spell_vague_de_corruption 91455 // Vague_de_Corruption

class mob_corruption_instable: public CreatureScript
{
public:
 mob_corruption_instable() : CreatureScript("mob_corruption_instable") {}
 
struct mob_corruption_instableAI : public ScriptedAI
{
mob_corruption_instableAI(Creature *c) : ScriptedAI(c) {}

uint32 vague_de_corruption;

void Reset()
{
vague_de_corruption = 12000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (vague_de_corruption<= diff)
{
DoCast(me, spell_vague_de_corruption);
vague_de_corruption = 12000;
} else vague_de_corruption -= diff;

DoMeleeAttackIfReady();
}
};
 
CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_corruption_instableAI(pCreature);
 }
 };
 
/**********************
**Factionnaire Corrompu
***********************/

#define spell_houle 76634 // Houle

class mob_factionnaire_corrompu: public CreatureScript
{
public:
 mob_factionnaire_corrompu() : CreatureScript("mob_factionnaire_corrompu") {}
 
struct mob_factionnaire_corrompuAI : public ScriptedAI
{
mob_factionnaire_corrompuAI(Creature *c) : ScriptedAI(c) {}

uint32 houle;

void Reset()
{
houle = 20000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (houle<= diff)
{
DoCast(me, spell_houle);
houle = 20000;
} else houle-= diff;

DoMeleeAttackIfReady();
}
};

CreatureAI* GetAI(Creature* pCreature) const
{
 return new mob_factionnaire_corrompuAI(pCreature);
}
 
};



/*******************
**Aquamage Gloubelin
********************/

#define spell_trait_deau 91460 // Trait_d'Eau
#define spell_tsunami 91461 // Tsunami

class mob_aquamage_gloubelin: public CreatureScript
{
public:
 mob_aquamage_gloubelin() : CreatureScript("mob_aquamage_gloubelin") {}
 
struct mob_aquamage_gloubelinAI : public ScriptedAI
{
mob_aquamage_gloubelinAI(Creature *c) : ScriptedAI(c) {}

uint32 trait_deau;
uint32 tsunami;

void Reset()
{
trait_deau = 5000;
tsunami = 14000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (trait_deau<= diff)
{
if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
DoCast(pTarget, spell_trait_deau);
trait_deau = 5000;
} else trait_deau-= diff;

if (tsunami<= diff)
{
DoCast(me->getVictim(), spell_tsunami);
tsunami = 14000;
} else tsunami-= diff;

}
};

CreatureAI* GetAI(Creature* pCreature) const
 {
return new mob_aquamage_gloubelinAI(pCreature);
}
};


/*******************
**Chasseur Gloubelin
********************/

#define spell_attaque_sournoise 76520 // Attaque_Sournoise
#define spell_lance_empoisonnee 91464 // Lançe_Empoisonnée

class mob_chasseur_gloubelin: public CreatureScript
{
public:
 mob_chasseur_gloubelin() : CreatureScript("mob_chasseur_gloubelin") {}
 
struct mob_chasseur_gloubelinAI : public ScriptedAI
{
mob_chasseur_gloubelinAI(Creature *c) : ScriptedAI(c) {}

uint32 attaque_sournoise;
uint32 lance_empoisonnee;

void Reset()
{
attaque_sournoise = 10000;
lance_empoisonnee = 8000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (attaque_sournoise<= diff)
{
DoCast(me->getVictim(), spell_attaque_sournoise);
attaque_sournoise = 10000;
} else attaque_sournoise-= diff;

if (lance_empoisonnee<= diff)
{
if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
DoCast(pTarget, spell_lance_empoisonnee);
lance_empoisonnee = 8000;
} else lance_empoisonnee-= diff;

DoMeleeAttackIfReady();
 }
 };
 
CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_chasseur_gloubelinAI(pCreature);
 }
 };
 
 
/********************
**Gardien Sans-Visage
*********************/

#define spell_dechirure_du_vide 76604 // Dechirure_du_Vide
#define spell_sol_martele 76590 // Sol_Martelé

class mob_gardien_sans_visage: public CreatureScript
{
public:
 mob_gardien_sans_visage() : CreatureScript("mob_gardien_sans_visage") {}
 
struct mob_gardien_sans_visageAI : public ScriptedAI
{
mob_gardien_sans_visageAI(Creature *c) : ScriptedAI(c) {}

uint32 dechirure_du_vide;

void Reset()
{
dechirure_du_vide = 20000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (dechirure_du_vide<= diff)
{
DoCast(me, spell_dechirure_du_vide);
DoCast(me, spell_sol_martele);
dechirure_du_vide = 20000;
} else dechirure_du_vide-= diff;

DoMeleeAttackIfReady();
}
};

CreatureAI* GetAI(Creature* pCreature) const
{
return new mob_gardien_sans_visageAI(pCreature);
}
};

void AddSC_mob_trash_trone_des_marees()
{
new mob_envahisseur_nazjar();
new mob_soignesprit_nazjar();
new mob_sorciere_des_tempetes_nazjar();
new mob_sentinelle_nazjar();
new mob_corruption_instable();
new mob_factionnaire_corrompu();
new mob_aquamage_gloubelin();
new mob_chasseur_gloubelin();
new mob_gardien_sans_visage();
}