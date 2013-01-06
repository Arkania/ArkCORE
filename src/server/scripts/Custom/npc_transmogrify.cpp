/*
* Copyright (C) 2011 - 2013 ArkCORE <http://www.arkania.net/>
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

// original author unknown
#include "ScriptPCH.h"

enum TransmogrifyActions {
    ACTION_TRANSMOGRIFY_ADD_DISPLAY,
    ACTION_TRANSMOGRIFY_REMOVE_DISPLAY
};

const int32 PriceInGold = 10000000; // 1k gold

class npc_transmogrify : public CreatureScript
{
    public:
        npc_transmogrify() : CreatureScript("npc_transmogrify") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Transmogrify!", GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_ADD_DISPLAY);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Remove Transmogrification", GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_REMOVE_DISPLAY);
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
                    player->PlayerTalkClass->CloseGossip();
                    break;
                case ACTION_TRANSMOGRIFY_REMOVE_DISPLAY:
                    ClearItem(player, creature);
                    player->PlayerTalkClass->CloseGossip();
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
                handler.PSendSysMessage(LANG_FAKEITEM_MISSING_ITEMS);
                return;
            }

            if (!player->HasEnoughMoney(PriceInGold))
            {
                handler.PSendSysMessage(LANG_FAKEITEM_MISSING_MONEY, PriceInGold);
                return;
            }

            uint8 result = trItem->SetFakeDisplay(displayItem->GetProto()->ItemId);
            switch (result)
            {
                case FAKE_ERR_CANT_FIND_ITEM:
                    handler.PSendSysMessage(LANG_FAKEITEM_MISSING_ITEM);
                    break;

                case FAKE_ERR_WRONG_QUALITY:
                    handler.PSendSysMessage(LANG_FAKEITEM_INVALID_QUALITY);
                    break;

                case FAKE_ERR_DIFF_INVENTORYTYPE:
                    handler.PSendSysMessage(LANG_FAKEITEM_DIFF_TYPE);
                    break;

                case FAKE_ERR_DIFF_CLASS:
                    handler.PSendSysMessage(LANG_FAKEITEM_DIFF_CLASS);
                    break;

                case FAKE_ERR_DIFF_RACE:
                    handler.PSendSysMessage(LANG_FAKEITEM_DIFF_RACE);
                    break;

                case FAKE_ERR_INVALID_CLASS:
                    handler.PSendSysMessage(LANG_FAKEITEM_INVALID_TYPE);
                    break;

                case FAKE_ERR_DIFF_SUBCLASS:
                    handler.PSendSysMessage(LANG_FAKEITEM_DIFF_TYPE);
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
                handler.PSendSysMessage(LANG_FAKEITEM_CLEARITEM);
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
