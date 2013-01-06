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
#include "SpellScript.h"
#include "SpellAuraEffects.h"

/***************
**Vortex Sauvage
****************/

#define spell_cyclone 88010 // Cyclone
#define spell_eclair 92775 // Eclair
#define spell_horion_de_vent 92785 // Horion_De_Vent

class mob_vortex_sauvage: public CreatureScript
{
public:
 mob_vortex_sauvage() : CreatureScript("mob_vortex_sauvage") {}
 
 struct mob_vortex_sauvageAI : public ScriptedAI
 {
 mob_vortex_sauvageAI(Creature *c): ScriptedAI(c) {}
 
 uint32 cyclone;
 uint32 eclair;
 uint32 horion_de_vent;
 
 void Reset()
 {
 cyclone = 10000;
 eclair = 4000;
 horion_de_vent = 15000;
 }
 
 void UpdateAI(const uint32 diff)
 {
 if (!UpdateVictim())
 return;
 
 if (cyclone<= diff)
 {
 DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_cyclone);
 cyclone = 10000;
 } else cyclone-= diff;
 
 if (eclair<= diff)
 {
 DoCast(me->getVictim(), spell_eclair);
 eclair = 4000;
 } else eclair-= diff;
 
 if (horion_de_vent<= diff)
 {
 if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -10.0f, true))
 DoCast(spell_horion_de_vent);
 horion_de_vent = 15000;
 } else horion_de_vent-= diff;
 
 DoMeleeAttackIfReady();
 }
 
 };
 
 CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_vortex_sauvageAI(pCreature);
 }
 
 };

 /******************
 **Soldat Bourrasque
 *******************/
 
 #define spell_charge 87930 // Charge
 #define spell_coup_de_vent 92761 // Coup_De_Vent
 #define spell_nova_aerienne 93753 // Nova_Aerienne
 
 class mob_soldat_bourrasque: public CreatureScript
 {
 public: 
  mob_soldat_bourrasque() : CreatureScript("mob_soldat_bourrasque") {}
  
 struct mob_soldat_bourrasqueAI : public ScriptedAI
 {
 mob_soldat_bourrasqueAI(Creature *c) : ScriptedAI(c) {}
 
 uint32 charge;
 uint32 coup_de_vent;
 uint32 nova_aerienne;
 
 void Reset()
 {
 charge = 10000;
 coup_de_vent = 25000;
 nova_aerienne = 32000;
 }
 
 void UpdateAI(const uint32 diff)
 {
 if (!UpdateVictim())
 return;
 
 if (charge<= diff)
 {
 if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 10.0f, true))
 DoCast(spell_charge);
 charge = 10000;
 } else charge-= diff;
 
 if (coup_de_vent<= diff)
 {
 DoCast(me->getVictim(), spell_coup_de_vent);
 coup_de_vent = 25000;
 } else coup_de_vent-= diff;
 
 if (nova_aerienne<= diff)
 {
 if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -10.0f, true))
 DoCast(spell_nova_aerienne);
 } else nova_aerienne-= diff;
 
 DoMeleeAttackIfReady();
 }
 };
 
 CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_soldat_bourrasqueAI(pCreature);
 }
 
 };

 /*****************
 **Mistral Cuirassé
 ******************/
 
 #define spell_eruption_de_tempete 88055 // Eruption_de_Tempête
 #define spell_frappe_de_la_trombe 92769 // Frappe_de_la_Trombe
 #define spell_levee_du_vent 88058 // Levée_du_Vent
 
 class mob_mistral_cuirase: public CreatureScript
 {
 public:
  mob_mistral_cuirase() : CreatureScript("mob_mistral_cuirase") {}
  
 struct mob_mistral_cuiraseAI : public ScriptedAI
 {
 mob_mistral_cuiraseAI(Creature *c) : ScriptedAI(c) {}
 
 uint32 eruption_de_tempete;
 uint32 frappe_de_la_trombe;
 uint32 levee_du_vent;
 
 void Reset()
 {
 eruption_de_tempete = 25000;
 frappe_de_la_trombe = 20000;
 levee_du_vent = 15000;
 }
 
 void UpdateAI(const uint32 diff)
 {
 if (!UpdateVictim())
 return;
 
 if (eruption_de_tempete<= diff)
 {
 if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -10.0f, true))
 DoCast(spell_eruption_de_tempete);
 eruption_de_tempete = 25000;
 } else eruption_de_tempete-= diff;
 
 if (frappe_de_la_trombe<= diff)
 {
 DoCast(me->getVictim(), spell_frappe_de_la_trombe);
 frappe_de_la_trombe = 20000;
 } else frappe_de_la_trombe-= diff;
 
 if (levee_du_vent<= diff)
 {
 DoCast(me, spell_levee_du_vent);
 levee_du_vent = 15000;
 } else levee_du_vent-= diff;
 
 DoMeleeAttackIfReady();
 }
 
 };
 
 CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_mistral_cuiraseAI(pCreature);
 }
 
 };

 /*******************
 **Tempête en Maraude
 ********************/
 
 #define spell_eclair 92776 // Eclair
 #define spell_maraude 85467 // Maraude
 
 class mob_tempete_en_maraude: public CreatureScript
 {
 public:
  mob_tempete_en_maraude() : CreatureScript("mob_tempete_en_maraude") {}
  
 struct mob_tempete_en_maraudeAI : public ScriptedAI
 {
 mob_tempete_en_maraudeAI(Creature *c): ScriptedAI(c) {}
 
 uint32 eclair;
 uint32 maraude;
 
 void Reset()
 {
 eclair = 5000;
 }
 
 void UpdateAI(const uint32 diff)
 {
 if (!UpdateVictim())
 return;
 
 if (eclair<= diff)
 {
 if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
DoCast(pTarget, spell_eclair);
eclair = 5000;
} else eclair-= diff;

if(!HealthAbovePct(100))
{
DoCast(me, spell_maraude);
}

DoMeleeAttackIfReady();
 }
 
 };
 
 CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_tempete_en_maraudeAI(pCreature);
 }
 
 };

 /*************
 **Prince-Nuage
 **************/
 
 #define spell_meteores 92783 // Météores
 #define spell_typhon 92784 // Typhon
 
 class mob_prince_nuage: public CreatureScript
 {
 public:
  mob_prince_nuage() : CreatureScript("mob_prince_nuage") {}
  
 struct mob_prince_nuageAI : public ScriptedAI
 {
 mob_prince_nuageAI(Creature *c) : ScriptedAI(c) {}
 
 uint32 meteores;
 uint32 typhon;
 
 void Reset()
 {
 meteores = 20000;
 typhon = 35000;
 }
 
 void UpdateAI(const uint32 diff)
 {
 if (!UpdateVictim())
 return;
 
 if (meteores<= diff)
 {
 if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
DoCast(pTarget, spell_meteores);
meteores = 20000;
} else meteores-= diff;

if (typhon<= diff)
{
if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
DoCast(pTarget, spell_typhon);
typhon = 35000;
} else typhon-= diff;

DoMeleeAttackIfReady();
 }
 
 };
 
 CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_prince_nuageAI(pCreature);
 }
 
 };

