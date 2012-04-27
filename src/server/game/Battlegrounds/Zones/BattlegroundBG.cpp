/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
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

#include "gamePCH.h"
#include "World.h"
#include "WorldPacket.h"
#include "ObjectMgr.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "BattlegroundBG.h"
#include "Creature.h"
#include "Language.h"
#include "Object.h"
#include "Player.h"
#include "Util.h"

// these variables aren't used outside of this file, so declare them only here
uint32 BG_BG_HonorScoreTicks[BG_HONOR_MODE_NUM] =
{ 330,          // normal honor
200          // holiday
};

BattlegroundBG::BattlegroundBG ()
{
    m_BuffChange = true;
    m_BgObjects.resize(BG_BG_OBJECT_MAX);
    m_BgCreatures.resize(BG_BG_ALL_NODES_COUNT + 5);          //+5 for aura triggers

    m_StartMessageIds[BG_STARTING_EVENT_FIRST] = LANG_BG_BG_START_TWO_MINUTES;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_BG_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD] = LANG_BG_BG_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_BG_HAS_BEGUN;
}

BattlegroundBG::~BattlegroundBG ()
{
}

void BattlegroundBG::Update (uint32 diff)
{
    Battleground::Update(diff);

    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        int team_points[BG_TEAMS_COUNT] =
        { 0, 0 };

        for (int node = 0; node < BG_BG_DYNAMIC_NODES_COUNT; ++node)
        {
            // 3 sec delay to spawn new banner instead previous despawned one
            if (m_BannerTimers[node].timer)
            {
                if (m_BannerTimers[node].timer > diff)
                    m_BannerTimers[node].timer -= diff;
                else
                {
                    m_BannerTimers[node].timer = 0;
                    _CreateBanner(node, m_BannerTimers[node].type, m_BannerTimers[node].teamIndex, false);
                }
            }

            // 1-minute to occupy a node from contested state
            if (m_NodeTimers[node])
            {
                if (m_NodeTimers[node] > diff)
                    m_NodeTimers[node] -= diff;
                else
                {
                    m_NodeTimers[node] = 0;
                    // Change from contested to occupied !
                    uint8 teamIndex = m_Nodes[node] - 1;
                    m_prevNodes[node] = m_Nodes[node];
                    m_Nodes[node] += 2;
                    // burn current contested banner
                    _DelBanner(node, BG_BG_NODE_TYPE_CONTESTED, teamIndex);
                    // create new occupied banner
                    _CreateBanner(node, BG_BG_NODE_TYPE_OCCUPIED, teamIndex, true);
                    _SendNodeUpdate(node);
                    _NodeOccupied(node, (teamIndex == 0) ? ALLIANCE : HORDE);
                    // Message to chatlog

                    if (teamIndex == 0)
                    {
                        // FIXME: team and node names not localized
                        SendMessage2ToAll(LANG_BG_AB_NODE_TAKEN, CHAT_MSG_BG_SYSTEM_ALLIANCE, NULL, LANG_BG_AB_ALLY, _GetNodeNameId(node));
                        PlaySoundToAll(BG_BG_SOUND_NODE_CAPTURED_ALLIANCE);
                    }
                    else
                    {
                        // FIXME: team and node names not localized
                        SendMessage2ToAll(LANG_BG_AB_NODE_TAKEN, CHAT_MSG_BG_SYSTEM_HORDE, NULL, LANG_BG_AB_HORDE, _GetNodeNameId(node));
                        PlaySoundToAll(BG_BG_SOUND_NODE_CAPTURED_HORDE);
                    }
                }
            }

            for (int team = 0; team < BG_TEAMS_COUNT; ++team)
                if (m_Nodes[node] == team + BG_BG_NODE_TYPE_OCCUPIED)
                    ++team_points[team];
        }

        // Accumulate points
        for (int team = 0; team < BG_TEAMS_COUNT; ++team)
        {
            int points = team_points[team];
            if (!points)
                continue;
            m_lastTick[team] += diff;
            if (m_lastTick[team] > BG_BG_TickIntervals[points])
            {
                m_lastTick[team] -= BG_BG_TickIntervals[points];
                m_TeamScores[team] += BG_BG_TickPoints[points];
                m_HonorScoreTics[team] += BG_BG_TickPoints[points];
                if (!m_IsInformedNearVictory && m_TeamScores[team] > BG_BG_WARNING_NEAR_VICTORY_SCORE)
                {
                    if (team == BG_TEAM_ALLIANCE)
                        SendMessageToAll(LANG_BG_AB_A_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                    else
                        SendMessageToAll(LANG_BG_AB_H_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                    PlaySoundToAll(BG_BG_SOUND_NEAR_VICTORY);
                    m_IsInformedNearVictory = true;
                }

                if (m_TeamScores[team] > BG_BG_MAX_TEAM_SCORE)
                    m_TeamScores[team] = BG_BG_MAX_TEAM_SCORE;
                if (team == BG_TEAM_ALLIANCE)
                    UpdateWorldState(BG_BG_OP_RESOURCES_ALLY, m_TeamScores[team]);
                if (team == BG_TEAM_HORDE)
                    UpdateWorldState(BG_BG_OP_RESOURCES_HORDE, m_TeamScores[team]);
                // update achievement flags
                // we increased m_TeamScores[team] so we just need to check if it is 500 more than other teams resources
                uint8 otherTeam = (team + 1) % BG_TEAMS_COUNT;
                if (m_TeamScores[team] > m_TeamScores[otherTeam] + 500)
                    m_TeamScores500Disadvantage[otherTeam] = true;
            }
        }

        // Test win condition
        if (m_TeamScores[BG_TEAM_ALLIANCE] >= BG_BG_MAX_TEAM_SCORE)
            EndBattleground(ALLIANCE);
        if (m_TeamScores[BG_TEAM_HORDE] >= BG_BG_MAX_TEAM_SCORE)
            EndBattleground(HORDE);
    }
}

void BattlegroundBG::StartingEventCloseDoors ()
{
    // despawn banners, auras and buffs
    for (int obj = BG_BG_OBJECT_BANNER_NEUTRAL; obj < BG_BG_DYNAMIC_NODES_COUNT * 8; ++obj)
        SpawnBGObject(obj, RESPAWN_ONE_DAY);
    for (int i = 0; i < BG_BG_DYNAMIC_NODES_COUNT * 3; ++i)
        SpawnBGObject(BG_BG_OBJECT_SPEEDBUFF_LIGHTHOUSE + i, RESPAWN_ONE_DAY);

    // Starting doors
    DoorClose(BG_BG_OBJECT_GATE_A);
    DoorClose(BG_BG_OBJECT_GATE_H);
    SpawnBGObject(BG_BG_OBJECT_GATE_A, RESPAWN_IMMEDIATELY);
    SpawnBGObject(BG_BG_OBJECT_GATE_H, RESPAWN_IMMEDIATELY);

    // Starting base spirit guides
    _NodeOccupied(BG_BG_SPIRIT_ALIANCE, ALLIANCE);
    _NodeOccupied(BG_BG_SPIRIT_HORDE, HORDE);
}

void BattlegroundBG::StartingEventOpenDoors ()
{
    // spawn neutral banners
    for (int banner = BG_BG_OBJECT_BANNER_NEUTRAL, i = 0; i < 3; banner += 8, ++i)
        SpawnBGObject(banner, RESPAWN_IMMEDIATELY);
    for (int i = 0; i < BG_BG_DYNAMIC_NODES_COUNT; ++i)
    {
        //randomly select buff to spawn
        uint8 buff = urand(0, 2);
        SpawnBGObject(BG_BG_OBJECT_SPEEDBUFF_LIGHTHOUSE + buff + i * 3, RESPAWN_IMMEDIATELY);
    }
    DoorOpen(BG_BG_OBJECT_GATE_A);
    DoorOpen(BG_BG_OBJECT_GATE_H);
}

void BattlegroundBG::AddPlayer (Player *plr)
{
    Battleground::AddPlayer(plr);
    //create score and add it to map, default values are set in the constructor
    BattlegroundBGScore* sc = new BattlegroundBGScore;

    m_PlayerScores[plr->GetGUID()] = sc;
}

void BattlegroundBG::RemovePlayer (Player * /*plr*/, uint64 /*guid*/)
{
}

void BattlegroundBG::HandleAreaTrigger (Player *Source, uint32 Trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
    //Area triggers are not handled yet!
    return;

    switch (Trigger)
    {
    case 3866:          // Lighthouse
    case 3869:          // Watterwork
    case 3867:          // Mine
    case 4020:          // Unk1
    case 4021:          // Unk2
        //break;
    default:
        sLog->outError("WARNING: Unhandled AreaTrigger in Battleground: %u", Trigger);
        Source->GetSession()->SendAreaTriggerMessage("Warning: Unhandled AreaTrigger in Battleground: %u", Trigger);
        break;
    }
}

/*  type: 0-neutral, 1-contested, 3-occupied
 teamIndex: 0-ally, 1-horde                        */
void BattlegroundBG::_CreateBanner (uint8 node, uint8 type, uint8 teamIndex, bool delay)
{
    // Just put it into the queue
    if (delay)
    {
        m_BannerTimers[node].timer = 2000;
        m_BannerTimers[node].type = type;
        m_BannerTimers[node].teamIndex = teamIndex;
        return;
    }

    uint8 obj = node * 8 + type + teamIndex;

    SpawnBGObject(obj, RESPAWN_IMMEDIATELY);

    // handle aura with banner
    if (!type)
        return;
    obj = node * 8 + ((type == BG_BG_NODE_TYPE_OCCUPIED) ? (3 + teamIndex) : 5);
    SpawnBGObject(obj, RESPAWN_IMMEDIATELY);
}

void BattlegroundBG::_DelBanner (uint8 node, uint8 type, uint8 teamIndex)
{
    uint8 obj = node * 8 + type + teamIndex;
    SpawnBGObject(obj, RESPAWN_ONE_DAY);

    // handle aura with banner
    if (!type)
        return;
    obj = node * 8 + ((type == BG_BG_NODE_TYPE_OCCUPIED) ? (3 + teamIndex) : 5);
    SpawnBGObject(obj, RESPAWN_ONE_DAY);
}

int32 BattlegroundBG::_GetNodeNameId (uint8 node)
{
    switch (node)
    {
    case BG_BG_NODE_WATERWORKS:
        return LANG_BG_BG_NODE_WATERWORKS;
    case BG_BG_NODE_LIGHTHOUSE:
        return LANG_BG_BG_NODE_LIGHTHOUSE;
    case BG_BG_NODE_MINE:
        return LANG_BG_BG_NODE_MINE;
    default:
        ASSERT(0)
        ;
    }
    return 0;
}

void BattlegroundBG::FillInitialWorldStates (WorldPacket& data)
{
    const uint8 plusArray[] =
    { 0, 2, 3, 0, 1 };

    // Node icons
    for (uint8 node = 0; node < BG_BG_DYNAMIC_NODES_COUNT; ++node)
        data << uint32(BG_BG_OP_NODEICONS[node]) << uint32((m_Nodes[node] == 0) ? 1 : 0);

    // Node occupied states
    for (uint8 node = 0; node < BG_BG_DYNAMIC_NODES_COUNT; ++node)
        for (uint8 i = 1; i < BG_BG_DYNAMIC_NODES_COUNT; ++i)
            data << uint32(BG_BG_OP_NODESTATES[node] + plusArray[i]) << uint32((m_Nodes[node] == i) ? 1 : 0);

    // How many bases each team owns
    uint8 ally = 0, horde = 0;
    for (uint8 node = 0; node < BG_BG_DYNAMIC_NODES_COUNT; ++node)
        if (m_Nodes[node] == BG_BG_NODE_STATUS_ALLY_OCCUPIED)
            ++ally;
        else if (m_Nodes[node] == BG_BG_NODE_STATUS_HORDE_OCCUPIED)
            ++horde;

    data << uint32(BG_BG_OP_OCCUPIED_BASES_ALLY) << uint32(ally);
    data << uint32(BG_BG_OP_OCCUPIED_BASES_HORDE) << uint32(horde);

    // Team scores
    data << uint32(BG_BG_OP_RESOURCES_MAX) << uint32(BG_BG_MAX_TEAM_SCORE);
    data << uint32(BG_BG_OP_RESOURCES_WARNING) << uint32(BG_BG_WARNING_NEAR_VICTORY_SCORE);
    data << uint32(BG_BG_OP_RESOURCES_ALLY) << uint32(m_TeamScores[BG_TEAM_ALLIANCE]);
    data << uint32(BG_BG_OP_RESOURCES_HORDE) << uint32(m_TeamScores[BG_TEAM_HORDE]);

    // other unknown
    data << uint32(0x745) << uint32(0x2);          // 37 1861 unk
}

void BattlegroundBG::_SendNodeUpdate (uint8 node)
{
    // Send node owner state update to refresh map icons on client
    const uint8 plusArray[] =
    { 0, 2, 3, 0, 1 };

    if (m_prevNodes[node])
        UpdateWorldState(BG_BG_OP_NODESTATES[node] + plusArray[m_prevNodes[node]], 0);
    else
        UpdateWorldState(BG_BG_OP_NODEICONS[node], 0);

    UpdateWorldState(BG_BG_OP_NODESTATES[node] + plusArray[m_Nodes[node]], 1);

    // How many bases each team owns
    uint8 ally = 0, horde = 0;
    for (uint8 i = 0; i < BG_BG_DYNAMIC_NODES_COUNT; ++i)
        if (m_Nodes[i] == BG_BG_NODE_STATUS_ALLY_OCCUPIED)
            ++ally;
        else if (m_Nodes[i] == BG_BG_NODE_STATUS_HORDE_OCCUPIED)
            ++horde;

    UpdateWorldState(BG_BG_OP_OCCUPIED_BASES_ALLY, ally);
    UpdateWorldState(BG_BG_OP_OCCUPIED_BASES_HORDE, horde);
}

void BattlegroundBG::_NodeOccupied (uint8 node, Team team)
{
    if (!AddSpiritGuide(node, BG_BG_SpiritGuidePos[node][0], BG_BG_SpiritGuidePos[node][1], BG_BG_SpiritGuidePos[node][2], BG_BG_SpiritGuidePos[node][3], team))
        sLog->outError("Failed to spawn spirit guide! point: %u, team: %u, ", node, team);

    uint8 capturedNodes = 0;
    for (uint8 i = 0; i < BG_BG_DYNAMIC_NODES_COUNT; ++i)
    {
        if (m_Nodes[node] == GetTeamIndexByTeamId(team) + BG_BG_NODE_TYPE_OCCUPIED && !m_NodeTimers[i])
            ++capturedNodes;
    }

    if (node >= BG_BG_DYNAMIC_NODES_COUNT)          //only dynamic nodes, no start points
        return;
    Creature* trigger = GetBGCreature(node + 5);          //0-6 spirit guides
    if (!trigger)
        trigger = AddCreature(WORLD_TRIGGER, node + 5, team, BG_BG_NodePositions[node][0], BG_BG_NodePositions[node][1], BG_BG_NodePositions[node][2], BG_BG_NodePositions[node][3]);

    //add bonus honor aura trigger creature when node is accupied
    //cast bonus aura (+50% honor in 25yards)
    //aura should only apply to players who have accupied the node, set correct faction for trigger
    if (trigger)
    {
        trigger->setFaction(team == ALLIANCE ? 84 : 83);
        trigger->CastSpell(trigger, SPELL_HONORABLE_DEFENDER_25Y, false);
    }
}

void BattlegroundBG::_NodeDeOccupied (uint8 node)
{
    if (node >= BG_BG_DYNAMIC_NODES_COUNT)
        return;

    //remove bonus honor aura trigger creature when node is lost
    if (node < BG_BG_DYNAMIC_NODES_COUNT)          //only dynamic nodes, no start points
        DelCreature(node + 7);          //NULL checks are in DelCreature! 0-6 spirit guides

    // Those who are waiting to resurrect at this node are taken to the closest own node's graveyard
    std::vector<uint64> ghost_list = m_ReviveQueue[m_BgCreatures[node]];
    if (!ghost_list.empty())
    {
        WorldSafeLocsEntry const *ClosestGrave = NULL;
        for (std::vector<uint64>::const_iterator itr = ghost_list.begin(); itr != ghost_list.end(); ++itr)
        {
            Player* plr = sObjectMgr->GetPlayer(*itr);
            if (!plr)
                continue;

            if (!ClosestGrave)          // cache
                ClosestGrave = GetClosestGraveYard(plr);

            if (ClosestGrave)
                plr->TeleportTo(GetMapId(), ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, plr->GetOrientation());
        }
    }

    if (m_BgCreatures[node])
        DelCreature(node);

    // buff object isn't despawned
}

/* Invoked if a player used a banner as a gameobject */
void BattlegroundBG::EventPlayerClickedOnFlag (Player *source, GameObject* /*target_obj*/)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    uint8 node = BG_BG_NODE_LIGHTHOUSE;
    GameObject* obj = GetBgMap()->GetGameObject(m_BgObjects[node * 8 + 5]);
    while ((node < BG_BG_DYNAMIC_NODES_COUNT) && ((!obj) || (!source->IsWithinDistInMap(obj, 10))))
    {
        ++node;
        obj = GetBgMap()->GetGameObject(m_BgObjects[node * 8 + BG_BG_OBJECT_AURA_CONTESTED]);
    }

    if (node == BG_BG_DYNAMIC_NODES_COUNT)
    {
        sLog->outString("Player %s (GUID: %u) in Battle for Gilneas fired EventPlayerClickedOnFlag() but isnt near of any flag", source->GetName(), source->GetGUIDLow());
        // this means our player isn't close to any of banners - maybe cheater ??
        return;
    }

    BattlegroundTeamId teamIndex = GetTeamIndexByTeamId(source->GetTeam());

    // Check if player really could use this banner, not cheated
    if (!(m_Nodes[node] == 0 || teamIndex == m_Nodes[node] % 2))
        return;

    source->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
    uint32 sound = 0;
    // If node is neutral, change to contested
    if (m_Nodes[node] == BG_BG_NODE_TYPE_NEUTRAL)
    {
        UpdatePlayerScore(source, SCORE_BASES_ASSAULTED, 1);
        m_prevNodes[node] = m_Nodes[node];
        m_Nodes[node] = teamIndex + 1;
        // burn current neutral banner
        _DelBanner(node, BG_BG_NODE_TYPE_NEUTRAL, 0);
        // create new contested banner
        _CreateBanner(node, BG_BG_NODE_TYPE_CONTESTED, teamIndex, true);
        _SendNodeUpdate(node);
        m_NodeTimers[node] = BG_BG_FLAG_CAPTURING_TIME;

        // FIXME: team and node names not localized
        if (teamIndex == 0)
            SendMessage2ToAll(LANG_BG_AB_NODE_CLAIMED, CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetNodeNameId(node), LANG_BG_AB_ALLY);
        else
            SendMessage2ToAll(LANG_BG_AB_NODE_CLAIMED, CHAT_MSG_BG_SYSTEM_HORDE, source, _GetNodeNameId(node), LANG_BG_AB_HORDE);

        sound = BG_BG_SOUND_NODE_CLAIMED;
    }
    // If node is contested
    else if ((m_Nodes[node] == BG_BG_NODE_STATUS_ALLY_CONTESTED) || (m_Nodes[node] == BG_BG_NODE_STATUS_HORDE_CONTESTED))
    {
        // If last state is NOT occupied, change node to enemy-contested
        if (m_prevNodes[node] < BG_BG_NODE_TYPE_OCCUPIED)
        {
            UpdatePlayerScore(source, SCORE_BASES_ASSAULTED, 1);
            m_prevNodes[node] = m_Nodes[node];
            m_Nodes[node] = teamIndex + BG_BG_NODE_TYPE_CONTESTED;
            // burn current contested banner
            _DelBanner(node, BG_BG_NODE_TYPE_CONTESTED, !teamIndex);
            // create new contested banner
            _CreateBanner(node, BG_BG_NODE_TYPE_CONTESTED, teamIndex, true);
            _SendNodeUpdate(node);
            m_NodeTimers[node] = BG_BG_FLAG_CAPTURING_TIME;

            // FIXME: node names not localized
            if (teamIndex == BG_TEAM_ALLIANCE)
                SendMessage2ToAll(LANG_BG_AB_NODE_ASSAULTED, CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetNodeNameId(node));
            else
                SendMessage2ToAll(LANG_BG_AB_NODE_ASSAULTED, CHAT_MSG_BG_SYSTEM_HORDE, source, _GetNodeNameId(node));
        }
        // If contested, change back to occupied
        else
        {
            UpdatePlayerScore(source, SCORE_BASES_DEFENDED, 1);
            m_prevNodes[node] = m_Nodes[node];
            m_Nodes[node] = teamIndex + BG_BG_NODE_TYPE_OCCUPIED;
            // burn current contested banner
            _DelBanner(node, BG_BG_NODE_TYPE_CONTESTED, !teamIndex);
            // create new occupied banner
            _CreateBanner(node, BG_BG_NODE_TYPE_OCCUPIED, teamIndex, true);
            _SendNodeUpdate(node);
            m_NodeTimers[node] = 0;
            _NodeOccupied(node, (teamIndex == BG_TEAM_ALLIANCE) ? ALLIANCE : HORDE);

            // FIXME: node names not localized
            if (teamIndex == BG_TEAM_ALLIANCE)
                SendMessage2ToAll(LANG_BG_AB_NODE_DEFENDED, CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetNodeNameId(node));
            else
                SendMessage2ToAll(LANG_BG_AB_NODE_DEFENDED, CHAT_MSG_BG_SYSTEM_HORDE, source, _GetNodeNameId(node));
        }
        sound = (teamIndex == BG_TEAM_ALLIANCE) ? BG_BG_SOUND_NODE_ASSAULTED_ALLIANCE : BG_BG_SOUND_NODE_ASSAULTED_HORDE;
    }
    // If node is occupied, change to enemy-contested
    else
    {
        UpdatePlayerScore(source, SCORE_BASES_ASSAULTED, 1);
        m_prevNodes[node] = m_Nodes[node];
        m_Nodes[node] = teamIndex + BG_BG_NODE_TYPE_CONTESTED;
        // burn current occupied banner
        _DelBanner(node, BG_BG_NODE_TYPE_OCCUPIED, !teamIndex);
        // create new contested banner
        _CreateBanner(node, BG_BG_NODE_TYPE_CONTESTED, teamIndex, true);
        _SendNodeUpdate(node);
        _NodeDeOccupied(node);
        m_NodeTimers[node] = BG_BG_FLAG_CAPTURING_TIME;

        // FIXME: node names not localized
        if (teamIndex == BG_TEAM_ALLIANCE)
            SendMessage2ToAll(LANG_BG_AB_NODE_ASSAULTED, CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetNodeNameId(node));
        else
            SendMessage2ToAll(LANG_BG_AB_NODE_ASSAULTED, CHAT_MSG_BG_SYSTEM_HORDE, source, _GetNodeNameId(node));

        sound = (teamIndex == BG_TEAM_ALLIANCE) ? BG_BG_SOUND_NODE_ASSAULTED_ALLIANCE : BG_BG_SOUND_NODE_ASSAULTED_HORDE;
    }

    // If node is occupied again, send "X has taken the Y" msg.
    if (m_Nodes[node] >= BG_BG_NODE_TYPE_OCCUPIED)
    {
        // FIXME: team and node names not localized
        if (teamIndex == BG_TEAM_ALLIANCE)
            SendMessage2ToAll(LANG_BG_AB_NODE_TAKEN, CHAT_MSG_BG_SYSTEM_ALLIANCE, NULL, LANG_BG_AB_ALLY, _GetNodeNameId(node));
        else
            SendMessage2ToAll(LANG_BG_AB_NODE_TAKEN, CHAT_MSG_BG_SYSTEM_HORDE, NULL, LANG_BG_AB_HORDE, _GetNodeNameId(node));
    }
    PlaySoundToAll(sound);
}

