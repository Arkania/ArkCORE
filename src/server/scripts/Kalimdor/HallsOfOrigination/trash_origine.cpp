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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

/**********************
**Lancelombre du Temple
***********************/

#define spell_lance_de_lombre 89555 // Lance_de_L'ombre
#define spell_pacte_des_tenebres 89560 // Pacte_des_Ténèbres

class mob_lancelombre_du_temple : public CreatureScript
{
public:
       mob_lancelombre_du_temple() : CreatureScript("mob_lancelombre_du_temple") {}
	   
	   struct mob_lancelombre_du_templeAI : public ScriptedAI
	   {
	      mob_lancelombre_du_templeAI(Creature *c) : ScriptedAI(c) {}
		  
		  uint32 lance_de_lombre;
		  uint32 pacte_des_tenebres;
		  
		  void Reset()
		  {
		  lance_de_lombre = 20000;
		  pacte_des_tenebres = 25000;
		  }
		  
		  void UpdateAI(const uint32 diff)
		  {
		    if (!UpdateVictim())
            return;
			
			if (lance_de_lombre<= diff)
			{
			DoCast(me, spell_lance_de_lombre);
			lance_de_lombre = 20000;
			} else lance_de_lombre -= diff;
			
			if (pacte_des_tenebres<= diff)
			{
			DoCast(me, spell_pacte_des_tenebres);
			pacte_des_tenebres = 25000;
			} else pacte_des_tenebres -= diff;
			
			DoMeleeAttackIfReady();
          }
       };
	   
	  CreatureAI* GetAI(Creature* pCreature) const
      {
           return new mob_lancelombre_du_templeAI(pCreature);
	  }
};

/**************************
**Traqueur Veloce du Temple
***************************/

#define spell_fleches_multiples 84836 // Flèches_Multiples
#define spell_tir 83877 // Tir
#define spell_tir_charge 94791 // Tir_Chargé

class mob_traqueur_veloce_du_temple : public CreatureScript
{
public:
      mob_traqueur_veloce_du_temple() : CreatureScript("mob_traqueur_veloce_du_temple") {}
	  
	  struct mob_traqueur_veloce_du_templeAI : public ScriptedAI
      {
         mob_traqueur_veloce_du_templeAI(Creature *c) : ScriptedAI(c) {}

		 uint32 fleches_multiples;
		 uint32 tir;
		 uint32 tir_charge;
		 
		 void Reset()
		 {
		 fleches_multiples = 12000;
		 tir = 2500;
		 tir_charge = 19000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
		    if (!UpdateVictim())
            return;
			
			if (fleches_multiples<= diff)
			{
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 10.0f, true))
			DoCast(target, spell_fleches_multiples);
			fleches_multiples = 12000;
			} else fleches_multiples -= diff;
			
			if (tir<= diff)
			{
			DoCast(me->getVictim(), spell_tir);
			tir = 2500;
			} else tir -= diff;
			
			if (tir_charge<= diff)
			{
			if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
            DoCast(pTarget, spell_tir_charge);
			tir_charge = 19000;
			} else tir_charge -= diff;
			
			 DoMeleeAttackIfReady();
         }
      };
	  
	  CreatureAI* GetAI(Creature* pCreature) const
      {
           return new mob_traqueur_veloce_du_templeAI(pCreature);
	  }	   
};	  

/***************************
**Lanceur de Runes du Temple
****************************/

#define spell_enchainement_runique 91806 // Enchainement_Runique
#define spell_malediction_du_lanceur_de_runes 95181 // Malédiction_du_Lanceur_de_Runes

class mob_lanceur_de_runes_du_temple : public CreatureScript
{
public:
      mob_lanceur_de_runes_du_temple() : CreatureScript("mob_lanceur_de_runes_du_temple") {}
	  
	  struct mob_lanceur_de_runes_du_templeAI : public ScriptedAI
	  {
	     mob_lanceur_de_runes_du_templeAI(Creature *c) : ScriptedAI(c) {}
		 
		 uint32 enchainement_runique;
		 uint32 malediction_du_lanceur_de_runes;
		 
