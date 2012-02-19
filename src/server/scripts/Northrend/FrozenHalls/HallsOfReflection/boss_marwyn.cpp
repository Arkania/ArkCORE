/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 *
 * Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "ScriptPCH.h"
#include "halls_of_reflection.h"

enum
{
    SAY_MARWYN_INTRO                        = -1594506,
    SAY_MARWYN_AGGRO                        = -1668060,
    SAY_MARWYN_DEATH                        = -1668063,
    SAY_MARWYN_SLAY01                       = -1668061,
    SAY_MARWYN_SLAY02                       = -1668062,
    SAY_MARWYN_SP01                         = -1668064,
    SAY_MARWYN_SP02                         = -1668065,

    SPELL_OBLITERATE_N                      = 72360,
    SPELL_OBLITERATE_H                      = 72434,
    SPELL_SHARED_SUFFERING_N                = 72368,
    SPELL_SHARED_SUFFERING_H                = 72369,
    SPELL_WELL_OF_CORRUPTION                = 72362,
    SPELL_CORRUPTED_FLESH_N                 = 72363,
    SPELL_CORRUPTED_FLESH_H                 = 72436,

    SPELL_BERSERK                           = 47008,
};

class boss_marwyn : public CreatureScript
{
public:
    boss_marwyn() : CreatureScript("boss_marwyn") { }

    struct boss_marwynAI : public ScriptedAI
    {
       boss_marwynAI(Creature* creature) : ScriptedAI(creature)
       {
            m_pInstance = (InstanceScript*)creature->GetInstanceScript();
            Regular = creature->GetMap()->IsRegularDifficulty();
            Reset();
       }

       InstanceScript* m_pInstance;
       bool Regular;
       bool m_bIsCall;

       //FUNCTIONS
       uint32 m_uiBerserkTimer;
       uint32 m_uiSharedSufferingTimer;
       uint32 m_uiWellTimer;
       uint32 m_uiTouchTimer;
       uint32 m_uiFleshTimer;
       uint32 m_uiObliterateTimer;
       uint32 m_uiSummonTimer;

       uint32 m_uiLocNo;
       uint64 m_uiSummonGUID[16];
       uint32 m_uiCheckSummon;

       uint8 SummonCount;

       uint32 summon;

       void Reset()
       {
          m_uiBerserkTimer = 180000;
          m_uiSharedSufferingTimer = 4000;
          m_uiWellTimer = 12000;
          m_uiTouchTimer = 8000;
          m_uiFleshTimer = 21000;
          m_uiObliterateTimer = 5000;
          SummonCount = 0;
          m_bIsCall = false;
          m_uiSummonTimer = 15000;
          me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
          me->SetVisible(false);
        }

        void Summon()
        {
             m_uiLocNo = 14;

             for(uint8 i = 0; i < 14; i++)
             {
                switch(urand(0,3))
                {
                   case 0:
                       switch(urand(1, 3))
                       {
                         case 1: summon = NPC_DARK_1; break;
                         case 2: summon = NPC_DARK_3; break;
                         case 3: summon = NPC_DARK_6; break;
                       }
                       break;
                   case 1:
                       switch(urand(1, 3))
                       {
                         case 1: summon = NPC_DARK_2; break;
                         case 2: summon = NPC_DARK_3; break;
                         case 3: summon = NPC_DARK_4; break;
                       }
                       break;
                   case 2:
                       switch(urand(1, 3))
                       {
                         case 1: summon = NPC_DARK_2; break;
                         case 2: summon = NPC_DARK_5; break;
                         case 3: summon = NPC_DARK_6; break;
                       }
                       break;
                   case 3:
                       switch(urand(1, 3))
                       {
                         case 1: summon = NPC_DARK_1; break;
                         case 2: summon = NPC_DARK_5; break;
                         case 3: summon = NPC_DARK_4; break;
                       }
                       break;
                 }

                 m_uiCheckSummon = 0;

                 if(Creature* Summon = me->SummonCreature(summon, SpawnLoc[m_uiLocNo].x, SpawnLoc[m_uiLocNo].y, SpawnLoc[m_uiLocNo].z, SpawnLoc[m_uiLocNo].o, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000))
                 {
                    m_uiSummonGUID[i] = Summon->GetGUID();
                    Summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    Summon->SetReactState(REACT_PASSIVE);
                    Summon->setFaction(974);
                 }
                 m_uiLocNo++;
             }
        }

