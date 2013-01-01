/*
* Copyright (C) 2011- 2013 ProjectStudioMirage <http://www.studio-mirage.fr/>
* Copyright (C) 2011- 2013 https://github.com/Asardial
* by JeanClaude & Kentaro
*/

#include "ScriptPCH.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

#define SAY_AGGRO "Intruders in the keep! To arms!"
#define SAY_DIED "Our vigilance is eternal..."
#define SAY_POP "The attackers weaken!"
#define SAY_KILL "One step closer to victory!"

#define SPELL_DESECRATION               93687
#define SPELL_MALEFICSTRIKE             93685
#define SPELL_PERFIDIOUSSHIELD          93693
#define SPELL_PERFIDIOUSSHIELD_H        93736  //Heroic Ability
#define SPELL_UNHOLYPOWER               93686
#define SPELL_UNHOLYPOWER_H             93735  //Heroic Ability
#define SPELL_FORSAKEN_ABILITYARMOR     91436  //Heroic Ability
#define SPELL_FORSAKEN_ABILITYHEALING   91442  //Heroic Ability
#define SPELL_FORSAKEN_ABILITYHEALTH    91444  //Heroic Ability
#define SPELL_WORDOFSHAME               93852  //Heroic Ability
#define SPELL_SEPARATION_ANXIETY        96272  //Heroic Ability

#define MOB_OFFICER                     50615
#define MOB_GUARDSMAN                   50613

const Position aSpawnLocations[2] =
{
   {-249.737961f, 2262.704834f, 100.888725f, 0.00f},
   {-250.883743f, 2239.309570f, 100.895302f, 0.00f},
};
 
/*********************
**Commander Springvale
**********************/
class boss_commander_springvale: public CreatureScript
{
public:
    boss_commander_springvale() : CreatureScript("boss_commander_springvale") {}
 
    struct boss_commander_springvaleAI : public ScriptedAI
    {
        boss_commander_springvaleAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        SummonList Summons;

        uint32 Desecration_Timer;
        uint32 MaleficStrike_Timer;
        uint32 ForsakenAbility_Timer;
        uint32 Summon_Timer;
        uint32 UnholyPower_Timer;
        uint32 SeparationAnxiety_Timer;

        void Reset()
        {
            Desecration_Timer = 10000;
            MaleficStrike_Timer = 5000;
            ForsakenAbility_Timer = 14000;
            Summon_Timer = 28000;
            SeparationAnxiety_Timer = 300000;
            UnholyPower_Timer = 24000;
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
                me->SummonCreature(47293, -227.723007f, 2257.919922f, 102.753998f, 3.428720f,TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(47006, -220.116318f, 2252.102539f, 102.756050f, 2.567765f,TEMPSUMMON_CORPSE_DESPAWN);
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
		
            if(Desecration_Timer <= diff)
            {
                DoCast(SPELL_DESECRATION);
                Desecration_Timer = 15000;
            }else Desecration_Timer -= diff;

            if (MaleficStrike_Timer<= diff)
            {
                DoCast(me->getVictim(), SPELL_MALEFICSTRIKE);
                MaleficStrike_Timer = urand(8000, 15000);
            } else MaleficStrike_Timer -= diff;

            if (ForsakenAbility_Timer <= diff)
            {
                if (IsHeroic())
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, RAND(SPELL_FORSAKEN_ABILITYARMOR, SPELL_FORSAKEN_ABILITYHEALING, SPELL_FORSAKEN_ABILITYHEALTH ));
                    ForsakenAbility_Timer = urand(17000, 20000);
                }
            } else ForsakenAbility_Timer -= diff;	       
		
            if (Summon_Timer<= diff)
            {
                if (IsHeroic())
                {
                    me->MonsterYell(SAY_POP, LANG_UNIVERSAL, NULL);
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_WORDOFSHAME);
                    me->SummonCreature(MOB_OFFICER, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(MOB_GUARDSMAN, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    Summon_Timer = 30000;
                }
            } else Summon_Timer -= diff;
	       
            if(UnholyPower_Timer <= diff)
            {
                DoCast(IsHeroic() ? SPELL_PERFIDIOUSSHIELD_H : SPELL_PERFIDIOUSSHIELD);
                UnholyPower_Timer = 24000;
            } else UnholyPower_Timer -= diff;
	        
            if(SeparationAnxiety_Timer <= diff)
            {
                if (IsHeroic())
                {
                    DoCast(me, SPELL_SEPARATION_ANXIETY);
                    SeparationAnxiety_Timer = 300000;
                }
            }else SeparationAnxiety_Timer -= diff;
	       
            DoMeleeAttackIfReady();
         
        }
    };
	
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_commander_springvaleAI(pCreature);
    }
};
 
void AddSC_boss_commander_springvale()
{
    new boss_commander_springvale();
}