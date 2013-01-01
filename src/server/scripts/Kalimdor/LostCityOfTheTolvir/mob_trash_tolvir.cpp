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
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

/********************
**Bonesnapper Scorpid
*********************/

#define SPELL_PARALYTIC_VENOM        84125
#define SPELL_PARALYTIC_VENOM_H      90022

class mob_bonesnapper_scorpid : public CreatureScript
{
public:
    mob_bonesnapper_scorpid() : CreatureScript("mob_bonesnapper_scorpid") {}
 
       struct mob_bonesnapper_scorpidAI : public ScriptedAI
       {
           mob_bonesnapper_scorpidAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 ParalyticVenom_Timer;
	   
	   void Reset()
           {
               ParalyticVenom_Timer = 2000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if(ParalyticVenom_Timer<= diff)
               {
		     DoCast(me->getVictim(), IsHeroic() ? SPELL_PARALYTIC_VENOM_H : SPELL_PARALYTIC_VENOM);
                     ParalyticVenom_Timer = 6000;		  
               }else ParalyticVenom_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_bonesnapper_scorpidAI(pCreature);
}
};

/********************
**Neferset Darkcaster
*********************/

#define SPELL_HEX             82760
#define SPELL_METEOR          84032
#define SPELL_METEOR_H        90023
#define SPELL_SHADOWBOLT      82765
#define SPELL_SHADOWBOLT_H    90036

class mob_neferset_darkcaster : public CreatureScript
{
public:
    mob_neferset_darkcaster() : CreatureScript("mob_neferset_darkcaster") {}
 
       struct mob_neferset_darkcasterAI : public ScriptedAI
       {
           mob_neferset_darkcasterAI(Creature *c): ScriptedAI(c) {}

           uint32 Hex_Timer;
           uint32 Meteor_Timer;
           uint32 ShadowBolt_Timer;

	   void Reset()
           {
               Hex_Timer = 6000;
	       Meteor_Timer = 15000;
	       ShadowBolt_Timer = 1000;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (Hex_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                     DoCast(pTarget, SPELL_HEX);
                     Hex_Timer = 12000;
               }else Hex_Timer -= diff;

               if (Meteor_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_METEOR_H : SPELL_METEOR);
                     Meteor_Timer = 20000;
               }else Meteor_Timer -= diff;
	       
	       if(ShadowBolt_Timer<= diff)
               {
                     DoCast(me->getVictim(), IsHeroic() ? SPELL_SHADOWBOLT_H : SPELL_SHADOWBOLT);
                     ShadowBolt_Timer = 3000;
	       }else ShadowBolt_Timer -= diff;
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_neferset_darkcasterAI(pCreature);
}
};

/***********************
**Neferset Plaguebringer
************************/

#define SPELL_DISEASE_BREATH           73976
#define SPELL_DISEASE_BREATH_H         90005
#define SPELL_INFECTIOUS_PLAGUE        82768

class mob_neferset_plaguebringer : public CreatureScript
{
public:
    mob_neferset_plaguebringer() : CreatureScript("mob_neferset_plaguebringer") {}
 
       struct mob_neferset_plaguebringerAI : public ScriptedAI
       {
           mob_neferset_plaguebringerAI(Creature *c): ScriptedAI(c) {}	

           uint32 InfectiousPlague_Timer;
           uint32 DiseaseBreath_Timer;

	   void Reset()
           {
               InfectiousPlague_Timer = 3000;
	       DiseaseBreath_Timer = 7000;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (InfectiousPlague_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, SPELL_INFECTIOUS_PLAGUE);
                     InfectiousPlague_Timer = 12000;
               }else InfectiousPlague_Timer -= diff;

               if (DiseaseBreath_Timer <= diff)
               {
                    DoCastVictim(IsHeroic() ? SPELL_DISEASE_BREATH_H : SPELL_DISEASE_BREATH);
                    DiseaseBreath_Timer = 25000;
               }else DiseaseBreath_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_neferset_plaguebringerAI(pCreature);
}
};

/*******************
**Neferset Theurgist
********************/

#define SPELL_MIXTURE_OF_HARNESSED_RAGE      82759
#define SPELL_RITUAL_OF_BLOODLETTING         82753
#define SPELL_RITUAL_OF_BLOODLETTING_H       89993
#define SPELL_SUMMON_VICIOUS_LEECHES         82757

class mob_neferset_theurgist : public CreatureScript
{
public:
    mob_neferset_theurgist() : CreatureScript("mob_neferset_theurgist") {}
 
