/*
 * Copyright (C) 2005 - 2013 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2013 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2006 - 2013 ScriptDev2 <http://www.scriptdev2.com/>
 *
 * Copyright (C) 2010 - 2013 ProjectSkyfire <http://www.projectskyfire.org/>
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

#include "Chat.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"

class modify_commandscript: public CommandScript
{
public:
    modify_commandscript () :
            CommandScript("modify_commandscript")
    {
    }

    ChatCommand* GetCommands() const
    {
        static ChatCommand modifyCommandTable[] =
        {
            { "hp",             SEC_MODERATOR,      false, &HandleModifyHPCommand,          "", NULL },
            { "mana",           SEC_MODERATOR,      false, &HandleModifyManaCommand,        "", NULL },
            { "rage",           SEC_MODERATOR,      false, &HandleModifyRageCommand,        "", NULL },
            { "runicpower",     SEC_MODERATOR,      false, &HandleModifyRunicPowerCommand,  "", NULL },
            { "energy",         SEC_MODERATOR,      false, &HandleModifyEnergyCommand,      "", NULL },
            { "money",          SEC_MODERATOR,      false, &HandleModifyMoneyCommand,       "", NULL },
            { "speed",          SEC_MODERATOR,      false, &HandleModifySpeedCommand,       "", NULL },
            { "swim",           SEC_MODERATOR,      false, &HandleModifySwimCommand,        "", NULL },
            { "scale",          SEC_MODERATOR,      false, &HandleModifyScaleCommand,       "", NULL },
            { "bit",            SEC_MODERATOR,      false, &HandleModifyBitCommand,         "", NULL },
            { "bwalk",          SEC_MODERATOR,      false, &HandleModifyBWalkCommand,       "", NULL },
            { "fly",            SEC_MODERATOR,      false, &HandleModifyFlyCommand,         "", NULL },
            { "aspeed",         SEC_MODERATOR,      false, &HandleModifyASpeedCommand,      "", NULL },
            { "faction",        SEC_MODERATOR,      false, &HandleModifyFactionCommand,     "", NULL },
            { "spell",          SEC_MODERATOR,      false, &HandleModifySpellCommand,       "", NULL },
            { "tp",             SEC_MODERATOR,      false, &HandleModifyTalentCommand,      "", NULL },
            { "mount",          SEC_MODERATOR,      false, &HandleModifyMountCommand,       "", NULL },
            { "currency",       SEC_MODERATOR,      false, &HandleModifyCurrencyCommand,    "", NULL },
            { "rep",            SEC_GAMEMASTER,     false, &HandleModifyRepCommand,         "", NULL },
            { "drunk",          SEC_MODERATOR,      false, &HandleModifyDrunkCommand,       "", NULL },
            { "standstate",     SEC_GAMEMASTER,     false, &HandleModifyStandStateCommand,  "", NULL },
            { "morph",          SEC_GAMEMASTER,     false, &HandleModifyMorphCommand,       "", NULL },
            { "phase",          SEC_ADMINISTRATOR,  false, &HandleModifyPhaseCommand,       "", NULL },
            { "gender",         SEC_GAMEMASTER,     false, &HandleModifyGenderCommand,      "", NULL },
	        { "honor",          SEC_GAMEMASTER,     false, &HandleModifyHonorCommand,       "", NULL },
            { "conquest",       SEC_GAMEMASTER,     false, &HandleModifyHonorCommand,       "", NULL },
            { "valor",          SEC_GAMEMASTER,     false, &HandleModifyHonorCommand,       "", NULL },
            { "justice",        SEC_GAMEMASTER,     false, &HandleModifyHonorCommand,       "", NULL },	
            { NULL,             0,                  false, NULL,                            "", NULL } };
        static ChatCommand commandTable[] =
        {
            { "modify",         SEC_MODERATOR,      false, NULL,                            "", modifyCommandTable },
            { NULL,             0,                  false, NULL,                            "", NULL } };
        return commandTable;
    }

    //Edit Player HP
    static bool HandleModifyHPCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        int32 hp = atoi((char*) args);
        int32 hpm = atoi((char*) args);

        if (hp < 1 || hpm < 1 || hpm < hp)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (handler->HasLowerSecurity(chr, 0))
            return false;

        handler->PSendSysMessage(LANG_YOU_CHANGE_HP, handler->GetNameLink(chr).c_str(), hp, hpm);
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_HP_CHANGED, handler->GetNameLink().c_str(), hp, hpm);

        chr->SetMaxHealth(hpm);
        chr->SetHealth(hp);

        return true;
    }

    //Edit Player Mana
    static bool HandleModifyManaCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        int32 mana = atoi((char*) args);
        int32 manam = atoi((char*) args);

        if (mana <= 0 || manam <= 0 || manam < mana)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        handler->PSendSysMessage(LANG_YOU_CHANGE_MANA, handler->GetNameLink(chr).c_str(), mana, manam);
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_MANA_CHANGED, handler->GetNameLink().c_str(), mana, manam);

        chr->SetMaxPower(POWER_MANA, manam);
        chr->SetPower(POWER_MANA, mana);

        return true;
    }

    //Edit Player Energy
    static bool HandleModifyEnergyCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        // char* pmana = strtok((char*)args, " ");
        // if (!pmana)
        //     return false;

        // char* pmanaMax = strtok(NULL, " ");
        // if (!pmanaMax)
        //     return false;

        // int32 manam = atoi(pmanaMax);
        // int32 mana = atoi(pmana);

        int32 energy = atoi((char*) args) * 10;
        int32 energym = atoi((char*) args) * 10;

        if (energy <= 0 || energym <= 0 || energym < energy)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player *chr = handler->getSelectedPlayer();
        if (!chr)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        handler->PSendSysMessage(LANG_YOU_CHANGE_ENERGY, handler->GetNameLink(chr).c_str(), energy / 10, energym / 10);
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_ENERGY_CHANGED, handler->GetNameLink().c_str(), energy / 10, energym / 10);

        chr->SetMaxPower(POWER_ENERGY, energym);
        chr->SetPower(POWER_ENERGY, energy);

        sLog->outDetail(handler->GetArkCoreString(LANG_CURRENT_ENERGY), chr->GetMaxPower(POWER_ENERGY));

        return true;
    }

    //Edit Player Rage
    static bool HandleModifyRageCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        // char* pmana = strtok((char*)args, " ");
        // if (!pmana)
        //     return false;

        // char* pmanaMax = strtok(NULL, " ");
        // if (!pmanaMax)
        //     return false;

        // int32 manam = atoi(pmanaMax);
        // int32 mana = atoi(pmana);

        int32 rage = atoi((char*) args) * 10;
        int32 ragem = atoi((char*) args) * 10;

        if (rage <= 0 || ragem <= 0 || ragem < rage)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        handler->PSendSysMessage(LANG_YOU_CHANGE_RAGE, handler->GetNameLink(chr).c_str(), rage / 10, ragem / 10);
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_RAGE_CHANGED, handler->GetNameLink().c_str(), rage / 10, ragem / 10);

        chr->SetMaxPower(POWER_RAGE, ragem);
        chr->SetPower(POWER_RAGE, rage);

        return true;
    }

    // Edit Player Runic Power
    static bool HandleModifyRunicPowerCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        int32 rune = atoi((char*) args) * 10;
        int32 runem = atoi((char*) args) * 10;

        if (rune <= 0 || runem <= 0 || runem < rune)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_YOU_CHANGE_RUNIC_POWER, handler->GetNameLink(chr).c_str(), rune / 10, runem / 10);
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_RUNIC_POWER_CHANGED, handler->GetNameLink().c_str(), rune / 10, runem / 10);

        chr->SetMaxPower(POWER_RUNIC_POWER, runem);
        chr->SetPower(POWER_RUNIC_POWER, rune);

        return true;
    }

    //Edit Player Faction
    static bool HandleModifyFactionCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* pfactionid = handler->extractKeyFromLink((char*) args, "Hfaction");

        Creature* chr = handler->getSelectedCreature();
        if (!chr)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!pfactionid)
        {
            if (chr)
            {
                uint32 factionid = chr->getFaction();
                uint32 flag = chr->GetUInt32Value(UNIT_FIELD_FLAGS);
                uint32 npcflag = chr->GetUInt32Value(UNIT_NPC_FLAGS);
                uint32 dyflag = chr->GetUInt32Value(UNIT_DYNAMIC_FLAGS);
                handler->PSendSysMessage(LANG_CURRENT_FACTION, chr->GetGUIDLow(), factionid, flag, npcflag, dyflag);
            }
            return true;
        }

        if (!chr)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 factionid = atoi(pfactionid);
        uint32 flag;

        char *pflag = strtok(NULL, " ");
        if (!pflag)
            flag = chr->GetUInt32Value(UNIT_FIELD_FLAGS);
        else
            flag = atoi(pflag);

        char* pnpcflag = strtok(NULL, " ");

        uint32 npcflag;
        if (!pnpcflag)
            npcflag = chr->GetUInt32Value(UNIT_NPC_FLAGS);
        else
            npcflag = atoi(pnpcflag);

        char* pdyflag = strtok(NULL, " ");

        uint32 dyflag;
        if (!pdyflag)
            dyflag = chr->GetUInt32Value(UNIT_DYNAMIC_FLAGS);
        else
            dyflag = atoi(pdyflag);

        if (!sFactionTemplateStore.LookupEntry(factionid))
        {
            handler->PSendSysMessage(LANG_WRONG_FACTION, factionid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_YOU_CHANGE_FACTION, chr->GetGUIDLow(), factionid, flag, npcflag, dyflag);

        chr->setFaction(factionid);
        chr->SetUInt32Value(UNIT_FIELD_FLAGS, flag);
        chr->SetUInt32Value(UNIT_NPC_FLAGS, npcflag);
        chr->SetUInt32Value(UNIT_DYNAMIC_FLAGS, dyflag);

        return true;
    }

    //Edit Player Spell
    static bool HandleModifySpellCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;
        char* pspellflatid = strtok((char*) args, " ");
        if (!pspellflatid)
            return false;

        char* pop = strtok(NULL, " ");
        if (!pop)
            return false;

        char* pval = strtok(NULL, " ");
        if (!pval)
            return false;

        uint16 mark;

        char* pmark = strtok(NULL, " ");

        uint8 spellflatid = atoi(pspellflatid);
        uint8 op = atoi(pop);
        uint16 val = atoi(pval);
        if (!pmark)
            mark = 65535;
        else
            mark = atoi(pmark);

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        handler->PSendSysMessage(LANG_YOU_CHANGE_SPELLFLATID, spellflatid, val, mark, handler->GetNameLink(chr).c_str());
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_SPELLFLATID_CHANGED, handler->GetNameLink().c_str(), spellflatid, val, mark);

        WorldPacket data(SMSG_SET_FLAT_SPELL_MODIFIER, (1 + 1 + 2 + 2));
        data << uint8(spellflatid);
        data << uint8(op);
        data << uint16(val);
        data << uint16(mark);
        chr->GetSession()->SendPacket(&data);

        return true;
    }

    //Edit Player TP
    static bool HandleModifyTalentCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        int tp = atoi((char*) args);
        if (tp < 0)
            return false;

        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            // check online security
            if (handler->HasLowerSecurity((Player*) target, 0))
                return false;
            target->ToPlayer()->SetFreeTalentPoints(tp);
            target->ToPlayer()->SendTalentsInfoData(false);
            return true;
        }
        else if (target->ToCreature()->isPet())
        {
            Unit *owner = target->GetOwner();
            if (owner && owner->GetTypeId() == TYPEID_PLAYER && ((Pet *) target)->IsPermanentPetFor(owner->ToPlayer()))
            {
                // check online security
                if (handler->HasLowerSecurity((Player*) owner, 0))
                    return false;
                ((Pet *) target)->SetFreeTalentPoints(tp);
                owner->ToPlayer()->SendTalentsInfoData(true);
                return true;
            }
        }

        handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
        handler->SetSentErrorMessage(true);
        return false;
    }

    //Edit Player Aspeed
    static bool HandleModifyASpeedCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        float ASpeed = (float) atof((char*) args);

        if (ASpeed > 50.0f)
            ASpeed = 50.0f;
        else if (ASpeed < 0.1f)
            ASpeed = 0.1f;

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        std::string chrNameLink = handler->GetNameLink(chr);

        if (chr->isInFlight())
        {
            handler->PSendSysMessage(LANG_CHAR_IN_FLIGHT, chrNameLink.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_YOU_CHANGE_ASPEED, ASpeed, chrNameLink.c_str());
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_ASPEED_CHANGED, handler->GetNameLink().c_str(), ASpeed);

        {
            //chr->SetSpeed(MOVE_WALK,    ASpeed, true); This is not needed anymore.
            chr->SetSpeed(MOVE_RUN, ASpeed, true);
            chr->SetSpeed(MOVE_SWIM, ASpeed, true);
            //chr->SetSpeed(MOVE_TURN,    ASpeed, true);
            chr->SetSpeed(MOVE_FLIGHT, ASpeed, true);
        }
        return true;
    }

    //Edit Player Speed
    static bool HandleModifySpeedCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        float Speed = (float) atof((char*) args);

        if (Speed > 50.0f)
            Speed = 50.0f;
        else if (Speed < 0.1f)
            Speed = 0.1f;

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        std::string chrNameLink = handler->GetNameLink(chr);

        if (chr->isInFlight())
        {
            handler->PSendSysMessage(LANG_CHAR_IN_FLIGHT, chrNameLink.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_YOU_CHANGE_SPEED, Speed, chrNameLink.c_str());
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_SPEED_CHANGED, handler->GetNameLink().c_str(), Speed);

        chr->SetSpeed(MOVE_RUN, Speed, true);

        return true;
    }

    //Edit Player Swim Speed
    static bool HandleModifySwimCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        float Swim = (float) atof((char*) args);

        if (Swim > 50.0f)
            Swim = 50.0f;
        else if (Swim < 0.1f)
            Swim = 0.1f;

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        std::string chrNameLink = handler->GetNameLink(chr);

        if (chr->isInFlight())
        {
            handler->PSendSysMessage(LANG_CHAR_IN_FLIGHT, chrNameLink.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_YOU_CHANGE_SWIM_SPEED, Swim, chrNameLink.c_str());
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_SWIM_SPEED_CHANGED, handler->GetNameLink().c_str(), Swim);

        chr->SetSpeed(MOVE_SWIM, Swim, true);

        return true;
    }

    //Edit Player Walk Speed
    static bool HandleModifyBWalkCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        float BSpeed = (float) atof((char*) args);

        if (BSpeed > 50.0f)
            BSpeed = 50.0f;
        else if (BSpeed < 0.1f)
            BSpeed = 0.1f;

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        std::string chrNameLink = handler->GetNameLink(chr);

        if (chr->isInFlight())
        {
            handler->PSendSysMessage(LANG_CHAR_IN_FLIGHT, chrNameLink.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_YOU_CHANGE_BACK_SPEED, BSpeed, chrNameLink.c_str());
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_BACK_SPEED_CHANGED, handler->GetNameLink().c_str(), BSpeed);

        chr->SetSpeed(MOVE_RUN_BACK, BSpeed, true);

        return true;
    }

    //Edit Player Fly
    static bool HandleModifyFlyCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        float FSpeed = (float) atof((char*) args);

        if (FSpeed > 50.0f)
            FSpeed = 50.0f;
        else if (FSpeed < 0.1f)
            FSpeed = 0.1f;

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        handler->PSendSysMessage(LANG_YOU_CHANGE_FLY_SPEED, FSpeed, handler->GetNameLink(chr).c_str());
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_FLY_SPEED_CHANGED, handler->GetNameLink().c_str(), FSpeed);

        chr->SetSpeed(MOVE_FLIGHT, FSpeed, true);

        return true;
    }

    //Edit Player Scale
    static bool HandleModifyScaleCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        float Scale = (float) atof((char*) args);

        if (Scale > 10.0f)
            Scale = 10.0f;
        else if (Scale < 0.1f)
            Scale = 0.1f;

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        handler->PSendSysMessage(LANG_YOU_CHANGE_SIZE, Scale, handler->GetNameLink(chr).c_str());
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_SIZE_CHANGED, handler->GetNameLink().c_str(), Scale);

        chr->SetFloatValue(OBJECT_FIELD_SCALE_X, Scale);

        return true;
    }

    //Enable Player mount
    static bool HandleModifyMountCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint16 mId = 1147;
        float speed = (float) 15;
        uint32 num = 0;

        num = atoi((char*) args);
        switch (num)
        {
        case 1:
            mId = 14340;
            break;
        case 2:
            mId = 4806;
            break;
        case 3:
            mId = 6471;
            break;
        case 4:
            mId = 12345;
            break;
        case 5:
            mId = 6472;
            break;
        case 6:
            mId = 6473;
            break;
        case 7:
            mId = 10670;
            break;
        case 8:
            mId = 10719;
            break;
        case 9:
            mId = 10671;
            break;
        case 10:
            mId = 10672;
            break;
        case 11:
            mId = 10720;
            break;
        case 12:
            mId = 14349;
            break;
        case 13:
            mId = 11641;
            break;
        case 14:
            mId = 12244;
            break;
        case 15:
            mId = 12242;
            break;
        case 16:
            mId = 14578;
            break;
        case 17:
            mId = 14579;
            break;
        case 18:
            mId = 14349;
            break;
        case 19:
            mId = 12245;
            break;
        case 20:
            mId = 14335;
            break;
        case 21:
            mId = 207;
            break;
        case 22:
            mId = 2328;
            break;
        case 23:
            mId = 2327;
            break;
        case 24:
            mId = 2326;
            break;
        case 25:
            mId = 14573;
            break;
        case 26:
            mId = 14574;
            break;
        case 27:
            mId = 14575;
            break;
        case 28:
            mId = 604;
            break;
        case 29:
            mId = 1166;
            break;
        case 30:
            mId = 2402;
            break;
        case 31:
            mId = 2410;
            break;
        case 32:
            mId = 2409;
            break;
        case 33:
            mId = 2408;
            break;
        case 34:
            mId = 2405;
            break;
        case 35:
            mId = 14337;
            break;
        case 36:
            mId = 6569;
            break;
        case 37:
            mId = 10661;
            break;
        case 38:
            mId = 10666;
            break;
        case 39:
            mId = 9473;
            break;
        case 40:
            mId = 9476;
            break;
        case 41:
            mId = 9474;
            break;
        case 42:
            mId = 14374;
            break;
        case 43:
            mId = 14376;
            break;
        case 44:
            mId = 14377;
            break;
        case 45:
            mId = 2404;
            break;
        case 46:
            mId = 2784;
            break;
        case 47:
            mId = 2787;
            break;
        case 48:
            mId = 2785;
            break;
        case 49:
            mId = 2736;
            break;
        case 50:
            mId = 2786;
            break;
        case 51:
            mId = 14347;
            break;
        case 52:
            mId = 14346;
            break;
        case 53:
            mId = 14576;
            break;
        case 54:
            mId = 9695;
            break;
        case 55:
            mId = 9991;
            break;
        case 56:
            mId = 6448;
            break;
        case 57:
            mId = 6444;
            break;
        case 58:
            mId = 6080;
            break;
        case 59:
            mId = 6447;
            break;
        case 60:
            mId = 4805;
            break;
        case 61:
            mId = 9714;
            break;
        case 62:
            mId = 6448;
            break;
        case 63:
            mId = 6442;
            break;
        case 64:
            mId = 14632;
            break;
        case 65:
            mId = 14332;
            break;
        case 66:
            mId = 14331;
            break;
        case 67:
            mId = 8469;
            break;
        case 68:
            mId = 2830;
            break;
        case 69:
            mId = 2346;
            break;
        default:
            handler->SendSysMessage(LANG_NO_MOUNT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player *chr = handler->getSelectedPlayer();
        if (chr == NULL)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(chr, 0))
            return false;

        handler->PSendSysMessage(LANG_YOU_GIVE_MOUNT, handler->GetNameLink(chr).c_str());
        if (handler->needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_MOUNT_GIVED, handler->GetNameLink().c_str());

        chr->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP);
        chr->Mount(mId);

        WorldPacket data(SMSG_FORCE_RUN_SPEED_CHANGE, (8 + 4 + 1 + 4));
        data.append(chr->GetPackGUID());
        data << (uint32) 0;
        data << (uint8) 0;          //new 2.1.0
        data << float(speed);
        chr->SendMessageToSet(&data, true);

        data.Initialize(SMSG_FORCE_SWIM_SPEED_CHANGE, (8 + 4 + 4));
        data.append(chr->GetPackGUID());
        data << (uint32) 0;
        data << float(speed);
        chr->SendMessageToSet(&data, true);

        return true;
    }

    //Edit Player money
    static bool HandleModifyMoneyCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, 0))
            return false;

        int32 addmoney = atoi((char*) args);

        uint32 moneyuser = target->GetMoney();

        if (addmoney < 0)
        {
            int32 newmoney = int32(moneyuser) + addmoney;

            sLog->outDetail(handler->GetArkCoreString(LANG_CURRENT_MONEY), moneyuser, addmoney, newmoney);
            if (newmoney <= 0)
            {
                handler->PSendSysMessage(LANG_YOU_TAKE_ALL_MONEY, handler->GetNameLink(target).c_str());
                if (handler->needReportToTarget(target))
                    (ChatHandler(target)).PSendSysMessage(LANG_YOURS_ALL_MONEY_GONE, handler->GetNameLink().c_str());

                target->SetMoney(0);
            }
            else
            {
                if (newmoney > MAX_MONEY_AMOUNT)
                    newmoney = MAX_MONEY_AMOUNT;

                handler->PSendSysMessage(LANG_YOU_TAKE_MONEY, abs(addmoney), handler->GetNameLink(target).c_str());
                if (handler->needReportToTarget(target))
                    (ChatHandler(target)).PSendSysMessage(LANG_YOURS_MONEY_TAKEN, handler->GetNameLink().c_str(), abs(addmoney));
                target->SetMoney(newmoney);
            }
        }
        else
        {
            handler->PSendSysMessage(LANG_YOU_GIVE_MONEY, addmoney, handler->GetNameLink(target).c_str());
            if (handler->needReportToTarget(target))
                (ChatHandler(target)).PSendSysMessage(LANG_YOURS_MONEY_GIVEN, handler->GetNameLink().c_str(), addmoney);

            if (addmoney >= MAX_MONEY_AMOUNT)
                target->SetMoney(MAX_MONEY_AMOUNT);
            else
                target->ModifyMoney(addmoney);
        }

        sLog->outDetail(handler->GetArkCoreString(LANG_NEW_MONEY), moneyuser, addmoney, target->GetMoney());

        return true;
    }

    //Edit Unit field
    static bool HandleModifyBitCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Unit *unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (unit->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity(unit->ToPlayer(), 0))
            return false;

        char* pField = strtok((char*) args, " ");
        if (!pField)
            return false;

        char* pBit = strtok(NULL, " ");
        if (!pBit)
            return false;

        uint16 field = atoi(pField);
        uint32 bit = atoi(pBit);

        if (field < OBJECT_END || field >= unit->GetValuesCount())
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (bit < 1 || bit > 32)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (unit->HasFlag(field, (1 << (bit - 1))))
        {
            unit->RemoveFlag(field, (1 << (bit - 1)));
            handler->PSendSysMessage(LANG_REMOVE_BIT, bit, field);
        }
        else
        {
            unit->SetFlag(field, (1 << (bit - 1)));
            handler->PSendSysMessage(LANG_SET_BIT, bit, field);
        }
        return true;
    }

    static bool HandleModifyCurrencyCommand (ChatHandler* handler, const char* args)
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

        char* currencyid_s = strtok((char*) args, " ");
        char* amount_s = strtok(NULL, "");
        if (!currencyid_s || !amount_s)
            return false;

        int32 currencyid = (int32) atoi(currencyid_s);
        int32 amount = (int32) atoi(amount_s);
        if (!sCurrencyTypesStore.LookupEntry(uint32(currencyid)))
        {
            handler->PSendSysMessage("Currency %u does not exist.", currencyid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        target->ModifyCurrency(uint32(currencyid), amount);

        handler->PSendSysMessage(LANG_COMMAND_MODIFY_HONOR, handler->GetNameLink(target).c_str(), target->GetCurrency(uint32(currencyid)));
        return true;
    }

    static bool HandleModifyRepCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player* target = NULL;
        target = handler->getSelectedPlayer();

        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, 0))
            return false;

        char* factionTxt = handler->extractKeyFromLink((char*) args, "Hfaction");
        if (!factionTxt)
            return false;

        uint32 factionId = atoi(factionTxt);

        int32 amount = 0;
        char *rankTxt = strtok(NULL, " ");
        if (!factionTxt || !rankTxt)
            return false;

        amount = atoi(rankTxt);
        if ((amount == 0) && (rankTxt[0] != '-') && !isdigit(rankTxt[0]))
        {
            std::string rankStr = rankTxt;
            std::wstring wrankStr;
            if (!Utf8toWStr(rankStr, wrankStr))
                return false;
            wstrToLower(wrankStr);

            int r = 0;
            amount = -42000;
            for (; r < MAX_REPUTATION_RANK; ++r)
            {
                std::string rank = handler->GetArkCoreString(ReputationRankStrIndex[r]);
                if (rank.empty())
                    continue;

                std::wstring wrank;
                if (!Utf8toWStr(rank, wrank))
                    continue;

                wstrToLower(wrank);

                if (wrank.substr(0, wrankStr.size()) == wrankStr)
                {
                    char *deltaTxt = strtok(NULL, " ");
                    if (deltaTxt)
                    {
                        int32 delta = atoi(deltaTxt);
                        if ((delta < 0) || (delta > ReputationMgr::PointsInRank[r] - 1))
                        {
                            handler->PSendSysMessage(LANG_COMMAND_FACTION_DELTA, (ReputationMgr::PointsInRank[r] - 1));
                            handler->SetSentErrorMessage(true);
                            return false;
                        }
                        amount += delta;
                    }
                    break;
                }
                amount += ReputationMgr::PointsInRank[r];
            }
            if (r >= MAX_REPUTATION_RANK)
            {
                handler->PSendSysMessage(LANG_COMMAND_FACTION_INVPARAM, rankTxt);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        FactionEntry const *factionEntry = sFactionStore.LookupEntry(factionId);

        if (!factionEntry)
        {
            handler->PSendSysMessage(LANG_COMMAND_FACTION_UNKNOWN, factionId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (factionEntry->reputationListID < 0)
        {
            handler->PSendSysMessage(LANG_COMMAND_FACTION_NOREP_ERROR, factionEntry->name, factionId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        target->GetReputationMgr().SetReputation(factionEntry, amount);
        handler->PSendSysMessage(LANG_COMMAND_MODIFY_REP, factionEntry->name, factionId, handler->GetNameLink(target).c_str(), target->GetReputationMgr().GetReputation(factionEntry));
        return true;
    }

    static bool HandleModifyDrunkCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 drunklevel = (uint32) atoi(args);
        if (drunklevel > 100)
            drunklevel = 100;

        uint16 drunkMod = drunklevel * 0xFFFF / 100;

        Player *target = handler->getSelectedPlayer();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        target->SetDrunkValue(drunkMod);

        return true;
    }
    
    //morph creature or player
    static bool HandleModifyMorphCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint16 display_id = (uint16) atoi((char*) args);

        Unit *target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        // check online security
        else if (target->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity((Player*) target, 0))
            return false;

        target->SetDisplayId(display_id);

        return true;
    }
    
    //set temporary phase mask for player
    static bool HandleModifyPhaseCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 phasemask = (uint32) atoi((char*) args);

        Unit *target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        // check online security
        else if (target->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity((Player*) target, 0))
            return false;

        target->SetPhaseMask(phasemask, true);

        return true;
    }
    
    //change standstate
    static bool HandleModifyStandStateCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 anim_id = atoi((char*) args);
        handler->GetSession()->GetPlayer()->SetUInt32Value(UNIT_NPC_EMOTESTATE, anim_id);

        return true;
    }
    
    static bool HandleModifyGenderCommand (ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player *player = handler->getSelectedPlayer();

        if (!player)
        {
            handler->PSendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        PlayerInfo const* info = sObjectMgr->GetPlayerInfo(player->getRace(), player->getClass());
        if (!info)
            return false;

        char const* gender_str = (char*) args;
        int gender_len = strlen(gender_str);

        Gender gender;

        if (!strncmp(gender_str, "male", gender_len))          // MALE
        {
            if (player->getGender() == GENDER_MALE)
                return true;

            gender = GENDER_MALE;
        }
        else if (!strncmp(gender_str, "female", gender_len))          // FEMALE
        {
            if (player->getGender() == GENDER_FEMALE)
                return true;

            gender = GENDER_FEMALE;
        }
        else
        {
            handler->SendSysMessage(LANG_MUST_MALE_OR_FEMALE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Set gender
        player->SetByteValue(UNIT_FIELD_BYTES_0, 2, gender);
        player->SetByteValue(PLAYER_BYTES_3, 0, gender);

        // Change display ID
        player->InitDisplayIds();

        char const* gender_full = gender ? "female" : "male";

        handler->PSendSysMessage(LANG_YOU_CHANGE_GENDER, handler->GetNameLink(player).c_str(), gender_full);

        if (handler->needReportToTarget(player))
            ChatHandler(player).PSendSysMessage(LANG_YOUR_GENDER_CHANGED, gender_full, handler->GetNameLink().c_str());

        return true;
    }

    static bool HandleModifyHonorCommand(ChatHandler* handler, const char* args)
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
        target->ModifyHonorPoints(amount);
        return true;
    }

    static bool HandleModifyConquestCommand(ChatHandler* handler, const char* args)
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
        target->ModifyConquestPoints(amount);
        return true;
    }

    static bool HandleModifyValorCommand(ChatHandler* handler, const char* args)
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
        target->ModifyValorPoints(amount);
        return true;
    }

    static bool HandleModifyJusticeCommand(ChatHandler* handler, const char* args)
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
        target->ModifyJusticePoints(amount);
        return true;
    }

};

void AddSC_modify_commandscript()
{
    new modify_commandscript();
}
