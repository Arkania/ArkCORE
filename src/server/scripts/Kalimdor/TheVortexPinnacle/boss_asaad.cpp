/*
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008 - 2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "vortex_pinnacle.h"
#include "ScriptPCH.h"

enum Texts
{
    SAY_AGGRO                   = 0,
    SAY_LIGHTNING               = 1,
    SAY_DEATH                   = 2,
};

enum Spells
{
    SPELL_CHAIN_LIGHTNING_N       = 87622,
    SPELL_CHAIN_LIGHTNING_H       = 93993,
};

class boss_asaad : public CreatureScript
{
public:
    boss_asaad() : CreatureScript("boss_asaad") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_asaadAI (creature);
    }

    struct boss_asaadAI : public ScriptedAI
    {
        boss_asaadAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 ChainLightningTimer;

        void Reset()
        {
            ChainLightningTimer = 15000;

            if (instance)
            {
                instance->SetData(DATA_ASAAD, NOT_STARTED);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, me);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance)
            {
                instance->SetData(DATA_ASAAD, IN_PROGRESS);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ADD, me);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (instance)
            {
                instance->SetData(DATA_ASAAD, DONE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, me);
            }

            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* player = i->getSource())
                    player->ModifyCurrency(395, DUNGEON_MODE(3000, 7000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (ChainLightningTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    me->CastSpell(target, DUNGEON_MODE(SPELL_CHAIN_LIGHTNING_N, SPELL_CHAIN_LIGHTNING_H), true);

                ChainLightningTimer = urand(12*IN_MILLISECONDS,17*IN_MILLISECONDS);
            } else ChainLightningTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_asaad()
{
    new boss_asaad();
}
