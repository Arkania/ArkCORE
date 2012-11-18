/*
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
 
 Orig author = maanuel
 Rcoded & updates by Biglad
 99.8% good!!!!!!
 */

#include "gamePCH.h"
#include "AnticheatMgr.h"
#include "Unit.h"
#include "Chat.h"
#include "SpellMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "../ArkChat/IRCClient.h"

AnticheatMgr::AnticheatMgr()
{
}

AnticheatMgr::~AnticheatMgr()
{
}


void AnticheatMgr::DeletePlayerReport(Player* player)
{
    if (!player->GetSession())
        return;

    CharacterDatabase.PExecute("DELETE FROM players_reports_status WHERE guid IN (SELECT guid FROM characters WHERE account=%u)",player->GetSession()->GetAccountId());
}

void AnticheatMgr::BuildReport(Player* player,uint8 reportType)
{
    if (player->anticheatData.total_reports == 0)
    {
        player->anticheatData.creation_time = time(NULL);
        CharacterDatabase.PExecute("INSERT IGNORE INTO players_reports_status (guid,creation_time) VALUES (%u,%u);",player->GetGUIDLow(),player->anticheatData.creation_time);
        CharacterDatabase.PExecute("INSERT IGNORE INTO players_reports_status2 (guid,creation_time) VALUES (%u,%u);",player->GetGUIDLow(),player->anticheatData.creation_time);
    }
    
    std::string report_type = report_types[reportType];

    player->anticheatData.type_reports[reportType]++;

    uint64 actual_time = time(NULL) - player->anticheatData.creation_time;

    player->anticheatData.average = player->anticheatData.total_reports > 0 ? ((player->anticheatData.average * (player->anticheatData.total_reports)) + actual_time) / (player->anticheatData.total_reports + 1) : 0;
    player->anticheatData.total_reports++;

    CharacterDatabase.PExecute("UPDATE players_reports_status SET %s=%u, total_reports=%u, average=%u WHERE guid=%u",report_type.c_str(),player->anticheatData.type_reports[reportType],player->anticheatData.total_reports,player->anticheatData.average,player->GetGUIDLow());
    CharacterDatabase.PExecute("UPDATE players_reports_status2 SET %s=%u, total_reports=%u, average=%u WHERE guid=%u",report_type.c_str(),player->anticheatData.type_reports[reportType],player->anticheatData.total_reports,player->anticheatData.average,player->GetGUIDLow());

    if (player->anticheatData.total_reports >= sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORTS_INGAME_NOTIFICATION))
    {
        // display warning at the center of the screen, hacky way?
        std::string str = "";
        str = "|cFFFFFC00[AC]|cFF00FFFF[|cFF60FF00" + std::string(player->GetName()) + "|cFF00FFFF] Possible cheater! Type: "+ report_type;
        WorldPacket data(SMSG_NOTIFICATION, (str.size()+1));
        data << str;
        sWorld->SendGlobalGMMessage(&data);
        std::string ircchana = sWorld->AntiCheatWarnChannel;
        std::stringstream ssa;
        // display warning to GMs in IRC.
        ssa << player->GetName();
        ssa << " - Possible cheater!";
        ssa << " - Type: ";
        ssa << report_type;
        if(sIRC.Active == 1)
            sIRC.Send_IRC_Channel(ircchana, sIRC.MakeMsg("\00304,08\037/!\\\037\017\00304 AntiCheat \00304,08\037/!\\\037\017 %s", "%s", ssa.str().c_str()), true);
        
        CharacterDatabase.PExecute("UPDATE players_reports_status SET autojail=(autojail+1) WHERE guid=%u",player->GetGUIDLow());
        CharacterDatabase.PExecute("UPDATE players_reports_status2 SET autojail=(autojail+1) WHERE guid=%u",player->GetGUIDLow());
        player->anticheatData.total_reports = ((player->anticheatData.total_reports-sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORTS_INGAME_NOTIFICATION))+2);
        QueryResult result;
        result = CharacterDatabase.PQuery("SELECT * FROM `players_reports_status` WHERE `guid` = '%u'",player->GetGUIDLow());
        Field *fields = result->Fetch();
        int32 autojail = fields[9].GetInt32();
        // so far never seen a fly,jump,tp hack thats fake one lol)

        if (report_type == "fly_reports" || report_type == "jump_reports" || report_type == "teleportplane_reports" || report_type == "speed_reports")
            autojail = 7; // lol juts to make sure these are very true
        if (report_type == "waterwalk_reports")
            autojail = autojail+1; // may need taking out????
        if (autojail > 2) // 0,1,2,3 - computers start count from 0
        {
        player->TeleportTo(1, 16220.7f, 16398.3f, -64.3786f, 0.825313f);
        player->SetMovement(MOVE_ROOT);
        player->CastSpell(player, 42201, true);  // Eternal Silence
        player->CastSpell(player, 23775, true);  // Stun Forever
        player->CastSpell(player, 9454, true);   // Freeze
        player->CastSpell(player, 45472, true);  // parachute
        //player->ResurrectPlayer(100, false);

        ChatHandler(player->GetSession()).PSendSysMessage("You Have Been Jailed By: The Anti Cheater System.");
        ChatHandler(player->GetSession()).PSendSysMessage("Speak to a GM.");
        ssa << " *** JAILED *** ";
        if(sIRC.Active == 1)
            sIRC.Send_IRC_Channel(ircchana, sIRC.MakeMsg("\00304,08\037/!\\\037\017\00304 AntiCheat \00304,08\037/!\\\037\017 %s", "%s", ssa.str().c_str()), true);
        std::string ircchan = "#";
        ircchan += sIRC._irc_chan[sIRC.anchn].c_str();
        std::stringstream ss;
        ss << player->GetName();
        ss << " <- Has been jailed for using hacks! lol nabs";
        if(sIRC.Active == 1)
            sIRC.Send_IRC_Channel(ircchan, sIRC.MakeMsg("\00304,08\037/!\\\037\017\00304 ArkCORE Watcher \00304,08\037/!\\\037\017 %s", "%s", ss.str().c_str()), true);
        sWorld->SendWorldText(5532, ss.str().c_str());
        }

    }
}

