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
**Unbound Earth Rager
*********************/

#define spell_fracture 87711 // Fracture

class mob_unbound_earth_rager : public CreatureScript
{
 public:
      mob_unbound_earth_rager() : CreatureScript("mob_unbound_earth_rager") {}
	  
	  struct mob_unbound_earth_ragerAI : public ScriptedAI
	  {
	    mob_unbound_earth_ragerAI(Creature * pCreature) : ScriptedAI(pCreature) {}
		
		uint32 fracture;
		
	  void Reset()
	  {
	    fracture = urand(1000, 3000);
	  }
	  
	  void UpdateAI(const uint32 diff)
	  {
	    if (!UpdateVictim())
        return;
		
		if (fracture<= diff)
        {
            DoCast(me->getVictim(), spell_fracture);
            fracture = urand(1000, 3000);
        } else fracture-= diff;
		
		DoMeleeAttackIfReady();
	}

};

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_unbound_earth_ragerAI(pCreature);
}
 
};



/************************
**Stonecore Rift Conjurer
*************************/

#define spell_demon_portal 80308 // Portail Démoniaque
#define spell_shadow_bolt 92637 // Trait de l'Ombre

class mob_stonecore_rift_conjurer : public CreatureScript
{
 public:
      mob_stonecore_rift_conjurer() : CreatureScript("mob_stonecore_rift_conjurer") {}
	  
	  struct mob_stonecore_rift_conjurerAI : public ScriptedAI
	  {
	    mob_stonecore_rift_conjurerAI(Creature * pCreature) : ScriptedAI(pCreature) {}
		
		uint32 demon_portal;
        uint32 shadow_bolt;
	
	  void Reset()
	  {
	    demon_portal = 15000;
		shadow_bolt = 2500;
	  }
	  
	  void UpdateAI(const uint32 diff)
	  {
	    if (!UpdateVictim())
        return;
		
		if (shadow_bolt<= diff)
        {
            DoCast(me->getVictim(), spell_shadow_bolt);
            shadow_bolt = 2500;
        } else shadow_bolt-= diff;
		
		if (demon_portal<= diff)
		{
		  DoCast(spell_demon_portal);
		  demon_portal = 15000;
		}else demon_portal-= diff;
		
	  }

};
		
CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_stonecore_rift_conjurerAI(pCreature);
}
 
};

/********************
**Stonecore Berserker
*********************/

#define spell_charge 81574 // Charge
#define spell_spinning_slash 92623 

class mob_stonecore_berserker : public CreatureScript
{
 public:
      mob_stonecore_berserker() : CreatureScript("mob_stonecore_berserker") {}
	  
	  struct mob_stonecore_berserkerAI : public ScriptedAI
	  {
	    mob_stonecore_berserkerAI(Creature * pCreature) : ScriptedAI(pCreature) {}
		
		uint32 charge;
        uint32 spinning_slash;
		
		void Reset()
		{
		  charge = urand(7000, 10000);
		  spinning_slash = 10000;
		}
		
		void UpdateAI (const uint32 diff)
	   {
	           if (!UpdateVictim())
			   return;
			   
			   if (charge<= diff)
			   {
			      if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, -5.0f, true))
                     DoCast(pTarget, spell_charge);
                     charge = urand(7000, 10000);
               } else charge-= diff;
			   
			   if (spinning_slash<= diff)
               {
                  DoCast(me->getVictim(), spell_spinning_slash);
                  spinning_slash = 10000;
               } else spinning_slash-= diff;
			   
			   DoMeleeAttackIfReady();
			   
	   }
	 
};

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_stonecore_berserkerAI(pCreature);
}
 
};

/******************
**Stonecore Bruiser
*******************/

#define spell_beat_down 80221
#define spell_body_slam 80180
#define spell_shockwave 92640

class mob_stonecore_bruiser : public CreatureScript
{
 public:
      mob_stonecore_bruiser() : CreatureScript("mob_stonecore_bruiser") {}
	  
	  struct mob_stonecore_bruiserAI : public ScriptedAI
	  {
	    mob_stonecore_bruiserAI(Creature * pCreature) : ScriptedAI(pCreature) {}
		
		uint32 beat_down;
        uint32 body_slam;
		uint32 shockwave;
		
		void Reset()
		{
		  beat_down = urand(5000, 8000);
		  body_slam = 15000;
		  shockwave = urand(20000, 25000);
		}
		
		void UpdateAI (const uint32 diff)
	   {
	           if (!UpdateVictim())
			   return;
			   
			   if (beat_down<= diff)
               {
                  DoCast(me->getVictim(), spell_beat_down);
                  beat_down = urand(5000, 8000);
               } else beat_down-= diff;
			   
			   if (body_slam<= diff)
			   {
			      if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, -5.0f, true))
                     DoCast(pTarget, body_slam);
                     body_slam = 15000;
               } else body_slam-= diff;
			   
			   if (shockwave<= diff)
			   {
			      DoCastVictim(spell_shockwave);
				  shockwave = urand(20000, 25000);
			   } else shockwave-= diff;
			   
			   DoMeleeAttackIfReady();
	   }
	 
};

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_stonecore_bruiserAI(pCreature);
}
 
};

/*****************
**Stonecore Flayer
******************/

#define spell_flay 79922

class mob_stonecore_flayer : public CreatureScript
{
 public:
      mob_stonecore_flayer() : CreatureScript("mob_stonecore_flayer") {}
	  
