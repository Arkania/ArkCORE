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
SDName: Boss Commander Stoutbeard
SDAuthor: Lopin
SD%Complete: 95
SDComment: Alliance commander - only for Horde. Timer adjustments needed. Whilrwind do ~half damage. Alliance Berserkers don't cast Bloodlust on friendly targets. Bad visual effect of charge.
SDCategory: Nexus, Nexus
Script Data End */

#include "ScriptPCH.h"
#include "nexus.h"

enum eStoutbeard
{
    //Spells
    SPELL_BATTLE_SHOUT                           = 31403,
    SPELL_CHARGE                                 = 60067,
    SPELL_FRIGHTENING_SHOUT                      = 19134,
    SPELL_WHIRLWIND                              = 38619,
    SPELL_WHIRLWIND_ADD                          = 38618,
    SPELL_FROZEN_PRISON                          = 47543, //Frozen block around them - on creature create and leave combat

    //Yells
    SAY_AGGRO                                    = -1576024,
    SAY_KILL                                     = -1576025,
    SAY_DEATH                                    = -1576026,

    //Add Spells
    //Alliance Cleric
    SPELL_POWER_WORD_SHIELD                      = 35944,
    SPELL_SHADOW_WORD_DEATH                      = 56920, //47697,
    SPELL_FLASH_HEAL                             = 17843,

    //Alliance Ranger
    SPELL_INCENDIARY_SHOT                        = 47777,
    SPELL_RAPID_SHOT                             = 48191,
    SPELL_SHOOT                                  = 15620,

    //Alliance Berserker
    SPELL_BLOODLUST                              = 21049,
    SPELL_FRENZY                                 = 47774,
    SPELL_WAR_STOMP                              = 38682,
};

