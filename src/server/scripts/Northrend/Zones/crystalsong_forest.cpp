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

/* Script Data Start
 SDName: CrystalSongForest
 SDAuthor: Malcrom
 SD%Complete: 99%
 SDComment:
 SDCategory: CrystalsongForest
 Script Data End */

#include "ScriptPCH.h"

/*******************************************************
 * npc_warmage_violetstand
 *******************************************************/

enum Spells {
	SPELL_TRANSITUS_SHIELD_BEAM = 48310
};

enum NPCs {
	NPC_TRANSITUS_SHIELD_DUMMY = 27306,
	NPC_WARMAGE_SARINA = 32369,
	NPC_WARMAGE_HALISTER = 32371,
	NPC_WARMAGE_ILSUDRIA = 32372
};

class npc_warmage_violetstand: public CreatureScript {
public:
	npc_warmage_violetstand() :
			CreatureScript("npc_warmage_violetstand") {
	}

	struct npc_warmage_violetstandAI: public Scripted_NoMovementAI {
		npc_warmage_violetstandAI(Creature* pCreature) :
				Scripted_NoMovementAI(pCreature) {
		}

		uint64 uiTargetGUID;

		void Reset() {
			uiTargetGUID = 0;
		}

		void UpdateAI(const uint32 /*uiDiff*/) {
			if (me->IsNonMeleeSpellCasted(false))
				return;

			if (me->GetEntry() == NPC_WARMAGE_SARINA) {
				if (!uiTargetGUID) {
					std::list<Creature*> orbList;
					GetCreatureListWithEntryInGrid(orbList, me,
							NPC_TRANSITUS_SHIELD_DUMMY, 32.0f);
					if (!orbList.empty()) {
						for (std::list<Creature*>::const_iterator itr =
								orbList.begin(); itr != orbList.end(); ++itr) {
							if (Creature* pOrb = *itr) {
								if (pOrb->GetPositionY() < 1000) {
									uiTargetGUID = pOrb->GetGUID();
									break;
								}
							}
						}
					}
				}
			} else {
				if (!uiTargetGUID)
					if (Creature* pOrb = GetClosestCreatureWithEntry(me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f))
						uiTargetGUID = pOrb->GetGUID();
			}

			if (Creature* pOrb = me->GetCreature(*me, uiTargetGUID))
				DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);
		}
	};

	CreatureAI *GetAI(Creature *creature) const {
		return new npc_warmage_violetstandAI(creature);
	}
};

void AddSC_crystalsong_forest() {
	new npc_warmage_violetstand;
}
