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
#include "blackwing_descent.h"
#include "MapManager.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "ObjectMgr.h"

enum Spells
{
    // General
    SPELL_BERSERK                   = 64238,
    SPELL_RELEASE_ABBERATIONS       = 77569,
    SPELL_RELEASE_ALL_ABBERATIONS   = 77991,
    SPELL_REMEDY                    = 92967,
    SPELL_ARCANE_STORM              = 77896,

    // Red Phase
    SPELL_THROW_RED_BOTTLE          = 77925, // Or 77928?

    SPELL_SCORCHING_BLAST           = 92970,
    SPELL_CONSUMING_FLAMES          = 92973,

    // Blue Phase
    SPELL_THROW_BLUE_BOTTLE         = 77932, // Or 77934?

    SPELL_BITING_CHILL              = 77760,

    SPELL_FLASH_FREEZE              = 77699, // HC: 92980
    SPELL_FLASH_FREEZE_SUMMON       = 77711,
    SPELL_FLASH_FREEZE_VISUAL       = 77712,

    // Green Phase
    SPELL_THROW_GREEN_BOTTLE        = 77937, // Or 77938?

    SPELL_DEBILITATING_SLIME        = 77602, // (Dummy Effect - or only visual?)
    SPELL_DEBILITATING_SLIME_DEBUFF = 77615, // 92910

    // Black Phase
    SPELL_THROW_BLACK_BOTTLE        = 92831, // Or 92828?
    SPELL_SHADOW_IMBUED             = 92716,

    SPELL_ENGULFING_DARKNESS        = 92982,

    // Final Phase
    SPELL_MAGMA_JET                 = 78194,
    SPELL_MAGMA_JET_AURA            = 78095,
    SPELL_SUMMON_JET_MAGMA          = 78094,
    SPELL_ZERO_ABSOLUE              = 78208,
    SPELL_NOVA_ACIDE_10             = 78225,
    SPELL_NOVA_ACIDE_10_H           = 93012,
    SPELL_NOVA_ACIDE_25             = 93011,
    SPELL_NOVA_ACIDE_25_H           = 93013,

    // Aberration
    SPELL_CROISSANCE                = 77987,
    // Sujet Primordial
    SPELL_FIXE                      = 78617,
    SPELL_POURFENDRE                = 78034,
    SPELL_SAUVAGE                   = 77987,
    // Vil Rata
    SPELL_DARK_VASE_10_H            = 92987,
    SPELL_DARK_VASE_25_H            = 92988,
};

enum Events
{
    // General
    EVENT_NEW_PHASE = 1,
    EVENT_DRINK_BOTTLE,
    EVENT_UNLOCK_SPELLS,
    EVENT_WAIT_SWITCH_PHASE,
    EVENT_BERSERK,
    EVENT_REMEDY,
    EVENT_ARCANE_STORM,
    EVENT_SUMMON,

    // Red Phase
    EVENT_SCORCHING_BLAST,
    EVENT_CONSUMING_FLAMES,

    // Blue Phase
    EVENT_BITING_CHILL,
    EVENT_FLASH_FREEZE,

    // Green Phase
    EVENT_CAULDRON_EXPLODE,
    EVENT_RELEASE_ABBERATIONS,

    // Black Phase
    EVENT_SUMMON_VILE_SWILL,
    EVENT_ENGULFING_DARKNESS,

    // Final Phase
    EVENT_ACID_NOVA,
    EVENT_ZERO_ABSOLUE,
    EVENT_JET_MAGMA,
    EVENT_JETFLAME_TRIGGER,
};

enum ScriptTexts
{
    SAY_KILL                        = 0,
    SAY_AGGRO                       = 1,
    SAY_VIAL                        = 2,
    SAY_EVENT_1                     = 3, // Fiole Rouge
    SAY_EVENT_2                     = 4, // Aberration
    SAY_NEFARIAN_ON_DEATH           = 5,
    SAY_GEL                         = 6,
    SAY_FLAME                       = 7,
    SAY_DEATH                       = 8,
    SAY_LOW_HEALTH                  = 9,
};

