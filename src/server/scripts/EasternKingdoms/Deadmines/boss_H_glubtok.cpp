/*
* Copyright (C) 2011 True Blood <http://www.trueblood-servers.com/>
* By JeanClaude
*/

#include "ScriptPCH.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"

#define SAY_AGGRO "Let's do it!"
#define SAY_DIED "'Sploded dat one!"
#define SAY_FLAME "Elemental Fists!"
#define SAY_ARCANE "Glubtok show you da power of de arcane!"

#define spell_elemental_fists RAND(87859,91273)

enum Spells
{
    //Glubtok
	SPELL_FIRE_BLOSSOMS = 91275, // Explose la boule de feu au sol
    SPELL_FIRE_BLOSSOM = 91286, // Lançe la Boule de feu
	SPELL_FROST_BLOSSOMS = 91274, // Explose la boule de glaçe
	SPELL_FROST_BLOSSOM = 91287, // Lançe la boule de glaçe
	SPELL_ARCANE_POWER = 88009, // Spell Phase 2
	SPELL_BLINK = 38932,	
};

const Position pos[1] =
{
    {-192.328003f, -450.244995f, 54.521500f, 0.00f}
};

enum Phases
{
    PHASE_NORMAL = 1,
	PHASE_50_PERCENT = 2,
};

enum BlossomSpell
{
    SUPER_FIRE_BLOSSOM,
	SUPER_FROST_BLOSSOM,
};

class boss_H_glubtok : public CreatureScript
{
 public:
    boss_H_glubtok() : CreatureScript("boss_H_glubtok") {}
	  
	struct boss_H_glubtokAI : public ScriptedAI
	{
	    boss_H_glubtokAI(Creature* pCreature) : ScriptedAI(pCreature)
		{
	        pInstance = me->GetInstanceScript();
	    }
			 
		InstanceScript* pInstance;
	   
	    uint8 Phase;
			 
		uint32 elemental_fists;
		uint32 ArcanePowerTimer;
		uint32 blinkTimer;
		uint32 PhaseChangeTimer;
		uint32 NormalCastTimer;
		uint8 BlossomSpell;
		
		uint32 SUPER_FROST_BLOSSOMS;
		uint32 SUPER_FIRE_BLOSSOMS;
		
		bool Phased;
		
		void Reset()
		{
			Phased = false;
			Phase = PHASE_NORMAL;
		
			elemental_fists = 20000;
			blinkTimer = 12000;
		
			NormalCastTimer = 3000;
			SUPER_FROST_BLOSSOMS = 2000;
			SUPER_FIRE_BLOSSOMS = 2000;
		}
			
		void EnterCombat(Unit* pWho)
		{
		    me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
		}

        void JustDied(Unit* /*Killer*/)
		{
		    me->MonsterYell(SAY_DIED, LANG_UNIVERSAL, NULL);
		}
		
		void UpdateAI(const uint32 diff)
		{
			if (!UpdateVictim())
            return;
				
			if(me->HealthBelowPct(51) && Phase == PHASE_50_PERCENT && Phased == false)
			{
			    me->SetReactState(REACT_PASSIVE);
			    me->MonsterYell(SAY_ARCANE, LANG_UNIVERSAL, NULL);
				DoCast(me, SPELL_ARCANE_POWER);
				Position pos;
                me->GetPosition(&pos);
					
				if(NormalCastTimer <= diff)
				{
				   if(!me->IsNonMeleeSpellCasted(false))
					{
						uint8 Available[2]; 
					    switch (BlossomSpell) 
						{
					        case SUPER_FIRE_BLOSSOM:
					        Available [0] = SUPER_FIRE_BLOSSOM;
							break;
							case SUPER_FROST_BLOSSOM:
                            Available [1] = SUPER_FROST_BLOSSOM;
							break;
						}

						BlossomSpell = Available[urand(0, 1)]; 
                        switch (BlossomSpell)  
                        {
                            case SUPER_FIRE_BLOSSOM:
      	                        if(Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true));
									DoCast(SPELL_FIRE_BLOSSOM);
									DoCast(SPELL_FIRE_BLOSSOMS);
									SUPER_FIRE_BLOSSOMS = 2000;
									break;
					        case SUPER_FROST_BLOSSOM:
								if(Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true));
									DoCast(SPELL_FROST_BLOSSOM);
									DoCast(SPELL_FROST_BLOSSOMS);
									SUPER_FROST_BLOSSOMS = 2000;
									break;
					    }
					}
					NormalCastTimer = 3000;
                } else NormalCastTimer -= diff;
				
				Phase = PHASE_50_PERCENT;
			    Phased = true;
				 
			}
				
			if(PhaseChangeTimer <= diff && Phase == PHASE_NORMAL)
            {
				if(PhaseChangeTimer<= diff)
				{
					me->SetReactState(REACT_AGGRESSIVE);
					elemental_fists = 20000;
					blinkTimer = 12000;
					Phase = PHASE_NORMAL;
				} else PhaseChangeTimer -= diff;
				
				if(elemental_fists <= diff && Phase == PHASE_NORMAL)
				{
					if(elemental_fists<= diff)
					{
					DoCast(me, elemental_fists);
					me->MonsterYell(SAY_FLAME, LANG_UNIVERSAL, NULL);
					elemental_fists = 20000;
				} else elemental_fists -= diff;
				}
				if(blinkTimer <= diff && Phase == PHASE_NORMAL)
				{
					if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 10.0f, true));
					DoCast(SPELL_BLINK);
					blinkTimer = 12000;
				} else blinkTimer -= diff;
			
				DoMeleeAttackIfReady();
			}
		}

    };

	CreatureAI* GetAI(Creature *pCreature) const
	{
		return new boss_H_glubtokAI(pCreature);
	}

};

void AddSC_boss_H_glubtok()
{
	new boss_H_glubtok();
}