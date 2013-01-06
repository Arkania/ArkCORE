/*
 * Copyright (C) 2010- 2013 Project TBEmu <http://www.trueblood-servers.com/>
 * by JeanClaude
 */

/******************
**Baron Silverlaine
*******************/

#include "ScriptPCH.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

#define SPELL_VEILOFSHADOW                23224 // Veil of Shadow  
#define SPELL_CURSEDVEIL_H                93956 // Cursed Veil
#define SPELL_SUMMON_WORGENSPIRIT         93857 // Summon Worgen Spirit
 
#define SAY_KILL "May your soul rest in peace."
#define SAY_DIED "This death is only a temporary respite from my curse."
#define SAY_AGGRO "Leave this accursed place at once!"
#define SAY_POP "I hope your spirit finds solace."
 
#define MOB_WORGEN_H   RAND(50857,50851,50834,50869)
#define MOB_WORGEN     RAND(4279,3886,3914,3927)
 
const Position adSpawnLocations[3] =
{
   {-247.277115f, 2295.571533f, 74.999435f, 0.00f},
   {-259.058899f, 2282.666504f, 74.999420f, 0.00f},
   {-273.889893f, 2296.535400f, 76.153397f, 0.00f},
};
 
class boss_baron_silverlaine: public CreatureScript
{
public:
    boss_baron_silverlaine() : CreatureScript("boss_baron_silverlaine") {}
 
        struct boss_baron_silverlaineAI : public ScriptedAI
        {
           boss_baron_silverlaineAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
           {
           pInstance = pCreature->GetInstanceScript();
           }
           InstanceScript* pInstance;
           SummonList Summons;
 
           uint32 VeilOfShadow_Timer;
	   uint32 CursedVeil_Timer;
           uint32 SummonWorgenSpirit_Timer;
 
           void Reset()
           {
	   VeilOfShadow_Timer = 5000;
           CursedVeil_Timer = 5000;
           SummonWorgenSpirit_Timer = 10000;
           }
 
           void EnterCombat(Unit* /*who*/)
           {
                  me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
           }
 
