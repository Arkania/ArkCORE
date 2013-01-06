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
#include "ScriptMgr.h"
#include "blackwing_descent.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum Events
{
    // Groundphase
    EVENT_SONAR_PULSE = 1,
    EVENT_MODULATION,
    EVENT_SONIC_BREATH,
    EVENT_SEARING_FLAMES,
    EVENT_ROARING_FLAME_BREATH,

    // Flightphase
    EVENT_ROARING_FLAME_BREATH_F,
    EVENT_SONAR_BOMB_F,
    EVENT_SONIC_FIREBALL_F,

    EVENT_GROUND,
    EVENT_FLIGHT,
    EVENT_LIFTOFF,
    EVENT_LAND,
};

enum Spells
{
    ATRAMEDES_ENTRY                 = 41442,

    // Bossfight
    // Flightphase
    SPELL_ROARING_FLAME_BREATH      = 78353,
    SPELL_SONAR_BOMB                = 92553,
    SPELL_SONIC_FIREBALL            = 78115,

    // Groundphase
    SPELL_MODULATION                = 77612,
    SPELL_SEARING_FLAME             = 77840,
    SPELL_SONIC_BREATH              = 78075,
    SPELL_TRACKING                  = 78092,

    // Effect
    SPELL_SONAR_PULSE               = 92418,
    SPELL_SONAR_PULSE_SUMMON        = 77673,
    SPELL_SONAR_PULSE_AURA          = 77674,
    SPELL_SONAR_PULSE_DAMAGE        = 92418,
    SPELL_ROARING_ZONE              = 76247,
    SPELL_ATRAMEDES_STUN            = 77611,
};

enum Phases 
{
    PHASE_NULL = 0,
    PHASE_FLIGHT,
	PHASE_GROUND,
};

enum MovementPoints
{
    POINT_FLIGHT            = 1,
    POINT_LAND              = 2,
};

Position const AtramedesFlyPos  = {147.491f, -225.301f, 76.4534f, 3.07607f};
Position const AtramedesLandPos = {147.491f, -225.301f, 75.4534f, 3.07607f};

enum SpiritSpells
{
    SPELL_AVATAR             = 80645, // Tank
    SPELL_BURDEN_OF_CROWN    = 80718, // Tank
    SPELL_CHAIN_LIGHTNING    = 91891, // Caster
    SPELL_STORMBOLT          = 91890,
    SPELL_THUNDERCLAP        = 91889,
    SPELL_WHIRLIND           = 80652,
};

#define ACTION_EVENT_START          1
#define ACTION_PROGRESS_PHASE       2

uint16 const adds[8] =
{
    43119, 43128, 43130, 43122, 43127, 43125, 43129, 43126
};

const Position addsLocations[8] = 
{
    {129.971f, -180.754f, 74.9073f, 4.67909f},
    {147.843f, -265.233f, 74.9073f, 2.06174f},
    {112.498f, -264.905f, 74.9073f, 1.15069f},
    {130.363f, -269.234f, 74.9073f, 1.49626f},
    {161.121f, -253.638f, 74.9073f, 2.47016f},
    {112.887f, -184.105f, 74.9073f, 5.21118f},
    {145.621f, -183.672f, 74.9073f, 4.22944f},
    {160.038f, -196.484f, 74.9073f, 3.92511f}
};


/*******************
** Event Ancien Bell
********************/

/***************
** Trashs Spirit
****************/
class npc_spirit : public CreatureScript
{
public:
    npc_spirit() : CreatureScript("npc_spirit") { }

    struct npc_spiritAI : public ScriptedAI
    {
        npc_spiritAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 AvatarTimer;
        uint32 CrownTimer;
        uint32 LightningTimer;
        uint32 StormboltTimer;
        uint32 ThunderTimer;
        uint32 WhirlindTimer;

        void Reset()
        {
            AvatarTimer = 10000;
            CrownTimer = 15000;
            LightningTimer = urand(18000,22000);
            StormboltTimer = 22000;
            ThunderTimer = 15000;
            WhirlindTimer = 20000;
        }

        void EnterCombat(Unit* /*who*/)
        {}

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (AvatarTimer <= diff)
            {
                DoCast(me, SPELL_AVATAR);
                AvatarTimer = 10000;
            }
            else AvatarTimer -= diff;

            if (CrownTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_BURDEN_OF_CROWN);
                CrownTimer = 15000;
            }
            else CrownTimer -= diff;

