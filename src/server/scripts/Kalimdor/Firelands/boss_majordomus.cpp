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
#include "firelands.h"

enum Yells
{
	SAY_AGGRO                                    = -1999971,
	SAY_ON_DEAD									 = -1999974 //TODO Add Sound
};

enum Spells
{
	SPELL_CAT_FORM								 = 98374,
	SPELL_SCORPION_FORM							 = 98379,

	SPELL_ADRENALINE							 = 97238,
	SPELL_BERSERK								 = 26662,
	SPELL_BURNING_ORBS							 = 98451,
	SPELL_FIERY_CYCLONE							 = 98443,
	SPELL_FLAME_SCYTE							 = 98474, // 10N
	SPELL_FURY									 = 97235,
	SPELL_LEAPING_FLAMES						 = 98476,
	SPELL_LEAPING_FLAMES_SUMMON					 = 101222,
	SPELL_SEARING_SEEDS							 = 98450,
};

enum Events
{
	EVENT_LEAPING_FLAMES = 1,
	EVENT_BERSERK		 = 2,
	EVENT_SWITCH_TO_NEXT_FORM = 3,
};

enum MajordomoPhase
{
	PHASE_DRUID,
	PHASE_CAT,
	PHASE_SCORPION
};

enum Misc
{
	DISPLAYID_DRUID								  = 37953, 
	DISPLAYID_CAT								  = 38747, // The two animals Display ids are needed
	DISPLAYID_SCORPION							  = 36617,  // because they are not handled through the spells
};

/**** Majordomo Staghelm ****/

class boss_majordomus : public CreatureScript
{
public:
	boss_majordomus() : CreatureScript("boss_majordomus"){}

	CreatureAI* GetAI(Creature* creature) const
	{
		return new boss_majordomusAI(creature);
	}

	struct boss_majordomusAI : public BossAI
	{
		boss_majordomusAI(Creature* c) : BossAI(c, DATA_MAJORDOMUS)
		{
			instance = me->GetInstanceScript();
		}

		InstanceScript* instance;
		MajordomoPhase phase;
		MajordomoPhase nextPhase;
		uint8 DruidPhaseCounterForSearingSeeds;

		void Reset()
		{
			instance->SetBossState(DATA_MAJORDOMUS, NOT_STARTED);
			events.Reset();

			me->GetMotionMaster()->MoveTargetedHome();

			summons.DespawnAll();

			TransformToDruid();
		}

		void KilledUnit(Unit * /*victim*/)
		{
		}

		void JustSummoned(Creature* summon)
		{
			summons.Summon(summon);
			summon->setActive(true);

			if(me->isInCombat())
				DoZoneInCombat();
		}

		void JustDied(Unit * /*victim*/)
		{
			instance->SetBossState(DATA_MAJORDOMUS, DONE);
			DoScriptText(SAY_ON_DEAD, me);
			summons.DespawnAll();
			_JustDied();
		}

		void EnterCombat(Unit* who)
		{
			DruidPhaseCounterForSearingSeeds = 3;

			events.ScheduleEvent(EVENT_BERSERK, 10 * MINUTE * IN_MILLISECONDS);

			TransformToCat();
			_EnterCombat();
		}

		void UpdateAI(const uint32 diff)
		{

			if(phase == PHASE_SCORPION && me->GetPower(POWER_ENERGY) == 100)
				DoCast(SPELL_FLAME_SCYTE);

			if(phase == PHASE_CAT && me->GetPower(POWER_ENERGY) == 100)
			{
				me->SetPower(POWER_ENERGY,0);

				me->SummonCreature(NPC_SPIRIT_OF_THE_FLAME,me->GetPositionX(),me->GetPositionY()
					,me->GetPositionZ(),TEMPSUMMON_CORPSE_DESPAWN);
			}

			if (me->HasUnitState(UNIT_STAT_CASTING))
				return;

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{

					if (phase == PHASE_DRUID)
					{

					}

					if (phase == PHASE_CAT)
					{




				case EVENT_LEAPING_FLAMES:

					// Spell cause Client to Crash
					//if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true))
					//	DoCastVictim(SPELL_LEAPING_FLAMES);

					events.ScheduleEvent(EVENT_LEAPING_FLAMES, 20000);
					break;

					}

				case EVENT_BERSERK:
					DoCast(me, SPELL_BERSERK,true);
					break;

				case EVENT_SWITCH_TO_NEXT_FORM:





					break;

				}
			}

