/*
 * Copyright (C) 2010- 2013 Project TBEmu <http://www.trueblood-servers.com/>
 * by JeanClaude
 */

#include "ScriptPCH.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
 
/******************
**Wailing Guardsman
*******************/

#define SPELL_SCREAMS_OF_THE_PAST   7074
#define SPELL_MORTAL_STRIKE         91801

class mob_wailing_guardsman : public CreatureScript
{
public:
    mob_wailing_guardsman() : CreatureScript("mob_wailing_guardsman") {}
 
       struct mob_wailing_guardsmanAI : public ScriptedAI
       {
           mob_wailing_guardsmanAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 ScreamsOfThePast_Timer;
	   uint32 MortalStrike_Timer;
	   
	   void Reset()
           {
               ScreamsOfThePast_Timer = 8000;
	       MortalStrike_Timer = 2000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	       
	       if(ScreamsOfThePast_Timer <= diff)
	       {
	            DoCast(SPELL_SCREAMS_OF_THE_PAST);
		    ScreamsOfThePast_Timer = 12000;
	       }else ScreamsOfThePast_Timer -= diff;
	       
	       if(MortalStrike_Timer<= diff)
               {
                  if (IsHeroic())
                  {
		     DoCast(me->getVictim(), SPELL_MORTAL_STRIKE);
                     MortalStrike_Timer = urand(9000, 12000);
		  }
               }else MortalStrike_Timer -= diff;
	       
	       		
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_wailing_guardsmanAI(pCreature);
}
};

/*****************
**Unstable Ravager
******************/

#define SPELL_RAVAGE               3242
#define SPELL_UNSTABLE_STRENGTH    91668

class mob_unstable_ravager : public CreatureScript
{
public:
    mob_unstable_ravager() : CreatureScript("mob_unstable_ravager") {}
 
       struct mob_unstable_ravagerAI : public ScriptedAI
       {
           mob_unstable_ravagerAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 Ravage_Timer;
	   uint32 UnstableStrength_Timer;
	   
	   void Reset()
           {
               Ravage_Timer = 5000;
	       UnstableStrength_Timer = 12000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	       
	       if(Ravage_Timer<= diff)
               {
                     DoCast(me->getVictim(), SPELL_RAVAGE);
                     Ravage_Timer = 10000;
	       }else Ravage_Timer -= diff;
	       
	       if(UnstableStrength_Timer <= diff)
	       {
	          if (IsHeroic())
                  {
		     DoCast(me, SPELL_UNSTABLE_STRENGTH);
		     UnstableStrength_Timer = 15000;
		  }
	       }else UnstableStrength_Timer -= diff;
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_unstable_ravagerAI(pCreature);
}
};

/******************
**Tormented Officer
*******************/

#define SPELL_FORSAKEN_ABILITY            7054
#define SPELL_FORSAKEN_ABILITY_HEALING    91442
#define SPELL_FORSAKEN_ABILITY_HEALTH     91444
#define SPELL_SHIELD_WALL                 91463

class mob_tormented_officer : public CreatureScript
{
public:
    mob_tormented_officer() : CreatureScript("mob_tormented_officer") {}
 
       struct mob_tormented_officerAI : public ScriptedAI
       {
           mob_tormented_officerAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 ForsakenAbility_Timer;
	   uint32 ForsakenAbilityDebuff_Timer;
	   
	   
	   bool Shield;
	   
	   void Reset()
           {
               ForsakenAbility_Timer = 3000;
	       ForsakenAbilityDebuff_Timer = 7000;
	       
	       Shield = false;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (ForsakenAbility_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                     DoCast(pTarget, SPELL_FORSAKEN_ABILITY);
                     ForsakenAbility_Timer = 20000;
               }else ForsakenAbility_Timer -= diff;	       
	       
	       if(ForsakenAbilityDebuff_Timer<= diff)
               {
                  if (IsHeroic())
                  {
                     DoCast(me->getVictim(), RAND(SPELL_FORSAKEN_ABILITY_HEALING, SPELL_FORSAKEN_ABILITY_HEALTH));
                     ForsakenAbilityDebuff_Timer = 10000;
		  }
	       }else ForsakenAbilityDebuff_Timer -= diff;
	       
	       if (!Shield && !HealthAbovePct(30))
	       {
	          if (IsHeroic())
                  {
		     DoCast(me, SPELL_SHIELD_WALL);
		     Shield = true;
		  }
		  
	        }
		  
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_tormented_officerAI(pCreature);
}
};

/**************
**Stone Sleeper
***************/

#define SPELL_FEAR      30615
#define SPELL_FEAR_H    38595

class mob_stone_sleeper : public CreatureScript
{
public:
    mob_stone_sleeper() : CreatureScript("mob_stone_sleeper") {}
 
