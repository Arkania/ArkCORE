/*
* Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
*
* Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
*
* Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/* ToDo:
- Damage of Shadow Gale needs to be fixed
- Shadow Gale is not displayed right
- Shadow Gale debuff has to be displayed
- Correct the Spell of the Twilight Hatchlings in SAI Script (Their damage is too high)
- Implement a better GetRandomEgg() method
- implement script text for summoning in the script
*/

#include "ScriptPCH.h"
#include "grim_batol.h"

enum ScriptTexts
{
    SAY_AGGRO                           = -1810000,
    SAY_DEATH                           = -1810001,
    SAY_SUMMON                          = -1810002,
    SAY_GALE                            = -1810003,
    SAY_SLAY                            = -1810004,
};

enum Spells
{
	// Erudax
	SPELL_ENFEEBLING_BLOW				= 75789,
	SPELL_SHADOW_GALE_VISUAL			= 75664,

	// (litte hole at the caster, it is a pre visual aura of shadow gale)
	SPELL_SHADOW_GALE_SPEED_TRIGGER		= 75675,
	SPELL_SHADOW_GALE_DEBUFF			= 75694,

	// Spawns 1 (NH - 40600) or 2 (HC - 48844) Faceless
	SPELL_SPAWN_FACELESS				= 75704,
	SPELL_TWILIGHT_PORTAL_VISUAL		= 95716,

	// In this Script is is casted by the Faceless itself
	SPELL_SHIELD_OF_NIGHTMARE			= 75809,

	SPELL_BINDING_SHADOWS				= 79466, // Wowhead is wrong

	// Faceless
	SPELL_UMBRAL_MENDING				= 79467, // Wowhead is wrong
	SPELL_TWILIGHT_CORRUPTION_DOT		= 93613,
	SPELL_TWILIGHT_CORRUPTION_VISUAL	= 75755, //91049,

	// Alexstraszas Eggs
	SPELL_SUMMON_TWILIGHT_HATCHLINGS = 91058,
};

enum Events
{
	EVENT_ENFEEBLING_BLOW					= 1,
	EVENT_SHADOW_GALE						= 2,
	EVENT_SUMMON_FACELESS					= 3,
	EVENT_REMOVE_TWILIGHT_PORTAL			= 4,
	EVENT_CAST_SHIELD_OF_NIGHTMARE_DELAY	= 5,
	EVENT_BINDING_SHADOWS					= 6,

	EVENT_TRIGGER_GALE_CHECK_PLAYERS		= 7,
};

enum Points
{
	POINT_FACELESS_IS_AT_AN_EGG = 1,
	POINT_ERUDAX_IS_AT_STALKER	= 2,
};