           void JustDied(Unit* /*killer*/)
           {
               me->MonsterYell(SAY_DIED, LANG_UNIVERSAL, NULL);
               if (!IsHeroic())
               {
	          me->SummonCreature(47293, -260.756989f, 2289.919922f, 74.999397f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                  me->SummonCreature(47006, -273.304199f, 2301.063965f, 76.153351f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                  me->SummonCreature(47294, -269.815002f, 2293.419922f, 77.483902f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
		  me->SummonCreature(47030, -257.640015f, 2300.989990f, 74.999298f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
		  me->SummonCreature(47030, -270.197998f, 2305.959961f, 81.359001f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
		  me->SummonCreature(47030, -264.845001f, 2283.000000f, 75.000397f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
		  me->SummonCreature(47030, -277.431000f, 2288.080078f, 81.359100f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN); 
	       }
	   }
 
           void KilledUnit(Unit* /*Victim*/)
           {
               me->MonsterYell(SAY_KILL, LANG_UNIVERSAL, NULL);
           } 
 
           void JustSummoned(Creature *pSummoned)
           {
           pSummoned->SetInCombatWithZone();
           if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
           pSummoned->AI()->AttackStart(pTarget);
           Summons.Summon(pSummoned);
           }
           void SummonedCreatureDespawn(Creature *summon)
           {
           Summons.Despawn(summon);
           }
 
           void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
                return;
                               
               if (VeilOfShadow_Timer<= diff)
               {
	          if (!IsHeroic())
                  {
                      DoCast(me->getVictim(), SPELL_VEILOFSHADOW);
                      VeilOfShadow_Timer = urand(8000, 15000);
		  }
               } else VeilOfShadow_Timer -= diff;
	       
	       if (CursedVeil_Timer<= diff)
               {
	          if (IsHeroic())
                  {
                       DoCast(SPELL_CURSEDVEIL_H);
                       CursedVeil_Timer = 20000;
		  }
               } else CursedVeil_Timer -= diff;
 
               if (SummonWorgenSpirit_Timer<= diff)
               {
               me->MonsterYell(SAY_POP, LANG_UNIVERSAL, NULL);
               DoCast(SPELL_SUMMON_WORGENSPIRIT);
               me->SummonCreature(IsHeroic() ? MOB_WORGEN_H : MOB_WORGEN, adSpawnLocations[1].GetPositionX(), adSpawnLocations[1].GetPositionY(), adSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
               SummonWorgenSpirit_Timer = 30000;
               } else SummonWorgenSpirit_Timer -= diff;
               
	       DoMeleeAttackIfReady();
         
	  }
};

CreatureAI* GetAI(Creature* pCreature) const
{
        return new boss_baron_silverlaineAI(pCreature);
}
 
};

/*********************
**Odo The Blindwatcher
**********************/

#define SPELL_BLINDINGSHADOWS         93952
#define SPELL_BLINDINGSHADOWS_H       93953
#define SPELL_HOWLINGRAGE             93931
#define SPELL_HOWLINGRAGE_H           93951

class mob_odo_the_blindwatcher : public CreatureScript
{
public:
    mob_odo_the_blindwatcher() : CreatureScript("mob_odo_the_blindwatcher") {}
 
       struct mob_odo_the_blindwatcherAI : public ScriptedAI
       {
           mob_odo_the_blindwatcherAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 HowlingRage_Timer;
	   
	   void Reset()
           {
	        HowlingRage_Timer = 6000;
	   }
	   
	   void EnterCombat(Unit* /*who*/)
           {
               DoCast(me, IsHeroic() ? SPELL_BLINDINGSHADOWS_H : SPELL_BLINDINGSHADOWS); 
           }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
                return;
		
		if (HowlingRage_Timer <= diff)
		{
		    DoCast(me, IsHeroic() ? SPELL_HOWLINGRAGE_H : SPELL_HOWLINGRAGE);
		    HowlingRage_Timer = 6000;
		} else HowlingRage_Timer -= diff;
		
	    DoMeleeAttackIfReady();
         
	  }
       };

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_odo_the_blindwatcherAI(pCreature);
}
 
};

/*******************
**Wolf Master Nandos
********************/

#define SPELL_CLAW                  93861
//#define SPELL_SUMMON_LUPINESPIRIT 94199 *Summon Only one lupine spirit , but he must summon three of them .

#define MOB_LUPINESPIRIT            50923

const Position aSpawnLocations = {-247.277115f, 2295.571533f, 74.999435f, 0.00f};

class mob_wolf_master_nandos : public CreatureScript
{
public:
    mob_wolf_master_nandos() : CreatureScript("mob_wolf_master_nandos") {}
 
       struct mob_wolf_master_nandosAI : public ScriptedAI
       {
           mob_wolf_master_nandosAI(Creature *c): ScriptedAI(c), Summons(me){}

           SummonList Summons;
	   
	   uint32 Claw_Timer;
	   
	   void JustSummoned(Creature *pSummoned)
           {
           pSummoned->SetInCombatWithZone();
           if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
           pSummoned->AI()->AttackStart(pTarget);
           Summons.Summon(pSummoned);
           }
           void SummonedCreatureDespawn(Creature *summon)
           {
           Summons.Despawn(summon);
           }
	   
	   void EnterCombat(Unit* /*who*/)
           {
               if (IsHeroic())
               {
	             me->SummonCreature(MOB_LUPINESPIRIT, -247.277115f, 2295.571533f, 74.999435f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                     me->SummonCreature(MOB_LUPINESPIRIT, -247.277115f, 2295.571533f, 74.999435f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
	             me->SummonCreature(MOB_LUPINESPIRIT, -247.277115f, 2295.571533f, 74.999435f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
	       }
	   }
	   
	   void Reset()
           {
	        Claw_Timer = 6000;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
		
	       if(Claw_Timer <= diff)
	       {
	          DoCast(me->getVictim(), SPELL_CLAW);
                  Claw_Timer = 7000;
	       }
	       
	      		
	    DoMeleeAttackIfReady();
         
	  }
       };

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_wolf_master_nandosAI(pCreature);
}
 
};

/***********
**Rethilgore
************/

#define SPELL_SOULDRAIN     93863
#define SPELL_SOULDRAIN_H   93920

class mob_rethilgore : public CreatureScript
{
public:
    mob_rethilgore() : CreatureScript("mob_rethilgore") {}
 
       struct mob_rethilgoreAI : public ScriptedAI
       {
           mob_rethilgoreAI(Creature *c): ScriptedAI(c) {}
	   
	   bool Drain;
	   
	   void Reset()
           {
	        Drain = false;
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	       
	       if (!Drain && !HealthAbovePct(50))
	       {
	            DoCast(me->getVictim(), IsHeroic() ? SPELL_SOULDRAIN_H : SPELL_SOULDRAIN);
		    Drain = true;
	       }
	       
               	    DoMeleeAttackIfReady();
         
	   }
       };

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_rethilgoreAI(pCreature);
}
 
};

/**********************
**Razorclaw The Butcher
***********************/

#define SPELL_SPECTRALRUSH     93914
#define SPELL_BUTCHERDRAIN     7485
#define SPELL_BUTCHERDRAIN_H   94924

class mob_razorclaw_the_butcher : public CreatureScript
{
public:
    mob_razorclaw_the_butcher() : CreatureScript("mob_razorclaw_the_butcher") {}
 
       struct mob_razorclaw_the_butcherAI : public ScriptedAI
       {
          mob_razorclaw_the_butcherAI(Creature *c): ScriptedAI(c) {}
	  
	  uint32 ButcherDrain_Timer;
	  
	  void EnterCombat(Unit* /*who*/)
           {
               DoCast(me->getVictim(), SPELL_SPECTRALRUSH);
           }
	  
	  void Reset()
          {
	        ButcherDrain_Timer = 12000;
	  }

          void UpdateAI(const uint32 diff)
          {
               if (!UpdateVictim())
               return;
	       
	       if(ButcherDrain_Timer <= diff)
	       {
	           DoCast(me->getVictim(), IsHeroic() ? SPELL_BUTCHERDRAIN_H : SPELL_BUTCHERDRAIN);
		   ButcherDrain_Timer = 10000;
	       }else ButcherDrain_Timer -= diff;
	       
	     DoMeleeAttackIfReady();
         
	  }
       };

CreatureAI* GetAI(Creature* pCreature) const
{
        return new mob_razorclaw_the_butcherAI(pCreature);
}
 
};

void AddSC_boss_baron_silverlaine()
{
    new boss_baron_silverlaine();
	new mob_odo_the_blindwatcher();
	new mob_wolf_master_nandos();
	new mob_rethilgore();
	new mob_razorclaw_the_butcher();
}