/*
 * Copyright (C) 2005-2011 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008-2011 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 *
 * Copyright (C) 2010-2011 ProjectSkyfire <http://www.projectskyfire.org/>
 * 
 * Copyright (C) 2011 ArkCORE <http://www.arkania.net/>
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
SDName: Boss_Gahz'ranka
SD%Complete: 85
SDComment: Massive Geyser with knockback not working. Spell buggy.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_FROSTBREATH            16099
#define SPELL_MASSIVEGEYSER          22421                  //Not working. Cause its a summon...
#define SPELL_SLAM                   24326

class boss_gahzranka : public CreatureScript
{
    public:

        boss_gahzranka()
            : CreatureScript("boss_gahzranka")
        {
        }

        struct boss_gahzrankaAI : public ScriptedAI
        {
            boss_gahzrankaAI(Creature *c) : ScriptedAI(c) {}
            uint32 Frostbreath_Timer;
            uint32 MassiveGeyser_Timer;
            uint32 Slam_Timer;

            void Reset()
            {
                Frostbreath_Timer = 8000;
                MassiveGeyser_Timer = 25000;
                Slam_Timer = 17000;
            }

            void EnterCombat(Unit * /*who*/)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //Frostbreath_Timer
                if (Frostbreath_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_FROSTBREATH);
                    Frostbreath_Timer = 7000 + rand()%4000;
                } else Frostbreath_Timer -= diff;

                //MassiveGeyser_Timer
                if (MassiveGeyser_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_MASSIVEGEYSER);
                    DoResetThreat();

                    MassiveGeyser_Timer = 22000 + rand()%10000;
                } else MassiveGeyser_Timer -= diff;

                //Slam_Timer
                if (Slam_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SLAM);
                    Slam_Timer = 12000 + rand()%8000;
                } else Slam_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_gahzrankaAI(creature);
        }
};

void AddSC_boss_gahzranka()
{
    new boss_gahzranka();
}