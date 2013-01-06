/*
 * Copyright (C) 2011 True Blood <http://www.trueblood-servers.com/>
 * By Asardial
 *
 * Copyright (C) 2011 - 2013 ArkCORE <http://www.arkania.net/>
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

#include "ScriptPCH.h"
#include "the_lost_city_of_tol_vir.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

#define SAY_AGGRO "Augh smart ! Augh already steal treasure while you no looking !"
#define SAY_DIED "Gwaaaaaaaaaaaahhh!!!"

enum Spells
{
    //Lockmaw
    SPELL_DUST_FLAIL		 = 81642,
    SPELL_SCENT_OF_BLOOD	 = 81690,
    H_SPELL_SCENT_OF_BLOOD	 = 89998,
    SPELL_VENOMOUS_RAGE		 = 81706,
    SPELL_VISCOUS_POISON	 = 81630,
    H_SPELL_VISCOUS_POISON	 = 90004,
    //Augh
    SPELL_H_FURY	= 23537,
    SPELL_H_FIRE_DRAGON	= 29964,
    SPELL_CLOUD	= 7964,
    SPELL_TEMPEST = 1680,
    SPELL_PARALYTIC_BLOW_DART	= 89989,
};

enum Events
{
    //Lockmaw
    EVENT_DUST_FLAIL,
    EVENT_SCENT_OF_BLOOD,
    EVENT_VISCOUS_POISON,
    //Augh
    EVENT_PARALYTIC_BLOW_DART,
    EVENT_CLOUD,
    EVENT_FIRE_DRAGON,
    EVENT_TEMPEST,
};

enum SummonIds
{
    NPC_FRENZIED_CROCOLISK   = 43658,
};

const Position SummonLocations[5] =
{
    {-11033.29f, -1674.57f, -0.56f, 1.09f},
    {-11029.84f, -1673.09f, -0.37f, 2.33f},
    {-11007.25f, -1666.37f, -0.23f, 2.46f},
    {-11006.83f, -1666.85f, -0.25f, 2.23f},
    {-11031.00f, -1653.59f,  0.86f, 2.42f},
};

class boss_lockmaw : public CreatureScript
{
public:
    boss_lockmaw() : CreatureScript("boss_lockmaw") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
       return new boss_lockmawAI(pCreature);
    }

    struct boss_lockmawAI : public ScriptedAI
    {
        boss_lockmawAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;
        SummonList Summons;
			
        bool Rage;

        void Reset ()
        {
            events.Reset();
            Summons.DespawnAll();
            Rage = false;
        }

        void JustDied(Unit* /*killer*/)
        {
            Summons.DespawnAll();
            if (IsHeroic())
            me->SummonCreature(49045, SummonLocations[4], TEMPSUMMON_MANUAL_DESPAWN);
        }

        void EnterCombat(Unit* /*Who*/)
        {
            DoZoneInCombat();
            EnterPhaseGround();
        }
			
        void EnterPhaseGround()
        {
            events.ScheduleEvent(EVENT_DUST_FLAIL, urand(15000, 22000));
            events.ScheduleEvent(EVENT_VISCOUS_POISON, 12000);
            events.ScheduleEvent(EVENT_SCENT_OF_BLOOD, 30000);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
            return;

            if (HealthBelowPct(30) && Rage == false)
            {
                DoCast(me, SPELL_VENOMOUS_RAGE);
                Rage = true;
            }
	
            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
            return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_DUST_FLAIL:
                    DoCast(me->getVictim(), SPELL_DUST_FLAIL);
                    events.ScheduleEvent(EVENT_DUST_FLAIL, urand(15000, 22000));
                    return;

                    case EVENT_VISCOUS_POISON:
                    DoCast(me->getVictim(), SPELL_VISCOUS_POISON);
                    events.ScheduleEvent(EVENT_VISCOUS_POISON, 12000);
                    return;

                    case EVENT_SCENT_OF_BLOOD:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, true))
                    DoCast(me->getVictim(), SPELL_SCENT_OF_BLOOD);
                    for(uint8 i=0; i<3; i++)
                    {
                        Creature* Crocolisk = me->SummonCreature(NPC_FRENZIED_CROCOLISK, SummonLocations[i], TEMPSUMMON_CORPSE_DESPAWN);
                        Crocolisk->AddThreat(me->getVictim(), 0.0f);
                        DoZoneInCombat(Crocolisk);
                    }
                    events.ScheduleEvent(EVENT_SCENT_OF_BLOOD, 30000);
                    return;

                    default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

/*************
** Augh Voleur
**************/
class mob_augh : public CreatureScript
{
public:
    mob_augh() : CreatureScript("mob_augh") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
       return new mob_aughAI(pCreature);
    }

    struct mob_aughAI : public ScriptedAI
    {
        mob_aughAI(Creature *c) : ScriptedAI(c) {}

        EventMap events;

        void Reset ()
        {
            me->RemoveAllAuras();
        }

        void EnterCombat(Unit* /*who*/) 
        {
            me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
            DoCast(me, SPELL_H_FURY);
            EnterPhaseGround();
        }
			
        void EnterPhaseGround()
        {
            events.ScheduleEvent(EVENT_PARALYTIC_BLOW_DART, 10000);
            events.ScheduleEvent(EVENT_CLOUD, 18000);
            events.ScheduleEvent(EVENT_FIRE_DRAGON, 40000);
            events.ScheduleEvent(EVENT_TEMPEST, 30000);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->MonsterYell(SAY_DIED, LANG_UNIVERSAL, NULL);
        }
			
        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
            return;
			
            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
            return;

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_PARALYTIC_BLOW_DART:
                    DoCast(me->getVictim(), SPELL_PARALYTIC_BLOW_DART);
                    events.ScheduleEvent(EVENT_PARALYTIC_BLOW_DART, 10000);
                    return;

                    case EVENT_CLOUD:
                    DoCast(me->getVictim(), SPELL_CLOUD);
                    events.ScheduleEvent(EVENT_CLOUD, 18000);
                    return;

                    case EVENT_FIRE_DRAGON:
                    DoCastVictim(SPELL_H_FIRE_DRAGON);
                    events.ScheduleEvent(EVENT_FIRE_DRAGON, 40000);
                    return;
					
                    case EVENT_TEMPEST:
                    DoCast(me, SPELL_TEMPEST);
                    events.ScheduleEvent(EVENT_TEMPEST, 30000);
                    return;

                    default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

/***********
** Crosilik
***********/

#define spell_vicious 81677
#define spell_vicious_H 89999

class mob_crosilik: public CreatureScript
{
public: 
 mob_crosilik() : CreatureScript("mob_crosilik") { } 

 struct mob_crosilikAI : public ScriptedAI
    {
        mob_crosilikAI(Creature *c) : ScriptedAI(c) {}

        uint32 vicious;
		
        void Reset()
        {
           vicious = 10000;        
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
            return;

            if (vicious<= diff)
            {
                if (Unit *pTar = SelectTarget(SELECT_TARGET_RANDOM, 0))
                DoCast(pTar, IsHeroic() ? spell_vicious_H : spell_vicious);
                vicious = 10000; 
            } else vicious -= diff; 

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_crosilikAI (pCreature);
    }
};

void AddSC_boss_lockmaw()
{
    new boss_lockmaw();
    new mob_augh();
    new mob_crosilik();
}