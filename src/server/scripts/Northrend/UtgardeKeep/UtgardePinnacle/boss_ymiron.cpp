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

/* Script Data Start
SDName: Boss ymiron
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

#include "ScriptPCH.h"
#include "utgarde_pinnacle.h"

enum Spells
{
    SPELL_BANE                                = 48294,
    H_SPELL_BANE                              = 59301,
    SPELL_BANE_TRIGGERED                      = 59302,
    SPELL_DARK_SLASH                          = 48292,
    SPELL_FETID_ROT                           = 48291,
    H_SPELL_FETID_ROT                         = 59300,
    SPELL_SCREAMS_OF_THE_DEAD                 = 51750,
    SPELL_SPIRIT_BURST                        = 48529,
    H_SPELL_SPIRIT_BURST                      = 59305,
    SPELL_SPIRIT_STRIKE                       = 48423,
    H_SPELL_SPIRIT_STRIKE                     = 59304,
    SPELL_ANCESTORS_VENGEANCE                 = 16939,
	SPELL_WITHER                              = 48584,

    SPELL_SUMMON_AVENGING_SPIRIT              = 48592,
    SPELL_SUMMON_SPIRIT_FOUNT                 = 48386,

    SPELL_CHANNEL_SPIRIT_TO_YMIRON            = 48316,
    SPELL_CHANNEL_YMIRON_TO_SPIRIT            = 48307,

    SPELL_SPIRIT_FOUNT                        = 48380,
    H_SPELL_SPIRIT_FOUNT                      = 59320
};

//not in db
enum Yells
{
    SAY_AGGRO                               = -1575031,
    SAY_SUMMON_BJORN                        = -1575032,
    SAY_SUMMON_HALDOR                       = -1575033,
    SAY_SUMMON_RANULF                       = -1575034,
    SAY_SUMMON_TORGYN                       = -1575035,
    SAY_SLAY_1                              = -1575036,
    SAY_SLAY_2                              = -1575037,
    SAY_SLAY_3                              = -1575038,
    SAY_SLAY_4                              = -1575039,
    SAY_DEATH                               = -1575040,
};

enum Creatures
{
    CREATURE_BJORN                          = 27303,
    CREATURE_BJORN_VISUAL                   = 27304,
    CREATURE_HALDOR                         = 27307,
    CREATURE_HALDOR_VISUAL                  = 27310,
    CREATURE_RANULF                         = 27308,
    CREATURE_RANULF_VISUAL                  = 27311,
    CREATURE_TORGYN                         = 27309,
    CREATURE_TORGYN_VISUAL                  = 27312,
    CREATURE_SPIRIT_FOUNT                   = 27339,
    CREATURE_AVENGING_SPIRIT                = 27386
};
enum Achievements
{
    ACHIEV_KINGS_BANE                       = 2157
};

struct ActiveBoatStruct
{
    uint32 npc;
    uint32 say;
    float MoveX,MoveY,MoveZ,SpawnX,SpawnY,SpawnZ,SpawnO;
};

static ActiveBoatStruct ActiveBot[4] =
{
    {CREATURE_BJORN_VISUAL,  SAY_SUMMON_BJORN,  404.379f, -335.335f, 104.756f, 413.594f, -335.408f, 107.995f, 3.157f},
    {CREATURE_HALDOR_VISUAL, SAY_SUMMON_HALDOR, 380.813f, -335.069f, 104.756f, 369.994f, -334.771f, 107.995f, 6.232f},
    {CREATURE_RANULF_VISUAL, SAY_SUMMON_RANULF, 381.546f, -314.362f, 104.756f, 370.841f, -314.426f, 107.995f, 6.232f},
    {CREATURE_TORGYN_VISUAL, SAY_SUMMON_TORGYN, 404.310f, -314.761f, 104.756f, 413.992f, -314.703f, 107.995f, 3.157f}
};

class boss_ymiron : public CreatureScript
{
public:
    boss_ymiron() : CreatureScript("boss_ymiron") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ymironAI(creature);
    }

    struct boss_ymironAI : public ScriptedAI
    {
        boss_ymironAI(Creature* c) : ScriptedAI(c), summons(c)
        {
            instance = c->GetInstanceScript();
            for (int i = 0; i < 4; ++i)
                m_uiActiveOrder[i] = i;
            for (int i = 0; i < 3; ++i)
            {
                int r = i + (rand() % (4 - i));
                int temp = m_uiActiveOrder[i];
                m_uiActiveOrder[i] = m_uiActiveOrder[r];
                m_uiActiveOrder[r] = temp;
            }
        }

        bool m_bIsWalking;
        bool m_bIsPause;
        bool m_bIsActiveWithBJORN;
        bool m_bIsActiveWithHALDOR;
        bool m_bIsActiveWithRANULF;
        bool m_bIsActiveWithTORGYN;
        bool m_bAchievement;

        uint8 m_uiActiveOrder[4];
        uint8 m_uiActivedNumber;

        uint32 m_uiFetidRot_Timer;
        uint32 m_uiBane_Timer;
        uint32 m_uiDarkSlash_Timer;
        uint32 m_uiAncestors_Vengeance_Timer;

        uint32 m_uiAbility_BJORN_Timer;
        uint32 m_uiAbility_HALDOR_Timer;
        uint32 m_uiAbility_RANULF_Timer;
        uint32 m_uiAbility_TORGYN_Timer;

        uint32 m_uiPause_Timer;
        uint32 m_uiHealthAmountModifier;
        uint32 m_uiHealthAmountMultipler;

        uint32 m_uiCheckSkadiTimer;

        uint64 m_uiActivedCreatureGUID;
        uint64 m_uiOrbGUID;

        InstanceScript* instance;
        SummonList summons;

        void Reset()
        {
            m_bIsPause = false;
            m_bIsWalking = false;
            m_bAchievement = true;
            m_bIsActiveWithBJORN = false;
            m_bIsActiveWithHALDOR = false;
            m_bIsActiveWithRANULF = false;
            m_bIsActiveWithTORGYN = false;

            m_uiFetidRot_Timer            = urand(5*IN_MILLISECONDS,8*IN_MILLISECONDS);
            m_uiBane_Timer                = urand(20*IN_MILLISECONDS,22*IN_MILLISECONDS);
            m_uiDarkSlash_Timer           = urand(10*IN_MILLISECONDS,33*IN_MILLISECONDS);
            m_uiAncestors_Vengeance_Timer = urand(60*IN_MILLISECONDS,45*IN_MILLISECONDS);
            m_uiPause_Timer               = 0;
            m_uiCheckSkadiTimer           = 10*IN_MILLISECONDS;

            m_uiAbility_BJORN_Timer  = 0;
            m_uiAbility_HALDOR_Timer = 0;
            m_uiAbility_RANULF_Timer = 0;
            m_uiAbility_TORGYN_Timer = 0;

            m_uiActivedNumber        = 0;
            m_uiHealthAmountModifier = 1;
            m_uiHealthAmountMultipler = DUNGEON_MODE(33,20);

            DespawnBoatGhosts(m_uiActivedCreatureGUID);
            DespawnBoatGhosts(m_uiOrbGUID);

            summons.DespawnAll();

            if (instance)
                instance->SetData(DATA_KING_YMIRON_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_AGGRO, me);

            if (instance)
                instance->SetData(DATA_KING_YMIRON_EVENT, IN_PROGRESS);
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }

        void UpdateAI(const uint32 diff)
        {
            if (m_uiCheckSkadiTimer <= diff)
            {
                if (instance)
                {
                    // try to prevent a possible exploit
                    if ((instance->GetData(DATA_SKADI_THE_RUTHLESS_EVENT) < DONE) && (!me->IsVisible() || (me->getFaction() != 35)))
                    {
                        me->SetVisible(false);
                        me->setFaction(35);
                    }
                    else if ((instance->GetData(DATA_SKADI_THE_RUTHLESS_EVENT) >= DONE) && (me->IsVisible()  || (me->getFaction() == 35)))
                    {
                        me->RestoreFaction();
                        me->SetVisible(true);
                    }
                }
                m_uiCheckSkadiTimer = 10*IN_MILLISECONDS;
            } else m_uiCheckSkadiTimer -= diff;

            if (m_bIsWalking)
            {
                if (m_uiPause_Timer <= diff)
                {
                    DoScriptText(ActiveBot[m_uiActiveOrder[m_uiActivedNumber]].say, me);
                    DoCast(me, SPELL_CHANNEL_YMIRON_TO_SPIRIT); // should be on spirit
                    if (Creature* temp = me->SummonCreature(ActiveBot[m_uiActiveOrder[m_uiActivedNumber]].npc, ActiveBot[m_uiActiveOrder[m_uiActivedNumber]].SpawnX, ActiveBot[m_uiActiveOrder[m_uiActivedNumber]].SpawnY, ActiveBot[m_uiActiveOrder[m_uiActivedNumber]].SpawnZ, ActiveBot[m_uiActiveOrder[m_uiActivedNumber]].SpawnO, TEMPSUMMON_CORPSE_DESPAWN, 0))
                    {
                        m_uiActivedCreatureGUID = temp->GetGUID();
                        temp->CastSpell(me, SPELL_CHANNEL_SPIRIT_TO_YMIRON, true);
                        temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        temp->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        switch (m_uiActiveOrder[m_uiActivedNumber])
                        {
                            case 0: m_bIsActiveWithBJORN  = true; break;
                            case 1: m_bIsActiveWithHALDOR = true; break;
                            case 2: m_bIsActiveWithRANULF = true; break;
                            case 3: m_bIsActiveWithTORGYN = true; break;
                        }
                    }

                    m_bIsPause = true;
                    m_bIsWalking = false;
                    m_uiPause_Timer = 3*IN_MILLISECONDS;
                } else m_uiPause_Timer -= diff;
                return;
            }
            else if (m_bIsPause)
            {
                if (m_uiPause_Timer <= diff)
                {
                    m_uiAbility_BJORN_Timer = 5*IN_MILLISECONDS;
                    m_uiAbility_HALDOR_Timer = 5*IN_MILLISECONDS;
                    m_uiAbility_RANULF_Timer = 5*IN_MILLISECONDS;
                    m_uiAbility_TORGYN_Timer = 5*IN_MILLISECONDS;

                    m_bIsPause = false;
                    m_uiPause_Timer = 0;
                } else m_uiPause_Timer -= diff;
                return;
            }

            //Return since we have no target
             if (!UpdateVictim())
                 return;

            if (!m_bIsPause)
            {
                // Normal spells ------------------------------------------------------------------------
                if (m_uiBane_Timer <= diff)
                {
                    if(!me->IsNonMeleeSpellCasted(false))
                    {
                    DoCast(me, DUNGEON_MODE(SPELL_BANE, H_SPELL_BANE));
                        m_uiBane_Timer = urand(20*IN_MILLISECONDS,22*IN_MILLISECONDS);
                    }
                } else m_uiBane_Timer -= diff;

                if (m_uiFetidRot_Timer <= diff)
                {
                    if(!me->IsNonMeleeSpellCasted(false))
                    {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                        DoCast(target, DUNGEON_MODE(SPELL_FETID_ROT, H_SPELL_FETID_ROT));
                    m_uiFetidRot_Timer = urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS);
                    }
                } else m_uiFetidRot_Timer -= diff;

                if (m_uiDarkSlash_Timer <= diff)
                {
                    if(!me->IsNonMeleeSpellCasted(false))
                    {
                        int dmg = int(me->getVictim()->GetHealth()*0.5);
                        me->CastCustomSpell(me->getVictim(), SPELL_DARK_SLASH, &dmg, 0, 0, false);
                        m_uiDarkSlash_Timer = urand(15*IN_MILLISECONDS,18*IN_MILLISECONDS);
                    }
                } else m_uiDarkSlash_Timer -= diff;

                if (m_uiAncestors_Vengeance_Timer <= diff)
                {
                    DoCast(me, SPELL_ANCESTORS_VENGEANCE);
                    m_uiAncestors_Vengeance_Timer = DUNGEON_MODE(urand(60*IN_MILLISECONDS,65*IN_MILLISECONDS),urand(45*IN_MILLISECONDS,50*IN_MILLISECONDS));
                } else m_uiAncestors_Vengeance_Timer -= diff;

                // Abilities ------------------------------------------------------------------------------
                if (m_bIsActiveWithBJORN && m_uiAbility_BJORN_Timer <= diff)
                {
                    //DoCast(me, SPELL_SUMMON_SPIRIT_FOUNT); // works fine, but using summon has better control
                    if (Creature* temp = me->SummonCreature(CREATURE_SPIRIT_FOUNT, float(385+rand()%10), float(-330+rand()%10), 104.756f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 180*IN_MILLISECONDS))
                    {
                        temp->SetSpeed(MOVE_RUN, 0.4f);
                        temp->CastSpell(temp, DUNGEON_MODE(SPELL_SPIRIT_FOUNT, H_SPELL_SPIRIT_FOUNT), true);
                        temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        temp->SetDisplayId(11686);
                        temp->GetMotionMaster()->MoveChase(me->getVictim());
                        m_uiOrbGUID = temp->GetGUID();
                    }
                    m_bIsActiveWithBJORN = false; // only one orb
                } else m_uiAbility_BJORN_Timer -= diff;

                if (m_bIsActiveWithHALDOR && m_uiAbility_HALDOR_Timer <= diff)
                {
                    if(!me->IsNonMeleeSpellCasted(false))
                    {
                    DoCast(me->getVictim(), DUNGEON_MODE(SPELL_SPIRIT_STRIKE, H_SPELL_SPIRIT_STRIKE));
                    m_uiAbility_HALDOR_Timer = 5*IN_MILLISECONDS; // overtime
                    }
                } else m_uiAbility_HALDOR_Timer -= diff;

                if (m_bIsActiveWithRANULF && m_uiAbility_RANULF_Timer <= diff)
                {
                    if(!me->IsNonMeleeSpellCasted(false))
                    {
                    DoCast(me, DUNGEON_MODE(SPELL_SPIRIT_BURST, H_SPELL_SPIRIT_BURST));
                    m_uiAbility_RANULF_Timer = 10*IN_MILLISECONDS; // overtime
                    }
                } else m_uiAbility_RANULF_Timer -= diff;

                if (m_bIsActiveWithTORGYN && m_uiAbility_TORGYN_Timer <= diff)
                {
                    float x, y, z;
                    x = me->GetPositionX()-5;
                    y = me->GetPositionY()-5;
                    z = me->GetPositionZ();
                    for (uint8 i = 0; i < 4; ++i)
                    {
                        //DoCast(me, SPELL_SUMMON_AVENGING_SPIRIT); // works fine, but using summon has better control
                        if (Creature* temp = me->SummonCreature(CREATURE_AVENGING_SPIRIT, x+rand()%10, y+rand()%10, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30*IN_MILLISECONDS))
                        {
                            temp->CastSpell(temp, SPELL_WITHER, true);

                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                temp->AddThreat(target, 0.0f);
                                temp->AI()->AttackStart(target);
                            }
                        }
                    }
                    m_uiAbility_TORGYN_Timer = 15*IN_MILLISECONDS; // overtime
                } else m_uiAbility_TORGYN_Timer -= diff;

                DoMeleeAttackIfReady();

                // Health check -----------------------------------------------------------------------------
                if (me->HealthBelowPct(100 - m_uiHealthAmountMultipler * m_uiHealthAmountModifier))
                {
                    uint8 m_uiOrder = m_uiHealthAmountModifier - 1;
                    ++m_uiHealthAmountModifier;

                    me->InterruptNonMeleeSpells(true);
                    DoCast(me, SPELL_SCREAMS_OF_THE_DEAD);
                    me->GetMotionMaster()->Clear();
                    me->StopMoving();
                    me->AttackStop();
                    me->GetMotionMaster()->MovePoint(0, ActiveBot[m_uiActiveOrder[m_uiOrder]].MoveX, ActiveBot[m_uiActiveOrder[m_uiOrder]].MoveY, ActiveBot[m_uiActiveOrder[m_uiOrder]].MoveZ);

                    DespawnBoatGhosts(m_uiActivedCreatureGUID);
                    DespawnBoatGhosts(m_uiOrbGUID);

                    m_bIsActiveWithBJORN  = false;
                    m_bIsActiveWithHALDOR = false;
                    m_bIsActiveWithRANULF = false;
                    m_bIsActiveWithTORGYN = false;

                    m_uiBane_Timer                = urand(20*IN_MILLISECONDS,22*IN_MILLISECONDS);
                    m_uiFetidRot_Timer            += 3*IN_MILLISECONDS;
                    m_uiDarkSlash_Timer           += 3*IN_MILLISECONDS;
                    m_uiAncestors_Vengeance_Timer += 8*IN_MILLISECONDS;

                    m_uiActivedNumber = m_uiOrder;
                    m_bIsWalking = true;
                    m_uiPause_Timer = 3*IN_MILLISECONDS;
                    return;
                }
            }
        }

        void JustDied(Unit* killer)
        {
            DoScriptText(SAY_DEATH, me);

            DespawnBoatGhosts(m_uiActivedCreatureGUID);
            DespawnBoatGhosts(m_uiOrbGUID);

            if (instance)
            {
                if (IsHeroic() && m_bAchievement)
                    instance->DoCompleteAchievement(ACHIEV_KINGS_BANE);
                instance->SetData(DATA_KING_YMIRON_EVENT, DONE);
        }
        }

        void KilledUnit(Unit* victim)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3, SAY_SLAY_4), me);
        }

        void SpellHitTarget(Unit* target, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_BANE_TRIGGERED)
                m_bAchievement = false;
        }

        void DespawnBoatGhosts(uint64 m_uiCreatureGUID)
        {
            if (m_uiCreatureGUID)
                if (Creature* temp = (Creature*)Unit::GetUnit(*me, m_uiCreatureGUID))
                    temp->DisappearAndDie();

            m_uiCreatureGUID = 0;
        }
    };
};

void AddSC_boss_ymiron()
{
    new boss_ymiron();
}
