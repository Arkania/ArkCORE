/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2012 ArkCORE <http://www.arkania.net/>
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
#include "violet_hold.h"

enum Spells
{
  SPELL_CAUTERIZING_FLAMES                      = 59466, //Only in heroic
  SPELL_FIREBOLT                                = 54235,
  H_SPELL_FIREBOLT                              = 59468,
  SPELL_FLAME_BREATH                            = 54282,
  H_SPELL_FLAME_BREATH                          = 59469,
  SPELL_LAVA_BURN                               = 54249,
  H_SPELL_LAVA_BURN                             = 59594
};

class boss_lavanthor : public CreatureScript
{
public:
    boss_lavanthor() : CreatureScript("boss_lavanthor") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lavanthorAI (creature);
    }

    struct boss_lavanthorAI : public ScriptedAI
    {
        boss_lavanthorAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiFireboltTimer;
        uint32 uiFlameBreathTimer;
        uint32 uiLavaBurnTimer;
        uint32 uiCauterizingFlamesTimer;

        InstanceScript* instance;

        void Reset()
        {
            uiFireboltTimer = 1000;
            uiFlameBreathTimer = 5000;
            uiLavaBurnTimer = 10000;
            uiCauterizingFlamesTimer = 3000;
            if (instance)
            {
                if (instance->GetData(DATA_WAVE_COUNT) == 6)
                    instance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
                else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                    instance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance)
            {
            if (GameObject* pDoor = instance->instance->GetGameObject(instance->GetData64(DATA_LAVANTHOR_CELL)))
                    if (pDoor->GetGoState() == GO_STATE_READY)
                    {
                        EnterEvadeMode();
                        return;
                    }
                if (instance->GetData(DATA_WAVE_COUNT) == 6)
                    instance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
                else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                    instance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
            }
        }

        void AttackStart(Unit* who)
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void MoveInLineOfSight(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiFlameBreathTimer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
            {
                DoCast(me->getVictim(), SPELL_FLAME_BREATH);
                uiFlameBreathTimer = urand(10000,15000);
                }
            } else uiFlameBreathTimer -= diff;

            if (uiLavaBurnTimer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me->getVictim(), DUNGEON_MODE(SPELL_LAVA_BURN, H_SPELL_LAVA_BURN));
                    uiLavaBurnTimer = urand(10000,20000);
                }
            }

            if (IsHeroic())
            {
                if (uiCauterizingFlamesTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_CAUTERIZING_FLAMES);
                    uiCauterizingFlamesTimer = urand(10000, 16000);
                } else uiCauterizingFlamesTimer -= diff;
            }

            if (uiFireboltTimer <= diff)
            {
                if(!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me->getVictim(), DUNGEON_MODE(SPELL_FIREBOLT, H_SPELL_FIREBOLT));
                    uiFireboltTimer = urand(5000,13000);
                }
            } else uiFireboltTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                if (instance->GetData(DATA_WAVE_COUNT) == 6)
                {
                    if(IsHeroic() && instance->GetData(DATA_1ST_BOSS_EVENT) == DONE)
                        me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);

                    instance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                    instance->SetData(DATA_WAVE_COUNT, 7);
                }
                else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                {
                    if(IsHeroic() && instance->GetData(DATA_2ND_BOSS_EVENT) == DONE)
                        me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);

                    instance->SetData(DATA_2ND_BOSS_EVENT, DONE);
                    instance->SetData(DATA_WAVE_COUNT, 13);
                }
            }
        }
    };
};

void AddSC_boss_lavanthor()
{
    new boss_lavanthor();
}
