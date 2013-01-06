/*
 * Copyright (C) 2005 - 2013 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2013 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2013 ArkCORE <http://www.arkania.net/>
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

#include "gamePCH.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "TicketMgr.h"
#include "Player.h"
#include "AccountMgr.h"
#include "Opcodes.h"
#include "Chat.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "Language.h"
#include "CellImpl.h"
#include "InstanceSaveMgr.h"
#include "Util.h"
#include "Group.h"
#include "ArkChat/IRCClient.h"

#ifdef _DEBUG_VMAPS
#include "VMapFactory.h"
#endif
uint32 testopcode = 0x0000;

void SendTestPacket (uint32 opcodeID, Player* plr)
{
    //Basic SMSG_FORCE_* opcode.
    WorldPacket data;
    data.Initialize(opcodeID, (8 + 4 + 4));
    data.append(plr->GetPackGUID());
    data << uint32(0);
    data << float(100.0f);
    plr->SendMessageToSet(&data, true);
}

bool ChatHandler::HandleOpcodeTestCommand (const char* args)
{
    std::istringstream arg(args);

    std::string command;
    arg >> command;

    if (command == "roster")
    {
        WorldPacket data(SMSG_GUILD_EVENT, 10);
        int ev;
        arg >> ev;
        data << uint8(ev);
        data << uint8(0);

        /*if (param3)
         data << param1 << param2 << param3;
         else if (param2)
         data << param1 << param2;
         else if (param1)
         data << param1;

         if (guid)
         data << uint64(guid);*/
        m_session->SendPacket(&data);
        PSendSysMessage("Sending GUILD EVENT %u", ev);
        return true;
    }

    if (command == "aura")
    {
        int id;
        arg >> id;

        WorldPacket data(SMSG_AURA_UPDATE, 100);
        data.append(m_session->GetPlayer()->GetPackGUID());
        uint8 slot;
        Unit::VisibleAuraMap const * visibleAuras = m_session->GetPlayer()->GetVisibleAuras();
        // lookup for free slots in units visibleAuras
        Unit::VisibleAuraMap::const_iterator itr = visibleAuras->find(0);
        for (uint32 freeSlot = 0; freeSlot < MAX_AURAS; ++itr, ++freeSlot)
        {
            if (itr == visibleAuras->end() || itr->first != freeSlot)
            {
                slot = freeSlot;
                break;
            }
        }
        data << uint8(slot);          // slot

        data << uint32(id);
        data << uint8(16);          // flags
        data << uint8(85);          // caster lvl
        data << uint8(1);          // stack charges

        data.appendPackGUID(m_session->GetPlayer()->GetGUID());

        m_session->SendPacket(&data);
        PSendSysMessage("Sent");
        return true;
    }

    if (command == "reset")
    {
        uint32 opcode = 0;
        if (!arg.eof())
            arg >> std::hex >> opcode;

        testopcode = opcode;
        return true;
    }

    if (command == "jump")
    {
        uint32 jump = 0;
        if (!arg.eof())
            arg >> std::hex >> jump;
        if (jump == 0)
            jump = 0xFF;

        sLog->outString("Performing opcode jump!");
        for (uint32 i = 0; i < jump; i++)
        {
            if (strcmp(LookupOpcodeName(testopcode), "UNKNOWN") == 0)
            {
                PSendSysMessage("Opcode: 0x%.4X - %s", testopcode, LookupOpcodeName(testopcode));
                SendTestPacket(testopcode, m_session->GetPlayer());
            }
            testopcode++;
        }

        PSendSysMessage("Opcodes: 0x%.4X - 0x%.4X", testopcode - jump, testopcode);
        return true;
    }

    if (command == "jumpback")
    {
        uint32 jump = 0;
        if (!arg.eof())
            arg >> std::hex >> jump;
        if (jump == 0)
            jump = 0xFF;

        PSendSysMessage("Performing opcode jumpback!(0x%.4X)", jump);
        testopcode = testopcode - jump;
        return true;
    }

    if (command == "repeat")
    {
        PSendSysMessage("Opcode: 0x%.4X", testopcode);
        SendTestPacket(testopcode, m_session->GetPlayer());
        return true;
    }

    if (command == "back")
    {
        PSendSysMessage("Opcode: 0x%.4X", --testopcode);
        return true;
    }

    if (command == "send")
    {
        if (arg.eof())
            return false;
        uint32 opcode;
        arg >> std::hex >> opcode;

        PSendSysMessage("Opcode: 0x%.4X - %s", opcode, LookupOpcodeName(opcode));
        SendTestPacket(opcode, m_session->GetPlayer());
        return true;
    }

    PSendSysMessage("Opcode: 0x%.4X - %s", testopcode, LookupOpcodeName(testopcode));
    SendTestPacket(testopcode++, m_session->GetPlayer());

    return true;
}

bool ChatHandler::HandleNameAnnounceCommand (const char* args)
{
    WorldPacket data;
    if (!*args)
        return false;

    sWorld->SendWorldText(LANG_ANNOUNCE_COLOR, m_session->GetPlayer()->GetName(), args);
    return true;
}

bool ChatHandler::HandleGMNameAnnounceCommand (const char* args)
{
    WorldPacket data;
    if (!*args)
        return false;

    sWorld->SendGMText(LANG_GM_ANNOUNCE_COLOR, m_session->GetPlayer()->GetName(), args);
    return true;
}