class boss_erudax: public CreatureScript
{
public:
	boss_erudax() : CreatureScript("boss_erudax") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new boss_erudaxAI (creature);
	}

	struct boss_erudaxAI : public ScriptedAI
	{
		boss_erudaxAI(Creature* pCreature) : ScriptedAI(pCreature), ShouldSummonAdds(false)
		{
			pInstance = pCreature->GetInstanceScript();
		}

		Unit* FacelessPortalStalker;
		Unit* ShadowGaleTrigger;

		InstanceScript* pInstance;
		EventMap events;

		bool ShouldSummonAdds;

		void Reset()
		{
			me->GetMotionMaster()->MoveTargetedHome();

			events.Reset();

			ResetMinions();
			RemoveShadowGaleDebuffFromPlayers();
		}

		void EnterCombat(Unit* /*who*/)
		{
			ShouldSummonAdds = false;

			// Fixes wrong behaviour of Erudax if the boss was respawned
			me->SetReactState(REACT_AGGRESSIVE);
			me->GetMotionMaster()->Clear();
			me->GetMotionMaster()->MoveChase(me->getVictim());
			events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, 4000);
			events.ScheduleEvent(EVENT_BINDING_SHADOWS, 9000);
			events.ScheduleEvent(EVENT_SHADOW_GALE, 20000);
			DoScriptText(SAY_AGGRO, me);

			// The Position of the Portal Stalker is the Summon Position of the Adds
			FacelessPortalStalker = me->SummonCreature(NPC_FACELESS_PORTAL_STALKER,-641.515f,-827.8f,235.5f,3.069f,TEMPSUMMON_MANUAL_DESPAWN);

			FacelessPortalStalker->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
		}

		void UpdateAI(const uint32 diff)
		{
			if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
				return;

			if(ShouldSummonAdds)
			{
				// Despawns the Stalker
				DespawnCreatures(NPC_SHADOW_GALE_STALKER);
				RemoveShadowGaleDebuffFromPlayers();

				me->SetReactState(REACT_AGGRESSIVE);
				me->GetMotionMaster()->Clear();
				me->GetMotionMaster()->MoveChase(me->getVictim());

				if ((rand()%2))
					me->MonsterYell(SAY_SUMMON, LANG_UNIVERSAL, NULL);

				//Adds a visual portal effect to the Stalker
				FacelessPortalStalker->GetAI()->DoCast(FacelessPortalStalker,SPELL_TWILIGHT_PORTAL_VISUAL,true);
				events.ScheduleEvent(EVENT_REMOVE_TWILIGHT_PORTAL, 7000);

				//Summons Faceless over the Spell
				FacelessPortalStalker->GetAI()->DoCast(FacelessPortalStalker,SPELL_SPAWN_FACELESS,true);

				ShouldSummonAdds = false;

				// DBM says that the Spell has 40s CD
				events.ScheduleEvent(EVENT_SHADOW_GALE, urand(40000,44000));
			}

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_ENFEEBLING_BLOW:
					DoCastVictim(SPELL_ENFEEBLING_BLOW);
					events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, urand(19000,24000));
					break;

				case EVENT_SHADOW_GALE:
					ShadowGaleTrigger = me->SummonCreature(NPC_SHADOW_GALE_STALKER,-739.665f/*+(urand(0,20)-10)*/,-827.024f/*+(urand(0,20)-10)*/,232.412f,3.1f,TEMPSUMMON_CORPSE_DESPAWN);
					me->SetReactState(REACT_PASSIVE);
					me->GetMotionMaster()->MovePoint(POINT_ERUDAX_IS_AT_STALKER,ShadowGaleTrigger->GetPositionX(),ShadowGaleTrigger->GetPositionY(),ShadowGaleTrigger->GetPositionZ());
                    DoScriptText(SAY_GALE, me);
					break;

				case EVENT_REMOVE_TWILIGHT_PORTAL:
					//Removes Portal effect from Stalker
					FacelessPortalStalker->RemoveAllAuras();
					break;

				case EVENT_BINDING_SHADOWS:

					if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
						DoCast(tempTarget,SPELL_BINDING_SHADOWS);

					events.ScheduleEvent(EVENT_BINDING_SHADOWS, urand(12000,17000));
					break;

				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

		void KilledUnit(Unit* victim)
		{
			DoScriptText(SAY_SLAY, me);
		}

		virtual void JustReachedHome()
		{
			ResetMinions();
		}

		void JustDied(Unit* /*killer*/)
		{
			ResetMinions();
			RemoveShadowGaleDebuffFromPlayers();
			DoScriptText(SAY_DEATH, me);
		}

		void JustSummoned(Creature* summon)
		{
			summon->setActive(true);
		}

		void MovementInform(uint32 type, uint32 id)
		{
			if (type == POINT_MOTION_TYPE)
			{
				switch (id)
				{
				case POINT_ERUDAX_IS_AT_STALKER:

					// if Erudax is not at the Stalkers poision while he is casting
					// the Casting Effect would not displayed right
					DoCast(SPELL_SHADOW_GALE_VISUAL);
					ShouldSummonAdds = true;

					break;

				default:
					break;
				}
			}
		}

	private:
		void ResetMinions()
		{
			DespawnCreatures(NPC_FACELESS);
			DespawnCreatures(NPC_FACELESS_HC);
			DespawnCreatures(NPC_FACELESS_PORTAL_STALKER);
			DespawnCreatures(NPC_TWILIGHT_HATCHLING);
			DespawnCreatures(NPC_SHADOW_GALE_STALKER);
			RespawnEggs();
		}

		void DespawnCreatures(uint32 entry)
		{
			std::list<Creature*> creatures;
			GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

			if (creatures.empty())
				return;

			for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
				(*iter)->DespawnOrUnsummon();
		}

		void RespawnEggs()
		{
			std::list<Creature*> creatures;
			GetCreatureListWithEntryInGrid(creatures, me, NPC_ALEXSTRASZAS_EGG, 1000.0f);

			if (creatures.empty())
				return;

			for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
			{
				if((*iter)->isDead())
					(*iter)->Respawn();

				(*iter)->SetHealth(77500);
				(*iter)->SetMaxHealth(77500);
			}
		}

		void RemoveShadowGaleDebuffFromPlayers()
		{
			Map::PlayerList const &PlayerList =  me->GetMap()->GetPlayers();

			if (!PlayerList.isEmpty())
			{
				for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
						i->getSource()->RemoveAura(SPELL_SHADOW_GALE_DEBUFF);
			}
		}
	};
};

