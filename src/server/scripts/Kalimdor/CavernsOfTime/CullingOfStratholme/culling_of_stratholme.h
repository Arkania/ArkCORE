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

#ifndef DEF_CULLING_OF_STRATHOLME_H
#define DEF_CULLING_OF_STRATHOLME_H

enum Data {
	DATA_MEATHOOK_EVENT,
	DATA_SALRAMM_EVENT,
	DATA_EPOCH_EVENT,
	DATA_MAL_GANIS_EVENT,
	DATA_INFINITE_EVENT,
	DATA_ARTHAS_EVENT
};

enum Data64 {
	DATA_ARTHAS,
	DATA_MEATHOOK,
	DATA_SALRAMM,
	DATA_EPOCH,
	DATA_MAL_GANIS,
	DATA_INFINITE,
	DATA_SHKAF_GATE,
	DATA_MAL_GANIS_GATE_1,
	DATA_MAL_GANIS_GATE_2,
	DATA_EXIT_GATE,
	DATA_MAL_GANIS_CHEST
};

enum Creatures {
	NPC_MEATHOOK = 26529,
	NPC_SALRAMM = 26530,
	NPC_EPOCH = 26532,
	NPC_MAL_GANIS = 26533,
	NPC_INFINITE = 32273,
	NPC_ARTHAS = 26499,
	NPC_JAINA = 26497,
	NPC_UTHER = 26528
};

enum GameObjects {
	GO_SHKAF_GATE = 188686,
	GO_MALGANIS_GATE_1 = 187711,
	GO_MALGANIS_GATE_2 = 187723,
	GO_EXIT_GATE = 191788,
	GO_MALGANIS_CHEST_N = 190663,
	GO_MALGANIS_CHEST_H = 193597
};
#endif
