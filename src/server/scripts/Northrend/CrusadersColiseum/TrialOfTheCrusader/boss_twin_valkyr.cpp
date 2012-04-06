/*
 * Copyright (C) 2008 - 2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2006-2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "trial_of_the_crusader.h"

enum Yells
{
    SAY_AGGRO           = -1649040,
    SAY_DEATH           = -1649041,
    SAY_BERSERK         = -1649042,
    EMOTE_SHIELD        = -1649043,
    SAY_SHIELD          = -1649044,
    SAY_KILL1           = -1649045,
    SAY_KILL2           = -1649046,
    EMOTE_LIGHT_VORTEX  = -1649047,
    SAY_LIGHT_VORTEX    = -1649048,
    EMOTE_DARK_VORTEX   = -1649049,
    SAY_DARK_VORTEX     = -1649050,
};

enum Equipment
{
    EQUIP_MAIN_1         = 49303,
    EQUIP_OFFHAND_1      = 47146,
    EQUIP_RANGED_1       = 47267,
    EQUIP_MAIN_2         = 45990,
    EQUIP_OFFHAND_2      = 47470,
    EQUIP_RANGED_2       = 47267,
    EQUIP_DONE           = EQUIP_NO_CHANGE,
};

enum Summons
{
    NPC_DARK_ESSENCE     = 34567,
    NPC_LIGHT_ESSENCE    = 34568,

    NPC_UNLEASHED_DARK   = 34628,
    NPC_UNLEASHED_LIGHT  = 34630,
};

enum BossSpells
{
    SPELL_LIGHT_TWIN_SPIKE_10_N      = 66075,
    SPELL_LIGHT_TWIN_SPIKE_25_N      = 67312,
    SPELL_LIGHT_TWIN_SPIKE_10_H      = 67313,
    SPELL_LIGHT_TWIN_SPIKE_25_H      = 67314,
    SPELL_LIGHT_SURGE_10_N           = 65766,
    SPELL_LIGHT_SURGE_25_N           = 67270,
    SPELL_LIGHT_SURGE_10_H           = 67271,
    SPELL_LIGHT_SURGE_25_H           = 67272,
    SPELL_LIGHT_SHIELD_10_N          = 65858,
    SPELL_LIGHT_SHIELD_25_N          = 67259,
    SPELL_LIGHT_SHIELD_10_H          = 67260,
    SPELL_LIGHT_SHIELD_25_H          = 67261,
    SPELL_LIGHT_TWIN_PACT_10_N       = 65876,
    SPELL_LIGHT_TWIN_PACT_25_N       = 67306,
    SPELL_LIGHT_TWIN_PACT_10_H       = 67307,
    SPELL_LIGHT_TWIN_PACT_25_H       = 67308,
    SPELL_LIGHT_VORTEX_10_N          = 66046,
    SPELL_LIGHT_VORTEX_25_N          = 67206,
    SPELL_LIGHT_VORTEX_10_H          = 67207,
    SPELL_LIGHT_VORTEX_25_H          = 67208,
    SPELL_LIGHT_TOUCH_10_H           = 67297,
    SPELL_LIGHT_TOUCH_25_H           = 67298,

    SPELL_DARK_TWIN_SPIKE_10_N       = 66069,
    SPELL_DARK_TWIN_SPIKE_25_N       = 67309,
    SPELL_DARK_TWIN_SPIKE_10_H       = 67310,
    SPELL_DARK_TWIN_SPIKE_25_H       = 67311,
    SPELL_DARK_SURGE_10_N            = 65768,
    SPELL_DARK_SURGE_25_N            = 67262,
    SPELL_DARK_SURGE_10_H            = 67263,
    SPELL_DARK_SURGE_25_H            = 67264,
    SPELL_DARK_SHIELD_10_N           = 65874,
    SPELL_DARK_SHIELD_25_N           = 67256,
    SPELL_DARK_SHIELD_10_H           = 67257,
    SPELL_DARK_SHIELD_25_H           = 67258,
    SPELL_DARK_TWIN_PACT_10_N        = 65875,
    SPELL_DARK_TWIN_PACT_25_N        = 67303,
    SPELL_DARK_TWIN_PACT_10_H        = 67304,
    SPELL_DARK_TWIN_PACT_25_H        = 67305,
    SPELL_DARK_VORTEX_10_N           = 66058,
    SPELL_DARK_VORTEX_25_N           = 67182,
    SPELL_DARK_VORTEX_10_H           = 67183,
    SPELL_DARK_VORTEX_25_H           = 67184,
    SPELL_DARK_TOUCH_10_H            = 67282,
    SPELL_DARK_TOUCH_25_H            = 67283,

    SPELL_TWIN_POWER                 = 65916,
    SPELL_LIGHT_ESSENCE_10_N         = 65686,
    SPELL_LIGHT_ESSENCE_25_N         = 67222,
    SPELL_LIGHT_ESSENCE_10_H         = 67223,
    SPELL_LIGHT_ESSENCE_25_H         = 67224,
    SPELL_DARK_ESSENCE_10_N          = 65684,
    SPELL_DARK_ESSENCE_25_N          = 67176,
    SPELL_DARK_ESSENCE_10_H          = 67177,
    SPELL_DARK_ESSENCE_25_H          = 67178,
    SPELL_BERSERK                    = 64238,
    SPELL_NONE                       = 0,

    SPELL_TWIN_EMPATHY_1             = 66132,
    SPELL_TWIN_EMPATHY_2             = 66133,

    SPELL_EMPOWERED_DARK             = 67215,
    SPELL_EMPOWERED_LIGHT            = 67218,
    SPELL_UNLEASHED_DARK_10          = 67172,
    SPELL_UNLEASHED_DARK_25          = 67173,
    SPELL_UNLEASHED_LIGHT_10         = 65795,
    SPELL_UNLEASHED_LIGHT_25         = 67239,

    SPELL_POWERING_UP_10_N           = 67590,
    SPELL_POWERING_UP_25_N           = 67602,
    SPELL_POWERING_UP_10_H           = 67603,
    SPELL_POWERING_UP_25_H           = 67604,

    SPELL_SURGE_OF_SPEED_10_N        = 65828,
    SPELL_SURGE_OF_SPEED_25_N        = 67241,
    SPELL_SURGE_OF_SPEED_10_H        = 67242,
    SPELL_SURGE_OF_SPEED_25_H        = 67243,
    SPELL_EMPOWERED_DARKNESS_10_N    = 65724,
    SPELL_EMPOWERED_DARKNESS_25_N    = 67213,
    SPELL_EMPOWERED_DARKNESS_10_H    = 67214,
    SPELL_EMPOWERED_DARKNESS_25_H    = 67215,
    SPELL_EMPOWERED_LIGHT_10_N       = 65748,
    SPELL_EMPOWERED_LIGHT_25_N       = 67216,
    SPELL_EMPOWERED_LIGHT_10_H       = 67217,
    SPELL_EMPOWERED_LIGHT_25_H       = 67218,
};

enum Actions
{
    ACTION_VORTEX		= 1,
    ACTION_PACT			= 2,
};

/*######
## boss_twin_base
######*/

