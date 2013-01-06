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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "CreatureAI.h"
#include "firelands.h"

#define MAX_ENCOUNTER  7

class instance_firelands : public InstanceMapScript
{
public:
	instance_firelands() : InstanceMapScript("instance_firelands", 720) { }

	struct instance_firelands_InstanceMapScript : public InstanceScript
	{
		instance_firelands_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

		uint32 Encounter[MAX_ENCOUNTER];

		// Creatures
		// Bosses
		uint64 uiBethilac;
		uint64 uiRhyolith;
		uint64 uiAlysrazar;
		uint64 uiShannox;
		uint64 uiBaloroc;
		uint64 uiMajordomus;
		uint64 uiRagnaros;

		// Npcs
		uint64 uiRiplimb;
		uint64 uiRageface;
		uint64 uiShannoxSpear;

		// Gameobjects
		uint64 uiBethilacDoor;
		uint64 uiBalorocDoor;
		uint64 uiMajordomoDoor;

		uint64 uiSulfuronBridge;

		// Some Data
		uint32 TeamInInstance;
		uint32 encounterSharingPhase;

		// GameObjects

		// Miscellaneous

		void Initialize()
		{
			SetBossNumber(MAX_ENCOUNTER);

			uiBethilac                 = 0;
			uiRhyolith		           = 0;
			uiAlysrazar		           = 0;
			uiShannox				   = 0;
			uiBaloroc                  = 0;
			uiMajordomus               = 0;
			uiRagnaros                 = 0;

			uiRiplimb				   = 0;
			uiRageface				   = 0;
			uiShannoxSpear			   = 0;

			uiBethilacDoor			   = 0;
			uiBalorocDoor			   = 0;
			uiMajordomoDoor			   = 0;

			uiSulfuronBridge		   = 0;


			for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
				Encounter[i] = NOT_STARTED;
		}

		void OnPlayerEnter(Player* player)
		{
			if (!TeamInInstance)
				TeamInInstance = player->GetTeam();
		}

		bool IsEncounterInProgress() const
		{
			for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
			{
				if (Encounter[i] == IN_PROGRESS)
					return true;
			}

			return false;
		}

		void OnCreatureCreate(Creature* creature)
		{
			if (!TeamInInstance)
			{
				Map::PlayerList const &players = instance->GetPlayers();
				if (!players.isEmpty())
					if (Player* player = players.begin()->getSource())
						TeamInInstance = player->GetTeam();
			}

			switch (creature->GetEntry())
			{
				// Bosses
			case BOSS_BETHTILAC:
				uiBethilac = creature->GetGUID();
				break;
			case BOSS_RHYOLITH:
				uiRhyolith = creature->GetGUID();
				break;
			case BOSS_ALYSRAZAR:
				uiAlysrazar = creature->GetGUID();
				break;
			case BOSS_SHANNOX:
				uiShannox = creature->GetGUID();
				break;
			case BOSS_BALOROC:
				uiBaloroc = creature->GetGUID();
				break;
			case BOSS_MAJORDOMUS:
				uiMajordomus = creature->GetGUID();
				break;
			case BOSS_RAGNAROS_CATA:
				uiRagnaros = creature->GetGUID();
				break;

				// Npcs
			case NPC_RAGEFACE:
				uiRageface = creature->GetGUID();
				break;
			case NPC_RIPLIMB:
				uiRiplimb = creature->GetGUID();
				break;
			case NPC_SHANNOX_SPEAR:
				uiShannoxSpear = creature->GetGUID();
				break;
			}

		}

		void OnGameObjectCreate(GameObject* gameObject)
		{
			switch (gameObject->GetEntry())
			{

			case GOB_DOOR_BETHILAC:
				uiBethilacDoor = gameObject->GetGUID();
				HandleGameObject(uiBethilacDoor,true);
				break;
			
			case GOB_DOOR_BALOROC:
				uiBalorocDoor = gameObject->GetGUID();
				HandleGameObject(uiBalorocDoor, true /* We let the Door open for testing Reasons*/ );
				break;
			
			case GOB_DOOR_MAJORDOMO:
				uiMajordomoDoor = gameObject->GetGUID();
				HandleGameObject(uiMajordomoDoor,GetBossState(DATA_MAJORDOMUS) == DONE);
				break;

			case GOB_SULFURON_BRIDGE:
				uiSulfuronBridge = gameObject->GetGUID();
				HandleGameObject(uiSulfuronBridge,false);
				break;
			}
		}

