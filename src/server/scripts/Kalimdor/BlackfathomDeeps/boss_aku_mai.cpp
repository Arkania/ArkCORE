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

#include "ScriptPCH.h"
#include "blackfathom_deeps.h"

enum Spells {
	SPELL_POISON_CLOUD = 3815, SPELL_FRENZIED_RAGE = 3490
};

class boss_aku_mai: public CreatureScript {
public:
	boss_aku_mai() :
			CreatureScript("boss_aku_mai") {
	}

	CreatureAI* GetAI(Creature* pCreature) const {
		return new boss_aku_maiAI(pCreature);
	}

	struct boss_aku_maiAI: public ScriptedAI {
		boss_aku_maiAI(Creature *c) :
				ScriptedAI(c) {
			pInstance = c->GetInstanceScript();
		}

		uint32 uiPoisonCloudTimer;
		bool bIsEnraged;

		InstanceScript *pInstance;

		void Reset() {
			uiPoisonCloudTimer = urand(5000, 9000);
			bIsEnraged = false;
			if (pInstance)
				pInstance->SetData(TYPE_AKU_MAI, NOT_STARTED);
		}

		void EnterCombat(Unit* /*who*/) {
			if (pInstance)
				pInstance->SetData(TYPE_AKU_MAI, IN_PROGRESS);
		}

		void JustDied(Unit* /*killer*/) {
			if (pInstance)
				pInstance->SetData(TYPE_AKU_MAI, DONE);
		}

		void UpdateAI(const uint32 diff) {
			if (!UpdateVictim())
				return;

			if (uiPoisonCloudTimer < diff) {
				DoCastVictim(SPELL_POISON_CLOUD);
				uiPoisonCloudTimer = urand(25000, 50000);
			} else
				uiPoisonCloudTimer -= diff;

			if (!bIsEnraged && HealthBelowPct(30)) {
				DoCast(me, SPELL_FRENZIED_RAGE);
				bIsEnraged = true;
			}

			DoMeleeAttackIfReady();
		}
	};
};

void AddSC_boss_aku_mai() {
	new boss_aku_mai();
}
