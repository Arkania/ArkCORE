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
SDName: Boss Black Knight
SD%Complete: 80%
SDComment: not sure about timers.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "trial_of_the_champion.h"
#include "Vehicle.h"

#define NPC_BLACK_KNIGHT 35451

enum eEnums
{
    //Yell
    SAY_DEATH_3                             = -1999935,
    SAY_AGGRO                               = -1999929,
    SAY_AGGRO_2                             = -1999930,
    SAY_SLAY                                = -1999932,
    SAY_DEATH_1                             = -1999933,
    SAY_DEATH                               = -1999934,
    SAY_START5                              = -1999936,
    SAY_START6                              = -1999937,
    SAY_START7                              = -1999928,
    SAY_START8                              = -1999929,
    SAY_START9                              = -1999952,
    SAY_START10                             = -1999932,
    SAY_START11                             = -1999953,
    SAY_KILL                                = -1999969,
    SAY_KILL1                               = -1999970
};
enum eSpells
{
    //phase 1
    SPELL_PLAGUE_STRIKE     = 67724,
    SPELL_PLAGUE_STRIKE_H   = 67884,
    SPELL_ICY_TOUCH_H       = 67881,
    SPELL_ICY_TOUCH         = 67718,
    SPELL_DEATH_RESPITE     = 67745,
    SPELL_DEATH_RESPITE_H   = 68306,
    SPELL_OBLITERATE_H      = 67883,
    SPELL_OBLITERATE        = 67725,
    //in this phase should rise herald (the spell is missing)

    //phase 2 - During this phase, the Black Knight will use the same abilities as in phase 1, except for Death's Respite
    SPELL_ARMY_DEAD         = 67761,
    SPELL_ARMY_DEAD_H       = 67874,
    SPELL_DESECRATION       = 67778,
    SPELL_DESECRATION_H     = 67877,
    SPELL_GHOUL_EXPLODE     = 67751,

    //phase 3
    SPELL_DEATH_BITE_H      = 67875,
    SPELL_DEATH_BITE        = 67808,
    SPELL_MARKED_DEATH      = 67882,
    SPELL_MARKED_DEATH_H    = 67823,

    SPELL_BLACK_KNIGHT_RES  = 67693,

    SPELL_LEAP                = 67749,
    SPELL_LEAP_H            = 67880
};

enum eModels
{
    MODEL_SKELETON = 29846,
    MODEL_GHOST    = 21300
};

enum eEqip
{
     EQUIP_SWORD                    = 40343
};

enum IntroPhase
{
    IDLE,
    INTRO,
    FINISHED
};

enum ePhases
{
    PHASE_UNDEAD    = 1,
    PHASE_SKELETON  = 2,
    PHASE_GHOST     = 3
};

enum Misc
{
    ACHIEV_WORSE                                  = 3804,
    ACHIEV_HEROIC_DONE_H                          = 4297,
    ACHIEV_HEROIC_DONE_A                          = 4298,
    ACHIEV_NORMAL_DONE_H                          = 4296,
    ACHIEV_NORMAL_DONE_A                          = 3778
};