        void CallFallSoldier()
        {
             for(uint8 i = 0; i < 4; i++)
             {
                if(Creature* Summon = m_pInstance->instance->GetCreature(m_uiSummonGUID[m_uiCheckSummon]))
                {
                   Summon->setFaction(14);
                   Summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                   Summon->SetReactState(REACT_AGGRESSIVE);
                   Summon->SetInCombatWithZone();
                }
                m_uiCheckSummon++;
             }
        }

        void JustDied(Unit* killer)
        {
          if(m_pInstance)
          {
             m_pInstance->SetData(TYPE_MARWYN, DONE);
             m_pInstance->SetData(TYPE_PHASE, 3);
          }

          DoScriptText(SAY_MARWYN_DEATH, me);
        }

        void KilledUnit(Unit* victim)
        {
            switch(urand(0,1))
            {
                case 0: DoScriptText(SAY_MARWYN_SLAY01, me); break;
                case 1: DoScriptText(SAY_MARWYN_SLAY02, me); break;
            }
        }

        void EnterCombat(Unit* victim)
        {
            if (!m_pInstance) return;
          //me->RemoveFlag(MOVEFLAG_WALK, MOVEMENTFLAG_WALK_MODE);
          DoScriptText(SAY_MARWYN_AGGRO, me);
        }

        void AttackStart(Unit* who)
        {
            if (!m_pInstance) return;

               if (m_pInstance->GetData(TYPE_MARWYN) != IN_PROGRESS)
                 return;

             ScriptedAI::AttackStart(who);
        }

       void UpdateAI(const uint32 uiDiff)
        {
            if(!m_pInstance) return;

            if (m_pInstance->GetData(TYPE_FALRIC) == SPECIAL)
            {
                if(!m_bIsCall)
                {
                   m_bIsCall = true;
                   Summon();
                }
            }

            if(m_pInstance->GetData(TYPE_MARWYN) == SPECIAL)
            {
               if(m_uiSummonTimer < uiDiff)
               {
                       ++SummonCount;
                       if(SummonCount == 1)
                          DoScriptText(SAY_MARWYN_INTRO, me);

                       if(SummonCount > 4)
                       {
                            m_pInstance->SetData(TYPE_MARWYN, IN_PROGRESS);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->SetInCombatWithZone();
                       }
                       else CallFallSoldier();
                       m_uiSummonTimer = 60000;
               } else m_uiSummonTimer -= uiDiff;
            }

            if(!UpdateVictim())
                return;

            if(m_uiObliterateTimer < uiDiff)
            {
                DoCast(me->getVictim(), Regular ? SPELL_OBLITERATE_N : SPELL_OBLITERATE_H);
                m_uiObliterateTimer = urand(8000, 12000);
            } else m_uiObliterateTimer -= uiDiff;

            if (m_uiWellTimer < uiDiff)
            {
                DoScriptText(SAY_MARWYN_SP02, me);
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                   DoCast(target, SPELL_WELL_OF_CORRUPTION);
                m_uiWellTimer= urand(25000, 30000);
            } else m_uiWellTimer -= uiDiff;

            if (m_uiSharedSufferingTimer < uiDiff)
            {
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                   DoCast(target, Regular ? SPELL_SHARED_SUFFERING_N : SPELL_SHARED_SUFFERING_H);
                m_uiSharedSufferingTimer = urand(15000, 20000);
            } else m_uiSharedSufferingTimer -= uiDiff;

            if (m_uiFleshTimer < uiDiff)
            {
                DoScriptText(SAY_MARWYN_SP01, me);
                if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    DoCast(target, Regular ? SPELL_CORRUPTED_FLESH_N : SPELL_CORRUPTED_FLESH_H);
                m_uiFleshTimer = urand(10000, 16000);
            } else m_uiFleshTimer -= uiDiff;

            if(m_uiBerserkTimer < uiDiff)
            {
                DoCast(me, SPELL_BERSERK);
                m_uiBerserkTimer = 180000;
            } else  m_uiBerserkTimer -= uiDiff;

            DoMeleeAttackIfReady();

            return;
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_marwynAI(creature);
    }
};

void AddSC_boss_marwyn()
{
    new boss_marwyn();
}