		 void Reset()
		 {
		 enchainement_runique = 10000;
		 malediction_du_lanceur_de_runes = 15000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
		    if (!UpdateVictim())
            return;
			
			if (enchainement_runique<= diff)
			{
			DoCast(me->getVictim(), spell_enchainement_runique);
			enchainement_runique = 10000;
			} else enchainement_runique -= diff;
			
			if (malediction_du_lanceur_de_runes<= diff)
			{
			DoCast(SelectTarget(SELECT_TARGET_RANDOM,0,100,true), spell_malediction_du_lanceur_de_runes);
			malediction_du_lanceur_de_runes = 15000;
			} else malediction_du_lanceur_de_runes -= diff;
			
			DoMeleeAttackIfReady();
         }
      };
	  
	  CreatureAI* GetAI(Creature* pCreature) const
      {
           return new mob_lanceur_de_runes_du_templeAI(pCreature);
	  }
};

/*********************
**Sculptefeu du Temple
**********************/

#define spell_barriere_de_la_fournaise 89542 // Barriere_de_la_Fournaise
#define spell_boule_de_feu 89854 // Boule_de_Feu
#define spell_eruption_flamboyante 89547 // Eruption_Flamboyante
#define spell_meteore 90023 // Météore

class mob_sculptefeu_du_temple : public CreatureScript
{
public:
      mob_sculptefeu_du_temple() : CreatureScript("mob_sculptefeu_du_temple") {}
	  
	  struct mob_sculptefeu_du_templeAI : public ScriptedAI
	  {
	     mob_sculptefeu_du_templeAI(Creature *c) : ScriptedAI(c) {}
		 
		 uint32 barriere_de_la_fournaise;
		 uint32 boule_de_feu;
		 uint32 eruption_flamboyante;
		 uint32 meteore;
		 
		 void Reset()
		 {
		 barriere_de_la_fournaise = 45000;
		 boule_de_feu = 4000;
		 eruption_flamboyante = 60000;
		 meteore = 30000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
		    if (!UpdateVictim())
            return;
			
			if (barriere_de_la_fournaise<= diff)
			{
			DoCast(me, spell_barriere_de_la_fournaise);
			barriere_de_la_fournaise = 45000;
			} else barriere_de_la_fournaise -= diff;
			
			if (boule_de_feu<= diff)
			{
			DoCast(me->getVictim(), spell_boule_de_feu);
			boule_de_feu = 4000;
			} else boule_de_feu -= diff;
			
			if (eruption_flamboyante<= diff)
			{
			DoCast(me, spell_eruption_flamboyante);
			eruption_flamboyante = 60000;
			} else eruption_flamboyante -= diff;
			
			if (meteore<= diff)
			{
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 10.0f, true))
			DoCast(target, spell_meteore);
			meteore = 30000;
			} else meteore -= diff;
			
			DoMeleeAttackIfReady();
         }
      };
	
	CreatureAI* GetAI(Creature* pCreature) const
    {
           return new mob_sculptefeu_du_templeAI(pCreature);
    }
	
};

/*******************
**Scarabée Caustique
********************/

#define spell_attaque_a_la_lame_dentelee 74542 // Attaque_a_la_Lame_Dentelée
#define spell_projection_corrosive 89857 // Projection_Corrosive

class mob_scarabee_caustique : public CreatureScript
{
public:
      mob_scarabee_caustique() : CreatureScript("mob_scarabee_caustique") {}
	  
	  struct mob_scarabee_caustiqueAI : public ScriptedAI
	  {
	     mob_scarabee_caustiqueAI(Creature *c) : ScriptedAI(c) {}
		 
		 uint32 attaque_a_la_lame_dentelee;
		 uint32 projection_corrosive;
		 
		 void Reset()
		 {
		 attaque_a_la_lame_dentelee = 15000;
		 projection_corrosive = 10000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
		    if (!UpdateVictim())
            return;
			
			if (attaque_a_la_lame_dentelee<= diff)
			{
			DoCast(me->getVictim(), spell_attaque_a_la_lame_dentelee);
			attaque_a_la_lame_dentelee = 15000;
			} else attaque_a_la_lame_dentelee -= diff;
			
			if (projection_corrosive<= diff)
			{
			DoCast(me, spell_projection_corrosive);
			projection_corrosive = 10000;
			} else projection_corrosive -= diff;
			
			DoMeleeAttackIfReady();
         }
      };
	