       struct mob_stone_sleeperAI : public ScriptedAI
       {
           mob_stone_sleeperAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 Fear_Timer;
	   
	   void Reset()
           {
               Fear_Timer = 6000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (Fear_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_FEAR_H : SPELL_FEAR);
                     Fear_Timer = 10000;
               }else Fear_Timer -= diff;
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_stone_sleeperAI(pCreature);
}
};

/*******************
**Spitebone Skeleton
********************/

#define SPELL_BONE_FLURRY           91419
#define SPELL_BONE_FLURRY_H         91425
#define SPELL_PENETRATING_STRIKE    91426

class mob_spitebone_skeleton : public CreatureScript
{
public:
    mob_spitebone_skeleton() : CreatureScript("mob_spitebone_skeleton") {}
 
       struct mob_spitebone_skeletonAI : public ScriptedAI
       {
           mob_spitebone_skeletonAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 BoneFlurry_Timer;
	   uint32 PenetratingStrike_Timer;
	   
	   void Reset()
           {
               BoneFlurry_Timer = 9000;
	       PenetratingStrike_Timer = 6000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	       
	       if (BoneFlurry_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_BONE_FLURRY_H : SPELL_BONE_FLURRY);
                     BoneFlurry_Timer = 10000;
               }else BoneFlurry_Timer -= diff;
	       
	       if(PenetratingStrike_Timer<= diff)
               {
                  if (IsHeroic())
                  {
                     DoCast(me->getVictim(), SPELL_PENETRATING_STRIKE);
                     PenetratingStrike_Timer = 5000;
		  }
	       }else PenetratingStrike_Timer -= diff;
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_spitebone_skeletonAI(pCreature);
}
};

/*******************
**Spitebone Guardian
********************/

#define SPELL_SHIELD_BASH       11972
#define SPELL_STRIKE            87081
#define SPELL_SHIELD_OF_BONES   91629

class mob_spitebone_guardian : public CreatureScript
{
public:
    mob_spitebone_guardian() : CreatureScript("mob_spitebone_guardian") {}
 
       struct mob_spitebone_guardianAI : public ScriptedAI
       {
           mob_spitebone_guardianAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 ShieldBash_Timer;
	   uint32 Strike_Timer;

           bool Bones;

           void Reset()
           {
               ShieldBash_Timer = 9000;
	       Strike_Timer = 6000;
	   
	       Bones = false;
	   }

           void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	       
	       if(ShieldBash_Timer<= diff)
               {
                     DoCast(me->getVictim(), SPELL_SHIELD_BASH);
                     ShieldBash_Timer = 10000;
	       }else ShieldBash_Timer -= diff;
	       
	       if(Strike_Timer<= diff)
               {
                     DoCast(me->getVictim(), SPELL_STRIKE);
                     Strike_Timer = 5000;
	       }else Strike_Timer -= diff;
	       
	       if (!Bones && !HealthAbovePct(30))
	       {
	          if (IsHeroic())
                  {
                     DoCast(me, SPELL_SHIELD_OF_BONES);
		     Bones = true;
		  }
		  
	        }
		  
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_spitebone_guardianAI(pCreature);
}
};

/*****************
**Spitebone Flayer
******************/

#define SPELL_FLAY     32731

class mob_spitebone_flayer : public CreatureScript
{
public:
    mob_spitebone_flayer() : CreatureScript("mob_spitebone_flayer") {}
 
       struct mob_spitebone_flayerAI : public ScriptedAI
       {
           mob_spitebone_flayerAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 Flay_Timer;
	   