		void OnGameObjectRemove(GameObject* gameObject)
		{
		}

		void OnCreatureDeath(Creature* creature)
		{
			switch (creature->GetEntry())
			{
			case BOSS_BETHTILAC:
				break;
			case BOSS_RHYOLITH:
			case BOSS_ALYSRAZAR:
			case BOSS_SHANNOX:
			case BOSS_BALOROC:
			case BOSS_MAJORDOMUS:
			case BOSS_RAGNAROS_CATA:
			default:
				break;
			}
		}

		bool SetBossState(uint32 type, EncounterState state)
		{
			if (!InstanceScript::SetBossState(type, state))
				return false;

			switch (type)
			{
			case DATA_BETHTILAC:
				HandleGameObject(uiBethilacDoor, state != IN_PROGRESS);			
				break;
			case DATA_RHYOLITH:
				break;
			case DATA_ALYSRAZAR:
				break;
			case DATA_SHANNOX:
				break;
			case DATA_BALOROC:
				if (type == DONE)
				HandleGameObject(uiBalorocDoor,true);
				break;
			case DATA_MAJORDOMUS:
				if (type == DONE)
				HandleGameObject(uiMajordomoDoor,true);
				break;
			case DATA_RAGNAROS:
				break;

			}

			return true;
		}

		void SetData(uint32 type, uint32 data)
		{
			switch (type)
			{
			case DATA_CURRENT_ENCOUNTER_PHASE:
				encounterSharingPhase = data;
				break;

			default:
				break;
			}

		}

		void SetData64(uint32 /*type*/, uint64 /*data*/)
		{

		}

		uint64 GetData64(uint32 data)
		{
			switch (data)
			{
				// Bosses
			case BOSS_BETHTILAC:
				return uiBethilac;
			case BOSS_RHYOLITH:
				return uiRhyolith;
			case BOSS_ALYSRAZAR:
				return uiAlysrazar;
			case BOSS_SHANNOX:
				return uiShannox;
			case BOSS_BALOROC:
				return uiBaloroc;
			case BOSS_MAJORDOMUS:
				return uiMajordomus;
			case BOSS_RAGNAROS_CATA:
				return uiRagnaros;

				// Npcs
			case NPC_RAGEFACE:
				return uiRageface;
			case NPC_RIPLIMB:
				return uiRiplimb;
			case NPC_SHANNOX_SPEAR:
				return uiShannoxSpear;
			}

			return NULL;
		}

		uint32 GetData(uint32 type)
		{
			switch (type)
			{
			case DATA_CURRENT_ENCOUNTER_PHASE:
				return encounterSharingPhase;
			}

			return 0;
		}

		std::string GetSaveData()
		{
			std::ostringstream saveStream;
			saveStream << "F L ";
			for(int i = 0; i < MAX_ENCOUNTER; ++i)
				saveStream << Encounter[i] << " ";

			return saveStream.str();
		}

		void Load(const char * data)
		{
			std::istringstream loadStream(data);
			char dataHead1, dataHead2;
			loadStream >> dataHead1 >> dataHead2;
			std::string newdata = loadStream.str();

			uint32 buff;
			if(dataHead1 == 'F' && dataHead2 == 'L')
			{
				for(int i = 0; i < MAX_ENCOUNTER; ++i)
				{
					loadStream >> buff;
					Encounter[i]= buff;
				}
			}

			for(int i = 0; i < MAX_ENCOUNTER; ++i)
				if(Encounter[i] != DONE)
					Encounter[i] = NOT_STARTED;
		}

		void Update(uint32 diff)
		{

		}

	};

	InstanceScript* GetInstanceScript(InstanceMap* map) const
	{
		return new instance_firelands_InstanceMapScript(map);
	}
};

void AddSC_instance_firelands()
{
	new instance_firelands();
}
