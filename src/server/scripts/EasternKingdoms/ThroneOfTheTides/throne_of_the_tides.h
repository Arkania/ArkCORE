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

#ifndef DEF_THRONEOFTHETIDES_H
#define DEF_THRONEOFTHETIDES_H

enum Defines
{
    ACTION_OZUMAT_PREPARE_EVENT,
    ACTION_OZUMAT_START_EVENT,
    ACTION_OZUMAT_FINAL_PHASE,

    // Event
    NPC_NAZJAR_INVADER = 39616,
    NPC_NAZJAR_SPIRITMENDER = 41139,
    NPC_DEEP_MURLOC_DRUDGE = 39960,
    NPC_TEMPEST_WITCH = 40634,

    // Lady Naz'jar
    BOSS_LADY_NAZJAR = 40586,
    NPC_SUMMONED_WITCH = 40634, // 2 of them
    NPC_SUMMONED_GUARD = 40633,
    NPC_SUMMONED_WATERSPOUT = 48571,
    NPC_SUMMONED_WATERSPOUT_HC = 49108,
    NPC_SUMMONED_GEYSER = 40597,
    NPC_NAZJAR_COMBAT_TRIGGER = 40568,

    // Commander Ulthok
    BOSS_COMMANDER_ULTHOK = 40765,
    NPC_DARK_FISSURE = 40784,

    // Erunak Stonespeaker & Mindbender Ghur'sha
    BOSS_ERUNAK_STONESPEAKER = 40825,
    BOSS_MINDBENDER_GHURSHA = 40788,
    NPC_EARTH_SHARD = 45469,
    NPC_MIND_FOG = 40861,

    // Ozumat
    BOSS_OZUMAT = 44566,
    BOSS_NEPTULON = 40792,
    NPC_DEEP_MURLOC = 44658,
    NPC_MINDLASHER = 44715,
    NPC_BEHEMOTH = 44648,
    NPC_SAPPER = 44752,
    NPC_BEAST = 44841,
    NPC_BLIGHT_OF_OZUMAT = 44801,
    NPC_OZUMAT_VISUAL_TRIGGER = 44809,


    // GOs
    GO_COMMANDER_ULTHOK_DOOR = 204338,
    GO_CORALES = 205542,
    GO_LADY_NAZJAR_DOOR = 204339,
    GO_ERUNAK_STONESPEAKER_DOOR = 204340,
    GO_OZUMAT_DOOR = 204341,
    GO_OZUMAT_CHEST_NORMAL = 205216,
    GO_OZUMAT_CHEST_HEROIC = 0,
    GO_TENTACLE_RIGHT = 402012,
    GO_TENTACLE_LEFT = 208301,
    GO_CONTROL_SYSTEM = 203199,
    GO_GOSTH_GATE = 180322,
    GO_JELLYFISH_ELEVATOR = 207209,

    SPELL_ULTHOK_INTRO = 82960,
};

enum Data
{
    DATA_LADY_NAZJAR_EVENT = 0,
    DATA_COMMANDER_ULTHOK_EVENT = 1,
    DATA_ERUNAK_STONESPEAKER_EVENT = 2,
    DATA_OZUMAT_EVENT = 3
};

enum Data64
{
    DATA_LADY_NAZJAR,
    DATA_COMMANDER_ULTHOK,
    DATA_MINDEBENDER_GHURSHA,
    DATA_ERUNAK_STONESPEAKER,
    DATA_OZUMAT,
    DATA_NEPTULON,
};

#define MAX_ENCOUNTER 4

#endif