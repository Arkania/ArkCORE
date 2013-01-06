/*
 * Copyright (C) 2011 True Blood <http://www.trueblood-servers.com/>
 * By Asardial
 *
 * Copyright (C) 2011 - 2013 ArkCORE <http://www.arkania.net/>
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
#include "throne_of_the_tides.h"

Position const EventPositions[] =
{{-139.756f, 802.663f, 796.641f, 3.136672f}, // Start Point
{-132.084763f, 798.554138f, 796.976257f, 3.155597f}, // Invader Spawnpoints
{-132.03f, 806.99f, 797.f, 3.06f},
{-103.577f, 806.394f, 796.965f, 3.06048f},
{-72.4102f, 798.265f, 796.97f, 3.12723f}, // Spiritmender Spawnpoints
{-72.2161f, 806.563f, 796.966f, 3.09581f},
{-104.031f, 798.42f, 796.957f, 3.14216f},
{-45.626f, 802.385f, 797.117f, 3.1178f}, // Murloc Spawnposition
{23.623f, 802.433f, 806.317f, 6.254f}, // Naz'jar despawn Point
{32.1444f, 802.431f, 806.317f, 3.11295f}, // 2. Event Part Tempest Witch
{33.6948f, 805.856f, 806.317f, 3.06583f}, // Invader
{33.4031f, 799.003f, 806.317f, 3.12473f},
{35.352394f, 809.527f, 806.317f, 3.05f}, // Spiritmender
{34.6015f, 795.f, 806.317f, 3.081633f}};

class mob_lady_nazjar_event : public CreatureScript
{
public:
    mob_lady_nazjar_event() : CreatureScript("mob_lady_nazjar_event") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_lady_nazjar_eventAI (creature);
    }

    struct mob_lady_nazjar_eventAI : public ScriptedAI
    {
        mob_lady_nazjar_eventAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        bool eventProgress;
        uint8 nextStep;
        uint32 timer;

        void Reset()
        {
            if(instance->GetData(DATA_LADY_NAZJAR) == DONE)
                me->ForcedDespawn(0);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);

            eventProgress = false;
            nextStep = 0;

            timer = 1000;
        }

        void UpdateAI(const uint32 diff)
        {
            if(!instance)
                return;

            if (!eventProgress)
            {
                if (timer <= diff)
                {
                    if (Player* target = me->FindNearestPlayer(143.0f, true))
                    {
                        if (!target->isGameMaster() && target->GetDistance(EventPositions[0]) < 15.f)
                        {
                            if(GameObject* door = me->FindNearestGameObject(GO_COMMANDER_ULTHOK_DOOR, 30.0f))
                                instance->HandleGameObject(0, false, door);

                            me->MonsterYell("Armies of the depths, wash over our enemies as a tide of death!",0,0);

                            eventProgress = true;

                            for(uint8 i = 1; i <= 3; i++)
                            {
                                if(Creature* invader = me->SummonCreature(NPC_NAZJAR_INVADER,EventPositions[i],TEMPSUMMON_MANUAL_DESPAWN))
                                    if(i != 3)
                                        invader->AI()->DoZoneInCombat(invader);
                            }

                            for(uint8 i = 4; i <= 6; i++)
                            {
                                if(Creature* spiritmender = me->SummonCreature(NPC_NAZJAR_SPIRITMENDER,EventPositions[i],TEMPSUMMON_MANUAL_DESPAWN))
                                    spiritmender->AI()->DoZoneInCombat(spiritmender);
                            }

                            nextStep = 4;
                        }
                    }

                    timer = 1000;

                } else timer -= diff;

            }else
            {
                if (timer <= diff)
                {
                    if(Player* target = me->FindNearestPlayer(143.0f, true))
                        if (!target->isGameMaster() && target->GetDistance(me) < 143)
                        {
                            for(uint8 i = 0; i <= 6; i++)
                            {
                                if(Creature* murloc = me->SummonCreature(NPC_DEEP_MURLOC_DRUDGE, EventPositions[7], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000))
                                {
                                    murloc->AI()->DoZoneInCombat(murloc);
                                    murloc->GetMotionMaster()->MovePoint(0, EventPositions[0]);
                                }
                            }
                        }

                        timer = 16000;

                } else timer -= diff;
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
        {
            if(summon->GetEntry() != NPC_DEEP_MURLOC_DRUDGE)
                nextStep--;

            if(nextStep == 0)
            {
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

                if(GameObject* door = me->FindNearestGameObject(GO_COMMANDER_ULTHOK_DOOR, 30.0f))
                    instance->HandleGameObject(0, true, door);

                me->MonsterYell("Meddlesome gnats! You think us defeated so easily?",0,0);
                me->GetMotionMaster()->MovePoint(0, EventPositions[8]);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != 0)
                return;

            me->SummonCreature(NPC_TEMPEST_WITCH,EventPositions[9], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 90000);

            for(uint8 i = 10; i <= 11; i++)
                me->SummonCreature(NPC_NAZJAR_INVADER,EventPositions[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 90000);

            for(uint8 i = 12; i <= 13; i++)
                me->SummonCreature(NPC_NAZJAR_SPIRITMENDER, EventPositions[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 90000);

            me->DisappearAndDie();
        }
    };
};

class go_totd_defense_system : public GameObjectScript
{
public:
    go_totd_defense_system() : GameObjectScript("go_totd_defense_system") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        if(InstanceScript* instance = go->GetInstanceScript())
        {
            Map::PlayerList const &PlayerList = go->GetMap()->GetPlayers();

            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    i->getSource()->SendCinematicStart(169);

            if(GameObject* door = go->FindNearestGameObject(GO_LADY_NAZJAR_DOOR,20.f))
                instance->HandleGameObject(0, true, door);
        }
        return false;
    }
};

void AddSC_throne_of_the_tides()
{
    new mob_lady_nazjar_event();
    new go_totd_defense_system();
}