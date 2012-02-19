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

/* ScriptData
 SDName: Boss_Gehennas
 SD%Complete: 90
 SDComment: Adds MC NYI
 SDCategory: Molten Core
 EndScriptData */

#include "ScriptPCH.h"

#define SPELL_SHADOWBOLT            19728
#define SPELL_RAINOFFIRE            19717
#define SPELL_GEHENNASCURSE         19716

class boss_gehennas: public CreatureScript {
public:
	boss_gehennas() :
			CreatureScript("boss_gehennas") {
	}

	CreatureAI* GetAI(Creature* pCreature) const {
		return new boss_gehennasAI(pCreature);
	}

	struct boss_gehennasAI: public ScriptedAI {
		boss_gehennasAI(Creature *c) :
				ScriptedAI(c) {
		}

		uint32 ShadowBolt_Timer;
		uint32 RainOfFire_Timer;
		uint32 GehennasCurse_Timer;

		void Reset() {
			ShadowBolt_Timer = 6000;
			RainOfFire_Timer = 10000;
			GehennasCurse_Timer = 12000;
		}

		void EnterCombat(Unit * /*who*/) {
		}

		void UpdateAI(const uint32 diff) {
			if (!UpdateVictim())
				return;

			//ShadowBolt_Timer
			if (ShadowBolt_Timer <= diff) {
				if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
					DoCast(pTarget, SPELL_SHADOWBOLT);

				ShadowBolt_Timer = 7000;
			} else
				ShadowBolt_Timer -= diff;

			//RainOfFire_Timer
			if (RainOfFire_Timer <= diff) {
				if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
					DoCast(pTarget, SPELL_RAINOFFIRE);

				RainOfFire_Timer = urand(4000, 12000);
			} else
				RainOfFire_Timer -= diff;

			//GehennasCurse_Timer
			if (GehennasCurse_Timer <= diff) {
				DoCast(me->getVictim(), SPELL_GEHENNASCURSE);
				GehennasCurse_Timer = urand(22000, 30000);
			} else
				GehennasCurse_Timer -= diff;

			DoMeleeAttackIfReady();
		}
	};
};

void AddSC_boss_gehennas() {
	new boss_gehennas();
}