	   void Reset()
           {
               Flay_Timer = 6000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	       
	       if(Flay_Timer <= diff)
	       {
	           DoCast(me, SPELL_FLAY);
		   Flay_Timer = 6000;
               }else Flay_Timer -= diff;
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_spitebone_flayerAI(pCreature);
}
};	       
             	       
/*******************
**Sorcerous Skeleton
********************/

#define SPELL_FIRE_BLAST    13341
#define SPELL_FROSTBOLT     15497
#define SPELL_FROSTBOLT_H   76067
#define SPELL_LIVING_BOMB   91563

class mob_sorcerous_skeleton : public CreatureScript
{
public:
    mob_sorcerous_skeleton() : CreatureScript("mob_sorcerous_skeleton") {}
 
       struct mob_sorcerous_skeletonAI : public ScriptedAI
       {
           mob_sorcerous_skeletonAI(Creature *c): ScriptedAI(c) {}
	   
           uint32 FireBlast_Timer;
           uint32 FrostBolt_Timer;
           uint32 LivingBomb_Timer;

           void Reset()
           {
             FrostBolt_Timer = 1000;
	     FireBlast_Timer = 4500;
	     LivingBomb_Timer = 9000;
	   }

           void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(FrostBolt_Timer<= diff)
               {
                     DoCast(me->getVictim(), IsHeroic() ? SPELL_FROSTBOLT_H : SPELL_FROSTBOLT);
                     FrostBolt_Timer = 4200;
	       }else FrostBolt_Timer -= diff;

               if(FireBlast_Timer<= diff)
               {
                     DoCast(me->getVictim(), SPELL_FIRE_BLAST);
                     FireBlast_Timer = 7000;
	       }else FireBlast_Timer -= diff;

               if (LivingBomb_Timer<= diff)
               {
                  if (IsHeroic())
                  {    
		     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, SPELL_LIVING_BOMB);
                     LivingBomb_Timer = 21000;
		  }
               }else LivingBomb_Timer -= diff;

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_sorcerous_skeletonAI(pCreature);
}
};

/******************
**Shadowy Attendant
*******************/

#define SPELL_SHADOW_BOLT      12739
#define SPELL_SHADOW_VORTEX    91325
#define SPELL_SHADOWY_TOUCH    91324

class mob_shadowy_attendant : public CreatureScript
{
public:
    mob_shadowy_attendant() : CreatureScript("mob_shadowy_attendant") {}
 
       struct mob_shadowy_attendantAI : public ScriptedAI
       {
           mob_shadowy_attendantAI(Creature *c): ScriptedAI(c) {}
	   
           uint32 ShadowBolt_Timer;
           uint32 ShadowVortex_Timer;
           uint32 ShadowyTouch_Timer;

           void Reset()
           {
             ShadowBolt_Timer = 1000;
	     ShadowVortex_Timer = 5000;
	     ShadowyTouch_Timer = 9000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(ShadowBolt_Timer<= diff)
               {
                  if (!IsHeroic())
                  {   
		     DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                     ShadowBolt_Timer = 4200;
		  }
	       }else ShadowBolt_Timer -= diff;
	       
	       if (ShadowVortex_Timer<= diff)
               {
                  if (IsHeroic())
                  {    
		     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, SPELL_SHADOW_VORTEX);
                     ShadowVortex_Timer = 10000;
		  }
               }else ShadowVortex_Timer -= diff;
	       
	       if (ShadowyTouch_Timer<= diff)
               {
                  if (IsHeroic())
                  {    
		    DoCast(me->getVictim(), SPELL_SHADOWY_TOUCH);
                    ShadowyTouch_Timer = urand(8000, 15000);
		  }
	       }else ShadowyTouch_Timer -= diff;
	      
             DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_shadowy_attendantAI(pCreature);
}
};
	       
/**********************
**Pustulant Monstrosity
***********************/

#define SPELL_PUSTULANT_SPIT     91677
#define SPELL_PUSTULANT_SPIT_H   91678

class mob_pustulant_monstrosity : public CreatureScript
{
public:
    mob_pustulant_monstrosity() : CreatureScript("mob_pustulant_monstrosity") {}
 
