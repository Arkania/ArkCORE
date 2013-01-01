/*
 * Copyright (C) 2010- 2013 Project TBEmu <http://www.trueblood-servers.com/>
 * by JeanClaude
 */

 
/*************
**Lord Godfrey
**************/

#include "ScriptPCH.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

#define SAY_AGGRO "That bitch Sylvanas sent you too, did she? No matter, your journey ends in agony."
#define SAY_DIED "I thank you for the clean death. I would not have done the same..."
#define SAY_BARRAGE "Murder never gets old."

#define SPELL_CURSEDBULLETS      93629
#define SPELL_CURSEDBULLETS_H    93761
#define SPELL_MORTALWOUND        93675
#define SPELL_MORTALWOUND_H      93771
#define SPELL_PISTOLBARRAGE      93520
#define SPELL_SUMMONGHOULS       93707

#define MOB_GHOUL                50561

const Position aSpawnLocations[5] =
{
    {-86.151756f, 2150.213379f, 155.599197f, 0.00f},
    {-71.873444f, 2153.057617f, 155.694305f, 0.00f},
    {-98.024406f, 2139.520264f, 144.921326f, 0.00f},
    {-71.873444f, 2153.057617f, 155.694305f, 0.00f},
    {-100.523468f, 2157.934326f, 144.921005f, 0.00f},
};

class boss_lord_godfrey: public CreatureScript
{
public:
    boss_lord_godfrey() : CreatureScript("boss_lord_godfrey") {}
 
        struct boss_lord_godfreyAI : public ScriptedAI
        {
           boss_lord_godfreyAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
           {
           pInstance = pCreature->GetInstanceScript();
           }
           InstanceScript* pInstance;
           SummonList Summons;
	   
	   uint32 CursedBullets_Timer;
	   uint32 MortalWound_Timer;
	   uint32 PistolBarrage_Timer;
	   uint32 SummonGhouls_Timer;
	   
	   void Reset()
           {
               CursedBullets_Timer = 20000;
               PistolBarrage_Timer = 50000;
               MortalWound_Timer = 5800;
               SummonGhouls_Timer = 35000;
           }
	   
	   void EnterCombat(Unit* /*who*/)
           {
               me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
           }
	   
	   void JustDied(Unit* /*Killer*/)
           {
               me->MonsterYell(SAY_DIED, LANG_UNIVERSAL, NULL);
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
	       
	       if (CursedBullets_Timer<= diff)
               {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                    DoCast(pTarget, IsHeroic() ?  SPELL_CURSEDBULLETS_H : SPELL_CURSEDBULLETS);
                    CursedBullets_Timer = 20000;
               }else CursedBullets_Timer -= diff;
	       
	       if (PistolBarrage_Timer<= diff)
               {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_PISTOLBARRAGE);
                    PistolBarrage_Timer = 50000;
               }else PistolBarrage_Timer -= diff;
	       
	       if (MortalWound_Timer<= diff)
               {
                    DoCast(me->getVictim(), IsHeroic() ? SPELL_MORTALWOUND_H : SPELL_MORTALWOUND);
                    MortalWound_Timer = urand(6000, 12000);
               }else MortalWound_Timer -= diff;
	       
	       if (SummonGhouls_Timer<= diff)
               {
                  if (IsHeroic())
                  {
		    DoCast(SPELL_SUMMONGHOULS);
                    me->SummonCreature(MOB_GHOUL, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(MOB_GHOUL, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(MOB_GHOUL, aSpawnLocations[2].GetPositionX(), aSpawnLocations[2].GetPositionY(), aSpawnLocations[2].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(MOB_GHOUL, aSpawnLocations[3].GetPositionX(), aSpawnLocations[3].GetPositionY(), aSpawnLocations[3].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(MOB_GHOUL, aSpawnLocations[4].GetPositionX(), aSpawnLocations[4].GetPositionY(), aSpawnLocations[4].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    SummonGhouls_Timer = 35000;
		  }
               }else SummonGhouls_Timer -= diff;
 
              DoMeleeAttackIfReady();
           }
 
        };
 
 CreatureAI* GetAI(Creature* pCreature) const
 {
        return new boss_lord_godfreyAI(pCreature);
 }
 
 };
 
 void AddSC_boss_lord_godfrey()
 {
        new boss_lord_godfrey();
 }