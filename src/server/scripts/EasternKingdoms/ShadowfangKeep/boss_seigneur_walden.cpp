/*
 * Copyright (C) 2010- 2013 Project TBEmu <http://www.trueblood-servers.com/>
 * by JeanClaude
 */

/************
**Lord Walden
*************/

#include "ScriptPCH.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

#define SAY_AGGRO "You shall annoy me no longer!"
#define SAY_DIED "My new life was just beginning..."

#define SPELL_ICESHARDS                    93527
#define SPELL_CONJURE_FROSTMIXTURE         93702
#define SPELL_CONJURE_POISONOUSMIXTURE     93697
#define SPELL_CONJURE_POISONOUSMIXTURE_H   93704
//#define SPELL_TOXIC_COAGULANT            93617 // Doesn't Work
//#define SPELL_TOXIC_CATALYST             93689 // Doesn't Work
//#define SPELL_MYSTERY_TOXIN              93562 // Doesn't Work

class boss_lord_walden : public CreatureScript
{
public:
    boss_lord_walden() : CreatureScript("boss_lord_walden") {}
 
       struct boss_lord_waldenAI : public ScriptedAI
       {
           boss_lord_waldenAI(Creature *c): ScriptedAI(c) {}
	   
	   uint32 IceShard_Timer;
	   uint32 ConjureFrostMixture_Timer;
	   uint32 ConjurePoisonousMixture_Timer;
	   
	   void Reset()
           {
	        IceShard_Timer = 10000;
		ConjureFrostMixture_Timer = 7000;
		ConjurePoisonousMixture_Timer = 18000;
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
	          me->SummonCreature(47293, -142.300003f, 2171.350098f, 128.201004f, 5.876330f,TEMPSUMMON_CORPSE_DESPAWN);
                  me->SummonCreature(47006, -137.094223f, 2163.624268f, 128.943665f, 2.279842f,TEMPSUMMON_CORPSE_DESPAWN);
               }
	   }
	   
	   void UpdateAI(const uint32 diff)
           {
               if (!UpdateVictim())
               return;
	       
	       if (IceShard_Timer<= diff)
               {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_ICESHARDS);
                    IceShard_Timer = 25000;
               } else IceShard_Timer-= diff;
	       
	       if (ConjureFrostMixture_Timer<= diff)
               {
	         if (IsHeroic())
                 {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, SPELL_CONJURE_FROSTMIXTURE);
                    ConjureFrostMixture_Timer = 18000;
                 }
               } else ConjureFrostMixture_Timer-= diff;
	       
	       if (ConjurePoisonousMixture_Timer<= diff)
               {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(pTarget, IsHeroic() ? SPELL_CONJURE_POISONOUSMIXTURE_H : SPELL_CONJURE_POISONOUSMIXTURE);
                    ConjurePoisonousMixture_Timer = 35000;
               } else ConjurePoisonousMixture_Timer -= diff;
	       
	       DoMeleeAttackIfReady();
         
	      }  
           };
	
CreatureAI* GetAI(Creature* pCreature) const
{
    return new boss_lord_waldenAI(pCreature);
}
 
};
 
void AddSC_boss_lord_walden()
{
        new boss_lord_walden();
}