            if (LightningTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true), SPELL_CHAIN_LIGHTNING);
                LightningTimer = urand(18000,22000);
            }
            else LightningTimer -= diff;

            if (StormboltTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1, 100,true), SPELL_STORMBOLT);
                StormboltTimer = 22000;
            }
            else StormboltTimer -= diff;

            if (ThunderTimer <= diff)
            {
                DoCastAOE(SPELL_THUNDERCLAP);
                ThunderTimer = 15000;
            }
            else ThunderTimer -= diff;

            if (WhirlindTimer <= diff)
            {
                DoCastAOE(SPELL_WHIRLIND);
                WhirlindTimer = 20000;
            }
            else WhirlindTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*who*/)
        {}
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_spiritAI(creature);
    }
};

/******************
** Trigger + Spells
*******************/
/*************
** Sonar Pulse
**************/
class npc_sonar_pulse : public CreatureScript
{
public:
    npc_sonar_pulse() : CreatureScript("npc_sonar_pulse") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_sonar_pulseAI (creature);
    }

    struct npc_sonar_pulseAI : public ScriptedAI
    {
        npc_sonar_pulseAI(Creature* creature) : ScriptedAI(creature)
        {
            creature->SetReactState(REACT_PASSIVE);
            me->DespawnOrUnsummon(30000);
        }
		
		uint32 timerChangeTarget;
		
		void Reset()
		{
            me->AddAura(SPELL_SONAR_PULSE_AURA, me);
            me->AddAura(SPELL_SONAR_PULSE_DAMAGE, me);
            timerChangeTarget = 13000;
		}

        void UpdateAI(const uint32 diff)
        {
            if (timerChangeTarget <= diff)
            {
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                me->GetMotionMaster()->MoveFollow(target, 3, 2);
                timerChangeTarget = 13000;
            } else timerChangeTarget -= diff;
        }
    };
};

/*****************
** Tracking Flames
******************/
class npc_tracking_flames : public CreatureScript
{
public:
    npc_tracking_flames() : CreatureScript("npc_tracking_flames") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_tracking_flamesAI (creature);
    }

    struct npc_tracking_flamesAI : public ScriptedAI
    {
        npc_tracking_flamesAI(Creature* creature) : ScriptedAI(creature)
        {
            me->DespawnOrUnsummon(30000);
        }
    };
};

/***************
** Roaring Flame
****************/
class npc_roaring_flame : public CreatureScript
{
public:
    npc_roaring_flame() : CreatureScript("npc_roaring_flame") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_roaring_flameAI (creature);
    }

    struct npc_roaring_flameAI : public Scripted_NoMovementAI
    {
        npc_roaring_flameAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            DoCast(me, SPELL_ROARING_ZONE);

            me->ForcedDespawn(20000);
        }
    };
};

/**********************
** Roaring Flame Target
***********************/
class npc_roaring_flame_target : public CreatureScript
{
public:
    npc_roaring_flame_target() : CreatureScript("npc_roaring_flame_target") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_roaring_flame_targetAI (creature);
    }

    struct npc_roaring_flame_targetAI : public ScriptedAI
    {
        npc_roaring_flame_targetAI(Creature* creature) : ScriptedAI(creature)
        {
            me->DespawnOrUnsummon(30000);
        }
    };
};

/*****************
** Atramedes Gongs
*****************/
class atramedes_gong : public CreatureScript
{
public:
    atramedes_gong() : CreatureScript("atramedes_gong") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if(Creature* un = pCreature->FindNearestCreature(ATRAMEDES_ENTRY,90.0f))
        {
            un->StopMoving();
            un->CastStop();
            pCreature->CastSpell(un, SPELL_ATRAMEDES_STUN, true);
            pCreature->DisappearAndDie();
        }
        return true;
    }
};



/*******************************
** Spell Atramedes Roaring Flame
********************************/
class RoaringFlameTargetSelector
{
    public:
        RoaringFlameTargetSelector() { }

        bool operator()(Unit* unit)
        {
            return unit->GetTypeId() != TYPEID_PLAYER;
        }
};


void AddSC_boss_atramedes()
{
    new npc_spirit();
    new npc_sonar_pulse();
    new npc_tracking_flames();
    new npc_roaring_flame();
    new npc_roaring_flame_target();
    new atramedes_gong();
}