class boss_commander_stoutbeard : public CreatureScript
{
public:
    boss_commander_stoutbeard() : CreatureScript("boss_commander_stoutbeard") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_commander_stoutbeardAI (creature);
    }

    struct boss_commander_stoutbeardAI : public BossAI
    {
        boss_commander_stoutbeardAI(Creature *pCreature) : BossAI(pCreature, DATA_COMMANDER)
        {
            me->CastSpell(me, SPELL_FROZEN_PRISON, true);
        }

        uint32 uiBattleShout_Timer;
        uint32 uiCharge_Timer;
        uint32 uiFrighteningShout_Timer;
        uint32 uiWhirlwind_Timer;
        uint32 uiWhirlwindAdd_Timer;

        bool IsWhirlwindTime;

        void Reset()
        {
            uiBattleShout_Timer = urand(200000,215000);
            uiCharge_Timer = urand(15000,17500);
            uiFrighteningShout_Timer = urand(10000,12500);
            uiWhirlwind_Timer = 10000;
            uiWhirlwindAdd_Timer = 10500;

            IsWhirlwindTime = false;

            me->CastSpell(me, SPELL_FROZEN_PRISON, true);

            if (instance)
                instance->SetData(DATA_COMMANDER, NOT_STARTED);
        }

        void EnterCombat(Unit * who)
        {
            DoScriptText(SAY_AGGRO, me);
            DoCast(me, SPELL_BATTLE_SHOUT);

            me->RemoveAurasDueToSpell(SPELL_FROZEN_PRISON);

            if (instance)
                instance->SetData(DATA_COMMANDER, IN_PROGRESS);
        }

        void KilledUnit(Unit * who)
        {
            DoScriptText(SAY_KILL, me);
        }

        void JustDied(Unit * /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (instance)
                instance->SetData(DATA_COMMANDER, DONE);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiCharge_Timer <= uiDiff)
            {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_CHARGE);
                uiCharge_Timer = urand(10500,12000);
            } else uiCharge_Timer -= uiDiff;

            if (uiBattleShout_Timer <= uiDiff)
            {
                DoCastAOE(SPELL_BATTLE_SHOUT);
                uiBattleShout_Timer = 200000;
            } else uiBattleShout_Timer -= uiDiff;

            if (uiFrighteningShout_Timer <= uiDiff)
            {
                DoCastAOE(SPELL_FRIGHTENING_SHOUT);
                uiFrighteningShout_Timer = urand(8000,10000);
            } else uiFrighteningShout_Timer -= uiDiff;

            if (uiWhirlwind_Timer <= uiDiff && !IsWhirlwindTime)
            {
                DoCastAOE(SPELL_WHIRLWIND);
                uiWhirlwindAdd_Timer = 500;
                IsWhirlwindTime = true;
            } else uiWhirlwind_Timer -= uiDiff;

            if (uiWhirlwindAdd_Timer <= uiDiff && IsWhirlwindTime)
            {
                DoCastAOE(SPELL_WHIRLWIND_ADD);
                uiWhirlwind_Timer = urand(10000,12500);
                IsWhirlwindTime = false;
            } else uiWhirlwindAdd_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_alliance_cleric : public CreatureScript
{
public:
    mob_alliance_cleric() : CreatureScript("mob_alliance_cleric") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_alliance_clericAI (pCreature);
    }

    struct mob_alliance_clericAI : public ScriptedAI
    {
        mob_alliance_clericAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            me->CastSpell(me, SPELL_FROZEN_PRISON, true);
        }

        uint32 uiFlashHeal_Timer;
        uint32 uiShadowWordDeath_Timer;
        uint32 uiPowerWordShield_Timer;

        void Reset()
        {
            uiFlashHeal_Timer = urand(9000,10500);
            uiShadowWordDeath_Timer = urand(5500,8500);
            uiPowerWordShield_Timer = urand(2000,4000);

            me->CastSpell(me, SPELL_FROZEN_PRISON, true);
        }

        void EnterCombat(Unit * who)
        {
            me->RemoveAurasDueToSpell(SPELL_FROZEN_PRISON);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (Unit *target = DoSelectLowestHpFriendly(40.0f))
            {
                if (uiFlashHeal_Timer <= uiDiff)
                {
                    DoCast(target, SPELL_FLASH_HEAL);
                    uiFlashHeal_Timer = urand(7000,8000);
                } else uiFlashHeal_Timer -= uiDiff;

                if (uiPowerWordShield_Timer <= uiDiff)
                {
                    DoCast(target, SPELL_POWER_WORD_SHIELD);
                    uiPowerWordShield_Timer = urand(9000,10000);
                } else uiPowerWordShield_Timer -= uiDiff;
            }

            if (uiShadowWordDeath_Timer <= uiDiff)
            {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    DoCast(target, SPELL_SHADOW_WORD_DEATH);
                uiShadowWordDeath_Timer = urand(4500,5500);
            } else uiShadowWordDeath_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_alliance_ranger : public CreatureScript
{
public:
    mob_alliance_ranger() : CreatureScript("mob_alliance_ranger") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_alliance_rangerAI (pCreature);
    }

    struct mob_alliance_rangerAI : public ScriptedAI
    {
        mob_alliance_rangerAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            me->CastSpell(me, SPELL_FROZEN_PRISON, true);
        }

        uint32 uiRapidShot_Timer;
        uint32 uiIncendiaryShot_Timer;
        uint32 uiShoot_Timer;

        uint8 i;

        void Reset()
        {
            uiRapidShot_Timer = urand(12500,14000);
            uiIncendiaryShot_Timer = urand(6500,8000);
            uiShoot_Timer = urand(2500,3000);

            me->CastSpell(me, SPELL_FROZEN_PRISON, true);
        }

        void EnterCombat(Unit * who)
        {
            me->RemoveAurasDueToSpell(SPELL_FROZEN_PRISON);
        }

        Unit* FindTarget()
        {
            i = 0;
            Unit *target;

            while (i < 5)
            {
                target = SelectTarget(SELECT_TARGET_TOPAGGRO, i);
                i++;

                if (!me->IsWithinDistInMap(target, 5.0f))
                    return target;
            }
            return 0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
            return;

            if (uiIncendiaryShot_Timer <= uiDiff)
            {
                if (Unit *target = FindTarget())
                    DoCast(target, SPELL_INCENDIARY_SHOT);
                uiIncendiaryShot_Timer = urand(6500,7500);
            } else uiIncendiaryShot_Timer -= uiDiff;

            if (uiShoot_Timer <= uiDiff)
            {
                if (Unit *target = FindTarget())
                    DoCast(target, SPELL_SHOOT);
                uiShoot_Timer = urand(2500,3000);
            } else uiShoot_Timer -= uiDiff;

            if (uiRapidShot_Timer <= uiDiff)
            {
                DoCastAOE(SPELL_RAPID_SHOT);
                uiRapidShot_Timer = urand(12500,14000);
            } else uiRapidShot_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_alliance_berserker : public CreatureScript
{
public:
    mob_alliance_berserker() : CreatureScript("mob_alliance_berserker") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_alliance_berserkerAI (pCreature);
    }

    struct mob_alliance_berserkerAI : public ScriptedAI
    {
        mob_alliance_berserkerAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            me->CastSpell(me, SPELL_FROZEN_PRISON, true);
        }

        uint32 uiBloodlust_Timer;
        uint32 uiFrenzy_Timer;
        uint32 uiWarStomp_Timer;

        void Reset()
        {
            uint32 uiBloolust_Timer = urand(5000,7500);
            uint32 uiFrenzy_Timer = urand(2500,4000);
            uint32 uiWarStomp_Timer = urand(6000,8000);

            me->CastSpell(me, SPELL_FROZEN_PRISON, true);
        }

        void EnterCombat(Unit * who)
        {
            me->RemoveAurasDueToSpell(SPELL_FROZEN_PRISON);
        }

        Creature* SelectRandomFriendlyMissingBuff(uint32 spell)
        {
            std::list<Creature *> lst = DoFindFriendlyMissingBuff(40.0f, spell);
            std::list<Creature *>::const_iterator itr = lst.begin();
            if (lst.empty())
                return NULL;
            advance(itr, rand()%lst.size());
            return (*itr);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
            return;

            if (uiBloodlust_Timer <= uiDiff)
            {
                if (Creature *target = SelectRandomFriendlyMissingBuff(SPELL_BLOODLUST)) //He should casts this only on allies, not on self...
                    DoCast(target, SPELL_BLOODLUST);
                uiBloodlust_Timer = urand(12000,15000);
            } else uiBloodlust_Timer -= uiDiff;

            if (uiFrenzy_Timer <= uiDiff)
            {
                DoCast(me, SPELL_FRENZY);
                uiFrenzy_Timer = 200000;
            } else uiFrenzy_Timer -= uiDiff;

            if (uiWarStomp_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_WAR_STOMP);
                uiWarStomp_Timer = urand(7000,8500);
            } else uiWarStomp_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_commander_stoutbeard()
{
    new boss_commander_stoutbeard();
    new mob_alliance_cleric();
    new mob_alliance_ranger();
    new mob_alliance_berserker();
}