			if (!UpdateVictim())
				return;

			DoMeleeAttackIfReady();
		}


	private:
		void TransformToCat()
		{
			me->RemoveAura(SPELL_ADRENALINE);
			me->RemoveAura(SPELL_SCORPION_FORM);

			me->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);

			DoCast(me,SPELL_CAT_FORM,false);
			me->SetDisplayId(DISPLAYID_CAT);

			me->setPowerType(POWER_ENERGY);
			me->SetMaxPower(POWER_ENERGY,100);
			me->SetPower(POWER_ENERGY,0);

			DoCast(me,SPELL_FURY,false);

			events.Reset();

			events.ScheduleEvent(EVENT_LEAPING_FLAMES, 10000);

			phase = PHASE_CAT;
		}

		void TransformToScorpion()
		{
			me->SetFloatValue(OBJECT_FIELD_SCALE_X, 15);
			me->RemoveAura(SPELL_ADRENALINE);
			me->RemoveAura(SPELL_CAT_FORM);

			DoCast(me,SPELL_SCORPION_FORM,false);
			me->SetDisplayId(DISPLAYID_SCORPION);

			me->setPowerType(POWER_ENERGY);
			me->SetMaxPower(POWER_ENERGY,100);
			me->SetPower(POWER_ENERGY,0);

			DoCast(me,SPELL_FURY,false);

			events.Reset();

			phase = PHASE_SCORPION;
		}

		void TransformToDruid()
		{
			me->RemoveAura(SPELL_ADRENALINE);
			me->RemoveAura(SPELL_CAT_FORM);
			me->RemoveAura(SPELL_SCORPION_FORM);

			me->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);

			me->SetDisplayId(DISPLAYID_DRUID);

			me->setPowerType(POWER_MANA);
			//me->SetMaxPower(POWER_MANA,155555);

			phase = PHASE_DRUID;


			// Cast Searing Seeds after Majordoma has switched the 3. time in the Druid Form
			if(me->isInCombat())
			{
				DruidPhaseCounterForSearingSeeds++;

				if(DruidPhaseCounterForSearingSeeds == 4)
				{
					DruidPhaseCounterForSearingSeeds = 1;

					DoCast(SPELL_SEARING_SEEDS);
				}

				events.ScheduleEvent(EVENT_SWITCH_TO_NEXT_FORM, 15000);

			}
		}

	};
};

class npc_spirit_of_the_flame : public CreatureScript
{
public:
	npc_spirit_of_the_flame() : CreatureScript("npc_spirit_of_the_flame"){}

	CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_spirit_of_the_flameAI(creature);
	}

	struct npc_spirit_of_the_flameAI : public ScriptedAI
	{
		npc_spirit_of_the_flameAI(Creature *c) : ScriptedAI(c), pMajordomus (NULL){}

		Unit* pMajordomus;
		bool canDropLeapingFlames;
		Position leapingFlamesPosition;

		void Reset()
		{

		}

		void IsSummonedBy(Unit* summoner)
		{
			pMajordomus = summoner;
		}

		void JustDied(Unit * /*victim*/)
		{
		}

		void EnterCombat(Unit* who)
		{
			if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true))
			{
				me->GetMotionMaster()->MoveJump(tempTarget->GetPositionX(),tempTarget->GetPositionY(),tempTarget->GetPositionZ(),1.0f,1.0f);
				me->AddThreat(pMajordomus->getVictim(), 100.0f);

				Position tempPosition = {tempTarget->GetPositionX(),tempTarget->GetPositionY(),tempTarget->GetPositionZ(), 0};

				leapingFlamesPosition = tempPosition;

				canDropLeapingFlames = true;
			}
		}

		void UpdateAI(const uint32 diff)
		{
			if(canDropLeapingFlames && me->GetDistance(leapingFlamesPosition) == 0)
			{
				me->MonsterSay("Was here!",0,0);
				me->GetMotionMaster()->MoveChase(me->getVictim());
			}

			DoMeleeAttackIfReady();
		}


	};
};

void AddSC_boss_majordomus()
{
	new boss_majordomus();
	new npc_spirit_of_the_flame();
}