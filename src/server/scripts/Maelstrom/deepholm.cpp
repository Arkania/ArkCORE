/*
* Copyright (C) 2010 - 2012 Project SkyFire <http://www.projectskyfire.org/>
*
* Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License,  or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful,  but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not,  see <http://www.gnu.org/licenses/>.
*/

#include "ScriptPCH.h"
#include "ScriptedFollowerAI.h"

class npc_lodestone : public CreatureScript
{
    public:
        npc_lodestone() : CreatureScript("npc_lodestone") { }

    struct npc_lodestoneAI : public ScriptedAI
    {
        npc_lodestoneAI(Creature* creature) : ScriptedAI(creature) { }

        void JustDied(Unit* killer)
        {
            if(Player* player = killer->ToPlayer())
            {
                if(player->GetQuestStatus(27136) == QUEST_STATUS_INCOMPLETE)
                {
                    if(Creature* totem = me->FindNearestCreature(45088, 20.0f, true))
                    {
                        totem->CastSpell(totem, 84163, true);
                        player->KilledMonsterCredit(45091, 0);
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new npc_lodestoneAI(creature);
    }
};

#define CREW_SAY_1 "They poisoned our supplies... we had cultists onboard all along..."
#define CREW_SAY_2 "Everyone started dropping like flies... everyone who ate the rations."
#define CREW_SAY_3 "They tricked us into ambushing the Horde gunship... but why?"
#define CREW_SAY_4 "I heard them praying to their dark gods as everything went black... the Twilight's Hammer did this!"
#define CREW_SAY_5 "Twilight scum! You did this to us!"
class npc_slaincrewmember : public CreatureScript
{
    public:
        npc_slaincrewmember() : CreatureScript("npc_slaincrewmember") { }

    struct npc_slaincrewmemberAI : public ScriptedAI
    {
        npc_slaincrewmemberAI(Creature* creature) : ScriptedAI(creature) { }

        uint64 playerGUID;
        bool QuestInProgress;
        uint32 sayTimer;

        void Reset()
        {
            playerGUID = 0;
            QuestInProgress = false;
            sayTimer = 3000;
        }
        void SetData(uint32 Id,  uint32 Value)
        {
            switch(Id)
            {
                case 1: // Set the GUID of the player
                {
                    playerGUID = Value;
                    QuestInProgress = true;
                    break;
                }
            }
        }
        void UpdateAI(uint32 const diff)
        {
            if(!QuestInProgress)
                return;

            Player* player = Unit::GetPlayer(*me, playerGUID);

            if(!player)
                return;

            if(sayTimer <= diff)
            {
                switch(RAND(0, 1, 2, 3, 4))
                {
                    case 0:
                        me->MonsterSay(CREW_SAY_1, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 1:
                        me->MonsterSay(CREW_SAY_2, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 2:
                        me->MonsterSay(CREW_SAY_3, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 3:
                        me->MonsterSay(CREW_SAY_4, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 4:
                        me->MonsterSay(CREW_SAY_5, LANG_UNIVERSAL, NULL);
                        me->setFaction(14);
                        me->AddThreat(player, 53.0f);
                        me->AI()->AttackStart(player);
                        QuestInProgress = false;
                        break;
                }
            }
            else sayTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_slaincrewmemberAI(creature);
    }
};

enum eFlint
{
    QUEST_TAKE_HIM_TO_THE_EARTHCALLER = 26413,
    NPC_YEVAA = 42573,
};

/* ToDo
- Maybe there is a dialog between Flint and Yeeva
*/

class npc_flint_oremantle : public CreatureScript
{
public:
    npc_flint_oremantle() : CreatureScript("npc_flint_oremantle") { }

	
	bool OnGossipHello(Player* pPlayer, Creature* creature)
	{
		
		if(creature->isInCombat() || pPlayer->GetQuestStatus(QUEST_TAKE_HIM_TO_THE_EARTHCALLER) != QUEST_STATUS_INCOMPLETE)
		return false;
		
		char const* _message = "Follow me to the Earthcaller!";	
		pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,_message,GOSSIP_SENDER_MAIN ,GOSSIP_ACTION_INFO_DEF+1);
		pPlayer->SEND_GOSSIP_MENU(68,creature->GetGUID());

		return true;
	}

	bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 uiSender, uint32 uiAction)
	{
		pPlayer->PlayerTalkClass->ClearMenus();

		pPlayer->CLOSE_GOSSIP_MENU();

         if (npc_flint_oremantleAI* npc_flint_oremantleAI = CAST_AI(npc_flint_oremantle::npc_flint_oremantleAI, creature->AI()))
         {
                creature->SetStandState(UNIT_STAND_STATE_STAND);
                npc_flint_oremantleAI->StartFollow(pPlayer, 35, 0);

				creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
         }
	
		return true;
	}
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_flint_oremantleAI(creature);
    }

    struct npc_flint_oremantleAI : public FollowerAI
    {
        npc_flint_oremantleAI(Creature* creature) : FollowerAI(creature), HomePosition(creature->GetHomePosition()) { }

		Position HomePosition;

		void Reset()
        {
			me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void MoveInLineOfSight(Unit* who)
        {
            FollowerAI::MoveInLineOfSight(who);

            if (!me->getVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && who->GetEntry() == NPC_YEVAA)
            {
                if (me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
                {
                    if (Player* player = GetLeaderForFollower())
                    {
                        if (player->GetQuestStatus(QUEST_TAKE_HIM_TO_THE_EARTHCALLER) == QUEST_STATUS_INCOMPLETE)
							player->KilledMonsterCredit(44207, 0);

						me->DespawnOrUnsummon(30000);
                    }

                    SetFollowComplete(true);
                }
            }
        }
    };
};

void AddSC_deepholm()
{
    new npc_lodestone();
    new npc_slaincrewmember();
	new npc_flint_oremantle();
}