       struct mob_pustulant_monstrosityAI : public ScriptedAI
       {
           mob_pustulant_monstrosityAI(Creature *c): ScriptedAI(c) {}

           uint32 PustulantSpit_Timer;

	   void Reset()
           {
             PustulantSpit_Timer = 4000;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if (PustulantSpit_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_PUSTULANT_SPIT_H : SPELL_PUSTULANT_SPIT);
                     PustulantSpit_Timer = 8000;
               }else PustulantSpit_Timer -= diff;

             DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_pustulant_monstrosityAI(pCreature);
}
};

/****************
**Mindless Horror
*****************/

#define SPELL_COWERING_ROAR   91220
#define SPELL_SMASH           91213
#define SPELL_SMASH_H         91217

class mob_mindless_horror : public CreatureScript
{
public:
    mob_mindless_horror() : CreatureScript("mob_mindless_horror") {}
 
       struct mob_mindless_horrorAI : public ScriptedAI
       {
           mob_mindless_horrorAI(Creature *c): ScriptedAI(c) {}

           uint32 CoweringRoar_Timer;
           uint32 Smash_Timer;

	   void Reset()
           {
             CoweringRoar_Timer = 10000;
	     Smash_Timer = 7000;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (CoweringRoar_Timer<= diff)
               {
                  if (IsHeroic())
                  {           
	             DoCast(SPELL_COWERING_ROAR);
		     CoweringRoar_Timer = 20000;
		  }
	       }else CoweringRoar_Timer -= diff;
	       
	       if (Smash_Timer <= diff)
               {
                     DoCast(IsHeroic() ? SPELL_SMASH_H : SPELL_SMASH);	       
		     Smash_Timer = urand(8000, 10000);
	       }else Smash_Timer -= diff;
	       
             DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_mindless_horrorAI(pCreature);
}
};

/****************
**Lesser Gargoyle
*****************/

#define SPELL_GARGOYLE_STRIKE   91611

class mob_lesser_gargoyle : public CreatureScript
{
public:
    mob_lesser_gargoyle() : CreatureScript("mob_lesser_gargoyle") {}
 
       struct mob_lesser_gargoyleAI : public ScriptedAI
       {
           mob_lesser_gargoyleAI(Creature *c): ScriptedAI(c) {}

           uint32 GargoyleStrike_Timer;

	   void Reset()
           {
             GargoyleStrike_Timer = 5000;
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(GargoyleStrike_Timer<= diff)
               {
                     DoCast(me->getVictim(), SPELL_GARGOYLE_STRIKE);
                     GargoyleStrike_Timer = 7000;
	       }else GargoyleStrike_Timer -= diff;
	       
             DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_lesser_gargoyleAI(pCreature);
}
};

/*****************
**Haunted Servitor
******************/

#define SPELL_HAUNTING_SPIRITS      7057
#define SPELL_HAUNTING_SPIRITS_H    91293
#define SPELL_DRAIN_LIFE            91291

class mob_haunted_servitor : public CreatureScript
{
public:
    mob_haunted_servitor() : CreatureScript("mob_haunted_servitor") {}
 
       struct mob_haunted_servitorAI : public ScriptedAI
       {
           mob_haunted_servitorAI(Creature *c): ScriptedAI(c) {}

           uint32 HauntingSpirits_Timer;

           bool Drain;

	   void Reset()
           {
             HauntingSpirits_Timer = 5000;
	     
	     Drain = false;
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if (HauntingSpirits_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_HAUNTING_SPIRITS_H : SPELL_HAUNTING_SPIRITS);
                     HauntingSpirits_Timer = urand(15000, 20000);
               }else HauntingSpirits_Timer -= diff;

               if (!Drain && !HealthAbovePct(50))
	       {
		  if (IsHeroic())
                  {
                     DoCast(me->getVictim(), SPELL_DRAIN_LIFE);
                     Drain = true;
		  }
	       }

             DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_haunted_servitorAI(pCreature);
}
};

/*************
**Ghostly Cook
**************/

#define SPELL_CLEAVE       15496
#define SPELL_TENDERIZE	   91348

class mob_ghostly_cook : public CreatureScript
{
public:
    mob_ghostly_cook() : CreatureScript("mob_ghostly_cook") {}
 