class boss_black_knight : public CreatureScript
{
public:
    boss_black_knight() : CreatureScript("boss_black_knight") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_black_knightAI (creature);
    }

    struct boss_black_knightAI : public ScriptedAI
    {
        boss_black_knightAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        std::list<uint64> SummonList;

        bool bEventInProgress;
        bool bEvent;
        bool bSummonArmy;
        bool bDeathArmyDone;
        bool bEventInBattle;
        bool bFight;

        uint8 uiPhase;
        uint8 uiIntroPhase;

        IntroPhase Phase;

        uint32 uiIntroTimer;
        uint32 uiPlagueStrikeTimer;
        uint32 uiPlagueStrike1Timer;
        uint32 uiIcyTouchTimer;
        uint32 uiIcyTouch1Timer;
        uint32 uiDeathRespiteTimer;
        uint32 uiObliterateTimer;
        uint32 uiObliterate1Timer;
        uint32 uiDesecrationTimer;
        uint32 uiDesecration1Timer;
        uint32 uiResurrectTimer;
        uint32 uiDeathArmyCheckTimer;
        uint32 uiGhoulExplodeTimer;
        uint32 uiDeathBiteTimer;
        uint32 uiMarkedDeathTimer;

        void Reset()
        {
            RemoveSummons();
            me->SetDisplayId(me->GetNativeDisplayId());
            me->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
	        me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);

            bEventInProgress = false;
            bEvent = false;
            bSummonArmy = false;
            bDeathArmyDone = false;
            bFight = false;

            if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
            pInstance->HandleGameObject(pGO->GetGUID(),true);
            if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
            pInstance->HandleGameObject(pGO->GetGUID(),false);

            if (bEventInBattle)
            {
                me->GetMotionMaster()->MovePoint(1,743.396f, 635.411f, 411.575f);
                me->setFaction(14);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
            }

            uiPhase = PHASE_UNDEAD;

            uiIcyTouchTimer = urand(5000,9000);
            uiIcyTouch1Timer = urand(15000,15000);
            uiPlagueStrikeTimer = urand(10000,13000);
            uiPlagueStrike1Timer = urand(14000,14000);
            uiDeathRespiteTimer = urand(15000,16000);
            uiObliterateTimer = urand(17000,19000);
            uiObliterate1Timer = urand(15000,15000);
            uiDesecrationTimer = urand(15000,16000);
            uiDesecration1Timer = urand(22000,22000);
            uiDeathArmyCheckTimer = 7000;
            uiResurrectTimer = 4000;
            uiGhoulExplodeTimer = 8000;
            uiDeathBiteTimer = urand (2000,4000);
            uiMarkedDeathTimer = urand (5000,7000);
            uiIntroTimer = 5000;
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

        void JustSummoned(Creature* summon)
        {
            SummonList.push_back(summon->GetGUID());
            summon->AI()->AttackStart(me->getVictim());
        }

        void UpdateAI(const uint32 uiDiff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (bEventInProgress)
            {
                if (uiResurrectTimer <= uiDiff)
                {
                        me->SetHealth(me->GetMaxHealth());
                        me->AttackStop();
                        switch(uiPhase)
                        {
                            case PHASE_UNDEAD:
                                DoScriptText(SAY_DEATH_1, me);
                                break;
                            case PHASE_SKELETON:
                                DoScriptText(SAY_DEATH, me);
                                break;
                        }
                    DoCast(me,SPELL_BLACK_KNIGHT_RES,true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                    uiPhase++;
                    uiResurrectTimer = 4000;
                    bEventInProgress = false;
                    me->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                } else uiResurrectTimer -= uiDiff;
            }

            switch(uiPhase)
            {
                case PHASE_UNDEAD:
                case PHASE_SKELETON:
                {
                    if (uiIcyTouchTimer <= uiDiff)
                    {
                        if (IsHeroic())
                            DoCastVictim(SPELL_ICY_TOUCH_H);
                        else
                            DoCastVictim(SPELL_ICY_TOUCH);
                        uiIcyTouchTimer = urand(5000,7000);
                    } else uiIcyTouchTimer -= uiDiff;
                    if (uiPlagueStrikeTimer <= uiDiff)
                    {
                        if (IsHeroic())
                            DoCastVictim(SPELL_PLAGUE_STRIKE);
                        else
                            DoCastVictim(SPELL_PLAGUE_STRIKE_H);
                        uiPlagueStrikeTimer = urand(12000,15000);
                    } else uiPlagueStrikeTimer -= uiDiff;

                    if (uiObliterateTimer <= uiDiff)
                    {
                        if (IsHeroic())
                            DoCastVictim(SPELL_OBLITERATE_H);
                        else
                            DoCastVictim(SPELL_OBLITERATE);
                        uiObliterateTimer = urand(17000,19000);
                    } else uiObliterateTimer -= uiDiff;
                    switch(uiPhase)
                    {
                        case PHASE_UNDEAD:
                        {
                            if (uiDeathRespiteTimer <= uiDiff)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                {
                                    if (target && target->isAlive())
                                    {
                                        if (IsHeroic())
                                            DoCast(target,SPELL_DEATH_RESPITE_H);
                                        else
                                            DoCast(target,SPELL_DEATH_RESPITE);
                                    }
                                }
                                uiDeathRespiteTimer = urand(15000,16000);
                            } else uiDeathRespiteTimer -= uiDiff;
                        break;
                    }
                        case PHASE_SKELETON:
                    {
                        if (!bSummonArmy)
                        {
                            bSummonArmy = true;
                            me->AddUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                            if (IsHeroic())
                                DoCast(me, SPELL_ARMY_DEAD_H);
                            else
                            DoCast(me, SPELL_ARMY_DEAD);
                        }

                        if (!bDeathArmyDone)
                            {
                            if (uiDeathArmyCheckTimer <= uiDiff)
                            {
                                me->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                                me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                                uiDeathArmyCheckTimer = 0;
                                bDeathArmyDone = true;
                            } else uiDeathArmyCheckTimer -= uiDiff;
                            }
                        if (uiDesecration1Timer <= uiDiff)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            {
                                if (target && target->isAlive())
                                    {
                                        if (IsHeroic())
                                            DoCast(target,SPELL_DESECRATION_H);
                                        else
                                            DoCast(target,SPELL_DESECRATION);
                                    }
                            }
                            uiDesecration1Timer = urand(15000,16000);
                        } else uiDesecration1Timer -= uiDiff;

                        if (uiGhoulExplodeTimer <= uiDiff)
                        {
                            DoCast(me, SPELL_GHOUL_EXPLODE);
                            uiGhoulExplodeTimer = 8000;
                        } else uiGhoulExplodeTimer -= uiDiff;
                            break;
                        }
                            break;
                    }
                    break;
                }
                case PHASE_GHOST:
                {
                    if (uiDeathBiteTimer <= uiDiff)
                    {
                            SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
                        if (IsHeroic())
                            DoCastAOE(SPELL_DEATH_BITE);
                        else
                            DoCastAOE(SPELL_DEATH_BITE_H);
                        uiDeathBiteTimer = urand (2000, 4000);
                    } else uiDeathBiteTimer -= uiDiff;

                    if (uiMarkedDeathTimer <= uiDiff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            if (target && target->isAlive())
                            {
                                if (IsHeroic())
                                    DoCast(target,SPELL_MARKED_DEATH);
                                else
                                    DoCast(target,SPELL_MARKED_DEATH_H);
                            }
                        }
                        uiMarkedDeathTimer = urand (5000, 7000);
                    } else uiMarkedDeathTimer -= uiDiff;
                    break;
                }
            }

                if (!me->HasUnitState(UNIT_STAT_ROOT) && !me->GetHealth()*100 / me->GetMaxHealth() <= 0)
                DoMeleeAttackIfReady();
        }

        void EnterCombat(Unit* who)
        {
            bEventInBattle = true;
            DoScriptText(SAY_AGGRO_2, me);
            SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
            pInstance->HandleGameObject(pGO->GetGUID(),false);
            if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
            pInstance->HandleGameObject(pGO->GetGUID(),false);
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32& uiDamage)
        {
            if (uiDamage > me->GetHealth() && uiPhase <= PHASE_SKELETON)
            {
                uiDamage = 0;
                me->SetHealth(0);
                me->AddUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                RemoveSummons();
                switch(uiPhase)
                {
                    case PHASE_UNDEAD:
                        me->SetDisplayId(MODEL_SKELETON);
                        break;
                    case PHASE_SKELETON:
                        me->SetDisplayId(MODEL_GHOST);
                        break;
                }
                bEventInProgress = true;
            }
        }

        void KilledUnit(Unit* victim)
        {
            DoScriptText(urand(0, 1) ? SAY_KILL : SAY_KILL1, me);
            if (pInstance)
                pInstance->SetData(BOSS_BLACK_KNIGHT,IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH_3, me);
            if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                        pInstance->HandleGameObject(pGO->GetGUID(),true);

            if (pInstance)
            {
                pInstance->SetData(BOSS_BLACK_KNIGHT,DONE);

                if (IsHeroic())
                {
                pInstance->DoCompleteAchievement(ACHIEV_WORSE);
                    if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_ALLIANCE)
                    {
                        pInstance->DoCompleteAchievement(ACHIEV_HEROIC_DONE_A);
                    }else
                    {
                        pInstance->DoCompleteAchievement(ACHIEV_HEROIC_DONE_H);
                    }
                }
                else
                {
                    if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_ALLIANCE)
                    {
                        pInstance->DoCompleteAchievement(ACHIEV_NORMAL_DONE_A);
                    }else
                    {
                        pInstance->DoCompleteAchievement(ACHIEV_NORMAL_DONE_H);
                    }
                }
            }
        }
    };
};

