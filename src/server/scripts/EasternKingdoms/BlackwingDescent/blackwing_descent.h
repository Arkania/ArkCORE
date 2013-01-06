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

#ifndef DEF_BLACKWING_DESCEND_H
#define DEF_BLACKWING_DESCEND_H

enum Data
{
    //Encounters
    DATA_MAGMAW,
    DATA_OMNOTRON_DEFENSE_SYSTEM,
    DATA_TOXITRON,
    DATA_MALORIAK,
    DATA_CHIMAERON,
    DATA_ATRAMEDES,
    DATA_NEFARIAN,
    DATA_ANCIEN_BELL,
    DATA_ABBERATIONS_LEFT,
    DATA_SPIRIT_SHADOWFORGE,
    DATA_SPIRIT_BURNINEYE,
    DATA_SPIRIT_IRONSTAR,
    DATA_SPIRIT_THAURISSAN,
    DATA_SPIRIT_ANVILRAGE,
    DATA_SPIRIT_COREHAMMER,
    DATA_SPIRIT_ANGERFORGE,
    DATA_SPIRIT_MOLTENFIST,
};

enum Data64
{
    DATA_ONYXIA,
    DATA_PROTOTYPE,
};

enum Creatures
{
    BOSS_MAGMAW                     = 41570,
    BOSS_OMNOTRON	               = 42186,
    BOSS_MALORIAK                   = 41378,
    BOSS_ATRAMEDES                  = 41442,
    BOSS_CHIMAERON                  = 43296,
    BOSS_NEFARIAN                   = 41376,

	// Magmaw
    NPC_MAGMAWS_HEAD                = 42347,
    NPC_IGNITION_TRIGGER            = 49447,    
    NPC_LAVA_PARASITE               = 41806,
    NPC_PILLAR_OF_FLAME_TRIGGER     = 41843,
    NPC_BLAZING_BONE_CONSTRUCT      = 49416,
    NPC_DRAGONID_DRUDGE             = 42362,

    // Omnotron Defense System
    // Toxitron
    NPC_TOXITRON                    = 42180,

    NPC_POISON_BOMB                 = 42897,
    NPC_POISON_CLOUD                = 42934,

    // Arcanotron
    NPC_ARCANOTRON                  = 42166,
    NPC_POWER_GENERATOR             = 42733,

    // Electron
    NPC_ELECTRON                    = 42179,

    // Magmatron
    NPC_MAGMATRON                   = 42178,

    // Chimaeron
    NPC_BILE_O_TRON                 = 44418,
    NPC_FINKLE_EINHORN              = 44202,

    // Maloriak
    NPC_ABBERATON                   = 41440,
    NPC_PRIME_SUBJECT               = 41841,
    NPC_SLIME_TRIGGER               = 41377,
    NPC_FLASH_FREEZE                = 41576,
    NPC_MAGMA_JET_CONTROLLER        = 50030,
    NPC_ABSOLUTE_ZERO               = 41961,
    NPC_VILE_SWILL                  = 49811,

    // Atramedes
    // Pre Event
    NPC_PRE_MALORIAK                = 43404,
    NPC_PRE_NEFARIAN                = 49799,
    NPC_PRE_ATRAMEDES               = 43407,
    NPC_PRE_LIGHT_EFFECT            = 41525,

    NPC_SONAR_PULSE                 = 49623,

    // Nefarian
    NPC_ONYXIA                      = 41270,
    NPC_WAR_OS                      = 41918,
    NPC_PROTOTYPE                   = 41948,

    // Misc
    NPC_NEFARIAN_HELPER_HEROIC      = 49427,
    NPC_LORD_VICTOR_NEFARIAN        = 41379,
};

enum Gameobjects
{
    GOB_DOOR_PRE_BOSSES             = 402092,
    GOB_DOOR_ATRAMEDES              = 402368,
    GOB_ONYXIA_PLATFORM             = 207834,
    GOB_MALORIAKS_CAULDRON          = 203306,
    GOB_NEFARIANS_THRONE            = 202832,
    GOB_ANCIEN_BELL                 = 204276,
};

#endif