       struct mob_ghostly_cookAI : public ScriptedAI
       {
           mob_ghostly_cookAI(Creature *c): ScriptedAI(c) {}

           uint32 Cleave_Timer;
           uint32 Tenderize_Timer;

	   void Reset()
           {
             Cleave_Timer = 8000;
	     Tenderize_Timer = 5000;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(Cleave_Timer<= diff)
               {
                     DoCast(me->getVictim(), SPELL_CLEAVE);
                     Cleave_Timer = urand(8000, 10000);
	       }else Cleave_Timer -= diff;

	       if(Tenderize_Timer<= diff)
               {
 		  if (IsHeroic())
                  {                    
		     DoCast(me->getVictim(), SPELL_TENDERIZE);
                     Tenderize_Timer = 6000;
		  }
	       }else Tenderize_Timer -= diff;
	       
             DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_ghostly_cookAI(pCreature);
}
};

/**************
**Frantic Geist
***************/

#define SPELL_FRANTIC_LEAP       91077
#define SPELL_SLASHING_CLAWS     91064
#define SPELL_SLASHING_CLAWS_H   91074

class mob_frantic_geist : public CreatureScript
{
public:
    mob_frantic_geist() : CreatureScript("mob_frantic_geist") {}
 
       struct mob_frantic_geistAI : public ScriptedAI
       {
           mob_frantic_geistAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 SlashingClaws_Timer;
	   
	   void EnterCombat(Unit* pWho)
           {
              if (IsHeroic())
              {                    
		  DoCast(me->getVictim(), SPELL_FRANTIC_LEAP);
              }
           }

	   void Reset()
           {
              SlashingClaws_Timer = 2000;
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(SlashingClaws_Timer<= diff)
               {
                     DoCast(me->getVictim(), IsHeroic() ? SPELL_SLASHING_CLAWS_H : SPELL_SLASHING_CLAWS);
                     SlashingClaws_Timer = 4200;
	       }else SlashingClaws_Timer -= diff;

             DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_frantic_geistAI(pCreature);
}
};

/************
**Fetid Ghoul
*************/

#define SPELL_DISEASE_CLOUD     91561
#define SPELL_FETID_CLOUD       91554

class mob_fetid_ghoul : public CreatureScript
{
public:
    mob_fetid_ghoul() : CreatureScript("mob_fetid_ghoul") {}
 
       struct mob_fetid_ghoulAI : public ScriptedAI
       {
           mob_fetid_ghoulAI(Creature *c): ScriptedAI(c) {}
	   
	   void JustDied(Unit* /*Killer*/)
           {
              if (IsHeroic())
              {                    
                   DoCast(SPELL_FETID_CLOUD);
              }
           }

           void Reset()
           {
              DoCast(me, SPELL_DISEASE_CLOUD);
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

             DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_fetid_ghoulAI(pCreature);
}
};

/*************
**Dread Scryer
**************/

#define SPELL_ARCANE_BARRAGE        91622
#define SPELL_ARCANE_EXPLOSION      91623
#define SPELL_ARCANE_MISSILES       33833
#define SPELL_CONE_OF_COLD          12611
#define SPELL_ENHANCE_MAGIC         91624

class mob_dread_scryer : public CreatureScript
{
public:
    mob_dread_scryer() : CreatureScript("mob_dread_scryer") {}
 
       struct mob_dread_scryerAI : public ScriptedAI
       {
           mob_dread_scryerAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 ArcaneBarrage_Timer;
	   uint32 ArcaneExplosion_Timer;
	   uint32 ArcaneMissiles_Timer;
	   uint32 ConeOfCold_Timer;
	   
	   bool Enhance;
	   
	   void Reset()
           {
              ArcaneBarrage_Timer = 1000;
	      ArcaneExplosion_Timer = 8000;
	      ArcaneMissiles_Timer = 1000;
	      ConeOfCold_Timer = 7000;
	      
	      Enhance = false;
           }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(ArcaneBarrage_Timer <= diff)
               {
                  if (IsHeroic())
                  {                    
		     DoCast(me->getVictim(), SPELL_ARCANE_BARRAGE);
                     ArcaneBarrage_Timer = 5000;
                  }
               }else ArcaneBarrage_Timer -= diff;               