class npc_risen_ghoul : public CreatureScript
{
public:
    npc_risen_ghoul() : CreatureScript("npc_risen_ghoul") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_risen_ghoulAI(creature);
    }

    struct npc_risen_ghoulAI : public ScriptedAI
    {
        npc_risen_ghoulAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 uiAttackTimer;

        void Reset()
        {
            uiAttackTimer = 3500;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiAttackTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                {
                    if (target && target->isAlive())
                    DoCast(me->getVictim(), RAID_MODE(SPELL_LEAP, SPELL_LEAP_H));
                }
                uiAttackTimer = 3500;
            } else uiAttackTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_black_knight_skeletal_gryphon : public CreatureScript
{
public:
    npc_black_knight_skeletal_gryphon() : CreatureScript("npc_black_knight_skeletal_gryphon") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_black_knight_skeletal_gryphonAI(creature);
    }

    struct npc_black_knight_skeletal_gryphonAI : public npc_escortAI
    {
        npc_black_knight_skeletal_gryphonAI(Creature* creature) : npc_escortAI(creature), vehicle(me->GetVehicleKit())
        {
            Start(false,true,0,NULL);
            pInstance = creature->GetInstanceScript();
        }
        InstanceScript* pInstance;

        Vehicle* vehicle;

        void Reset()
        {
            vehicle->Reset();
        }

        void WaypointReached(uint32 uiPointId)
        {
            switch(uiPointId)
            {
                    case 1:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 2:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    if (pInstance)
                    {
                    pInstance->SetData(DATA_BLACK_KNIGHT, NOT_STARTED);
                    }
                    break;
                    case 3:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 4:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 5:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 6:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 7:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 8:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 9:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 10:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 11:
                    me->SetSpeed(MOVE_FLIGHT , 2.0f);
                    break;
                    case 12:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    me->SetSpeed(MOVE_RUN, 2.0f);
                    break;
                    case 13:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    me->SummonCreature(VEHICLE_GR,744.841f,634.505f,411.575f, 2.79f);
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;
        }
    };
};

class npc_gr : public CreatureScript
{
public:
    npc_gr() : CreatureScript("npc_gr") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_grAI(creature);
    }

    struct npc_grAI : public npc_escortAI
    {
        npc_grAI(Creature* creature) : npc_escortAI(creature)
        {
            Start(false,true,0,NULL);
            pInstance = (InstanceScript*)creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void WaypointReached(uint32 uiPointId)
        {
            switch(uiPointId)
            {
                    case 1:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
                    if (pInstance)
                    {
                    pInstance->SetData(DATA_BLACK_KNIGHT, IN_PROGRESS);
                    }
                    break;
                    case 2:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
                    if (pInstance)
                    {
                    pInstance->SetData(DATA_BLACK_KNIGHT, DONE);
                    }
                    break;
                    case 3:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
                    break;
                    case 4:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
                    if (pInstance)
                    {
                    pInstance->SetData(DATA_KNIGHT, NOT_STARTED);
                    }
                    break;
                    case 5:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
                    if (pInstance)
                    {
                    pInstance->SetData(DATA_KNIGHT, IN_PROGRESS);
                    }
                    break;
                    case 6:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
                    break;
                    case 7:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
                    break;
                    case 8:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
                    case 9:
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    if (pInstance)
                    {
                    pInstance->SetData(DATA_KNIGHT, DONE);
                    }
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;
        }
};
};

void AddSC_boss_black_knight()
{
    new boss_black_knight();
    new npc_risen_ghoul();
    new npc_black_knight_skeletal_gryphon();
    new npc_gr();
}