// global announce
bool ChatHandler::HandleAnnounceCommand (const char* args)
{
    if (!*args)
        return false;

    if ((sIRC.BOTMASK & 256) != 0)
	{
		std::string ircchan = "#";
		ircchan += sIRC._irc_chan[sIRC.anchn].c_str();
		sIRC.Send_IRC_Channel(ircchan, sIRC.MakeMsg("\00304,08\037/!\\\037\017\00304 System Message \00304,08\037/!\\\037\017 %s", "%s", args), true);
	}
	
	char buff[2048];
    sprintf(buff, GetArkCoreString(LANG_SYSTEMMESSAGE), args);
    sWorld->SendServerMessage(SERVER_MSG_STRING, buff);
    return true;
}

// announce to logged in GMs
bool ChatHandler::HandleGMAnnounceCommand (const char* args)
{
    if (!*args)
        return false;

    sWorld->SendGMText(LANG_GM_BROADCAST, args);
    return true;
}

//notification player at the screen
bool ChatHandler::HandleNotifyCommand (const char* args)
{
    if (!*args)
        return false;

    std::string str = GetArkCoreString(LANG_GLOBAL_NOTIFY);
    str += args;

    WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
    data << str;
    sWorld->SendGlobalMessage(&data);

    return true;
}

//notification GM at the screen
bool ChatHandler::HandleGMNotifyCommand (const char* args)
{
    if (!*args)
        return false;

    std::string str = GetArkCoreString(LANG_GM_NOTIFY);
    str += args;

    WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
    data << str;
    sWorld->SendGlobalGMMessage(&data);

    return true;
}

//Enable\Dissable GM Mode
bool ChatHandler::HandleGMCommand (const char* args)
{
    if (!*args)
    {
        if (m_session->GetPlayer()->isGameMaster())
            m_session->SendNotification(LANG_GM_ON);
        else
            m_session->SendNotification(LANG_GM_OFF);
        return true;
    }

    std::string argstr = (char*) args;

    if (argstr == "change")
    {
        if (m_session->GetPlayer()->isGameMaster())
            argstr = "off";
        else
            argstr = "on";
    }

    if (argstr == "on")
    {
        m_session->GetPlayer()->SetGameMaster(true);
        m_session->SendNotification(LANG_GM_ON);
        m_session->GetPlayer()->UpdateTriggerVisibility();
#ifdef _DEBUG_VMAPS
        VMAP::IVMapManager *vMapManager = VMAP::VMapFactory::createOrGetVMapManager();
        vMapManager->processCommand("stoplog");
#endif
        return true;
    }

    if (argstr == "off")
    {
        m_session->GetPlayer()->SetGameMaster(false);
        m_session->SendNotification(LANG_GM_OFF);
        m_session->GetPlayer()->UpdateTriggerVisibility();
#ifdef _DEBUG_VMAPS
        VMAP::IVMapManager *vMapManager = VMAP::VMapFactory::createOrGetVMapManager();
        vMapManager->processCommand("startlog");
#endif
        return true;
    }

    SendSysMessage(LANG_USE_BOL);
    SetSentErrorMessage(true);
    return false;
}

// Enables or disables hiding of the staff badge
bool ChatHandler::HandleGMChatCommand (const char* args)
{
    if (!*args)
    {
        if (m_session->GetPlayer()->isGMChat())
            m_session->SendNotification(LANG_GM_CHAT_ON);
        else
            m_session->SendNotification(LANG_GM_CHAT_OFF);
        return true;
    }

    std::string argstr = (char*) args;

    if (argstr == "change")
    {
        if (m_session->GetPlayer()->isGMChat())
            argstr = "off";
        else
            argstr = "on";
    }

    if (argstr == "on")
    {
        m_session->GetPlayer()->SetGMChat(true);
        m_session->SendNotification(LANG_GM_CHAT_ON);
        return true;
    }

    if (argstr == "off")
    {
        m_session->GetPlayer()->SetGMChat(false);
        m_session->SendNotification(LANG_GM_CHAT_OFF);
        return true;
    }

    SendSysMessage(LANG_USE_BOL);
    SetSentErrorMessage(true);
    return false;
}

//Enable\Dissable Invisible mode
bool ChatHandler::HandleGMVisibleCommand (const char* args)
{
    if (!*args)
    {
        PSendSysMessage(LANG_YOU_ARE, m_session->GetPlayer()->isGMVisible() ? GetArkCoreString(LANG_VISIBLE) : GetArkCoreString(LANG_INVISIBLE));
        return true;
    }

    std::string argstr = (char*) args;

    if (argstr == "change")
    {
        if (m_session->GetPlayer()->isGMVisible())
            argstr = "off";
        else
            argstr = "on";
    }

    if (argstr == "on")
    {
        m_session->GetPlayer()->SetGMVisible(true);
        m_session->SendNotification(LANG_INVISIBLE_VISIBLE);
        return true;
    }

    if (argstr == "off")
    {
        m_session->SendNotification(LANG_INVISIBLE_INVISIBLE);
        m_session->GetPlayer()->SetGMVisible(false);
        return true;
    }

    SendSysMessage(LANG_USE_BOL);
    SetSentErrorMessage(true);
    return false;
}

