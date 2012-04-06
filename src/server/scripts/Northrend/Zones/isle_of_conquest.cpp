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

#include "ScriptPCH.h"
#include "BattlegroundIC.h"

// TO-DO: This should be done with SmartAI, but yet it does not correctly support vehicles's AIs.
//        Even adding ReactState Passive we still have issues using SmartAI.

class npc_four_car_garage: public CreatureScript {
public:
    npc_four_car_garage() :
            CreatureScript("npc_four_car_garage") {
    }

    struct npc_four_car_garageAI: public NullCreatureAI {
        npc_four_car_garageAI(Creature* pCreature) :
                NullCreatureAI(pCreature) {
        }

        void PassengerBoarded(Unit* who, int8 seatId, bool apply) {
            if (apply) {
                uint32 spellId = 0;

                switch (me->GetEntry()) {
                case NPC_DEMOLISHER:
                    spellId = 68365;
                    break;
                    //case NPC_GLAIVE_THROWER:
                    //    spellId = 68363;
                    //    break;
                case NPC_SIEGE_ENGINE_H:
                case NPC_SIEGE_ENGINE_A:
                    spellId = 68364;
                    break;
                case NPC_CATAPULT:
                    spellId = 68362;
                    break;
                default:
                    return;
                }

                me->CastSpell(who, spellId, true);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const {
        return new npc_four_car_garageAI(creature);
    }
};

void AddSC_isle_of_conquest() {
    new npc_four_car_garage();
}
