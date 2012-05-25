-- DB/ADDONS: Transform some addons to old format and fix some wrong one's this fix all addons errors
-- Addons still remaids into old TC format. so if you want to create a addon remenber this.
-- I feel like stupid making the same fixes again
UPDATE `creature_template_addon` SET `auras`='25824 0 31261 0 31261 0' WHERE `entry`='37552';
UPDATE `creature_template_addon` SET `auras`='78243 0' WHERE `entry`='39863';
UPDATE `creature_template_addon` SET `auras`='75476 0 78243 0' WHERE `entry`='40142';
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry` IN ('52983'); -- Serpent's Poison can't be a aura (http://www.wowhead.com/spell=96572)