/*
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 1, 0, 'There can be no disruptions! Mustn\'t keep the master waiting! Mustn\'t fail again!', 1, 0, 0, 0, 0, 19847, 'VO_BD_Maloriak aggro');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 8, 0, 'There will never be another like me..', 1, 0, 0, 0, 0, 19848, 'VO_BD_Maloriak death');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 0, 0, 'Nothing goes to waste...', 1, 0, 0, 0, 0, 19849, 'VO_BD_Maloriak_event02');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 4, 0, 'Strip the flesh, harvest the organs!', 1, 0, 0, 0, 0, 19850, 'VO_BD_Maloriak_event03');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 3, 0, 'Mix and stir, apply heat...', 1, 0, 0, 0, 0, 19851, 'VO_BD_Maloriak_event05');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 4, 1, 'This one\'s a little unstable, but what\'s progress without failure?', 1, 0, 0, 0, 0, 19852, 'VO_BD_Maloriak_event06');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 3, 1, 'How well does the mortal shell handle extreme temperature change? Must find out! For science!', 1, 0, 0, 0, 0, 19853, 'VO_BD_Maloriak_event07');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 7, 0, '', 1, 0, 0, 0, 0, 19854, 'VO_BD_Maloriak_event08');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 3, 2, 'What they lack in intelligence they make up for in ferocity!', 1, 0, 0, 0, 0, 19855, 'VO_BD_Maloriak_event09');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 9, 1, 'My failings will be your downfall!', 1, 0, 0, 0, 0, 19856, 'VO_BD_Maloriak_event10');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 2, 0, 'Too early, but no choice... They must be tested! Face now my prime subjects!', 1, 0, 0, 0, 0, 19857, 'VO_BD_Maloriak_event11');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES (41378, 9, 0, 'Meet the brawn to my brains! Prime subjects, devour them!', 1, 0, 0, 0, 0, 19858, 'VO_BD_Maloriak_event12');
*/

const Position aSpawnLocations[2] =
{
    {-95.657280f, -435.196167f, 73.401993f, 0.015100f},
    {-107.731865f, -414.607819f, 74.731171f, 0.003308f},
};

Position const MaloriakPositions[5] =
{
    {-106.148842f, -473.517365f, 73.454552f, 4.699424f}, // Cauldron Position
    {-75.459419f, -430.066071f, 73.274872f, 3.609182f}, // Add summon Positions
    {-77.055763f, -441.063354f, 73.489388f, 3.285442f},
    {-75.247200f, -499.593018f, 73.240547f, 2.064154f},
    {-143.885178f, -457.006409f, 73.369576f, 0.112437f},
};

enum Phases
{
    PHASE_RED,
    PHASE_BLUE,
    PHASE_GREEN,
    PHASE_BLACK,
    PHASE_NON,
    PHASE_FINAL,
};

#define TIMER_PHASE 45000

