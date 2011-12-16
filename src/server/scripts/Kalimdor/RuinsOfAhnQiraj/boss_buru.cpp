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

/* ScriptData
 SDName: Boss_Buru
 SD%Complete: 0
 SDComment: Place Holder
 SDCategory: Ruins of Ahn'Qiraj
 EndScriptData */

#include "ScriptPCH.h"
#include "ruins_of_ahnqiraj.h"

enum Yells {
	EMOTE_TARGET = -1509002
};

class boss_buru: public CreatureScript {
public:
	boss_buru() :
			CreatureScript("boss_buru") {
	}

	CreatureAI* GetAI(Creature* pCreature) const {
		return new boss_buruAI(pCreature);
	}

	struct boss_buruAI: public ScriptedAI {
		boss_buruAI(Creature *c) :
				ScriptedAI(c) {
			pInstance = c->GetInstanceScript();
		}

		InstanceScript *pInstance;

		void Reset() {
			if (pInstance)
				pInstance->SetData(DATA_BURU_EVENT, NOT_STARTED);
		}

		void EnterCombat(Unit * /*who*/) {
			if (pInstance)
				pInstance->SetData(DATA_BURU_EVENT, IN_PROGRESS);
		}

		void JustDied(Unit * /*killer*/) {
			if (pInstance)
				pInstance->SetData(DATA_BURU_EVENT, DONE);
		}
	};
};

void AddSC_boss_buru() {
	new boss_buru();
}
