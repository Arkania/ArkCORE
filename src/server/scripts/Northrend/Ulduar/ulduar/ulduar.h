/*
 * Copyright (C) 2005-2011 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008-2011 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 *
 * Copyright (C) 2010-2011 ProjectSkyfire <http://www.projectskyfire.org/>
 * 
 * Copyright (C) 2011 ArkCORE <http://www.arkania.net/>
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

#ifndef DEF_ULDUAR_H
#define DEF_ULDUAR_H

enum eTypes {
	MAX_ENCOUNTER = 15,

	TYPE_LEVIATHAN = 0,
	TYPE_IGNIS = 1,
	TYPE_RAZORSCALE = 2,
	TYPE_XT002 = 3,
	TYPE_ASSEMBLY = 4,
	TYPE_KOLOGARN = 5,
	TYPE_AURIAYA = 6,
	TYPE_MIMIRON = 7,
	TYPE_HODIR = 8,
	TYPE_THORIM = 9,
	TYPE_FREYA = 10,
	TYPE_VEZAX = 11,
	TYPE_YOGGSARON = 12,
	TYPE_ALGALON = 13,
	TYPE_COLOSSUS = 14,

	DATA_STEELBREAKER,
	DATA_MOLGEIM,
	DATA_BRUNDIR,

	DATA_EXP_COMMANDER,
	DATA_RIGHT_ARM,
	DATA_LEFT_ARM,
};

enum eBossNPCs {
	NPC_LEVIATHAN = 33113,
	NPC_IGNIS = 33118,
	NPC_RAZORSCALE = 33186,
	NPC_EXPEDITION_COMMANDER = 33210,
	NPC_XT002 = 33293,
	NPC_STEELBREAKER = 32867,
	NPC_MOLGEIM = 32927,
	NPC_BRUNDIR = 32857,
	NPC_KOLOGARN = 32930,
	NPC_AURIAYA = 33515,
	NPC_MIMIRON = 33350,
	NPC_HODIR = 32845,
	NPC_THORIM = 32865,
	NPC_FREYA = 32906,
	NPC_VEZAX = 33271,
	NPC_YOGGSARON = 33288,
	NPC_ALGALON = 32871,
};

enum eTowerEvents {
	EVENT_TOWER_OF_STORM_DESTROYED = 21031,
	EVENT_TOWER_OF_FROST_DESTROYED = 21032,
	EVENT_TOWER_OF_FLAMES_DESTROYED = 21033,
	EVENT_TOWER_OF_LIFE_DESTROYED = 21030
};

enum eAchievementCriteria {
	ACHIEVEMENT_CRITERIA_HOT_POCKET_10 = 10430, //ignis
	ACHIEVEMENT_CRITERIA_HOT_POCKET_25 = 10431,
};
#endif
