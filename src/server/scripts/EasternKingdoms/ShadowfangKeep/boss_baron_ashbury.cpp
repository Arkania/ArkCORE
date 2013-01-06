/*
* Copyright (C) 2011- 2013 ProjectStudioMirage <http://www.studio-mirage.fr/>
* Copyright (C) 2011- 2013 https://github.com/Asardial
* by JeanClaude
*/

/**************
**Baron Ashbury
***************/

#include "ScriptPCH.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

#define SAY_AGGRO "Tally ho! The hunt begins!"
#define SAY_DEATH "Killed by lowly commoners. How droll..."
#define SAY_DARKANGEL "HA! Let's at least keep it interesting."
#define SAY_KILL "Pathetic."

#define SPELL_ASPHYXIATE               93423
#define SPELL_ASPHYXIATE_H             93710
#define SPELL_PAINANDSUFFERING         93581
#define SPELL_PAINANDSUFFERING_H       93712
#define SPELL_STAYOFEXECUTION          93468
#define SPELL_STAYOFEXECUTION_H        93705
#define SPELL_WRACKINGPAIN             93720

// Spells Phase 2
#define SPELL_ARCHANGELFORM            93757
#define SPELL_CALAMITY                 93812

const Position pos = {-253.514816f, 2123.584961f, 81.179588f, 0.00f};

class boss_baron_ashbury : public CreatureScript
{
public:
    boss_baron_ashbury() : CreatureScript("boss_baron_ashbury") {}

    struct boss_baron_ashburyAI : public ScriptedAI
    {
        boss_baron_ashburyAI(Creature *c): ScriptedAI(c) {}

        uint32 Asphyxiate_Timer;
        uint32 PainAndSuffering_Timer;
        uint32 StayOfExecution_Timer;
        uint32 WrackingPain_Timer;

        bool Light; //Phase 1
        bool Dark;  //Phase 2

        void Reset()
        {
            Asphyxiate_Timer = 15000;
            PainAndSuffering_Timer = 1000;
            StayOfExecution_Timer = 21300;
            WrackingPain_Timer = 10000;

            Light = false;
            Dark = false;
        }

        void EnterCombat(Unit* pWho)
        {
            me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
        }

        void JustDied(Unit* /*Killer*/)
        {
            me->MonsterYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
            if (!IsHeroic())
            {
                me->SummonCreature(47293, -256.848999f, 2117.020020f, 81.179604f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(47006, -254.389603f, 2115.685059f, 81.180580f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(47030, -240.097000f, 2142.600098f, 87.013100f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(47030, -234.399994f, 2140.530029f, 87.013100f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(47030, -237.617996f, 2150.810059f, 90.624603f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(47030, -233.084000f, 2148.949951f, 90.624603f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
            }
        }

        void KilledUnit(Unit* /*Victim*/)
        {
            me->MonsterYell(SAY_KILL, LANG_UNIVERSAL, NULL);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
            return;

            if (!Light && !HealthAbovePct(100))
            {
                if(Asphyxiate_Timer <= diff)
                {
                    DoCastToAllHostilePlayers(IsHeroic() ? SPELL_ASPHYXIATE_H : SPELL_ASPHYXIATE);
                    Asphyxiate_Timer = 30000;
                }else Asphyxiate_Timer -= diff;

                if(PainAndSuffering_Timer <= diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, IsHeroic() ? SPELL_PAINANDSUFFERING_H : SPELL_PAINANDSUFFERING);
                    PainAndSuffering_Timer = 12000;
                }else PainAndSuffering_Timer -= diff;

                if(StayOfExecution_Timer <= diff)
                {
                    DoCastToAllHostilePlayers(IsHeroic() ? SPELL_STAYOFEXECUTION_H : SPELL_STAYOFEXECUTION);
                    StayOfExecution_Timer = 36200;
                }else StayOfExecution_Timer -= diff;

                if(WrackingPain_Timer <= diff)
                {
                    if (IsHeroic())
                    {
                        DoCast(SPELL_WRACKINGPAIN);
                        WrackingPain_Timer = 20000;
                    }else WrackingPain_Timer -= diff;

                    Light = true;
                    Dark = false;
                }
            }

            if (!Dark && !HealthAbovePct(26))
            {
                if (IsHeroic())
                {
                    Position pos;
                    me->GetPosition(&pos);
                    SetCombatMovement(false);
                    me->MonsterYell(SAY_DARKANGEL, LANG_UNIVERSAL, NULL);
                    DoCast(me, SPELL_ARCHANGELFORM);
                    DoCast(SPELL_CALAMITY);

                    Dark = true;
                    Light = false;
                }

                DoMeleeAttackIfReady();
            }
        }
    };

    CreatureAI* GetAI(Creature *pCreature) const
    {
        return new boss_baron_ashburyAI(pCreature);
    }
};

void AddSC_boss_baron_ashbury()
{
    new boss_baron_ashbury();
}