class boss_maloriak : public CreatureScript
{
public:
    boss_maloriak() : CreatureScript("boss_maloriak") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_maloriakAI (creature);
    }

    struct boss_maloriakAI : public BossAI
    {
        boss_maloriakAI(Creature* creature) : BossAI(creature, DATA_MALORIAK)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        uint8 phase;
        uint8 abberationsLeft;
        uint8 lastPhase;
        bool spellsLocked;
        bool wasInBlackPhase;
        uint8 withoutGreenPhase;

        bool phaseFinal;

        void Reset()
        {   
            events.Reset();
            me->SetReactState(REACT_AGGRESSIVE);
            abberationsLeft = 18;
            withoutGreenPhase = 0;
            wasInBlackPhase = true;
            spellsLocked = false;
            phaseFinal = false;
            UpdatePhase(PHASE_NON);
            DespawnMinions();

            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();

            Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_NEW_PHASE, urand(10000,12000));
            events.ScheduleEvent(EVENT_REMEDY, urand(25000,30000));
            events.ScheduleEvent(EVENT_ARCANE_STORM, urand(7000,8000));

            events.ScheduleEvent(EVENT_JET_MAGMA, urand(17000,31000));
            events.ScheduleEvent(EVENT_ZERO_ABSOLUE, urand(12000,26000));
            events.ScheduleEvent(EVENT_ACID_NOVA, urand(18000,27000));

            events.ScheduleEvent(EVENT_BERSERK, me->GetMap()->IsHeroic() ? 720000 : 420000);

            me->SummonCreature(41440, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_CASTING))
                return;

            events.Update(diff);

            if(me->GetHealthPct() < 25 && phase != PHASE_FINAL && phaseFinal)
            {
                // Enter Final Phase
                phase = PHASE_FINAL;
                me->InterruptNonMeleeSpells(true);
                
                DoCast(SPELL_RELEASE_ALL_ABBERATIONS);
                me->SummonCreature(41841, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(41841, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);

                Talk(SAY_LOW_HEALTH);
            };

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // General and Phase Switching
                case EVENT_NEW_PHASE:
                    UpdatePhase(urand(PHASE_RED, PHASE_BLUE));
                    spellsLocked = true;
                    events.ScheduleEvent(EVENT_NEW_PHASE, TIMER_PHASE);
                    break;

                case EVENT_DRINK_BOTTLE:

                    if(GameObject* cauldron = me->FindNearestGameObject(GOB_MALORIAKS_CAULDRON,100.f))
                    {
                        switch(phase)
                        {
                        case PHASE_RED:
                            DoCast(cauldron->ToCreature(), SPELL_THROW_RED_BOTTLE);
                            break;

                        case PHASE_BLUE:
                            DoCast(cauldron->ToCreature(), SPELL_THROW_BLUE_BOTTLE);
                            break;

                        /*case PHASE_GREEN:
                            DoCast(cauldron->ToCreature(), SPELL_THROW_GREEN_BOTTLE);
                            break;*/

                        case PHASE_BLACK:
                            DoCast(cauldron->ToCreature(), SPELL_THROW_BLACK_BOTTLE);
                            me->AddAura(SPELL_SHADOW_IMBUED, me);
                            break;
                        }
                    }

                    events.ScheduleEvent(EVENT_WAIT_SWITCH_PHASE, 1000);
                    break;

                case EVENT_WAIT_SWITCH_PHASE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->GetMotionMaster()->MoveChase(me->getVictim());

                    // Intialize Phase Events
                    switch(phase)
                    {
                    case PHASE_RED:
                        events.ScheduleEvent(EVENT_SCORCHING_BLAST, 7000);
                        events.ScheduleEvent(EVENT_CONSUMING_FLAMES, 3000);
                        break;

                    case PHASE_BLUE:
                        events.ScheduleEvent(EVENT_BITING_CHILL, 7000);
                        events.ScheduleEvent(EVENT_FLASH_FREEZE, 9000);
                        break;

                    /*case PHASE_GREEN:
                        events.ScheduleEvent(EVENT_CAULDRON_EXPLODE, 2000);
                        break;*/

                    case PHASE_BLACK:
                        events.ScheduleEvent(EVENT_SUMMON_VILE_SWILL, urand(4000,6000));
                        events.ScheduleEvent(EVENT_ENGULFING_DARKNESS, 9000);
                        break;
                    }

                    if(phase != PHASE_BLACK)
                    {
                        events.ScheduleEvent(EVENT_RELEASE_ABBERATIONS, urand(12000,17000));
                        Talk(SAY_VIAL);
                    }

                    events.ScheduleEvent(EVENT_UNLOCK_SPELLS, 1500);
                    break;

                    // Misc
                case EVENT_UNLOCK_SPELLS:
                    spellsLocked = false;
                    break;

                case EVENT_BERSERK:
                    DoCast(me,SPELL_BERSERK);
                    break;

                case EVENT_REMEDY:
                    if(spellsLocked)
                        events.ScheduleEvent(EVENT_REMEDY, 1500);
                    else
                    {
                        DoCast(me,SPELL_REMEDY);
                        events.ScheduleEvent(EVENT_REMEDY, urand(25000,30000));
                    }
                    break;

                case EVENT_ARCANE_STORM:
                    if(spellsLocked)
                        events.ScheduleEvent(EVENT_ARCANE_STORM, 1500);
                    else
                    {
                        me->AttackStop();
                        DoCastAOE(SPELL_ARCANE_STORM);
                        events.ScheduleEvent(EVENT_ARCANE_STORM, urand(27000,29000));
                    }
                    break;

                    // Red Phase
                case EVENT_SCORCHING_BLAST:
                    DoCastAOE(SPELL_SCORCHING_BLAST);
                    events.ScheduleEvent(EVENT_SCORCHING_BLAST, urand(15000, 17000));
                    break;

                case EVENT_CONSUMING_FLAMES:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                        DoCast(target, SPELL_CONSUMING_FLAMES);
                    events.ScheduleEvent(EVENT_CONSUMING_FLAMES, urand(7000, 8500));
                    break;

                    // Blue Phase
                case EVENT_BITING_CHILL:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                        DoCast(target, SPELL_BITING_CHILL);
                    events.ScheduleEvent(EVENT_BITING_CHILL, urand(8000, 10000));
                    break;

                case EVENT_FLASH_FREEZE:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                        target->CastSpell(target, SPELL_FLASH_FREEZE_SUMMON, true);
                    events.ScheduleEvent(EVENT_FLASH_FREEZE, urand(11000, 13000));
                    break;

                    // Green Phase
                /*case EVENT_CAULDRON_EXPLODE:
                    me->FindNearestCreature(NPC_SLIME_TRIGGER, 100.f)->AI()->DoCastAOE(SPELL_DEBILITATING_SLIME);
                    DoCastCausticSlime();
                    events.ScheduleEvent(EVENT_CAULDRON_EXPLODE, 15000);
                    break;*/

                case EVENT_RELEASE_ABBERATIONS:
                    DoCast(SPELL_RELEASE_ABBERATIONS);
                    me->SummonCreature(41440, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(41440, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    break;

                    // Black Phase
                case EVENT_SUMMON_VILE_SWILL:
                    me->SummonCreature(NPC_VILE_SWILL, MaloriakPositions[urand(1,4)]);
                    events.ScheduleEvent(EVENT_SUMMON_VILE_SWILL, urand(4000,5000));
                    break;

                case EVENT_ENGULFING_DARKNESS:
                    DoCastAOE(SPELL_ENGULFING_DARKNESS);
                    events.ScheduleEvent(EVENT_ENGULFING_DARKNESS, 16000);
                    break;
						
                default:
                    break;
                }
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                phaseFinal = true;

                switch (eventId)
                {
                    // Final Phase
                case EVENT_JET_MAGMA:
                    Talk(SAY_FLAME);
                    FlameJetLastPos.Relocate(me);
                    me->CastCustomSpell(SPELL_MAGMA_JET, SPELLVALUE_MAX_TARGETS, 2, me);
                    events.ScheduleEvent(EVENT_JET_MAGMA, urand(17000,31000));
                    break;

                case EVENT_ZERO_ABSOLUE:
                    Talk(SAY_GEL);
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1, 200, true), SPELL_ZERO_ABSOLUE);
                    events.ScheduleEvent(EVENT_ZERO_ABSOLUE, urand(12000,26000));
                    break;

                case EVENT_ACID_NOVA:
                    DoCastAOE(RAID_MODE(SPELL_NOVA_ACIDE_10, SPELL_NOVA_ACIDE_25, SPELL_NOVA_ACIDE_10_H, SPELL_NOVA_ACIDE_25_H));
                    events.ScheduleEvent(EVENT_ACID_NOVA, urand(18000,27000));
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        const Position* GetLastJetflamePosition() const
        {
            return &FlameJetLastPos;
        }

        void KilledUnit(Unit* /*who*/)
        {
            Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            DespawnMinions();

            _JustDied();
        }

        void JustSummoned(Creature* summon)
        {
            //summon->AI()->SetMinionInCombat();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != 1)
                return;

            if(GameObject* cauldron = me->FindNearestGameObject(GOB_MALORIAKS_CAULDRON,100.f))
            {
                cauldron->SendCustomAnim(phase);
                me->SetFacingToObject(cauldron);
            }

            events.ScheduleEvent(EVENT_DRINK_BOTTLE, 1500);
        }

        uint32 GetData(uint32 type)
        {
            if(type == DATA_ABBERATIONS_LEFT)
                return abberationsLeft;
            else
                return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            if(type == DATA_ABBERATIONS_LEFT)
                abberationsLeft = data;
        }

    private:
        Position FlameJetLastPos;

        void UpdatePhase(uint8 newPhase)
        {
            // Cancel current Phase Events

            switch(phase)
            {
            case PHASE_RED:
                events.CancelEvent(EVENT_SCORCHING_BLAST);
                events.CancelEvent(EVENT_CONSUMING_FLAMES);
                break;

            case PHASE_BLUE:
                events.CancelEvent(EVENT_BITING_CHILL);
                events.CancelEvent(EVENT_FLASH_FREEZE);
                break;

            /*case PHASE_GREEN:
                events.CancelEvent(EVENT_CAULDRON_EXPLODE);
                break;*/

            case PHASE_BLACK:
                me->RemoveAura(SPELL_SHADOW_IMBUED);
                events.CancelEvent(EVENT_SUMMON_VILE_SWILL);
                events.CancelEvent(EVENT_ENGULFING_DARKNESS);
                break;
            }

            phase = newPhase;

            if(phase == PHASE_NON)
                return;

            // In Heroic Mode every 2. Phase is a Black Phase
            if((me->GetMap()->IsHeroic()) && (!wasInBlackPhase))
            {
                phase = PHASE_BLACK;
                wasInBlackPhase = true;
            } else
            {
                withoutGreenPhase++;
                wasInBlackPhase = false;

                if(lastPhase == phase )
                {
                    if(phase == PHASE_RED)
                        phase = PHASE_BLUE;
                    else if(phase == PHASE_BLUE)
                        phase = PHASE_RED;
                }

                lastPhase = phase;
            }

            // Every 3. Phase is a Green Phase
            if(withoutGreenPhase >= 3)
            {
                if(phase == PHASE_BLACK)
                    wasInBlackPhase = false;

                phase = PHASE_GREEN;
                withoutGreenPhase = 0;
            }              

            // Debug: (here you can define a spezified phase for debugging)
            // phase = PHASE_BLACK;

            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            me->GetMotionMaster()->MovePoint(1, MaloriakPositions[0]);
        }

        inline void DespawnMinions()
        {
            DespawnCreatures(NPC_ABBERATON);
            DespawnCreatures(NPC_PRIME_SUBJECT);
            DespawnCreatures(NPC_FLASH_FREEZE);
            DespawnCreatures(NPC_VILE_SWILL);
            DespawnCreatures(NPC_MAGMA_JET_CONTROLLER);
            DespawnCreatures(NPC_ABSOLUTE_ZERO);  
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 200.0f);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        inline void DoCastCausticSlime()
        {
            // All Players
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    me->AddAura(SPELL_DEBILITATING_SLIME_DEBUFF,  i->getSource());

            // Maloriak and all his Minions
            me->AddAura(SPELL_DEBILITATING_SLIME_DEBUFF, me);

            std::list<Creature*> creatures;

            // Abberations
            GetCreatureListWithEntryInGrid(creatures, me, NPC_ABBERATON, 50.0f);

            if (!creatures.empty())
                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    me->AddAura(SPELL_DEBILITATING_SLIME_DEBUFF,  (*iter));

            // Vile Swill (Hardmode)
            GetCreatureListWithEntryInGrid(creatures, me, NPC_VILE_SWILL, 50.0f);

            if (!creatures.empty())
                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    me->AddAura(SPELL_DEBILITATING_SLIME_DEBUFF,  (*iter));
        }
    };
};

