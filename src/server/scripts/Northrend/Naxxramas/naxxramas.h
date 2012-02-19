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

#ifndef DEF_NAXXRAMAS_H
#define DEF_NAXXRAMAS_H

enum Encounter {
	BOSS_ANUBREKHAN,
	BOSS_FAERLINA,
	BOSS_MAEXXNA,
	BOSS_NOTH,
	BOSS_HEIGAN,
	BOSS_LOATHEB,
	BOSS_PATCHWERK,
	BOSS_GROBBULUS,
	BOSS_GLUTH,
	BOSS_THADDIUS,
	BOSS_RAZUVIOUS,
	BOSS_GOTHIK,
	BOSS_HORSEMEN,
	BOSS_SAPPHIRON,
	BOSS_KELTHUZAD,
	MAX_BOSS_NUMBER
};

enum Data {
	DATA_HEIGAN_ERUPT, DATA_GOTHIK_GATE, DATA_SAPPHIRON_BIRTH,

	DATA_HORSEMEN0, DATA_HORSEMEN1, DATA_HORSEMEN2, DATA_HORSEMEN3,
};

enum Data64 {
	DATA_FAERLINA,
	DATA_THANE,
	DATA_LADY,
	DATA_BARON,
	DATA_SIR,
	DATA_THADDIUS,
	DATA_FEUGEN,
	DATA_STALAGG,
	DATA_KELTHUZAD,
	DATA_KELTHUZAD_PORTAL01,
	DATA_KELTHUZAD_PORTAL02,
	DATA_KELTHUZAD_PORTAL03,
	DATA_KELTHUZAD_PORTAL04,
	DATA_KELTHUZAD_TRIGGER,
};

#define GO_BIRTH                181356

#endif