bool ChatHandler::HandleGPSCommand (const char* args)
{
    WorldObject *obj = NULL;
    if (*args)
    {
        uint64 guid = extractGuidFromLink((char*) args);
        if (guid)
            obj = (WorldObject*) ObjectAccessor::GetObjectByTypeMask(*m_session->GetPlayer(), guid, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);

        if (!obj)
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }
    }
    else
    {
        obj = getSelectedUnit();

        if (!obj)
        {
            SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            SetSentErrorMessage(true);
            return false;
        }
    }
    CellPair cell_val = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());
    Cell cell(cell_val);

    uint32 zone_id, area_id;
    obj->GetZoneAndAreaId(zone_id, area_id);

    MapEntry const* mapEntry = sMapStore.LookupEntry(obj->GetMapId());
    AreaTableEntry const* zoneEntry = GetAreaEntryByAreaID(zone_id);
    AreaTableEntry const* areaEntry = GetAreaEntryByAreaID(area_id);

    float zone_x = obj->GetPositionX();
    float zone_y = obj->GetPositionY();

    Map2ZoneCoordinates(zone_x, zone_y, zone_id);

    Map const *map = obj->GetMap();
    float ground_z = map->GetHeight(obj->GetPositionX(), obj->GetPositionY(), MAX_HEIGHT);
    float floor_z = map->GetHeight(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ());

    GridPair p = Trinity::ComputeGridPair(obj->GetPositionX(), obj->GetPositionY());

    // 63? WHY?
    int gx = 63 - p.x_coord;
    int gy = 63 - p.y_coord;

    uint32 have_map = Map::ExistMap(obj->GetMapId(), gx, gy) ? 1 : 0;
    uint32 have_vmap = Map::ExistVMap(obj->GetMapId(), gx, gy) ? 1 : 0;

    if (have_vmap)
    {
        if (map->IsOutdoors(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ()))
            PSendSysMessage("You are outdoors");
        else
            PSendSysMessage("You are indoors");
    }
    else
        PSendSysMessage("no VMAP available for area info");

    PSendSysMessage(LANG_MAP_POSITION, obj->GetMapId(), (mapEntry ? mapEntry->name : "<unknown>"), zone_id, (zoneEntry ? zoneEntry->area_name : "<unknown>"), area_id, (areaEntry ? areaEntry->area_name : "<unknown>"), obj->GetPhaseMask(), obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), obj->GetOrientation(), cell.GridX(), cell.GridY(), cell.CellX(), cell.CellY(), obj->GetInstanceId(), zone_x, zone_y, ground_z, floor_z, have_map, have_vmap);

    LiquidData liquid_status;
    ZLiquidStatus res = map->getLiquidStatus(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), MAP_ALL_LIQUIDS, &liquid_status);
    if (res)
    {
        PSendSysMessage(LANG_LIQUID_STATUS, liquid_status.level, liquid_status.depth_level, liquid_status.type, res);
    }
    return true;
}