               if(ArcaneExplosion_Timer <= diff)
               {
                  if (IsHeroic())
                  {
                     DoCast(SPELL_ARCANE_EXPLOSION);
                     ArcaneExplosion_Timer = 12000;
                  }
               }else ArcaneExplosion_Timer -= diff;

               if(ArcaneMissiles_Timer <= diff)
               {
                  if (!IsHeroic())
                  {                    
		     DoCast(me->getVictim(), SPELL_ARCANE_MISSILES);
                     ArcaneMissiles_Timer = 5000;
                  }
               }else ArcaneMissiles_Timer -= diff;

               if(ConeOfCold_Timer <= diff)
               {
                  if (!IsHeroic())
                  {
                     DoCast(me->getVictim(), SPELL_CONE_OF_COLD);
                     ConeOfCold_Timer = 12000;
                  }
               }else ConeOfCold_Timer -= diff;

		if (!Enhance && !HealthAbovePct(40))
		{
		  if (IsHeroic())
                  {
		     DoCast(me, SPELL_ENHANCE_MAGIC);
		     Enhance = true;
		  }
		}
		
	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_dread_scryerAI(pCreature);
}
};

/*************
**Dark Creeper
**************/

#define SPELL_DARK_TOUCH   91522


class mob_dark_creeper : public CreatureScript
{
public:
    mob_dark_creeper() : CreatureScript("mob_dark_creeper") {}
 
       struct mob_dark_creeperAI : public ScriptedAI
       {
           mob_dark_creeperAI(Creature *c): ScriptedAI(c) {}

           uint32 DarkTouch_Timer;

	   void Reset()
           {
              DarkTouch_Timer = 2000;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(DarkTouch_Timer <= diff)
               {
                  DoCast(me->getVictim(), SPELL_DARK_TOUCH);
                  DarkTouch_Timer = 3000;
               }else DarkTouch_Timer -= diff;

	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_dark_creeperAI(pCreature);
}
};

/*************
**Corpse Eater
**************/

#define SPELL_CONSUME_FLESH       91088
#define SPELL_CONSUME_FLESH_H	  91093
#define SPELL_ROTTING_BILE        91099

class mob_corpse_eater : public CreatureScript
{
public:
    mob_corpse_eater() : CreatureScript("mob_corpse_eater") {}
 
       struct mob_corpse_eaterAI : public ScriptedAI
       {
           mob_corpse_eaterAI(Creature *c): ScriptedAI(c) {}

           uint32 ConsumeFlesh_Timer;
           uint32 RottingBile_Timer;

	   void Reset()
           {
              ConsumeFlesh_Timer = 7000;
	      RottingBile_Timer = 3000;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;	   
           
               if(ConsumeFlesh_Timer <= diff)
               {
                  DoCast(me->getVictim(), IsHeroic() ? SPELL_CONSUME_FLESH_H : SPELL_CONSUME_FLESH);
                  ConsumeFlesh_Timer = 12000;
               }else ConsumeFlesh_Timer -= diff;

               if(RottingBile_Timer <= diff)
               {
                  if (IsHeroic())
                  {                    
		     DoCast(me->getVictim(), SPELL_ROTTING_BILE);
                     RottingBile_Timer = 8000;
                  }
               }else RottingBile_Timer -= diff;

	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_corpse_eaterAI(pCreature);
}
};

void AddSC_trash_shadowfang_keep()
{	       
    new mob_wailing_guardsman();
    new mob_unstable_ravager();
    new mob_tormented_officer();    
    new mob_stone_sleeper();	       
    new mob_spitebone_skeleton();	   
    new mob_spitebone_guardian();
    new mob_spitebone_flayer();
    new mob_sorcerous_skeleton();
    new mob_shadowy_attendant();
    new mob_pustulant_monstrosity();	       
    new mob_mindless_horror();
    new mob_lesser_gargoyle();    
    new mob_haunted_servitor();	   
    new mob_ghostly_cook();
    new mob_frantic_geist();
    new mob_fetid_ghoul();
    new mob_dread_scryer();
    new mob_dark_creeper();
    new mob_corpse_eater();
}