	  struct mob_stonecore_flayerAI : public ScriptedAI
	  {
	    mob_stonecore_flayerAI(Creature * pCreature) : ScriptedAI(pCreature) {}
		
		uint32 flay;
        
		void Reset()
		{
		    flay = urand(5000, 8000);
		}
		
		void UpdateAI (const uint32 diff)
	   {
	           if (!UpdateVictim())
			   return;
			   
			   if (flay<= diff)
			   {
			      DoCastVictim(spell_flay);
				  flay = urand(5000, 8000);
			   } else flay-= diff;
			   
			   DoMeleeAttackIfReady();
	   }
	 
};

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_stonecore_flayerAI(pCreature);
}
 
};

/*********************
**Stonecore Warbringer
**********************/

#define spell_cleave 15496
#define spell_rage 80158

class mob_stonecore_warbringer : public CreatureScript
{
 public:
      mob_stonecore_warbringer() : CreatureScript("mob_stonecore_warbringer") {}
	  
	  struct mob_stonecore_warbringerAI : public ScriptedAI
	  {
	    mob_stonecore_warbringerAI(Creature * pCreature) : ScriptedAI(pCreature) {}
		
		uint32 cleave;
		uint32 rage;
		
        void Reset()
		{
		    cleave = urand(5000, 8000);
			rage = 10000;
		}
		
		void UpdateAI (const uint32 diff)
	   {
	           if (!UpdateVictim())
			   return;
			   
			   if (cleave<= diff)
			   {
			      DoCast(me->getVictim(), spell_cleave);
                  cleave = urand(5000, 8000);
               } else cleave-= diff;
			   
			   if (rage<= diff)
			   {
			     DoCast(me , spell_rage);
				 rage = 10000;
			   } else rage-= diff;
			   
			   DoMeleeAttackIfReady();
	   }
	   
};

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_stonecore_warbringerAI(pCreature);
}
 
};

/**********************
**Stonecore Earthshaper
***********************/

#define spell_dust_storm 92624
#define spell_force_of_earth 81459
#define spell_ground_shock 92628
#define spell_lava_burst 92626

class mob_stonecore_earthshaper : public CreatureScript
{
 public:
      mob_stonecore_earthshaper() : CreatureScript("mob_stonecore_earthshaper") {}
	  
	  struct mob_stonecore_earthshaperAI : public ScriptedAI
	  {
	    mob_stonecore_earthshaperAI(Creature * pCreature) : ScriptedAI(pCreature) {}
		
		uint32 dust_storm;
		uint32 force_of_earth;
		uint32 ground_shock;
		uint32 lava_burst;
		
        void Reset()
		{
		    dust_storm = urand(5000, 8000);
			force_of_earth = 30000;
			ground_shock = urand(15000, 25000);
			lava_burst = urand(8000, 9000);
		}
		
		void UpdateAI (const uint32 diff)
	   {
	           if (!UpdateVictim())
			   return;
			   
               if (dust_storm<= diff)
				{
				    DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_dust_storm);
					dust_storm = urand(5000, 8000);
				} else dust_storm -= diff;
				
			   if (force_of_earth<= diff)
			   {
			     DoCast(spell_force_of_earth);
				 force_of_earth = 30000;
			   } else force_of_earth-= diff;
			   
			   if (ground_shock<= diff)
			   {
			      DoCastVictim(spell_ground_shock);
				  ground_shock = urand(15000, 25000);
			   } else ground_shock-= diff;
			      
			   if (lava_burst<= diff)
			   {
			      DoCast(me->getVictim(), spell_lava_burst);
                  lava_burst = urand(8000, 9000);
               } else lava_burst -= diff;
			   
		    DoMeleeAttackIfReady();
		}
		
};

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_stonecore_earthshaperAI(pCreature);
}
 
};

/********************
**Stonecore Magmalord
*********************/

#define spell_ignite 92636
#define spell_magma_eruption 80038

class mob_stonecore_magmalord : public CreatureScript
{
 public:
      mob_stonecore_magmalord() : CreatureScript("mob_stonecore_magmalord") {}
	  
	  struct mob_stonecore_magmalordAI : public ScriptedAI
	  {
	    mob_stonecore_magmalordAI(Creature * pCreature) : ScriptedAI(pCreature) {}
		
		uint32 ignite;
		uint32 magma_eruption;
	
		void Reset()
		{
		    ignite = urand(5000, 8000);
			magma_eruption = urand (10000, 12000);
		}
		
		void UpdateAI (const uint32 diff)
	   {
	           if (!UpdateVictim())
			   return;
			   
			   if (ignite<= diff)
			   {
			      DoCast(me->getVictim(), spell_ignite);
                  ignite = urand(5000, 8000);
               } else ignite-= diff;
			   
			    if (magma_eruption<= diff)
				{
				   DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), spell_magma_eruption);
				   magma_eruption = urand (10000, 12000);
				} else magma_eruption -= diff;
				
			DoMeleeAttackIfReady();
		}
		
};

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_stonecore_magmalordAI(pCreature);
}
 
};

void AddSC_mob_trash_coeur_de_pierre()
{
    new mob_unbound_earth_rager();
	new mob_stonecore_rift_conjurer();
	new mob_stonecore_berserker();
	new mob_stonecore_bruiser();
	new mob_stonecore_flayer();
	new mob_stonecore_warbringer();
	new mob_stonecore_earthshaper();
	new mob_stonecore_magmalord();
}