       struct mob_neferset_theurgistAI : public ScriptedAI
       {
           mob_neferset_theurgistAI(Creature *c): ScriptedAI(c) {} 

           uint32 RitualOfBloodletting_Timer;
           uint32 SummonViciousLeeches_Timer;
           
	   bool Mixture;

	   void Reset()
           {
               RitualOfBloodletting_Timer = 8000;
	       SummonViciousLeeches_Timer = 3000;
	       
	       Mixture = false;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (RitualOfBloodletting_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_RITUAL_OF_BLOODLETTING_H : SPELL_RITUAL_OF_BLOODLETTING);
                     RitualOfBloodletting_Timer = 20000;
               }else RitualOfBloodletting_Timer -= diff;

	       if (SummonViciousLeeches_Timer <= diff)
	       {
	            DoCast(SPELL_SUMMON_VICIOUS_LEECHES);
		    SummonViciousLeeches_Timer = 30000;
	       }
	       
	       if (!Mixture && !HealthAbovePct(30))
	       {
	           DoCast(me, SPELL_MIXTURE_OF_HARNESSED_RAGE);
		   Mixture = true;
	       }
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_neferset_theurgistAI(pCreature);
}
};

/******************
**Neferset Torturer
*******************/

#define SPELL_BRANDED_TONGUE         82744
#define SPELL_BRANDED_TONGUE_H       90037
#define SPELL_SERUM_OF_TORMENT       82750
#define SPELL_SERUM_OF_TORMENT_H     89994

class mob_neferset_torturer : public CreatureScript
{
public:
    mob_neferset_torturer() : CreatureScript("mob_neferset_torturer") {}
 
       struct mob_neferset_torturerAI : public ScriptedAI
       {
           mob_neferset_torturerAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 BrandedTongue_Timer;
	   uint32 SerumOfTorment_Timer;
	   
	   void Reset()
           {
               BrandedTongue_Timer = 2000;
	       SerumOfTorment_Timer = 7000;
           }
	   
           void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	       
	       if (BrandedTongue_Timer <= diff)
               {
                     if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -5.0f, true))
	             DoCast(target, IsHeroic() ? SPELL_BRANDED_TONGUE_H : SPELL_BRANDED_TONGUE);
	             BrandedTongue_Timer = 12000;
               }else BrandedTongue_Timer -= diff;
	       
               if (SerumOfTorment_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_SERUM_OF_TORMENT_H : SPELL_SERUM_OF_TORMENT);
                     SerumOfTorment_Timer = 15000;
               }else SerumOfTorment_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_neferset_torturerAI(pCreature);
}
};

/********************
**Oathsworn Axemaster
*********************/

#define SPELL_SKULL_CRUSH      84256
#define SPELL_SLAM             82763

class mob_oathsworn_axemaster : public CreatureScript
{
public:
    mob_oathsworn_axemaster() : CreatureScript("mob_oathsworn_axemaster") {}
 
       struct mob_oathsworn_axemasterAI : public ScriptedAI
       {
           mob_oathsworn_axemasterAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 SkullCrush_Timer;
	   uint32 Slam_Timer;
	   
	   void Reset()
           {
               SkullCrush_Timer = 4000;
	       Slam_Timer = 9000;
           }
	   
           void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(SkullCrush_Timer<= diff)
               {
                    DoCast(me->getVictim(), SPELL_SKULL_CRUSH);
                    SkullCrush_Timer = 6000;
               }else SkullCrush_Timer -= diff;	       
	   
               if(Slam_Timer<= diff)
               {
                    DoCast(me->getVictim(), SPELL_SKULL_CRUSH);
                    Slam_Timer = 10000;
               }else Slam_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_oathsworn_axemasterAI(pCreature);
}
};

/******************
**Oathsworn Captain
*******************/

#define SPELL_SKULL_CRACK     82670

