/*
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

/* ScriptData
Name: credits_commandscript
%Complete: 100
Comment: This shows ArkCORE credits.
EndScriptData */

#include "ScriptPCH.h"
#include "Chat.h"

// **** Script Info ****
class credits_commandscript : public CommandScript
{
    public:
        credits_commandscript() : CommandScript("credits_commandscript") { }

        static bool HandleCreditsCommand(ChatHandler* handler, const char* /*args*/)
        {
			handler->PSendSysMessage("");
            handler->PSendSysMessage("__[ArkCORE Credits]______________________________________________");
			sLog->outString("This command lists the people, projects, and urls");
			sLog->outString("that we would like to thank for their contribution to our project,");
			sLog->outString("whether their influence was direct or indirect.");
			sLog->outString("");
			sLog->outString("Thanks goes out to the following people for various patches and/or code");
			handler->PSendSysMessage("Chameleon, AlterEgo, Fabi, LordJZ, Azazel, Dvlpr, Brecky, Keany, Arktus, Sovak");
			handler->PSendSysMessage("");
			sLog->outString("The following people have contributed directly to our project:");
			handler->PSendSysMessage("Blizz, raxume, cooler, Dekona, openmage, Venugh, Naios, billykitty, chark01,");
			handler->PSendSysMessage("cocolino, Georgian Constantin, gpn39f, h.norrt, Maibenrai, MysteriousSoul,");
			handler->PSendSysMessage("Nation, robo2104, Theoderic, wazy, Yuniorvoltes, zxelf, Aegwynn, BladeFight,");
			handler->PSendSysMessage("Walkum, wlasser, jorex, Dan Pendleton, Nibelar, vandellan, xkaixer, Atomic,");
			handler->PSendSysMessage("dimiandre, Keital, Myst, PortgasDAce, Red Sonja, Redneo, Arcane, AriDEV, Bootz,");
			handler->PSendSysMessage("DJScias, Dreadii, espargon, FailZorD, impas, Intel, JohnDeere, misimouse,");
			handler->PSendSysMessage("Naffbeats, pek2011, PrinceCreed, sanctum32, sharq, thehacker66, Winston,");
			handler->PSendSysMessage("Spyder, drakeos, kraven5, Booman666, gaal, nantesfer, Mrbytes, Mikadmin.");
			handler->PSendSysMessage("");
			sLog->outString("These people have helped the project via donations:");
			handler->PSendSysMessage("akaHaki, Betaman2k, bleu, Draken, GaryZywiec, glkrlos, ppops, Spazman2c,");
			handler->PSendSysMessage("Swiss-Rainbow.");
			handler->PSendSysMessage("");
			sLog->outString("We would also like to thank the following Sites/Communities:");
			handler->PSendSysMessage("ProjectSkyfire: http://www.projectskyfire.org");
			handler->PSendSysMessage("TrinityCore: http://www.trinitycore.org");
			handler->PSendSysMessage("Mangos: http://www.getmangos.com");
			handler->PSendSysMessage("");
			handler->PSendSysMessage("__[ArkCORE Credits]______________________________________________");
            return true;
        }

        ChatCommand* GetCommands() const
        {
            static ChatCommand CreditsCommandTable[] =
            {
                { "credits",        SEC_PLAYER,         true,   &HandleCreditsCommand,        "", NULL },
                { NULL,             0,                  false,  NULL,                         "", NULL }
            };
            return CreditsCommandTable;
        }
};

void AddSC_credits_commandscript()
{
    new credits_commandscript();
}
