/*
 * Copyright (C) 2005 - 2013 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2013 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2013 ArkCORE <http://www.arkania.net/>
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
#include "vault_of_archavon.h"

#include "OutdoorPvPMgr.h"
#include "OutdoorPvPWG.h"

/* Vault of Archavon encounters:
1 - Archavon the Stone Watcher event
2 - Emalon the Storm Watcher event
3 - Koralon the Flame Watcher event
4 - Toravon the Ice Watcher event
*/

class instance_archavon : public InstanceMapScript
{
    public:
        instance_archavon() : InstanceMapScript("instance_archavon", 624) { }

        struct instance_archavon_InstanceMapScript : public InstanceScript
        {
            instance_archavon_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(MAX_ENCOUNTER);
            }

            uint32 m_auiEncounter[MAX_ENCOUNTER];

            void Initialize()
            {
                EmalonGUID = 0;
                ToravonGUID = 0;
                ArchavonDeath = 0;
                EmalonDeath = 0;
                KoralonDeath = 0;
            }

            void OnPlayerEnter(Player *player)
            {
                if (sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
                {
                    OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197);
                    if (pvpWG && !player->isGameMaster() && player->GetTeamId() != pvpWG->getDefenderTeam())
                        player->CastSpell(player, SPELL_TELEPORT_FORTRESS, true);
                }
            }

            void OnCreatureCreate(Creature* creature, bool /*add*/)
            {
                switch (creature->GetEntry())
                {
                    case CREATURE_EMALON:
                        EmalonGUID = creature->GetGUID();
                        break;
                    case CREATURE_TORAVON:
                        ToravonGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 identifier)
            {
                switch (identifier)
                {
                    case DATA_EMALON:
                        return EmalonGUID;
                    case DATA_TORAVON:
                        return ToravonGUID;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                case DATA_ARCHAVON:
                    m_auiEncounter[0] = data;
                    break;
                case DATA_EMALON:
                    m_auiEncounter[1] = data;
                    break;
                case DATA_KORALON:
                    m_auiEncounter[2] = data;
                    break;
                case DATA_TORAVON:
                    m_auiEncounter[3] = data;
                    break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_ARCHAVON:       return m_auiEncounter[0];
                    case DATA_EMALON:         return m_auiEncounter[1];
                    case DATA_KORALON:        return m_auiEncounter[2];
                    case DATA_TORAVON:        return m_auiEncounter[3];
                }

                return 0;
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS) return true;

                return false;
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state != DONE)
                   return true;

                switch (type)
                {
                    case DATA_ARCHAVON:
                        ArchavonDeath = time(NULL);
                        break;
                    case DATA_EMALON:
                        EmalonDeath = time(NULL);
                        break;
                    case DATA_KORALON:
                        KoralonDeath = time(NULL);
                        break;
                    default:
                        return true;
                }

                // on every death of Archavon, Emalon and Koralon check our achievement
                DoCastSpellOnPlayers(SPELL_EARTH_WIND_FIRE_ACHIEVEMENT_CHECK);

                return true;
            }

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
            {
                switch (criteria_id)
                {
                    case CRITERIA_EARTH_WIND_FIRE_10:
                    case CRITERIA_EARTH_WIND_FIRE_25:
                        if (ArchavonDeath && EmalonDeath && KoralonDeath)
                        {
                            // instance difficulty check is already done in db (achievement_criteria_data)
                            // int() for Visual Studio, compile errors with abs(time_t)
                            return (abs(int(ArchavonDeath-EmalonDeath)) < MINUTE && \
                                abs(int(EmalonDeath-KoralonDeath)) < MINUTE && \
                                abs(int(KoralonDeath-ArchavonDeath)) < MINUTE);
                        }
                        break;
                    default:
                        break;
                }

                return false;
            }

        private:
            uint64 EmalonGUID;
            uint64 ToravonGUID;
            time_t ArchavonDeath;
            time_t EmalonDeath;
            time_t KoralonDeath;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_archavon_InstanceMapScript(map);
        }
};

void AddSC_instance_archavon()
{
    new instance_archavon();
}