/***************
** Jet de Magma
****************/
typedef boss_maloriak::boss_maloriakAI MaloriakAI;

class npc_flame_jet : public CreatureScript
{
    public:
        npc_flame_jet() : CreatureScript("npc_flame_jet") { }

        struct npc_flame_jetAI : public ScriptedAI
        {
            npc_flame_jetAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void IsSummonedBy(Unit* owner)
            {
                if (owner->GetTypeId() != TYPEID_UNIT)
                    return;

                Creature* creOwner = owner->ToCreature();
                Position pos;
                
				MaloriakAI* maloriakAI = CAST_AI(MaloriakAI, creOwner->AI());
                Position const* ownerPos = maloriakAI->GetLastJetflamePosition();
                float ang = me->GetAngle(ownerPos) - static_cast<float>(M_PI);
                MapManager::NormalizeOrientation(ang);
                me->SetOrientation(ang);
                owner->GetNearPosition(pos, 2.5f, 0.0f);
                
                me->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                events.ScheduleEvent(EVENT_JETFLAME_TRIGGER, 200);
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_JETFLAME_TRIGGER)
                {
                    Position newPos;
                    me->GetNearPosition(newPos, 5.5f, 0.0f);
                    me->NearTeleportTo(newPos.GetPositionX(), newPos.GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    DoCast(SPELL_SUMMON_JET_MAGMA);
                    events.ScheduleEvent(EVENT_JETFLAME_TRIGGER, 200);
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_flame_jetAI(creature);
        }
};

class npc_flash_freeze_maloriak : public CreatureScript
{
public:
    npc_flash_freeze_maloriak() : CreatureScript("npc_flash_freeze_maloriak") { }