void AnticheatMgr::DisableAnticheatDetection(Player* player, bool teleport)
{
    player->anticheatData.disableACCheck = true;
    player->anticheatData.disableACCheckTimer = (teleport ? 7000 : 5000);
}

void AnticheatMgr::HandleHackDetectionTimer(Player* player,uint32 diffTime)
{
    if (player->anticheatData.disableACCheck)
    {
        if (player->anticheatData.disableACCheckTimer <= diffTime)
        {
            player->anticheatData.disableACCheck = false;
        } else player->anticheatData.disableACCheckTimer -= diffTime;
    }
}

void AnticheatMgr::JumpHackDetection(Player* player, MovementInfo movementInfo,uint32 opcode)
{
    if (player->anticheatData.lastOpcode == MSG_MOVE_JUMP && opcode == MSG_MOVE_JUMP)
    {
        BuildReport(player,JUMP_HACK_REPORT);
        sLog->outError("Jump Hack Detection Player LowGuid %u",player->GetGUIDLow());
    }
}

void AnticheatMgr::WalkOnWaterHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!player->anticheatData.lastMovementInfo.HasMovementFlag(MOVEMENTFLAG_WATERWALKING))
        return;

    if (player->isGameMaster())
        return;

    // if we are a ghost we can walk on water
    if (!player->isAlive())
        return;

    if (
        player->HasAuraType(SPELL_AURA_FEATHER_FALL) || // as is says on tin
        player->HasAuraType(SPELL_AURA_SAFE_FALL) ||    // as is says on tin
        player->HasAuraType(SPELL_AURA_WATER_WALK) ||   // as is says on tin
        player->HasAura(3714) ||                        // path of frost
        player->HasAura(60068) ||                       // path of frost (2)
        player->HasAura(61081) ||                       // path of frost (3)
        player->HasAura(59307) ||                       // glyph path of frost
        player->HasAura(1706) ||                        // levitate
        player->HasAura(57987)                          // Glyph of Levitate
        )
        return;

    sLog->outError("Walk on Water Player LowGuid %u",player->GetGUIDLow());
    BuildReport(player,WALK_WATER_HACK_REPORT);

}