bool BattlegroundBG::SetupBattleground ()
{
    for (int i = 0; i < BG_BG_DYNAMIC_NODES_COUNT; ++i)
    {
        if (!AddObject(BG_BG_OBJECT_BANNER_NEUTRAL + 8 * i, BG_BG_OBJECTID_NODE_BANNER_0 + i, BG_BG_NodePositions[i][0], BG_BG_NodePositions[i][1], BG_BG_NodePositions[i][2], BG_BG_NodePositions[i][3], 0, 0, sin(BG_BG_NodePositions[i][3] / 2), cos(BG_BG_NodePositions[i][3] / 2), RESPAWN_ONE_DAY) || !AddObject(BG_BG_OBJECT_BANNER_CONT_A + 8 * i, BG_BG_OBJECTID_BANNER_CONT_A, BG_BG_NodePositions[i][0], BG_BG_NodePositions[i][1], BG_BG_NodePositions[i][2], BG_BG_NodePositions[i][3], 0, 0, sin(BG_BG_NodePositions[i][3] / 2), cos(BG_BG_NodePositions[i][3] / 2), RESPAWN_ONE_DAY) || !AddObject(BG_BG_OBJECT_BANNER_CONT_H + 8 * i, BG_BG_OBJECTID_BANNER_CONT_H, BG_BG_NodePositions[i][0], BG_BG_NodePositions[i][1], BG_BG_NodePositions[i][2], BG_BG_NodePositions[i][3], 0, 0, sin(BG_BG_NodePositions[i][3] / 2), cos(BG_BG_NodePositions[i][3] / 2), RESPAWN_ONE_DAY) || !AddObject(BG_BG_OBJECT_BANNER_ALLY + 8 * i, BG_BG_OBJECTID_BANNER_A, BG_BG_NodePositions[i][0], BG_BG_NodePositions[i][1], BG_BG_NodePositions[i][2], BG_BG_NodePositions[i][3], 0, 0, sin(BG_BG_NodePositions[i][3] / 2), cos(BG_BG_NodePositions[i][3] / 2), RESPAWN_ONE_DAY) || !AddObject(BG_BG_OBJECT_BANNER_HORDE + 8 * i, BG_BG_OBJECTID_BANNER_H, BG_BG_NodePositions[i][0], BG_BG_NodePositions[i][1], BG_BG_NodePositions[i][2], BG_BG_NodePositions[i][3], 0, 0, sin(BG_BG_NodePositions[i][3] / 2), cos(BG_BG_NodePositions[i][3] / 2), RESPAWN_ONE_DAY) || !AddObject(BG_BG_OBJECT_AURA_ALLY + 8 * i, BG_BG_OBJECTID_AURA_A, BG_BG_NodePositions[i][0], BG_BG_NodePositions[i][1], BG_BG_NodePositions[i][2], BG_BG_NodePositions[i][3], 0, 0, sin(BG_BG_NodePositions[i][3] / 2), cos(BG_BG_NodePositions[i][3] / 2), RESPAWN_ONE_DAY) || !AddObject(BG_BG_OBJECT_AURA_HORDE + 8 * i, BG_BG_OBJECTID_AURA_H, BG_BG_NodePositions[i][0], BG_BG_NodePositions[i][1], BG_BG_NodePositions[i][2], BG_BG_NodePositions[i][3], 0, 0, sin(BG_BG_NodePositions[i][3] / 2), cos(BG_BG_NodePositions[i][3] / 2), RESPAWN_ONE_DAY) || !AddObject(BG_BG_OBJECT_AURA_CONTESTED + 8 * i, BG_BG_OBJECTID_AURA_C, BG_BG_NodePositions[i][0], BG_BG_NodePositions[i][1], BG_BG_NodePositions[i][2], BG_BG_NodePositions[i][3], 0, 0, sin(BG_BG_NodePositions[i][3] / 2), cos(BG_BG_NodePositions[i][3] / 2), RESPAWN_ONE_DAY))
        {
            sLog->outErrorDb("BatteGroundBG: Failed to spawn some object Battleground not created!");
            return false;
        }
    }
    if (!AddObject(BG_BG_OBJECT_GATE_A, BG_BG_OBJECTID_GATE_A, BG_BG_DoorPositions[0][0], BG_BG_DoorPositions[0][1], BG_BG_DoorPositions[0][2], BG_BG_DoorPositions[0][3], BG_BG_DoorPositions[0][4], BG_BG_DoorPositions[0][5], BG_BG_DoorPositions[0][6], BG_BG_DoorPositions[0][7], RESPAWN_IMMEDIATELY) || !AddObject(BG_BG_OBJECT_GATE_H, BG_BG_OBJECTID_GATE_H, BG_BG_DoorPositions[1][0], BG_BG_DoorPositions[1][1], BG_BG_DoorPositions[1][2], BG_BG_DoorPositions[1][3], BG_BG_DoorPositions[1][4], BG_BG_DoorPositions[1][5], BG_BG_DoorPositions[1][6], BG_BG_DoorPositions[1][7], RESPAWN_IMMEDIATELY))
    {
        sLog->outErrorDb("BatteGroundBG: Failed to spawn door object Battleground not created!");
        return false;
    }
    //buffs
    for (int i = 0; i < BG_BG_DYNAMIC_NODES_COUNT; ++i)
    {
        if (!AddObject(BG_BG_OBJECT_SPEEDBUFF_LIGHTHOUSE + 3 * i, Buff_Entries[0], BG_BG_BuffPositions[i][0], BG_BG_BuffPositions[i][1], BG_BG_BuffPositions[i][2], BG_BG_BuffPositions[i][3], 0, 0, sin(BG_BG_BuffPositions[i][3] / 2), cos(BG_BG_BuffPositions[i][3] / 2), RESPAWN_ONE_DAY) || !AddObject(BG_BG_OBJECT_SPEEDBUFF_LIGHTHOUSE + 3 * i + 1, Buff_Entries[1], BG_BG_BuffPositions[i][0], BG_BG_BuffPositions[i][1], BG_BG_BuffPositions[i][2], BG_BG_BuffPositions[i][3], 0, 0, sin(BG_BG_BuffPositions[i][3] / 2), cos(BG_BG_BuffPositions[i][3] / 2), RESPAWN_ONE_DAY) || !AddObject(BG_BG_OBJECT_SPEEDBUFF_LIGHTHOUSE + 3 * i + 2, Buff_Entries[2], BG_BG_BuffPositions[i][0], BG_BG_BuffPositions[i][1], BG_BG_BuffPositions[i][2], BG_BG_BuffPositions[i][3], 0, 0, sin(BG_BG_BuffPositions[i][3] / 2), cos(BG_BG_BuffPositions[i][3] / 2), RESPAWN_ONE_DAY))
            sLog->outErrorDb("BatteGroundBG: Failed to spawn buff object!");
    }

    return true;
}

