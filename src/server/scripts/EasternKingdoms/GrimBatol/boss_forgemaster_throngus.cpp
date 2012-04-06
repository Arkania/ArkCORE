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

/**********
* Script Coded by Naios
* Script Complete 60% (or less)
**********/

#include "ScriptPCH.h"
#include "grim_batol.h"

#define SAY_AGGRO "You not get through defenses!"
#define SAY_AGGRO1 "You not get through defenses!"
#define SAY_AGGRO2 "Throngus use your corpse on body. Somewhere..."
#define SAY_AGGRO3 "Oh, this gonna HURT!"
#define SAY_DIED "Death... Good choice. Not best choice maybe, but better than fail and live."

enum Spells
{
	// Misc
	SPELL_MIGHTY_STOMP = 74984,
	SPELL_PICK_WEAPON = 75000, // He switches his weapon (DBM Announce)

	// Shield Phase
	SPELL_PERSONAL_PHALANX = 74908,
	SPELL_FLAMING_SHIELD = 90819, // Wowhead is wrong

	SPELL_FLAMING_ARROW = 45101, // Casted by the Archers
	SPELL_FLAMING_ARROW_VISUAL = 74944,

	// Swords Phase
	SPELL_DUAL_BLADES_BUFF = 74981,
	SPELL_TRASH_BUFF = 47480,
	SPELL_DISORIENTING_ROAR = 74976,
	SPELL_BURNING_FLAMES = 90764,

	// Mace Phase
	SPELL_ENCUMBERED = 75007,
	SPELL_IMPALING_SLAM = 75056,
	SPELL_LAVA_PATCH = 90754,
	SPELL_LAVA_PATCH_VISUAL = 90752,
};

enum Events
{
	// General
	EVENT_PICK_WEAPON = 1,
	EVENT_STOMP = 2,

	// Shield Phase
	EVENT_PERSONAL_PHALANX = 3,

	// Swords Phase
	EVENT_DISORIENTING_ROAR = 4,

	// Mace Phase
	EVENT_IMPALING_SLAM = 5,

	// Twilight Archer
	EVENT_ARCHER_SHOOT = 6,
};

enum Weapon
{
	WEAPON_NON		= 0,
	WEAPON_CHOOSING	= 1,
	WEAPON_SHIELD	= 2,
	WEAPON_SWORDS	= 3,
	WEAPON_MACE		= 4,
};

enum Equipment
{
	EQUIPMENT_ID_SHIELD	= 40400,  // Not Blizzlike
	EQUIPMENT_ID_SWORD	= 65094,  // Not Blizzlike
	EQUIPMENT_ID_MACE	= 65090,  // Not Blizzlike
};

// Summon Position of the Twilight Archers that are attacking
// the Playery in the shield Phase (not Blizzlike)
Position const TwilightArcherSummonPos[13] =
{{-542.994f, -605.236f, 300.201f, 1.68049f},
{-543.59f, -605.413f, 283.784f, 1.50377f},
{-521.237f, -605.435f, 300.76f, 1.63886f},
{-483.862f, -588.658f, 297.574f, 2.38106f},
{-482.655f, -588.461f, 280.966f, 2.34571f},
{-471.266f, -575.324f, 295.906f, 2.30254f},
{-525.377f, -455.312f, 285.288f, 4.66187f},
{-544.49f, -454.961f, 295.831f, 4.79539f},
{-522.164f, -455.31f, 299.791f, 4.77575f},
{-468.703f, -489.004f, 300.462f, 3.78616f},
{-470.907f, -484.791f, 282.203f, 3.87255f},
{-485.052f, -474.621f, 296.525f, 3.92361f},
{-481.352f, -477.21f, 280.714f, 3.72334f}};

class boss_forgemaster_throngus: public CreatureScript
{
public:
	boss_forgemaster_throngus() : CreatureScript("boss_forgemaster_throngus") { }

	CreatureAI* GetAI(Creature* pCreature) const
	{
		return new boss_forgemaster_throngusAI (pCreature);
	}

