/*
 * Copyright (C) 2010- 2013 Project TBEmu <http://www.trueblood-servers.com/>
 * by JeanClaude
 */

#include "ScriptPCH.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

/*****************
**Albino Eyegouger
******************/

#define SPELL_EYE_GOUGE      90913
#define SPELL_EYE_GOUGE_H    90918
#define SPELL_EYE_PECK       90920
#define SPELL_EYE_PECK_H     90921

class mob_albino_eyegouger : public CreatureScript
{
public:
    mob_albino_eyegouger() : CreatureScript("mob_albino_eyegouger") {}
 
       struct mob_albino_eyegougerAI : public ScriptedAI
       {
           mob_albino_eyegougerAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 EyeGouge_Timer;
	   uint32 EyePeck_Timer;
	   
	   void Reset()
           {
               EyeGouge_Timer = 1000;
	       EyePeck_Timer = 3000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if(EyeGouge_Timer<= diff)
               {
                     DoCast(me->getVictim(), IsHeroic() ? SPELL_EYE_GOUGE_H : SPELL_EYE_GOUGE);
                     EyeGouge_Timer = 4000;
	       }else EyeGouge_Timer -= diff;

               if (EyePeck_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_EYE_PECK_H : SPELL_EYE_PECK);
                     EyePeck_Timer = 7000;
               }else EyePeck_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_albino_eyegougerAI(pCreature);
}
};

/***************
**Brillant Macaw
****************/

#define SPELL_EYE_GOUGE      90913
#define SPELL_EYE_GOUGE_H    90918
#define SPELL_EYE_PECK       90920
#define SPELL_EYE_PECK_H     90921

class mob_brillant_macaw : public CreatureScript
{
public:
    mob_brillant_macaw() : CreatureScript("mob_brillant_macaw") {}
 
       struct mob_brillant_macawAI : public ScriptedAI
       {
           mob_brillant_macawAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 EyeGouge_Timer;
	   uint32 EyePeck_Timer;
	   
	   void Reset()
           {
               EyeGouge_Timer = 1000;
	       EyePeck_Timer = 3000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if(EyeGouge_Timer<= diff)
               {
                     DoCast(me->getVictim(), IsHeroic() ? SPELL_EYE_GOUGE_H : SPELL_EYE_GOUGE);
                     EyeGouge_Timer = 4000;
	       }else EyeGouge_Timer -= diff;

               if (EyePeck_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_EYE_PECK_H : SPELL_EYE_PECK);
                     EyePeck_Timer = 7000;
               }else EyePeck_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_brillant_macawAI(pCreature);
}
};

/********************
**Defias Blood Wizard
*********************/

#define SPELL_BLOODBOLT      90938
#define SPELL_BLOODBOLT_H    90939
#define SPELL_BLOODWASH      90947
#define SPELL_RAGEZONE       90932
#define SPELL_RAGEZONE_H     90933

class mob_defias_blood_wizard : public CreatureScript
{
public:
    mob_defias_blood_wizard() : CreatureScript("mob_defias_blood_wizard") {}
 
       struct mob_defias_blood_wizardAI : public ScriptedAI
       {
           mob_defias_blood_wizardAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 BloodBolt_Timer;
	   uint32 BloodWash_Timer;
	   uint32 Ragezone_Timer;
	   
	   void Reset()
           {
               BloodBolt_Timer = 1000;
	       BloodWash_Timer = 4500;
	       Ragezone_Timer = 9500;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(BloodBolt_Timer<= diff)
               {
                   DoCast(me->getVictim(), IsHeroic() ? SPELL_BLOODBOLT_H : SPELL_BLOODBOLT);
                   BloodBolt_Timer = 5000 ;
               }else BloodBolt_Timer -= diff;

               if(BloodWash_Timer <= diff)
               {
                  if (IsHeroic())
                  {
                     DoCast(me, SPELL_BLOODWASH);
                     BloodWash_Timer = 14000;
                  }
               }else BloodWash_Timer -= diff;

               if (Ragezone_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_RAGEZONE_H : SPELL_RAGEZONE);
                     Ragezone_Timer = 35000;
               }else Ragezone_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_defias_blood_wizardAI(pCreature);
}
};

