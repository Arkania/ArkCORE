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

/*
Kein Fallschaden buff 87740
Weise Linie 85063

Westen -> Süden 89501
Süden->Westen 89501

*/

#include "throne_of_the_four_winds.h"

#define ENCOUNTERS 2

class instance_throne_of_the_four_winds : public InstanceMapScript
{
public:
	instance_throne_of_the_four_winds() : InstanceMapScript("instance_throne_of_the_four_winds", 754) { }

	InstanceScript* GetInstanceScript(InstanceMap* map) const
	{
		return new instance_throne_of_the_four_winds_InstanceMapScript(map);
	}

	struct instance_throne_of_the_four_winds_InstanceMapScript: public InstanceScript
	{
		instance_throne_of_the_four_winds_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

		uint32 Encounter[ENCOUNTERS];

		uint64 Anshal;
		uint64 Nezir;
		uint64 Rohash;

		uint64 Alakir;

		void Initialize()
		{
			Anshal = 0;
			Nezir = 0;
			Rohash = 0;
			Alakir = 0;

			for (uint8 i = 0 ; i<ENCOUNTERS; ++i)
				Encounter[i] = NOT_STARTED;
		}

		void OnPlayerEnter(Player* player)
		{ // If Conclave of Wind is not DONE check weather they must be spawed
		}

		bool IsEncounterInProgress() const
		{
			for (uint8 i = 0; i < ENCOUNTERS; ++i)
			{
				if (Encounter[i] == IN_PROGRESS)
					return true;
			}
			return false;
		}

		void OnCreatureCreate(Creature* creature, bool )
		{
			switch (creature->GetEntry())
			{
			case BOSS_ANSHAL:
				Anshal = creature->GetGUID();
				break;
			case BOSS_NEZIR:
				Nezir = creature->GetGUID();
				break;
			case BOSS_ROHASH:
				Rohash = creature->GetGUID();
				break;
			case BOSS_ALAKIR:
				Alakir = creature->GetGUID();
				break;
			}
		}

		uint64 getData64(uint32 identifier)
		{
			switch (identifier)
			{
			case DATA_ANSHAL:
				return Anshal;
			case DATA_NEZIR:
				return Nezir;
			case DATA_ROHASH:
				return Rohash;
			case DATA_ALAKIR:
				return Alakir;
			}
			return 0;
		}

		void SetData(uint32 type, uint32 data)
		{
			switch (type)
			{
			case DATA_CONCLAVE_OF_WIND_EVENT:
				Encounter[0] = data;
				break;
			case DATA_ALAKIR_EVENT:
				Encounter[1] = data;
				break;
			}

			if (data == DONE)
				SaveToDB();
		}

		uint32 GetData(uint32 type)
		{
			switch (type)
			{
			case DATA_CONCLAVE_OF_WIND_EVENT:
				return Encounter[0];
			case DATA_ALAKIR_EVENT:
				return Encounter[1];
			}
			return 0;
		}

		std::string GetSaveData()
		{
			OUT_SAVE_INST_DATA;

			std::string str_data;
			std::ostringstream saveStream;
			saveStream << "T W" << Encounter[0] << " " << Encounter[1] << " " << Encounter[2] << " " << Encounter[3];
			str_data = saveStream.str();

			OUT_SAVE_INST_DATA_COMPLETE;
			return str_data;
		}

		void Load(const char* in)
		{
			if (!in)
			{
				OUT_LOAD_INST_DATA_FAIL;
				return;
			}

			OUT_LOAD_INST_DATA(in);

			char dataHead1, dataHead2;
			uint16 data0, data1;

			std::istringstream loadStream(in);
			loadStream >> dataHead1 >> dataHead2 >> data0 >> data1;

			if (dataHead1 == 'T' && dataHead2 == 'W')
			{
				Encounter[0] = data0;
				Encounter[1] = data1;

				for (uint8 i=0; i < ENCOUNTERS; ++i)
					if (Encounter[i] == IN_PROGRESS)
						Encounter[i] = NOT_STARTED;
			}
			else OUT_LOAD_INST_DATA_FAIL;

			OUT_LOAD_INST_DATA_COMPLETE;
		}
	};
};

void AddSC_instance_throne_of_the_four_winds()
{
	new instance_throne_of_the_four_winds();
}