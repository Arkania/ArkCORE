/*
 * Copyright (C) 2005-2011 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008-2011 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010-2011 ArkCORE <http://www.arkania.net/>
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

/* Script Data Start
SDName: Boss_Skadi
SDAuthor: LordVanMartin, JohnHoliver
SD%Complete: 90%
SDComment: <Known Bugs>
               After Unmount() he appears to still be flying even with SetFlying(false)
           </Known Bugs>
SDCategory: Utgarde Pinnacle
Script Data End */

#include "ScriptPCH.h"
#include "utgarde_pinnacle.h"

//Yell
enum eYells
{
    SAY_AGGRO                           = -1575019,
    SAY_DRAKE_BREATH_1                  = -1575020,
    SAY_DRAKE_BREATH_2                  = -1575021,
    SAY_DRAKE_BREATH_3                  = -1575022,
    SAY_DRAKE_HARPOON_1                 = -1575023,
    SAY_DRAKE_HARPOON_2                 = -1575024,
    SAY_KILL_1                          = -1575025,
    SAY_KILL_2                          = -1575026,
    SAY_KILL_3                          = -1575027,
    SAY_DEATH                           = -1575028,
    SAY_DRAKE_DEATH                     = -1575029,
    EMOTE_RANGE                         = -1575030,
};

static Position SpawnLoc = {468.931f, -513.555f, 104.723f, 0};
static Position Location[]=
{
    // Boss
    {341.740997f, -516.955017f, 104.66900f, 0}, // 0
    {293.299f, -505.95f, 142.03f, 0},           // 1
    {301.664f, -535.164f, 146.097f, 0},         // 2
    {521.031006f, -544.667847f, 128.80064f, 0}, // 3
    {477.311981f, -509.296814f, 104.72308f, 0}, // 4
    {341.740997f, -516.955017f, 104.66900f, 0}, // 5
    {341.740997f, -516.955017f, 104.66900f, 0}, // 6
    {341.740997f, -516.955017f, 104.66900f, 0}, // 7
    // Triggers Left
    {469.661f, -484.546f, 104.712f, 0},         // 8
    {483.315f, -485.028f, 104.718f, 0},         // 9
    {476.87f, -487.994f, 104.735f, 0},          //10
    {477.512f, -497.772f, 104.728f, 0},         //11
    {486.287f, -500.759f, 104.722f, 0},         //12
    {480.1f, -503.895f, 104.722f, 0},           //13
    {472.391f, -505.103f, 104.723f, 0},         //14
    {478.885f, -510.803f, 104.723f, 0},         //15
    {489.529f, -508.615f, 104.723f, 0},         //16
    {484.272f, -508.589f, 104.723f, 0},         //17
    {465.328f, -506.495f, 104.427f, 0},         //18
    {456.885f, -508.104f, 104.447f, 0},         //19
    {450.177f, -507.989f, 105.247f, 0},         //20
    {442.273f, -508.029f, 104.813f, 0},         //21
    {434.225f, -508.19f, 104.787f, 0},          //22
    {423.902f, -508.525f, 104.274f, 0},         //23
    {414.551f, -508.645f, 105.136f, 0},         //24
    {405.787f, -508.755f, 104.988f, 0},         //25
    {398.812f, -507.224f, 104.82f, 0},          //26
    {389.702f, -506.846f, 104.729f, 0},         //27
    {381.856f, -506.76f, 104.756f, 0},          //28
    {372.881f, -507.254f, 104.779f, 0},         //29
    {364.978f, -508.182f, 104.673f, 0},         //30
    {357.633f, -508.075f, 104.647f, 0},         //31
    {350.008f, -506.826f, 104.588f, 0},         //32
    {341.69f, -506.77f, 104.499f, 0},           //33
    {335.31f, -505.745f, 105.18f, 0},           //34
    {471.178f, -510.74f, 104.723f, 0},          //35
    {461.759f, -510.365f, 104.199f, 0},         //36
    {424.07287f, -510.082916f, 104.711082f, 0}, //37
    // Triggers Right
    {489.46f, -513.297f, 105.413f, 0},          //38
    {485.706f, -517.175f, 104.724f, 0},         //39
    {480.98f, -519.313f, 104.724f, 0},          //40
    {475.05f, -520.52f, 104.724f, 0},           //41
    {482.97f, -512.099f, 104.724f, 0},          //42
    {477.082f, -514.172f, 104.724f, 0},         //43
    {468.991f, -516.691f, 104.724f, 0},         //44
    {461.722f, -517.063f, 104.627f, 0},         //45
    {455.88f, -517.681f, 104.707f, 0},          //46
    {450.499f, -519.099f, 104.701f, 0},         //47
    {444.889f, -518.963f, 104.82f, 0},          //48
    {440.181f, -518.893f, 104.861f, 0},         //49
    {434.393f, -518.758f, 104.891f, 0},         //50
    {429.328f, -518.583f, 104.904f, 0},         //51
    {423.844f, -518.394f, 105.004f, 0},         //52
    {418.707f, -518.266f, 105.135f, 0},         //53
    {413.377f, -518.085f, 105.153f, 0},         //54
    {407.277f, -517.844f, 104.893f, 0},         //55
    {401.082f, -517.443f, 104.723f, 0},         //56
    {394.933f, -514.64f, 104.724f, 0},          //57
    {388.917f, -514.688f, 104.734f, 0},         //58
    {383.814f, -515.834f, 104.73f, 0},          //59
    {377.887f, -518.653f, 104.777f, 0},         //60
    {371.376f, -518.289f, 104.781f, 0},         //61
    {365.669f, -517.822f, 104.758f, 0},         //62
    {359.572f, -517.314f, 104.706f, 0},         //63
    {353.632f, -517.146f, 104.647f, 0},         //64
    {347.998f, -517.038f, 104.538f, 0},         //65
    {341.803f, -516.98f, 104.584f, 0},          //66
    {335.879f, -516.674f, 104.628f, 0},         //67
    {329.871f, -515.92f, 104.711f, 0},          //68
    // Breach Zone
    {491.2511f, -503.3972f, 115.3011f, 0},      //69
    {485.9489f, -522.4509f, 115.3011f, 0},      //70
    {435.1892f, -514.5232f, 118.6719f, 0},      //71
    {413.9327f, -540.9407f, 138.2614f, 0},      //72
};