struct boss_twin_baseAI : public ScriptedAI
{
    boss_twin_baseAI(Creature* creature) : ScriptedAI(creature), Summons(me)
    {
        m_pInstance = (InstanceScript*)creature->GetInstanceScript();
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
    }

    InstanceScript* m_pInstance;
    SummonList Summons;

    uint8  m_uiStage;
    bool   m_bIsBerserk;
    uint8  m_uiWaveCount;
    uint32 m_uiColorballsTimer;
    uint32 m_uiSpecialAbilityTimer;
    uint32 m_uiSpikeTimer;
    uint32 m_uiTouchTimer;
    uint32 m_uiBerserkTimer;

    int32 m_uiVortexSay;
    int32 m_uiVortexEmote;
    uint32 m_uiSisterNpcId;
    uint32 m_uiColorballNpcId;
    uint32 m_uiEssenceNpcId;
    uint32 m_uiMyEssenceSpellId;
    uint32 m_uiOtherEssenceSpellId;
    uint32 m_uiEmpoweredWeaknessSpellId;
    uint32 m_uiSurgeSpellId;
    uint32 m_uiVortexSpellId;
    uint32 m_uiShieldSpellId;
    uint32 m_uiTwinPactSpellId;
    uint32 m_uiSpikeSpellId;
    uint32 m_uiTouchSpellId;

    Position HomeLocation;
    Position EssenceLocation[2];

    void Reset() {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_PASSIVE);
        /* Uncomment this once that they are flying above the ground
        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        me->SetFlying(true); */
        m_bIsBerserk = false;

        m_uiWaveCount = 1;
        m_uiColorballsTimer = 15*IN_MILLISECONDS;
        m_uiSpecialAbilityTimer = MINUTE*IN_MILLISECONDS;
        m_uiSpikeTimer = 20*IN_MILLISECONDS;
        m_uiTouchTimer = urand(10, 15)*IN_MILLISECONDS;
        m_uiBerserkTimer = IsHeroic() ? 6*MINUTE*IN_MILLISECONDS : 10*MINUTE*IN_MILLISECONDS;

