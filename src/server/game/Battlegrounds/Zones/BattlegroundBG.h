/*
 * Copyright (C) 2005 - 2013 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2013 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2013 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2013 ArkCORE <http://www.arkania.net/>
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

#ifndef __BattlegroundBG_H
#define __BattlegroundBG_H

class Battleground;

enum BG_BG_WorldStates
{
    BG_BG_OP_OCCUPIED_BASES_HORDE = 1778, BG_BG_OP_OCCUPIED_BASES_ALLY = 1779, BG_BG_OP_RESOURCES_ALLY = 1776, BG_BG_OP_RESOURCES_HORDE = 1777, BG_BG_OP_RESOURCES_MAX = 1780, BG_BG_OP_RESOURCES_WARNING = 1955
/*
 BG_BG_OP_LIGHTHOUSE_ICON                = 1842,             //LIGHTHOUSE map icon (NONE)
 BG_BG_OP_LIGHTHOUSE_STATE_ALIENCE       = 1767,             //LIGHTHOUSE map state (ALIENCE)
 BG_BG_OP_LIGHTHOUSE_STATE_HORDE         = 1768,             //LIGHTHOUSE map state (HORDE)
 BG_BG_OP_LIGHTHOUSE_STATE_CON_ALI       = 1769,             //LIGHTHOUSE map state (CON ALIENCE)
 BG_BG_OP_LIGHTHOUSE_STATE_CON_HOR       = 1770,             //LIGHTHOUSE map state (CON HORDE)
 BG_BG_OP_WATERWORKS_ICON                  = 1845,             //WATERWORKS map icon (NONE)
 BG_BG_OP_WATERWORKS_STATE_ALIENCE         = 1772,             //WATERWORKS state (ALIENCE)
 BG_BG_OP_WATERWORKS_STATE_HORDE           = 1773,             //WATERWORKS state (HORDE)
 BG_BG_OP_WATERWORKS_STATE_CON_ALI         = 1774,             //WATERWORKS state (CON ALIENCE)
 BG_BG_OP_WATERWORKS_STATE_CON_HOR         = 1775,             //WATERWORKS state (CON HORDE)
 BG_BG_OP_MINE_ICON            = 1846,             //MINE map icon (NONE)
 BG_BG_OP_MINE_STATE_ALIENCE   = 1782,             //MINE map state (ALIENCE)
 BG_BG_OP_MINE_STATE_HORDE     = 1783,             //MINE map state (HORDE)
 BG_BG_OP_MINE_STATE_CON_ALI   = 1784,             //MINE map state (CON ALIENCE)
 BG_BG_OP_MINE_STATE_CON_HOR   = 1785,             //MINE map state (CON HORDE)
 */
};

const uint32 BG_BG_OP_NODESTATES[3] =
{ 1767, 1782, 1772, };

const uint32 BG_BG_OP_NODEICONS[3] =
{ 1842, 1846, 1845, };

enum BG_BG_NodeObjectId
{
    BG_BG_OBJECTID_NODE_BANNER_0 = 208779,          // Lighthouse banner
    BG_BG_OBJECTID_NODE_BANNER_1 = 208782,          // Mine banner
    BG_BG_OBJECTID_NODE_BANNER_2 = 208785          // Waterworks banner
};

enum BG_BG_ObjectType
{
    BG_BG_OBJECT_BANNER_NEUTRAL = 0, BG_BG_OBJECT_BANNER_CONT_A = 1, BG_BG_OBJECT_BANNER_CONT_H = 2, BG_BG_OBJECT_BANNER_ALLY = 3, BG_BG_OBJECT_BANNER_HORDE = 4, BG_BG_OBJECT_AURA_ALLY = 5, BG_BG_OBJECT_AURA_HORDE = 6, BG_BG_OBJECT_AURA_CONTESTED = 7, BG_BG_OBJECT_GATE_A = 25, BG_BG_OBJECT_GATE_H = 26,
    //buffs
    BG_BG_OBJECT_SPEEDBUFF_LIGHTHOUSE = 27, BG_BG_OBJECT_REGENBUFF_LIGHTHOUSE = 28, BG_BG_OBJECT_BERSERKBUFF_LIGHTHOUSE = 29, BG_BG_OBJECT_SPEEDBUFF_MINE = 30, BG_BG_OBJECT_REGENBUFF_MINE = 31, BG_BG_OBJECT_BERSERKBUFF_MINE = 32, BG_BG_OBJECT_SPEEDBUFF_WATERWORKS = 33, BG_BG_OBJECT_REGENBUFF_WATERWORKS = 34, BG_BG_OBJECT_BERSERKBUFF_WATERWORKS = 35, BG_BG_OBJECT_MAX = 36
};