class mob_faceless : public CreatureScript
{
public:
	mob_faceless() : CreatureScript("mob_faceless") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new mob_facelessAI (creature);
	}

	struct mob_facelessAI : public ScriptedAI
	{
		mob_facelessAI(Creature* creature) : ScriptedAI(creature), pTarget(NULL), isAtAnEgg(false), isCastingUmbraMending (false) {}

		Creature* pTarget;
		Unit* pErudax;

		bool isAtAnEgg;
		bool isCastingUmbraMending;

		EventMap events;

		void IsSummonedBy(Unit* summoner)
		{
			pTarget = GetRandomEgg();
			DoZoneInCombat();
            DoScriptText(SAY_SUMMON, summoner);

			if(me->GetMap()->IsHeroic())
				events.ScheduleEvent(EVENT_CAST_SHIELD_OF_NIGHTMARE_DELAY, 3000);

			if(pTarget != NULL)
			{
				me->GetMotionMaster()->MovePoint(POINT_FACELESS_IS_AT_AN_EGG,pTarget->GetPositionX()-4.0f,pTarget->GetPositionY()-4.0f,pTarget->GetPositionZ());
			}

			me->SetReactState(REACT_PASSIVE); // That the Faceless are not running to Players while running to Eggs
		}

		void UpdateAI(const uint32 diff)
		{
			if (pTarget == NULL || !isAtAnEgg || me->HasUnitState(UNIT_STAT_CASTING))
				return;

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_CAST_SHIELD_OF_NIGHTMARE_DELAY:
					DoCast(me, SPELL_SHIELD_OF_NIGHTMARE, true);
					break;

				default:
					break;
				}
			}

			if(isCastingUmbraMending)
			{	// If the Egg is Death and Umbra Mending was casted go to the next Egg
				pTarget = GetNextEgg();

				if(pTarget != NULL) // Solves Crashes if the Faceless killed all eggs
					me->GetMotionMaster()->MovePoint(POINT_FACELESS_IS_AT_AN_EGG,pTarget->GetPositionX(),pTarget->GetPositionY(),pTarget->GetPositionZ());

				isAtAnEgg = false;
				isCastingUmbraMending = false;

				return;
			}

			if(pTarget->isDead())
			{
				if(Unit* pErudax = me->FindNearestCreature(BOSS_ERUDAX,1000.0f, true))
					DoCast(pErudax, SPELL_UMBRAL_MENDING,false);

				isCastingUmbraMending = true;

				return;
			}

			pTarget->AI()->DoZoneInCombat();

			DoCast(pTarget,SPELL_TWILIGHT_CORRUPTION_DOT,true);
			DoCast(pTarget,SPELL_TWILIGHT_CORRUPTION_VISUAL,true);
		}

		void MovementInform(uint32 type, uint32 id)
		{
			if (type == POINT_MOTION_TYPE)
			{
				switch (id)
				{
				case POINT_FACELESS_IS_AT_AN_EGG:
					isAtAnEgg = true;
					break;

				default:
					break;
				}
			}
		}

		void JustDied(Unit* killer)
		{	// Removes the Dot of the Egg if the Faceless dies
			if(isAtAnEgg && pTarget->isAlive())
				pTarget->RemoveAllAuras();
		}

	private:
		Creature* GetRandomEgg()
		{
			// I know that this is looking strange but it works! ^^

			std::list<Creature*> creatures;
			GetCreatureListWithEntryInGrid(creatures, me, NPC_ALEXSTRASZAS_EGG, 300.0f);

			if (creatures.empty())
				return GetNextEgg();

			uint32 c = 0;
			uint32 r = urand(0,creatures.size());

			for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
			{
				if (c == r)
					return (*iter);

				c++;
			}

			return GetNextEgg();
		}

		inline Creature* GetNextEgg()
		{
			return me->FindNearestCreature(NPC_ALEXSTRASZAS_EGG,1000.0f, true);
		}
	};
};

