/*
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
* Script Complete 80% (or less)
**********/

#include "ScriptPCH.h"
#include "blackrock_caverns.h"

enum Spells
{
	SPELL_CALL_FOR_HELP = 82137,
	SPELL_QUAKE = 75272,
	SPELL_CHAINS_OF_WOE = 75539,
	SPELL_CHAINS_OF_WOE_VISUAL = 75441,
	SPELL_CHAINS_OF_WOE_AURA = 82192,
	SPELL_THE_SKULLCRACKER = 75543,
	SPELL_WOUNDING_STRIKE = 69651,
};

enum Events
{
	EVENT_QUAKE = 1,
	EVENT_CHAINS_OF_WOE = 2,
	EVENT_WOUNDING_STRIKE = 3,
};

class boss_romogg_bonecrusher : public CreatureScript
{
public:
	boss_romogg_bonecrusher() : CreatureScript("boss_romogg_bonecrusher") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new boss_romogg_bonecrusherAI (creature);
	}

	struct boss_romogg_bonecrusherAI : public ScriptedAI
	{
		boss_romogg_bonecrusherAI(Creature* creature) : ScriptedAI(creature), castSkullCracker(false), chainsOfWoe(NULL)
		{
			instance = creature->GetInstanceScript();
		}

		InstanceScript* instance;
		EventMap events;
		bool castSkullCracker;
		Creature* chainsOfWoe;

		void Reset()
		{
			me->GetMotionMaster()->MoveTargetedHome();
			castSkullCracker = false;

			if(chainsOfWoe != NULL)
				chainsOfWoe->DespawnOrUnsummon();

			chainsOfWoe = NULL;

			DespawnCreatures(NPC_ANGERED_EARTH);
		}

		void EnterCombat(Unit* /*who*/)
		{
			me->MonsterYell("Dat's what you get! Noting!", LANG_UNIVERSAL, NULL);

			events.ScheduleEvent(EVENT_QUAKE, 13000);
			events.ScheduleEvent(EVENT_CHAINS_OF_WOE, 17000);
			events.ScheduleEvent(EVENT_WOUNDING_STRIKE, 7000);

			DoCastAOE(SPELL_CALL_FOR_HELP);
		}

		void UpdateAI(const uint32 diff)
		{
			if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
				return;

			if(chainsOfWoe != NULL)
				if(chainsOfWoe->isAlive())
				{
					/* Buggy!

					Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();

					if (!PlayerList.isEmpty())
					{
						for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
							if (!i->getSource()->HasAura(SPELL_CHAINS_OF_WOE_AURA))
								me->CastSpell(i->getSource(),SPELL_CHAINS_OF_WOE_AURA,true);
					}*/
				}else
					{
						chainsOfWoe->DespawnOrUnsummon();
						chainsOfWoe = NULL;
					}

				if(castSkullCracker)
				{
					me->MonsterYell("Stand still! Rom'ogg crack your skulls!", LANG_UNIVERSAL, NULL);

					castSkullCracker = false;
					DoCastAOE(SPELL_THE_SKULLCRACKER);

					return;
				}

				events.Update(diff);

				while (uint32 eventId = events.ExecuteEvent())
				{
					switch (eventId)
					{
					case EVENT_QUAKE:
						DoCastAOE(SPELL_QUAKE);

						if(me->GetMap()->IsHeroic())
						{ // Summon Angered Earth
							Position myPos;
							me->GetPosition(&myPos);

							for(uint8 i=1; i<=5; i++)
								me->SummonCreature(NPC_ANGERED_EARTH,myPos,TEMPSUMMON_CORPSE_DESPAWN);
						}

						events.ScheduleEvent(EVENT_QUAKE, 25000);
						break;
					case EVENT_CHAINS_OF_WOE:

						DoCastAOE(SPELL_CHAINS_OF_WOE);

						castSkullCracker = true;
						events.ScheduleEvent(EVENT_CHAINS_OF_WOE, 20000);
						break;
					case EVENT_WOUNDING_STRIKE:
						DoCastVictim(SPELL_WOUNDING_STRIKE);
						events.ScheduleEvent(EVENT_WOUNDING_STRIKE, 15000);
						break;
					}
				}

				DoMeleeAttackIfReady();
		}

		void JustSummoned(Creature* summon)
		{
			summon->setActive(true);

			if(summon->GetEntry() == NPC_CHAINS_OF_WOE)
			{
				summon->CastSpell(summon, SPELL_CHAINS_OF_WOE_VISUAL, true);
				summon->SetReactState(REACT_PASSIVE);
				chainsOfWoe = summon;
			}else if(summon->GetEntry() == NPC_ANGERED_EARTH)
			{
				summon->GetMotionMaster()->MoveChase(me->getVictim());
			}
		}

		void JustDied(Unit * /*victim*/)
		{
			DespawnCreatures(NPC_ANGERED_EARTH);
			me->MonsterYell("Boss Cho'gall not gonna be happy 'bout dis!", LANG_UNIVERSAL, NULL);

			if(chainsOfWoe != NULL)
				chainsOfWoe->DespawnOrUnsummon();

			chainsOfWoe = NULL;
		}

	private:
		void DespawnCreatures(uint32 entry)
		{
			std::list<Creature*> creatures;
			GetCreatureListWithEntryInGrid(creatures, me, entry, 500.0f);

			if (creatures.empty())
				return;

			for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
				(*iter)->DespawnOrUnsummon();
		}
	};
};

void AddSC_boss_romogg_bonecrusher()
{
	new boss_romogg_bonecrusher();
}