/****************
**Grain Turbulent
*****************/

#define spell_asphyxier 92757 // Asphyxier
#define spell_explosion_nuageuse 92760 // Explosion_Nuageuse
#define spell_ouragan 92773 // Ouragan

class mob_grain_turbulent: public CreatureScript
{
public:
 mob_grain_turbulent() : CreatureScript("mob_grain_turbulent") {}
 
struct mob_grain_turbulentAI : public ScriptedAI
{
mob_grain_turbulentAI(Creature *c) : ScriptedAI(c) {}

uint32 asphyxier;
uint32 explosion_nuageuse;
uint32 ouragan;

void Reset()
{
asphyxier = 20000;
explosion_nuageuse = 30000;
ouragan = 12000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (asphyxier<= diff)
{
DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_asphyxier);
asphyxier = 20000;
} else asphyxier-= diff;

if (explosion_nuageuse<= diff)
{
DoCast(me, spell_explosion_nuageuse);
explosion_nuageuse = 30000;
} else explosion_nuageuse-= diff;

if (ouragan<= diff)
{
DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_ouragan);
ouragan = 12000;
} else ouragan-= diff;

DoMeleeAttackIfReady();
 }
 
 };
 
 CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_grain_turbulentAI(pCreature);
 }
 
 };

/******************
**Assassin Empyréen
*******************/

#define spell_forme_de_vapeur 88186 // Forme_de_Vapeur
#define spell_poison_lethargique 92774 // Poison_Léthargique