class mob_alexstraszas_eggs : public CreatureScript
{
public:
	mob_alexstraszas_eggs() : CreatureScript("mob_alexstraszas_eggs") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new mob_alexstraszas_eggsAI (creature);
	}

	struct mob_alexstraszas_eggsAI : public ScriptedAI
	{
		mob_alexstraszas_eggsAI(Creature* creature) : ScriptedAI(creature)
		{
			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);

			me->SetReactState(REACT_PASSIVE);
		}

		void JustDied(Unit* killer)
		{	// Summon Twilight Hatchlings
			// Despawn of the Hatchlings is handled by Erudax
			// The behaviour of the hatchlings is handled through SmartAI

			DoCastAOE(SPELL_SUMMON_TWILIGHT_HATCHLINGS, true);
		}

		void JustSummoned(Creature* summon)
		{
			summon->setActive(true);
			summon->AI()->DoZoneInCombat();

			if (GetPlayerAtMinimumRange(0))
				summon->Attack(GetPlayerAtMinimumRange(0), true);
		}
	};
};

class mob_shadow_gale_stalker : public CreatureScript
{
public:
	mob_shadow_gale_stalker() : CreatureScript("mob_shadow_gale_stalker") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new mob_shadow_gale_stalkerAI (creature);
	}

	struct mob_shadow_gale_stalkerAI : public ScriptedAI
	{
		mob_shadow_gale_stalkerAI(Creature* creature) : ScriptedAI(creature), VisualEffectCasted(false) {}

		Unit* pErudax;
		EventMap events;
		bool VisualEffectCasted;

		void IsSummonedBy(Unit* summoner)
		{
			pErudax = summoner;
			me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
			DoCastAOE(SPELL_SHADOW_GALE_SPEED_TRIGGER);
		}

		void UpdateAI(const uint32 diff)
		{
			if(VisualEffectCasted)
			{
				events.Update(diff);

				while (uint32 eventId = events.ExecuteEvent())
				{
					switch (eventId)
					{
					case EVENT_TRIGGER_GALE_CHECK_PLAYERS:

						Map::PlayerList const &PlayerList =  me->GetMap()->GetPlayers();

						if (!PlayerList.isEmpty())
						{
							for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
								if(me->GetDistance(i->getSource()) >= 3)
								{
									// ToDo Add Debuff and Deal damage
									if(!i->getSource()->HasAura(SPELL_SHADOW_GALE_DEBUFF))
										me->CastSpell(i->getSource(), SPELL_SHADOW_GALE_DEBUFF, true);
								}else
									i->getSource()->RemoveAura(SPELL_SHADOW_GALE_DEBUFF);
						}

						events.ScheduleEvent(EVENT_TRIGGER_GALE_CHECK_PLAYERS, 1000);
						break;
					}
				}
			}

			if (me->HasUnitState(UNIT_STAT_CASTING))
				return;

			if(!VisualEffectCasted)
			{
				VisualEffectCasted = true;
				events.ScheduleEvent(EVENT_TRIGGER_GALE_CHECK_PLAYERS, 1000);
			}
		}
	};
};

void AddSC_boss_erudax()
{
	new boss_erudax();
	new mob_faceless();
	new mob_alexstraszas_eggs();
	new mob_shadow_gale_stalker();
}