void AnticheatMgr::FlyHackDetection(Player* player, MovementInfo movementInfo)
{
    if (player->isGameMaster())
        return;
        
    if (!player->anticheatData.lastMovementInfo.HasMovementFlag(MOVEMENTFLAG_FLYING))
        return;

    if (player->HasAuraType(SPELL_AURA_FLY) ||
        player->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) ||
        player->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED))
        return;

    if (
        player->HasAura(34480) || // GRAVITY_LAPSE
        player->HasAura(39432) || // GRAVITY_LAPSE_AURA
        player->HasAura(33943) || // Flight Form
        player->HasAura(40120) || // Swift Flight Form
        player->HasAura(73446) || // The Pride Of Kezan: Flight Speed Aura
        player->HasAura(44227) // GRAVITY_LAPSE_FLY
        )
        return;

    sLog->outError("FlyHack Player LowGuid %u",player->GetGUIDLow());
    BuildReport(player,FLY_HACK_REPORT);
    std::string ircchana = sWorld->AntiCheatWarnChannel;
    std::stringstream ssa;
    ssa << player->GetName();
    ssa << " <- Lagging or fly hack!";
    if(sIRC.Active == 1)
        sIRC.Send_IRC_Channel(ircchana, sIRC.MakeMsg("\00304,08\037/!\\\037\017\00304 AntiCheat \00304,08\037/!\\\037\017 %s", "%s", ssa.str().c_str()), true);
}

void AnticheatMgr::TeleportPlaneHackDetection(Player* player, MovementInfo movementInfo)
{
    if (player->anticheatData.lastMovementInfo.pos.GetPositionZ() != 0 ||
        movementInfo.pos.GetPositionZ() != 0)
        return;

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING))
        return;

    if (player->getDeathState() == DEAD_FALLING)
        return;
    float x, y, z;
    player->GetPosition(x, y, z);
    float ground_Z = player->GetMap()->GetHeight(x, y, z);
    float z_diff = fabs(ground_Z - z);

    // we are not really walking there
    if (z_diff > 1.0f)
        BuildReport(player,TELEPORT_PLANE_HACK_REPORT);
}

void AnticheatMgr::StartHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
        return;

    if (player->isGameMaster())
        return;

    if (player->anticheatData.disableACCheck || player->isInFlight() || player->GetTransport() || player->GetVehicle())
    {
        player->anticheatData.lastMovementInfo = movementInfo;
        player->anticheatData.lastOpcode = opcode;
        return;
    }

    SpeedHackDetection(player,movementInfo);
    FlyHackDetection(player,movementInfo);
    WalkOnWaterHackDetection(player,movementInfo);
    JumpHackDetection(player,movementInfo,opcode);
    TeleportPlaneHackDetection(player, movementInfo);

    player->anticheatData.lastMovementInfo = movementInfo;
    player->anticheatData.lastOpcode = opcode;
}


