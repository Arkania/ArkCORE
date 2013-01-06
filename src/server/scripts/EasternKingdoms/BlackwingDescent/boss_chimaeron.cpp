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
#include "blackwing_descent.h"

#define TARGETS_10 2
#define TARGETS_25 5

enum Events
{
    EVENT_DOUBLE_ATTACK = 1,
    EVENT_CAUSTIC_SLIME,
    EVENT_MASSACRE,
    EVENT_SEC_MASSACRE,
    EVENT_BREAK,
};

enum Actions
{
    ACTION_BILE_O_TRON_EVENT_START      = 1,
    ACTION_BILE_O_TRON_SYSTEM_FAILURE,
    ACTION_BILE_O_TRON_RESET,
};

enum Spells
{
    // Chimaeron
    SPELL_DOUBLE_ATTACK                 = 88826,
    SPELL_CAUSTIC_SLIME                 = 82935,
    SPELL_MASSACRE                      = 82848,
    SPELL_FEUD                          = 88872,
    SPELL_BREAK                         = 82881,

    SPELL_MORTALITY                     = 82934,
    SPELL_MORTALITY_RAID_DEBUFF         = 82890,

    // Bile O Tron
    SPELL_FINKLES_MIXTURE               = 82705,
    SPELL_FINKLES_MIXTURE_VISUAL        = 91106,
    SPELL_SYSTEM_FALURE                 = 88853,
    SPELL_REROUTE_POWER                 = 88861,
};

Position const BilePositions[6] =
{
    {-135.795151f, 15.569847f, 73.165909f, 4.646072f},
    {-129.176636f, -10.488489f, 73.079071f, 5.631739f},
    {-106.186249f, -18.533386f, 72.798332f, 1.555510f},
    {-77.951973f, 0.702321f, 73.093552f, 1.509125f},
    {-77.466125f, 31.038124f, 73.177673f, 4.489712f},
    {-120.426445f, 34.491863f, 72.057610f, 4.116642f},
};

class boss_chimaeron : public CreatureScript
{
public:
    boss_chimaeron() : CreatureScript("boss_chimaeron") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_chimaeronAI (creature);
    }

    struct boss_chimaeronAI: public BossAI
    {
        boss_chimaeronAI(Creature* creature) : BossAI(creature, DATA_CHIMAERON)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        uint8 phase;

        void Reset()
        {
            events.Reset();
            playerList.clear();
            me->SetReactState(REACT_PASSIVE);
            phase = 1;

            me->RemoveAura(SPELL_DOUBLE_ATTACK);
            me->RemoveAura(SPELL_MORTALITY);
            me->RemoveAura(SPELL_MORTALITY_RAID_DEBUFF);
            
            if(Creature* finkle_einhorn = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_FINKLE_EINHORN)))
                finkle_einhorn->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            if(Creature* bile_o_tron = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_BILE_O_TRON)))
                bile_o_tron->AI()->DoAction(ACTION_BILE_O_TRON_RESET);

            if(Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC,50.0f,true))
                nefarianHelperheroic->ForcedDespawn();

            _Reset();
        }
		
        void EnterCombat(Unit* /*who*/)
        {
           if(me->GetMap()->IsHeroic())
               me->SummonCreature(NPC_NEFARIAN_HELPER_HEROIC,-115.5546f, 45.403f, 79.078f, 4.57f ,TEMPSUMMON_MANUAL_DESPAWN);

            events.ScheduleEvent(EVENT_MASSACRE, urand(30000,35000));
            events.ScheduleEvent(EVENT_DOUBLE_ATTACK, urand(13000,15000));
            events.ScheduleEvent(EVENT_CAUSTIC_SLIME, urand(10000,12000));
            events.ScheduleEvent(EVENT_BREAK, urand(14000,16000));

            _EnterCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if(me->GetHealthPct() < 20 && phase == 1)
            {
                phase = 2;

                DoCast(me, SPELL_MORTALITY);
                DoCastAOE(SPELL_MORTALITY_RAID_DEBUFF);
				instance->DoSendNotifyToInstance("INSTANCE MESSAGE: Chimaeron's Frenzy"); // Notification de la Mortalite

                events.CancelEvent(EVENT_MASSACRE);
                events.CancelEvent(EVENT_BREAK);
                events.CancelEvent(EVENT_CAUSTIC_SLIME);
            }

            events.Update(diff);
            //_DoAggroPulse(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {

                case EVENT_MASSACRE:
                    DoCast(SPELL_MASSACRE);
                    DoCast(me,SPELL_FEUD);
					instance->DoSendNotifyToInstance("INSTANCE MESSAGE: Chimaeron's Massacre"); // Notification du Massacre

                    if(urand(0,2) == 0)
                        if(Creature* bile_o_tron = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_BILE_O_TRON)))
                        {
                            bile_o_tron->AI()->DoAction(ACTION_BILE_O_TRON_SYSTEM_FAILURE);
                            events.ScheduleEvent(EVENT_MASSACRE, 45000);
                        }else
                            events.ScheduleEvent(EVENT_MASSACRE, 27000);

                    DoCast(me,SPELL_FEUD);
                    break;

                case EVENT_DOUBLE_ATTACK:
                    DoCastVictim(SPELL_DOUBLE_ATTACK);
                    events.ScheduleEvent(EVENT_DOUBLE_ATTACK, urand(13000,15000));
                    break;

                case EVENT_CAUSTIC_SLIME:
				    SelectTargetList(playerList, RAID_MODE(TARGETS_10,TARGETS_25,TARGETS_10,TARGETS_25), SELECT_TARGET_RANDOM,1,100,true);
					for (std::list<Unit*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    {
                        Unit *pTemp = (*itr);
                        me->CastSpell(pTemp, SPELL_CAUSTIC_SLIME, true);
                    }
                    events.ScheduleEvent(EVENT_CAUSTIC_SLIME, urand(10000,12000));
                    break;

                case EVENT_BREAK:
                    DoCastVictim(SPELL_BREAK);
                    events.ScheduleEvent(EVENT_BREAK, 14000);
                    break;

                default:
                    break;
                }
            }		

            DoMeleeAttackIfReady();
        }

        private:
            std::list<Unit *> playerList;

        void DamageTaken(Unit* who, uint32& damage)
        {
            if(me->HasReactState(REACT_PASSIVE))
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if(Creature* bile_o_tron = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_BILE_O_TRON)))
            {
                bile_o_tron->RemoveAllAuras();
                bile_o_tron->GetMotionMaster()->MoveIdle();
            }

            if(Creature* nefarianHelperheroic = me->FindNearestCreature(NPC_NEFARIAN_HELPER_HEROIC,50.0f,true))
                nefarianHelperheroic->ForcedDespawn();

            _JustDied();
        }
    };
};

