/*
 * Copyright (C) 2008 - 2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss Volkhan
SD%Complete: 90%
SDComment: Event should be pretty close minus a few visual flaws
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptPCH.h"
#include "halls_of_lightning.h"

enum eEnums
{
    SAY_AGGRO                               = -1602032,
    SAY_SLAY_1                              = -1602033,
    SAY_SLAY_2                              = -1602034,
    SAY_SLAY_3                              = -1602035,
    SAY_DEATH                               = -1602036,
    SAY_STOMP_1                             = -1602037,
    SAY_STOMP_2                             = -1602038,
    SAY_FORGE_1                             = -1602039,
    SAY_FORGE_2                             = -1602040,
    EMOTE_TO_ANVIL                          = -1602041,
    EMOTE_SHATTER                           = -1602042,

    SPELL_HEAT_N                            = 52387,
    SPELL_HEAT_H                            = 59528,
    SPELL_SHATTERING_STOMP_N                = 52237,
    SPELL_SHATTERING_STOMP_H                = 59529,

    //unclear how "directions" of spells must be. Last, summoning GO, what is it for? Script depend on:
    SPELL_TEMPER                            = 52238,        //TARGET_SCRIPT boss->anvil
    SPELL_TEMPER_DUMMY                      = 52654,        //TARGET_SCRIPT anvil->boss

    //SPELL_TEMPER_VISUAL                     = 52661,        //summons GO

    SPELL_SUMMON_MOLTEN_GOLEM               = 52405,

    // Molten Golem
    SPELL_BLAST_WAVE                        = 23113,
    SPELL_IMMOLATION_STRIKE_N               = 52433,
    SPELL_IMMOLATION_STRIKE_H               = 59530,
    SPELL_SHATTER_N                         = 52429,
    SPELL_SHATTER_H                         = 59527,

    NPC_MOLTEN_GOLEM                        = 28695,
    NPC_BRITTLE_GOLEM                       = 28681,

    POINT_ID_ANVIL                          = 0,
    MAX_GOLEM                               = 2,

    ACHIEVEMENT_SHATTER_RESISTANT            = 2042
};

/*######
## Boss Volkhan
######*/