	struct boss_forgemaster_throngusAI : public ScriptedAI
	{
		boss_forgemaster_throngusAI(Creature *c) : ScriptedAI(c) {}

		EventMap events;

		uint32 currentWaepon;
		uint8 phases [3];

		void EnterCombat(Unit* /*who*/)
		{
			me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);

			phases[0] = 0;
			phases[1] = 0;
			phases[2] = 0;
		}

		void JustDied(Unit* /*killer*/)
		{
			me->MonsterYell(SAY_DIED, LANG_UNIVERSAL, NULL);
			DespawnCreatures(NPC_FIRE_PATCH);
			DespawnCreatures(NPC_TWILIGHT_ARCHER);
		}

		void Reset()
		{
			currentWaepon = WEAPON_NON;
			DespawnCreatures(NPC_FIRE_PATCH);
			DespawnCreatures(NPC_TWILIGHT_ARCHER);

			SetEquipmentSlots(false, 0, 0,0);
		}

		void UpdateAI(const uint32 diff)
		{
			if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
				return;

			if(currentWaepon == WEAPON_SHIELD && me->GetMap()->IsHeroic() && (!me->HasAura(SPELL_FLAMING_SHIELD)))
					DoCast(me, SPELL_FLAMING_SHIELD, true);

			if(currentWaepon == WEAPON_NON)
			{
				ResetWeapon();
				currentWaepon = WEAPON_CHOOSING;

				DoCast(SPELL_PICK_WEAPON);

				return;
			}

			if(currentWaepon == WEAPON_CHOOSING)
			{
				// Chooses a new Weapon
				IntializeWeapon();

				events.ScheduleEvent(EVENT_PICK_WEAPON, 30000);

				return;
			}

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch(eventId)
				{
				case EVENT_PICK_WEAPON:
					// It is only need to set the Weapon to WEAPON_NON to switch the Weapon
					currentWaepon = WEAPON_NON;
					break;

				case EVENT_PERSONAL_PHALANX:
					if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
						DoCast(tempTarget, SPELL_PERSONAL_PHALANX);

					events.ScheduleEvent(EVENT_PERSONAL_PHALANX, 10000);
					break;

				case EVENT_IMPALING_SLAM:
					if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
						DoCast(tempTarget, SPELL_IMPALING_SLAM);

					events.ScheduleEvent(EVENT_IMPALING_SLAM, 15000);
					break;

				case EVENT_DISORIENTING_ROAR:

					DoCastAOE(SPELL_DISORIENTING_ROAR);

					events.ScheduleEvent(EVENT_DISORIENTING_ROAR, 11000);
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

		void JustSummoned(Creature* summon)
		{
			//summon->setActive(true);

			summon->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);

			if(summon->GetEntry() == NPC_FIRE_PATCH)
				summon->CastSpell(summon, SPELL_LAVA_PATCH_VISUAL, true);
		}

		void DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/)
		{
			if(currentWaepon != WEAPON_SWORDS || !me->GetMap()->IsHeroic())
				return;

			if(me->GetMap()->IsHeroic() && damage > 0)
				me->CastSpell(me->getVictim(), SPELL_BURNING_FLAMES, true);
		}

	private:
		inline void IntializeWeapon()
		{ // Intialize next Phase
			// Choose Weapon
			currentWaepon = GetNextPhase();

			// If you want to test a single Phase you can overwrite the rand value here
			// currentWaepon = WEAPON_MACE;

			switch(currentWaepon)
			{
			case WEAPON_SHIELD:

				SetEquipmentSlots(false, 0, EQUIPMENT_ID_SHIELD,0);

				if(me->GetMap()->IsHeroic())
					DoCast(me, SPELL_FLAMING_SHIELD, true);

				for(uint32 i = 0; i<=12; i++)
					me->SummonCreature(NPC_TWILIGHT_ARCHER,TwilightArcherSummonPos[i],TEMPSUMMON_MANUAL_DESPAWN);

				events.ScheduleEvent(EVENT_PERSONAL_PHALANX, 10000);

				break;

			case WEAPON_SWORDS:
				DoCast(me, SPELL_DUAL_BLADES_BUFF, true);
				DoCast(me, SPELL_TRASH_BUFF, true);

				SetEquipmentSlots(false, EQUIPMENT_ID_SWORD, EQUIPMENT_ID_SWORD,0);

				events.ScheduleEvent(EVENT_DISORIENTING_ROAR, 11000);

				break;

			case WEAPON_MACE:

				if(me->GetMap()->IsHeroic())
					DoCast(me, SPELL_LAVA_PATCH, true);

				DoCast(me, SPELL_ENCUMBERED, true);

				SetEquipmentSlots(false, EQUIPMENT_ID_MACE, 0,0);

				events.ScheduleEvent(EVENT_IMPALING_SLAM, 7000);

				break;
			}
		}

