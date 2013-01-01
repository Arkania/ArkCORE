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
#include "bastion_of_twilight.h"
#include <cstring>

class boss_halfus_wyrmbreaker: public CreatureScript
{
public:
    boss_halfus_wyrmbreaker () :
            CreatureScript("boss_halfus_wyrmbreaker")
    {
    }

    struct boss_halfus_wyrmbreakerAI: public BossAI
    {
        boss_halfus_wyrmbreakerAI (Creature * creature) :
                BossAI(creature, DATA_WYRMBREAKER)
        {
            pInstance = (InstanceScript*) creature->GetInstanceScript();
        }

        void Reset ()
        {
            uiBerserkTimer = 360000;
            uiMalevolentStrikeTimer = 155000;
            uiFuriousRoarTimer = 30000;
            uiShadowNovaTimer = 30000;
            pInstance->SetData(DATA_WYRMBREAKER_EVENT, NOT_STARTED);
        }

        void EnterCombat ()
        {
            if (pInstance)
                pInstance->SetData(DATA_WYRMBREAKER_EVENT, IN_PROGRESS);
        }

        void JustDied ()
        {
            if (!pInstance)
                return;

            pInstance->SetData(DATA_WYRMBREAKER_EVENT, DONE);
        }

        void UpdateAI (const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (!HealthAbovePct(50))
            {
                if (uiFuriousRoarTimer <= uiDiff)
                {
                    DoCast(SPELL_FURIOUS_ROAR);
                    DoCast(SPELL_SHADOW_NOVA);
                }
                else
                    uiFuriousRoarTimer -= uiDiff;
            }

            if (me->HasAura(SPELL_MALEVOLENT_STRIKES))
            {
                if (uiMalevolentStrikeTimer <= uiDiff)
                {
                    DoCastVictim(SPELL_MALEVOLENT_STRIKES_DEBUFF);
                    uiMalevolentStrikeTimer = 155000;
                }
                else
                    uiMalevolentStrikeTimer -= uiDiff;
            }

            if (me->HasAura(SPELL_SHADOW_WARPED))
            {
                if (uiShadowNovaTimer <= uiDiff)
                {
                    DoCast(SPELL_SHADOW_NOVA);
                }
                else
                    uiShadowNovaTimer -= uiDiff;
            }

            if (uiBerserkTimer <= uiDiff)
            {
                me->AddAura(SPELL_BERSERK_HALFUS, me);
                uiBerserkTimer = 360000;
            }
            else
                uiBerserkTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    private:

        InstanceScript* pInstance;

        uint32 uiBerserkTimer;
        uint32 uiFuriousRoarTimer;
        uint32 uiMalevolentStrikeTimer;
        uint32 uiShadowNovaTimer;
    };

    CreatureAI* GetAI (Creature* creature) const
    {
        return new boss_halfus_wyrmbreakerAI(creature);
    }
};

class npc_proto_behemoth: public CreatureScript
{
public:
    npc_proto_behemoth () :
            CreatureScript("npc_proto_behemoth")
    {
    }

    struct npc_proto_behemothAI: public ScriptedAI
    {
        npc_proto_behemothAI (Creature * creature) :
                ScriptedAI(creature)
        {
            pInstance = (InstanceScript*) creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint64 uiFireballTimer;
        //uint64 uiScorchingBreathTimer;
        uint64 uiFireballBaradgeTimer;

        void Reset ()
        {
            uiFireballTimer = 120000;
            //uiScorchingBreathTimer = 360000;
            uiFireballBaradgeTimer = 145000;
        }

        void UpdateAI (const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasAura(SPELL_DANCING_FLAMES))
            {
                if (uiFireballBaradgeTimer <= uiDiff)
                {
                    if (Unit * Target = SelectTarget(SELECT_TARGET_RANDOM, 1, 50.0f, true))
                    {
                        DoCast(Target, SPELL_FIREBALL_BARADGE);
                    }
                    uiFireballBaradgeTimer = 145000;
                }
                else
                    uiFireballBaradgeTimer -= uiDiff;
            }

            if (uiFireballTimer <= uiDiff)
            {
                if (Unit * Target = SelectTarget(SELECT_TARGET_RANDOM, 1, 50.0f, true))
                {
                    DoCast(Target, SPELL_FIREBALL);
                }
            }
            else
                uiFireballTimer -= uiDiff;
        }
    };