class boss_volkhan : public CreatureScript
{
public:
    boss_volkhan() : CreatureScript("boss_volkhan") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_volkhanAI(creature);
    }

    struct boss_volkhanAI : public ScriptedAI
    {
        boss_volkhanAI(Creature* creature) : ScriptedAI(creature)
        {
            m_pInstance = creature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        std::list<uint64> m_lGolemGUIDList;

        bool m_bHasTemper;
        bool m_bIsStriking;
        bool m_bCanShatterGolem;
        bool m_bMove;

        uint8 GolemsShattered;
        uint32 m_uiPause_Timer;
        uint32 m_uiShatteringStomp_Timer;
        uint32 m_uiShatter_Timer;
        uint32 m_uiCheckTimer;
        uint32 m_uiCheckZ;

        uint32 m_uiHealthAmountModifier;

        void Reset()
        {
            m_bIsStriking = false;
            m_bHasTemper = false;
            m_bCanShatterGolem = false;
            m_bMove = false;

            m_uiPause_Timer = 1500;
            m_uiShatteringStomp_Timer = 30000;
            m_uiShatter_Timer = 3000;
            m_uiCheckTimer = 1100;
            m_uiCheckZ = 1000;
            GolemsShattered = 0;

            m_uiHealthAmountModifier = 1;

            DespawnGolem();

            me->SetReactState(REACT_AGGRESSIVE);
            if (!me->HasUnitMovementFlag(MOVEMENTFLAG_WALKING))
                me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);

            if (m_pInstance)
                m_pInstance->SetData(TYPE_VOLKHAN, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (m_pInstance)
                m_pInstance->SetData(TYPE_VOLKHAN, IN_PROGRESS);
        }

        void AttackStart(Unit* who)
        {
            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);

                if (!m_bHasTemper)
                    me->GetMotionMaster()->MoveChase(who);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            DespawnGolem();

            if (m_pInstance)
                m_pInstance->SetData(TYPE_VOLKHAN, DONE);

            if (IsHeroic() && GolemsShattered < 5)
            {
                AchievementEntry const* AchievShatterResistant = GetAchievementStore()->LookupEntry(ACHIEVEMENT_SHATTER_RESISTANT);
                if (AchievShatterResistant)
                {
                    Map* pMap = me->GetMap();
                    if (pMap && pMap->IsDungeon())
                    {
                        Map::PlayerList const &players = pMap->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            itr->getSource()->CompletedAchievement(AchievShatterResistant);
                    }
                }
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }

        void DespawnGolem()
        {
            if (m_lGolemGUIDList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = m_lGolemGUIDList.begin(); itr != m_lGolemGUIDList.end(); ++itr)
            {
                if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                {
                    if (pTemp->isAlive())
                        pTemp->DespawnOrUnsummon();
                }
            }

            m_lGolemGUIDList.clear();
        }

        void ShatterGolem()
        {
            if (m_lGolemGUIDList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = m_lGolemGUIDList.begin(); itr != m_lGolemGUIDList.end(); ++itr)
            {
                if (Creature* pTemp = Unit::GetCreature(*me, *itr))
                {
                    // Only shatter brittle golems
                    if (pTemp->isAlive() && pTemp->GetEntry() == NPC_BRITTLE_GOLEM)
                    {
                        pTemp->CastSpell(pTemp, DUNGEON_MODE(SPELL_SHATTER_N, SPELL_SHATTER_H), false);
                        GolemsShattered++;
                    }
                }
            }
        }

        void JustSummoned(Creature* pSummoned)
        {
            if (pSummoned->GetEntry() == NPC_MOLTEN_GOLEM)
            {
                m_lGolemGUIDList.push_back(pSummoned->GetGUID());

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    pSummoned->AI()->AttackStart(target);

                //useless at this position
                pSummoned->CastSpell(pSummoned, DUNGEON_MODE(SPELL_HEAT_N, SPELL_HEAT_H), false, NULL, NULL, me->GetGUID());
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //exploit fix, remove later
            if (m_uiCheckZ <= uiDiff)
            {
                if (me->GetPositionZ() < 50.0f)
                {
                    EnterEvadeMode();
                    return;
                }
                m_uiCheckZ = 1000;
            }
            else m_uiCheckZ -= uiDiff;

            if (m_bIsStriking && !m_bMove)
            {
                if (m_uiPause_Timer <= uiDiff)
                {
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                    {
                        if (me->getVictim())
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                    }

                    m_bHasTemper = false;
                    m_bIsStriking = false;
                    m_uiPause_Timer = 1500;
                }
                else
                    m_uiPause_Timer -= uiDiff;

                return;
            }

            // ShatteringStomp all the Time,
            if (!m_bHasTemper && !m_bMove)
            {
                if (m_uiShatteringStomp_Timer <= uiDiff)
                {
                    DoScriptText(RAND(SAY_STOMP_1,SAY_STOMP_2), me);

                    DoCast(me, DUNGEON_MODE(SPELL_SHATTERING_STOMP_N,SPELL_SHATTERING_STOMP_H));

                    if (Creature* temp = me->FindNearestCreature(NPC_BRITTLE_GOLEM,99))
                    {
                    DoScriptText(EMOTE_SHATTER, me);
                    m_bCanShatterGolem = true;
                }

                    m_uiShatteringStomp_Timer = 30000;
                }
                else
                    m_uiShatteringStomp_Timer -= uiDiff;
            }

            // Shatter Golems 3 seconds after Shattering Stomp
            if (m_bCanShatterGolem)
            {
                if (m_uiShatter_Timer <= uiDiff)
                {
                    ShatterGolem();
                    m_uiShatter_Timer = 3000;
                    m_bCanShatterGolem = false;
                }
                else
                    m_uiShatter_Timer -= uiDiff;
            }

            Creature* pAnvil = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_VOLKHAN_ANVIL));

            float fX, fY, fZ;
            me->GetContactPoint(pAnvil, fX, fY, fZ, INTERACTION_DISTANCE);

            // Health check
            if (!m_bCanShatterGolem && me->HealthBelowPct(100 - 20 * m_uiHealthAmountModifier) && !m_bMove)
            {
                ++m_uiHealthAmountModifier;

                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);

                DoScriptText(RAND(SAY_FORGE_1, SAY_FORGE_2), me);

                if (me->GetDistance(pAnvil) > 5)
                {
                    me->GetMotionMaster()->Clear();
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(5,fX,fY,fZ);
            }

                    DoScriptText(EMOTE_TO_ANVIL, me);
                m_bMove=true;
                    }

            if (me->IsWithinMeleeRange(pAnvil,5) && m_bMove)
            {
                me->GetMotionMaster()->Clear();
                            me->SetReactState(REACT_AGGRESSIVE);
                m_bHasTemper = true;
                m_bMove=false;
                        for (uint8 i = 0; i < MAX_GOLEM; ++i)
                {
                    DoCast(SPELL_SUMMON_MOLTEN_GOLEM);
                }
                DoCast(SPELL_TEMPER);
                    m_bIsStriking = true;
            }

            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType()!=POINT_MOTION_TYPE && m_bMove)
                //if (m_uiCheckTimer<=uiDiff)
                {
                    me->GetMotionMaster()->MovePoint(5,fX,fY,fZ);
                    m_uiCheckTimer=1100;
                }
                //else
                    //m_uiCheckTimer-=uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