enum eCombatPhase
{
    FLYING,
    SKADI
};

enum eSide
{
    LEFT,
    RIGHT,
    NONE
};

enum eSpells
{
    SPELL_CRUSH                 = 50234,
    H_SPELL_CRUSH               = 59330,
    SPELL_POISONED_SPEAR        = 50255,
    H_SPELL_POISONED_SPEAR      = 59331,
    SPELL_POISONED_SPEAR_DOT    = 50258,
    H_SPELL_POISONED_SPEAR_DOT  = 59334,
    SPELL_WHIRLWIND             = 50228, //random target, but not the tank approx. every 20s
    H_SPELL_WHIRLWIND           = 59322,
    SPELL_LAUNCH_HARPOON        = 51368,
    SPELL_FREEZING_CLOUD        = 47579,
    H_SPELL_FREEZING_CLOUD      = 60020
};

enum eCreature
{
    CREATURE_YMIRJAR_WARRIOR       = 26690,
    CREATURE_YMIRJAR_WITCH_DOCTOR  = 26691,
    CREATURE_YMIRJAR_HARPOONER     = 26692,
    CREATURE_GRAUF                 = 26893,
    CREATURE_TRIGGER               = 28351,
    DATA_MOUNT                     = 27043,
};

enum eAchievments
{
    ACHIEV_TIMED_START_EVENT                      = 17726,
    ACHIEV_MY_GIRL_LOVES_TO_SKADI  = 2156,
    MAX_HIT_COUNT                  = 2,         //needed harpoon hits
    H_MAX_HIT_COUNT                = 4          //heroic
};