void AnticheatMgr::SpeedHackDetection(Player* player,MovementInfo movementInfo)
{
    // ghosts move faster
    if (!player->isAlive())
        return;
    if (player->isGameMaster())
        return;
   // if (player->IsMounted())
   //     return;
    if (player->HasUnitState(UNIT_STAT_ONVEHICLE))
        return;
    if (player->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
        return;
    if ((player->IsFalling() && player->GetMapId() == 607) || player->IsFalling()) //False postives in SOTA
        return;
    if (player->HasAuraType(SPELL_AURA_FEATHER_FALL) || player->HasAuraType(SPELL_AURA_SAFE_FALL))
        return;


    uint32 distance2D = (uint32)movementInfo.pos.GetExactDist2d(&player->anticheatData.lastMovementInfo.pos);
    uint8 moveType = 0;
    float auraspeed = 0.0f;
    int32 main_speed_mod = 0;
    int32 main_speed_mod_fly = 0;
    float stack_bonus = 0.0f;
    float stack_bonus_fly = 0.0f;
    float non_stack_bonus = 0.0f;
    float main_speed_mod_swim = 0.0f;

    // we need to know HOW is the player moving
    // TO-DO: Should we check the incoming movement flags?
    // of course not the client can modify those ^
    if (player->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
        moveType = MOVE_SWIM;
    else if (player->IsFlying())
        moveType = MOVE_FLIGHT;
    else if (player->HasUnitMovementFlag(MOVEMENTFLAG_WALKING))
        moveType = MOVE_WALK;
    else
        moveType = MOVE_RUN;

    if (moveType == MOVE_SWIM)
    {
        // no need for mount check
        // vashj'ir?
        main_speed_mod_swim = player->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_SWIM_SPEED);
        non_stack_bonus = (100.0f + player->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_SPEED_NOT_STACK)) / 100.0f;
        auraspeed = main_speed_mod_swim + non_stack_bonus;
    }

    if (moveType == MOVE_RUN)
    {
        if (player->IsMounted())
        {
            main_speed_mod = player->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED);
            stack_bonus = player->GetTotalAuraMultiplier(SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS);
            non_stack_bonus = (100.0f + player->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_MOUNTED_SPEED_NOT_STACK)) / 100.0f;
            auraspeed += main_speed_mod + stack_bonus + non_stack_bonus; 
        }
        else
        {
            main_speed_mod = player->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_SPEED);
            stack_bonus = player->GetTotalAuraMultiplier(SPELL_AURA_MOD_SPEED_ALWAYS);
            non_stack_bonus = (100.0f + player->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_SPEED_NOT_STACK)) / 100.0f;
            auraspeed += main_speed_mod + stack_bonus + non_stack_bonus;
        }
    }

    if (moveType == MOVE_FLIGHT)
    {
        // no need for mount check
        main_speed_mod_fly = player->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
        stack_bonus_fly = player->GetTotalAuraMultiplier(SPELL_AURA_MOD_VEHICLE_SPEED_ALWAYS);
        non_stack_bonus = (100.0f + player->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_SPEED_NOT_STACK)) / 100.0f;
        auraspeed += main_speed_mod_fly + stack_bonus_fly + non_stack_bonus;
    }

    // how many yards the player can do in one sec.
    uint32 speedRate = (uint32)(player->GetSpeed(UnitMoveType(moveType)) + movementInfo.j_xyspeed + auraspeed);

    // how long the player took to move to here.
    uint32 timeDiff = getMSTimeDiff(player->anticheatData.lastMovementInfo.time,movementInfo.time);

    if (timeDiff == 0)
        timeDiff = 1;

    // this is the distance doable by the player in 1 sec, using the time done to move to this point.
    //this has changed since 335a was 1000
    uint32 clientSpeedRate = (distance2D * 1000 / timeDiff) + auraspeed;

    //sLog->outError("fallxy %f fallz %f Distance2D %u clientSpeedRate %u speedRate %u auraspeed %u timeDiff %u ",movementInfo.j_xyspeed, movementInfo.j_zspeed,distance2D,clientSpeedRate,speedRate,auraspeed,timeDiff);
    
    // we did the (uint32) cast to accept a margin of tolerance
    if (clientSpeedRate > speedRate)
    {
        if (player->HasSpellCooldown(6544)) //heroic leap
            return;
        BuildReport(player,SPEED_HACK_REPORT);
        sLog->outError("Speed Hack Player LowGuid %u",player->GetGUIDLow());
        std::string ircchana = sWorld->AntiCheatWarnChannel;
        std::stringstream ssa;
        ssa << player->GetName();
        ssa << " <- Lagging or speed hack!";
        if(sIRC.Active == 1)
            sIRC.Send_IRC_Channel(ircchana, sIRC.MakeMsg("\00304,08\037/!\\\037\017\00304 AntiCheat \00304,08\037/!\\\037\017 %s", "%s", ssa.str().c_str()), true);
    }
}