/**************
**Defias Digger
***************/

#define SPELL_RENEGADE_STRENGTH    91010
//#define SPELL_TUNNEL             90994 Doesn't Work
//#define SPELL_TUNNEL_H           90995 Doesn't Work

class mob_defias_digger : public CreatureScript
{
public:
    mob_defias_digger() : CreatureScript("mob_defias_digger") {}
 
       struct mob_defias_diggerAI : public ScriptedAI
       {
           mob_defias_diggerAI(Creature *c): ScriptedAI(c) {}

           uint32 RenegadeStregth_Timer;
           //uint32 Tunnel_Timer;

	   void Reset()
           {
               RenegadeStregth_Timer = 120000;
	       //Tunnel_Timer = 4500;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(RenegadeStregth_Timer <= diff)
               {
                  if (IsHeroic())
                  {
                     DoCast(me, SPELL_RENEGADE_STRENGTH);
                     RenegadeStregth_Timer = 120000;
                  }
               }else RenegadeStregth_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_defias_diggerAI(pCreature);
}
};

/****************
**Defias Enforcer
*****************/

#define SPELL_BLOODBATH           90925
#define SPELL_CHARGE              90928
#define SPELL_CHARGE_H            90931
#define SPELL_RECKLESSNESS        90929
#define SPELL_RECKLESSNESS_H      90930

class mob_defias_enforcer : public CreatureScript
{
public:
    mob_defias_enforcer() : CreatureScript("mob_defias_enforcer") {}
 
       struct mob_defias_enforcerAI : public ScriptedAI
       {
           mob_defias_enforcerAI(Creature *c): ScriptedAI(c) {}

           uint32 BloodBath_Timer;
           
           bool	Recklessness;

	   void EnterCombat(Unit* pWho)
           {
	       DoCast(me, IsHeroic() ? SPELL_CHARGE_H : SPELL_CHARGE);
	   }
	   
	   void Reset()
           {
               BloodBath_Timer = 5000;
	       
	       Recklessness = false;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;           	   
	       
	       if(BloodBath_Timer<= diff)
               {
                   DoCast(me->getVictim(), SPELL_BLOODBATH);
                   BloodBath_Timer = 15000;
               }else BloodBath_Timer -= diff;
	       
	       if (!Recklessness && !HealthAbovePct(40))
	       {
	           DoCast(me, IsHeroic() ? SPELL_RECKLESSNESS_H : SPELL_RECKLESSNESS);
		   Recklessness = true;
	       }
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_defias_enforcerAI(pCreature);
}
};

/***************
**Defias Envoker
****************/

#define SPELL_ENVOKERS_SHIELD        92001
#define SPELL_HOLY_FIRE              91004
#define SPELL_HOLY_FIRE_H            91005
#define SPELL_RENEGADE_STRENGTH      91006

class mob_defias_envoker : public CreatureScript
{
public:
    mob_defias_envoker() : CreatureScript("mob_defias_envoker") {}
 
       struct mob_defias_envokerAI : public ScriptedAI
       {
           mob_defias_envokerAI(Creature *c): ScriptedAI(c) {}

           uint32 HolyFire_Timer;
           
           bool Renegade;

           void Reset()
           {
              if (IsHeroic())
              {
                DoCast(me, SPELL_ENVOKERS_SHIELD);
              }                
	       
	      HolyFire_Timer = 1000;
	       
	      Renegade = false;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if(HolyFire_Timer<= diff)
               {
                   DoCast(me->getVictim(), IsHeroic() ? SPELL_HOLY_FIRE_H : SPELL_HOLY_FIRE);
                   HolyFire_Timer = 5500;
               }else HolyFire_Timer -= diff;
	       
	       if (!Renegade && !HealthAbovePct(25))
	       {
	           DoCast(me, SPELL_RENEGADE_STRENGTH);
		   Renegade = true;
	       }
	       
	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_defias_envokerAI(pCreature);
}
};

/*************
**Defias Miner
**************/

#define SPELL_RENEGADE_STRENGTH    91010
//#define SPELL_TUNNEL             90994 Doesn't Work
//#define SPELL_TUNNEL_H           90995 Doesn't Work

class mob_defias_miner : public CreatureScript
{
public:
    mob_defias_miner() : CreatureScript("mob_defias_miner") {}
 