    struct npc_flash_freeze_maloriakAI : public ScriptedAI
     {
        npc_flash_freeze_maloriakAI(Creature * pCreature) : ScriptedAI(pCreature) {}

        uint32 timerChecktarget;
			
        void Reset()
        {
            timerChecktarget = 500;		
            me->AddAura(SPELL_FLASH_FREEZE_VISUAL, me);
        }
			
        void JustDied(Unit* /*killer*/)
        {
            me->ForcedDespawn();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
				
            if (timerChecktarget <= diff)
            {
                if (Unit *pTar = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                DoCast(pTar, SPELL_FLASH_FREEZE);
                timerChecktarget = 500;
            } else timerChecktarget -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_flash_freeze_maloriakAI(creature);
    }
};

/**********
** Vil Rata
***********/
class npc_vil_rata : public CreatureScript
{
public:
    npc_vil_rata() : CreatureScript("npc_vil_rata") { }

    struct npc_vil_rataAI : public ScriptedAI
    {
        npc_vil_rataAI(Creature * pCreature) : ScriptedAI(pCreature) {}

        uint32 SombreVase;

        void Reset()
        {
            SombreVase = 20000;
            me->DespawnOrUnsummon(60000);
        }
	
        void Entercombat()
        {
            DoZoneInCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
		
            if (IsHeroic())
            {
                if (SombreVase<= diff)
                {
                    DoCast(me, RAID_MODE(SPELL_DARK_VASE_10_H,SPELL_DARK_VASE_25_H), true);
                    SombreVase = 20000;
                } else SombreVase -= diff;
            }
				
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_vil_rataAI(creature);
    }
};

/***********
** Aberration
************/
class npc_aberration: public CreatureScript
{
public:
    npc_aberration() : CreatureScript("npc_aberration") { }

