/*
 * Copyright (C) 2011-2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2010-2012 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2006-2012 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

/*
 * Scripts for spells with SPELLFAMILY_DRUID and SPELLFAMILY_GENERIC spells used by druid players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dru_".
 */

#include "ScriptPCH.h"
#include "SpellAuraEffects.h"

enum DruidSpells
{
    DRUID_INCREASED_MOONFIRE_DURATION   = 38414,
    DRUID_NATURES_SPLENDOR              = 57865,
    DRUID_NPC_WILD_MUSHROOM             = 47649,
    DRUID_TALENT_FUNGAL_GROWTH_1        = 78788,
    DRUID_TALENT_FUNGAL_GROWTH_2        = 78789,
    DRUID_NPC_FUNGAL_GROWTH_1           = 81291,
    DRUID_NPC_FUNGAL_GROWTH_2           = 81283,
    DRUID_SPELL_WILD_MUSHROOM_SUICIDE   = 92853,
    DRUID_SPELL_WILD_MUSHROOM_DAMAGE    = 78777,
};

// 54846 Glyph of Starfire
class spell_dru_glyph_of_starfire : public SpellScriptLoader
{
    public:
        spell_dru_glyph_of_starfire() : SpellScriptLoader("spell_dru_glyph_of_starfire") { }

        class spell_dru_glyph_of_starfire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_glyph_of_starfire_SpellScript);

            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(DRUID_INCREASED_MOONFIRE_DURATION))
                    return false;
                if (!sSpellStore.LookupEntry(DRUID_NATURES_SPLENDOR))
                    return false;
                return true;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                    if (AuraEffect const* aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00000002, 0, 0, caster->GetGUID()))
                    {
                        Aura* aura = aurEff->GetBase();

                        uint32 countMin = aura->GetMaxDuration();
                        uint32 countMax = GetSpellMaxDuration(aura->GetSpellProto()) + 9000;
                        if (caster->HasAura(DRUID_INCREASED_MOONFIRE_DURATION))
                            countMax += 3000;
                        if (caster->HasAura(DRUID_NATURES_SPLENDOR))
                            countMax += 3000;

                        if (countMin < countMax)
                        {
                            aura->SetDuration(uint32(aura->GetDuration() + 3000));
                            aura->SetMaxDuration(countMin + 3000);
                        }
                    }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_dru_glyph_of_starfire_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_glyph_of_starfire_SpellScript();
        }
};

// 62606 - Savage Defense
class spell_dru_savage_defense : public SpellScriptLoader
{
    public:
        spell_dru_savage_defense() : SpellScriptLoader("spell_dru_savage_defense") { }

        class spell_dru_savage_defense_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_savage_defense_AuraScript);

            uint32 absorbPct;

            bool Load()
            {
                absorbPct = SpellMgr::CalculateSpellEffectAmount(GetSpellProto(), EFFECT_0, GetCaster());
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* aurEff, DamageInfo & /*dmgInfo*/, uint32 & absorbAmount)
            {
                absorbAmount = uint32(CalculatePctN(GetTarget()->GetTotalAttackPowerValue(BASE_ATTACK), absorbPct));
                aurEff->SetAmount(0);
            }

            void Register()
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_savage_defense_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_dru_savage_defense_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_dru_savage_defense_AuraScript();
        }
};

class spell_dru_t10_restoration_4p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t10_restoration_4p_bonus() : SpellScriptLoader("spell_dru_t10_restoration_4p_bonus") { }

        class spell_dru_t10_restoration_4p_bonus_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_t10_restoration_4p_bonus_SpellScript);

            bool Load()
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void FilterTargets(std::list<Unit*>& unitList)
            {
                if (!GetCaster()->ToPlayer()->GetGroup())
                {
                    unitList.clear();
                    unitList.push_back(GetCaster());
                }
                else
                {
                    unitList.remove(GetTargetUnit());
                    std::list<Unit*> tempTargets;
                    for (std::list<Unit*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                        if ((*itr)->GetTypeId() == TYPEID_PLAYER && GetCaster()->IsInRaidWith(*itr))
                            tempTargets.push_back(*itr);

                    if (tempTargets.empty())
                    {
                        unitList.clear();
                        FinishCast(SPELL_FAILED_DONT_REPORT);
                        return;
                    }

                    Unit* target = SelectRandomContainerElement(tempTargets);
                    unitList.clear();
                    unitList.push_back(target);
                }
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_dru_t10_restoration_4p_bonus_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ALLY_DST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_t10_restoration_4p_bonus_SpellScript();
        }
};

// 40121 - Swift Flight Form (Passive)
class spell_dru_swift_flight_passive : public SpellScriptLoader
{
    public:
        spell_dru_swift_flight_passive() : SpellScriptLoader("spell_dru_swift_flight_passive") { }