		inline void ResetWeapon()
		{ // Resets last Phase
			events.Reset();
			DespawnCreatures(NPC_TWILIGHT_ARCHER);

			// Remove Auras spezified to the Phases
			// Shield Phase
			me->RemoveAura(SPELL_FLAMING_SHIELD);
			me->RemoveAura(SPELL_PERSONAL_PHALANX);

			// Swords Phase
			me->RemoveAura(SPELL_DUAL_BLADES_BUFF);
			me->RemoveAura(SPELL_TRASH_BUFF);

			// Mace Phase
			me->RemoveAura(SPELL_LAVA_PATCH);
			me->RemoveAura(SPELL_ENCUMBERED);
		}

		inline uint8 GetNextPhase()
		{	// [100%] Working
			// zit. Wowhead
			// The three weapon phases will switch randomly,
			// but Throngus will always go through all three
			// before he picks the first one again.

			uint8 base[3] = {WEAPON_SHIELD, WEAPON_SWORDS, WEAPON_MACE};

			if (phases[0]==0 && phases[1]==0 && phases[2]==0)
			{ // If Throngus was in every phase or the fight has just begun calculate new phase string
				for(uint8 i = 0; i <= 2; i++)
				{
					while(phases[i] == 0)
					{
						uint8 r = urand(0,2);
						phases[i] = base[r];
						base[r] = 0;
					}
				}

				uint8 v = phases[0];
				phases[0] = 0;
				return v;
			}else
			{ // If Throngus was still in a Phase, just get next Phase
				for(uint8 i = 0; i <= 2; i++)
				{
					if(phases[i] != 0)
					{
						uint8 v = phases[i];
						phases[i] = 0;

						return v;
					}
				}
			}

			// Should not happend but sure is sure
			return urand(WEAPON_SHIELD,WEAPON_MACE);
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
	};
};

class mob_twilight_archer : public CreatureScript
{
public:
	mob_twilight_archer() : CreatureScript("mob_twilight_archer") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new mob_twilight_archerAI (creature);
	}

	struct mob_twilight_archerAI : public ScriptedAI
	{
		mob_twilight_archerAI(Creature* creature) : ScriptedAI(creature)
		{
			creature->SetReactState(REACT_PASSIVE);
		}

		EventMap events;

		void IsSummonedBy(Unit* summoner)
		{
			DoZoneInCombat();

			events.ScheduleEvent(EVENT_ARCHER_SHOOT, urand(1700,2500));
		}

		void UpdateAI(const uint32 diff)
		{
			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch(eventId)
				{
				case EVENT_ARCHER_SHOOT:

					if(Unit* nearPlayer = SelectTarget(SELECT_TARGET_NEAREST, 0, 2, true))
					{
						me->CastSpell(nearPlayer,SPELL_FLAMING_ARROW_VISUAL,true);
						me->CastSpell(nearPlayer,SPELL_FLAMING_ARROW,true);
					}

					events.ScheduleEvent(EVENT_ARCHER_SHOOT, urand(1700,2500));
					break;
				}
			}
		}
	};
};

void AddSC_boss_forgemaster_throngus()
{
	new boss_forgemaster_throngus();
	new mob_twilight_archer();
}