    struct npc_aberrationAI : public ScriptedAI
    {
        npc_aberrationAI(Creature * pCreature) : ScriptedAI(pCreature) {}

        uint32 Croissance;
        bool Fixe;
			
        void Reset()
        {
            Croissance = 20000;
            Fixe = false;
            me->DespawnOrUnsummon(60000);
        }
			
        void Entercombat(Unit * /*who*/)
        {
            DoZoneInCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
				
            if (Croissance<= diff)
            {
                DoCast(me, SPELL_CROISSANCE);
                Croissance = 20000;
            } else Croissance -= diff;
			
            if (Fixe<= diff)
            {
                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                DoCast(target, SPELL_FIXE, true);
                Fixe = true;
            } else Fixe -= diff;
				
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_aberrationAI(creature);
    }
};

/***************
** Prime Subject
****************/
class npc_prime_subject: public CreatureScript
{
public:
    npc_prime_subject() : CreatureScript("npc_prime_subject") { }

    struct npc_prime_subjectAI : public ScriptedAI
    {
        npc_prime_subjectAI(Creature * pCreature) : ScriptedAI(pCreature) {}

        uint32 Sauvage;
        uint32 Fendre;
			
        void Reset()
        {
            Sauvage = 20000;
            Fendre = 5000;
            me->DespawnOrUnsummon(60000);
        }
		