/* Object id templates from DB */
enum BG_BG_ObjectTypes
{
    BG_BG_OBJECTID_BANNER_A = 208673, BG_BG_OBJECTID_BANNER_CONT_A = 208763, BG_BG_OBJECTID_BANNER_H = 208748, BG_BG_OBJECTID_BANNER_CONT_H = 208733,

    BG_BG_OBJECTID_AURA_A = 180100, BG_BG_OBJECTID_AURA_H = 180101, BG_BG_OBJECTID_AURA_C = 180102,

    BG_BG_OBJECTID_GATE_A = 207177, BG_BG_OBJECTID_GATE_H = 207178
};

enum BG_BG_Timers
{
    BG_BG_FLAG_CAPTURING_TIME = 60000,
};

enum BG_BG_Score
{
    BG_BG_WARNING_NEAR_VICTORY_SCORE = 1800, BG_BG_MAX_TEAM_SCORE = 2000
};

/* do NOT change the order, else wrong behaviour */
enum BG_BG_BattlegroundNodes
{
    BG_BG_NODE_LIGHTHOUSE = 0, BG_BG_NODE_WATERWORKS = 1, BG_BG_NODE_MINE = 2,

    BG_BG_DYNAMIC_NODES_COUNT = 3,          // dynamic nodes that can be captured(it's normally 4)

    BG_BG_SPIRIT_ALIANCE = 3, BG_BG_SPIRIT_HORDE = 4,

    BG_BG_ALL_NODES_COUNT = 5,          // all nodes (dynamic and static)
};

enum BG_BG_NodeStatus
{
    BG_BG_NODE_TYPE_NEUTRAL = 0, BG_BG_NODE_TYPE_CONTESTED = 1, BG_BG_NODE_STATUS_ALLY_CONTESTED = 1, BG_BG_NODE_STATUS_HORDE_CONTESTED = 2, BG_BG_NODE_TYPE_OCCUPIED = 3, BG_BG_NODE_STATUS_ALLY_OCCUPIED = 3, BG_BG_NODE_STATUS_HORDE_OCCUPIED = 4
};

enum BG_BG_Sounds
{
    BG_BG_SOUND_NODE_CLAIMED = 8192, BG_BG_SOUND_NODE_CAPTURED_ALLIANCE = 8173, BG_BG_SOUND_NODE_CAPTURED_HORDE = 8213, BG_BG_SOUND_NODE_ASSAULTED_ALLIANCE = 8212, BG_BG_SOUND_NODE_ASSAULTED_HORDE = 8174, BG_BG_SOUND_NEAR_VICTORY = 8456
};

enum BG_BG_Objectives
{
    BG_OBJECTIVE_ASSAULT_BASE = 122, BG_OBJECTIVE_DEFEND_BASE = 123
};

#define BG_BG_NotBGBGWeekendHonorTicks      330
#define BG_BG_BGBGWeekendHonorTicks         200
#define BG_BG_NotBGBGWeekendReputationTicks 200
#define BG_BG_BGBGWeekendReputationTicks    150

// x, y, z, o
const float BG_BG_NodePositions[BG_BG_DYNAMIC_NODES_COUNT][4] =
{
{ 1057.7800f, 1278.260010f, 3.192400f, 1.864820f },          // Lighthouse
{ 980.1835f, 947.8692f, 12.868f, 5.9015f },          // Waterwork
{ 1251.010f, 958.3939f, 5.680f, 2.7698f }          // mine
};

// x, y, z, o, rot0, rot1, rot2, rot3
const float BG_BG_DoorPositions[2][8] =
{
{ 918.876f, 1336.56f, 27.6195f, 2.77481f, 0.0f, 0.0f, 0.983231f, 0.182367f },
{ 1396.15f, 977.014f, 7.43169f, 6.27043f, 0.0f, 0.0f, 0.006378f, -0.99998f } };

const uint32 BG_BG_TickIntervals[4] =
{ 0, 12000, 6000, 1000 };
const uint32 BG_BG_TickPoints[4] =
{ 0, 10, 10, 30 };