        class spell_dru_swift_flight_passive_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_swift_flight_passive_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                Unit* caster = GetCaster();
                if (!caster || !caster->ToPlayer())
                    return;

                if (caster->ToPlayer()->Has310Flyer(false))
                    amount = 310;
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_swift_flight_passive_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_dru_swift_flight_passive_AuraScript();
        }
};

// Ferocious Bite
// Spell Id: 22568
class spell_dru_ferocious_bite : public SpellScriptLoader
{
    public:
        spell_dru_ferocious_bite() : SpellScriptLoader("spell_dru_ferocious_bite") { }

        class spell_dru_ferocious_bite_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_ferocious_bite_SpellScript);

            void CalculateDamage(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    int32 damage = GetHitDamage();
                    float ap = caster->GetTotalAttackPowerValue(BASE_ATTACK);
                    float multiple = ap / 410 + SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), EFFECT_1);
                    int32 energy = -(caster->ModifyPower(POWER_ENERGY, -30));
                    damage += int32(energy * multiple);
                    damage += int32(CalculatePctN(caster->ToPlayer()->GetComboPoints() * ap, 7));
                    SetHitDamage(damage);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_dru_ferocious_bite_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_ferocious_bite_SpellScript;
        }
};

// Mark Of The Wild
// Spell Id: 1126
class spell_dru_mark_of_the_wild : public SpellScriptLoader
{
public:
    spell_dru_mark_of_the_wild() : SpellScriptLoader("spell_dru_mark_of_the_wild") { }

    class spell_dru_mark_of_the_wild_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dru_mark_of_the_wild_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->GetTypeId() == TYPEID_PLAYER)
                {
                    std::list<Unit*> PartyMembers;
                    caster->GetPartyMembers(PartyMembers);

                    bool Continue = false;
                    uint32 player = 0;

                    for (std::list<Unit*>::iterator itr = PartyMembers.begin(); itr != PartyMembers.end(); ++itr) // If caster is in party with a player
                    {
                        ++player;
                        if (Continue == false && player > 1)
                            Continue = true;
                    }
                    if (Continue == true)
                        caster->CastSpell(GetHitUnit(), 79061, true); // Mark of the Wild (Raid)
                    else
                        caster->CastSpell(GetHitUnit(), 79060, true); // Mark of the Wild (Caster)
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dru_mark_of_the_wild_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dru_mark_of_the_wild_SpellScript;
    }
};

// Berserk
// Spellid: 50334
class spell_dru_berserk : public SpellScriptLoader
{
   public:
       spell_dru_berserk() : SpellScriptLoader("spell_dru_berserk") {}

       class spell_dru_berserk_AuraScript : public AuraScript
       {
           PrepareAuraScript(spell_dru_berserk_AuraScript);
           void HandleEffectApply(AuraEffect const * /*aurEff*/, AuraEffectHandleModes /*mode*/)
           {
               if (Unit* target = GetTarget())
                   if (target->GetTypeId() == TYPEID_PLAYER)
                       target->ToPlayer()->RemoveSpellCategoryCooldown(971, true);
           }

           void Register()
           {
               OnEffectApply += AuraEffectApplyFn(spell_dru_berserk_AuraScript::HandleEffectApply, EFFECT_2, SPELL_AURA_MECHANIC_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
           }
       };

       AuraScript* GetAuraScript() const
       {
           return new spell_dru_berserk_AuraScript();
       }
};

// Wild mushroom, 88747
class spell_druid_wild_mushroom : public SpellScriptLoader
{
    public:
        spell_druid_wild_mushroom() : SpellScriptLoader("spell_druid_wild_mushroom") { }

        class spell_druid_wild_mushroom_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_druid_wild_mushroom_SpellScript)

            void HandleSummon(SpellEffIndex effIndex)
            {
                if (Player* player = GetCaster()->ToPlayer())
                {
                    PreventHitDefaultEffect(effIndex);
                    const SpellEntry* spell = GetSpellInfo();

                    std::list<Creature*> list;
                    player->GetCreatureListWithEntryInGrid(list, DRUID_NPC_WILD_MUSHROOM, 500.0f);
                    for (std::list<Creature*>::iterator i = list.begin(); i != list.end(); ++i)
                    {
                        if ((*i)->isSummon() && (*i)->GetCharmerOrOwner() == player)
                        if (!player)
                        return;
                        continue;

                        list.remove((*i));
                    }

                    if ((int32)list.size() >= spell->EffectBasePoints[0]) // Max 3
                        list.front()->ToTempSummon()->UnSummon();

                    Position pos;
                    GetTargetDest()->GetPosition(&pos);
                    const SummonPropertiesEntry* properties = sSummonPropertiesStore.LookupEntry(spell->EffectMiscValueB[effIndex]);
                    TempSummon* summon = player->SummonCreature(spell->EffectMiscValue[0], pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, GetSpellDuration(spell));
                    if (!summon)
                        return;
                    summon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, player->GetGUID());
                    summon->setFaction(player->getFaction());
                    summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, GetSpellInfo()->Id);
                    summon->SetMaxHealth(5);
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_druid_wild_mushroom_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_druid_wild_mushroom_SpellScript();
        }
};