        Summons.DespawnAll();
    }

    void JustReachedHome()
    {
        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_VALKIRIES, FAIL);
            m_pInstance->SetData(DATA_HEALTH_TWIN_SHARED, me->GetMaxHealth());
        }
        me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE) return;

        switch (uiId)
        {
            case 0:
                me->GetMotionMaster()->MovePoint(1, HomeLocation.GetPositionX(), HomeLocation.GetPositionY(), HomeLocation.GetPositionZ());
                me->SetHomePosition(HomeLocation);
                break;
            case 1:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetInCombatWithZone();
                break;
        }
    }

    void KilledUnit(Unit* who)
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            DoScriptText(urand(0, 1) ? SAY_KILL1 : SAY_KILL2, me);
            if (m_pInstance)
                m_pInstance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE, 0);
        }
    }

    void JustSummoned(Creature* summoned)
    {
        switch (summoned->GetEntry())
        {
            case NPC_UNLEASHED_DARK:
            case NPC_UNLEASHED_LIGHT:
                summoned->SetCorpseDelay(0);
                break;
        }
        Summons.Summon(summoned);
    }

    void SummonedCreatureDespawn(Creature* summoned)
    {
        switch (summoned->GetEntry())
        {
            case NPC_LIGHT_ESSENCE:
            case NPC_DARK_ESSENCE:
                Map* pMap = me->GetMap();
                Map::PlayerList const &lPlayers = pMap->GetPlayers();
                for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                {
                    Unit* player = itr->getSource();
                    if (!player)
                        continue;
                    if (player->isAlive())
                    {
                        if (summoned->GetEntry() == NPC_LIGHT_ESSENCE)
                            player->RemoveAurasDueToSpell(RAID_MODE(SPELL_LIGHT_ESSENCE_10_N, SPELL_LIGHT_ESSENCE_25_N, SPELL_LIGHT_ESSENCE_10_H, SPELL_LIGHT_ESSENCE_25_H));
                        if (summoned->GetEntry() == NPC_DARK_ESSENCE)
                            player->RemoveAurasDueToSpell(RAID_MODE(SPELL_DARK_ESSENCE_10_N, SPELL_DARK_ESSENCE_25_N, SPELL_DARK_ESSENCE_10_H, SPELL_DARK_ESSENCE_25_H));
                    }
                }
                break;
        }
        Summons.Despawn(summoned);
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
    {
        if (!me || !me->isAlive())
            return;

        if (pDoneBy->GetGUID() == me->GetGUID())
            return;

        if (pDoneBy->GetTypeId() == TYPEID_PLAYER)
        {
            if (pDoneBy->HasAura(m_uiOtherEssenceSpellId))
                uiDamage += uiDamage/2;
            if (pDoneBy->HasAura(m_uiEmpoweredWeaknessSpellId))
                uiDamage += uiDamage;
            else
                if (pDoneBy->HasAura(m_uiMyEssenceSpellId))
                    uiDamage /= 2;
        }

        if (m_pInstance)
            m_pInstance->SetData(DATA_HEALTH_TWIN_SHARED, me->GetHealth() >= uiDamage ? me->GetHealth() - uiDamage : 0);
    }

	void SpellHit(Unit* caster, const SpellEntry* spell) {
		if (caster->ToCreature() == me)
			if (spell->Effect[0] == 136) //Effect Heal
				if (m_pInstance)
					m_pInstance->SetData(
							DATA_HEALTH_TWIN_SHARED,
							me->GetHealth()
									+ me->CountPctFromMaxHealth(
											spell->EffectBasePoints[0]));
	}

    void SummonColorballs(uint8 quantity)
    {
        float x0 = ToCCommonLoc[1].GetPositionX(), y0 = ToCCommonLoc[1].GetPositionY(), r = 47.0f;
        float y = y0;
        for (uint8 i = 0; i < quantity; i++)
        {
            float x = float(urand(uint32(x0 - r), uint32(x0 + r)));
            if (urand(0, 1))
                y = y0 + sqrt(pow(r, 2) - pow((x-x0), 2));
            else
                y = y0 - sqrt(pow(r, 2) - pow((x-x0), 2));
            me->SummonCreature(m_uiColorballNpcId, x, y, me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
        }
    }

    void JustDied(Unit* /*killer*/)
    {
        DoScriptText(SAY_DEATH, me);
        if (m_pInstance)
        {
            m_pInstance->SetData(DATA_HEALTH_TWIN_SHARED, 0);
            if (Creature* pSister = GetSister())
            {
                if (!pSister->isAlive())
                {
                    m_pInstance->SetData(TYPE_VALKIRIES, DONE);
                    Summons.DespawnAll();
                }
                else m_pInstance->SetData(TYPE_VALKIRIES, SPECIAL);
            }
        }
        Summons.DespawnAll();
    }

    // Called when sister pointer needed
    Creature* GetSister()
    {
        return Unit::GetCreature((*me), m_pInstance->GetData64(m_uiSisterNpcId));
    }

    void EnterCombat(Unit* /*who*/)
    {
        me->SetInCombatWithZone();
        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_VALKIRIES, IN_PROGRESS);
            m_pInstance->SetData(DATA_HEALTH_TWIN_SHARED, me->GetMaxHealth());
        }
        if (me->isAlive())
        {
            me->SummonCreature(m_uiEssenceNpcId, EssenceLocation[0].GetPositionX(), EssenceLocation[0].GetPositionY(), EssenceLocation[0].GetPositionZ());
            me->SummonCreature(m_uiEssenceNpcId, EssenceLocation[1].GetPositionX(), EssenceLocation[1].GetPositionY(), EssenceLocation[1].GetPositionZ());
        }
        DoScriptText(SAY_AGGRO, me);
        DoCast(me, m_uiSurgeSpellId);
    }

    void DoAction(int32 const action)
    {
        switch (action)
        {
            case ACTION_VORTEX:
                m_uiStage = me->GetEntry() == NPC_LIGHTBANE ? 2 : 1;
                break;
            case ACTION_PACT:
                m_uiStage = me->GetEntry() == NPC_LIGHTBANE ? 1 : 2;
                DoCast(me, SPELL_TWIN_POWER);
                break;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!m_pInstance || !UpdateVictim())
            return;

        if (m_pInstance->GetData(DATA_HEALTH_TWIN_SHARED) != 0)
            me->SetHealth(m_pInstance->GetData(DATA_HEALTH_TWIN_SHARED));
        else
            me->SetHealth(1);

        switch (m_uiStage)
        {
            case 0:
                break;
            case 1: // Vortex
                if (m_uiSpecialAbilityTimer <= uiDiff)
                {
                    if (Creature* pSister = GetSister())
					{
                        pSister->AI()->DoAction(ACTION_VORTEX);
					}
                    DoScriptText(m_uiVortexEmote, me);
                    DoScriptText(m_uiVortexSay, me);
                    DoCastAOE(m_uiVortexSpellId);
                    m_uiStage = 0;
                    m_uiSpecialAbilityTimer = 45*IN_MILLISECONDS;
                }
                else
				{
                    m_uiSpecialAbilityTimer -= uiDiff;
				}
                break;
            case 2: // Shield+Pact
                if (m_uiSpecialAbilityTimer <= uiDiff)
                {
                    if (Creature* pSister = GetSister())
					{
                        pSister->AI()->DoAction(ACTION_PACT);
					}
                    DoScriptText(EMOTE_SHIELD, me);
                    DoScriptText(SAY_SHIELD, me);
                    DoCast(me, m_uiShieldSpellId);
                    DoCast(me, m_uiTwinPactSpellId);
                    m_uiStage = 0;
                    m_uiSpecialAbilityTimer = 45*IN_MILLISECONDS;
                }
                else
				{
                    m_uiSpecialAbilityTimer -= uiDiff;
				}
                break;
            default:
                break;
        }

        if (m_uiSpikeTimer <= uiDiff)
        {
            DoCastVictim(m_uiSpikeSpellId);
            m_uiSpikeTimer = 20*IN_MILLISECONDS;
        }
        else
            m_uiSpikeTimer -= uiDiff;

        if (IsHeroic() && m_uiTouchTimer <= uiDiff)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true, m_uiOtherEssenceSpellId))
                me->CastCustomSpell(m_uiTouchSpellId, SPELLVALUE_MAX_TARGETS, 1, target, false);
            m_uiTouchTimer = urand(10, 15)*IN_MILLISECONDS;
        }
        else
            m_uiTouchTimer -= uiDiff;

        if (m_uiColorballsTimer <= uiDiff)
        {
            if (m_uiWaveCount >= 2)
            {
                SummonColorballs(12);
                m_uiWaveCount = 0;
            }
            else
            {
                SummonColorballs(2);
                m_uiWaveCount++;
            }
            m_uiColorballsTimer = 15*IN_MILLISECONDS;
        }
        else
            m_uiColorballsTimer -= uiDiff;

        if (!m_bIsBerserk && m_uiBerserkTimer <= uiDiff)
        {
            DoCast(me, SPELL_BERSERK);
            DoScriptText(SAY_BERSERK, me);
            m_bIsBerserk = true;
        }
        else
		{
            m_uiBerserkTimer -= uiDiff;
		}
        DoMeleeAttackIfReady();
    }
};