// WorldSafeLocs ids for 3 nodes, and for ally, and horde starting location
const uint32 BG_BG_GraveyardIds[BG_BG_ALL_NODES_COUNT] =
{ 1736, 1738, 1735, 1740, 1739 };

// x, y, z, o
const float BG_BG_BuffPositions[BG_BG_DYNAMIC_NODES_COUNT][4] =
{
{ 1063.39f, 1309.09f, 4.91f, 3.98f },          // Lighthouse
{ 990.95f, 984.46f, 13.01f, 4.57f },          // Waterworks
{ 1196.65f, 1020.01f, 7.97f, 5.74f },          // Mine
//	{ 1107.57f, 912.18f, 27.54f, 5.53f } To be named
};

// x, y, z, o
const float BG_BG_SpiritGuidePos[BG_BG_ALL_NODES_COUNT][4] =
{
{ 1036.32f, 1341.61f, 11.55f, 4.78f },          // Lighthouse
{ 886.44f, 938.06f, 24.13f, 0.53f },          // Waterworks
{ 1252.39f, 831.77f, 27.78f, 1.59f },          // Mine
{ 898.15f, 1341.58f, 27.66f, 6.06f },          // alliance starting base
{ 1408.16f, 977.34f, 7.44f, 3.18f }          // horde starting base
};

struct BG_BG_BannerTimer
{
    uint32 timer;
    uint8 type;
    uint8 teamIndex;
};

class BattlegroundBGScore: public BattlegroundScore
{
public:
    BattlegroundBGScore () :
            BasesAssaulted(0), BasesDefended(0)
    {
    }
    ;
    virtual ~BattlegroundBGScore ()
    {
    }
    ;
    uint32 BasesAssaulted;
    uint32 BasesDefended;
};

class BattlegroundBG: public Battleground
{
    friend class BattlegroundMgr;

public:
    BattlegroundBG ();
    ~BattlegroundBG ();

    void Update (uint32 diff);
    void AddPlayer (Player *plr);
    virtual void StartingEventCloseDoors ();
    virtual void StartingEventOpenDoors ();
    void RemovePlayer (Player *plr, uint64 guid);
    void HandleAreaTrigger (Player *Source, uint32 Trigger);
    virtual bool SetupBattleground ();
    virtual void Reset ();
    void EndBattleground (uint32 winner);
    virtual WorldSafeLocsEntry const* GetClosestGraveYard (Player* player);

    /* Scorekeeping */
    virtual void UpdatePlayerScore (Player *Source, uint32 type, uint32 value, bool doAddHonor = true);

    virtual void FillInitialWorldStates (WorldPacket& data);

    /* achievement req. */
    bool IsAllNodesConrolledByTeam (uint32 team) const;          // overwrited
    bool IsTeamScores500Disadvantage (uint32 team) const
    {
        return m_TeamScores500Disadvantage[GetTeamIndexByTeamId(team)];
    }
private:
    /* Gameobject spawning/despawning */
    void _CreateBanner (uint8 node, uint8 type, uint8 teamIndex, bool delay);
    void _DelBanner (uint8 node, uint8 type, uint8 teamIndex);
    void _SendNodeUpdate (uint8 node);

    /* Creature spawning/despawning */
    // TODO: working, scripted peons spawning
    void _NodeOccupied (uint8 node, Team team);
    void _NodeDeOccupied (uint8 node);

    int32 _GetNodeNameId (uint8 node);
    /* Nodes occupying */
    virtual void EventPlayerClickedOnFlag (Player *source, GameObject* target_obj);

    /* Nodes info:
     0: neutral
     1: ally contested
     2: horde contested
     3: ally occupied
     4: horde occupied     */
    uint8 m_Nodes[BG_BG_DYNAMIC_NODES_COUNT];
    uint8 m_prevNodes[BG_BG_DYNAMIC_NODES_COUNT];
    BG_BG_BannerTimer m_BannerTimers[BG_BG_DYNAMIC_NODES_COUNT];
    uint32 m_NodeTimers[BG_BG_DYNAMIC_NODES_COUNT];
    uint32 m_lastTick[BG_TEAMS_COUNT];
    uint32 m_HonorScoreTics[BG_TEAMS_COUNT];
    uint32 m_ReputationScoreTics[BG_TEAMS_COUNT];
    bool m_IsInformedNearVictory;
    uint32 m_HonorTics;
    uint32 m_ReputationTics;
    // need for achievements
    bool m_TeamScores500Disadvantage[BG_TEAMS_COUNT];
};
#endif