	CreatureAI* GetAI(Creature* pCreature) const
    {
            return new mob_scarabee_caustiqueAI(pCreature);
	}
	
};

/******************
**Glisseur Venimeux
*******************/

#define spell_afflux 75158 // Afflux
#define spell_toxine RAND(89859,89856) // Toxine

class mob_glisseur_venimeux : public CreatureScript
{
public:
      mob_glisseur_venimeux() : CreatureScript("mob_glisseur_venimeux") {}
	  
	  struct mob_glisseur_venimeuxAI : public ScriptedAI
	  {
	     mob_glisseur_venimeuxAI(Creature *c) : ScriptedAI(c) {}
		 
		 uint32 afflux;
		 uint32 toxine;
		 
		 void Reset()
		 {
		 afflux = 15000;
		 toxine = 10000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
		    if (!UpdateVictim())
            return;
			
			if (afflux<= diff)
			{
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 10.0f, true))
			DoCast(target, spell_afflux);
			afflux = 15000;
			} else afflux -= diff;
			
			if (toxine<= diff)
			{
			DoCast(me->getVictim(), spell_toxine);
			toxine = 10000;
			} else toxine -= diff;
			
			DoMeleeAttackIfReady();
         }
      };
	  
	CreatureAI* GetAI(Creature* pCreature) const
    {
           return new mob_glisseur_venimeuxAI(pCreature);
    }
	
};

/*********************
**Horreur Os-Poussière
**********************/

#define spell_choc 75453 // Choc

class mob_horreur_os_poussiere : public CreatureScript
{
public:
      mob_horreur_os_poussiere() : CreatureScript("mob_horreur_os_poussiere") {}
	  
	  struct mob_horreur_os_poussiereAI : public ScriptedAI
	  {
	     mob_horreur_os_poussiereAI(Creature *c) : ScriptedAI(c) {}
		 
		 uint32 choc;
		 
		 void Reset()
		 {
		 choc = 5000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
		    if (!UpdateVictim())
            return;
			
			if (choc<= diff)
			{
			DoCast(me->getVictim(), spell_choc);
			choc = 5000;
			} else choc -= diff;
			
			DoMeleeAttackIfReady();
         }
      };
	
    CreatureAI* GetAI(Creature* pCreature) const
    {
            return new mob_horreur_os_poussiereAI(pCreature);
    }

};

/*************************
**Tourmenteur Os-Poussière
**************************/

#define spell_trait_de_lombre 89855 // Trait_de_Lombre
#define spell_malediction_depuisement 90006 // Malédiction_d'Epuisement

class mob_tourmenteur_os_poussiere : public CreatureScript
{
public:
      mob_tourmenteur_os_poussiere() : CreatureScript("mob_tourmenteur_os_poussiere") {}
	  
	  struct mob_tourmenteur_os_poussiereAI : public ScriptedAI
	  {
	     mob_tourmenteur_os_poussiereAI(Creature *c) : ScriptedAI(c) {}
		 
		 uint32 trait_de_lombre;
		 uint32 malediction_depuisement;
		 
		 void Reset()
		 {
		 trait_de_lombre = 6000;
		 malediction_depuisement = 10000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
		    if (!UpdateVictim())
            return;
			
			if (trait_de_lombre<= diff)
			{
			DoCast(me->getVictim(), spell_trait_de_lombre);
			trait_de_lombre = 6000;
			} else trait_de_lombre -= diff;
			
			if (malediction_depuisement<= diff)
			{
			if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
            DoCast(pTarget, spell_malediction_depuisement);
			malediction_depuisement = 10000;
			} else malediction_depuisement -= diff;
			
			DoMeleeAttackIfReady();
         }
      };
	  
	CreatureAI* GetAI(Creature* pCreature) const
    {
           return new mob_tourmenteur_os_poussiereAI(pCreature);
	}
	
};

/******************
**Chercheur du Vide
*******************/

#define spell_prison_anti_magie 76903 // Prison_Anti_Magie
#define spell_salve_de_traits_de_lombre 89846 // Salve_de_Traits_de_l'Ombre

