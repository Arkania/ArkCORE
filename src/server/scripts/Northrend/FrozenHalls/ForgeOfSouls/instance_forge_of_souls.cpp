/*
 * Copyright (C) 2005-2011 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008-2011 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 *
 * Copyright (C) 2010-2011 ProjectSkyfire <http://www.projectskyfire.org/>
 * 
 * Copyright (C) 2011 ArkCORE <http://www.arkania.net/>
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
#include "forge_of_souls.h"

#define MAX_ENCOUNTER 2

/* Forge of Souls encounters:
 0- Bronjahm, The Godfather of Souls
 1- The Devourer of Souls
 */

class instance_forge_of_souls: public InstanceMapScript {
public:
	instance_forge_of_souls() :
			InstanceMapScript(FoSScriptName, 632) {
	}

	struct instance_forge_of_souls_InstanceScript: public InstanceScript {
		instance_forge_of_souls_InstanceScript(Map* map) :
				InstanceScript(map) {
			SetBossNumber(MAX_ENCOUNTER);
			bronjahm = 0;
			devourerOfSouls = 0;

			teamInInstance = 0;
		}

		void OnCreatureCreate(Creature* creature, bool /*add*/) {
			Map::PlayerList const &players = instance->GetPlayers();
			if (!players.isEmpty())
				if (Player* player = players.begin()->getSource())
					teamInInstance = player->GetTeamId();

			switch (creature->GetEntry()) {
			case CREATURE_BRONJAHM:
				bronjahm = creature->GetGUID();
				break;
			case CREATURE_DEVOURER:
				devourerOfSouls = creature->GetGUID();
				break;
			}
		}

		uint32 GetData(uint32 type) {
			switch (type) {
			case DATA_TEAM_IN_INSTANCE:
				return teamInInstance;
			default:
				break;
			}

			return 0;
		}

		uint64 GetData64(uint32 type) {
			switch (type) {
			case DATA_BRONJAHM:
				return bronjahm;
			case DATA_DEVOURER:
				return devourerOfSouls;
			default:
				break;
			}

			return 0;
		}

		std::string GetSaveData() {
			OUT_SAVE_INST_DATA;

			std::ostringstream saveStream;
			saveStream << "F S " << GetBossSaveData();

			OUT_SAVE_INST_DATA_COMPLETE;
			return saveStream.str();
		}

		void Load(const char* in) {
			if (!in) {
				OUT_LOAD_INST_DATA_FAIL;
				return;
			}

			OUT_LOAD_INST_DATA(in);

			char dataHead1, dataHead2;

			std::istringstream loadStream(in);
			loadStream >> dataHead1 >> dataHead2;

			if (dataHead1 == 'F' && dataHead2 == 'S') {
				for (uint8 i = 0; i < MAX_ENCOUNTER; ++i) {
					uint32 tmpState;
					loadStream >> tmpState;
					if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
						tmpState = NOT_STARTED;
					SetBossState(i, EncounterState(tmpState));
				}
			} else
				OUT_LOAD_INST_DATA_FAIL;

			OUT_LOAD_INST_DATA_COMPLETE;
		}

	private:
		uint64 bronjahm;
		uint64 devourerOfSouls;

		uint32 teamInInstance;
	};

	InstanceScript* GetInstanceScript(InstanceMap *map) const {
		return new instance_forge_of_souls_InstanceScript(map);
	}
};

void AddSC_instance_forge_of_souls() {
	new instance_forge_of_souls();
}
