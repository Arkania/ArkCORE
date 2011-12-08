/*
 * Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
 *
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2011 ArkCORE <http://www.arkania.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "World.h"

class Reset_OnDuelEnd: public PlayerScript {
public:
	Reset_OnDuelEnd() :
			PlayerScript("Reset_OnDuelEnd") {
	}

	void OnDuelEnd(Player* winner, Player* looser, DuelCompleteType type) {
		// reset cooldowns (in order) Elwyn, Durotar, Tirisfal, Tendrasil, Dun Morogh, Gurubashi Arena, Exodar, Mulgore
		//int32 ZONE_ONE = sWorld->getIntConfig(CONFIG_DUEL_RESET_ONE);
		//int32 ZONE_TWO = sWorld->getIntConfig(CONFIG_DUEL_RESET_TWO);
		if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN)) {
			if (winner->GetZoneId() == 12 || winner->GetZoneId() == 14
					|| winner->GetZoneId() == 85 || winner->GetZoneId() == 141
					|| winner->GetZoneId() == 1 || winner->GetZoneId() == 5287
					|| winner->GetZoneId() == 3524
					|| winner->GetZoneId() == 215) {
				winner->RemoveArenaSpellCooldowns();
				looser->RemoveArenaSpellCooldowns();
				winner->SetHealth(winner->GetMaxHealth());
				looser->SetHealth(looser->GetMaxHealth());
				if (winner->getPowerType() == POWER_MANA)
					winner->SetPower(POWER_MANA,
							winner->GetMaxPower(POWER_MANA));
				if (looser->getPowerType() == POWER_MANA)
					looser->SetPower(POWER_MANA,
							looser->GetMaxPower(POWER_MANA));
			}
		}
	}
};

void AddSC_DuelReset() {
	new Reset_OnDuelEnd;
}
