/*
 * Copyright (C) 2010-2011 SkyFire <http://www.projectskyfire.org/>
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
#include "blackwing_descent.h"

#define ENCOUNTERS 10

/* Boss Encounters
------------------
   Arcanotron
   Atramedes
   Chimaeron
   Electron
   Magmatron
   Magmaw
   Maloriak
   Nefarian
   Onyxia
   Toxitron
*/

class instance_blackwing_descent : public InstanceMapScript
{
public:
    instance_blackwing_descent() : InstanceMapScript("instance_blackwing_descent", 669) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_blackwing_descent_InstanceMapScript(map);
    }

    struct instance_blackwing_descent_InstanceMapScript: public InstanceScript
    {
        instance_blackwing_descent_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        uint32 uiEncounter[ENCOUNTERS];

       	uint64 uiArcanotron;
        uint64 uiAtramedes;
        uint64 uiChimaeron;
        uint64 uiElectron;
        uint64 uiMagmatron;
        uint64 uiMagmaw;
        uint64 uiMaloriak;
        uint64 uiNefarian;
        uint64 uiOnyxia;
        uint64 uiToxitron;
        
        void Initialize()
        {
            uiArcanotron = 0;
			uiAtramedes = 0;
			uiChimaeron = 0;
			uiElectron = 0;
			uiMagmatron = 0;
			uiMagmaw = 0;
			uiMaloriak = 0;
			uiNefarian = 0;
			uiOnyxia = 0;
			uiToxitron = 0;
            
        for(uint8 i=0; i < ENCOUNTERS; ++i)
                uiEncounter[i] = NOT_STARTED;
        }

        bool IsEncounterInProgress() const
        {
            for(uint8 i=0; i < ENCOUNTERS; ++i)
            {
                if (uiEncounter[i] == IN_PROGRESS)
                    return true;
            }

            return false;
        }

        void OnCreatureCreate(Creature* pCreature, bool)
        {
            switch(pCreature->GetEntry())
            {
                case NPC_ARCANOTRON:
                    uiArcanotron = pCreature->GetGUID();
                    break;
                case NPC_ATRAMEDES:
                    uiAtramedes = pCreature->GetGUID();
                    break;
                case NPC_CHIMAERON:
                    uiChimaeron = pCreature->GetGUID();
                    break;
				case NPC_ELECTRON:
                    uiElectron = pCreature->GetGUID();
                    break;
				case NPC_MAGMATRON:
                    uiMagmatron = pCreature->GetGUID();
                    break;
				case NPC_MAGMAW:
                    uiMagmaw = pCreature->GetGUID();
                    break;
				case NPC_MALORIAK:
                    uiMaloriak = pCreature->GetGUID();
                    break;
				case NPC_NEFARIAN:
                    uiNefarian = pCreature->GetGUID();
                    break;
				case NPC_ONYXIA:
                    uiOnyxia = pCreature->GetGUID();
                    break;
				case NPC_TOXITRON:
                    uiToxitron = pCreature->GetGUID();
                    break;
            }
        }

	    uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_ARCANOTRON_GUID:
                    return uiArcanotron;
                case DATA_ATRAMEDES:
                    return uiAtramedes;
                case DATA_CHIMAERON:
                    return uiChimaeron;
				case DATA_ELECTRON_GUID:
                    return uiElectron;
				case DATA_MAGMATRON_GUID:
                    return uiMagmatron;
				case DATA_MAGMAW:
                    return uiMagmaw;
				case DATA_MALORIAK:
                    return uiMaloriak;
				case DATA_NEFARIAN:
                    return uiNefarian;
				case DATA_ONYXIA_GUID:
                    return uiOnyxia;
				case DATA_TOXITRON_GUID:
                    return uiToxitron;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case DATA_ARCANOTRON_GUID:
                     uiEncounter[0] = data;
                    break;
                case DATA_ATRAMEDES:
                    uiEncounter[1] = data;
                    break;
                case DATA_CHIMAERON:
                    uiEncounter[2] = data;
					break;
				case DATA_ELECTRON_GUID:
					 uiEncounter[3] = data; 
                    break;
				case DATA_MAGMATRON_GUID:
				     uiEncounter[4] = data;
					break;
				case DATA_MAGMAW:
					uiEncounter[5] = data;
					break;
				case DATA_MALORIAK:
					uiEncounter[6] = data;
					break;
				case DATA_NEFARIAN:
					uiEncounter[7] = data;
					break;
				case DATA_ONYXIA_GUID:
					uiEncounter[8] = data;
					break;
				case DATA_TOXITRON_GUID:
					uiEncounter[9] = data;
					break;
            }

         	if (data == DONE)
             	SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_ARCANOTRON_GUID:
                    return uiEncounter[0];
                case DATA_ATRAMEDES:
                    return uiEncounter[1];
                case DATA_CHIMAERON:
                    return uiEncounter[2];
				case DATA_ELECTRON_GUID:
                    return uiEncounter[3];
				case DATA_MAGMATRON_GUID:
                    return uiEncounter[4];
				case DATA_MAGMAW_EVENT:
                    return uiEncounter[5];
				case DATA_MALORIAK:
                    return uiEncounter[6];
				case DATA_NEFARIAN:
                    return uiEncounter[7];
				case DATA_ONYXIA_GUID:
                    return uiEncounter[8];
				case DATA_TOXITRON_GUID:
                    return uiEncounter[9];
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::string str_data;
            std::ostringstream saveStream;
            saveStream << "V P" << uiEncounter[0] << " " << uiEncounter[1]  << " " << uiEncounter[2];
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
            uint16 data0, data1, data2;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2;

            if (dataHead1 == 'V' && dataHead2 == 'P')
            {
                uiEncounter[0] = data0;
                uiEncounter[1] = data1;
                uiEncounter[2] = data2;

                for(uint8 i=0; i < ENCOUNTERS; ++i)
                    if (uiEncounter[i] == IN_PROGRESS)
                        uiEncounter[i] = NOT_STARTED;
            }
            else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };
};

void AddSC_instance_blackwing_descent()
{
    new instance_blackwing_descent();
}