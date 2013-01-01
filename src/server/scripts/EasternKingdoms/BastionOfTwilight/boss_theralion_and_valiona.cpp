/*
 * Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
 *
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2011 - 2013 ArkCORE <http://www.arkania.net/>
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

#include "bastion_of_twilight.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ScriptPCH.h"

#define MAX_DAZZLIN_DESTRUCTION 6

class boss_theralion: public CreatureScript
{
public:
    boss_theralion () :
            CreatureScript("boss_theralion")
    {
    }

    struct boss_theralionAI: public BossAI
    {
        boss_theralionAI (Creature * creature) :
                BossAI(creature, DATA_THERALION), summons(me)
        {
            pInstance = (InstanceScript*) creature->GetInstanceScript();
        }

        void Reset ()
        {
            uiPhase = 0;
            uiPhaseTimer = 900000;
            uiEngulfingMagicCount = 0;
            uiEngulfingMagicTimer = 180000;
            uiFabulousFlamesTimer = 160000;
            uiTwilightBlastTimer = 3000;
            uiDazzlingDestructionTimer = 2000;
        }

        void SetData (uint32 id, uint32 value)
        {
            switch (id)
            {
            case DATA_PHASE:
                uiPhase = value;
            }
        }

        uint32 GeData (uint32 id)
        {
            switch (id)
            {
            case DATA_PHASE:
                return uiPhase;
            case DATA_ENGULFING_COUNT:
                return uiEngulfingMagicCount;
            }
        }

        Creature * GetValiona ()
        {
            return me->GetCreature(*me, pInstance->GetData64(DATA_VALIONA));
        }

        void JustSummoned (Creature * creature)
        {
            if (creature->GetEntry() == NPC_THERALION_FLIGHT_TARGET_STALKER)
            {
                DoCast(creature, SPELL_TWILIGHT_BLAST);
            }
        }

        void AttackStart ()
        {
            uiPhase = 1;
        }

        void DoAction (const uint32 action)
        {
            switch (action)
            {
            case ACTION_THERALION_AIRBORNE:
                me->GetMotionMaster()->MoveTakeoff(POINT_THERALION_TAKEOFF, Positions[0], 1.0f);
                break;
            }
        }

        void MovementInform (uint32 type, uint32 id)
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                case POINT_THERALION_TAKEOFF:
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveIdle();
                    //case POINT_THERALION_LAND:
                }
            }
        }

        void UpdateAI (const uint32 uiDiff)
        {
            Creature * Valiona = GetValiona();

            if (!UpdateVictim())
                return;

            if (uiPhaseTimer <= uiDiff)
            {
                uiPhaseTimer = 900000;
                switch (uiPhase)
                {
                case 1:
                    uiPhase = 2;
                    Valiona->AI()->DoAction(ACTION_VALIONA_AIRBORNE);
                    Valiona->SetHealth(me->GetHealth());
                    break;
                case 3:
                    uiPhase = 1;
                    me->SetHealth(Valiona->GetHealth());
                    break;
                }
            }
            else
                uiPhaseTimer -= uiDiff;

            switch (uiPhase)
            {
            case 1:
                if (uiEngulfingMagicTimer <= uiDiff && uiEngulfingMagicTimer <= 2)
                {
                    uiEngulfingMagicTimer = 180000;
                    uiEngulfingMagicCount++;
                    Unit * Target = SelectTarget(SELECT_TARGET_RANDOM);
                    DoCast(Target, SPELL_ENGULFING_MAGIC);
                }
                else
                    uiEngulfingMagicTimer -= uiDiff;
                if (uiFabulousFlamesTimer <= uiDiff)
                {
                    DoCast(SPELL_FABILOUS_FLAMES);
                }
                else
                    uiFabulousFlamesTimer -= uiDiff;
                DoMeleeAttackIfReady();
            case 2:
                if (uiDazzlingDestructionTimer <= uiDiff && uiDazzlingDestructionCount <= MAX_DAZZLIN_DESTRUCTION)
                {
                    Unit * Target = SelectTarget(SELECT_TARGET_RANDOM);
                    me->CastSpell(Target->GetPositionX(), Target->GetPositionY(), Target->GetPositionZ(), SPELL_DAZZLING_DESTRUCTION_SUMMON, false);
                    uiDazzlingDestructionTimer = 2000;
                    uiDazzlingDestructionCount++;
                }
                else
                    uiDazzlingDestructionTimer -= uiDiff;
                if (uiDazzlingDestructionCount == MAX_DAZZLIN_DESTRUCTION)
                {
                    std::list<uint64>::iterator itr;
                    for (itr = summons.begin(); itr != summons.end(); ++itr)
                    {
                        if (Creature * Destruction = ObjectAccessor::GetCreature(*me, *itr))
                            DoCast(Destruction, SPELL_DAZZLING_DESTRUCTION_MISSILE);
                    }
                }
            case 3:
                if (uiTwilightBlastTimer <= uiDiff)
                {
                    uiTwilightBlastTimer = 3000;
                    me->SummonCreature(NPC_THERALION_FLIGHT_TARGET_STALKER, me->getVictim()->GetPositionX(), me->getVictim()->GetPositionY(), me->getVictim()->GetPositionZ(), 0.0f, TEMPSUMMON_MANUAL_DESPAWN);
                }
                else
                    uiTwilightBlastTimer -= uiDiff;
            }
        }
    private:
        InstanceScript* pInstance;
        SummonList summons;

        uint8 uiEngulfingMagicCount;
        uint8 uiDazzlingDestructionCount;
        uint32 uiBerserkTimer;
        uint32 uiPhase;
        uint32 uiPhaseTimer;
        uint32 uiEngulfingMagicTimer;
        uint32 uiFabulousFlamesTimer;
        uint32 uiTwilightBlastTimer;
        uint32 uiDazzlingDestructionTimer;
    };

    CreatureAI* GetAI (Creature* creature) const
    {
        return new boss_theralionAI(creature);
    }
};
class boss_valiona: public CreatureScript
{
public:
    boss_valiona () :
            CreatureScript("boss_valiona")
    {
    }

    struct boss_valionaAI: public BossAI
    {
        boss_valionaAI (Creature * creature) :
                BossAI(creature, DATA_VALIONA)
        {
            pInstance = (InstanceScript*) creature->GetInstanceScript();
        }

        void Reset ()
        {
            uiTheralionPhase = 0;
            uiBlackoutCount = 0;
            uiBlackoutTimer = 122000;
            uiDevouringFlamesTimer = 132000;
            uiTwilightMeteoriteTimer = 40000;
        }

        Creature * GetTheralion ()
        {
            return me->GetCreature(*me, pInstance->GetData64(DATA_THERALION));
        }

        void AttackStart ()
        {
            Creature * tmp = GetTheralion();
            tmp->AI()->SetData(DATA_PHASE, 2);
        }

        void DoAction (const uint32 action)
        {
            switch (action)
            {
            case ACTION_VALIONA_AIRBORNE:
                me->GetMotionMaster()->MovePoint(POINT_VALIONA_TAKEOFF, Positions[0]);
                break;
            }
        }

        void MovementInform (uint32 type, uint32 id)
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                case POINT_VALIONA_TAKEOFF:
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveIdle();
                }
            }
        }

        void UpdateAI (const uint32 uiDiff)
        {
            Creature * pTheralion = GetTheralion();
            uiTheralionPhase = pTheralion->AI()->GetData(DATA_PHASE);
            switch (uiTheralionPhase)
            {
            case 2:
                if (!UpdateVictim())
                    return;

                if (uiBlackoutTimer <= uiDiff && uiBlackoutCount <= 2)
                {
                    uiBlackoutTimer = 122000;
                    uiBlackoutCount++;
                    DoCastAOE(SPELL_BLACKOUT);
                }
                else
                    uiBlackoutTimer -= uiDiff;
                if (uiDevouringFlamesTimer <= uiDiff)
                {
                    uiDevouringFlamesTimer = 132000;
                    DoCastAOE(SPELL_DEVOURING_FLAMES);
                }
                else
                    uiDevouringFlamesTimer -= uiDiff;
                DoMeleeAttackIfReady();
            case 1:
                if (pTheralion->AI()->GetData(DATA_ENGULFING_COUNT) == 2)
                {
                    DoCast(SPELL_DEEP_BREATH);
                }
                if (uiTwilightMeteoriteTimer <= uiDiff)
                {
                    uiTwilightMeteoriteTimer = 40000;
                    Unit * Target = SelectTarget(SELECT_TARGET_RANDOM, 500.0f);
                    DoCast(Target, SPELL_TWILIGHT_METEORITE);
                }
                else
                    uiTwilightMeteoriteTimer -= uiDiff;
            }
        }

    private:
        InstanceScript* pInstance;
        uint8 uiBlackoutCount;
        uint32 uiTheralionPhase;
        uint32 uiBlackoutTimer;
        uint32 uiDevouringFlamesTimer;
        uint32 uiTwilightMeteoriteTimer;
    };

    CreatureAI * GetAI (Creature * creature) const
    {
        return new boss_valionaAI(creature);
    }
};
class spell_dazzling_destruction: public SpellScriptLoader
{
public:
    spell_dazzling_destruction () :
            SpellScriptLoader("spell_dazzling_destruction")
    {
    }

    class spell_dazzling_destructionSpellScript: public SpellScript
    {
        int32 spell_trigger;PrepareSpellScript(spell_dazzling_destructionSpellScript)
        ;
        bool Validate (SpellEntry const * spellEntry)
        {
            if (!sSpellStore.LookupEntry(spellEntry->Id))
                return false;
            return true;
        }

        bool Load ()
        {
            spell_trigger = GetSpellInfo()->EffectBasePoints[0];
            return true;
        }

        void HandleDummy (SpellEffIndex effIndex)
        {
            GetCaster()->CastSpell(GetTargetUnit(), spell_trigger, false);
        }

        void HandleOnHit ()
        {
            std::list<Unit*> players;
            std::list<Unit*>::const_iterator itr;
            GetTargetUnit()->GetRaidMember(players, 5.0f);
            for (itr = players.begin(); itr != players.end(); ++itr)
            {
                if ((*itr)->GetTypeId() == TYPEID_PLAYER)
                {
                    GetCaster()->CastSpell((*itr), SPELL_DESTRUCTION_PROCS, false);
                }
            }
        }

        void Register ()
        {
            OnEffectHitTarget += SpellEffectFn(spell_dazzling_destructionSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnHit += SpellHitFn(spell_dazzling_destructionSpellScript::HandleOnHit);
        }
    };

    SpellScript * GetSpellScript () const
    {
        return new spell_dazzling_destructionSpellScript();
    }
};

void AddSC_boss_theralion ()
{
    new boss_theralion();
    new boss_valiona();
    new spell_dazzling_destruction();
}
