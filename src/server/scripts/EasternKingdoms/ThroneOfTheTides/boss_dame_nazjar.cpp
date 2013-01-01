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
#include "throne_of_the_tides.h"

// Boss
#define SPELL_FUNGAL_SPORES 76001
#define SPELL_SHOCK_BLAST 76008
#define SPELL_SUMMON_GEYSER 75722
#define SPELL_WATERSPOUT 75683
#define SPELL_WATERSPOUT_SUMMON DUNGEON_MODE(90495,90497) // summons tornado every 7/3 secs.
#define SPELL_PLAY_MOVIE 82964 // Spell zone movie ouverture area
// Adds
#define SPELL_CHAIN_LIGHTNING 75813
#define SPELL_LIGHTNING_SURGE 75992
#define SPELL_ARC_SLASH 75907
#define SPELL_ENRAGE 75998

enum Yells
{
    SAY_AGGRO = -1643001,
    SAY_66_PRECENT = -1643002,
    SAY_33_PRECENT = -1643003,
    SAY_DEATH = -1643004,
    SAY_KILL_1 = -1643005,
    SAY_KILL_2 = -1643006,
};

enum Phases
{
    PHASE_ALL = 0,
    PHASE_NORMAL = 1,
    PHASE_WATERSPOUT = 2,
};

class boss_lady_nazjar : public CreatureScript
{
public:
    boss_lady_nazjar() : CreatureScript("boss_lady_nazjar") { }

    struct boss_lady_nazjarAI : public ScriptedAI
    {
        boss_lady_nazjarAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
            pInstance = pCreature->GetInstanceScript();
        }

        std::list<uint64> SummonList;

        InstanceScript *pInstance;

        uint8 Phase;
        bool Phased;
        uint8 SpawnCount;
        uint8 PhaseCount;

        uint32 FungalSporesTimer;
        uint32 ShockBlastTimer;
        uint32 SummonGeyserTimer;
        uint32 Phase2EndTimer;

        void Reset()
        {
            Phased = false;
            RemoveSummons();

            Phase = PHASE_NORMAL;

            SpawnCount = 3;
            PhaseCount = 0;

            FungalSporesTimer = urand(8000,13000);
            ShockBlastTimer = 22000;
            SummonGeyserTimer = urand(11000,16000);

            me->RemoveAurasDueToSpell(SPELL_WATERSPOUT);
            me->RemoveAurasDueToSpell(SPELL_WATERSPOUT_SUMMON);

            me->GetMotionMaster()->MoveTargetedHome();

            if (pInstance)
                pInstance->SetData(DATA_LADY_NAZJAR_EVENT, NOT_STARTED);
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            switch(summon->GetEntry())
            {
                case NPC_SUMMONED_WITCH:
                case NPC_SUMMONED_GUARD:
                    SpawnCount--;
                    break;
            }
        }