class mob_finkle_einhorn : public CreatureScript
{
public:
    mob_finkle_einhorn() : CreatureScript("mob_finkle_einhorn") { }

    bool OnGossipHello(Player* pPlayer, Creature* creature)
    {

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Aidez-nous avec Bille-O-Tron 800!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(1,creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        pPlayer->CLOSE_GOSSIP_MENU();

        if(InstanceScript* instance = creature->GetInstanceScript())
        {
            if(Creature* bile_o_tron = ObjectAccessor::GetCreature(*creature,instance->GetData64(NPC_BILE_O_TRON)))
            {
                bile_o_tron->AI()->DoAction(ACTION_BILE_O_TRON_EVENT_START);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }
        }
        return true;
    }
};

class mob_bile_o_tron : public CreatureScript
{
public:
    mob_bile_o_tron() : CreatureScript("mob_bile_o_tron") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_bile_o_tronAI (creature);
    }

    struct mob_bile_o_tronAI : public ScriptedAI
    {
        mob_bile_o_tronAI(Creature* creature) : ScriptedAI(creature), waypoint(7), uiSystemFailureTimer(0), activated(false)
        {
            instance = creature->GetInstanceScript();
            creature->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);

            isFailureActive = false;
        }

        InstanceScript* instance;
        uint8 waypoint;
        uint32 uiSystemFailureTimer;
        bool activated;
        bool isFailureActive;

        void UpdateAI(const uint32 diff)
        {
            if(!activated)
                return;

            if(!me->HasAura(SPELL_SYSTEM_FALURE) && !me->HasAura(SPELL_FINKLES_MIXTURE))
                me->AddAura(SPELL_FINKLES_MIXTURE, me);

            if(uiSystemFailureTimer <= diff && isFailureActive)
            { // Reroute Power
                me->RemoveAura(SPELL_SYSTEM_FALURE);
                me->GetMotionMaster()->MovePoint(1,BilePositions[waypoint]);

                isFailureActive = false;
                DoCast(me,SPELL_FINKLES_MIXTURE_VISUAL,true);
            }
            else uiSystemFailureTimer -= diff;
        }

        void DoAction(const int32 action)
        {

            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();

            switch(action)
            {

            case ACTION_BILE_O_TRON_EVENT_START:
                DoCast(me,SPELL_FINKLES_MIXTURE_VISUAL,true);
                waypoint = 8;
                me->GetMotionMaster()->MovePoint(1, BilePositions[0]);
                activated = true;
                isFailureActive = false;
                break;

            case ACTION_BILE_O_TRON_SYSTEM_FAILURE:
                if(!activated)
                    break;

                if(Creature* finkle_einhorn = ObjectAccessor::GetCreature(*me,instance->GetData64(NPC_FINKLE_EINHORN)))
                    finkle_einhorn->MonsterYell("Un p'tit coup de main ?",0,0);

                me->RemoveAllAuras();
                DoCast(me,SPELL_REROUTE_POWER, true);
                DoCast(me,SPELL_SYSTEM_FALURE, true);
                isFailureActive = true;
                uiSystemFailureTimer = 26000;
                break;

            case ACTION_BILE_O_TRON_RESET:
                me->RemoveAllAuras();
                me->GetMotionMaster()->MoveTargetedHome();
                waypoint = 7;
                uiSystemFailureTimer = 0;
                activated = false;
                break;
            }
        }

        void JustReachedHome()
        {
            me->RemoveAllAuras();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || waypoint == 7)
                return;

            if(waypoint >= 5)
                waypoint = 0;
            else
                waypoint++;

            me->GetMotionMaster()->MovePoint(1,BilePositions[waypoint]);
        }
    };
};

void AddSC_boss_chimaeron()
{
    new boss_chimaeron();
    new mob_finkle_einhorn();
    new mob_bile_o_tron();
}