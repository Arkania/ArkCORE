/*
 * Copyright (C) 2008 - 2012 ArkCORE <http://www.arkania.net/>
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
SDName: Argent Challenge Encounter.
SD%Complete: 90 %
SDComment: AI for Argent Soldiers are not implemented. AI from bosses need more improvements.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "trial_of_the_champion.h"
#include "ScriptedEscortAI.h"

enum eSpells
{
    //Eadric
    SPELL_EADRIC_ACHIEVEMENT    = 68197,
    SPELL_HAMMER_JUSTICE        = 66863,
    SPELL_HAMMER_RIGHTEOUS      = 66867,
    SPELL_RADIANCE              = 66935,
    SPELL_VENGEANCE             = 66865,

    //Paletress
    SPELL_SMITE                 = 66536,
    SPELL_SMITE_H               = 67674,
    SPELL_HOLY_FIRE             = 66538,
    SPELL_HOLY_FIRE_H           = 67676,
    SPELL_RENEW                 = 66537,
    SPELL_RENEW_H               = 67675,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_SHIELD                = 66515,
    SPELL_CONFESS               = 66680,

    //Npc_argent_soldier

    //Monk
    SPELL_DIVINE                = 67251,
    SPELL_FINAL                 = 67255,
    SPELL_FLURRY                = 67233,
	SPELL_PUMMEL                = 67235,

    //Priestess
    SPELL_SSMITE                = 36176,
    SPELL_SSMITE_H              = 67289,
    SPELL_PAIN                  = 34941,
    SPELL_PAIN_H                = 34941,
    SPELL_MIND                  = 67229,

    //Lightwielder
    SPELL_LIGHT				    = 67247,
    SPELL_LIGHT_H               = 67290,
    SPELL_STRIKE                = 67237,
    SPELL_CLEAVE                = 15284,

    SPELL_FONT                  = 67194,

    //Memory
    SPELL_OLD_WOUNDS            = 66620,
    SPELL_OLD_WOUNDS_H          = 67679,
    SPELL_SHADOWS_PAST          = 66619,
    SPELL_SHADOWS_PAST_H        = 67678,
    SPELL_WAKING_NIGHTMARE      = 66552,
    SPELL_WAKING_NIGHTMARE_H    = 67677
};
enum Misc
{
    ACHIEV_FACEROLLER           = 3803,
    ACHIEV_CONF                 = 3802
};

enum eEnums
{
    SAY_MEM_DIE                             = -1999968,
    SAY_DEATH_P                             = -1999967,
    SAY_INTRO_P2                            = -1999966,
    SAY_INTRO_P1                            = -1999965,
    SAY_INTRO_E                             = -1999964,
    SAY_HAMMER_E                            = -1999963,
    SAY_DEATH_E                             = -1999962,
    SAY_START_E                             = -1999961,
    SAY_KILL1_P                             = -1999960,
    SAY_KILL2_P                             = -1999959,
    SAY_KILL1_E                             = -1999958,
    SAY_KILL2_E                             = -1999957,
    SAY_START_10                            = -1999956,
    SAY_START_9                             = -1999955,
    SAY_START_8                             = -1999941,
    SAY_START_P                             = -1999955,
    SAY_START_7                             = -1999954,
    SAY_START_6                             = -1999951
};

class OrientationCheck : public std::unary_function<Unit*, bool>
{
    public:
        explicit OrientationCheck(Unit* _caster) : caster(_caster) { }
        bool operator() (Unit* unit)
        {
            return !unit->isInFront(caster, 40.0f, 2.5f);
        }

    private:
        Unit* caster;
};

class spell_eadric_radiance : public SpellScriptLoader
{
    public:
        spell_eadric_radiance() : SpellScriptLoader("spell_eadric_radiance") { }
        class spell_eadric_radiance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_eadric_radiance_SpellScript);
            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(OrientationCheck(GetCaster()));
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_eadric_radiance_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_eadric_radiance_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ENEMY_SRC);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_eadric_radiance_SpellScript();
        }
};

class boss_eadric : public CreatureScript
{
public:
    boss_eadric() : CreatureScript("boss_eadric") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_eadricAI(creature);
    }

    struct boss_eadricAI : public ScriptedAI
    {
        boss_eadricAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
            creature->SetReactState(REACT_PASSIVE);
            creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
            creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
        }

        InstanceScript* pInstance;

        uint32 uiVenganceTimer;
        uint32 uiRadianceTimer;
        uint32 uiHammerJusticeTimer;
        uint32 uiResetTimer;

        bool bDone;

        void Reset()
        {
            uiVenganceTimer = 10000;
            uiRadianceTimer = 16000;
            uiHammerJusticeTimer = 25000;
            uiResetTimer = 5000;
            me->GetMotionMaster()->MovePoint(1,746.71f,661.02f,411.69f);
            me->SetOrientation(4.714f);
            bDone = false;
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EnterEvadeMode();
                me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
                DoScriptText(SAY_DEATH_E, me);
                me->setFaction(35);
                bDone = true;
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(),true);
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                        pInstance->HandleGameObject(pGO->GetGUID(),true);
            if (pInstance)
                pInstance->SetData(BOSS_ARGENT_CHALLENGE_E, DONE);
                        if (IsHeroic())
                        pInstance->DoCompleteAchievement(ACHIEV_FACEROLLER);
            }
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_START_E, me);
        }

        void KilledUnit(Unit* victim)
        {
            DoScriptText(urand(0, 1) ? SAY_KILL1_E : SAY_KILL2_E, me);
            if (pInstance)
                pInstance->SetData(BOSS_ARGENT_CHALLENGE_E,IN_PROGRESS);
        }

        void MovementInform(uint32 MovementType, uint32 Data)
        {
            if (MovementType != POINT_MOTION_TYPE)
                return;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (bDone && uiResetTimer <= uiDiff)
            {
                me->GetMotionMaster()->MovePoint(0,746.843f, 695.68f, 412.339f);
                pInstance->SetData(BOSS_ARGENT_CHALLENGE_E, DONE);
                me->DisappearAndDie();
                bDone = false;
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(),true);
            } else uiResetTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            if (uiHammerJusticeTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                {
                    if (target && target->isAlive())
                    {
                        DoScriptText(SAY_HAMMER_E , me);
                        DoCast(target, SPELL_HAMMER_JUSTICE);
                        DoCast(target, SPELL_HAMMER_RIGHTEOUS);
                    }
                }
                uiHammerJusticeTimer = 25000;
            } else uiHammerJusticeTimer -= uiDiff;

            if (uiVenganceTimer <= uiDiff)
            {
                DoCast(me, SPELL_VENGEANCE);

                uiVenganceTimer = 10000;
            } else uiVenganceTimer -= uiDiff;

            if (uiRadianceTimer <= uiDiff)
            {
                DoCastAOE(SPELL_RADIANCE);

                uiRadianceTimer = 16000;
            } else uiRadianceTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class boss_paletress : public CreatureScript
{
public:
    boss_paletress() : CreatureScript("boss_paletress") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_paletressAI(creature);
    }

    struct boss_paletressAI : public ScriptedAI
    {
        boss_paletressAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();

            MemoryGUID = 0;
            creature->SetReactState(REACT_PASSIVE);
            creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
            creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
            creature->RestoreFaction();
        }

        InstanceScript* pInstance;

        Creature* pMemory;
        uint64 MemoryGUID;

        bool bHealth;
        bool bDone;

        uint32 uiHolyFireTimer;
        uint32 uiHolySmiteTimer;
        uint32 uiRenewTimer;
        uint32 uiResetTimer;

        void Reset()
        {
            me->RemoveAllAuras();

            uiHolyFireTimer     = urand(9000, 12000);
            uiHolySmiteTimer    = urand(5000, 7000);
            uiRenewTimer        = urand(2000, 5000);

            uiResetTimer        = 7000;

            me->GetMotionMaster()->MovePoint(1,746.71f,661.02f,411.69f);
            me->SetOrientation(4.714f);

            bHealth = false;
            bDone = false;

            if (Creature* pMemory = Unit::GetCreature(*me, MemoryGUID))
                if (pMemory->isAlive())
                    pMemory->RemoveFromWorld();
        }

        void SetData(uint32 uiId, uint32 /*uiValue*/)
        {
            if (uiId == 1)
            {
                me->RemoveAura(SPELL_SHIELD);
                DoScriptText(SAY_MEM_DIE, me);
        }
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EnterEvadeMode();
                me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
                DoScriptText(SAY_START_7, me);
                me->setFaction(35);
                bDone = true;
                DoScriptText(SAY_DEATH_P, me);
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(),true);
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                        pInstance->HandleGameObject(pGO->GetGUID(),true);
                pInstance->SetData(BOSS_ARGENT_CHALLENGE_P, DONE);
                if (IsHeroic())
                    pInstance->DoCompleteAchievement(ACHIEV_CONF);
            }
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_START_P, me);
        }

        void KilledUnit(Unit* victim)
        {
            DoScriptText(urand(0, 1) ? SAY_KILL1_P : SAY_KILL2_P, me);
            if (pInstance)
                pInstance->SetData(BOSS_ARGENT_CHALLENGE_P,IN_PROGRESS);
        }

        void MovementInform(uint32 MovementType, uint32 Data)
        {
            if (MovementType != POINT_MOTION_TYPE)
                return;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (bDone && uiResetTimer <= uiDiff)
            {
                me->GetMotionMaster()->MovePoint(0,746.843f, 695.68f, 412.339f);
                bDone = false;
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(),true);
                me->DisappearAndDie();
            } else uiResetTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            if (uiHolyFireTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                {
                    if (target && target->isAlive())
                        DoCast(me->getVictim(), RAID_MODE(SPELL_HOLY_FIRE, SPELL_HOLY_FIRE_H));
                }
                 if (me->HasAura(SPELL_SHIELD))
                    uiHolyFireTimer = 13000;
                else
                    uiHolyFireTimer = urand(9000,12000);
            } else uiHolyFireTimer -= uiDiff;

            if (uiHolySmiteTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
                {
                    if (target && target->isAlive())
                        DoCast(me->getVictim(), RAID_MODE(SPELL_SMITE, SPELL_SMITE_H));
                }
                if (me->HasAura(SPELL_SHIELD))
                    uiHolySmiteTimer = 9000;
                else
                    uiHolySmiteTimer = urand(5000,7000);
            } else uiHolySmiteTimer -= uiDiff;

            if (me->HasAura(SPELL_SHIELD))
            {
                if (uiRenewTimer <= uiDiff)
                {
                    me->InterruptNonMeleeSpells(true);
                    uint8 uiTarget = urand(0,1);
                    switch(uiTarget)
                    {
                        case 0:
                            DoCast(me, RAID_MODE(SPELL_RENEW, SPELL_RENEW_H));
                            break;
                        case 1:
                            if (Creature* pMemory = Unit::GetCreature(*me, MemoryGUID))
                                if (pMemory->isAlive())
                                    DoCast(pMemory, RAID_MODE(SPELL_RENEW,SPELL_RENEW_H));
                            break;
                    }
                    uiRenewTimer = urand(15000,17000);
                } else uiRenewTimer -= uiDiff;
            }

            if (!bHealth && me->GetHealth()*100 / me->GetMaxHealth() <= 35)
            {
            DoScriptText(SAY_START_6, me);
                me->InterruptNonMeleeSpells(true);
                DoCastAOE(SPELL_HOLY_NOVA,false);
                DoCast(me, SPELL_SHIELD);
                DoCastAOE(SPELL_CONFESS,false);

                bHealth = true;

                switch(urand(0, 24))
                {
        case 0: me->SummonCreature(MEMORY_ALGALON, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
            break;
        case 1: me->SummonCreature(MEMORY_CHROMAGGUS, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 2: me->SummonCreature(MEMORY_CYANIGOSA, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 3: me->SummonCreature(MEMORY_DELRISSA, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 4: me->SummonCreature(MEMORY_ECK, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 5: me->SummonCreature(MEMORY_ENTROPIUS, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 6: me->SummonCreature(MEMORY_GRUUL, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 7: me->SummonCreature(MEMORY_HAKKAR, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 8: me->SummonCreature(MEMORY_HEIGAN, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 9: me->SummonCreature(MEMORY_HEROD, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 10: me->SummonCreature(MEMORY_HOGGER, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 11: me->SummonCreature(MEMORY_IGNIS, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 12: me->SummonCreature(MEMORY_ILLIDAN, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 13: me->SummonCreature(MEMORY_INGVAR, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 14: me->SummonCreature(MEMORY_KALITHRESH, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 15: me->SummonCreature(MEMORY_LUCIFRON, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 16: me->SummonCreature(MEMORY_MALCHEZAAR, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 17: me->SummonCreature(MEMORY_MUTANUS, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 18: me->SummonCreature(MEMORY_ONYXIA, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 19: me->SummonCreature(MEMORY_THUNDERAAN, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 20: me->SummonCreature(MEMORY_VANCLEEF, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 21: me->SummonCreature(MEMORY_VASHJ, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 22: me->SummonCreature(MEMORY_VEKNILASH, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 23: me->SummonCreature(MEMORY_VEZAX, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
        case 24: me->SummonCreature(MEMORY_ARCHIMONDE, 0.0f, 0.0f, 0.0f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon)
        {
            MemoryGUID = summon->GetGUID();
        }
    };
};

class npc_memory : public CreatureScript
{
public:
    npc_memory() : CreatureScript("npc_memory") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_memoryAI(creature);
    }

    struct npc_memoryAI : public ScriptedAI
    {
        npc_memoryAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 uiOldWoundsTimer;
        uint32 uiShadowPastTimer;
        uint32 uiWakingNightmare;

        void Reset()
        {
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
            uiOldWoundsTimer = 12000;
            uiShadowPastTimer = 5000;
            uiWakingNightmare = 7000;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiOldWoundsTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    if (target && target->isAlive())
                        DoCast(me->getVictim(), RAID_MODE(SPELL_OLD_WOUNDS, SPELL_OLD_WOUNDS_H));
                }
                uiOldWoundsTimer = 12000;
            }else uiOldWoundsTimer -= uiDiff;

            if (uiWakingNightmare <= uiDiff)
            {
                DoCast(me, RAID_MODE(SPELL_WAKING_NIGHTMARE, SPELL_WAKING_NIGHTMARE_H));
                uiWakingNightmare = 7000;
            }else uiWakingNightmare -= uiDiff;

            if (uiShadowPastTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,1))
                {
                    if (target && target->isAlive())
                        DoCast(me->getVictim(), RAID_MODE(SPELL_SHADOWS_PAST, SPELL_SHADOWS_PAST_H));
                }
                uiShadowPastTimer = 5000;
            }else uiShadowPastTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (me->isSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                    if (summoner->isAlive())
                        summoner->GetAI()->SetData(1, 0);
        }
    };
};

// THIS AI NEEDS MORE IMPROVEMENTS
class npc_argent_soldier : public CreatureScript
{
public:
    npc_argent_soldier() : CreatureScript("npc_argent_soldier") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_argent_soldierAI(creature);
    }

    struct npc_argent_soldierAI : public npc_escortAI
    {
        npc_argent_soldierAI(Creature* creature) : npc_escortAI(creature)
        {
            pInstance = creature->GetInstanceScript();
            me->SetReactState(REACT_DEFENSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
            if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(),true);

            SetDespawnAtEnd(false);
            uiWaypoint = 0;
        }

        InstanceScript* pInstance;

        uint8 uiWaypoint;
        uint32 uiCleaveTimer;
        uint32 uiStrikeTimer;
        uint32 uiblazingLightTimer;
        uint32 uiFlurryTimer;
        uint32 uiPummelTimer;
        uint32 uiPainTimer;
        uint32 uiMindTimer;
        uint32 uiSsmiteTimer;
        uint32 uiFontTimer;
        uint32 uiLightTimer;

        uint32 uiFinalTimer;
        uint32 uiDivineTimer;
        uint32 uiResetTimer;

        uint32 uiHolySmiteTimer;
        uint32 uiFountainTimer;
        bool Shielded;

        void Reset()
        {
                    uiCleaveTimer = 10000;
                    uiStrikeTimer = 12000;
                    uiblazingLightTimer = 9000;
                    uiFlurryTimer = 8000;
                    uiPummelTimer = 10000;
                    Shielded = false;
					uiPainTimer = 8000;
            uiMindTimer = 7000;
              uiSsmiteTimer = 9000;
            uiResetTimer = 3000;
            uiLightTimer = 2000;
                    uiFontTimer = 10000;

            uiFinalTimer = 21000;
            uiDivineTimer = 20000;
        }

        void WaypointReached(uint32 uiPoint)
        {
            if (uiPoint == 0)
            {
                switch(uiWaypoint)
                {
                    case 0:
                        me->SetOrientation(5.81f);
                        break;
                    case 1:
                        me->SetOrientation(4.60f);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        break;
                        break;
                }
            }
            if (uiPoint == 1)
            {
                switch(uiWaypoint)
                {
                    case 0:
                        me->SetOrientation(5.81f);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    case 2:
                        me->SetOrientation(3.39f);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(),false);
                        break;
                }
                me->SendMovementFlagUpdate();
            }
        }

        void SetData(uint32 uiType, uint32 /*uiData*/)
        {
            switch(me->GetEntry())
            {
                case NPC_ARGENT_LIGHWIELDER:
                    switch(uiType)
                    {
                        case 0:
                            AddWaypoint(0,737.14f,655.42f,412.88f);
                            AddWaypoint(1,712.14f,628.42f,411.88f);
                            break;
                        case 1:
                            AddWaypoint(0,742.44f,650.29f,411.79f);
                            break;
                        case 2:
                            AddWaypoint(0,756.14f,655.42f,411.88f);
                            AddWaypoint(1,781.626f, 629.383f, 411.892f);
                            break;
                    }
                    break;
                case NPC_ARGENT_MONK:
                    switch(uiType)
                    {
                        case 0:
                            AddWaypoint(0,737.14f,655.42f,412.88f);
                            AddWaypoint(1,713.12f,632.97f,411.90f);
                            break;
                        case 1:
                            AddWaypoint(0,746.73f,650.24f,411.56f);
                            break;
                        case 2:
                            AddWaypoint(0,756.14f,655.42f,411.88f);
                            AddWaypoint(1,781.351f, 633.146f, 411.907f);
                            break;
                    }
                    break;
                case NPC_PRIESTESS:
                    switch(uiType)
                    {
                        case 0:
                            AddWaypoint(0,737.14f,655.42f,412.88f);
                            AddWaypoint(1,715.06f,637.07f,411.91f);
                            break;
                        case 1:
                            AddWaypoint(0,750.72f,650.20f,411.77f);
                            break;
                        case 2:
                            AddWaypoint(0,756.14f,655.42f,411.88f);
                            AddWaypoint(1,780.439f, 636.681f, 411.918f);
                            break;
                    }
                    break;
            }

            Start(false,true,0);
            uiWaypoint = uiType;
        }

        void DamageTaken(Unit * /*done_by*/, uint32 &damage)
        {
            if (me->GetEntry() == NPC_ARGENT_MONK && IsHeroic() && Shielded==false)
            {
                if (damage >= me->GetHealth())
                {
                    DoCast(me, SPELL_DIVINE);
                    DoCast(me, SPELL_FINAL);
                    me->SetHealth(1);
                    damage = 0;
                    Shielded = true;
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

        switch(me->GetEntry())
        {
            case NPC_ARGENT_LIGHWIELDER:
            {
                if (uiCleaveTimer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                        DoCast(target,SPELL_STRIKE);
                        uiCleaveTimer = 12000;
                } else
				      uiCleaveTimer -= uiDiff;

                if (uiStrikeTimer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                        DoCast(target,SPELL_CLEAVE);
                        uiStrikeTimer = 10000;
                } else
				      uiStrikeTimer -= uiDiff;

                if (uiLightTimer <= uiDiff)
                {
                        DoCast(me, RAID_MODE(SPELL_LIGHT, SPELL_LIGHT_H));
                        uiLightTimer = urand (12000, 15000);
                } else
				      uiLightTimer -= uiDiff;
                break;
            }
            case NPC_ARGENT_MONK:
            {
                if (uiDivineTimer <= uiDiff)
                {
                        DoCast(me,SPELL_DIVINE);
                        uiDivineTimer = 85000;
                } else
				      uiDivineTimer -= uiDiff;

                if (uiFinalTimer <= uiDiff)
                {
                        DoCast(me,SPELL_FINAL);
                        uiFinalTimer = 70000;
                } else
				      uiFinalTimer -= uiDiff;

                if (uiPummelTimer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                        DoCast(target,SPELL_PUMMEL);
                        uiPummelTimer = 15000;
                } else
				      uiPummelTimer -= uiDiff;

                if (uiFlurryTimer <= uiDiff)
                {
                        DoCast(me,SPELL_FLURRY);
                        uiFlurryTimer = 15000;
                } else
				      uiFlurryTimer -= uiDiff;
                break;
            }
            case NPC_PRIESTESS:
            {
                if (uiFontTimer <= uiDiff)
                {
                        DoCast(me,SPELL_FONT);
                        uiFontTimer = urand (15000, 17000);
                } else
				      uiFontTimer -= uiDiff;

                if (uiPainTimer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                        DoCast(target,SPELL_PAIN);
                        uiPainTimer = 25000;
                } else
				      uiPainTimer -= uiDiff;

                if (uiMindTimer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                        DoCast(target,SPELL_MIND);
                        uiMindTimer = 90000;
                } else
				      uiMindTimer -= uiDiff;

                if (uiSsmiteTimer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                        DoCast(target,SPELL_SSMITE);
                        uiSsmiteTimer = 9000;
                } else
				      uiSsmiteTimer -= uiDiff;
                break;
            }
        }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_ARGENT_SOLDIER_DEFEATED, pInstance->GetData(DATA_ARGENT_SOLDIER_DEFEATED) + 1);
        }
    };
};

enum ReflectiveShield
{
    SPELL_REFLECTIVE_SHIELD_TRIGGERED = 33619,
};

// Reflective Shield 66515
class spell_gen_reflective_shield : public SpellScriptLoader
{
    public:
        spell_gen_reflective_shield() : SpellScriptLoader("spell_gen_reflective_shield") { }

        class spell_gen_reflective_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_reflective_shield_AuraScript);

            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                return sSpellStore.LookupEntry(SPELL_REFLECTIVE_SHIELD_TRIGGERED);
            }

            void Trigger(AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Unit * target = dmgInfo.GetAttacker();
                if (!target)
                    return;
                Unit * caster = GetCaster();
                if (!caster)
                    return;
                int32 bp = CalculatePctN(absorbAmount, 25);
                target->CastCustomSpell(target, SPELL_REFLECTIVE_SHIELD_TRIGGERED, &bp, NULL, NULL, true, NULL, aurEff);
            }

            void Register()
            {
                 AfterEffectAbsorb += AuraEffectAbsorbFn(spell_gen_reflective_shield_AuraScript::Trigger, EFFECT_0);
            }
        };

        AuraScript *GetAuraScript() const
        {
            return new spell_gen_reflective_shield_AuraScript();
        }
};

void AddSC_boss_argent_challenge()
{
    new boss_eadric();
    new spell_eadric_radiance();
    new boss_paletress();
    new npc_memory();
    new npc_argent_soldier();
    new spell_gen_reflective_shield();
}
