/*
 * Copyright (C) 2011 True Blood <http://www.trueblood-servers.com/>
 * By Asardial
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

#ifndef DEF_FIRELANDS_H
#define DEF_FIRELANDS_H

#include "ObjectMgr.h"
#define FirelandsScriptName "instance_firelands"

enum Data
{
DATA_INTRO_EVENT, //ragnaros intro
DATA_BETHTILAC_EVENT,
DATA_RHYOLITH_EVENT,
DATA_ALYSRAZAR_EVENT,
DATA_SHANNOX_EVENT,
DATA_BALOROC_EVENT,
DATA_MAJORDOMUS_EVENT,
DATA_RAGNAROS_EVENT,

DATA_CURRENT_ENCOUNTER_PHASE = 7,
};

enum Data64
{
DATA_INTRO, //ragnaros intro
DATA_BETHTILAC,
DATA_RHYOLITH,
DATA_ALYSRAZAR,
DATA_SHANNOX,
DATA_BALOROC,
DATA_MAJORDOMUS,
DATA_RAGNAROS,
};

enum creatures
{
//bosses
BOSS_BETHTILAC = 52498,
BOSS_RHYOLITH = 52558,
BOSS_ALYSRAZAR = 52530,
BOSS_SHANNOX = 53691,
BOSS_BALOROC = 53494,
BOSS_MAJORDOMUS = 52571, // (54015 <-- maybe this entry - 52571 is spawned in the world db)
BOSS_RAGNAROS_CATA = 52409,

//other npc's
NPC_SULFURAS = 53420, //ragnaros boss weapon
NPC_LIVING_METEOR = 53500,
NPC_MOLTEN_ELEMENTAR = 53189,

// Shannox
NPC_RIPLIMB = 53694, // Shannox Dogs
NPC_RAGEFACE = 53695,
NPC_SHANNOX_SPEAR = 53752, // Shannox Spear
NPC_CRYSTAL_TRAP = 53713,
NPC_CRYSTAL_PRISON = 53819,

// Bethilac
NPC_CINDERWEB_SPINNER = 52524,
NPC_CINDERWEB_DRONE = 52581,
NPC_CINDERWEB_SPIDERLING = 52447,
NPC_ENGORGED_BROODLING = 53745, // Correct id?
NPC_SPIDERWEB_FILAMENT = 53082, // This is the Elevator

// Majordomo Staghelm
NPC_SPIRIT_OF_THE_FLAME = 52593
};

enum gameobjectIDs
{
GOB_DOOR_BETHILAC = 208877,
GOB_DOOR_BALOROC = 209066,
GOB_DOOR_MAJORDOMO = 208873,

GOB_SULFURON_BRIDGE = 209251,
};

enum Phase
{
//Shannox
PHASE_NON = 0,

PHASE_SHANNOX_HAS_SPEER = 1,
PHASE_SPEAR_ON_THE_GROUND = 2,
PHASE_RIPLIMB_GOS_TO_SPEER = 3,
PHASE_RIPLIMB_BRINGS_SPEER = 4,

// Bethilac
PHASE_BETHILAC_UPPER = 5,
PHASE_BETHILAC_LOWER = 6,



//Ragnaros
PHASE_1 = 7,
PHASE_2 = 8,

};

enum PathIDs
{
PATH_SHANNOX = 154280940,
};

enum DataVar
{
DATA_PHASE,
};

enum MovePoints
{
POINT_RAGNAROS_DOWN, //end of each phase
POINT_RAGNAROS_UP, //start of each next phase
POINT_RAGNAROS_STANDUP, //only on heroic mode
POINT_SULFURAS_SMASH, //target for smashes
};

enum Actions
{
//Ragnaros
ACTION_RAGNAROS_DOWN, //end of each phase
ACTION_RAGNAROS_UP, //start of each next phase
ACTION_RAGNAROS_STANDUP, //only on heroic mode
ACTION_SULFURAS_SMASH, //target for smashes

//Shannox
ACTION_SAY_RIPLIMB, //Shannox yell when Riplimb bites someone
};

#endif