/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2012 ArkCORE <http://www.arkania.net/>
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
#include "utgarde_keep.h"

uint32 entry_search[3] =
{
    186609,
    186610,
    186611
};

class npc_dragonflayer_forge_master : public CreatureScript
{
public:
    npc_dragonflayer_forge_master() : CreatureScript("npc_dragonflayer_forge_master") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_dragonflayer_forge_masterAI(creature);
    }

    struct npc_dragonflayer_forge_masterAI : public ScriptedAI
    {
        npc_dragonflayer_forge_masterAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
            fm_Type = 0;
        }

        InstanceScript* instance;
        uint8 fm_Type;

        void Reset()
        {
            if (fm_Type == 0) fm_Type = GetForgeMasterType();
            CheckForge();
        }

        void CheckForge()
        {
           if (instance)
            {
                switch (fm_Type)
                {
                case 1:
                    instance->SetData(EVENT_FORGE_1, me->isAlive() ? NOT_STARTED : DONE);
                    break;
                case 2:
                    instance->SetData(EVENT_FORGE_2, me->isAlive() ? NOT_STARTED : DONE);
                    break;
                case 3:
                    instance->SetData(EVENT_FORGE_3, me->isAlive() ? NOT_STARTED : DONE);
                    break;
                }
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (fm_Type == 0) fm_Type = GetForgeMasterType();
            if (instance)
            {
                switch (fm_Type)
                {
                case 1:
                    instance->SetData(EVENT_FORGE_1, DONE);
                    break;
                case 2:
                    instance->SetData(EVENT_FORGE_2, DONE);
                    break;
                case 3:
                    instance->SetData(EVENT_FORGE_3, DONE);
                    break;
                }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (fm_Type == 0) fm_Type = GetForgeMasterType();
            if (instance)
            {
                switch (fm_Type)
                {
                case 1:
                    instance->SetData(EVENT_FORGE_1, IN_PROGRESS);
                    break;
                case 2:
                    instance->SetData(EVENT_FORGE_2, IN_PROGRESS);
                    break;
                case 3:
                    instance->SetData(EVENT_FORGE_3, IN_PROGRESS);
                    break;
                }
            }
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
        }

        uint8 GetForgeMasterType()
        {
            float diff = 30.0f;
            int near_f = 0;

            for (uint8 i = 0; i < 3 ; ++i)
            {
                GameObject* temp;
                temp = me->FindNearestGameObject(entry_search[i], 30);
                if (temp)
                {
                    if (me->IsWithinDist(temp, diff, false))
                    {
                        near_f = i + 1;
                        diff = me->GetDistance2d(temp);
                    }
                }
            }

            switch (near_f)
            {
            case 1:  return 1;
            case 2:  return 2;
            case 3:  return 3;
            default: return 0;
            }
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (fm_Type == 0)
                fm_Type = GetForgeMasterType();

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

/*######
## npc_dark_ranger_marrah
######*/
#define SPELL_RANGER_STEALTH   34189

class npc_dark_ranger_marrah : public CreatureScript
{
public:
    npc_dark_ranger_marrah() : CreatureScript("npc_dark_ranger_marrah") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new  npc_dark_ranger_marrahAI(pCreature);
    }

    struct npc_dark_ranger_marrahAI : public ScriptedAI
    {
        npc_dark_ranger_marrahAI(Creature *c) : ScriptedAI(c) { }

        void Reset()
        {
            DoCast(me,SPELL_RANGER_STEALTH);
        }
        void MoveInLineOfSight(Unit *who)
        {
            if(!who || who->GetTypeId() != TYPEID_PLAYER)
                return;

            if(who->ToPlayer()->GetTeamId() == TEAM_HORDE)
            {
                if(who->GetDistance2d(me) <= 5)
                    me->RemoveAurasDueToSpell(SPELL_RANGER_STEALTH);
            }else
            {
                me->SetVisible(false);
            }

            return;
        }
        void AttackStart(Unit *who) { return; }
        void EnterCombat(Unit *who) { }
    };
};

#define SPELL_ENRAGE            42745
#define SPELL_POUNCE            55077

class npc_savage_worg : public CreatureScript
{
public:
    npc_savage_worg() : CreatureScript("npc_savage_worg") { }

    struct npc_savage_worgAI : public ScriptedAI
    {
        npc_savage_worgAI(Creature *c) : ScriptedAI(c) { }

        uint32 uiPounceTimer;

        void Reset()
        {
            uiPounceTimer=0;
        }

        void EnterCombat(Unit *who)
        {
            me->CallForHelp(15);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiPounceTimer<=diff)
            {
                if (Unit* player = SelectTarget(SELECT_TARGET_FARTHEST,1,100,true))
                    DoCast(player,SPELL_POUNCE);
                uiPounceTimer=30000;
            } else uiPounceTimer-=diff;

            if (HealthBelowPct(40))
                DoCast(me,SPELL_ENRAGE);

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_savage_worgAI(pCreature);
    }
};
void AddSC_utgarde_keep()
{
    new npc_dark_ranger_marrah();
    new npc_dragonflayer_forge_master();
    new npc_savage_worg();
}
