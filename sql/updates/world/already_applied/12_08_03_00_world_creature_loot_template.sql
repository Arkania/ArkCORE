-- creature_loot_template
-- By Mikadmin For ARKania
-- Fix error consol

-- Error: Table 'creature_loot_template' entry 48589 isn't creature entry and not referenced from loot, and then useless.
DELETE FROM `creature_loot_template` WHERE (`entry`=48589);