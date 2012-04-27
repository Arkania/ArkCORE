/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 *
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
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

/* ScriptData
SDName: Instance_Shattered_Halls
SD%Complete: 50
SDComment: currently missing info about door. instance not complete
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

#include "ScriptPCH.h"
#include "shattered_halls.h"

#define MAX_ENCOUNTER  2

#define DOOR_NETHEKURSE     1

class instance_shattered_halls : public InstanceMapScript
{
    public:
        instance_shattered_halls()
            : InstanceMapScript("instance_shattered_halls", 540)
        {
        }
        struct instance_shattered_halls_InstanceMapScript : public InstanceScript
        {
            instance_shattered_halls_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

            uint32 m_auiEncounter[MAX_ENCOUNTER];
            uint64 nethekurseGUID;
            uint64 nethekurseDoorGUID;

            void Initialize()
            {
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

                nethekurseGUID = 0;
                nethekurseDoorGUID = 0;
            }

            void OnGameObjectCreate(GameObject* pGo, bool /*add*/)
            {
                switch (pGo->GetEntry())
                {
                    case DOOR_NETHEKURSE:
                        nethekurseDoorGUID = pGo->GetGUID();
                        break;
                }
            }

            void OnCreatureCreate(Creature* pCreature, bool /*add*/)
            {
                switch (pCreature->GetEntry())
                {
                    case 16807:
                        nethekurseGUID = pCreature->GetGUID();
                        break;
                }
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                    case TYPE_NETHEKURSE:
                        m_auiEncounter[0] = data;
                        break;
                    case TYPE_OMROGG:
                        m_auiEncounter[1] = data;
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case TYPE_NETHEKURSE:
                        return m_auiEncounter[0];
                    case TYPE_OMROGG:
                        return m_auiEncounter[1];
                }
                return 0;
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case DATA_NETHEKURSE:
                        return nethekurseGUID;
                    case DATA_NETHEKURSE_DOOR:
                        return nethekurseDoorGUID;
                }
                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* pMap) const
        {
            return new instance_shattered_halls_InstanceMapScript(pMap);
        }
};

void AddSC_instance_shattered_halls()
{
    new instance_shattered_halls();
}