/*######
## boss_fjola
######*/

class boss_fjola : public CreatureScript
{
public:
    boss_fjola() : CreatureScript("boss_fjola") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_fjolaAI(creature);
    }

    struct boss_fjolaAI : public boss_twin_baseAI
    {
        boss_fjolaAI(Creature* creature) : boss_twin_baseAI(creature) {}

        void Reset() {
            boss_twin_baseAI::Reset();
            SetEquipmentSlots(false, EQUIP_MAIN_1, EQUIP_OFFHAND_1, EQUIP_RANGED_1);
            m_uiStage = 0;
            m_uiVortexEmote = EMOTE_LIGHT_VORTEX;
            m_uiVortexSay = SAY_LIGHT_VORTEX;
            m_uiSisterNpcId = NPC_DARKBANE;
            m_uiColorballNpcId = NPC_UNLEASHED_LIGHT;
            m_uiEssenceNpcId = NPC_LIGHT_ESSENCE;
            m_uiMyEssenceSpellId = RAID_MODE(SPELL_LIGHT_ESSENCE_10_N, SPELL_LIGHT_ESSENCE_25_N, SPELL_LIGHT_ESSENCE_10_H, SPELL_LIGHT_ESSENCE_25_H);
            m_uiOtherEssenceSpellId = RAID_MODE(SPELL_DARK_ESSENCE_10_N, SPELL_DARK_ESSENCE_25_N, SPELL_DARK_ESSENCE_10_H, SPELL_DARK_ESSENCE_25_H);
            m_uiEmpoweredWeaknessSpellId = SPELL_EMPOWERED_DARK;
            m_uiSurgeSpellId = RAID_MODE(SPELL_LIGHT_SURGE_10_N, SPELL_LIGHT_SURGE_25_N, SPELL_LIGHT_SURGE_10_H, SPELL_LIGHT_SURGE_25_H);
            m_uiVortexSpellId = RAID_MODE(SPELL_LIGHT_VORTEX_10_N, SPELL_LIGHT_VORTEX_25_N, SPELL_LIGHT_VORTEX_10_H, SPELL_LIGHT_VORTEX_25_H);
            m_uiShieldSpellId = RAID_MODE(SPELL_LIGHT_SHIELD_10_N, SPELL_LIGHT_SHIELD_25_N, SPELL_LIGHT_SHIELD_10_H, SPELL_LIGHT_SHIELD_25_H);
            m_uiTwinPactSpellId = RAID_MODE(SPELL_LIGHT_TWIN_PACT_10_N, SPELL_LIGHT_TWIN_PACT_25_N, SPELL_LIGHT_TWIN_PACT_10_H, SPELL_LIGHT_TWIN_PACT_25_H);
            m_uiTouchSpellId = RAID_MODE(SPELL_LIGHT_TOUCH_10_H, SPELL_LIGHT_TOUCH_25_H, SPELL_LIGHT_TOUCH_10_H, SPELL_LIGHT_TOUCH_25_H);
            m_uiSpikeSpellId = RAID_MODE(SPELL_LIGHT_TWIN_SPIKE_10_N, SPELL_LIGHT_TWIN_SPIKE_25_N, SPELL_LIGHT_TWIN_SPIKE_10_H, SPELL_LIGHT_TWIN_SPIKE_25_H);

            HomeLocation = ToCCommonLoc[8];
            EssenceLocation[0] = TwinValkyrsLoc[2];
            EssenceLocation[1] = TwinValkyrsLoc[3];

            if (m_pInstance)
            {
                m_pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT,  EVENT_START_TWINS_FIGHT);
            }
        }

        void EnterCombat(Unit* who)
        {
            boss_twin_baseAI::EnterCombat(who);
            if (m_pInstance)
            {
                m_pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT,  EVENT_START_TWINS_FIGHT);
               if (Creature* pEydis = Unit::GetCreature(*me, m_pInstance->GetData64(NPC_DARKBANE)))
				   me->AddAura(SPELL_TWIN_EMPATHY_1, pEydis);
            }
        }
    };
};

