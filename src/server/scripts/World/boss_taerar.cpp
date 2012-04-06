/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 *
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
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

/* ScriptData
 SDName: Taerar
 SD%Complete: 70
 SDComment: Mark of Nature & Teleport NYI. Fix the way to be banished.
 SDCategory: Bosses
 EndScriptData */

#include "ScriptPCH.h"

enum eEnums {
    SAY_AGGRO = -1000399, //signed for 20021
    SAY_SUMMONSHADE = -1000400, //signed for 20021

    //Spells of Taerar
    SPELL_SLEEP = 24777,
    SPELL_NOXIOUSBREATH = 24818,
    SPELL_TAILSWEEP = 15847,
    SPELL_ARCANEBLAST = 24857,
    SPELL_BELLOWINGROAR = 22686,

    SPELL_SUMMONSHADE_1 = 24841,
    SPELL_SUMMONSHADE_2 = 24842,
    SPELL_SUMMONSHADE_3 = 24843,

    //Spells of Shades of Taerar
    SPELL_POSIONCLOUD = 24840,
    SPELL_POSIONBREATH = 20667
};

uint32 m_auiSpellSummonShade[] = { SPELL_SUMMONSHADE_1, SPELL_SUMMONSHADE_2,
        SPELL_SUMMONSHADE_3 };

class boss_taerar: public CreatureScript {
public:
    boss_taerar() :
            CreatureScript("boss_taerar") {
    }

    struct boss_taerarAI: public ScriptedAI {
        boss_taerarAI(Creature *c) :
                ScriptedAI(c) {
        }

        uint32 m_uiSleep_Timer;
        uint32 m_uiNoxiousBreath_Timer;
        uint32 m_uiTailSweep_Timer;
        uint32 m_uiArcaneBlast_Timer;
        uint32 m_uiBellowingRoar_Timer;
        uint32 m_uiShades_Timer;
        uint32 m_uiShadesSummoned;

        bool m_bShades;

        void Reset() {
            m_uiSleep_Timer = 15000 + rand() % 5000;
            m_uiNoxiousBreath_Timer = 8000;
            m_uiTailSweep_Timer = 4000;
            m_uiArcaneBlast_Timer = 12000;
            m_uiBellowingRoar_Timer = 30000;
            m_uiShades_Timer = 60000; //The time that Taerar is banished
            m_uiShadesSummoned = 0;

            m_bShades = false;
        }

        void EnterCombat(Unit* /*pWho*/) {
            DoScriptText(SAY_AGGRO, me);
        }

        void JustSummoned(Creature* pSummoned) {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                pSummoned->AI()->AttackStart(pTarget);
        }

        void UpdateAI(const uint32 uiDiff) {
            if (m_bShades && m_uiShades_Timer <= uiDiff) {
                //Become unbanished again
                me->setFaction(14);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                m_bShades = false;
            } else if (m_bShades) {
                m_uiShades_Timer -= uiDiff;
                //Do nothing while banished
                return;
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Sleep_Timer
            if (m_uiSleep_Timer <= uiDiff) {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_SLEEP);

                m_uiSleep_Timer = 8000 + rand() % 7000;
            } else
                m_uiSleep_Timer -= uiDiff;

            //NoxiousBreath_Timer
            if (m_uiNoxiousBreath_Timer <= uiDiff) {
                DoCast(me->getVictim(), SPELL_NOXIOUSBREATH);
                m_uiNoxiousBreath_Timer = 14000 + rand() % 6000;
            } else
                m_uiNoxiousBreath_Timer -= uiDiff;

            //Tailsweep every 2 seconds
            if (m_uiTailSweep_Timer <= uiDiff) {
                DoCast(me, SPELL_TAILSWEEP);
                m_uiTailSweep_Timer = 2000;
            } else
                m_uiTailSweep_Timer -= uiDiff;

            //ArcaneBlast_Timer
            if (m_uiArcaneBlast_Timer <= uiDiff) {
                DoCast(me->getVictim(), SPELL_ARCANEBLAST);
                m_uiArcaneBlast_Timer = 7000 + rand() % 5000;
            } else
                m_uiArcaneBlast_Timer -= uiDiff;

            //BellowingRoar_Timer
            if (m_uiBellowingRoar_Timer <= uiDiff) {
                DoCast(me->getVictim(), SPELL_BELLOWINGROAR);
                m_uiBellowingRoar_Timer = 20000 + rand() % 10000;
            } else
                m_uiBellowingRoar_Timer -= uiDiff;

            //Summon 3 Shades at 75%, 50% and 25% (if bShades is true we already left in line 117, no need to check here again)
            if (!m_bShades && !HealthAbovePct(100 - 25 * m_uiShadesSummoned)) {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0)) {
                    //Interrupt any spell casting
                    me->InterruptNonMeleeSpells(false);

                    //horrible workaround, need to fix
                    me->setFaction(35);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                    DoScriptText(SAY_SUMMONSHADE, me);

                    int iSize = sizeof(m_auiSpellSummonShade) / sizeof(uint32);

                    for (int i = 0; i < iSize; ++i)
                        DoCast(pTarget, m_auiSpellSummonShade[i], true);

                    ++m_uiShadesSummoned; // prevent casting twice at same health
                    m_bShades = true;
                }
                m_uiShades_Timer = 60000;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const {
        return new boss_taerarAI(creature);
    }
};

class boss_shadeoftaerar: public CreatureScript {
public:
    boss_shadeoftaerar() :
            CreatureScript("boss_shade_of_taerar") {
    }

    struct boss_shadeoftaerarAI: public ScriptedAI {
        boss_shadeoftaerarAI(Creature *c) :
                ScriptedAI(c) {
        }

        uint32 m_uiPoisonCloud_Timer;
        uint32 m_uiPosionBreath_Timer;

        void Reset() {
            m_uiPoisonCloud_Timer = 8000;
            m_uiPosionBreath_Timer = 12000;
        }

        void UpdateAI(const uint32 uiDiff) {
            if (!UpdateVictim())
                return;

            //PoisonCloud_Timer
            if (m_uiPoisonCloud_Timer <= uiDiff) {
                DoCast(me->getVictim(), SPELL_POSIONCLOUD);
                m_uiPoisonCloud_Timer = 30000;
            } else
                m_uiPoisonCloud_Timer -= uiDiff;

            //PosionBreath_Timer
            if (m_uiPosionBreath_Timer <= uiDiff) {
                DoCast(me->getVictim(), SPELL_POSIONBREATH);
                m_uiPosionBreath_Timer = 12000;
            } else
                m_uiPosionBreath_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const {
        return new boss_shadeoftaerarAI(creature);
    }
};

void AddSC_boss_taerar() {
    new boss_taerar;
    new boss_shadeoftaerar;
}
