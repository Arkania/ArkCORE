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

#include "vortex_pinnacle.h"
#include "ScriptPCH.h"

enum Texts
{
    SAY_AGGRO                   = 0,   //todo: find texts + sound id
};

enum Spells
{
    SPELL_LIGHTNING_BOLT_NORMAL = 86331,
    SPELL_LIGHTNING_BOLT_HEROIC = 93990,
};

class boss_grand_vizier_ertan : public CreatureScript
{
public:
    boss_grand_vizier_ertan() : CreatureScript("boss_grand_vizier_ertan") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_grand_vizier_ertanAI (creature);
    }

    struct boss_grand_vizier_ertanAI : public ScriptedAI
    {
        boss_grand_vizier_ertanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 LightningBoltTimer;

        void Reset()
        {
            LightningBoltTimer = 7000;

            if (instance)
            {
                instance->SetData(DATA_GRAND_VIZIER_ERTAN, NOT_STARTED);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, me);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance)
            {
                Talk(SAY_AGGRO);    // lets use creature texts for that
                instance->SetData(DATA_GRAND_VIZIER_ERTAN, IN_PROGRESS);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ADD, me);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (instance)
            {
                instance->SetData(DATA_GRAND_VIZIER_ERTAN, DONE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, me);
            }

            Creature * Slipstream = me->SummonCreature(NPC_SLIPSTREAM, -775.51f, -70.93f, 640.31f, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            Slipstream->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* player = i->getSource())
                    player->ModifyCurrency(395, DUNGEON_MODE(3000, 7000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (LightningBoltTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    me->CastSpell(target, DUNGEON_MODE(SPELL_LIGHTNING_BOLT_NORMAL, SPELL_LIGHTNING_BOLT_HEROIC), true);

                LightningBoltTimer = urand(5*IN_MILLISECONDS, 7*IN_MILLISECONDS);
            } else LightningBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class spell_vizier_ertan_lurking_tempest_summon : public SpellScriptLoader
{
    public:
        spell_vizier_ertan_lurking_tempest_summon() : SpellScriptLoader("spell_vizier_ertan_lurking_tempest_summon") { }
 
        class spell_vizier_ertan_lurking_tempest_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_vizier_ertan_lurking_tempest_summon_SpellScript);
 
            void ChangeSummonPos(SpellEffIndex /*effIndex*/)
            {   
                WorldLocation* summonPos = GetTargetDest();
                Position offset = {0.0f, 0.0f, 0.0f, 0.0f+urand(0, 6)};
                Position offset2 = {0.0f, 30.0f, 0.0f, 0.0f+urand(0, 6)};
                summonPos->RelocateOffset(offset);  // Reprendre 0 les coordonées du boss
                summonPos->RelocateOffset(offset2);  // Spawn les Mobs +30 de rayon
            }
 
            void Register()
            {
                OnEffect += SpellEffectFn(spell_vizier_ertan_lurking_tempest_summon_SpellScript::ChangeSummonPos, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };
 
        SpellScript* GetSpellScript() const
        {
            return new spell_vizier_ertan_lurking_tempest_summon_SpellScript();
        }
};

void AddSC_boss_grand_vizier_ertan()
{
    new boss_grand_vizier_ertan();
	new spell_vizier_ertan_lurking_tempest_summon();
}