//Summon Player
bool ChatHandler::HandleSummonCommand (const char* args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*) args, &target, &target_guid, &target_name))
        return false;

    Player* _player = m_session->GetPlayer();
    if (target == _player || target_guid == _player->GetGUID())
    {
        PSendSysMessage(LANG_CANT_TELEPORT_SELF);
        SetSentErrorMessage(true);
        return false;
    }

    if (target)
    {
        std::string nameLink = playerLink(target_name);
        // check online security
        if (HasLowerSecurity(target, 0))
            return false;

        if (target->IsBeingTeleported())
        {
            PSendSysMessage(LANG_IS_TELEPORTED, nameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        Map* pMap = m_session->GetPlayer()->GetMap();

        if (target->GetVehicle())
            target->ExitVehicle();

        if (pMap->IsBattlegroundOrArena())
        {
            // only allow if gm mode is on
            if (!_player->isGameMaster())
            {
                PSendSysMessage(LANG_CANNOT_GO_TO_BG_GM, nameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
            // if both players are in different bgs
            else if (target->GetBattlegroundId() && m_session->GetPlayer()->GetBattlegroundId() != target->GetBattlegroundId())
                target->LeaveBattleground(false);          // Note: should be changed so target gets no Deserter debuff

            // all's well, set bg id
            // when porting out from the bg, it will be reset to 0
            target->SetBattlegroundId(m_session->GetPlayer()->GetBattlegroundId(), m_session->GetPlayer()->GetBattlegroundTypeId());
            // remember current position as entry point for return at bg end teleportation
            if (!target->GetMap()->IsBattlegroundOrArena())
                target->SetBattlegroundEntryPoint();
        }
        else if (pMap->IsDungeon())
        {
            Map* cMap = target->GetMap();

            if (cMap->Instanceable() && cMap->GetInstanceId() != pMap->GetInstanceId())
                target->UnbindInstance(pMap->GetInstanceId(), target->GetDungeonDifficulty(), true);

            // we are in instance, and can summon only player in our group with us as lead
            if (!m_session->GetPlayer()->GetGroup() || !target->GetGroup() || (target->GetGroup()->GetLeaderGUID() != m_session->GetPlayer()->GetGUID()) || (m_session->GetPlayer()->GetGroup()->GetLeaderGUID() != m_session->GetPlayer()->GetGUID()))
            // the last check is a bit excessive, but let it be, just in case
            {
                PSendSysMessage(LANG_CANNOT_SUMMON_TO_INST, nameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
        }

        PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), "");
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_SUMMONED_BY, playerLink(_player->GetName()).c_str());

        // stop flight if need
        if (target->isInFlight())
        {
            target->GetMotionMaster()->MovementExpired();
            target->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            target->SaveRecallPosition();

        // before GM
        float x, y, z;
        m_session->GetPlayer()->GetClosePoint(x, y, z, target->GetObjectSize());
        target->TeleportTo(m_session->GetPlayer()->GetMapId(), x, y, z, target->GetOrientation());
        target->SetPhaseMask(m_session->GetPlayer()->GetPhaseMask(), true);
    }
    else
    {
        // check offline security
        if (HasLowerSecurity(NULL, target_guid))
            return false;

        std::string nameLink = playerLink(target_name);

        PSendSysMessage(LANG_SUMMONING, nameLink.c_str(), GetArkCoreString(LANG_OFFLINE));

        // in point where GM stay
        Player::SavePositionInDB(m_session->GetPlayer()->GetMapId(), m_session->GetPlayer()->GetPositionX(), m_session->GetPlayer()->GetPositionY(), m_session->GetPlayer()->GetPositionZ(), m_session->GetPlayer()->GetOrientation(), m_session->GetPlayer()->GetZoneId(), target_guid);
    }

    return true;
}

//Teleport to Player
bool ChatHandler::HandleAppearCommand (const char* args)
{
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*) args, &target, &target_guid, &target_name))
        return false;

    Player* _player = m_session->GetPlayer();
    if (target == _player || target_guid == _player->GetGUID())
    {
        SendSysMessage(LANG_CANT_TELEPORT_SELF);
        SetSentErrorMessage(true);
        return false;
    }

    if (target)
    {
        // check online security
        if (HasLowerSecurity(target, 0))
            return false;

        std::string chrNameLink = playerLink(target_name);

        Map* cMap = target->GetMap();
        if (cMap->IsBattlegroundOrArena())
        {
            // only allow if gm mode is on
            if (!_player->isGameMaster())
            {
                PSendSysMessage(LANG_CANNOT_GO_TO_BG_GM, chrNameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
            // if both players are in different bgs
            else if (_player->GetBattlegroundId() && _player->GetBattlegroundId() != target->GetBattlegroundId())
                _player->LeaveBattleground(false);          // Note: should be changed so _player gets no Deserter debuff

            // all's well, set bg id
            // when porting out from the bg, it will be reset to 0
            _player->SetBattlegroundId(target->GetBattlegroundId(), target->GetBattlegroundTypeId());
            // remember current position as entry point for return at bg end teleportation
            if (!_player->GetMap()->IsBattlegroundOrArena())
                _player->SetBattlegroundEntryPoint();
        }
        else if (cMap->IsDungeon())
        {
            // we have to go to instance, and can go to player only if:
            //   1) we are in his group (either as leader or as member)
            //   2) we are not bound to any group and have GM mode on
            if (_player->GetGroup())
            {
                // we are in group, we can go only if we are in the player group
                if (_player->GetGroup() != target->GetGroup())
                {
                    PSendSysMessage(LANG_CANNOT_GO_TO_INST_PARTY, chrNameLink.c_str());
                    SetSentErrorMessage(true);
                    return false;
                }
            }
            else
            {
                // we are not in group, let's verify our GM mode
                if (!_player->isGameMaster())
                {
                    PSendSysMessage(LANG_CANNOT_GO_TO_INST_GM, chrNameLink.c_str());
                    SetSentErrorMessage(true);
                    return false;
                }
            }

            // if the player or the player's group is bound to another instance
            // the player will not be bound to another one
            InstancePlayerBind *pBind = _player->GetBoundInstance(target->GetMapId(), target->GetDifficulty(cMap->IsRaid()));
            if (!pBind)
            {
                Group *group = _player->GetGroup();
                // if no bind exists, create a solo bind
                InstanceGroupBind *gBind = group ? group->GetBoundInstance(target) : NULL;          // if no bind exists, create a solo bind
                if (!gBind)
                    if (InstanceSave * save = sInstanceSaveMgr->GetInstanceSave(target->GetInstanceId()))
                        _player->BindToInstance(save, !save->CanReset());
            }

            if (cMap->IsRaid())
                _player->SetRaidDifficulty(target->GetRaidDifficulty());
            else
                _player->SetDungeonDifficulty(target->GetDungeonDifficulty());
        }

        PSendSysMessage(LANG_APPEARING_AT, chrNameLink.c_str());

        // stop flight if need
        if (_player->isInFlight())
        {
            _player->GetMotionMaster()->MovementExpired();
            _player->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            _player->SaveRecallPosition();

        // to point to see at target with same orientation
        float x, y, z;
        target->GetContactPoint(_player, x, y, z);

        _player->TeleportTo(target->GetMapId(), x, y, z, _player->GetAngle(target), TELE_TO_GM_MODE);
        _player->SetPhaseMask(target->GetPhaseMask(), true);
    }
    else
    {
        // check offline security
        if (HasLowerSecurity(NULL, target_guid))
            return false;

        std::string nameLink = playerLink(target_name);

        PSendSysMessage(LANG_APPEARING_AT, nameLink.c_str());

        // to point where player stay (if loaded)
        float x, y, z, o;
        uint32 map;
        bool in_flight;
        if (!Player::LoadPositionFromDB(map, x, y, z, o, in_flight, target_guid))
            return false;

        // stop flight if need
        if (_player->isInFlight())
        {
            _player->GetMotionMaster()->MovementExpired();
            _player->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            _player->SaveRecallPosition();

        _player->TeleportTo(map, x, y, z, _player->GetOrientation());
    }

    return true;
}

// Teleport player to last position
bool ChatHandler::HandleRecallCommand (const char* args)
{
    Player* target;
    if (!extractPlayerTarget((char*) args, &target))
        return false;

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    if (target->IsBeingTeleported())
    {
        PSendSysMessage(LANG_IS_TELEPORTED, GetNameLink(target).c_str());
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (target->isInFlight())
    {
        target->GetMotionMaster()->MovementExpired();
        target->CleanupAfterTaxiFlight();
    }

    target->TeleportTo(target->m_recallMap, target->m_recallX, target->m_recallY, target->m_recallZ, target->m_recallO);
    return true;
}

//Enable On\OFF all taxi paths
bool ChatHandler::HandleTaxiCheatCommand (const char* args)
{
    if (!*args)
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    std::string argstr = (char*) args;

    Player *chr = getSelectedPlayer();
    if (!chr)
    {
        chr = m_session->GetPlayer();
    }

    // check online security
    else if (HasLowerSecurity(chr, 0))
        return false;

    if (argstr == "on")
    {
        chr->SetTaxiCheater(true);
        PSendSysMessage(LANG_YOU_GIVE_TAXIS, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_TAXIS_ADDED, GetNameLink().c_str());
        return true;
    }

    if (argstr == "off")
    {
        chr->SetTaxiCheater(false);
        PSendSysMessage(LANG_YOU_REMOVE_TAXIS, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_TAXIS_REMOVED, GetNameLink().c_str());

        return true;
    }

    SendSysMessage(LANG_USE_BOL);
    SetSentErrorMessage(true);
    return false;
}

bool ChatHandler::HandleTeleCommand (const char * args)
{
    if (!*args)
        return false;

    Player* _player = m_session->GetPlayer();

    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    GameTele const* tele = extractGameTeleFromLink((char*) args);

    if (!tele)
    {
        SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    if (_player->isInCombat())
    {
        SendSysMessage(LANG_YOU_IN_COMBAT);
        SetSentErrorMessage(true);
        return false;
    }

    MapEntry const * me = sMapStore.LookupEntry(tele->mapId);
    if (!me || me->IsBattlegroundOrArena())
    {
        SendSysMessage(LANG_CANNOT_TELE_TO_BG);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    _player->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
    return true;
}

bool ChatHandler::HandleLookupAreaCommand (const char* args)
{
    if (!*args)
        return false;

    std::string namepart = args;
    std::wstring wnamepart;

    if (!Utf8toWStr(namepart, wnamepart))
        return false;

    bool found = false;
    uint32 count = 0;
    uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    // Search in AreaTable.dbc
    for (uint32 areaflag = 0; areaflag < sAreaStore.GetNumRows(); ++areaflag)
    {
        AreaTableEntry const *areaEntry = sAreaStore.LookupEntry(areaflag);
        if (areaEntry)
        {
            int loc = GetSessionDbcLocale();
            std::string name = areaEntry->area_name;
            if (!name.empty() && Utf8FitTo(name, wnamepart))
            {
                if (maxResults && count++ == maxResults)
                {
                    PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);
                    return true;
                }

                // send area in "id - [name]" format
                std::ostringstream ss;
                if (m_session)
                    ss << areaEntry->ID << " - |cffffffff|Harea:" << areaEntry->ID << "|h[" << name << " " << localeNames[loc] << "]|h|r";
                else
                    ss << areaEntry->ID << " - " << name << " " << localeNames[loc];

                SendSysMessage(ss.str().c_str());

                if (!found)
                    found = true;
            }
        }
    }

    if (!found)
        SendSysMessage(LANG_COMMAND_NOAREAFOUND);

    return true;
}

//Find tele in game_tele order by name
bool ChatHandler::HandleLookupTeleCommand (const char * args)
{
    if (!*args)
    {
        SendSysMessage(LANG_COMMAND_TELE_PARAMETER);
        SetSentErrorMessage(true);
        return false;
    }

    char const* str = strtok((char*) args, " ");
    if (!str)
        return false;

    std::string namepart = str;
    std::wstring wnamepart;

    if (!Utf8toWStr(namepart, wnamepart))
        return false;

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    std::ostringstream reply;
    uint32 count = 0;
    uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);
    bool limitReached = false;

    GameTeleMap const & teleMap = sObjectMgr->GetGameTeleMap();
    for (GameTeleMap::const_iterator itr = teleMap.begin(); itr != teleMap.end(); ++itr)
    {
        GameTele const* tele = &itr->second;

        if (tele->wnameLow.find(wnamepart) == std::wstring::npos)
            continue;

        if (maxResults && count++ == maxResults)
        {
            limitReached = true;
            break;
        }

        if (m_session)
            reply << "  |cffffffff|Htele:" << itr->first << "|h[" << tele->name << "]|h|r\n";
        else
            reply << "  " << itr->first << " " << tele->name << "\n";
    }

    if (reply.str().empty())
        SendSysMessage(LANG_COMMAND_TELE_NOLOCATION);
    else
        PSendSysMessage(LANG_COMMAND_TELE_LOCATION, reply.str().c_str());

    if (limitReached)
        PSendSysMessage(LANG_COMMAND_LOOKUP_MAX_RESULTS, maxResults);

    return true;
}

//Enable\Dissable accept whispers (for GM)
bool ChatHandler::HandleWhispersCommand (const char* args)
{
    if (!*args)
    {
        PSendSysMessage(LANG_COMMAND_WHISPERACCEPTING, m_session->GetPlayer()->isAcceptWhispers() ? GetArkCoreString(LANG_ON) : GetArkCoreString(LANG_OFF));
        return true;
    }

    std::string argstr = (char*) args;

    if (argstr == "change")
    {
        if (m_session->GetPlayer()->isAcceptWhispers())
            argstr = "off";
        else
            argstr = "on";
    }

    // whisper on
    if (argstr == "on")
    {
        m_session->GetPlayer()->SetAcceptWhispers(true);
        SendSysMessage(LANG_COMMAND_WHISPERON);
        return true;
    }

    // whisper off
    if (argstr == "off")
    {
        m_session->GetPlayer()->SetAcceptWhispers(false);
        SendSysMessage(LANG_COMMAND_WHISPEROFF);
        return true;
    }

    SendSysMessage(LANG_USE_BOL);
    SetSentErrorMessage(true);
    return false;
}

//Save all players in the world
bool ChatHandler::HandleSaveAllCommand (const char* /*args*/)
{
    sObjectAccessor->SaveAllPlayers();
    SendSysMessage(LANG_PLAYERS_SAVED);
    return true;
}

//Send mail by command
bool ChatHandler::HandleSendMailCommand (const char* args)
{
    // format: name "subject text" "mail text"
    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget((char*) args, &target, &target_guid, &target_name))
        return false;

    char* tail1 = strtok(NULL, "");
    if (!tail1)
        return false;

    char* msgSubject = extractQuotedArg(tail1);
    if (!msgSubject)
        return false;

    char* tail2 = strtok(NULL, "");
    if (!tail2)
        return false;

    char* msgText = extractQuotedArg(tail2);
    if (!msgText)
        return false;

    // msgSubject, msgText isn't NUL after prev. check
    std::string subject = msgSubject;
    std::string text = msgText;

    // from console show not existed sender
    MailSender sender(MAIL_NORMAL, m_session ? m_session->GetPlayer()->GetGUIDLow() : 0, MAIL_STATIONERY_GM);

    //- TODO: Fix poor design
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    MailDraft(subject, text).SendMailTo(trans, MailReceiver(target, GUID_LOPART(target_guid)), sender);

    CharacterDatabase.CommitTransaction(trans);

    std::string nameLink = playerLink(target_name);
    PSendSysMessage(LANG_MAIL_SENT, nameLink.c_str());
    return true;
}

// teleport player to given game_tele.entry
bool ChatHandler::HandleTeleNameCommand (const char * args)
{
    char* nameStr;
    char* teleStr;
    extractOptFirstArg((char*) args, &nameStr, &teleStr);
    if (!teleStr)
        return false;

    Player* target;
    uint64 target_guid;
    std::string target_name;
    if (!extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
        return false;

    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    GameTele const* tele = extractGameTeleFromLink(teleStr);
    if (!tele)
    {
        SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    /*    MapEntry const * me = sMapStore.LookupEntry(tele->mapId);
     if (!me || me->IsBattlegroundOrArena())
     {
     SendSysMessage(LANG_CANNOT_TELE_TO_BG);
     SetSentErrorMessage(true);
     return false;
     }

     Player *chr = sObjectMgr->GetPlayer(name.c_str());*/

    if (target)
    {
        // check online security
        if (HasLowerSecurity(target, 0))
            return false;

        std::string chrNameLink = playerLink(target_name);

        if (target->IsBeingTeleported() == true)
        {
            PSendSysMessage(LANG_IS_TELEPORTED, chrNameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        PSendSysMessage(LANG_TELEPORTING_TO, chrNameLink.c_str(), "", tele->name.c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_TELEPORTED_TO_BY, GetNameLink().c_str());

        // stop flight if need
        if (target->isInFlight())
        {
            target->GetMotionMaster()->MovementExpired();
            target->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            target->SaveRecallPosition();

        target->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
    }
    else
    {
        // check offline security
        if (HasLowerSecurity(NULL, target_guid))
            return false;

        std::string nameLink = playerLink(target_name);

        PSendSysMessage(LANG_TELEPORTING_TO, nameLink.c_str(), GetArkCoreString(LANG_OFFLINE), tele->name.c_str());
        Player::SavePositionInDB(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation, sMapMgr->GetZoneId(tele->mapId, tele->position_x, tele->position_y, tele->position_z), target_guid);
    }

    return true;
}

//Teleport group to given game_tele.entry
bool ChatHandler::HandleTeleGroupCommand (const char * args)
{
    if (!*args)
        return false;

    Player *player = getSelectedPlayer();
    if (!player)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(player, 0))
        return false;

    // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
    GameTele const* tele = extractGameTeleFromLink((char*) args);
    if (!tele)
    {
        SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    MapEntry const * me = sMapStore.LookupEntry(tele->mapId);
    if (!me || me->IsBattlegroundOrArena())
    {
        SendSysMessage(LANG_CANNOT_TELE_TO_BG);
        SetSentErrorMessage(true);
        return false;
    }

    std::string nameLink = GetNameLink(player);

    Group *grp = player->GetGroup();
    if (!grp)
    {
        PSendSysMessage(LANG_NOT_IN_GROUP, nameLink.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *pl = itr->getSource();

        if (!pl || !pl->GetSession())
            continue;

        // check online security
        if (HasLowerSecurity(pl, 0))
            return false;

        std::string plNameLink = GetNameLink(pl);

        if (pl->IsBeingTeleported())
        {
            PSendSysMessage(LANG_IS_TELEPORTED, plNameLink.c_str());
            continue;
        }

        PSendSysMessage(LANG_TELEPORTING_TO, plNameLink.c_str(), "", tele->name.c_str());
        if (needReportToTarget(pl))
            ChatHandler(pl).PSendSysMessage(LANG_TELEPORTED_TO_BY, nameLink.c_str());

        // stop flight if need
        if (pl->isInFlight())
        {
            pl->GetMotionMaster()->MovementExpired();
            pl->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            pl->SaveRecallPosition();

        pl->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
    }

    return true;
}

//Summon group of player
bool ChatHandler::HandleGroupSummonCommand (const char* args)
{
    Player* target;
    if (!extractPlayerTarget((char*) args, &target))
        return false;

    // check online security
    if (HasLowerSecurity(target, 0))
        return false;

    Group *grp = target->GetGroup();

    std::string nameLink = GetNameLink(target);

    if (!grp)
    {
        PSendSysMessage(LANG_NOT_IN_GROUP, nameLink.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    Map* gmMap = m_session->GetPlayer()->GetMap();
    bool to_instance = gmMap->Instanceable();

    // we are in instance, and can summon only player in our group with us as lead
    if (to_instance && (!m_session->GetPlayer()->GetGroup() || (grp->GetLeaderGUID() != m_session->GetPlayer()->GetGUID()) || (m_session->GetPlayer()->GetGroup()->GetLeaderGUID() != m_session->GetPlayer()->GetGUID())))
    // the last check is a bit excessive, but let it be, just in case
    {
        SendSysMessage(LANG_CANNOT_SUMMON_TO_INST);
        SetSentErrorMessage(true);
        return false;
    }

    for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *pl = itr->getSource();

        if (!pl || pl == m_session->GetPlayer() || !pl->GetSession())
            continue;

        // check online security
        if (HasLowerSecurity(pl, 0))
            return false;

        std::string plNameLink = GetNameLink(pl);

        if (pl->IsBeingTeleported() == true)
        {
            PSendSysMessage(LANG_IS_TELEPORTED, plNameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        if (to_instance)
        {
            Map* plMap = pl->GetMap();

            if (plMap->Instanceable() && plMap->GetInstanceId() != gmMap->GetInstanceId())
            {
                // cannot summon from instance to instance
                PSendSysMessage(LANG_CANNOT_SUMMON_TO_INST, plNameLink.c_str());
                SetSentErrorMessage(true);
                return false;
            }
        }

        PSendSysMessage(LANG_SUMMONING, plNameLink.c_str(), "");
        if (needReportToTarget(pl))
            ChatHandler(pl).PSendSysMessage(LANG_SUMMONED_BY, GetNameLink().c_str());

        // stop flight if need
        if (pl->isInFlight())
        {
            pl->GetMotionMaster()->MovementExpired();
            pl->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            pl->SaveRecallPosition();

        // before GM
        float x, y, z;
        m_session->GetPlayer()->GetClosePoint(x, y, z, pl->GetObjectSize());
        pl->TeleportTo(m_session->GetPlayer()->GetMapId(), x, y, z, pl->GetOrientation());
    }

    return true;
}

bool ChatHandler::HandleGoTaxinodeCommand (const char* args)
{
    Player* _player = m_session->GetPlayer();

    if (!*args)
        return false;

    char* cNodeId = extractKeyFromLink((char*) args, "Htaxinode");
    if (!cNodeId)
        return false;

    int32 i_nodeId = atoi(cNodeId);
    if (!i_nodeId)
        return false;

    TaxiNodesEntry const* node = sTaxiNodesStore.LookupEntry(i_nodeId);
    if (!node)
    {
        PSendSysMessage(LANG_COMMAND_GOTAXINODENOTFOUND, i_nodeId);
        SetSentErrorMessage(true);
        return false;
    }

    if ((node->x == 0.0f && node->y == 0.0f && node->z == 0.0f) || !MapManager::IsValidMapCoord(node->map_id, node->x, node->y, node->z))
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD, node->x, node->y, node->map_id);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    _player->TeleportTo(node->map_id, node->x, node->y, node->z, _player->GetOrientation());
    return true;
}

//teleport at coordinates
bool ChatHandler::HandleGoXYCommand (const char* args)
{
    if (!*args)
        return false;

    Player* _player = m_session->GetPlayer();

    char* px = strtok((char*) args, " ");
    char* py = strtok(NULL, " ");
    char* pmapid = strtok(NULL, " ");

    if (!px || !py)
        return false;

    float x = (float) atof(px);
    float y = (float) atof(py);
    uint32 mapid;
    if (pmapid)
        mapid = (uint32) atoi(pmapid);
    else
        mapid = _player->GetMapId();

    if (!MapManager::IsValidMapCoord(mapid, x, y))
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapid);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    Map const *map = sMapMgr->CreateBaseMap(mapid);
    float z = std::max(map->GetHeight(x, y, MAX_HEIGHT), map->GetWaterLevel(x, y));

    _player->TeleportTo(mapid, x, y, z, _player->GetOrientation());

    return true;
}

//teleport at coordinates, including Z
bool ChatHandler::HandleGoXYZCommand (const char* args)
{
    if (!*args)
        return false;

    Player* _player = m_session->GetPlayer();

    char* px = strtok((char*) args, " ");
    char* py = strtok(NULL, " ");
    char* pz = strtok(NULL, " ");
    char* pmapid = strtok(NULL, " ");

    if (!px || !py || !pz)
        return false;

    float x = (float) atof(px);
    float y = (float) atof(py);
    float z = (float) atof(pz);
    uint32 mapid;
    if (pmapid)
        mapid = (uint32) atoi(pmapid);
    else
        mapid = _player->GetMapId();

    if (!MapManager::IsValidMapCoord(mapid, x, y, z))
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapid);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    _player->TeleportTo(mapid, x, y, z, _player->GetOrientation());

    return true;
}

//teleport at coordinates
bool ChatHandler::HandleGoZoneXYCommand (const char* args)
{
    if (!*args)
        return false;

    Player* _player = m_session->GetPlayer();

    char* px = strtok((char*) args, " ");
    char* py = strtok(NULL, " ");
    char* tail = strtok(NULL, "");

    char* cAreaId = extractKeyFromLink(tail, "Harea");          // string or [name] Shift-click form |color|Harea:area_id|h[name]|h|r

    if (!px || !py)
        return false;

    float x = (float) atof(px);
    float y = (float) atof(py);

    // prevent accept wrong numeric args
    if ((x == 0.0f && *px != '0') || (y == 0.0f && *py != '0'))
        return false;

    uint32 areaid = cAreaId ? (uint32) atoi(cAreaId) : _player->GetZoneId();

    AreaTableEntry const* areaEntry = GetAreaEntryByAreaID(areaid);

    if (x < 0 || x > 100 || y < 0 || y > 100 || !areaEntry)
    {
        PSendSysMessage(LANG_INVALID_ZONE_COORD, x, y, areaid);
        SetSentErrorMessage(true);
        return false;
    }

    // update to parent zone if exist (client map show only zones without parents)
    AreaTableEntry const* zoneEntry = areaEntry->zone ? GetAreaEntryByAreaID(areaEntry->zone) : areaEntry;

    Map const *map = sMapMgr->CreateBaseMap(zoneEntry->mapid);

    if (map->Instanceable())
    {
        PSendSysMessage(LANG_INVALID_ZONE_MAP, areaEntry->ID, areaEntry->area_name[GetSessionDbcLocale()], map->GetId(), map->GetMapName());
        SetSentErrorMessage(true);
        return false;
    }

    Zone2MapCoordinates(x, y, zoneEntry->ID);

    if (!MapManager::IsValidMapCoord(zoneEntry->mapid, x, y))
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, zoneEntry->mapid);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    float z = std::max(map->GetHeight(x, y, MAX_HEIGHT), map->GetWaterLevel(x, y));
    _player->TeleportTo(zoneEntry->mapid, x, y, z, _player->GetOrientation());

    return true;
}

//teleport to grid
bool ChatHandler::HandleGoGridCommand (const char* args)
{
    if (!*args)
        return false;
    Player* _player = m_session->GetPlayer();

    char* px = strtok((char*) args, " ");
    char* py = strtok(NULL, " ");
    char* pmapid = strtok(NULL, " ");

    if (!px || !py)
        return false;

    float grid_x = (float) atof(px);
    float grid_y = (float) atof(py);
    uint32 mapid;
    if (pmapid)
        mapid = (uint32) atoi(pmapid);
    else
        mapid = _player->GetMapId();

    // center of grid
    float x = (grid_x - CENTER_GRID_ID + 0.5f) * SIZE_OF_GRIDS;
    float y = (grid_y - CENTER_GRID_ID + 0.5f) * SIZE_OF_GRIDS;

    if (!MapManager::IsValidMapCoord(mapid, x, y))
    {
        PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapid);
        SetSentErrorMessage(true);
        return false;
    }

    // stop flight if need
    if (_player->isInFlight())
    {
        _player->GetMotionMaster()->MovementExpired();
        _player->CleanupAfterTaxiFlight();
    }
    // save only in non-flight case
    else
        _player->SaveRecallPosition();

    Map const *map = sMapMgr->CreateBaseMap(mapid);
    float z = std::max(map->GetHeight(x, y, MAX_HEIGHT), map->GetWaterLevel(x, y));
    _player->TeleportTo(mapid, x, y, z, _player->GetOrientation());

    return true;
}
