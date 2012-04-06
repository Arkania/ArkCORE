/*
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008 - 2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "gundrak.h"

enum Spells
{
    SPELL_EMERGE                                  = 54850,
    SPELL_MIGHTY_BLOW                             = 54719,
    SPELL_MORTAL_STRIKE                           = 54715,
    SPELL_MERGE                                   = 54878,
    SPELL_SURGE                                   = 54801,
    SPELL_FREEZE_ANIM                             = 16245,
    SPELL_MOJO_VOLLEY                             = 54849,
    SPELL_MOJO_VOLLEY_TRIGGERED                   = 54847,
    H_SPELL_MOJO_VOLLEY                           = 59453,
    H_SPELL_MOJO_VOLLEY_TRIGGERED                 = 59452,
    SPELL_MOJO_PUDDLE                             = 59451,
    SPELL_MOJO_WAVE                               = 55626,
    H_SPELL_MOJO_WAVE                             = 58993
};

enum Emotes
{
    EMOTE_SURGE                                   = -1604008,
    EMOTE_SEEP                                    = -1604009,
    EMOTE_GLOW                                    = -1604010
};

enum Creatures
{
    CREATURE_MOJO                                 = 29830
};

enum Action
{
    ACTION_FREEZE = 1,
    ACTION_UNFREEZE,
    DATA_EMERGED
};

static Position SpawnLoc[]=
{
    {1669.98f, 753.686f, 143.074f, 4.95674f},
    {1680.67f, 737.104f, 143.083f, 2.53073f},
    {1680.63f, 750.682f, 143.074f, 3.87463f},
    {1663.1f,  743.665f, 143.078f, 6.19592f},
    {1670.39f, 733.493f, 143.073f, 1.27409f}
};

class boss_drakkari_colossus : public CreatureScript
{
    public:
        boss_drakkari_colossus() : CreatureScript("boss_drakkari_colossus") { }

        struct boss_drakkari_colossusAI : public ScriptedAI
        {
            boss_drakkari_colossusAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();

                // 100% too much?
                SpellEntry* spell = (SpellEntry*)sSpellStore.LookupEntry(SPELL_MORTAL_STRIKE);
              //TODO: Fix spell proc
			  // if (spell)
              //      spell->ProcChance = 50;
            }

            void Reset()
            {
                if (_instance)
                    _instance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, NOT_STARTED);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                DoDespawnMojo();
                DoSpawnMojo();

                _mightyBlowTimer = 10*IN_MILLISECONDS;
                _phase = 0;
                _mojoDespawnTimer = 2*IN_MILLISECONDS;

                DoAction(ACTION_UNFREEZE);
            }

            void JustReachedHome()
            {
                DoCast(me, SPELL_FREEZE_ANIM);
            }

            void DoSpawnMojo()
            {
                for (uint8 i = 0; i < 5; ++i)
                    if (Creature* mojo = me->SummonCreature(CREATURE_MOJO, SpawnLoc[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1*IN_MILLISECONDS))
                    {
                        _mojoGUID[i] = mojo->GetGUID();
                        mojo->SetVisible(true);
                        mojo->SetReactState(REACT_PASSIVE);
                        mojo->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }
            }

            void DoDespawnMojo()
            {
                for (uint8 i = 0; i < 5; ++i)
                {
                    if (_mojoGUID[i])
                    {
                        Creature* mojo = Unit::GetCreature((*me), _mojoGUID[i]);
                        if (mojo && mojo->isAlive())
                        {
                            mojo->SetVisible(false);
                            mojo->DespawnOrUnsummon();
                        }
                    }
                    _mojoGUID[i] = 0;
                }
            }

            void DoMoveMojo()
            {
                for (uint8 i = 0; i < 5; ++i)
                    if (_mojoGUID[i])
                    {
                        Creature* mojo = Unit::GetCreature((*me), _mojoGUID[i]);
                        if (mojo && mojo->isAlive())
                        {
                            mojo->GetMotionMaster()->Clear();
                            mojo->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                        }
                    }
            }

            void EnterEvadeMode()
            {
                me->ClearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                _EnterEvadeMode();
                me->GetMotionMaster()->MoveTargetedHome();
                Reset();
            }

            uint32 GetData(uint32 data)
            {
                if (data == DATA_EMERGED)
                    return (_phase == 4) ? 1 : 0;

                return 0;
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_FREEZE:
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->AddUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                        DoCast(SPELL_FREEZE_ANIM);
                        break;
                    case ACTION_UNFREEZE:
                        me->ClearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveAura(SPELL_FREEZE_ANIM);
                        DoCast(SPELL_MORTAL_STRIKE);
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (_instance)
                    _instance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, IN_PROGRESS);

                me->RemoveAura(SPELL_FREEZE_ANIM);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                _phase = 1;
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage)
            {
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;
            }

            void JustDied(Unit* /*killer*/)
            {
                if (_instance)
                    _instance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, DONE);
            }

            void JustSummoned(Creature* summon)
            {
                if (HealthBelowPct(5))
                    summon->DealDamage(summon, uint32(summon->GetHealth() * 0.5), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                summon->AI()->AttackStart(me->getVictim());
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (_phase == 1)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                    DoAction(ACTION_FREEZE);
                    DoMoveMojo();
                    ++_phase;
                }

                if (_phase == 2)
                {
                    if (_mojoDespawnTimer <= diff)
                    {
                        DoDespawnMojo();
                        DoAction(ACTION_UNFREEZE);
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                        ++_phase;
                    }
                    else
                        _mojoDespawnTimer -= diff;
                }

                if (_phase == 3 && HealthBelowPct(50) || _phase == 4 && HealthBelowPct(5))
                {
                    DoAction(ACTION_FREEZE);
                    DoCast(me, SPELL_EMERGE);
                    ++_phase;
                    me->RemoveAllAuras();
                }

                if (me->HasUnitState(UNIT_STAT_STUNNED))
                    return;

                if (_mightyBlowTimer <= diff)
                {
                    DoCastVictim(SPELL_MIGHTY_BLOW);
                    _mightyBlowTimer = 15*IN_MILLISECONDS;
                }
                else
                    _mightyBlowTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            uint8 _phase;
            uint32 _mightyBlowTimer;
            uint32 _mojoDespawnTimer;
            uint64 _mojoGUID[5];
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_drakkari_colossusAI(creature);
        }
};

