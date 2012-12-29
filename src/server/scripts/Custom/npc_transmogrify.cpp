/*
* Copyright (C) 2011-2012 ProjectStudioMirage <http://www.studio-mirage.fr/>
* Copyright (C) 2011-2012 https://github.com/Asardial
*/


#include "ScriptPCH.h"

enum TransmogrifyActions {
    ACTION_TRANSMOGRIFY_ADD_DISPLAY,
    ACTION_TRANSMOGRIFY_REMOVE_DISPLAY
};

const uint16 PriceInGold = 1000 * 100 * 100; // 1k golds

class npc_transmogrify : public CreatureScript
{
    public:
        npc_transmogrify() : CreatureScript("npc_transmogrify") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Transmogrifer!", GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_ADD_DISPLAY);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Remove Transmogrifer", GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_REMOVE_DISPLAY);
            pPlayer->SEND_GOSSIP_MENU(51000, pCreature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (action)
            {
                case ACTION_TRANSMOGRIFY_ADD_DISPLAY:
                    TransmogrifyItem(player, creature);
                    break;
                case ACTION_TRANSMOGRIFY_REMOVE_DISPLAY:
                    ClearItem(player, creature);
                    break;
            }
            return true;
        }

        void TransmogrifyItem(Player* player, Creature* creature)
        {
            ChatHandler handler(player);
            Item *trItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
            Item *displayItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START + 1);
            if (!trItem || !displayItem)
            {
                handler.PSendSysMessage("Put your items in slot 1 and 2 in your bag!");
                return;
            }

            if (!player->HasEnoughMoney(PriceInGold))
            {
                handler.PSendSysMessage("It costs %u gold!", PriceInGold);
                return;
            }

            uint8 result = trItem->SetFakeDisplay(displayItem->GetProto()->ItemId);
            switch (result)
            {
                case FAKE_ERR_CANT_FIND_ITEM:
                    handler.PSendSysMessage("Your item was not found!");
                    break;

                case FAKE_ERR_WRONG_QUALITY:
                    handler.PSendSysMessage("The item is of incorrect quality!");
                    break;

                case FAKE_ERR_DIFF_SLOTS:
                    handler.PSendSysMessage("The items are for different slots!");
                    break;

                case FAKE_ERR_DIFF_CLASS:
                    handler.PSendSysMessage("Item is for a different class!");
                    break;

                case FAKE_ERR_DIFF_RACE:
                    handler.PSendSysMessage("Item is for a different race!");
                    break;

                case FAKE_ERR_OK:
                {
                    WorldPacket data;
                    data << uint8(INVENTORY_SLOT_BAG_0);
                    data << uint8(trItem->GetSlot());
                    player->GetSession()->HandleAutoEquipItemOpcode(data);

                    player->ModifyMoney(-1 * PriceInGold);
                    creature->GetAI()->DoCast(63491);
                    break;
                }
            }
        }

        void ClearItem(Player *player, Creature* creature)
        {
            ChatHandler handler(player);
            Item *trItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
            if (!trItem)
            {
                handler.PSendSysMessage("Put the item in the first slot of your bag");
                return;
            }

            trItem->RemoveFakeDisplay();

            WorldPacket data;
            data << uint8(INVENTORY_SLOT_BAG_0);
            data << uint8(trItem->GetSlot());
            player->GetSession()->HandleAutoEquipItemOpcode(data);

            creature->GetAI()->DoCast(63491);
        }
};

void AddSC_transmogrify_script()
{
    new npc_transmogrify;
}