void BattlegroundBG::Reset ()
{
    //call parent's class reset
    Battleground::Reset();

    m_TeamScores[BG_TEAM_ALLIANCE] = 0;
    m_TeamScores[BG_TEAM_HORDE] = 0;
    m_lastTick[BG_TEAM_ALLIANCE] = 0;
    m_lastTick[BG_TEAM_HORDE] = 0;
    m_HonorScoreTics[BG_TEAM_ALLIANCE] = 0;
    m_HonorScoreTics[BG_TEAM_HORDE] = 0;
    m_IsInformedNearVictory = false;
    bool isBGWeekend = sBattlegroundMgr->IsBGWeekend(GetTypeID());
    m_HonorTics = (isBGWeekend) ? BG_BG_BGBGWeekendHonorTicks : BG_BG_NotBGBGWeekendHonorTicks;
    m_TeamScores500Disadvantage[BG_TEAM_ALLIANCE] = false;
    m_TeamScores500Disadvantage[BG_TEAM_HORDE] = false;

    for (uint8 i = 0; i < BG_BG_DYNAMIC_NODES_COUNT; ++i)
    {
        m_Nodes[i] = 0;
        m_prevNodes[i] = 0;
        m_NodeTimers[i] = 0;
        m_BannerTimers[i].timer = 0;
    }

    for (uint8 i = 0; i < BG_BG_ALL_NODES_COUNT + 3; ++i)          //+3 for aura triggers
        if (m_BgCreatures[i])
            DelCreature(i);
}