class mob_chercheur_du_vide : public CreatureScript
{
public: 
     mob_chercheur_du_vide() : CreatureScript("mob_chercheur_du_vide") {}
	 
	 struct mob_chercheur_du_videAI : public ScriptedAI
	 {
	    mob_chercheur_du_videAI(Creature *c) : ScriptedAI(c) {}
		
		uint32 prison_anti_magie;
		uint32 salve_de_traits_de_lombre;
		
		void Reset()
		{
		prison_anti_magie = 30000;
		salve_de_traits_de_lombre = 12000;
		}
		
		void UpdateAI(const uint32 diff)
		{
		   if (!UpdateVictim())
           return;
		   
		   if (prison_anti_magie<= diff)
		   {
		   DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_prison_anti_magie);
		   prison_anti_magie = 30000;
		   } else prison_anti_magie -= diff;
		   
		   if (salve_de_traits_de_lombre<= diff)
		   {
		   DoCast(me, spell_salve_de_traits_de_lombre);
		   salve_de_traits_de_lombre = 12000;
		   } else salve_de_traits_de_lombre -= diff;
		   
		   DoMeleeAttackIfReady();
        }
     };
	
	CreatureAI* GetAI(Creature* pCreature) const
    {
          return new mob_chercheur_du_videAI(pCreature);
	}
	
};
	
/*****************
**Seigneur du Vide
******************/

#define spell_explosion_de_vide 89847 // Explosion_de_Vide
#define spell_salve_de_traits_de_lombre 89846 // Salve_de_Traits_de_l'Ombre
#define spell_infusion_de_vide 77470 // A mettre en place prochainement

class mob_seigneur_du_vide : public CreatureScript
{
public:
      mob_seigneur_du_vide() : CreatureScript("mob_seigneur_du_vide") {}
	  
	  struct mob_seigneur_du_videAI : public ScriptedAI
	  {
	     mob_seigneur_du_videAI(Creature *c) : ScriptedAI(c) {}
		 
		 uint32 explosion_de_vide;
		 uint32 salve_de_traits_de_lombre;
		 
		 void Reset()
		 {
		 explosion_de_vide = 30000;
		 salve_de_traits_de_lombre = 16000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
		    if (!UpdateVictim())
            return;
			
			if (explosion_de_vide<= diff)
			{
			DoCast(me, spell_explosion_de_vide);
			explosion_de_vide = 30000;
			} else explosion_de_vide -= diff;
			
			if (salve_de_traits_de_lombre<= diff)
			{
			DoCast(me, spell_salve_de_traits_de_lombre);
			salve_de_traits_de_lombre = 16000;
			} else salve_de_traits_de_lombre -= diff;
			
			DoMeleeAttackIfReady();
         }
      };
			
	CreatureAI* GetAI(Creature* pCreature) const
    {
           return new mob_seigneur_du_videAI(pCreature);
	}
	
};

/******************
**Anomalie Spatiale
*******************/

#define spell_jaillissement_des_arcanes 89862 // Jaillissement_des_Arcanes

class mob_anomalie_spatiale : public CreatureScript
{
public:
     mob_anomalie_spatiale() : CreatureScript("mob_anomalie_spatiale") {}
	 
	 struct mob_anomalie_spatialeAI : public ScriptedAI
	 {
	    mob_anomalie_spatialeAI(Creature *c) : ScriptedAI(c) {}
		
		uint32 jaillissement_des_arcanes;
		
		void Reset()
		{
		jaillissement_des_arcanes = 15000;
		}
		
		void UpdateAI(const uint32 diff)
		{
		     if (!UpdateVictim())
             return;
			 
			 if (jaillissement_des_arcanes<= diff)
			 {
			 DoCast(me, spell_jaillissement_des_arcanes);
			 jaillissement_des_arcanes = 15000;
			 } else jaillissement_des_arcanes -= diff;
			 
			  DoMeleeAttackIfReady();
        }
     };
	
	CreatureAI* GetAI(Creature* pCreature) const
    {
            return new mob_anomalie_spatialeAI(pCreature);
	}
		
};

/******************
**Animateur de Flux
*******************/