       struct mob_defias_minerAI : public ScriptedAI
       {
           mob_defias_minerAI(Creature *c): ScriptedAI(c) {}

           uint32 RenegadeStregth_Timer;
           //uint32 Tunnel_Timer;

	   void Reset()
           {
               RenegadeStregth_Timer = 120000;
	       //Tunnel_Timer = 4500;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(RenegadeStregth_Timer <= diff)
               {
                  if (IsHeroic())
                  {
                     DoCast(me, SPELL_RENEGADE_STRENGTH);
                     RenegadeStregth_Timer = 120000;
                  }
               }else RenegadeStregth_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_defias_minerAI(pCreature);
}
};

/**************
**Defias Pirate
***************/

#define SPELL_LEAPING_CLEAVE       90905
#define SPELL_LEAPING_CLEAVE_H     90906

class mob_defias_pirate : public CreatureScript
{
public:
    mob_defias_pirate() : CreatureScript("mob_defias_pirate") {}
 
       struct mob_defias_pirateAI : public ScriptedAI
       {
           mob_defias_pirateAI(Creature *c): ScriptedAI(c) {}

           uint32 LeapingCleave_Timer;

	   void Reset()
           {
               LeapingCleave_Timer = 1000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (LeapingCleave_Timer<= diff)
               {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -5.0f, true))
                    DoCast(target, IsHeroic() ? SPELL_LEAPING_CLEAVE_H : SPELL_LEAPING_CLEAVE);
                    LeapingCleave_Timer = 10000;
               }else LeapingCleave_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_defias_pirateAI(pCreature);
}
};

/*******************
**Defias Shadowguard
********************/

#define SPELL_CAMOUFLAGE             90954
#define SPELL_CAMOUFLAGE_H           90955
#define SPELL_EVASION                90958
#define SPELL_EVASION_H              90959
#define SPELL_SHADOWSTEP             90956
#define SPELL_SHADOWSTEP_H           90957
#define SPELL_SINISTER_STRIKE        90951
#define SPELL_SINISTER_STRIKE_H      90952
#define SPELL_WHIRLWING_BLADES       90960
#define SPELL_WHIRLWING_BLADES_H     90961

class mob_defias_shadowguard : public CreatureScript
{
public:
    mob_defias_shadowguard() : CreatureScript("mob_defias_shadowguard") {}
 
       struct mob_defias_shadowguardAI : public ScriptedAI
       {
           mob_defias_shadowguardAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 Camouflage_Timer;
	   uint32 Shadowstep_Timer;
	   uint32 SinisterStrike_Timer;
	   uint32 WhirlingBlades_Timer;
	   
	   bool Evasion;
	   
	   void Reset()
           {
               Camouflage_Timer = 35000;
	       Shadowstep_Timer = 12000;
	       SinisterStrike_Timer = 3000;
	       WhirlingBlades_Timer = 10000;
	       
	       Evasion = false;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(Camouflage_Timer <= diff)
               {
                   DoCast(me, IsHeroic() ? SPELL_CAMOUFLAGE_H : SPELL_CAMOUFLAGE);
                   Camouflage_Timer = 30000;
               }else Camouflage_Timer -= diff;

               if(Shadowstep_Timer<= diff)
               {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -5.0f, true))
                    DoCast(target, IsHeroic() ? SPELL_SHADOWSTEP_H : SPELL_SHADOWSTEP);
                    Shadowstep_Timer = 15000;
               }else Shadowstep_Timer -= diff;