void BattlegroundBG::EndBattleground (uint32 winner)
{
    //win reward
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);
    //complete map_end rewards (even if no team wins)
    RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);
    RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);

    Battleground::EndBattleground(winner);
}

WorldSafeLocsEntry const* BattlegroundBG::GetClosestGraveYard (Player* player)
{
    BattlegroundTeamId teamIndex = GetTeamIndexByTeamId(player->GetTeam());

    // Is there any occupied node for this team?
    std::vector<uint8> nodes;
    for (uint8 i = 0; i < BG_BG_DYNAMIC_NODES_COUNT; ++i)
        if (m_Nodes[i] == teamIndex + 3)
            nodes.push_back(i);

    WorldSafeLocsEntry const* good_entry = NULL;
    // If so, select the closest node to place ghost on
    if (!nodes.empty())
    {
        float plr_x = player->GetPositionX();
        float plr_y = player->GetPositionY();

        float mindist = 999999.0f;
        for (uint8 i = 0; i < nodes.size(); ++i)
        {
            WorldSafeLocsEntry const*entry = sWorldSafeLocsStore.LookupEntry(BG_BG_GraveyardIds[nodes[i]]);
            if (!entry)
                continue;
            float dist = (entry->x - plr_x) * (entry->x - plr_x) + (entry->y - plr_y) * (entry->y - plr_y);
            if (mindist > dist)
            {
                mindist = dist;
                good_entry = entry;
            }
        }
        nodes.clear();
    }
    // If not, place ghost on starting location
    if (!good_entry)
        good_entry = sWorldSafeLocsStore.LookupEntry(BG_BG_GraveyardIds[teamIndex + 3]);

    return good_entry;
}