class mob_oathsworn_captain : public CreatureScript
{
public:
    mob_oathsworn_captain() : CreatureScript("mob_oathsworn_captain") {}
 
       struct mob_oathsworn_captainAI : public ScriptedAI
       {
           mob_oathsworn_captainAI(Creature *c): ScriptedAI(c) {}

           uint32 SkullCrack_Timer;

	   void Reset()
           {
               SkullCrack_Timer = 5000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(SkullCrack_Timer<= diff)
               {
                    DoCast(me->getVictim(), SPELL_SKULL_CRACK);
                    SkullCrack_Timer = 10000;
               }else SkullCrack_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_oathsworn_captainAI(pCreature);
}
};

/*******************
**Oathsworn Myrmidon
********************/

#define SPELL_BLADE_SHIELD_SPIKE         82671
#define SPELL_BLADE_SHIELD_SPIKE_H       95184
#define SPELL_RESISTANCE                 82673

class mob_oathsworn_myrmidon : public CreatureScript
{
public:
    mob_oathsworn_myrmidon() : CreatureScript("mob_oathsworn_myrmidon") {}
 
       struct mob_oathsworn_myrmidonAI : public ScriptedAI
       {
           mob_oathsworn_myrmidonAI(Creature *c): ScriptedAI(c) {}

           uint32 Resistance_Timer;
           
           bool Spike;

           void Reset()
           {
               Resistance_Timer = 10000;
	       
	       Spike = false;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(Resistance_Timer <= diff)
               {
                   DoCast(me, SPELL_RESISTANCE);
		   Resistance_Timer = 25000;
	       }else Resistance_Timer -= diff;
	       
	       if (!Spike && !HealthAbovePct(50))
	       {
	           DoCast(me, IsHeroic() ? SPELL_BLADE_SHIELD_SPIKE_H : SPELL_BLADE_SHIELD_SPIKE);
		   Spike = true;
	       }
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_oathsworn_myrmidonAI(pCreature);
}
};

/*********************
**Oathsworm Pathfinder
**********************/

#define SPELL_SHOOT           83877
#define SPELL_CALL_FALCON     82792
#define SPELL_WING_CLIP       82764

class mob_oathsworn_pathfinder : public CreatureScript
{
public:
    mob_oathsworn_pathfinder() : CreatureScript("mob_oathsworn_pathfinder") {}
 
       struct mob_oathsworn_pathfinderAI : public ScriptedAI
       {
           mob_oathsworn_pathfinderAI(Creature *c): ScriptedAI(c) {}

           uint32 Shoot_Timer;
           uint32 WingClip_Timer;

           void EnterCombat(Unit* pWho)
           {
                DoCast(SPELL_CALL_FALCON);
           }

           void Reset()
           {
               Shoot_Timer = 2000;
	       WingClip_Timer = 7000;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(Shoot_Timer <= diff)
               {
                   if (!me->IsWithinMeleeRange(me->getVictim()))
                   {
                       DoCast(me->getVictim(), SPELL_SHOOT);
                       Shoot_Timer = 2000;
		   }
               }else Shoot_Timer -= diff;

               if(WingClip_Timer <= diff)
               {
	            DoCast(me->getVictim(), SPELL_WING_CLIP);
                    WingClip_Timer = 7000;
               }else WingClip_Timer -= diff;
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_oathsworn_pathfinderAI(pCreature);
}
};

/*************************
**Oathsworn Scorpid Keeper
**************************/

#define SPELL_CALL_SCORPID     84126
#define SPELL_EVASION          84122

class mob_oathsworn_scorpid_keeper : public CreatureScript
{
public:
    mob_oathsworn_scorpid_keeper() : CreatureScript("mob_oathsworn_scorpid_keeper") {}
 
       struct mob_oathsworn_scorpid_keeperAI : public ScriptedAI
       {
           mob_oathsworn_scorpid_keeperAI(Creature *c): ScriptedAI(c) {}

           bool Evasion;

           void EnterCombat(Unit* pWho)
           {
                DoCast(SPELL_CALL_SCORPID);
           }