/*######
## boss_eydis
######*/

class boss_eydis : public CreatureScript
{
public:
    boss_eydis() : CreatureScript("boss_eydis") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_eydisAI(creature);
    }

    struct boss_eydisAI : public boss_twin_baseAI
    {
        boss_eydisAI(Creature* creature) : boss_twin_baseAI(creature) {}

        void Reset()
		{
            boss_twin_baseAI::Reset();
            SetEquipmentSlots(false, EQUIP_MAIN_2, EQUIP_OFFHAND_2, EQUIP_RANGED_2);
            m_uiStage = 1;
            m_uiVortexEmote = EMOTE_DARK_VORTEX;
            m_uiVortexSay = SAY_DARK_VORTEX;
            m_uiSisterNpcId = NPC_LIGHTBANE;
            m_uiColorballNpcId = NPC_UNLEASHED_DARK;
            m_uiEssenceNpcId = NPC_DARK_ESSENCE;
            m_uiMyEssenceSpellId = RAID_MODE(SPELL_DARK_ESSENCE_10_N, SPELL_DARK_ESSENCE_25_N, SPELL_DARK_ESSENCE_10_H, SPELL_DARK_ESSENCE_25_H);
            m_uiOtherEssenceSpellId = RAID_MODE(SPELL_LIGHT_ESSENCE_10_N, SPELL_LIGHT_ESSENCE_25_N, SPELL_LIGHT_ESSENCE_10_H, SPELL_LIGHT_ESSENCE_25_H);
            m_uiEmpoweredWeaknessSpellId = SPELL_EMPOWERED_LIGHT;
            m_uiSurgeSpellId = RAID_MODE(SPELL_DARK_SURGE_10_N, SPELL_DARK_SURGE_25_N, SPELL_DARK_SURGE_10_H, SPELL_DARK_SURGE_25_H);
            m_uiVortexSpellId = RAID_MODE(SPELL_DARK_VORTEX_10_N, SPELL_DARK_VORTEX_25_N, SPELL_DARK_VORTEX_10_H, SPELL_DARK_VORTEX_25_H);
            m_uiShieldSpellId = RAID_MODE(SPELL_DARK_SHIELD_10_N, SPELL_DARK_SHIELD_25_N, SPELL_DARK_SHIELD_10_H, SPELL_DARK_SHIELD_25_H);
            m_uiTwinPactSpellId = RAID_MODE(SPELL_DARK_TWIN_PACT_10_N, SPELL_DARK_TWIN_PACT_25_N, SPELL_DARK_TWIN_PACT_10_H, SPELL_DARK_TWIN_PACT_25_H);
            m_uiTouchSpellId = RAID_MODE(SPELL_DARK_TOUCH_10_H, SPELL_DARK_TOUCH_25_H, SPELL_DARK_TOUCH_10_H, SPELL_DARK_TOUCH_25_H);
            m_uiSpikeSpellId = RAID_MODE(SPELL_DARK_TWIN_SPIKE_10_N, SPELL_DARK_TWIN_SPIKE_25_N, SPELL_DARK_TWIN_SPIKE_10_H, SPELL_DARK_TWIN_SPIKE_25_H);

            HomeLocation = ToCCommonLoc[9];
            EssenceLocation[0] = TwinValkyrsLoc[0];
            EssenceLocation[1] = TwinValkyrsLoc[1];
        }
        void EnterCombat(Unit* pWho)
        {
            boss_twin_baseAI::EnterCombat(pWho);
            if (m_pInstance)
                if (Creature* pFjola = Unit::GetCreature(*me, m_pInstance->GetData64(NPC_LIGHTBANE)))
                    me->AddAura(SPELL_TWIN_EMPATHY_2, pFjola);
        }
    };
};

