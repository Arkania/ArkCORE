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
SDName: Boss_Sulfuron_Harbringer
SD%Complete: 80
SDComment: Adds NYI
SDCategory: Molten Core
EndScriptData */

#include "ScriptPCH.h"
#include "molten_core.h"

#define SPELL_DARKSTRIKE            19777
#define SPELL_DEMORALIZINGSHOUT     19778
#define SPELL_INSPIRE               19779
#define SPELL_KNOCKDOWN             19780
#define SPELL_FLAMESPEAR            19781

//Adds Spells
#define SPELL_HEAL                  19775
#define SPELL_SHADOWWORDPAIN        19776
#define SPELL_IMMOLATE              20294

class boss_sulfuron : public CreatureScript
{
public:
    boss_sulfuron() : CreatureScript("boss_sulfuron") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_sulfuronAI (pCreature);
    }

    struct boss_sulfuronAI : public ScriptedAI
    {
        boss_sulfuronAI(Creature *c) : ScriptedAI(c) {}

        uint32 Darkstrike_Timer;
        uint32 DemoralizingShout_Timer;
        uint32 Inspire_Timer;
        uint32 Knockdown_Timer;
        uint32 Flamespear_Timer;

        void Reset()
        {
            Darkstrike_Timer=10000;                             //These times are probably wrong
            DemoralizingShout_Timer = 15000;
            Inspire_Timer = 13000;
            Knockdown_Timer = 6000;
            Flamespear_Timer = 2000;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //DemoralizingShout_Timer
            if (DemoralizingShout_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_DEMORALIZINGSHOUT);
                DemoralizingShout_Timer = 15000 + rand()%5000;
            } else DemoralizingShout_Timer -= diff;

            //Inspire_Timer
            if (Inspire_Timer <= diff)
            {
                Creature *pTarget = NULL;
                std::list<Creature*> pList = DoFindFriendlyMissingBuff(45.0f, SPELL_INSPIRE);
                if (!pList.empty())
                {
                    std::list<Creature*>::const_iterator i = pList.begin();
                    advance(i, (rand()%pList.size()));
                    pTarget = (*i);
                }

                if (pTarget)
                    DoCast(pTarget, SPELL_INSPIRE);

                DoCast(me, SPELL_INSPIRE);

                Inspire_Timer = 20000 + rand()%6000;
            } else Inspire_Timer -= diff;

            //Knockdown_Timer
            if (Knockdown_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_KNOCKDOWN);
                Knockdown_Timer = 12000 + rand()%3000;
            } else Knockdown_Timer -= diff;

            //Flamespear_Timer
            if (Flamespear_Timer <= diff)
            {
                Unit *pTarget = NULL;
                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if (pTarget) DoCast(pTarget, SPELL_FLAMESPEAR);

                Flamespear_Timer = 12000 + rand()%4000;
            } else Flamespear_Timer -= diff;

            //DarkStrike_Timer
            if (Darkstrike_Timer <= diff)
            {
                DoCast(me, SPELL_DARKSTRIKE);
                Darkstrike_Timer = 15000 + rand()%3000;
            } else Darkstrike_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_flamewaker_priest : public CreatureScript
{
public:
    mob_flamewaker_priest() : CreatureScript("mob_flamewaker_priest") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_flamewaker_priestAI (pCreature);
    }

    struct mob_flamewaker_priestAI : public ScriptedAI
    {
        mob_flamewaker_priestAI(Creature *c) : ScriptedAI(c) {}

        uint32 Heal_Timer;
        uint32 ShadowWordPain_Timer;
        uint32 Immolate_Timer;

        void Reset()
        {
            Heal_Timer = 15000+rand()%15000;
            ShadowWordPain_Timer = 2000;
            Immolate_Timer = 8000;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //Casting Heal to Sulfuron or other Guards.
            if (Heal_Timer <= diff)
            {
                Unit* pUnit = DoSelectLowestHpFriendly(60.0f, 1);
                if (!pUnit)
                    return;

                DoCast(pUnit, SPELL_HEAL);

                Heal_Timer = 15000+rand()%5000;
            } else Heal_Timer -= diff;

            //ShadowWordPain_Timer
            if (ShadowWordPain_Timer <= diff)
            {
                Unit *pTarget = NULL;
                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if (pTarget) DoCast(pTarget, SPELL_SHADOWWORDPAIN);

                ShadowWordPain_Timer = 18000+rand()%8000;
            } else ShadowWordPain_Timer -= diff;

            //Immolate_Timer
            if (Immolate_Timer <= diff)
            {
                Unit *pTarget = NULL;
                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if (pTarget) DoCast(pTarget, SPELL_IMMOLATE);

                Immolate_Timer = 15000+rand()%10000;
            } else Immolate_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_sulfuron()
{
    new boss_sulfuron();
    new mob_flamewaker_priest();
}
