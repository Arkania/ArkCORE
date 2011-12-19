-- DB/ADDONS: Transform some addons to old format and fix some wrong one's this fix all addons errors
-- Addons still remaids into old TC format. so if you want to create a addon remenber this.
-- Fix also wrong creature_addons 
UPDATE `creature_template_addon` SET `auras`='29266 0' WHERE `entry`='20561';
UPDATE `creature_template_addon` SET `auras`='39205 0' WHERE `entry`='22454';
UPDATE `creature_template_addon` SET `auras`='50325 0' WHERE `entry` IN ('27692','27755','27756');
UPDATE `creature_template_addon` SET `auras`='66132 0' WHERE `entry` IN('34496','34497','35347','35348','35349');
UPDATE `creature_template_addon` SET `auras`='66133 0' WHERE `entry` IN ('35350','35351','35352');
UPDATE `creature_template_addon` SET `auras`='25824 0 31261 0 31261 0' WHERE `entry`='37552';
UPDATE `creature_template_addon` SET `auras`='61796 0' WHERE `entry`='34812';
UPDATE `creature_template_addon` SET `auras`='61795 0' WHERE `entry`='34819';
UPDATE `creature_template_addon` SET `auras`='61794 0' WHERE `entry`='34822';
UPDATE `creature_template_addon` SET `auras`='61793 0' WHERE `entry`='34823';
UPDATE `creature_template_addon` SET `auras`='61797 0' WHERE `entry`='34824';
UPDATE `creature_template_addon` SET `auras`='73530 0' WHERE `entry`='39137';
UPDATE `creature_template_addon` SET `auras`='72372 0' WHERE `entry` IN ('36823','38579','39189','39217');
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry` IN ('35463','35907'); -- Addons can't be zero
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry` IN ('52983'); -- Serpent's Poison can't be a aura (http://www.wowhead.com/spell=96572)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry` IN ('8455'); -- Portal Effect: Vengeance Landing can't be a aurathis is the spell to teleport players (http://www.wowhead.com/spell=49995) TO TEST IN GAME: .cast 49995
DELETE FROM `creature_template_addon` WHERE `entry` IN ('190000','23863','52371','52372','52411'); -- Dont' exist this entry

-- creature addons
UPDATE `creature_addon` SET `auras`='79488 0' WHERE `guid` IN ('304861','305936');
UPDATE `creature_addon` SET `auras`='49414 0' WHERE `guid`='311380';
UPDATE `creature_addon` SET `auras`='' WHERE `guid`='6645158'; -- Remove don't aura spell from creature.
DELETE FROM `creature_addon` WHERE `guid` IN ('86609','241822','242545','302617','302618'); -- If guuids don't exist better delete it