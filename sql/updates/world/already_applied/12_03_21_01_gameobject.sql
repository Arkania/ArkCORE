-- Rockin' Powder
-- By mikadmin for Arkania

UPDATE `gameobject_template` SET `data1` = '202351' WHERE `gameobject_template`.`entry` =202351;
UPDATE `creature_template` SET `lootid` = '38813' WHERE `creature_template`.`entry` =38813;

DELETE FROM `gameobject_loot_template` WHERE (`entry`=202351);
INSERT INTO `gameobject_loot_template` VALUES 
(202351, 52024, -100, 1, 0, 1, 1);

DELETE FROM `creature_loot_template` WHERE (`entry`=38813);
INSERT INTO `creature_loot_template` VALUES 
(38813, 52024, -100, 1, 0, 1, 1);

DELETE FROM creature_loot_template WHERE entry = 38811 and item = 52024;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(38811, 52024, '-0.5', 1, 0, 1, 1);