#define spell_barrage_des_arcanes 89863 // Barrage_des_Arcanes

class mob_animateur_de_flux : public CreatureScript
{
public:
     mob_animateur_de_flux() : CreatureScript("mob_animateur_de_flux") {}
	 
	 struct mob_animateur_de_fluxAI : public ScriptedAI
	 {
	    mob_animateur_de_fluxAI(Creature *c) : ScriptedAI(c) {}
		
		uint32 barrage_des_arcanes;
		
		void Reset()
		{
		barrage_des_arcanes = 8000;
		}
		
		void UpdateAI(const uint32 diff)
		{
		   if (!UpdateVictim())
           return;
		   
		   if (barrage_des_arcanes<= diff)
		   {
		   if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
           DoCast(pTarget, spell_barrage_des_arcanes);
		   barrage_des_arcanes = 8000;
		   } else barrage_des_arcanes -= diff;
		   
		   DoMeleeAttackIfReady();
        }
     };
	 
	CreatureAI* GetAI(Creature* pCreature) const
    {
          return new mob_animateur_de_fluxAI(pCreature);
    }
	
};

/********************
**Serviteur Solegrâce
*********************/

#define spell_disperser 88097 // A mettre en place plus tard
#define spell_dispersion_des_flammes 89852 // Dispersion_des_Flammes
#define spell_flammes_incendiaires 89849 // Flammes_Incendiaires

class mob_serviteur_solegrace : public CreatureScript
{
public :
    mob_serviteur_solegrace() : CreatureScript("mob_serviteur_solegrace") {}
	  
	struct mob_serviteur_solegraceAI : public ScriptedAI
	{
	    mob_serviteur_solegraceAI(Creature *c) : ScriptedAI(c) {}
		  
		uint32 dispersion_des_flammes;
		uint32 flammes_incendiaires;
		  
		void Reset()
		{
		dispersion_des_flammes = 15000;
		flammes_incendiaires = 10000;
		}
		  
		void UpdateAI(const uint32 diff)
		{
		      if (!UpdateVictim())
              return;
			  
			  if (dispersion_des_flammes<= diff)
			  {
			  DoCast(me, dispersion_des_flammes);
			  dispersion_des_flammes = 15000;
			  } else dispersion_des_flammes -= diff;
			  
			  if (flammes_incendiaires<= diff)
			  {
			  if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
              DoCast(pTarget, spell_flammes_incendiaires);
			  flammes_incendiaires = 10000;
			  } else flammes_incendiaires -= diff;
			  
			  DoMeleeAttackIfReady();
        }
    };
	  
	CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_serviteur_solegraceAI(pCreature);
	}
	
};

/**************
**Fée Solegrace
***************/

#define spell_disperser 88097 // A mettre en place plus tard
#define spell_pyrogenie 76158 // Pyrogénie
#define spell_dispersion_des_flammes 89852 // Dispersion_des_Flammes
#define spell_flammes_incendiaires 89849 // Flammes_Incendiaires

class mob_fee_solegrace : public CreatureScript
{
public :
    mob_fee_solegrace() : CreatureScript("mob_fee_solegrace") {}
	  
	struct mob_fee_solegraceAI : public ScriptedAI
	{
	    mob_fee_solegraceAI(Creature *c) : ScriptedAI(c) {}
		 
		uint32 pyrogenie;
		uint32 dispersion_des_flammes;
		uint32 flammes_incendiaires;
		 
		void Reset()
		{
		pyrogenie = 30000;
		dispersion_des_flammes = 20000;
		flammes_incendiaires = 15000;
		}
		 
		void UpdateAI(const uint32 diff)
		{
		    if (!UpdateVictim())
            return;
			
			if (pyrogenie<= diff)
			{
			DoCast(me, spell_pyrogenie);
			pyrogenie = 30000;
			} else pyrogenie -= diff;
			
			if (dispersion_des_flammes<= diff)
			{
			DoCast(me, dispersion_des_flammes);
			dispersion_des_flammes = 20000;
			} else dispersion_des_flammes -= diff;
			  
			if (flammes_incendiaires<= diff)
			{
			if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
            DoCast(pTarget, spell_flammes_incendiaires);
			flammes_incendiaires = 15000;
			} else flammes_incendiaires -= diff;
			
			DoMeleeAttackIfReady();
        }
    };
	 		
	CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_fee_solegraceAI(pCreature);
    }			
	
};

/*********************
**Petite Fée Solegrace
**********************/

#define spell_pyrogenie 76158 // Pyrogénie
#define spell_dispersion_des_flammes 89852 // Dispersion_des_Flammes
#define spell_flammes_incendiaires 89849 // Flammes_Incendiaires

class mob_petite_fee_solegrace : public CreatureScript
{
public :
    mob_petite_fee_solegrace() : CreatureScript("mob_petite_fee_solegrace") {}

	struct mob_petite_fee_solegraceAI : public ScriptedAI
	{
	    mob_petite_fee_solegraceAI(Creature *c) : ScriptedAI(c) {}

		uint32 pyrogenie;
		uint32 dispersion_des_flammes;
		uint32 flammes_incendiaires;

		void Reset()
		{
		pyrogenie = 30000;
		dispersion_des_flammes = 20000;
		flammes_incendiaires = 15000;
		}

		void UpdateAI(const uint32 diff)
		{
		    if (!UpdateVictim())
            return;

			if (pyrogenie<= diff)
			{
			DoCast(me, spell_pyrogenie);
			pyrogenie = 30000;
			} else pyrogenie -= diff;

			if (dispersion_des_flammes<= diff)
			{
			DoCast(me, dispersion_des_flammes);
			dispersion_des_flammes = 20000;
			} else dispersion_des_flammes -= diff;

			if (flammes_incendiaires<= diff)
			{
			if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
            DoCast(pTarget, spell_flammes_incendiaires);
			flammes_incendiaires = 15000;
			} else flammes_incendiaires -= diff;

			DoMeleeAttackIfReady();
        }
    };

	CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_petite_fee_solegraceAI(pCreature);
    }

};

/***********************
**Porte Parole Solegrace
************************/

#define spell_pietinement_reverberant 89851 // Piétinement_Réverbérant
#define spell_tempete_de_feu 73861 // Tempête_de_Feu

class mob_porte_parole_solegrace : public CreatureScript
{
public:
      mob_porte_parole_solegrace() : CreatureScript("mob_porte_parole_solegrace") {}
	  
	  struct mob_porte_parole_solegraceAI : public ScriptedAI
	  {
	     mob_porte_parole_solegraceAI(Creature *c) : ScriptedAI(c) {}
		 
		 uint32 pietinement_reverberant;
		 uint32 tempete_de_feu;
		 
		 void Reset()
		 {
		 pietinement_reverberant = 25000;
		 tempete_de_feu = 13000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
		    if (!UpdateVictim())
            return;
			
			if (pietinement_reverberant<= diff)
			{
			DoCast(me->getVictim(), spell_pietinement_reverberant);
			pietinement_reverberant = 25000;
			} else pietinement_reverberant -= diff;
			
			if (tempete_de_feu<= diff)
			{
			DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_tempete_de_feu);
			tempete_de_feu = 13000;
			} else tempete_de_feu -= diff;
			
			DoMeleeAttackIfReady();
         }
      };
    
    CreatureAI* GetAI(Creature* pCreature) const
    {
            return new mob_porte_parole_solegraceAI(pCreature);
	}
	
};

/***************************
**Nymphe Gardienne de la Vie
****************************/

#define spell_tir 75958 // Tir
#define spell_tir_enchevetrant 89865 // Tir_Enchevetrant
#define spell_tranquillite 75940 // Tranquillité

class mob_nymphe_gardienne : public CreatureScript
{
public :
      mob_nymphe_gardienne() : CreatureScript("mob_nymphe_gardienne") {}
	  
	  struct mob_nymphe_gardienneAI : public ScriptedAI
	  {
	      mob_nymphe_gardienneAI(Creature *c) : ScriptedAI(c) {}
		  
		  uint32 tir;
		  uint32 tir_enchevetrant;
		  uint32 tranquillite;
		  
		  void Reset()
		  {
		  tir = 4000;
		  tir_enchevetrant = 22000;
		  tranquillite = 35000;
		  }
		  
