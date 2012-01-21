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

#include "ScriptPCH.h"
#include "BattlegroundAB.h"
#include "BattlegroundWS.h"
#include "BattlegroundIC.h"
#include "BattlegroundSA.h"

class achievement_school_of_hard_knocks : public AchievementCriteriaScript
{
    public:
        achievement_school_of_hard_knocks() : AchievementCriteriaScript("achievement_school_of_hard_knocks") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            static uint32 const orphanEntries[6] = {14305, 14444, 22818, 22817, 33533, 33532};
            uint32 currentPet = GUID_ENPART(source->GetCritterGUID());
            for (uint8 i = 0; i < 6; ++i)
                if (currentPet == orphanEntries[i])
                    return true;

            return false;
        }
};

class achievement_storm_glory : public AchievementCriteriaScript
{
    public:
        achievement_storm_glory() : AchievementCriteriaScript("achievement_storm_glory") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (source->GetBattlegroundTypeId() != BATTLEGROUND_EY)
                return false;

            Battleground *pEotS = source->GetBattleground();
            if (!pEotS)
                return false;

            return pEotS->IsAllNodesConrolledByTeam(source->GetTeam());
        }
};

class achievement_resilient_victory : public AchievementCriteriaScript
{
    public:
        achievement_resilient_victory() : AchievementCriteriaScript("achievement_resilient_victory") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            Battleground* bg = source->GetBattleground();
            if (!bg)
                return false;

            if (bg->GetTypeID(true) != BATTLEGROUND_AB)
                return false;

            if (!static_cast<BattlegroundAB*>(bg)->IsTeamScores500Disadvantage(source->GetTeam()))
                return false;

            return true;
        }
};

class achievement_bg_control_all_nodes : public AchievementCriteriaScript
{
    public:
        achievement_bg_control_all_nodes() : AchievementCriteriaScript("achievement_bg_control_all_nodes") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            Battleground* bg = source->GetBattleground();
            if (!bg)
                return false;

            if (!bg->IsAllNodesConrolledByTeam(source->GetTeam()))
                return false;

            return true;
        }
};

class achievement_save_the_day : public AchievementCriteriaScript
{
    public:
        achievement_save_the_day() : AchievementCriteriaScript("achievement_save_the_day") { }

        bool OnCheck(Player* source, Unit* target)
        {
            if (!target)
                return false;

            if (Player const* pTarget = target->ToPlayer())
            {
                if (source->GetBattlegroundTypeId() != BATTLEGROUND_WS || !source->GetBattleground())
                    return false;

                BattlegroundWS* pWSG = static_cast<BattlegroundWS*>(source->GetBattleground());
                if (pWSG->GetFlagState(pTarget->GetTeam()) == BG_WS_FLAG_STATE_ON_BASE)
                    return true;
            }
            return false;
        }
};

class achievement_bg_ic_resource_glut : public AchievementCriteriaScript
{
    public:
        achievement_bg_ic_resource_glut() : AchievementCriteriaScript("achievement_bg_ic_resource_glut") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (source->HasAura(SPELL_OIL_REFINERY) && source->HasAura(SPELL_QUARRY))
                return true;

            return false;
        }
};

class achievement_bg_ic_glaive_grave : public AchievementCriteriaScript
{
    public:
        achievement_bg_ic_glaive_grave() : AchievementCriteriaScript("achievement_bg_ic_glaive_grave") { }

        bool OnCheck(Player* source, Unit* target)
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == 35273 || vehicle->GetEntry() == 34802)
                    return true;
            }

            return false;
        }
};

class achievement_bg_ic_mowed_down : public AchievementCriteriaScript
{
    public:
        achievement_bg_ic_mowed_down() : AchievementCriteriaScript("achievement_bg_ic_mowed_down") { }

        bool OnCheck(Player* source, Unit* target)
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == NPC_KEEP_CANNON)
                    return true;
            }

            return false;
        }
};

//class achievement_bg_sa_artillery_veteran : public AchievementCriteriaScript
//{
//    public:
//        achievement_bg_sa_artillery_veteran() : AchievementCriteriaScript("achievement_bg_sa_artillery_veteran") { }
//
//        bool OnCheck(Player* source, Unit* target)
//        {
//            if (Creature* vehicle = source->GetVehicleCreatureBase())
//            {
//                if (vehicle->GetEntry() == NPC_ANTI_PERSONNAL_CANNON)
//                    return true;
//            }
//
//            return false;
//        }
//};
//
//class achievement_bg_sa_artillery_expert : public AchievementCriteriaScript
//{
//    public:
//        achievement_bg_sa_artillery_expert() : AchievementCriteriaScript("achievement_bg_sa_artillery_expert") { }
//
//        bool OnCheck(Player* source, Unit* target)
//        {
//            if (Creature* vehicle = source->GetVehicleCreatureBase())
//            {
//                if (vehicle->GetEntry() != NPC_ANTI_PERSONNAL_CANNON)
//                    return false;
//
//                BattlegroundSA* SA = static_cast<BattlegroundSA*>(source->GetBattleground());
//                return SA->GetPlayerDemolisherScore(source);
//            }
//
//            return false;
//        }
//};
//
//class achievement_bg_sa_drop_it : public AchievementCriteriaScript
//{
//    public:
//        achievement_bg_sa_drop_it() : AchievementCriteriaScript("achievement_bg_sa_drop_it") { }
//
//        enum AchievementData
//        {
//            SPELL_CARRYING_SEAFORIUM = 52418,
//        };
//
//        bool OnCheck(Player* /*source*/, Unit* target)
//        {
//            if (target->HasAura(SPELL_CARRYING_SEAFORIUM))
//                return true;
//
//            return false;
//        }
//};

void AddSC_achievement_scripts()
{
    new achievement_school_of_hard_knocks();
    new achievement_storm_glory();
    new achievement_resilient_victory();
    new achievement_bg_control_all_nodes();
    new achievement_save_the_day();
    new achievement_bg_ic_resource_glut();
    new achievement_bg_ic_glaive_grave();
    new achievement_bg_ic_mowed_down();
//    new achievement_bg_sa_artillery_veteran();
//    new achievement_bg_sa_artillery_expert();
//    new achievement_bg_sa_drop_it();
}
