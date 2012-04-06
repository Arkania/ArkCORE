/*
 * Copyright (C) 2008 - 2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2006-2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "trial_of_the_crusader.h"
#include "Vehicle.h"

enum Yells
{
    SAY_INTRO               = -1649030,
    SAY_AGGRO               = -1649031,
    SAY_DEATH               = -1649032,
    EMOTE_INCINERATE        = -1649033,
    SAY_INCINERATE          = -1649034,
    EMOTE_LEGION_FLAME      = -1649035,
    EMOTE_NETHER_PORTAL     = -1649036,
    SAY_NETHER_PORTAL       = -1649037,
    EMOTE_INFERNAL_ERUPTION = -1649038,
    SAY_INFERNAL_ERUPTION   = -1649039,
};

enum Equipment
{
    EQUIP_MAIN           = 47266,
    EQUIP_OFFHAND        = 46996,
    EQUIP_RANGED         = 47267,
    EQUIP_DONE           = EQUIP_NO_CHANGE,
};

enum Summons
{
    NPC_LEGION_FLAME     = 34784,
    NPC_INFERNAL_VOLCANO = 34813,
    NPC_FEL_INFERNAL     = 34815, // immune to all CC on Heroic (stuns, banish, interrupt, etc)
    NPC_NETHER_PORTAL    = 34825,
    NPC_MISTRESS_OF_PAIN = 34826,
};

enum BossSpells
{
    SPELL_NETHER_POWER               = 66228, // +20% of spell damage per stack, stackable up to 5/10 times, must be dispelled/stealed
    SPELL_INFERNAL_ERUPTION          = 66258, // summons Infernal Volcano
    SPELL_INFERNAL_ERUPTION_EFFECT   = 66252, // summons Felflame Infernal (3 at Normal and inifinity at Heroic)
    SPELL_FEL_FIREBALL_10_N          = 66532, // does heavy damage to the tank, interruptable
    SPELL_FEL_FIREBALL_25_N          = 66963,
    SPELL_FEL_FIREBALL_10_H          = 66964,
    SPELL_FEL_FIREBALL_25_H          = 66965,
    SPELL_FEL_LIGHTING_10_N          = 66528, // jumps to nearby targets
    SPELL_FEL_LIGHTING_25_N          = 67029,
    SPELL_FEL_LIGHTING_10_H          = 67030,
    SPELL_FEL_LIGHTING_25_H          = 67031,
    SPELL_INCINERATE_FLESH_10_N      = 66237, // target must be healed or will trigger Burning Inferno
    SPELL_INCINERATE_FLESH_25_N      = 67049,
    SPELL_INCINERATE_FLESH_10_H      = 67050,
    SPELL_INCINERATE_FLESH_25_H      = 67051,
    SPELL_TOUCH_OF_JARAXXUS          = 66209, // used only in 25H
    SPELL_BURNING_INFERNO            = 66242, // triggered by Incinerate Flesh
    SPELL_NETHER_PORTAL              = 66269, // summons Nether Portal
    SPELL_NETHER_PORTAL_EFFECT       = 66263, // summons Mistress of Pain (1 at Normal and infinity at Heroic)
    SPELL_LEGION_FLAME_10_N          = 66197, // player should run away from raid because he triggers Legion Flame
    SPELL_LEGION_FLAME_25_N          = 68123,
    SPELL_LEGION_FLAME_10_H          = 68124,
    SPELL_LEGION_FLAME_25_H          = 68125,
    SPELL_LEGION_FLAME_EFFECT_10_N   = 66201, // used by trigger npc
    SPELL_LEGION_FLAME_EFFECT_25_N   = 67070,
    SPELL_LEGION_FLAME_EFFECT_10_H   = 67071,
    SPELL_LEGION_FLAME_EFFECT_25_H   = 67072,
    SPELL_SHIVAN_SLASH               = 67098,
    SPELL_SPINNING_STRIKE            = 66283,
    SPELL_MISTRESS_KISS              = 67077,
    SPELL_SPINNING_STRIKE_1          = 66283,
    SPELL_SPINNING_STRIKE_2          = 66285,
    SPELL_FEL_INFERNO                = 67047,
    SPELL_FEL_STREAK                 = 66494,
    SPELL_BERSERK                    = 64238, // unused
};

/*######
## boss_jaraxxus
######*/