class mob_assassin_empyreen: public CreatureScript
{
public:
 mob_assassin_empyreen() : CreatureScript("mob_assassin_empyreen") {}
 
struct mob_assassin_empyreenAI : public ScriptedAI
{
mob_assassin_empyreenAI(Creature *c) : ScriptedAI(c) {}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
return;

if(!HealthAbovePct(25))
{
DoCast(me, spell_forme_de_vapeur);
}

if(!HealthAbovePct(99))
{
DoCast(me, spell_poison_lethargique);
}

DoMeleeAttackIfReady();
}
};
  
CreatureAI* GetAI(Creature* pCreature) const
{
return new mob_assassin_empyreenAI(pCreature);
}
  
};

/**************************
**Jeune Dragon des Tempêtes
***************************/

#define spell_explosion_glaciale 92759 // Explosion_Glaciale
#define spell_frappes_brutales 88192 // Frappes_Brutales

class mob_jeune_dragon_des_tempetes: public CreatureScript
{
public:
 mob_jeune_dragon_des_tempetes() : CreatureScript("mob_jeune_dragon_des_tempetes") {}
 
struct mob_jeune_dragon_des_tempetesAI : public ScriptedAI
{
mob_jeune_dragon_des_tempetesAI(Creature *c) : ScriptedAI(c) {}

uint32 explosion_glaciale;

void Reset()
{
explosion_glaciale = 30000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
return;

if (explosion_glaciale<= diff)
{
DoCast(me->getVictim(), spell_explosion_glaciale);
explosion_glaciale = 30000;
} else explosion_glaciale-= diff;

if(!HealthAbovePct(30))
{
DoCast(me, spell_frappes_brutales);
}

DoMeleeAttackIfReady();
}
};

CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_jeune_dragon_des_tempetesAI(pCreature);
 }
 
 };

/******************
**Ministre de l'Air
*******************/

#define spell_fouet_foudroyant 87762 // Fouet_Foudroyant
#define spell_nova_de_foudre 92780 // Nova_de_Foudre

class mob_minsistre_de_lair: public CreatureScript
{
public:
 mob_minsistre_de_lair() : CreatureScript("mob_minsistre_de_lair") {}
 
struct mob_minsistre_de_lairAI : public ScriptedAI
{
mob_minsistre_de_lairAI(Creature *c) : ScriptedAI(c) {}

uint32 fouet_foudroyant;
uint32 nova_de_foudre;

void Reset()
{
fouet_foudroyant = 15000;
nova_de_foudre = 25000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
return;

if (fouet_foudroyant<= diff)
{
DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_fouet_foudroyant);
fouet_foudroyant = 15000;
} else fouet_foudroyant-= diff;

if (nova_de_foudre<= diff)
{
if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -10.0f, true))
DoCast(target, spell_nova_de_foudre);
nova_de_foudre = 25000;
} else nova_de_foudre-= diff;

DoMeleeAttackIfReady();
}
};

CreatureAI* GetAI(Creature* pCreature) const
{
return new mob_minsistre_de_lairAI(pCreature);
}

};

/*****************
**Adepte du Temple
******************/

#define spell_chatiment_sacre 92772 // Chatiment_Sacré
#define spell_soins_superieurs 92770 // Soins_Superieurs
#define spell_vitesse_desesperee 92763 // Vitesse_Despesperee

class mob_adepte_du_temple: public CreatureScript
{
public:
 mob_adepte_du_temple() : CreatureScript("mob_adepte_du_temple") {}
 
struct mob_adepte_du_templeAI : public ScriptedAI
{
mob_adepte_du_templeAI(Creature *c) : ScriptedAI(c) {}

uint32 chatiment_sacre;
uint32 soins_superieurs;
uint32 vitesse_desesperee;

void Reset()
{
chatiment_sacre = 10000;
soins_superieurs = 15000;
vitesse_desesperee = 30000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (chatiment_sacre<= diff)
{
if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
DoCast(pTarget, spell_chatiment_sacre);
chatiment_sacre = 10000;
} else chatiment_sacre-= diff;

if (soins_superieurs<= diff)
{
DoCast(me, spell_soins_superieurs);
soins_superieurs = 15000;
} else soins_superieurs-= diff;

if (vitesse_desesperee<= diff)
{
DoCast(me, spell_vitesse_desesperee);
vitesse_desesperee = 30000;
} else vitesse_desesperee-= diff;

DoMeleeAttackIfReady();
}
 
};

CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_adepte_du_templeAI(pCreature);
 }
 
 };