        void RemoveSummons()
        {
            if (SummonList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
            {
                if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                    if (pTemp)
                        pTemp->DisappearAndDie();
            }
            SummonList.clear();
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2), me);
        }

        void JustSummoned(Creature* pSummon)
        {
            switch (pSummon->GetEntry())
            {
                case NPC_SUMMONED_WITCH:
                case NPC_SUMMONED_GUARD:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        pSummon->AI()->AttackStart(pTarget);
                    SummonList.push_back(pSummon->GetGUID());
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
                pInstance->SetData(DATA_LADY_NAZJAR_EVENT, IN_PROGRESS);
        }

        void JustDied(Unit* /*pKiller*/)
        {
            DoCastAOE(SPELL_PLAY_MOVIE, true);
            me->SummonCreature(BOSS_COMMANDER_ULTHOK, 53.106316f, 802.355957f, 805.731812f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
            DoScriptText(SAY_DEATH, me);
            RemoveSummons();

            if (pInstance)
                pInstance->SetData(DATA_LADY_NAZJAR_EVENT, DONE);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (SpawnCount == 0 && Phase == PHASE_WATERSPOUT)
            {
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
                SpawnCount = 3;
                SetCombatMovement(true);
                Phase = PHASE_NORMAL;
                Phased = false;
                FungalSporesTimer = urand(8000,13000);
                ShockBlastTimer = 22000;
                SummonGeyserTimer = urand(11000,16000);
                me->RemoveAurasDueToSpell(SPELL_WATERSPOUT);
                me->RemoveAurasDueToSpell(SPELL_WATERSPOUT_SUMMON);
            }

            if (me->HealthBelowPct(67) && Phase == PHASE_NORMAL && PhaseCount == 0)
            {
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
                DoScriptText(SAY_66_PRECENT, me);

                PhaseCount++;
                SetCombatMovement(false);
                Phase = PHASE_WATERSPOUT;
                DoTeleportTo(192.056f, 802.527f, 807.638f, 3);
                DoCast(me, SPELL_WATERSPOUT);
                me->AddAura(SPELL_WATERSPOUT_SUMMON, me);
                Position pos;
                me->GetPosition(&pos);
                me->SummonCreature(NPC_SUMMONED_WITCH, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
                me->SummonCreature(NPC_SUMMONED_WITCH, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
                me->SummonCreature(NPC_SUMMONED_GUARD, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
                Phase2EndTimer = 60000;
            }

            if (me->HealthBelowPct(34) && Phase == PHASE_NORMAL && PhaseCount == 1)
            {
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
                DoScriptText(SAY_33_PRECENT, me);

                PhaseCount++;
                SetCombatMovement(false);
                Phase = PHASE_WATERSPOUT;
                DoTeleportTo(192.056f, 802.527f, 807.638f, 3);
                DoCast(me, SPELL_WATERSPOUT);
                me->AddAura(SPELL_WATERSPOUT_SUMMON, me);
                Position pos;
                me->GetPosition(&pos);
                me->SummonCreature(NPC_SUMMONED_WITCH, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
                me->SummonCreature(NPC_SUMMONED_WITCH, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
                me->SummonCreature(NPC_SUMMONED_GUARD, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
                Phase2EndTimer = 60000;
            }

            if (FungalSporesTimer <= diff && Phase == PHASE_NORMAL)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_FUNGAL_SPORES);
                FungalSporesTimer = urand(5000,7000);
            } else FungalSporesTimer -= diff;

            if (ShockBlastTimer <= diff && Phase == PHASE_NORMAL)
            {
                DoCastVictim(SPELL_SHOCK_BLAST);
                ShockBlastTimer = urand(12000,15000);
            } else ShockBlastTimer -= diff;

            if (SummonGeyserTimer <= diff && Phase == PHASE_NORMAL)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                    DoCast(target, SPELL_SUMMON_GEYSER);
                SummonGeyserTimer = urand(13000,16000);
            } else SummonGeyserTimer -= diff;

            if (Phase == PHASE_WATERSPOUT)
            {
                if (Phase2EndTimer <= diff)
                {
                    SpawnCount = 3;
                    SetCombatMovement(true);
                    Phase = PHASE_NORMAL;
                    Phased = false;
                    FungalSporesTimer = urand(8000,13000);
                    ShockBlastTimer = 22000;
                    SummonGeyserTimer = urand(11000,16000);
                    me->RemoveAurasDueToSpell(SPELL_WATERSPOUT);
                    me->RemoveAurasDueToSpell(SPELL_WATERSPOUT_SUMMON);
                } else Phase2EndTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature *pCreature) const
    {
        return new boss_lady_nazjarAI (pCreature);
    }
};

/***********************
** WaterSpout trigger
************************/
#define SPELL_GEYSER_DAMAGE 76560
#define SPELL_GEYZER_AURA 75699

class npc_waterspout_trigger : public CreatureScript
{
    public:
        npc_waterspout_trigger() : CreatureScript("npc_waterspout_trigger") { }

        struct npc_waterspout_triggerAI : public ScriptedAI
        {
            npc_waterspout_triggerAI(Creature * pCreature) : ScriptedAI(pCreature) {}

            uint32 GeyserTimer;
			
            void Reset()
            {
                GeyserTimer = 5000;
                me->AddAura(SPELL_GEYZER_AURA, me);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
				
                if (GeyserTimer <= diff)
                {
                    DoCast(SPELL_GEYSER_DAMAGE);
                    GeyserTimer = 5000;
                } else GeyserTimer -= diff;
				
                me->DespawnOrUnsummon(30000);
            }
       };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_waterspout_triggerAI(creature);
    }
};

/***********************
** WaterSpout trigger
************************/
#define MOVIE_AREA_LADY_NAZJAR 169
// id Spell 82964
class spell_lady_nazjar_play_movie : public SpellScriptLoader
{
    public:
        spell_lady_nazjar_play_movie() : SpellScriptLoader("spell_lady_nazjar_play_movie") { }

        class spell_lady_nazjar_play_movie_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_lady_nazjar_play_movie_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sMovieStore.LookupEntry(MOVIE_AREA_LADY_NAZJAR))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Player* player = GetHitPlayer())
                    player->SendMovieStart(MOVIE_AREA_LADY_NAZJAR);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_lady_nazjar_play_movie_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_lady_nazjar_play_movie_SpellScript();
        }
};

void AddSC_boss_lady_nazjar()
{
    new boss_lady_nazjar();
    new npc_waterspout_trigger();
    new spell_lady_nazjar_play_movie();
}