           void Reset()
           {
               Evasion = false;
           }	       
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (!Evasion && !HealthAbovePct(30))
               {
                   DoCast(me, SPELL_EVASION);
		   Evasion = true;
	       }
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_oathsworn_scorpid_keeperAI(pCreature);
}
};

/******************
**Oathsworn Skinner
*******************/

#define SPELL_SPINAL_PIERCE       84031
#define SPELL_FAN_OF_KNIVES       82789
#define SPELL_FAN_OF_KNIVES_H     90034

class mob_oathsworn_skinner : public CreatureScript
{
public:
    mob_oathsworn_skinner() : CreatureScript("mob_oathsworn_skinner") {}
 
       struct mob_oathsworn_skinnerAI : public ScriptedAI
       {
           mob_oathsworn_skinnerAI(Creature *c): ScriptedAI(c) {}

           uint32 SpinalPierce_Timer;
	   uint32 FanOfKnives_Timer;
	   
	   void Reset()
           {
               SpinalPierce_Timer = 3000;
	       FanOfKnives_Timer = 10000;
           }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	       
	       if(SpinalPierce_Timer <= diff)
               {
	            DoCast(me->getVictim(), SPELL_SPINAL_PIERCE);
                    SpinalPierce_Timer = 7000;
               }else SpinalPierce_Timer -= diff;
	       
	       if(FanOfKnives_Timer <= diff)
	       {
	            DoCast(IsHeroic() ? SPELL_FAN_OF_KNIVES_H : SPELL_FAN_OF_KNIVES);
		    FanOfKnives_Timer = 20000;
	       }else FanOfKnives_Timer -= diff;
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_oathsworn_skinnerAI(pCreature);
}
};

/*******************
**Oathsworn Wanderer
********************/

#define SPELL_CALL_CROCOLISK      82791
#define SPELL_FORKED_FIRESHOT     82794
#define SPELL_FORKED_FIRESHOT_H   89992
#define SPELL_SHOOT               83877

class mob_oathsworn_wanderer : public CreatureScript
{
public:
    mob_oathsworn_wanderer() : CreatureScript("mob_oathsworn_wanderer") {}
 
       struct mob_oathsworn_wandererAI : public ScriptedAI
       {
           mob_oathsworn_wandererAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 ForkedFireShot_Timer;
	   uint32 Shoot_Timer;
	   
           void EnterCombat(Unit* pWho)
           {
                DoCast(SPELL_CALL_CROCOLISK);
           }

	   void Reset()
           {
               Shoot_Timer = 2000;
	       ForkedFireShot_Timer = 13000;
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(Shoot_Timer <= diff)
               {
                   if (!me->IsWithinMeleeRange(me->getVictim()))
                   {
                       DoCast(me->getVictim(), SPELL_SHOOT);
                       Shoot_Timer = 2000;
		   }
               }else Shoot_Timer -= diff;

               if(ForkedFireShot_Timer <= diff)
               {
                   if (!me->IsWithinMeleeRange(me->getVictim()))
                   {
                       DoCast(me->getVictim(),IsHeroic() ? SPELL_FORKED_FIRESHOT_H : SPELL_FORKED_FIRESHOT);
                       ForkedFireShot_Timer = 15000;
		   }
               }else ForkedFireShot_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_oathsworn_wandererAI(pCreature);
}
};	       
	      
/************
**Pygmy Brute
*************/

#define SPELL_IMPALE         83783	      
#define SPELL_IMPALE_H       89990
#define SPELL_SHOCKWAVE      83785
#define SPELL_SHOCKWAVE_H    90024

class mob_pygmy_brute : public CreatureScript
{
public:
    mob_pygmy_brute() : CreatureScript("mob_pygmy_brute") {}
 
       struct mob_pygmy_bruteAI : public ScriptedAI
       {
           mob_pygmy_bruteAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 Impale_Timer;
	   uint32 Shockwave_Timer;
	   
	   void Reset()
           {
               Impale_Timer = 5000;
	       Shockwave_Timer = 13000;
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	   
               if (Impale_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_IMPALE_H : SPELL_IMPALE);
                     Impale_Timer = 15000;
               }else Impale_Timer -= diff;

