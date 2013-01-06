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
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

#define spell_chaos 77069 // Trait du Chaos
#define spell_chaos_H 89873
#define spell_vide 77030
#define spell_explo 76681
#define spell_graine 76870

#define SPELL_SUMMON_VIDE_PORTAL 72482
#define NPC_NIGHTMARE_PORTAL 38429 // Golem faisant pop le portail
#define SPELL_EFFECT_PORTAL 71994
#define NPC_PORTAL RAND(41208,41371,41374)
#define NPC_VIDE RAND(41208,41371,41374)

enum Texts
{
    SAY_AGGRO = 0,
    SAY_EVENT = 1,
    SAY_SLAY = 2,
    SAY_DEATH = 3,
};

const Position addSpawnLocations[] =
{
    {-525.337524f, -6.749335f, 343.933044f, 0.00f},
	{-485.971008f, -6.552939f, 343.932709f, 0.00f},
};

/********
** Setesh
*********/
class boss_setesh: public CreatureScript
{
public: 
 boss_setesh() : CreatureScript("boss_setesh") { }

 struct boss_seteshAI : public ScriptedAI
    {
        boss_seteshAI(Creature *c) : ScriptedAI(c), Summons(me) 
        {
            SetCombatMovement(false);
        }

		SummonList Summons;
		uint32 chaos;
		uint32 vide;
		uint32 explo;
		uint32 graine;
		uint32 SummonPortal;
		uint32 slay;

        void Reset()
        {
			chaos = 5000; 
			vide = 10000;
			explo = 7000;
			graine = 15000;
			SummonPortal = 30000;
			slay = 9000;
        }

        void EnterCombat(Unit* /*who*/) 
        {
			Talk(SAY_AGGRO);
        }

        void JustDied(Unit* /*killer*/)
        {
			Talk(SAY_DEATH);
        }
		
        void UpdateAI(const uint32 diff)
        {
                if (!UpdateVictim())
                    return;
           
            if (chaos <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, IsHeroic() ? spell_chaos_H : spell_chaos);
                chaos = 5000;
            } else chaos -= diff;
				
            if (vide <= diff)
            {
                DoCast(me->getVictim(), spell_vide);
                vide = 10000;
            } else vide -= diff;
				
            if (explo <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, spell_explo);
                explo = 7000;
            } else explo -= diff;
				
            if (graine <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, spell_graine);
                graine = 15000;
            } else graine -= diff;
			
			if (slay<= diff)
            {
                Talk(SAY_SLAY);
				slay   = 9000; 
            } else slay -= diff;
				
			if (SummonPortal <= diff)
            {
                Talk(SAY_EVENT);
				DoCast(SPELL_EFFECT_PORTAL);
                me->SummonCreature(NPC_VIDE, me->GetPositionX(), me->GetPositionY()+2, me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
				me->SummonCreature(NPC_PORTAL, me->GetPositionX(), me->GetPositionY()-2, me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
				SummonPortal = 30000;
            } else SummonPortal -= diff;
		}
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_seteshAI (pCreature);
    }

};

/*****************
** Portail du Vide
******************/
class npc_vide_portal : public CreatureScript
{
public:
    npc_vide_portal() : CreatureScript("npc_vide_portal") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_vide_portalAI(pCreature);
    }

    struct npc_vide_portalAI : public ScriptedAI
    {
        npc_vide_portalAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;

        SummonList Summons;

        uint8  m_CountMax;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            if (!IsHeroic())
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                m_CountMax = 1;
            }
            else
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                m_CountMax = 0;
            }
            Summons.DespawnAll();
			me->DespawnOrUnsummon(60000);
        }

        void JustSummoned(Creature* pSummoned)
        {
            Summons.Summon(pSummoned);
            pSummoned->SetCorpseDelay(0);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            //DoCast(SPELL_EFFECT_PORTAL);
			//me->SummonCreature(NPC_VIDE, TEMPSUMMON_CORPSE_DESPAWN);
            //me->SummonCreature(NPC_PORTAL, TEMPSUMMON_CORPSE_DESPAWN);
			//me->SummonCreature(NPC_VIDE, me->GetPositionX(), me->GetPositionY()+10, me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
        	//me->SummonCreature(NPC_PORTAL, me->GetPositionX(), me->GetPositionY()-10, me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
        }
    };

};

void AddSC_boss_setesh() 
{
    new boss_setesh();
	new npc_vide_portal();
}