    CreatureAI* GetAI (Creature* creature) const
    {
        return new npc_proto_behemothAI(creature);
    }
};

class npc_halfus_dragon: public CreatureScript
{
public:
    npc_halfus_dragon () :
            CreatureScript("npc_halfus_dragon")
    {
    }

    struct npc_halfus_dragonAI: public ScriptedAI
    {
        npc_halfus_dragonAI (Creature * creature) :
                ScriptedAI(creature)
        {
            pInstance = (InstanceScript*) creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void Reset ()
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void UpdateAI (const uint32 uiDiff)
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            {
                me->SetReactState(REACT_PASSIVE);
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI (Creature* creature) const
    {
        return new npc_halfus_dragonAI(creature);
    }

    bool OnGossipHello (Player* pPlayer, Creature* creature)
    {
        char const* _message = "Simple Text!";
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, _message, GOSSIP_SENDER_MAIN , GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(68, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect (Player* pPlayer, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        InstanceScript* pInstance;
        pInstance = (InstanceScript*) creature->GetInstanceScript();
        if (!pInstance)
            return false;

        pPlayer->CLOSE_GOSSIP_MENU();

        switch (uiAction)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            if (Creature * Halfus = Unit::GetCreature(*creature, pInstance->GetData64(DATA_WYRMBREAKER)))
            {
                switch (creature->GetEntry())
                {
                case NPC_SLATE_DRAKE:
                    creature->AddAura(SPELL_STONE_TOUCH, Halfus);
                    break;
                case NPC_NETHER_SCION:
                    creature->AddAura(SPELL_NETHER_BLINDNESS, Halfus);
                    break;
                case NPC_STORM_RIDER:
                    creature->CastSpell(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), SPELL_CYCLONE_WINDS, false);
                    break;
                }
                Halfus->AddAura(SPELL_BIND_WILL, creature);
                creature->SetAuraStack(SPELL_DRAGON_VENGEANCE, Halfus, Halfus->GetAuraCount(SPELL_DRAGON_VENGEANCE) + 1);
                creature->SetReactState(REACT_AGGRESSIVE);
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            break;
        }
        return true;
    }
};

class npc_cyclon_winds: public CreatureScript
{
public:
    npc_cyclon_winds () :
            CreatureScript("npc_cyclon_winds")
    {
    }

    struct npc_cyclon_windsAI: public ScriptedAI
    {
        npc_cyclon_windsAI (Creature * creature) :
                ScriptedAI(creature)
        {
            pInstance = (InstanceScript*) creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void Reset ()
        {
        }

        void UpdateAI (const uint32 uiDiff)
        {
        }

        void MovementInForm (uint32 type, uint32 id)
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                case POINT_CYCLON_WIND:
                    Creature * Halfus = ObjectAccessor::GetCreature(*me, pInstance->GetData64(NPC_CYCLON_WIND));
                    me->AddAura(84092, Halfus);
                    me->DestroyForNearbyPlayers();
                }
            }
        }
    };

    CreatureAI * GetAI (Creature * creature) const
    {
        return new npc_cyclon_windsAI(creature);
    }
};
class spell_cyclon_winds: public SpellScriptLoader
{
public:
    spell_cyclon_winds () :
            SpellScriptLoader("spell_cyclon_winds")
    {
    }

    class spell_cyclon_windsSpellScript: public SpellScript
    {
        PrepareSpellScript(spell_cyclon_windsSpellScript)
        ;

        bool Validate (SpellEntry const * spellEntry)
        {
            if (!sSpellStore.LookupEntry(spellEntry->Id))
                return false;
            return true;
        }

        void HandleAfterHit ()
        {
            Creature * Cyclon = ObjectAccessor::GetCreature(*GetCaster(), NPC_CYCLON_WIND);
            Cyclon->GetMotionMaster()->MovePoint(POINT_CYCLON_WIND, Positions[1]);
        }

        void Register ()
        {
            AfterHit += SpellHitFn(spell_cyclon_windsSpellScript::HandleAfterHit);
        }
    };

    SpellScript * GetSpellScript () const
    {
        return new spell_cyclon_windsSpellScript();
    }
};
void AddSC_boss_halfus_wyrmbreaker ()
{
    new boss_halfus_wyrmbreaker();
    new npc_halfus_dragon();
    new npc_proto_behemoth();
    new spell_cyclon_winds();
}