               if (Shockwave_Timer <= diff)
               {
                   DoCastVictim(IsHeroic() ? SPELL_SHOCKWAVE_H : SPELL_SHOCKWAVE);
                   Shockwave_Timer = 25000;
               }else Shockwave_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_pygmy_bruteAI(pCreature);
}
};

/*******************
**Pygmy Firebreather
********************/

#define SPELL_DRAGONS_BREATH       83776
#define SPELL_DRAGONS_BREATH_H     90026
#define SPELL_FIRE_BLAST           83778
#define SPELL_FIRE_BLAST_H         90025

class mob_pygmy_firebreather : public CreatureScript
{
public:
    mob_pygmy_firebreather() : CreatureScript("mob_pygmy_firebreather") {}
 
       struct mob_pygmy_firebreatherAI : public ScriptedAI
       {
           mob_pygmy_firebreatherAI(Creature *c): ScriptedAI(c) {}	       
	   
	   uint32 DragonsBreath_Timer;
	   uint32 FireBlast_Timer;
	   
	   void Reset()
           {
               DragonsBreath_Timer = 10000;
	       FireBlast_Timer = 3000;
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (DragonsBreath_Timer <= diff)
               {
                   DoCastVictim(IsHeroic() ? SPELL_DRAGONS_BREATH_H : SPELL_DRAGONS_BREATH);
                   DragonsBreath_Timer = 20000;
               }else DragonsBreath_Timer -= diff;

	       if(FireBlast_Timer <= diff)
               {
	            DoCast(me->getVictim(), IsHeroic() ? SPELL_FIRE_BLAST_H : SPELL_FIRE_BLAST);
                    FireBlast_Timer = 8000;
               }else FireBlast_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_pygmy_firebreatherAI(pCreature);
}
};

/************
**Pygmy Scout
*************/

#define SPELL_TOXIC_BLOW_DART        83780
#define SPELL_TOXIC_BLOW_DART_H      89991

class mob_pygmy_scout : public CreatureScript
{
public:
    mob_pygmy_scout() : CreatureScript("mob_pygmy_scout") {}
 
       struct mob_pygmy_scoutAI : public ScriptedAI
       {
           mob_pygmy_scoutAI(Creature *c): ScriptedAI(c) {}

           uint32 ToxicBlowDart_Timer;

	   void Reset()
           {
	       ToxicBlowDart_Timer = 3000;
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (ToxicBlowDart_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_TOXIC_BLOW_DART_H : SPELL_TOXIC_BLOW_DART);
                     ToxicBlowDart_Timer = 15000;
               }else ToxicBlowDart_Timer -= diff;
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_pygmy_scoutAI(pCreature);
}
};

/*****************
**Sharptalon Eagle
******************/

#define SPELL_EAGLE_CLAW       89212
#define SPELL_EAGLE_CLAW_H     89988

class mob_sharptalon_eagle : public CreatureScript
{
public:
    mob_sharptalon_eagle() : CreatureScript("mob_sharptalon_eagle") {}
 
       struct mob_sharptalon_eagleAI : public ScriptedAI
       {
           mob_sharptalon_eagleAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 EagleClaw_Timer;
	   
	   void Reset()
           {
	       EagleClaw_Timer = 2000;
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if(EagleClaw_Timer <= diff)
               {
	            DoCast(me->getVictim(), IsHeroic() ? SPELL_EAGLE_CLAW_H : SPELL_EAGLE_CLAW);
                    EagleClaw_Timer = 15000;
               }else EagleClaw_Timer -= diff;               	       

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_sharptalon_eagleAI(pCreature);
}
};

void AddSC_trash_lost_city_of_tolvir()
{
     new mob_bonesnapper_scorpid();
     new mob_neferset_darkcaster();
     new mob_neferset_plaguebringer();     
     new mob_neferset_theurgist();
     new mob_neferset_torturer();
     new mob_oathsworn_axemaster();
     new mob_oathsworn_captain();
     new mob_oathsworn_myrmidon();
     new mob_oathsworn_pathfinder();
     new mob_oathsworn_scorpid_keeper();
     new mob_oathsworn_skinner();
     new mob_oathsworn_wanderer();     
     new mob_pygmy_brute();             		   
     new mob_pygmy_firebreather();          	       
     new mob_pygmy_scout();	   
     new mob_sharptalon_eagle();
}