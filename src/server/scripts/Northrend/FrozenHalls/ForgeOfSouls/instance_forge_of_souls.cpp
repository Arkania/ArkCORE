/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
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

#include "ScriptPCH.h"
#include "forge_of_souls.h"

#define MAX_ENCOUNTER 2

/* Forge of Souls encounters:
0- Bronjahm, The Godfather of Souls
1- The Devourer of Souls
*/

class instance_forge_of_souls : public InstanceMapScript
{
    public:
        instance_forge_of_souls() : InstanceMapScript(FoSScriptName, 632) { }

        struct instance_forge_of_souls_InstanceScript : public InstanceScript
        {
            instance_forge_of_souls_InstanceScript(Map* map) : InstanceScript(map){}

			uint64 uiJainaOrSylvanas1;
			uint64 uiJainaOrSylvanas2;

			uint64 uiKaliraOrElandra;
			uint64 uiLoralenOrKolern;

			uint64 uiChampion1;
			uint64 uiChampion2;

			uint32 uiEncounter[MAX_ENCOUNTER];

			void Initialize()
            {
				for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
					uiEncounter[i] = NOT_STARTED;

                uiBronjahm = 0;
                uiDevourerOfSouls = 0;
            }

            void OnCreatureCreate(Creature* creature)
            {
                Map::PlayerList const &players = instance->GetPlayers();
                if (!players.isEmpty())
				{
					if (Player* player = players.begin()->getSource())
						uiTeamInInstance = player->GetTeam();
				}

                switch (creature->GetEntry())
                {
                    case CREATURE_BRONJAHM:
                        uiBronjahm = creature->GetGUID();
                        break;
                    case CREATURE_DEVOURER:
                        uiDevourerOfSouls = creature->GetGUID();
                        break;
					case NPC_SYLVANAS_PART1:
						if (uiTeamInInstance == ALLIANCE)
							creature->UpdateEntry(NPC_JAINA_PART1, ALLIANCE);
						uiJainaOrSylvanas1 = creature->GetGUID();
						break;
					case NPC_SYLVANAS_PART2:
						if (uiTeamInInstance == ALLIANCE)
							creature->UpdateEntry(NPC_JAINA_PART2, ALLIANCE);
						uiJainaOrSylvanas2 = creature->GetGUID();
						break;
					case NPC_KALIRA:
						if (uiTeamInInstance == ALLIANCE)
							creature->UpdateEntry(NPC_ELANDRA, ALLIANCE);
						uiKaliraOrElandra = creature->GetGUID();
						break;
					case NPC_LORALEN:
						if (uiTeamInInstance == ALLIANCE)
							creature->UpdateEntry(NPC_KORELN, ALLIANCE);
						uiLoralenOrKolern = creature->GetGUID();
						break;
					case NPC_CHAMPION_1_HORDE:
						if (uiTeamInInstance == ALLIANCE)
							creature->UpdateEntry(NPC_CHAMPION_1_ALLIANCE, ALLIANCE);
						uiChampion1 = creature->GetGUID();
						break;
					case NPC_CHAMPION_2_HORDE:
						if (uiTeamInInstance == ALLIANCE)
							creature->UpdateEntry(NPC_CHAMPION_2_ALLIANCE, ALLIANCE);
						uiChampion2 = creature->GetGUID();
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_TEAM_IN_INSTANCE:
                        return uiTeamInInstance;
                    default:
                        break;
                }

                return 0;
            }

            uint64 GetData64(uint32 type)
            {
                switch (type)
                {
                    case DATA_BRONJAHM:
                        return uiBronjahm;
                    case DATA_DEVOURER:
                        return uiDevourerOfSouls;
                    default:
                        break;
                }

                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "F S " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
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

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'F' && dataHead2 == 'S')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            uint64 uiBronjahm;
            uint64 uiDevourerOfSouls;

            uint32 uiTeamInInstance;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_forge_of_souls_InstanceScript(map);
        }
};

void AddSC_instance_forge_of_souls()
{
    new instance_forge_of_souls();
}