class boss_jaraxxus : public CreatureScript
{
public:
    boss_jaraxxus() : CreatureScript("boss_jaraxxus") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_jaraxxusAI(creature);
    }

    struct boss_jaraxxusAI : public ScriptedAI
    {
        boss_jaraxxusAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            m_pInstance = creature->GetInstanceScript();
            Reset();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }

        InstanceScript* m_pInstance;

        SummonList Summons;

        uint32 m_uiFelFireballTimer;
        uint32 m_uiFelLightningTimer;
        uint32 m_uiIncinerateFleshTimer;
        uint32 m_uiNetherPowerTimer;
        uint32 m_uiLegionFlameTimer;
        uint32 m_uiTouchOfJaraxxusTimer;
        uint32 m_uiSummonNetherPortalTimer;
        uint32 m_uiSummonInfernalEruptionTimer;

        void Reset()
        {
            if (m_pInstance)
                m_pInstance->SetData(TYPE_JARAXXUS, NOT_STARTED);
            SetEquipmentSlots(false, EQUIP_MAIN, EQUIP_OFFHAND, EQUIP_RANGED);
            m_uiFelFireballTimer = 5*IN_MILLISECONDS;
            m_uiFelLightningTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
            m_uiIncinerateFleshTimer = urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS);
            m_uiNetherPowerTimer = 40*IN_MILLISECONDS;
            m_uiLegionFlameTimer = 30*IN_MILLISECONDS;
            m_uiTouchOfJaraxxusTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
            m_uiSummonNetherPortalTimer = 1*MINUTE*IN_MILLISECONDS;
            m_uiSummonInfernalEruptionTimer = 2*MINUTE*IN_MILLISECONDS;
            Summons.DespawnAll();
        }

        void JustReachedHome()
        {
            if (m_pInstance)
                m_pInstance->SetData(TYPE_JARAXXUS, FAIL);
            DoCast(me, SPELL_JARAXXUS_CHAINS);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void KilledUnit(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (m_pInstance)
                    m_pInstance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE, 0);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            Summons.DespawnAll();
            DoScriptText(SAY_DEATH, me);
            if (m_pInstance)
                m_pInstance->SetData(TYPE_JARAXXUS, DONE);
        }

        void JustSummoned(Creature* summoned)
        {
            Summons.Summon(summoned);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->SetInCombatWithZone();
            if (m_pInstance)
                m_pInstance->SetData(TYPE_JARAXXUS, IN_PROGRESS);
            DoScriptText(SAY_AGGRO, me);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (m_uiSummonInfernalEruptionTimer <= uiDiff)
            {
                DoScriptText(EMOTE_INFERNAL_ERUPTION, me);
                DoScriptText(SAY_INFERNAL_ERUPTION, me);
                DoCast(SPELL_INFERNAL_ERUPTION);
                m_uiSummonInfernalEruptionTimer = 2*MINUTE*IN_MILLISECONDS;
            } else m_uiSummonInfernalEruptionTimer -= uiDiff;

            if (m_uiSummonNetherPortalTimer <= uiDiff)
            {
                DoScriptText(EMOTE_NETHER_PORTAL, me);
                DoScriptText(SAY_NETHER_PORTAL, me);
                DoCast(SPELL_NETHER_PORTAL);
                m_uiSummonNetherPortalTimer = 2*MINUTE*IN_MILLISECONDS;
            } else m_uiSummonNetherPortalTimer -= uiDiff;

            if (m_uiFelFireballTimer <= uiDiff)
            {
                DoCastVictim(RAID_MODE(SPELL_FEL_FIREBALL_10_N, SPELL_FEL_FIREBALL_25_N, SPELL_FEL_FIREBALL_10_H, SPELL_FEL_FIREBALL_25_H));
                m_uiFelFireballTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
            } else m_uiFelFireballTimer -= uiDiff;

            if (m_uiFelLightningTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, RAID_MODE(SPELL_FEL_LIGHTING_10_N, SPELL_FEL_LIGHTING_25_N, SPELL_FEL_LIGHTING_10_H, SPELL_FEL_LIGHTING_25_H));
                m_uiFelLightningTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
            } else m_uiFelLightningTimer -= uiDiff;

            if (m_uiIncinerateFleshTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    DoScriptText(EMOTE_INCINERATE, me, target);
                    DoScriptText(SAY_INCINERATE, me);
                    DoCast(target, RAID_MODE(SPELL_INCINERATE_FLESH_10_N, SPELL_INCINERATE_FLESH_25_N, SPELL_INCINERATE_FLESH_10_H, SPELL_INCINERATE_FLESH_25_H));
                }
                m_uiIncinerateFleshTimer = urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS);
            } else m_uiIncinerateFleshTimer -= uiDiff;

            if (m_uiNetherPowerTimer <= uiDiff)
            {
                me->CastCustomSpell(SPELL_NETHER_POWER, SPELLVALUE_AURA_STACK, RAID_MODE<uint32>(5,10,5,10), me, true);
                m_uiNetherPowerTimer = 40*IN_MILLISECONDS;
            } else m_uiNetherPowerTimer -= uiDiff;

            if (m_uiLegionFlameTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0, true))
                {
                    DoScriptText(EMOTE_LEGION_FLAME, me, target);
                    DoCast(target, RAID_MODE(SPELL_LEGION_FLAME_10_N, SPELL_LEGION_FLAME_25_N, SPELL_LEGION_FLAME_10_H, SPELL_LEGION_FLAME_25_H));
                }
                m_uiLegionFlameTimer = 30*IN_MILLISECONDS;
            } else m_uiLegionFlameTimer -= uiDiff;

            if (GetDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC && m_uiTouchOfJaraxxusTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_TOUCH_OF_JARAXXUS);
                m_uiTouchOfJaraxxusTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
            } else m_uiTouchOfJaraxxusTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_legion_flame : public CreatureScript
{
public:
    mob_legion_flame() : CreatureScript("mob_legion_flame") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_legion_flameAI(creature);
    }

    struct mob_legion_flameAI : public Scripted_NoMovementAI
    {
        mob_legion_flameAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            Reset();
        }

        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetInCombatWithZone();
            DoCast(RAID_MODE(SPELL_LEGION_FLAME_EFFECT_10_N, SPELL_LEGION_FLAME_EFFECT_25_N, SPELL_LEGION_FLAME_EFFECT_10_H, SPELL_LEGION_FLAME_EFFECT_25_H));
        }

        void UpdateAI(const uint32 /*uiDiff*/)
        {
            UpdateVictim();
        }
    };
};

