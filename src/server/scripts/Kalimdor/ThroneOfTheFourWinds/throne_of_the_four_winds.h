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

#ifndef DEF_THRONE_OF_THE_FOUR_WINDS_H
#define DEF_THRONE_OF_THE_FOUR_WINDS_H

enum Data
{
    DATA_CONCLAVE_OF_WIND_EVENT,
    DATA_ALAKIR_EVENT,
};

enum Data64
{
    DATA_ANSHAL,
    DATA_NEZIR,
    DATA_ROHASH,
    DATA_ALAKIR,
};

enum CreatureIds
{
    BOSS_ANSHAL                     = 45870,
    BOSS_NEZIR                      = 45871,
    BOSS_ROHASH                     = 45872,

    BOSS_ALAKIR                     = 46753,

    // Conclave of Wind
    NPC_SOOTHING_BREEZE             = 46246,
    NPC_RAVENOUS_CREEPER            = 45812,
    NPC_RAVENOUS_CREEPER_TRIGGER    = 45813,
    NPC_ICE_PATCH                   = 46186,
};

enum InstanceSpells
{
    SPELL_PRE_COMBAT_EFFECT_ANSHAL  = 85537,
    SPELL_PRE_COMBAT_EFFECT_NEZIR   = 85532,
    SPELL_PRE_COMBAT_EFFECT_ROHASH  = 85538,
};

#endif