class mob_essence_of_twin : public CreatureScript
{
public:
    mob_essence_of_twin() : CreatureScript("mob_essence_of_twin") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        switch (creature->GetEntry())
        {
            case NPC_LIGHT_ESSENCE:
                if (player->HasAura(SPELL_DARK_ESSENCE_10_N))
                    player->RemoveAura(SPELL_DARK_ESSENCE_10_N);
                if (player->HasAura(SPELL_DARK_ESSENCE_25_N))
                    player->RemoveAura(SPELL_DARK_ESSENCE_25_N);
                if (player->HasAura(SPELL_DARK_ESSENCE_10_H))
                    player->RemoveAura(SPELL_DARK_ESSENCE_10_H);
                if (player->HasAura(SPELL_DARK_ESSENCE_25_H))
                    player->RemoveAura(SPELL_DARK_ESSENCE_25_H);
                switch(player->GetDifficulty(true))
                {
                    case RAID_DIFFICULTY_10MAN_NORMAL:
                        player->CastSpell(player, SPELL_LIGHT_ESSENCE_10_N, false);
                        break;
                    case RAID_DIFFICULTY_25MAN_NORMAL:
                        player->CastSpell(player, SPELL_LIGHT_ESSENCE_25_N, false);
                        break;
                    case RAID_DIFFICULTY_10MAN_HEROIC:
                        player->CastSpell(player, SPELL_LIGHT_ESSENCE_10_H, false);
                        break;
                    case RAID_DIFFICULTY_25MAN_HEROIC:
                        player->CastSpell(player, SPELL_LIGHT_ESSENCE_25_H, false);
                        break;
                    default:
                        break;
                }
                break;
            case NPC_DARK_ESSENCE:
                if (player->HasAura(SPELL_LIGHT_ESSENCE_10_N))
                    player->RemoveAura(SPELL_LIGHT_ESSENCE_10_N);
                if (player->HasAura(SPELL_LIGHT_ESSENCE_25_N))
                    player->RemoveAura(SPELL_LIGHT_ESSENCE_25_N);
                if (player->HasAura(SPELL_LIGHT_ESSENCE_10_H))
                    player->RemoveAura(SPELL_LIGHT_ESSENCE_10_H);
                if (player->HasAura(SPELL_LIGHT_ESSENCE_25_H))
                    player->RemoveAura(SPELL_LIGHT_ESSENCE_25_H);
                switch(player->GetDifficulty(true))
                {
                    case RAID_DIFFICULTY_10MAN_NORMAL:
                        player->CastSpell(player, SPELL_DARK_ESSENCE_10_N, false);
                        break;
                    case RAID_DIFFICULTY_25MAN_NORMAL:
                        player->CastSpell(player, SPELL_DARK_ESSENCE_25_N, false);
                        break;
                    case RAID_DIFFICULTY_10MAN_HEROIC:
                        player->CastSpell(player, SPELL_DARK_ESSENCE_10_H, false);
                        break;
                    case RAID_DIFFICULTY_25MAN_HEROIC:
                        player->CastSpell(player, SPELL_DARK_ESSENCE_25_H, false);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        player->CLOSE_GOSSIP_MENU();
        return true;
    }
};

struct mob_unleashed_ballAI : public ScriptedAI
{
    mob_unleashed_ballAI(Creature* creature) : ScriptedAI(creature)
    {
        m_pInstance = (InstanceScript*)creature->GetInstanceScript();
    }

    InstanceScript* m_pInstance;
    uint32 m_uiRangeCheckTimer;

    void MoveToNextPoint()
    {
        float x0 = ToCCommonLoc[1].GetPositionX(), y0 = ToCCommonLoc[1].GetPositionY(), r = 47.0f;
        float y = y0;
        float x = float(urand(uint32(x0 - r), uint32(x0 + r)));
        if (urand(0, 1))
            y = y0 + sqrt(pow(r, 2) - pow((x-x0), 2));
        else
            y = y0 - sqrt(pow(r, 2) - pow((x-x0), 2));
        me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());
    }