class mob_infernal_volcano : public CreatureScript
{
public:
    mob_infernal_volcano() : CreatureScript("mob_infernal_volcano") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_infernal_volcanoAI(creature);
    }

    struct mob_infernal_volcanoAI : public Scripted_NoMovementAI
    {
        mob_infernal_volcanoAI(Creature* creature) : Scripted_NoMovementAI(creature), Summons(me)
        {
            m_pInstance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;

        SummonList Summons;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);

            if (!IsHeroic())
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            else
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);

            Summons.DespawnAll();
        }

        void IsSummonedBy(Unit* /*summoner*/)
        {
            DoCast(SPELL_INFERNAL_ERUPTION_EFFECT);
        }

        void JustSummoned(Creature* summoned)
        {
            Summons.Summon(summoned);
            // makes immediate corpse despawn of summoned Felflame Infernals
            summoned->SetCorpseDelay(0);
        }

        void JustDied(Unit* /*killer*/)
        {
            // used to despawn corpse immediately
            me->DespawnOrUnsummon();
        }
    };
};

class mob_fel_infernal : public CreatureScript
{
public:
    mob_fel_infernal() : CreatureScript("mob_fel_infernal") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_fel_infernalAI(creature);
    }

    struct mob_fel_infernalAI : public ScriptedAI
    {
        mob_fel_infernalAI(Creature* creature) : ScriptedAI(creature)
        {
            m_pInstance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;
        uint32 m_uiFelStreakTimer;

        void Reset()
        {
            m_uiFelStreakTimer = 30*IN_MILLISECONDS;
            me->SetInCombatWithZone();
        }

        /*void SpellHitTarget(Unit* target, const SpellInfo* pSpell)
        {
            if (pSpell->Id == SPELL_FEL_STREAK)
                DoCastAOE(SPELL_FEL_INFERNO); //66517
        }*/

        void UpdateAI(const uint32 uiDiff)
        {
            if (m_pInstance && m_pInstance->GetData(TYPE_JARAXXUS) != IN_PROGRESS)
                me->DespawnOrUnsummon();

            if (!UpdateVictim())
                return;

            if (m_uiFelStreakTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FEL_STREAK);
                m_uiFelStreakTimer = 30*IN_MILLISECONDS;
            } else m_uiFelStreakTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_nether_portal : public CreatureScript
{
public:
    mob_nether_portal() : CreatureScript("mob_nether_portal") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_nether_portalAI(creature);
    }

    struct mob_nether_portalAI : public ScriptedAI
    {
        mob_nether_portalAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            m_pInstance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;

        SummonList Summons;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);

            if (!IsHeroic())
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            else
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);

            Summons.DespawnAll();
        }

        void IsSummonedBy(Unit* /*summoner*/)
        {
            DoCast(SPELL_NETHER_PORTAL_EFFECT);
        }

        void JustSummoned(Creature* summoned)
        {
            Summons.Summon(summoned);
            // makes immediate corpse despawn of summoned Mistress of Pain
            summoned->SetCorpseDelay(0);
        }

        void JustDied(Unit* /*killer*/)
        {
            // used to despawn corpse immediately
            me->DespawnOrUnsummon();
        }
    };
};