        void Entercombat(Unit * /*who*/)
        {
            DoZoneInCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
				
            if (Sauvage<= diff)
            {
                DoCast(me, SPELL_SAUVAGE, true);
                Sauvage = 20000;
            } else Sauvage -= diff;
		
            if (Fendre<= diff)
            {
                DoCast(me->getVictim(), SPELL_POURFENDRE, true);
                Fendre = 5000;
            } else Fendre -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_prime_subjectAI(creature);
    }
};

/********************
** Release Aberration
*********************/
class spell_release_abberations : public SpellScriptLoader
{
public:
    spell_release_abberations() : SpellScriptLoader("spell_release_abberations") { }

    class spell_release_abberationsSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_release_abberationsSpellScript);

        bool Validate(SpellEntry const * spellEntry)
        {
            return true;
        }

        bool Load()
        {
            return true;
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            if(Unit* caster = GetCaster())
            {
                uint8 abberationsLeft = caster->ToCreature()->AI()->GetData(DATA_ABBERATIONS_LEFT);

                if(abberationsLeft >= 3)
                {
                    for (uint8 i = 0; i<=2; i++)
                        caster->SummonCreature(NPC_ABBERATON, MaloriakPositions[urand(1,4)]);

                    caster->ToCreature()->AI()->SetData(DATA_ABBERATIONS_LEFT, abberationsLeft-3);
                }
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_release_abberationsSpellScript::HandleDummy,EFFECT_0,SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_release_abberationsSpellScript();
    }
};

/************************
** Release All Aberration
*************************/
class spell_release_all_abberations : public SpellScriptLoader
{
public:
    spell_release_all_abberations() : SpellScriptLoader("spell_release_all_abberations") { }

    class spell_release_all_abberationsSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_release_all_abberationsSpellScript);

        bool Validate(SpellEntry const * spellEntry)
        {
            return true;
        }

        bool Load()
        {
            return true;
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            if(Unit* caster = GetCaster())
            {
                uint8 abberationsLeft = caster->ToCreature()->AI()->GetData(DATA_ABBERATIONS_LEFT);

                if(abberationsLeft > 0)
                    for (uint8 i = 0; i < abberationsLeft; i++)
                        caster->SummonCreature(NPC_ABBERATON, MaloriakPositions[urand(1,4)]);

                for (uint8 i = 0; i <= 1; i++)
                    caster->SummonCreature(NPC_PRIME_SUBJECT, MaloriakPositions[urand(1,4)]);

                caster->ToCreature()->AI()->SetData(DATA_ABBERATIONS_LEFT, 0);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_release_all_abberationsSpellScript::HandleDummy,EFFECT_0,SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_release_all_abberationsSpellScript();
    }
};

/********************
** Spell Jet de Magma
*********************/
class spell_gen_maloriak_jetmagma : public SpellScriptLoader
{
    public:
        spell_gen_maloriak_jetmagma() : SpellScriptLoader("spell_gen_maloriak_jetmagma") { }

        class spell_gen_maloriak_jetmagma_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gen_maloriak_jetmagma_SpellScript);

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetCaster();
                uint8 count = 1;
                if (GetSpellInfo()->Id == 78095)
                    count = 4;

                for (uint8 i = 0; i < count; ++i)
                    caster->CastSpell(caster, uint32(GetEffectValue()+i), true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_gen_maloriak_jetmagma_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_gen_maloriak_jetmagma_SpellScript();
        }
};

void AddSC_boss_maloriak()
{
    new boss_maloriak();
    new npc_flash_freeze_maloriak();
    new npc_flame_jet();
    new npc_vil_rata();
    new npc_aberration();
    new npc_prime_subject();
    new spell_release_abberations();
    new spell_release_all_abberations();
    new spell_gen_maloriak_jetmagma();
}