class boss_skadi : public CreatureScript
{
public:
    boss_skadi() : CreatureScript("boss_skadi") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_skadiAI (creature);
    }

    struct boss_skadiAI : public ScriptedAI
    {
        boss_skadiAI(Creature* c) : ScriptedAI(c), Summons(me)
        {
            m_pInstance = c->GetInstanceScript();
        }

        InstanceScript* m_pInstance;
        SummonList Summons;
        std::vector<uint64> triggersGUID;

        uint64 m_uiWhirlGUID;
        uint64 m_uiGraufGUID;
        uint32 m_uiCrushTimer;
        uint32 m_uiSpawnTriggerTimer;
        uint32 m_uiPoisonedSpearTimer;
        uint32 m_uiWhirlwindTimer;
        uint32 m_uiWaypointId;
        uint32 m_uiMovementTimer;
        uint32 m_uiMountTimer;
        uint32 m_uiSummonTimer;
        uint8  m_uiSpellHitCount;
        uint8  m_Start, m_End, m_LocNr, m_LocCount;
        bool   m_bSaidEmote;
        bool m_isWhirling;
        bool m_bAchiev;

        eSide BreathSide;
        eCombatPhase Phase;

        void Reset()
        {
            triggersGUID.clear();

            m_uiCrushTimer = 8000;
            m_uiPoisonedSpearTimer = 10000;
            m_uiWhirlwindTimer = 20000;
            m_uiMountTimer = 3000;
            m_uiWaypointId = 0;
            m_bAchiev = true;
            m_bSaidEmote = false;
            m_isWhirling = false;
            m_uiWhirlGUID = 0;
            m_uiSpellHitCount = 0;

            Phase = SKADI;
            BreathSide = NONE;

            Summons.DespawnAll();
            me->SetSpeed(MOVE_FLIGHT, 3.0f);
            me->SetReactState(REACT_AGGRESSIVE);
            //me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
            if ((Unit::GetCreature((*me), m_uiGraufGUID) == NULL) && !me->IsMounted())
                 me->SummonCreature(CREATURE_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);
            if (m_pInstance)
            {
                m_pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, NOT_STARTED);
                m_pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }
        }

        void JustReachedHome()
        {
            me->SetFlying(false);
            me->Unmount();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            if (Unit::GetCreature((*me), m_uiGraufGUID) == NULL)
                me->SummonCreature(CREATURE_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);

            Phase = FLYING;

            m_uiMovementTimer = 1000;
            m_uiSummonTimer = 10000;
            me->SetInCombatWithZone();
            if (m_pInstance)
            {
                m_pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, IN_PROGRESS);
                m_pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
                me->GetMotionMaster()->MoveJump(Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 5.0f, 10.0f);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                m_uiMountTimer = 1000;
                Summons.DespawnEntry(CREATURE_GRAUF);
            }
        }

        void JustSummoned(Creature* pSummoned)
        {
            switch (pSummoned->GetEntry())
            {
                case CREATURE_GRAUF:
                    m_uiGraufGUID = pSummoned->GetGUID();
                    break;
                case CREATURE_YMIRJAR_WARRIOR:
                case CREATURE_YMIRJAR_WITCH_DOCTOR:
                case CREATURE_YMIRJAR_HARPOONER:
                    pSummoned->setActive(true);
                    pSummoned->SetInCombatWithZone();
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        pSummoned->AI()->AttackStart(target);
                    break;
                case CREATURE_TRIGGER:
                    pSummoned->CastSpell((Unit*)NULL, DUNGEON_MODE(SPELL_FREEZING_CLOUD, H_SPELL_FREEZING_CLOUD), true);
                    pSummoned->ForcedDespawn(10*IN_MILLISECONDS);
                    break;
            }
            Summons.Summon(pSummoned);
        }

        void SummonedCreatureDespawn(Creature* pSummoned)
        {
            if (pSummoned->GetEntry() == CREATURE_GRAUF)
                m_uiGraufGUID = 0;
            Summons.Despawn(pSummoned);
        }

        void SpellHit(Unit* /*caster*/, const SpellEntry* spell)
        {
            if (spell->Id == SPELL_LAUNCH_HARPOON && Phase == FLYING)
            {
                DoScriptText(RAND(SAY_DRAKE_HARPOON_1, SAY_DRAKE_HARPOON_2), me);
                m_uiSpellHitCount++;
                if (m_uiSpellHitCount >= DUNGEON_MODE(MAX_HIT_COUNT, H_MAX_HIT_COUNT))
                {
                    Phase = SKADI;
                    me->Unmount();
                    me->SetFlying(false);
                    me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                    if (Creature* pGrauf = me->SummonCreature(CREATURE_GRAUF, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS))
                    {
                        pGrauf->GetMotionMaster()->MoveFall(0);
                        pGrauf->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);
                    }

                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        me->AI()->AttackStart(target);
                        me->GetMotionMaster()->MoveChase(target);
                    }
                    me->GetMotionMaster()->MoveJump(Location[4].GetPositionX(), Location[4].GetPositionY(), Location[4].GetPositionZ(), 5.0f, 10.0f);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    DoScriptText(SAY_DRAKE_DEATH, me);
                    m_uiCrushTimer = 10000;
                    m_uiPoisonedSpearTimer = 8000;
                    m_uiWhirlwindTimer = 4000;
                }
            }
        }

        void SpellHitTarget(Unit *target, const SpellEntry *spell) 
                    {
            if (spell->Id == DUNGEON_MODE(SPELL_POISONED_SPEAR, H_SPELL_POISONED_SPEAR))
                target->CastSpell(target, DUNGEON_MODE(SPELL_POISONED_SPEAR_DOT, H_SPELL_POISONED_SPEAR_DOT), true);
        }

        void UpdateAI(const uint32 diff)
        {
            switch (Phase)
            {
                case FLYING:
                    if (!UpdateVictim())
                        return;

                    if (me->GetPositionX() >= 515)
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        if (!m_bSaidEmote)
                        {
                            DoScriptText(EMOTE_RANGE, me);
                            m_bSaidEmote = true;
                        }
                    }
                    else
                    {
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        m_bSaidEmote = false;
                    }

                    if (m_uiMountTimer && m_uiMountTimer <= diff)
                    {
                        me->Mount(DATA_MOUNT);
                        me->SetFlying(true);
                        m_uiMountTimer = 0;
                    } else m_uiMountTimer -= diff;

                    if (m_uiSummonTimer <= diff)
                    {
                        SpawnMobs();
                        m_uiSummonTimer = 25000;
                    } else m_uiSummonTimer -= diff;

                    if (BreathSide != NONE)
                        if (m_uiSpawnTriggerTimer <= diff)
                        {
                            me->SummonCreature(CREATURE_TRIGGER,Location[m_LocCount]);
                            m_uiSpawnTriggerTimer = 125;
                            m_LocCount++;
                            if (m_LocCount > m_End)
                                BreathSide = NONE;
                        } else m_uiSpawnTriggerTimer -= diff;

                    if (m_uiMovementTimer <= diff)
                    {
                        switch (m_uiWaypointId)
                        {
                            case 0:
                                me->GetMotionMaster()->MovePoint(0, Location[1].GetPositionX(), Location[1].GetPositionY(), Location[1].GetPositionZ());
                                m_uiMovementTimer = 5000;
                                break;
                            case 1:
                                me->GetMotionMaster()->MovePoint(0, Location[2].GetPositionX(), Location[2].GetPositionY(), Location[2].GetPositionZ());
                                m_uiMovementTimer = 2000;
                                break;
                            case 2:
                                me->GetMotionMaster()->MovePoint(0, Location[3].GetPositionX(), Location[3].GetPositionY(), Location[3].GetPositionZ());
                                m_uiMovementTimer = 15000;
                                break;
                            case 3:
                                switch (urand(0,1))
                                {
                                    case 0: 
                                        BreathSide = LEFT; 
                                        m_Start = 8;
                                        m_End = 37;
                                        m_LocNr = 69;
                                        break;
                                    case 1: 
                                        BreathSide = RIGHT;
                                        m_Start = 38;
                                        m_End = 68;
                                        m_LocNr = 70; 
                                        break;
                                }
                                me->GetMotionMaster()->MovePoint(0, Location[m_LocNr].GetPositionX(), Location[m_LocNr].GetPositionY(), Location[m_LocNr].GetPositionZ());
                                DoScriptText(RAND(SAY_DRAKE_BREATH_1, SAY_DRAKE_BREATH_2, SAY_DRAKE_BREATH_3), me);
                                //DoScriptText(EMOTE_BREATH, me);
                                m_uiMovementTimer = 2500;
                                m_uiSpawnTriggerTimer = 3000;
                                m_LocCount = m_Start;
                                break;
                            case 4:
                                me->GetMotionMaster()->MovePoint(0, Location[71].GetPositionX(), Location[71].GetPositionY(), Location[71].GetPositionZ());
                                m_uiMovementTimer = 2000;
                                //SpawnTrigger();

                                // if there are harpoon hits at this point, disable achievement
                                if (m_uiSpellHitCount)
                                    m_bAchiev = false;
                                break;
                            case 5:
                                me->GetMotionMaster()->MovePoint(0, Location[72].GetPositionX(), Location[72].GetPositionY(), Location[72].GetPositionZ());
                                m_uiMovementTimer = 15000;
                                break;
                            case 6:
                                me->GetMotionMaster()->MovePoint(0, Location[3].GetPositionX(), Location[3].GetPositionY(), Location[3].GetPositionZ());
                                m_uiWaypointId = 2;
                                m_uiMovementTimer = 15000;
                                break;
                        }
                        m_uiWaypointId++;
                    } else m_uiMovementTimer -= diff;
                    break;
                case SKADI:
                    //Return since we have no target
                    if (!UpdateVictim())
                        return;

                    if (!me->HasAura(DUNGEON_MODE(SPELL_WHIRLWIND, H_SPELL_WHIRLWIND)))
                    {
                        if (m_isWhirling)
                        {
                            m_isWhirling = false;
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                            m_uiWhirlwindTimer = 13000;
                        }

                    if (m_uiCrushTimer <= diff)
                    {
                            if(!me->IsNonMeleeSpellCasted(false))
                            {
                            DoCastVictim(DUNGEON_MODE(SPELL_CRUSH, H_SPELL_CRUSH));
                            m_uiCrushTimer = urand(8000, 12000);
                            }
                    } else m_uiCrushTimer -= diff;

                    if (m_uiPoisonedSpearTimer <= diff)
                    {
                            if(!me->IsNonMeleeSpellCasted(false))
                            {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, DUNGEON_MODE(SPELL_POISONED_SPEAR, H_SPELL_POISONED_SPEAR));
                            m_uiPoisonedSpearTimer = urand(10000, 12000);
                            }
                    } else m_uiPoisonedSpearTimer -= diff;
                    }

                    if (!m_isWhirling)
                    {
                    if (m_uiWhirlwindTimer <= diff)
                    {
                        if(!me->IsNonMeleeSpellCasted(false))
                        {
                                if (Unit *newTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                    m_uiWhirlGUID = newTarget->GetGUID();

                                DoCast(DUNGEON_MODE(SPELL_WHIRLWIND, H_SPELL_WHIRLWIND));
                                m_isWhirling = true;
                        }
                    } else m_uiWhirlwindTimer -= diff;
                    }

                    if (m_isWhirling)  //somewhat hacky to get skadi move during whirlwind
                    {
                        if (m_uiWhirlwindTimer <= diff)
                        {
                            Unit *whirlTarget = Unit::GetUnit(*me, m_uiWhirlGUID);
                            if (whirlTarget && whirlTarget->isAlive())
                            {
                                me->GetMotionMaster()->Clear();
                                me->GetMotionMaster()->MovePoint(0,whirlTarget->GetPositionX(),whirlTarget->GetPositionY(),whirlTarget->GetPositionZ());
                            } 
                            else if (Unit *newTarget = SelectTarget(SELECT_TARGET_RANDOM, 1)) //whirl target died
                            {
                                me->GetMotionMaster()->Clear();
                                m_uiWhirlGUID = newTarget->GetGUID();
                                me->GetMotionMaster()->MovePoint(0,newTarget->GetPositionX(),newTarget->GetPositionY(),newTarget->GetPositionZ());
                            }
                            else                                                            //only 1 target left
                            {
                                me->GetMotionMaster()->Clear();
                                me->GetMotionMaster()->MoveChase(me->getVictim());
                            }

                            m_uiWhirlwindTimer = 500;
                        } else m_uiWhirlwindTimer -= diff;
                    }

                    DoMeleeAttackIfReady();
                    break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            Summons.DespawnAll();
            if (m_pInstance)
            {
                m_pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, DONE);
    
                if (IsHeroic() && m_bAchiev)
                    m_pInstance->DoCompleteAchievement(ACHIEV_MY_GIRL_LOVES_TO_SKADI);
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2, SAY_KILL_3), me);
        }

        void SpawnMobs()
        {
            for (uint8 i = 0; i < DUNGEON_MODE(5, 6); ++i)
            {
                switch (urand(0, 2))
                {
                    case 0: me->SummonCreature(CREATURE_YMIRJAR_WARRIOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000); break;
                    case 1: me->SummonCreature(CREATURE_YMIRJAR_WITCH_DOCTOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000); break;
                    case 2: me->SummonCreature(CREATURE_YMIRJAR_HARPOONER, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000); break;
                }
            }
        }

        void SpawnTrigger()
        {
            uint8 iStart = 0, iEnd = 0;
            switch (urand(0, 1))
            {
                case 0:
                    iStart = 8;
                    iEnd = 37;
                    break;
                case 1:
                    iStart = 38;
                    iEnd = 68;
                    break;
                default:
                    break;
            }
            for (uint32 i = iStart; i < iEnd; ++i)
                me->SummonCreature(CREATURE_TRIGGER, Location[i]);
        }
    };

};

class go_harpoon_launcher : public GameObjectScript
{
public:
    go_harpoon_launcher() : GameObjectScript("go_harpoon_launcher") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            InstanceScript* instance = go->GetInstanceScript();

            if (!instance)
        return false;

            Creature* skadi = Unit::GetCreature(*go, instance->GetData64(DATA_SKADI_THE_RUTHLESS));
            if (skadi && skadi->isAlive())
                player->CastSpell(skadi, SPELL_LAUNCH_HARPOON, true);

            return false;
        }
};

void AddSC_boss_skadi()
{
    new boss_skadi();
    new go_harpoon_launcher();
}