    void Reset()
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        me->SetFlying(true);
        SetCombatMovement(false);
        MoveToNextPoint();
        m_uiRangeCheckTimer = IN_MILLISECONDS;
    }

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE) return;

        switch (uiId)
        {
            case 0:
                if (urand(0, 3) == 0)
                    MoveToNextPoint();
                else
                    me->DisappearAndDie();
                break;
        }
    }
};

class mob_unleashed_dark : public CreatureScript
{
public:
    mob_unleashed_dark() : CreatureScript("mob_unleashed_dark") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_unleashed_darkAI(creature);
    }

    struct mob_unleashed_darkAI : public mob_unleashed_ballAI
    {
        mob_unleashed_darkAI(Creature* creature) : mob_unleashed_ballAI(creature) {}

        void SpellHitTarget(Unit* pWho, const SpellEntry* spell)
        {
            if (spell->Id == RAID_MODE(SPELL_UNLEASHED_DARK_10, SPELL_UNLEASHED_DARK_25, SPELL_UNLEASHED_DARK_10, SPELL_UNLEASHED_DARK_25)
                && pWho->HasAura(RAID_MODE(SPELL_DARK_ESSENCE_10_N, SPELL_DARK_ESSENCE_25_N, SPELL_DARK_ESSENCE_10_H, SPELL_DARK_ESSENCE_25_H)))
            {
                pWho->CastSpell(pWho, RAID_MODE(SPELL_POWERING_UP_10_N, SPELL_POWERING_UP_25_N, SPELL_POWERING_UP_10_H, SPELL_POWERING_UP_25_H), true);
                int n = 5 + rand() % 8;
                if(Aura * aura = pWho->GetAura(RAID_MODE(SPELL_POWERING_UP_10_N, SPELL_POWERING_UP_25_N, SPELL_POWERING_UP_10_H, SPELL_POWERING_UP_25_H)))
                {
                    if(aura->GetStackAmount()+n > 100 || aura->GetStackAmount() == 100)
                    {
                        aura->SetStackAmount(100);
                        pWho->RemoveAurasDueToSpell(RAID_MODE(SPELL_POWERING_UP_10_N, SPELL_POWERING_UP_25_N, SPELL_POWERING_UP_10_H, SPELL_POWERING_UP_25_H));
                        pWho->CastSpell(pWho, RAID_MODE(SPELL_EMPOWERED_DARKNESS_10_N, SPELL_EMPOWERED_DARKNESS_25_N, SPELL_EMPOWERED_DARKNESS_10_H, SPELL_EMPOWERED_DARKNESS_25_H), true);
                        if (rand()%100 < 30)
                            pWho->CastSpell(pWho, RAID_MODE(SPELL_SURGE_OF_SPEED_10_N, SPELL_SURGE_OF_SPEED_25_N, SPELL_SURGE_OF_SPEED_10_H, SPELL_SURGE_OF_SPEED_25_H), true);
                    }
                    else
                    aura->SetStackAmount(aura->GetStackAmount()+n);
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (m_uiRangeCheckTimer < uiDiff)
            {
                if (Unit* target = me->SelectNearestTarget(2.0f))
                    if (target->GetTypeId() == TYPEID_PLAYER && target->isAlive())
                    {
                        DoCastAOE(RAID_MODE(SPELL_UNLEASHED_DARK_10, SPELL_UNLEASHED_DARK_25, SPELL_UNLEASHED_DARK_10, SPELL_UNLEASHED_DARK_25));
                        if (target->HasAura(RAID_MODE(SPELL_DARK_ESSENCE_10_N, SPELL_DARK_ESSENCE_25_N, SPELL_DARK_ESSENCE_10_H, SPELL_DARK_ESSENCE_25_H)))
                            me->CastSpell(target, RAID_MODE(SPELL_POWERING_UP_10_N, SPELL_POWERING_UP_25_N, SPELL_POWERING_UP_10_H, SPELL_POWERING_UP_25_H), true);
                        me->GetMotionMaster()->MoveIdle();
                        me->DespawnOrUnsummon(1000);
                    }
                m_uiRangeCheckTimer = IN_MILLISECONDS;
            }
            else m_uiRangeCheckTimer -= uiDiff;
        }
    };
};

class mob_unleashed_light : public CreatureScript
{
public:
    mob_unleashed_light() : CreatureScript("mob_unleashed_light") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_unleashed_lightAI(creature);
    }

    struct mob_unleashed_lightAI : public mob_unleashed_ballAI
    {
        mob_unleashed_lightAI(Creature* creature) : mob_unleashed_ballAI(creature) {}

        void SpellHitTarget(Unit* pWho, const SpellEntry* spell)
        {
            if (spell->Id == RAID_MODE(SPELL_UNLEASHED_LIGHT_10, SPELL_UNLEASHED_LIGHT_25, SPELL_UNLEASHED_LIGHT_10, SPELL_UNLEASHED_LIGHT_25)
                && pWho->HasAura(RAID_MODE(SPELL_LIGHT_ESSENCE_10_N, SPELL_LIGHT_ESSENCE_25_N, SPELL_LIGHT_ESSENCE_10_H, SPELL_LIGHT_ESSENCE_25_H)))
            {
                pWho->CastSpell(pWho, RAID_MODE(SPELL_POWERING_UP_10_N, SPELL_POWERING_UP_25_N, SPELL_POWERING_UP_10_H, SPELL_POWERING_UP_25_H), true);
                int n = 5 + rand() % 8;
                if(Aura * aura = pWho->GetAura(RAID_MODE(SPELL_POWERING_UP_10_N, SPELL_POWERING_UP_25_N, SPELL_POWERING_UP_10_H, SPELL_POWERING_UP_25_H)))
                {
                    if(aura->GetStackAmount()+n > 100 || aura->GetStackAmount() == 100)
                    {
                        pWho->RemoveAurasDueToSpell(RAID_MODE(SPELL_POWERING_UP_10_N, SPELL_POWERING_UP_25_N, SPELL_POWERING_UP_10_H, SPELL_POWERING_UP_25_H));
                        pWho->CastSpell(pWho, RAID_MODE(SPELL_EMPOWERED_LIGHT_10_N, SPELL_EMPOWERED_LIGHT_25_N, SPELL_EMPOWERED_LIGHT_10_H, SPELL_EMPOWERED_LIGHT_25_H), true);
                        if (rand()%100 < 30)
                            pWho->CastSpell(pWho, RAID_MODE(SPELL_SURGE_OF_SPEED_10_N, SPELL_SURGE_OF_SPEED_25_N, SPELL_SURGE_OF_SPEED_10_H, SPELL_SURGE_OF_SPEED_25_H), true);
                    }
                    else
                    aura->SetStackAmount(aura->GetStackAmount()+n);
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (m_uiRangeCheckTimer < uiDiff)
            {
                if (Unit* target = me->SelectNearestTarget(2.0f))
                    if (target->GetTypeId() == TYPEID_PLAYER && target->isAlive())
                    {
                        DoCastAOE(RAID_MODE(SPELL_UNLEASHED_LIGHT_10, SPELL_UNLEASHED_LIGHT_25, SPELL_UNLEASHED_LIGHT_10, SPELL_UNLEASHED_LIGHT_25));
                        if (target->GetAura(RAID_MODE(SPELL_DARK_ESSENCE_10_N, SPELL_DARK_ESSENCE_25_N, SPELL_DARK_ESSENCE_10_H, SPELL_DARK_ESSENCE_25_H)))
                            me->CastSpell(target, RAID_MODE(SPELL_POWERING_UP_10_N, SPELL_POWERING_UP_25_N, SPELL_POWERING_UP_10_H, SPELL_POWERING_UP_25_H), true);
                        me->GetMotionMaster()->MoveIdle();
                        me->DespawnOrUnsummon(1000);
                    }
                m_uiRangeCheckTimer = IN_MILLISECONDS;
            }
            else m_uiRangeCheckTimer -= uiDiff;
        }
    };
};

enum PoweringUpSpells
{
    SPELL_SURGE_OF_SPEED_1      = 65828,
    SPELL_SURGE_OF_SPEED_2      = 67241,
    SPELL_SURGE_OF_SPEED_3      = 67242,
    SPELL_SURGE_OF_SPEED_4      = 67243,

    SPELL_POWERING_UP_1         = 67590,
    SPELL_POWERING_UP_2         = 67602,
    SPELL_POWERING_UP_3         = 67603,
    SPELL_POWERING_UP_4         = 67604,
};

class spell_powering_up : public SpellScriptLoader
{
public:
    spell_powering_up() : SpellScriptLoader("spell_powering_up") { }
    class spell_powering_up_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_powering_up_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            return true;
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* pTarget = GetTargetUnit())
			{
                if (urand(0, 100) <= 30)
				{
					switch(GetSpellInfo()->Id)
					{
						case SPELL_POWERING_UP_1:
							pTarget->CastSpell(pTarget, SPELL_SURGE_OF_SPEED_1, true);
							break;
						case SPELL_POWERING_UP_2:
							pTarget->CastSpell(pTarget, SPELL_SURGE_OF_SPEED_2, true);
							break;
						case SPELL_POWERING_UP_3:
							pTarget->CastSpell(pTarget, SPELL_SURGE_OF_SPEED_3, true);
							break;
						case SPELL_POWERING_UP_4:
							pTarget->CastSpell(pTarget, SPELL_SURGE_OF_SPEED_4, true);
							break;
					}
				}
			}
		}

        void Register()
        {
            OnEffect += SpellEffectFn(spell_powering_up_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_powering_up_SpellScript();
    }
};
void AddSC_boss_twin_valkyr()
{
    new boss_fjola();
    new boss_eydis();
    new mob_unleashed_light();
    new mob_unleashed_dark();
    new mob_essence_of_twin();
	new spell_powering_up();
}
