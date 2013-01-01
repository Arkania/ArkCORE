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
#include "the_stonecore.h"

/*********
**Corborus
**********/

enum Spells
{
    SPELL_CRYSTAL_BARRAGE            = 86881,
    SPELL_CRYSTAL_BARRAGE_H          = 92648,
    SPELL_DAMPENING_WAVE             = 82415,
    SPELL_DAMPENING_WAVE_H           = 92650,
    SPELL_BURROW                     = 26381,
};

class boss_corborus : public CreatureScript
{
public:
    boss_corborus() : CreatureScript("boss_corborus") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_corborusAI (creature);
    }

    struct boss_corborusAI : public ScriptedAI
    {
        boss_corborusAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        SummonList Summons;

        uint32 _SummonBorerTimer;
        uint32 b_BorrowTimer;
        uint32 _CrystalTimer;
        uint32 _DampeningTimer;
        bool b_BORROW;

        void Reset()
        {
            _SummonBorerTimer    = 33000;
            b_BORROW             = 0;
            _CrystalTimer        = 13600;
            _DampeningTimer      = 25000;
            Summons.DespawnAll();
        }

        void JustDied(Unit* )
        {
            Summons.DespawnAll();
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoZoneInCombat();
        }

        void SummonRockBorer()
        {
            if (!IsHeroic())
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                    for (uint8 i=0;i<2;++i)                                   //summon 2 Rock Borer Normal Mode
                me->SummonCreature(NPC_ROCK_BORER,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0.0f, TEMPSUMMON_CORPSE_DESPAWN);

            if (IsHeroic())
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                    for (uint8 i=0;i<4;++i)                                  //summon 4 Rock Borer Heroic Mode
                me->SummonCreature(NPC_ROCK_BORER,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(),0.0f, TEMPSUMMON_CORPSE_DESPAWN);
        }

        void JustSummoned(Creature* summoned)
        {
            summoned->SetInCombatWithZone();

            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                summoned->AI()->AttackStart(target);

            switch (summoned->GetEntry())
            {
                Summons.Summon(summoned);
            }
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            Summons.Despawn(summon);
        }

        void UpdateAI(const uint32 Diff)
        {
            if (!UpdateVictim())
                return;

            if (_SummonBorerTimer <= Diff)
            {
                instance->DoSendNotifyToInstance("INSTANCE MESSAGE: Rock Borer are spawned"); // Notification Spawn des adds
                b_BORROW = 1;
                DoCast(me,SPELL_BURROW);
                SummonRockBorer();
                _SummonBorerTimer = 30000;
                b_BorrowTimer = 9000;
            }
            else
            {
                _SummonBorerTimer -= Diff;
                b_BorrowTimer -= Diff;
            }
            if (b_BorrowTimer <= Diff)
                b_BORROW = 0;

            if (_CrystalTimer <= Diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    if (!IsHeroic())
                        DoCast(target,SPELL_CRYSTAL_BARRAGE);
                    else
                        DoCast(target,SPELL_CRYSTAL_BARRAGE_H);

                    _CrystalTimer = 11000;
            }
            else
                _CrystalTimer -= Diff;

            if (_DampeningTimer <= Diff)
            {
                if (!IsHeroic())
                    DoCast(SPELL_DAMPENING_WAVE);
                else
                    DoCast(SPELL_DAMPENING_WAVE_H);

                _DampeningTimer = 20000;
            }
            else
                _DampeningTimer -= Diff;

            if (b_BORROW == 0)

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_corborus()
{
    new boss_corborus();
}