/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
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
#include "ahnkahet.h"

//not in db
enum Yells
{
    SAY_AGGRO                                     = -1619014,
    SAY_SLAY_1                                    = -1619015,
    SAY_SLAY_2                                    = -1619016,
    SAY_SLAY_3                                    = -1619017,
    SAY_DEATH                                     = -1619018,
    SAY_EGG_SAC_1                                 = -1619019,
    SAY_EGG_SAC_2                                 = -1619020
};

enum Spells
{
    SPELL_BROOD_PLAGUE                            = 56130,
    H_SPELL_BROOD_PLAGUE                          = 59467,
    H_SPELL_BROOD_RAGE                            = 59465,
    SPELL_ENRAGE                                  = 26662, // Enraged if too far away from home
    SPELL_SUMMON_SWARMERS                         = 56119, //2x 30178  -- 2x every 10secs
    SPELL_SUMMON_SWARM_GUARD                      = 56120, //1x 30176  -- every 25secs

    // adds
    SPELL_SPRINT                = 56354,
    SPELL_GUARDIAN_AURA         = 56151
};

enum Creatures
{
    NPC_AHNKAHAR_SWARMER        = 30178,
    NPC_AHNKAHAR_GUARDIAN       = 30176
};

enum Events
{
    EVENT_PLAGUE = 1,
    EVENT_RAGE,
    EVENT_SUMMON_SWARMER,
    EVENT_CHECK_ENRAGE,
    DATA_RESPECT_YOUR_ELDERS
};

#define EMOTE_HATCHES                       "An Ahn'kahar Guardian hatches!"

class boss_elder_nadox : public CreatureScript
{
public:
    boss_elder_nadox() : CreatureScript("boss_elder_nadox") { }

    struct boss_elder_nadoxAI : public ScriptedAI
    {
            boss_elder_nadoxAI(Creature* c) : ScriptedAI(c), _summons(me)
        {
                _instance = c->GetInstanceScript();
        }

        void Reset()
        {
                _summons.DespawnAll();
                _events.Reset();

                _healthAmountModifier = 1;
                _guardianDied = false;

                if (_instance)
                    _instance->SetData(DATA_ELDER_NADOX_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
                DoScriptText(SAY_AGGRO, me);

                if (_instance)
                    _instance->SetData(DATA_ELDER_NADOX_EVENT, IN_PROGRESS);

                _events.ScheduleEvent(EVENT_PLAGUE, 13000);
                _events.ScheduleEvent(EVENT_SUMMON_SWARMER, 10000);

                if (IsHeroic())
                {
                    _events.ScheduleEvent(EVENT_RAGE, 12000);
                    _events.ScheduleEvent(EVENT_CHECK_ENRAGE, 5000);
                }
            }

            void JustSummoned(Creature* summon)
            {
                _summons.Summon(summon);
                summon->AI()->DoZoneInCombat();
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                if (summon->GetEntry() == NPC_AHNKAHAR_GUARDIAN)
                    _guardianDied = true;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_RESPECT_YOUR_ELDERS)
                    return !_guardianDied ? 1 : 0;

                return 0;
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
            }

            void JustDied(Unit* /*killer*/)
            {
                //_summons.DespawnAll();
                DoScriptText(SAY_DEATH, me);

                if (_instance)
                    _instance->SetData(DATA_ELDER_NADOX_EVENT, DONE);
            }