class mob_mistress_of_pain : public CreatureScript
{
public:
    mob_mistress_of_pain() : CreatureScript("mob_mistress_of_pain") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_mistress_of_painAI(creature);
    }

    struct mob_mistress_of_painAI : public ScriptedAI
    {
        mob_mistress_of_painAI(Creature* creature) : ScriptedAI(creature)
        {
            m_pInstance = (InstanceScript*)creature->GetInstanceScript();
            if (m_pInstance)
                m_pInstance->SetData(DATA_MISTRESS_OF_PAIN_COUNT, INCREASE);
            Reset();
        }

        InstanceScript* m_pInstance;
        uint32 m_uiShivanSlashTimer;
        uint32 m_uiSpinningStrikeTimer;
        uint32 m_uiMistressKissTimer;

        void Reset()
        {
            m_uiShivanSlashTimer = 30*IN_MILLISECONDS;
            m_uiSpinningStrikeTimer = 30*IN_MILLISECONDS;
            m_uiMistressKissTimer = 15*IN_MILLISECONDS;
            me->SetInCombatWithZone();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (m_pInstance)
                m_pInstance->SetData(DATA_MISTRESS_OF_PAIN_COUNT, DECREASE);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (m_pInstance && m_pInstance->GetData(TYPE_JARAXXUS) != IN_PROGRESS)
                me->DespawnOrUnsummon();

            if (!UpdateVictim())
                return;

            if (m_uiShivanSlashTimer <= uiDiff)
            {
                DoCastVictim(SPELL_SHIVAN_SLASH);
                m_uiShivanSlashTimer = 30*IN_MILLISECONDS;
            } else m_uiShivanSlashTimer -= uiDiff;

            if (m_uiSpinningStrikeTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                {
                    DoCast(target,SPELL_SPINNING_STRIKE_1);
                    DoCast(target,SPELL_SPINNING_STRIKE_2);
                    target->CastSpell(me, 66287, true);
                }
                m_uiSpinningStrikeTimer = 30*IN_MILLISECONDS;
            } else m_uiSpinningStrikeTimer -= uiDiff;

            if (IsHeroic() && m_uiMistressKissTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    DoCast(target, SPELL_MISTRESS_KISS);
                m_uiMistressKissTimer = 30*IN_MILLISECONDS;
            } else m_uiMistressKissTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class spell_spinning_pain_strike : public SpellScriptLoader
{
public:
    spell_spinning_pain_strike() : SpellScriptLoader("spell_spinning_pain_strike") { }

    class spell_spinning_pain_strike_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_spinning_pain_strike_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            return true;
        }

        void CalcDamage(SpellEffIndex /*effIndex*/)
        {
            uint32 dmg = 0;
            if(Unit* target = GetHitUnit())
                dmg = ((float)target->GetMaxHealth())*50.0f/100.0f;
            SetHitDamage(dmg);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_spinning_pain_strike_SpellScript::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_spinning_pain_strike_SpellScript();
    }
};

class spell_eject_all_passengers : public SpellScriptLoader
{
public:
    spell_eject_all_passengers() : SpellScriptLoader("spell_eject_all_passengers") { }

    class spell_eject_all_passengers_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_eject_all_passengers_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* pCaster = GetCaster())
                if (Vehicle* pVehicle = pCaster->GetVehicleKit())
                    pVehicle->RemoveAllPassengers();
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_eject_all_passengers_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_eject_all_passengers_SpellScript();
    }
};

void AddSC_boss_jaraxxus()
{
    new boss_jaraxxus();
    new mob_legion_flame();
    new mob_infernal_volcano();
    new mob_fel_infernal();
    new mob_nether_portal();
    new mob_mistress_of_pain();
    new spell_spinning_pain_strike();
    new spell_eject_all_passengers();
}
