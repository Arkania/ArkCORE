/*
 * Copyright (C) 2012 - 2013 ArkCORE <http://www.arkania.net/>
 * 
 * Copyright (C) 2008 - 2013 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
 Name: currency_commandscript
 %Complete: 100
 Comment: All currency related commands except modifies.
 Category: commandscripts
 EndScriptData */

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Chat.h"

class currency_commandscript: public CommandScript
{
public:
    currency_commandscript() : CommandScript("currency_commandscript") {}

    ChatCommand* GetCommands() const
    {
        static ChatCommand honorAddCommandTable[] = 
        {
            { "kill", SEC_GAMEMASTER, false, &HandleHonorAddKillCommand, "", NULL },
            { "", SEC_GAMEMASTER, false, &HandleHonorAddCommand, "", NULL },
            { NULL, 0, false, NULL, "", NULL } 
        };

        static ChatCommand honorCommandTable[] = 
        {
            { "add", SEC_GAMEMASTER, false, NULL, "", honorAddCommandTable },
            { "update", SEC_GAMEMASTER, false, &HandleHonorUpdateCommand, "", NULL },
            { NULL, 0, false, NULL, "", NULL } 
        };

        static ChatCommand conquestCommandTable[] = 
        {
            { "add", SEC_GAMEMASTER, false, &HandleConquestAddCommand, "", NULL },
            { NULL, 0, false, NULL, "", NULL } 
        };

        static ChatCommand valorCommandTable[] = 
        {
            { "add", SEC_GAMEMASTER, false, &HandleValorAddCommand, "", NULL },
            { NULL, 0, false, NULL, "", NULL } 
        };

        static ChatCommand justiceCommandTable[] = 
        {
            { "add", SEC_GAMEMASTER, false, &HandleJusticeAddCommand, "", NULL },
            { NULL, 0, false, NULL, "", NULL } 
        };

        static ChatCommand commandTable[] = 
        {
            { "honor", SEC_GAMEMASTER, false, NULL, "", honorCommandTable },
            { "conquest", SEC_GAMEMASTER, false, NULL, "", conquestCommandTable },
            { "valor", SEC_GAMEMASTER, false, NULL, "", valorCommandTable },
            { "justice", SEC_GAMEMASTER, false, NULL, "", justiceCommandTable },
            { NULL, 0, false, NULL, "", NULL }
        };

        return commandTable;
    }

    static bool HandleHonorAddCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player *target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, 0))
            return false;

        uint32 amount = (uint32) atoi(args);
        target->AddHonorPoints(amount);
        return true;
    }

    static bool HandleHonorAddKillCommand(ChatHandler* handler, const char* /*args*/)
    {
        Unit *target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (target->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity((Player*) target, 0))
            return false;

        handler->GetSession()->GetPlayer()->RewardHonor(target, 1);
        return true;
    }

    static bool HandleHonorUpdateCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player *target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, 0))
            return false;

        target->UpdateHonorFields();
        return true;
    }

    static bool HandleConquestAddCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player *target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, 0))
            return false;

        uint32 amount = (uint32) atoi(args);
        target->AddConquestPoints(amount);
        return true;
    }

    static bool HandleValorAddCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player *target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, 0))
            return false;

        uint32 amount = (uint32) atoi(args);
        target->AddValorPoints(amount);
        return true;
    }

    static bool HandleJusticeAddCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player *target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, 0))
            return false;

        uint32 amount = (uint32) atoi(args);
        target->AddJusticePoints(amount);
        return true;
    }
};

void AddSC_currency_commandscript()
{
    new currency_commandscript();
}