	       if(SinisterStrike_Timer<= diff)
               {
                   DoCast(me->getVictim(), IsHeroic() ? SPELL_SINISTER_STRIKE_H : SPELL_SINISTER_STRIKE);
                   SinisterStrike_Timer = 6000;
               }else SinisterStrike_Timer -= diff;

               if(WhirlingBlades_Timer <= diff)
               {
                   DoCast(IsHeroic() ? 	SPELL_WHIRLWING_BLADES_H : SPELL_WHIRLWING_BLADES );
                   WhirlingBlades_Timer = 22000;
               }else WhirlingBlades_Timer -= diff;

	       if (!Evasion && !HealthAbovePct(30))
	       {
	           DoCast(me, IsHeroic() ? SPELL_EVASION_H : SPELL_EVASION);
                   Evasion = true;
               }

	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_defias_shadowguardAI(pCreature);
}
};

/********************
**Defias Squallshaper
*********************/

#define SPELL_RIPTIDE       90914
#define SPELL_SEASWELL      90398
#define SPELL_SEASWELL_H    90912

class mob_defias_squallshaper : public CreatureScript
{
public:
    mob_defias_squallshaper() : CreatureScript("mob_defias_squallshaper") {}
 
       struct mob_defias_squallshaperAI : public ScriptedAI
       {
           mob_defias_squallshaperAI(Creature *c): ScriptedAI(c) {}

           uint32 Seaswell_Timer;

           bool Riptide;

	   void Reset()
           {
               Seaswell_Timer = 5000;

	       Riptide = false;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (Seaswell_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_SEASWELL_H : SPELL_SEASWELL);
                     Seaswell_Timer = 35000;
               }else Seaswell_Timer -= diff;

	       if (!Riptide && !HealthAbovePct(50))
	       {
		  if (IsHeroic())
                  {
		     DoCast(me, SPELL_RIPTIDE);
		     Riptide = true;
		  }
	       }

	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_defias_squallshaperAI(pCreature);
}
};

/**************
**Kobold Digger
***************/

#define SPELL_CANDLE_BLAST      89663
#define SPELL_CANDLE_BLAST_H    91057

class mob_kobold_digger : public CreatureScript
{
public:
    mob_kobold_digger() : CreatureScript("mob_kobold_digger") {}
 
       struct mob_kobold_diggerAI : public ScriptedAI
       {
           mob_kobold_diggerAI(Creature *c): ScriptedAI(c) {}

           uint32 CandleBlast_Timer;
           
	   void Reset()
           {
              CandleBlast_Timer = 8000;
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(CandleBlast_Timer <= diff)
               {
                    DoCastVictim(IsHeroic() ? SPELL_CANDLE_BLAST_H : SPELL_CANDLE_BLAST);
                    CandleBlast_Timer = 12000;
               }else CandleBlast_Timer -= diff;

	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_kobold_diggerAI(pCreature);
}
};

/************
**Molten Slag
*************/

#define SPELL_FIXATE            91830
#define SPELL_MOLTEN_SHIELD	91815

class mob_molten_slag : public CreatureScript
{
public:
    mob_molten_slag() : CreatureScript("mob_molten_slag") {}
 
       struct mob_molten_slagAI : public ScriptedAI
       {
           mob_molten_slagAI(Creature *c): ScriptedAI(c) {}

           uint32 Fixate_Timer;

	   void Reset()
           {
              Fixate_Timer = 5000;
	   }

	   void EnterCombat(Unit* pWho)
           {
                DoCast(me, SPELL_MOLTEN_SHIELD);
           }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(Fixate_Timer <= diff)
               {
                   DoCast(me->getVictim(), SPELL_FIXATE);
                   Fixate_Timer = 6000;
               }else Fixate_Timer -= diff;

	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_molten_slagAI(pCreature);
}
};

/*****************
**Monstrous Parrot
******************/

#define SPELL_EYE_GOUGE      90913
#define SPELL_EYE_GOUGE_H    90918
#define SPELL_EYE_PECK       90920
#define SPELL_EYE_PECK_H     90921

class mob_monstrous_parrot : public CreatureScript
{
public:
    mob_monstrous_parrot() : CreatureScript("mob_monstrous_parrot") {}
 
