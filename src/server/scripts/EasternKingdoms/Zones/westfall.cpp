/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * Copyright (C) 2011- 2013 ArkCore <https://www.arkania.net/>
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
 SDName: Westfall
 SD%Complete: 100
 SDComment: Quest support: 26271, 26228
 SDCategory: Westfall
 EndScriptData */

/* ContentData
 npc_hungry_hobo
 npc_OldHouse
 EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*
Script for quest Feeding the Hungry and the Hopeless (26271)
*/

enum eHobo
{
    QUEST_FEEDING_THE_HUNGRY    = 26271,
    STEW                        = 42617,
    SPELL_FULL_BELLY            = 79451,
};

class npc_hungry_hobo : public CreatureScript
{
    public:
    npc_hungry_hobo() : CreatureScript("npc_hungry_hobo") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_hungry_hoboAI (creature);
    }

    struct npc_hungry_hoboAI  : public ScriptedAI
    {
        npc_hungry_hoboAI(Creature* creature) : ScriptedAI(creature) {}

        uint8 count;
        uint32 Miam;

        void Reset()
        {
            count = 0;
            Miam = 2000;

            me->SetStandState(UNIT_STAND_STATE_SLEEP);
        }

        void Eat()
        {
            me->CastSpell(me, SPELL_FULL_BELLY, true);
            me->SetStandState(UNIT_STAND_STATE_SIT);
        }

        void UpdateAI(const uint32 diff)
        {
            if (Miam < diff)
            {
                if (Creature* stew = me->FindNearestCreature(STEW, 10.0f, true))
                {
                    if (me->HasAura(SPELL_FULL_BELLY) && count == 0)
                        return;

                    switch (count)
                    {
                        case 0:
                        {
                            me->RemoveStandFlags(UNIT_STAND_STATE_SLEEP);
                            me->SetStandFlags(UNIT_STAND_STATE_STAND);
                            Miam = 1000;
                            count++;
                            break;
                        }
                        case 1:
                        {
                            Eat();
                            Miam = 2000;
                            count++;
                            break;
                        }
                        case 2:
                        {
                            if (Unit* player = me->GetPlayer(*stew, stew->GetUInt64Value(UNIT_FIELD_SUMMONEDBY)))
                                player->ToPlayer()->KilledMonsterCredit(42617, NULL);
                                Miam = 25000;
                                count++;
                                break;
                        }
                        default:
                        break;
                    }
                }
                else Miam = 3000;

                if (count == 3)
                    Reset();
            }
            else Miam -= diff;
        }
    };
};

/* Add support for quest 26228 : Livin' the Life */
enum eOldHouse
{
    QUEST_LIVIN_THE_LIFE    = 26228
};
class npc_OldHouse : public CreatureScript
{
    public:
    npc_OldHouse() : CreatureScript("npc_OldHouse") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_OldHouseAI (creature);
    }

    struct npc_OldHouseAI  : public ScriptedAI
    {
        npc_OldHouseAI(Creature* creature) : ScriptedAI(creature) {}

        uint8 count;
        uint32 Timer;
        uint64 ShadowyGUID;
        uint64 GlubtokGUID;
		uint64 PlayerGUID;

        bool bSummoned;

        void Reset()
        {
            count = 0;
            Timer = 1000;
            ShadowyGUID = 0;
            GlubtokGUID = 0;
			PlayerGUID = 0;
            bSummoned = false;
            SummonEvent();
        }

		void SummonEvent()
        {
            if(!bSummoned)
            {
                if (Creature* glubtok = me->SummonCreature(42492, -9846.5f, 1395.5f, 37.5534f, 0.63f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 85000))
                if (Creature* shadowy = me->SummonCreature(42515, -9825.17f, 1409.41f, 36.654f, 3.66f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 85000))
                {
					shadowy->CastSpell(shadowy, 79192, true);
                    GlubtokGUID = glubtok->GetGUID();
                    ShadowyGUID = shadowy->GetGUID();

                    bSummoned = true;
                    Timer = 250;
                }
            }
        }
		 void UpdateAI(const uint32 diff)
        {
            if (Timer <= diff)
            {
				if(bSummoned)
				{
                    if (Creature* glubtok = me->GetCreature(*me, GlubtokGUID))
                    if (Creature* shadowy = me->GetCreature(*me, ShadowyGUID))
                    {
                        switch (count)
                        {
                            case 0:
                            {
                                Timer = 2500;
                                count++;
                                break;
                            }
							case 1:
                            {
                                shadowy->SetWalk(true);
                                shadowy->GetMotionMaster()->MovePoint(0, -9841.677f, 1400.042f, 37.129f);
                                Timer = 7000;
                                count++;
                                break;
                            }
                            case 2:
                            {
                                glubtok->MonsterSay("What little humie want? Why you call Glubtok?", 0, 0);
								glubtok->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 5000;
                                count++;
                                break;
                            }
                            case 3:
                            {
                                shadowy->MonsterSay("Sad... Is this the life you had hoped for, Glubtok? Running two-bit extortion operations out of a cave?", 0, 0);
								shadowy->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 8500;
                                count++;
                                break;
                            }
                            case 4:
                            {
                                glubtok->MonsterSay("Glubtok crush you!", 0, 0);
								glubtok->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 4000;
                                count++;
                                break;
                            }
                            case 5:
                            {
                                shadowy->MonsterSay("Oh will you? Do you dare cross that line and risk your life?", 0, 0);
								shadowy->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 6500;
                                count++;
                                break;
                            }
                            case 6:
                            {
                                shadowy->MonsterSay("You may attempt to kill me - and fail - or you may take option two.", 0, 0);
								shadowy->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 6500;
                                count++;
                                break;
                            }
                            case 7:
                            {
                                glubtok->MonsterSay("What option two?", 0, 0);
								glubtok->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 4000;
                                count++;
                                break;
                            }
                            case 8:
                            {
                                shadowy->MonsterSay("You join me and I shower wealth and power upon you.", 0, 0);
								shadowy->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 7000;
                                count++;
                                break;
                            }
                            case 9:
                            {
                                glubtok->MonsterSay("So Glubtok have two choices: die or be rich and powerful?", 0, 0);
								glubtok->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 7000;
                                count++;
                                break;
                            }
                            case 10:
                            {
                                glubtok->MonsterSay("Glubtok take choice two.", 0, 0);
								glubtok->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 6000;
                                count++;
                                break;
                            }
                            case 11:
                            {
                                shadowy->MonsterSay("I thought you'd see it my way.", 0, 0);
								shadowy->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 6000;
                                count++;
                                break;
                            }
                            case 12:
                            {
                                shadowy->MonsterSay("I will call you when the dawning is upon us.", 0, 0);
								shadowy->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                Timer = 6000;
                                count++;
                                break;
                            }
                            case 13:
                            {
								PlayerGUID = me->GetUInt64Value(UNIT_FIELD_SUMMONEDBY);
								Player* player = me->GetPlayer(*me, PlayerGUID);
								player->CompleteQuest(QUEST_LIVIN_THE_LIFE);
								player->ExitVehicle();
                                me->ForcedDespawn(2000);
                                glubtok->ForcedDespawn(1000);
								shadowy->CastSpell(shadowy, 24222, true);
                                shadowy->ForcedDespawn(1000);
                                count = 0;
                            }
                            break;
                            default:
                            break;
                        }
                    }
                }
            }
            else Timer -= diff;
        }
    };
};

void AddSC_westfall() {
	new npc_hungry_hobo();
	new npc_OldHouse();
}
