-- gameobject_loot_template
-- By Mikadmin For ARKania
-- Fix error consol

-- Error: Table 'gameobject_loot_template' entry 35326 (gameobject entry) not exist but used as loot id in DB.
DELETE FROM `gameobject_loot_template` WHERE (`entry`=35326);
INSERT INTO `gameobject_loot_template` VALUES 
(35326, 62317, -100, 1, 0, 1, 1);

-- Error: Table 'gameobject_loot_template' entry xxxxxx isn't gameobject entry and not referenced from loot, and then useless.
UPDATE `gameobject_template` SET `data1` = 35572 WHERE `entry` = 206689;
UPDATE `gameobject_template` SET `data1` = 36086 WHERE `entry` = 207259;
UPDATE `gameobject_template` SET `data1` = 202745 WHERE `entry` = 202745;
UPDATE `gameobject_template` SET `data1` = 202775 WHERE `entry` = 202775;
UPDATE `gameobject_template` SET `data1` = 203014 WHERE `entry` = 203014;
UPDATE `gameobject_template` SET `data1` = 204280 WHERE `entry` = 204280;
UPDATE `gameobject_template` SET `data1` = 204388 WHERE `entry` = 204388;
UPDATE `gameobject_template` SET `data1` = 205246 WHERE `entry` = 205246;

-- Table 'gameobject_loot_template' entry 0 item 0: item entry not listed in `item_template` - skipped
DELETE FROM `gameobject_loot_template` WHERE (`entry` = 0);