       struct mob_monstrous_parrotAI : public ScriptedAI
       {
           mob_monstrous_parrotAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 EyeGouge_Timer;
	   uint32 EyePeck_Timer;
	   
	   void Reset()
           {
               EyeGouge_Timer = 1000;
	       EyePeck_Timer = 3000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if(EyeGouge_Timer<= diff)
               {
                     DoCast(me->getVictim(), IsHeroic() ? SPELL_EYE_GOUGE_H : SPELL_EYE_GOUGE);
                     EyeGouge_Timer = 4000;
	       }else EyeGouge_Timer -= diff;

               if (EyePeck_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_EYE_PECK_H : SPELL_EYE_PECK);
                     EyePeck_Timer = 7000;
               }else EyePeck_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_monstrous_parrotAI(pCreature);
}
};

/***********
**Oaf Lackey
************/

#define SPELL_AXE_TO_THE_HEAD        90098
#define SPELL_AXE_TO_THE_HEAD_H      91016
#define SPELL_ENRAGE                 8599

class mob_oaf_lackey : public CreatureScript
{
public:
    mob_oaf_lackey() : CreatureScript("mob_oaf_lackey") {}
 
       struct mob_oaf_lackeyAI : public ScriptedAI
       {
           mob_oaf_lackeyAI(Creature *c): ScriptedAI(c) {}
	   
	   bool Enrage;
	   
	   void Reset()
           {
               Enrage = false;
	   }
	   
	   void EnterCombat(Unit* pWho)
           {
                DoCast(me->getVictim(), IsHeroic() ? SPELL_AXE_TO_THE_HEAD_H : SPELL_AXE_TO_THE_HEAD);
           }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if (!Enrage && !HealthAbovePct(30))
               {
                    DoCast(me, SPELL_ENRAGE);
                    Enrage = true;
               }

	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_oaf_lackeyAI(pCreature);
}
};

/***************
**Ogre Bodyguard
****************/

#define SPELL_BONK          91050
#define SPELL_BONK_H	    91051
#define SPELL_FRENZY        91053
#define SPELL_FRENZY_H      91054

class mob_ogre_bodyguard : public CreatureScript
{
public:
    mob_ogre_bodyguard() : CreatureScript("mob_ogre_bodyguard") {}
 
       struct mob_ogre_bodyguardAI : public ScriptedAI
       {
           mob_ogre_bodyguardAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 Bonk_Timer;
	   uint32 Frenzy_Timer;
	   
	   void Reset()
           {
               Bonk_Timer = 5000;
	       Frenzy_Timer = 12000;
	   }

	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(Bonk_Timer <= diff)
               {
                    DoCast(me->getVictim(), IsHeroic() ? SPELL_BONK_H : SPELL_BONK);
                    Bonk_Timer = 10000;
               }else Bonk_Timer -= diff;

               if(Frenzy_Timer <= diff)
               {
                    DoCast(me, IsHeroic() ? SPELL_FRENZY_H : SPELL_FRENZY);
                    Frenzy_Timer = 22000;
               }else Frenzy_Timer -= diff;

	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_ogre_bodyguardAI(pCreature);
}
};

/**************
**Ogre Henchman
***************/

#define SPELL_OGRISH_MOTIVATION         89652
#define SPELL_OGRISH_MOTIVATION_H       92748
#define SPELL_UPPERCUT                  91045
#define SPELL_UPPERCUT_H                91046

class mob_ogre_henchman : public CreatureScript
{
public:
    mob_ogre_henchman() : CreatureScript("mob_ogre_henchman") {}
 
       struct mob_ogre_henchmanAI : public ScriptedAI
       {
           mob_ogre_henchmanAI(Creature *c): ScriptedAI(c) {}

           uint32 Uppercut_Timer;
           uint32 OgrishMotivation_Timer;
           
	   void Reset()
           {
               Uppercut_Timer = 5000;
	       OgrishMotivation_Timer = 18000;
	   }

	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