// Wild mushroom : Detonate, 88751
class spell_druid_wild_mushroom_detonate : public SpellScriptLoader
{
    public:
        spell_druid_wild_mushroom_detonate() : SpellScriptLoader("spell_druid_wild_mushroom_detonate") { }

        class spell_druid_wild_mushroom_detonate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_druid_wild_mushroom_detonate_SpellScript)

            // Globals variables
            float spellRange;
            std::list<TempSummon*> mushroomList;

            bool Load()
            {
                spellRange = GetSpellRangeStore()->LookupEntry(GetSpellInfo()->rangeIndex)->maxRangeFriend;

                Player* player = GetCaster()->ToPlayer();
                if (!player)
                    return false;

                std::list<Creature*> list;
                std::list<TempSummon*> summonList;
                player->GetCreatureListWithEntryInGrid(list, DRUID_NPC_WILD_MUSHROOM, 500.0f);

                for (std::list<Creature*>::const_iterator i = list.begin(); i != list.end(); ++i)
                {
                    if ((*i)->isSummon() && (*i)->GetCharmerOrOwner() == player)
                    {
                        summonList.push_back((*i)->ToTempSummon());
                        continue;
                    }
                }
                mushroomList = summonList;

                if (!spellRange)
                    return false;

                return true;
            }

            SpellCastResult CheckCast()
            {
                Player* player = GetCaster()->ToPlayer();
                if (!player)
                    return SPELL_FAILED_CASTER_DEAD;

                if (mushroomList.empty())
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                bool inRange = false;

                for (std::list<TempSummon*>::const_iterator i = mushroomList.begin(); i != mushroomList.end(); ++i)
                {
                    Position shroomPos;
                    (*i)->GetPosition(&shroomPos);
                    if (player->IsWithinDist3d(&shroomPos, spellRange)) // Must have at least one mushroom within 40 yards
                    {
                        inRange = true;
                        break;
                    }
                }

                if (!inRange)
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_TARGET_TOO_FAR);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }
                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Player* player = GetCaster()->ToPlayer())
                {
                    uint32 fungal = NULL;
                    if (player->HasAura(DRUID_TALENT_FUNGAL_GROWTH_1)) // Fungal Growth Rank 1
                        fungal = DRUID_NPC_FUNGAL_GROWTH_1;
                    else if (player->HasAura(DRUID_TALENT_FUNGAL_GROWTH_2)) // Fungal Growth Rank 2
                        fungal = DRUID_NPC_FUNGAL_GROWTH_2;

                    for (std::list<TempSummon*>::const_iterator i = mushroomList.begin(); i != mushroomList.end(); ++i)
                    {
                        Position shroomPos;
                        (*i)->GetPosition(&shroomPos);
                        if (!player->IsWithinDist3d(&shroomPos, spellRange))
                            continue;

                        (*i)->CastSpell((*i), DRUID_SPELL_WILD_MUSHROOM_SUICIDE, true); // Explosion visual and suicide
                        player->CastSpell((*i)->GetPositionX(), (*i)->GetPositionY(), (*i)->GetPositionZ(), DRUID_SPELL_WILD_MUSHROOM_DAMAGE, true); // damage

                        if (fungal)
                            player->CastSpell((*i)->GetPositionX(), (*i)->GetPositionY(), (*i)->GetPositionZ(), fungal, true); // Summoning fungal growth
                    }
                }
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_druid_wild_mushroom_detonate_SpellScript::CheckCast);
                OnEffect += SpellEffectFn(spell_druid_wild_mushroom_detonate_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_druid_wild_mushroom_detonate_SpellScript();
        }
};

void AddSC_druid_spell_scripts()
{
    new spell_dru_glyph_of_starfire();
    new spell_dru_savage_defense();
    new spell_dru_t10_restoration_4p_bonus();
    new spell_dru_swift_flight_passive();
    new spell_dru_ferocious_bite();
    new spell_dru_mark_of_the_wild();
    new spell_dru_berserk();
    new spell_druid_wild_mushroom();
    new spell_druid_wild_mushroom_detonate();
}