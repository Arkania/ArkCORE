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
 SDName: Boss_Nerubenkan
 SD%Complete: 70
 SDComment:
 SDCategory: Stratholme
 EndScriptData */

#include "ScriptPCH.h"
#include "stratholme.h"

#define SPELL_ENCASINGWEBS          4962
#define SPELL_PIERCEARMOR           6016
#define SPELL_CRYPT_SCARABS         31602
#define SPELL_RAISEUNDEADSCARAB     17235

class boss_nerubenkan: public CreatureScript {
public:
    boss_nerubenkan() :
            CreatureScript("boss_nerubenkan") {
    }

    CreatureAI* GetAI(Creature* pCreature) const {
        return new boss_nerubenkanAI(pCreature);
    }

    struct boss_nerubenkanAI: public ScriptedAI {
        boss_nerubenkanAI(Creature *c) :
                ScriptedAI(c) {
            pInstance = me->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 EncasingWebs_Timer;
        uint32 PierceArmor_Timer;
        uint32 CryptScarabs_Timer;
        uint32 RaiseUndeadScarab_Timer;

        void Reset() {
            CryptScarabs_Timer = 3000;
            EncasingWebs_Timer = 7000;
            PierceArmor_Timer = 19000;
            RaiseUndeadScarab_Timer = 3000;
        }

        void EnterCombat(Unit * /*who*/) {
        }

        void JustDied(Unit* /*Killer*/) {
            if (pInstance)
                pInstance->SetData(TYPE_NERUB, IN_PROGRESS);
        }

        void RaiseUndeadScarab(Unit* pVictim) {
            if (Creature* pUndeadScarab = DoSpawnCreature(10876, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000))
                if (pUndeadScarab->AI())
                    pUndeadScarab->AI()->AttackStart(pVictim);
        }

        void UpdateAI(const uint32 diff) {
            if (!UpdateVictim())
                return;

            //EncasingWebs
            if (EncasingWebs_Timer <= diff) {
                DoCast(me->getVictim(), SPELL_ENCASINGWEBS);
                EncasingWebs_Timer = 30000;
            } else
                EncasingWebs_Timer -= diff;

            //PierceArmor
            if (PierceArmor_Timer <= diff) {
                if (urand(0, 3) < 2)
                    DoCast(me->getVictim(), SPELL_PIERCEARMOR);
                PierceArmor_Timer = 35000;
            } else
                PierceArmor_Timer -= diff;

            //CryptScarabs_Timer
            if (CryptScarabs_Timer <= diff) {
                DoCast(me->getVictim(), SPELL_CRYPT_SCARABS);
                CryptScarabs_Timer = 20000;
            } else
                CryptScarabs_Timer -= diff;

            //RaiseUndeadScarab
            if (RaiseUndeadScarab_Timer <= diff) {
                RaiseUndeadScarab(me->getVictim());
                RaiseUndeadScarab_Timer = 16000;
            } else
                RaiseUndeadScarab_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_nerubenkan() {
    new boss_nerubenkan();
}