		  void UpdateAI(const uint32 diff)
		  {
		     if (!UpdateVictim())
             return;
			 
			 if (tir<= diff)
			 {
			 DoCast(me->getVictim(), spell_tir);
			 tir = 4000;
			 } else tir -= diff;
			 
			 if (tir_enchevetrant<= diff)
			 {
			 if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 10.0f, true))
			 DoCast(target, spell_tir_enchevetrant);
			 tir_enchevetrant = 22000;
			 } else tir_enchevetrant -= diff;
			 
			 if (tranquillite<= diff)
			 {
			 DoCast(me, spell_tranquillite);
			 tranquillite = 35000;
			 } else tranquillite -= diff;
			 
			 DoMeleeAttackIfReady();
           }
      };
	  
	CreatureAI* GetAI(Creature* pCreature) const
    {
            return new mob_nymphe_gardienneAI(pCreature);
	}
	
};

/**************
**Liane Vivante
***************/

#define spell_souffle_de_spores 89864 // Souffle_de_Spores

class mob_liane_vivante : public CreatureScript
{
public :
      mob_liane_vivante() : CreatureScript("mob_liane_vivante") {}
	  
	  struct mob_liane_vivanteAI : public ScriptedAI
	  {
	     mob_liane_vivanteAI(Creature *c) : ScriptedAI(c) {}
		 
		 uint32 souffle_de_spores;
		 
		 void Reset()
		 {
		 souffle_de_spores = 8000;
		 }
		 
		 void UpdateAI(const uint32 diff)
		 {
	        if (!UpdateVictim())
            return;

			if (souffle_de_spores<= diff)
			{
			if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
            DoCast(pTarget, spell_souffle_de_spores);
			souffle_de_spores = 8000;
			} else souffle_de_spores -= diff;
			
			DoMeleeAttackIfReady();
         }
      };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_liane_vivanteAI(pCreature);
    }		   

};

/******************
**Spore en Bourgeon
*******************/

#define spell_nuage_de_spores 75701 // Nuage_de_Spores
#define spell_spores_nauseabondes 89889 // Spores_Nauséabondes

class mob_spore_en_bourgeon : public CreatureScript
{
public :
    mob_spore_en_bourgeon() : CreatureScript("mob_spore_en_bourgeon") {}
	  
	struct mob_spore_en_bourgeonAI : public ScriptedAI
	{
	    mob_spore_en_bourgeonAI(Creature *c) : ScriptedAI(c) {}

		uint32 nuage_de_spores;
		uint32 spores_nauseabondes;
		 
		void Reset()
		{
			nuage_de_spores = 5000;
			spores_nauseabondes = 10000;
		}
		 
		void UpdateAI(const uint32 diff)
		{
		    if (!UpdateVictim())
            return;
			
			if (nuage_de_spores<= diff)
			{
			DoCast(me, spell_nuage_de_spores);
			nuage_de_spores = 5000;
			} else nuage_de_spores -= diff;
			
			if (spores_nauseabondes<= diff)
			{
			DoCast(me, spell_spores_nauseabondes);
			spores_nauseabondes = 10000;
			} else spores_nauseabondes -= diff;
			
			DoMeleeAttackIfReady();
        }
    };
		
	CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_spore_en_bourgeonAI(pCreature);
    }		   

};

void AddSC_mob_trash_sdo()
{
    new mob_lancelombre_du_temple();
    new mob_traqueur_veloce_du_temple();
	new mob_lanceur_de_runes_du_temple();
	new mob_sculptefeu_du_temple();
	new mob_scarabee_caustique();
	new mob_glisseur_venimeux();
	new mob_horreur_os_poussiere();
	new mob_tourmenteur_os_poussiere();
	new mob_chercheur_du_vide();
	new mob_seigneur_du_vide();
	new mob_anomalie_spatiale();
	new mob_animateur_de_flux();
	new mob_serviteur_solegrace();
	new mob_fee_solegrace();
	new mob_petite_fee_solegrace();
	new mob_porte_parole_solegrace();
	new mob_nymphe_gardienne();
	new mob_liane_vivante();
	new mob_spore_en_bourgeon();
}