            void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PLAGUE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, DUNGEON_MODE(SPELL_BROOD_PLAGUE, H_SPELL_BROOD_PLAGUE));
                            _events.ScheduleEvent(EVENT_PLAGUE, 15000);
                            break;
                        case EVENT_RAGE:
                            DoCast(H_SPELL_BROOD_RAGE);
                            _events.ScheduleEvent(EVENT_RAGE, urand(5000, 10000));
                            break;
                        case EVENT_SUMMON_SWARMER:
                DoCast(me, SPELL_SUMMON_SWARMERS);
                if (urand(1,3) == 3) // 33% chance of dialog
                    DoScriptText(RAND(SAY_EGG_SAC_1,SAY_EGG_SAC_2), me);
                            _events.ScheduleEvent(EVENT_SUMMON_SWARMER, 10000);
                            break;
                        case EVENT_CHECK_ENRAGE:
                            if (me->HasAura(SPELL_ENRAGE))
                                return;
                            if (me->GetPositionZ() < 24.0f)
                                DoCast(me, SPELL_ENRAGE, true);
                            _events.ScheduleEvent(EVENT_CHECK_ENRAGE, 5000);
                            break;
                        default:
                            break;
                    }
                }

                if (me->HealthBelowPct(100 - _healthAmountModifier * 25))
            {
                me->MonsterTextEmote(EMOTE_HATCHES,me->GetGUID(),true);
                DoCast(me, SPELL_SUMMON_SWARM_GUARD);
                    ++_healthAmountModifier;
                }

            DoMeleeAttackIfReady();
        }

        private:
            bool _guardianDied;
            uint8 _healthAmountModifier;
            InstanceScript* _instance;
            SummonList _summons;
            EventMap _events;
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new boss_elder_nadoxAI(creature);
    }
};

class mob_ahnkahar_nerubian : public CreatureScript
{
    public:
        mob_ahnkahar_nerubian() : CreatureScript("mob_ahnkahar_nerubian") { }

        struct mob_ahnkahar_nerubianAI : public ScriptedAI
        {
            mob_ahnkahar_nerubianAI(Creature* c) : ScriptedAI(c)
            {
            }

            void Reset()
            {
                if (me->GetEntry() == NPC_AHNKAHAR_GUARDIAN)
                    DoCast(me, SPELL_GUARDIAN_AURA, true);

                _sprintTimer = 5*IN_MILLISECONDS;
            }

            void JustDied(Unit* /*killer*/)
            {
                if (me->GetEntry() == NPC_AHNKAHAR_GUARDIAN)
                    me->RemoveAurasDueToSpell(SPELL_GUARDIAN_AURA);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (_sprintTimer <= diff)
                {
                    DoCast(me, SPELL_SPRINT);
                    _sprintTimer = 20*IN_MILLISECONDS;
                }
                else
                    _sprintTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _sprintTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ahnkahar_nerubianAI(creature);
        }
};

//HACK: No, AI. Replace with proper db content?
class mob_nadox_eggs : public CreatureScript
{
public:
    mob_nadox_eggs() : CreatureScript("mob_nadox_eggs") { }

    struct mob_nadox_eggsAI : public Scripted_NoMovementAI
    {
        mob_nadox_eggsAI(Creature* c) : Scripted_NoMovementAI(c)
        {
            c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            c->UpdateAllStats();
        }

        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*victim*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
            void UpdateAI(uint32 const /*diff*/) {}
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_nadox_eggsAI(creature);
    }
};

class GuardianCheck
{
    public:
        bool operator() (Unit* unit)
        {
            if (unit->GetEntry() == NPC_AHNKAHAR_GUARDIAN)
                return true;

            return false;
        }
};

class spell_elder_nadox_guardian_aura : public SpellScriptLoader
{
    public:
        spell_elder_nadox_guardian_aura() : SpellScriptLoader("spell_elder_nadox_guardian_aura") { }

        class spell_elder_nadox_guardian_aura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_elder_nadox_guardian_aura_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(GuardianCheck());
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_elder_nadox_guardian_aura_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ALLY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_elder_nadox_guardian_aura_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ALLY_SRC);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_elder_nadox_guardian_aura_SpellScript();
        }
};

class achievement_respect_your_elders : public AchievementCriteriaScript
{
    public:
        achievement_respect_your_elders() : AchievementCriteriaScript("achievement_respect_your_elders")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* nadox = target->ToCreature())
                if (nadox->AI()->GetData(DATA_RESPECT_YOUR_ELDERS))
                    return true;

            return false;
        }
};

void AddSC_boss_elder_nadox()
{
    new boss_elder_nadox;
    new mob_ahnkahar_nerubian;
    new mob_nadox_eggs;
    new spell_elder_nadox_guardian_aura();
    new achievement_respect_your_elders();
}
