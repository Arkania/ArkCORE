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
SDName: Ysondre
SD%Complete: 90
SDComment: Mark of Nature & Teleport missing
SDCategory: Bosses
EndScriptData */

#include "ScriptPCH.h"

enum eEnums
{
    SAY_AGGRO               = -1000360, //signed for 17969
    SAY_SUMMONDRUIDS        = -1000361, //signed for 17969

    SPELL_SLEEP             = 24777,
    SPELL_NOXIOUSBREATH     = 24818,
    SPELL_TAILSWEEP         = 15847,
    //SPELL_MARKOFNATURE   = 25040,                        // Not working
    SPELL_LIGHTNINGWAVE     = 24819,
    SPELL_SUMMONDRUIDS      = 24795,

    SPELL_SUMMON_PLAYER     = 24776,

    //druid spells
    SPELL_MOONFIRE          = 21669
};

// Ysondre script
class boss_ysondre : public CreatureScript
{
public:
    boss_ysondre() : CreatureScript("boss_ysondre") { }

    struct boss_ysondreAI : public ScriptedAI
    {
        boss_ysondreAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 m_uiSleep_Timer;
        uint32 m_uiNoxiousBreath_Timer;
        uint32 m_uiTailSweep_Timer;
        uint32 m_uiLightningWave_Timer;
        uint32 m_uiSummonDruidModifier;

        void Reset()
        {
            m_uiSleep_Timer = 15000 + rand()%5000;
            m_uiNoxiousBreath_Timer = 8000;
            m_uiTailSweep_Timer = 4000;
            m_uiLightningWave_Timer = 12000;
            m_uiSummonDruidModifier = 0;
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_AGGRO, me);
        }

        void JustSummoned(Creature* pSummoned)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                pSummoned->AI()->AttackStart(pTarget);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            //Sleep_Timer
            if (m_uiSleep_Timer <= uiDiff)
            {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_SLEEP);

                m_uiSleep_Timer = 8000 + rand()%7000;
            }
            else
                m_uiSleep_Timer -= uiDiff;

            //NoxiousBreath_Timer
            if (m_uiNoxiousBreath_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_NOXIOUSBREATH);
                m_uiNoxiousBreath_Timer = 14000 + rand()%6000;
            }
            else
                m_uiNoxiousBreath_Timer -= uiDiff;

            //Tailsweep every 2 seconds
            if (m_uiTailSweep_Timer <= uiDiff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_TAILSWEEP);

                m_uiTailSweep_Timer = 2000;
            }
            else
                m_uiTailSweep_Timer -= uiDiff;

            //LightningWave_Timer
            if (m_uiLightningWave_Timer <= uiDiff)
            {
                //Cast LIGHTNINGWAVE on a Random target
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_LIGHTNINGWAVE);

                m_uiLightningWave_Timer = 7000 + rand()%5000;
            }
            else
                m_uiLightningWave_Timer -= uiDiff;

            //Summon Druids
            if (!HealthAbovePct(100 - 25 * m_uiSummonDruidModifier))
            {
                DoScriptText(SAY_SUMMONDRUIDS, me);

                for (int i = 0; i < 10; ++i)
                    DoCast(me, SPELL_SUMMONDRUIDS, true);

                ++m_uiSummonDruidModifier;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new boss_ysondreAI(creature);
    }
};

// Summoned druid script
class mob_dementeddruids : public CreatureScript
{
public:
    mob_dementeddruids() : CreatureScript("mob_dementeddruids") { }

    struct mob_dementeddruidsAI : public ScriptedAI
    {
        mob_dementeddruidsAI(Creature *c) : ScriptedAI(c) {}

        uint32 m_uiMoonFire_Timer;

        void Reset()
        {
            m_uiMoonFire_Timer = 3000;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            //MoonFire_Timer
            if (m_uiMoonFire_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_MOONFIRE);
                m_uiMoonFire_Timer = 5000;
            }
            else
                m_uiMoonFire_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_dementeddruidsAI(creature);
    }
};

void AddSC_boss_ysondre()
{
    new boss_ysondre;
    new mob_dementeddruids;
}