/******************
**Serviteur d'Asaad
*******************/

#define spell_frappe_du_croise 92762 // Frappe_du_Croisé
#define spell_main_de_protection 87772 // Main_de_Protection
#define spell_tempete_divine 58127 // Tempête_Divine

class mob_serviteur_dasaad: public CreatureScript
{
public:
 mob_serviteur_dasaad() : CreatureScript("mob_serviteur_dasaad") {}
 
struct mob_serviteur_dasaadAI : public ScriptedAI
{
mob_serviteur_dasaadAI(Creature *c) : ScriptedAI(c) {}

uint32 frappe_du_croise;
uint32 main_de_protection;
uint32 tempete_divine;

void Reset()
{
frappe_du_croise = 10000;
main_de_protection = 25000;
tempete_divine = 15000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;

if (frappe_du_croise<= diff)
{
DoCast(me->getVictim(), spell_frappe_du_croise);
frappe_du_croise = 10000;
} else frappe_du_croise-= diff;

if (main_de_protection<= diff)
{
DoCast(me, spell_main_de_protection);
main_de_protection = 25000;
} else main_de_protection-= diff;

if (tempete_divine<= diff)
{
if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -10.0f, true))
DoCast(me, spell_tempete_divine);
tempete_divine = 15000;
} else tempete_divine-= diff;

DoMeleeAttackIfReady();
}
 
};

CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_serviteur_dasaadAI(pCreature);
 }
 
 };

/********************
**Exécuteur du Calife
*********************/

#define spell_devaster 78660 // Devaster
#define spell_onde_de_choc 92782 // Onde_de_Choc
#define spell_ralliement 87761 // Ralliement

class mob_executeur_du_calife: public CreatureScript
{
public:
 mob_executeur_du_calife() : CreatureScript("mob_executeur_du_calife") {}
 
struct mob_executeur_du_califeAI : public ScriptedAI
{
mob_executeur_du_califeAI(Creature *c) : ScriptedAI(c) {}

uint32 devaster;
uint32 onde_de_choc;
uint32 ralliement;

void Reset()
{
devaster = 6000;
onde_de_choc = 15000;
ralliement = 35000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (devaster<= diff)
{
DoCast(me->getVictim(), spell_devaster);
devaster = 6000;
} else devaster-= diff;

if (onde_de_choc<= diff)
{
DoCast(me->getVictim(), spell_onde_de_choc);
onde_de_choc = 15000;
} else onde_de_choc-= diff;

if (ralliement<= diff)
{
DoCastAOE(spell_ralliement);
ralliement = 35000;
} else ralliement-= diff;

DoMeleeAttackIfReady();
}
 
};

CreatureAI* GetAI(Creature* pCreature) const
 {
 return new mob_executeur_du_califeAI(pCreature);
 }
};
 
/******************
**Etoile Tombe-Ciel
*******************/

#define spell_barrage_des_arcanes 87854 // Barrage_des_Arcanes

class mob_etoile_tombe_ciel: public CreatureScript
{
public:
 mob_etoile_tombe_ciel() : CreatureScript("mob_etoile_tombe_ciel") {}
 
struct mob_etoile_tombe_cielAI : public ScriptedAI
{
mob_etoile_tombe_cielAI(Creature *c) : ScriptedAI(c) {}

uint32 barrage_des_arcanes;

void Reset()
{
barrage_des_arcanes = 4000;
}

void UpdateAI(const uint32 diff)
{
if (!UpdateVictim())
 return;
 
if (barrage_des_arcanes<= diff)
{
if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
DoCast(pTarget, spell_barrage_des_arcanes);
barrage_des_arcanes = 4000;
} else barrage_des_arcanes-= diff;

}

};

CreatureAI* GetAI(Creature* pCreature) const
{
return new mob_etoile_tombe_cielAI(pCreature);
}

};

void AddSC_mob_trash_cime_du_vortex()
{
new mob_vortex_sauvage();
new mob_soldat_bourrasque();
new mob_mistral_cuirase();
new mob_tempete_en_maraude();
new mob_prince_nuage();
new mob_grain_turbulent();
new mob_assassin_empyreen();
new mob_jeune_dragon_des_tempetes();
new mob_minsistre_de_lair();
new mob_adepte_du_temple();
new mob_serviteur_dasaad();
new mob_executeur_du_calife();
new mob_etoile_tombe_ciel();
}