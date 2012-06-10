-- Save the Wee Animals
-- By Mikadmin and Loonyx for Arkania
-- Fix Loot template & creature_template

DELETE FROM `creature_loot_template` WHERE (`entry`=721) AND (`item`=53060);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (721, 53060, -100, 1, 0, 1, 1);

UPDATE `creature_template` SET `lootid` = '39998' WHERE `creature_template`.`entry` =39998;

DELETE FROM `creature_loot_template` WHERE (`entry`=39998);
INSERT INTO `creature_loot_template` VALUES 
(39998, 53060, -100, 1, 0, 1, 1);

UPDATE `creature_template` SET `lootid` = '39999' WHERE `creature_template`.`entry` =39999;

DELETE FROM `creature_loot_template` WHERE (`entry`=39999);
INSERT INTO `creature_loot_template` VALUES 
(39999, 53060, -100, 1, 0, 1, 1);