               if(Uppercut_Timer <= diff)
               {
                    DoCast(me->getVictim(), IsHeroic() ? SPELL_UPPERCUT_H : SPELL_UPPERCUT);
                    Uppercut_Timer = 12000;
               }else Uppercut_Timer -= diff;
	       
	       if(OgrishMotivation_Timer <= diff)
	       {
	            DoCast(me, IsHeroic() ? SPELL_OGRISH_MOTIVATION_H : SPELL_OGRISH_MOTIVATION);
		    OgrishMotivation_Timer = 30000;
	       }else OgrishMotivation_Timer -= diff;
	       
	     DoMeleeAttackIfReady();            

           }

       };
       
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_ogre_henchmanAI(pCreature);
}
};

/*********
**Ol'Beaky
**********/

#define SPELL_EYE_GOUGE      90913
#define SPELL_EYE_GOUGE_H    90918
#define SPELL_EYE_PECK       90920
#define SPELL_EYE_PECK_H     90921

class mob_olbeaky : public CreatureScript
{
public:
    mob_olbeaky() : CreatureScript("mob_olbeaky") {}
 
       struct mob_olbeakyAI : public ScriptedAI
       {
           mob_olbeakyAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 EyeGouge_Timer;
	   uint32 EyePeck_Timer;
	   
	   void Reset()
           {
               EyeGouge_Timer = 1000;
	       EyePeck_Timer = 3000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if(EyeGouge_Timer<= diff)
               {
                     DoCast(me->getVictim(), IsHeroic() ? SPELL_EYE_GOUGE_H : SPELL_EYE_GOUGE);
                     EyeGouge_Timer = 4000;
	       }else EyeGouge_Timer -= diff;

               if (EyePeck_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_EYE_PECK_H : SPELL_EYE_PECK);
                     EyePeck_Timer = 7000;
               }else EyePeck_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_olbeakyAI(pCreature);
}
};

/*****************
**Sunwing Squawker
******************/

#define SPELL_EYE_GOUGE      90913
#define SPELL_EYE_GOUGE_H    90918
#define SPELL_EYE_PECK       90920
#define SPELL_EYE_PECK_H     90921

class mob_sunwing_squawker : public CreatureScript
{
public:
    mob_sunwing_squawker() : CreatureScript("mob_sunwing_squawker") {}
 
       struct mob_sunwing_squawkerAI : public ScriptedAI
       {
           mob_sunwing_squawkerAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 EyeGouge_Timer;
	   uint32 EyePeck_Timer;
	   
	   void Reset()
           {
               EyeGouge_Timer = 1000;
	       EyePeck_Timer = 3000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;

	       if(EyeGouge_Timer<= diff)
               {
                     DoCast(me->getVictim(), IsHeroic() ? SPELL_EYE_GOUGE_H : SPELL_EYE_GOUGE);
                     EyeGouge_Timer = 4000;
	       }else EyeGouge_Timer -= diff;

               if (EyePeck_Timer<= diff)
               {
                     if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                     DoCast(pTarget, IsHeroic() ? SPELL_EYE_PECK_H : SPELL_EYE_PECK);
                     EyePeck_Timer = 7000;
               }else EyePeck_Timer -= diff;

	      DoMeleeAttackIfReady();
           }
       };
	
CreatureAI* GetAI(Creature *pCreature) const
{
        return new mob_sunwing_squawkerAI(pCreature);
}
};

void AddSC_trash_deadmines()
{
   new mob_albino_eyegouger();  
   new mob_brillant_macaw();	       
   new mob_defias_blood_wizard();
   new mob_defias_digger();
   new mob_defias_enforcer();
   new mob_defias_envoker();	       
   new mob_defias_miner();
   new mob_defias_pirate();
   new mob_defias_shadowguard();   
   new mob_defias_squallshaper();
   new mob_kobold_digger();   
   new mob_molten_slag();
   new mob_monstrous_parrot();
   new mob_oaf_lackey();
   new mob_ogre_bodyguard();
   new mob_ogre_henchman();
   new mob_olbeaky();   
   new mob_sunwing_squawker();
}