void BattlegroundBG::UpdatePlayerScore (Player *Source, uint32 type, uint32 value, bool doAddHonor)
{
    BattlegroundScoreMap::iterator itr = m_PlayerScores.find(Source->GetGUID());
    if (itr == m_PlayerScores.end())          // player not found...
        return;

    switch (type)
    {
    case SCORE_BASES_ASSAULTED:
        ((BattlegroundBGScore*) itr->second)->BasesAssaulted += value;
        Source->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, BG_OBJECTIVE_ASSAULT_BASE);
        break;
    case SCORE_BASES_DEFENDED:
        ((BattlegroundBGScore*) itr->second)->BasesDefended += value;
        Source->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, BG_OBJECTIVE_DEFEND_BASE);
        break;
    default:
        Battleground::UpdatePlayerScore(Source, type, value, doAddHonor);
        break;
    }
}

bool BattlegroundBG::IsAllNodesConrolledByTeam (uint32 team) const
{
    uint32 count = 0;
    for (int i = 0; i < BG_BG_DYNAMIC_NODES_COUNT; ++i)
        if ((team == ALLIANCE && m_Nodes[i] == BG_BG_NODE_STATUS_ALLY_OCCUPIED) || (team == HORDE && m_Nodes[i] == BG_BG_NODE_STATUS_HORDE_OCCUPIED))
            ++count;

    return count == BG_BG_DYNAMIC_NODES_COUNT;
}