/*######
## mob_molten_golem
######*/

class mob_molten_golem : public CreatureScript
{
public:
    mob_molten_golem() : CreatureScript("mob_molten_golem") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_molten_golemAI(creature);
    }

    struct mob_molten_golemAI : public ScriptedAI
    {
        mob_molten_golemAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        bool m_bIsFrozen;

        uint32 m_uiBlast_Timer;
        uint32 m_uiDeathDelay_Timer;
        uint32 m_uiImmolation_Timer;

        void Reset()
        {
            m_bIsFrozen = false;

            m_uiBlast_Timer = 20000;
            m_uiDeathDelay_Timer = 0;
            m_uiImmolation_Timer = 5000;
        }

        void AttackStart(Unit* who)
        {
            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);

                if (!m_bIsFrozen)
                    me->GetMotionMaster()->MoveChase(who);
            }
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
        {
            if (uiDamage > me->GetHealth())
            {
                me->UpdateEntry(NPC_BRITTLE_GOLEM);
                me->SetHealth(1);
                uiDamage = 0;
                me->RemoveAllAuras();
                me->AttackStop();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);
                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == TARGETED_MOTION_TYPE)
                    me->GetMotionMaster()->MovementExpired();
                m_bIsFrozen = true;
            }
        }

        void SpellHit(Unit* /*pCaster*/, const SpellEntry* pSpell)
        {
            // This is the dummy effect of the spells
            if (pSpell->Id == SPELL_SHATTER_N || pSpell->Id == SPELL_SHATTER_H)
            {
                if (me->GetEntry() == NPC_BRITTLE_GOLEM)
                    me->DespawnOrUnsummon();
        }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            // Return since we have no target or if we are frozen
            if (!UpdateVictim() || m_bIsFrozen)
                return;

            if (m_uiBlast_Timer <= uiDiff)
            {
                DoCast(me, SPELL_BLAST_WAVE);
                m_uiBlast_Timer = 20000;
            }
            else
                m_uiBlast_Timer -= uiDiff;

            if (m_uiImmolation_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_IMMOLATION_STRIKE_N);
                m_uiImmolation_Timer = 5000;
            }
            else
                m_uiImmolation_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_volkhan()
{
    new boss_volkhan();
    new mob_molten_golem();
}
