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
#include "azjol_nerub.h"

#define MAX_ENCOUNTER     3

/* Azjol Nerub encounters:
 0 - Krik'thir the Gatewatcher
 1 - Hadronox
 2 - Anub'arak
 */

class instance_azjol_nerub: public InstanceMapScript {
public:
	instance_azjol_nerub() :
			InstanceMapScript("instance_azjol_nerub", 601) {
	}

	struct instance_azjol_nerub_InstanceScript: public InstanceScript {
		instance_azjol_nerub_InstanceScript(Map* pMap) :
				InstanceScript(pMap) {
			Initialize();
		}
		;

		uint64 uiKrikthir;
		uint64 uiHadronox;
		uint64 uiAnubarak;
		uint64 uiWatcherGashra;
		uint64 uiWatcherSilthik;
		uint64 uiWatcherNarjil;
		uint64 uiAnubarakDoor[3];

		uint64 uiKrikthirDoor;

		uint32 auiEncounter[MAX_ENCOUNTER];

		void Initialize() {
			memset(&auiEncounter, 0, sizeof(auiEncounter));
			memset(&uiAnubarakDoor, 0, sizeof(uiAnubarakDoor));

			uiKrikthir = 0;
			uiHadronox = 0;
			uiAnubarak = 0;
			uiWatcherGashra = 0;
			uiWatcherSilthik = 0;
			uiWatcherNarjil = 0;
			uiKrikthirDoor = 0;
		}

		bool IsEncounterInProgress() const {
			for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
				if (auiEncounter[i] == IN_PROGRESS)
					return true;

			return false;
		}

		void OnCreatureCreate(Creature* pCreature, bool /*add*/) {
			switch (pCreature->GetEntry()) {
			case 28684:
				uiKrikthir = pCreature->GetGUID();
				break;
			case 28921:
				uiHadronox = pCreature->GetGUID();
				break;
			case 29120:
				uiAnubarak = pCreature->GetGUID();
				break;
			case 28730:
				uiWatcherGashra = pCreature->GetGUID();
				break;
			case 28731:
				uiWatcherSilthik = pCreature->GetGUID();
				break;
			case 28729:
				uiWatcherNarjil = pCreature->GetGUID();
				break;
			}
		}

		void OnGameObjectCreate(GameObject* pGo, bool /*add*/) {
			switch (pGo->GetEntry()) {
			case 192395:
				uiKrikthirDoor = pGo->GetGUID();
				if (auiEncounter[0] == DONE)
					HandleGameObject(NULL, true, pGo);
				break;
			case 192396:
				uiAnubarakDoor[0] = pGo->GetGUID();
				break;
			case 192397:
				uiAnubarakDoor[1] = pGo->GetGUID();
				break;
			case 192398:
				uiAnubarakDoor[2] = pGo->GetGUID();
				break;
			}
		}

		uint64 GetData64(uint32 identifier) {
			switch (identifier) {
			case DATA_KRIKTHIR_THE_GATEWATCHER:
				return uiKrikthir;
			case DATA_HADRONOX:
				return uiHadronox;
			case DATA_ANUBARAK:
				return uiAnubarak;
			case DATA_WATCHER_GASHRA:
				return uiWatcherGashra;
			case DATA_WATCHER_SILTHIK:
				return uiWatcherSilthik;
			case DATA_WATCHER_NARJIL:
				return uiWatcherNarjil;
			}

			return 0;
		}

		void SetData(uint32 type, uint32 data) {
			switch (type) {
			case DATA_KRIKTHIR_THE_GATEWATCHER_EVENT:
				auiEncounter[0] = data;
				if (data == DONE)
					HandleGameObject(uiKrikthirDoor, true);
				break;
			case DATA_HADRONOX_EVENT:
				auiEncounter[1] = data;
				break;
			case DATA_ANUBARAK_EVENT:
				auiEncounter[2] = data;
				if (data == IN_PROGRESS)
					for (uint8 i = 0; i < 3; ++i)
						HandleGameObject(uiAnubarakDoor[i], false);
				else if (data == NOT_STARTED || data == DONE)
					for (uint8 i = 0; i < 3; ++i)
						HandleGameObject(uiAnubarakDoor[i], true);
				break;
			}

			if (data == DONE) {
				SaveToDB();
			}
		}

		uint32 GetData(uint32 type) {
			switch (type) {
			case DATA_KRIKTHIR_THE_GATEWATCHER_EVENT:
				return auiEncounter[0];
			case DATA_HADRONOX_EVENT:
				return auiEncounter[1];
			case DATA_ANUBARAK_EVENT:
				return auiEncounter[2];
			}

			return 0;
		}

		std::string GetSaveData() {
			OUT_SAVE_INST_DATA;

			std::ostringstream saveStream;
			saveStream << "A N " << auiEncounter[0] << " " << auiEncounter[1]
					<< " " << auiEncounter[2];

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
			uint16 data0, data1, data2;

			std::istringstream loadStream(in);
			loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2;

			if (dataHead1 == 'A' && dataHead2 == 'N') {
				auiEncounter[0] = data0;
				auiEncounter[1] = data1;
				auiEncounter[2] = data2;

				for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
					if (auiEncounter[i] == IN_PROGRESS)
						auiEncounter[i] = NOT_STARTED;
			} else
				OUT_LOAD_INST_DATA_FAIL;

			OUT_LOAD_INST_DATA_COMPLETE;
		}
	};

	InstanceScript* GetInstanceScript(InstanceMap *map) const {
		return new instance_azjol_nerub_InstanceScript(map);
	}
};

void AddSC_instance_azjol_nerub() {
	new instance_azjol_nerub;
}