class boss_drakkari_elemental : public CreatureScript
{
    public:
        boss_drakkari_elemental() : CreatureScript("boss_drakkari_elemental") { }

        struct boss_drakkari_elementalAI : public ScriptedAI
        {
            boss_drakkari_elementalAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                _surgeTimer = 15000;
                _disappearTimer = 2500;
                _mojoWaveTimer = 7000;
                _merging = false;
            }

            void EnterEvadeMode()
            {
                if (Creature* colossus = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
                    colossus->AI()->DoAction(ACTION_UNFREEZE);

                me->SetVisible(false);
                me->DisappearAndDie();
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoCast(me, DUNGEON_MODE<uint32>(SPELL_MOJO_VOLLEY, H_SPELL_MOJO_VOLLEY));
            }

            void JustDied(Unit* /*killer*/)
            {
                me->RemoveAurasDueToSpell(DUNGEON_MODE<uint32>(SPELL_MOJO_VOLLEY, H_SPELL_MOJO_VOLLEY));

                if (Creature* colossus = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
                {
                    colossus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    colossus->Kill(colossus);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (!_merging && HealthBelowPct(50))
                    if (Creature* colossus = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
                        if (colossus->AI()->GetData(DATA_EMERGED))
                        {
                            me->InterruptNonMeleeSpells(true);
                            DoCast(colossus, SPELL_MERGE);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            me->RemoveAurasDueToSpell(DUNGEON_MODE<uint32>(SPELL_MOJO_VOLLEY, H_SPELL_MOJO_VOLLEY));
                            _merging = true;
                        }

                if (_merging)
                    if (_disappearTimer <= diff)
                    {
                        if (Creature* colossus = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
                            colossus->AI()->DoAction(ACTION_UNFREEZE);

                        me->DisappearAndDie();
                    }
                    else
                        _disappearTimer -= diff;

                if (_surgeTimer <= diff)
                {
                    DoCastVictim(SPELL_SURGE);
                    _surgeTimer = urand(15000, 25000);
                }
                else
                    _surgeTimer -= diff;

                if (_mojoWaveTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        DoCast(target, DUNGEON_MODE<uint32>(SPELL_MOJO_WAVE, H_SPELL_MOJO_WAVE));
                        _mojoWaveTimer = urand(10000, 20000);
                    }
                }
                else
                    _mojoWaveTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            uint32 _surgeTimer;
            uint32 _disappearTimer;
            uint32 _mojoWaveTimer;
            bool _merging;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_drakkari_elementalAI(creature);
        }
};

class npc_living_mojo : public CreatureScript
{
    public:
        npc_living_mojo() : CreatureScript("npc_living_mojo") { }

        struct npc_living_mojoAI : public ScriptedAI
        {
            npc_living_mojoAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _mojoWaveTimer = 5*IN_MILLISECONDS;
                _mojoPuddleTimer = 10*IN_MILLISECONDS;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (_mojoWaveTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        DoCastVictim(DUNGEON_MODE<uint32>(SPELL_MOJO_WAVE, H_SPELL_MOJO_WAVE));
                        _mojoWaveTimer = 10*IN_MILLISECONDS;
                    }
                }
                else
                    _mojoWaveTimer -= diff;

                if (_mojoPuddleTimer <= diff)
                {
                    DoCast(H_SPELL_MOJO_VOLLEY_TRIGGERED);
                    _mojoPuddleTimer = DUNGEON_MODE<uint32>(20*IN_MILLISECONDS, 10*IN_MILLISECONDS);
                }
                else
                    _mojoPuddleTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _mojoWaveTimer;
            uint32 _mojoPuddleTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_living_mojoAI (creature);
        }
};

class spell_mojo_volley_targeting : public SpellScriptLoader
{
    public:
        spell_mojo_volley_targeting() : SpellScriptLoader("spell_mojo_volley_targeting") { }

        class spell_mojo_volley_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mojo_volley_targeting_SpellScript);

            void FilterTargetsInitial(std::list<Unit*>& unitList)
            {
                sharedUnitList = unitList;
            }

            void FilterTargetsSubsequent(std::list<Unit*>& unitList)
            {
                unitList = sharedUnitList;
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_mojo_volley_targeting_SpellScript::FilterTargetsInitial, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_mojo_volley_targeting_SpellScript::FilterTargetsSubsequent, EFFECT_1, TARGET_UNIT_AREA_ENEMY_SRC);
            }

            std::list<Unit*> sharedUnitList;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mojo_volley_targeting_SpellScript();
        }
};

class spell_mojo_volley_trigger : public SpellScriptLoader
{
    public:
        spell_mojo_volley_trigger() : SpellScriptLoader("spell_mojo_volley_trigger") { }

        class spell_mojo_volley_trigger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mojo_volley_trigger_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                uint32 triggerSpellId = GetSpellProto()->EffectTriggerSpell[0];

                if (Unit* caster = GetCaster())
                    caster->CastCustomSpell(triggerSpellId, SPELLVALUE_MAX_TARGETS, irand(1, 2), caster, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mojo_volley_trigger_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_mojo_volley_trigger_AuraScript();
        }
};

void AddSC_boss_drakkari_colossus()
{
    new boss_drakkari_colossus();
    new boss_drakkari_elemental();
    new npc_living_mojo();
    new spell_mojo_volley_targeting();
    new spell_mojo_volley_trigger();
}
