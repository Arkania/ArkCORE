/*
 * Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
 *
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
 *
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

#include "ScriptPCH.h"
#include "World.h"

class Reset_OnDuelEnd: public PlayerScript
{
public:
    Reset_OnDuelEnd () :
            PlayerScript("Reset_OnDuelEnd")
    {
    }

    void OnDuelEnd (Player* winner, Player* loser, DuelCompleteType type)
    {
        // reset cooldowns (in order) Elwyn, Durotar, Tirisfal, Tendrasil, Dun Morogh, Gurubashi Arena, Exodar, Mulgore
        if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN))
        {
            if (winner->GetZoneId() == 12 || winner->GetZoneId() == 14 || winner->GetZoneId() == 85 || winner->GetZoneId() == 141 || winner->GetZoneId() == 1 || winner->GetZoneId() == 5287 || winner->GetZoneId() == 3524 || winner->GetZoneId() == 215)
            {
                winner->ResetAllPowers();
                winner->RemoveArenaSpellCooldowns(true);
                loser->ResetAllPowers();
                loser->RemoveArenaSpellCooldowns(true);
            }
        }
    }
};

/*######
 ## duel_challenger_dk
 ######*/

#define GOSSIP_ACCEPT_DUEL      "I challenge you in duel!"

enum eDuelEnums
{
    SAY_DUEL_A = -1609080, SAY_DUEL_B = -1609081, SAY_DUEL_C = -1609082, SAY_DUEL_D = -1609083, SAY_DUEL_E = -1609084, SAY_DUEL_F = -1609085, SAY_DUEL_G = -1609086, SAY_DUEL_H = -1609087, SAY_DUEL_I = -1609088,

    SPELL_DUEL = 52996, SPELL_DUEL_VICTORY = 52994, SPELL_DUEL_FLAG = 52991,

    FACTION_HOSTILE = 2068
};

int32 m_auiRandomSayDK[] =
{ SAY_DUEL_A, SAY_DUEL_B, SAY_DUEL_C, SAY_DUEL_D, SAY_DUEL_E, SAY_DUEL_F, SAY_DUEL_G, SAY_DUEL_H, SAY_DUEL_I };

class duel_challenger_dk: public CreatureScript
{
public:
    duel_challenger_dk () :
            CreatureScript("duel_challenger_dk")
    {
    }

    bool OnGossipSelect (Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF)
        {
            pPlayer->CLOSE_GOSSIP_MENU();

            if (pPlayer->isInCombat() || pCreature->isInCombat())
                return true;

            if (duel_challenger_dkAI* pInitiateAI = CAST_AI(duel_challenger_dk::duel_challenger_dkAI, pCreature->AI()))
            {
                if (pInitiateAI->m_bIsDuelInProgress)
                    return true;
            }

            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_15);

            int32 uiSayId = rand() % (sizeof(m_auiRandomSayDK) / sizeof(int32));
            DoScriptText(m_auiRandomSayDK[uiSayId], pCreature, pPlayer);

            pPlayer->CastSpell(pCreature, SPELL_DUEL, false);
            pPlayer->CastSpell(pPlayer, SPELL_DUEL_FLAG, true);
        }
        return true;
    }

    bool OnGossipHello (Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->IsFullHealth())
        {
            if (pPlayer->HealthBelowPct(10))
                return true;

            if (pPlayer->isInCombat() || pCreature->isInCombat())
                return true;

            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ACCEPT_DUEL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI (Creature* pCreature) const
    {
        return new duel_challenger_dkAI(pCreature);
    }

    struct duel_challenger_dkAI: public CombatAI
    {
        duel_challenger_dkAI (Creature* pCreature) :
                CombatAI(pCreature)
        {
            m_bIsDuelInProgress = false;
        }

        bool lose;
        uint64 m_uiDuelerGUID;
        uint32 m_uiDuelTimer;
        bool m_bIsDuelInProgress;

        void Reset ()
        {
            lose = false;
            me->RestoreFaction();
            CombatAI::Reset();

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_15);

            m_uiDuelerGUID = 0;
            m_uiDuelTimer = 5000;
            m_bIsDuelInProgress = false;
        }

        void SpellHit (Unit* pCaster, const SpellEntry* pSpell)
        {
            if (!m_bIsDuelInProgress && pSpell->Id == SPELL_DUEL)
            {
                m_uiDuelerGUID = pCaster->GetGUID();
                m_bIsDuelInProgress = true;
            }
        }

        void DamageTaken (Unit* pDoneBy, uint32 &uiDamage)
        {
            if (m_bIsDuelInProgress && pDoneBy->IsControlledByPlayer())
            {
                if (pDoneBy->GetGUID() != m_uiDuelerGUID && pDoneBy->GetOwnerGUID() != m_uiDuelerGUID)          // other players cannot help
                    uiDamage = 0;
                else if (uiDamage >= me->GetHealth())
                {
                    uiDamage = 0;

                    if (!lose)
                    {
                        pDoneBy->RemoveGameObject(SPELL_DUEL_FLAG, true);
                        pDoneBy->AttackStop();
                        me->CastSpell(pDoneBy, SPELL_DUEL_VICTORY, true);
                        lose = true;
                        me->CastSpell(me, 7267, true);
                        me->RestoreFaction();
                    }
                }
            }
        }

        void UpdateAI (const uint32 uiDiff)
        {
            if (!UpdateVictim())
            {
                if (m_bIsDuelInProgress)
                {
                    if (m_uiDuelTimer <= uiDiff)
                    {
                        me->setFaction(FACTION_HOSTILE);

                        if (Unit* pUnit = Unit::GetUnit(*me, m_uiDuelerGUID))
                            AttackStart(pUnit);
                    }
                    else
                        m_uiDuelTimer -= uiDiff;
                }
                return;
            }

            if (m_bIsDuelInProgress)
            {
                if (lose)
                {
                    if (!me->HasAura(7267))
                        EnterEvadeMode();
                    return;
                }
                else if (me->getVictim()->GetTypeId() == TYPEID_PLAYER && me->getVictim()->HealthBelowPct(10))
                {
                    me->getVictim()->CastSpell(me->getVictim(), 7267, true);          // beg
                    me->getVictim()->RemoveGameObject(SPELL_DUEL_FLAG, true);
                    EnterEvadeMode();
                    return;
                }
            }

            // TODO: spells

            CombatAI::UpdateAI(uiDiff);
        }
    };
};

void AddSC_DuelReset ()
{
    new Reset_OnDuelEnd;
    new duel_challenger_dk();
}
