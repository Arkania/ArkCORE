-- Anshal
-- By Mikadmin for Arkania
-- Fix loot_template

-- 10
DELETE FROM `creature_loot_template` WHERE (`entry`=45870);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(45870, 63494, 20, 1, 0, 1, 1),
(45870, 63492, 20, 1, 0, 1, 1),
(45870, 63495, 19, 1, 0, 1, 1),
(45870, 63497, 19, 1, 0, 1, 1),
(45870, 63490, 19, 1, 0, 1, 1),
(45870, 63491, 17, 1, 0, 1, 1),
(45870, 63498, 16, 1, 0, 1, 1),
(45870, 63493, 16, 1, 0, 1, 1),
(45870, 63496, 16, 1, 0, 1, 1),
(45870, 63488, 16, 1, 0, 1, 1),
(45870, 63489, 15, 1, 0, 1, 1);

-- 10H 
DELETE FROM `creature_loot_template` WHERE (`entry`=50113);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(50113, 65373, 21, 1, 0, 1, 1),
(50113, 65368, 19, 1, 0, 1, 1),
(50113, 65375, 18, 1, 0, 1, 1),
(50113, 65374, 17, 1, 0, 1, 1),
(50113, 65369, 17, 1, 0, 1, 1),
(50113, 65370, 17, 1, 0, 1, 1),
(50113, 65376, 15, 1, 0, 1, 1),
(50113, 65371, 14, 1, 0, 1, 1),
(50113, 65377, 13, 1, 0, 1, 1),
(50113, 65367, 12, 1, 0, 1, 1),
(50113, 65372, 12, 1, 0, 1, 1);

-- 25 
DELETE FROM `creature_loot_template` WHERE (`entry`=50103);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(50103, 63494, 42, 1, 0, 1, 1),
(50103, 63492, 41, 1, 0, 1, 1),
(50103, 63495, 41, 1, 0, 1, 1),
(50103, 63497, 40, 1, 0, 1, 1),
(50103, 63490, 40, 1, 0, 1, 1),
(50103, 63491, 35, 1, 0, 1, 1),
(50103, 63498, 35, 1, 0, 1, 1),
(50103, 63493, 34, 1, 0, 1, 1),
(50103, 63496, 34, 1, 0, 1, 1),
(50103, 63488, 34, 1, 0, 1, 1),
(50103, 63489, 32, 1, 0, 1, 1);

-- 25H 
DELETE FROM `creature_loot_template` WHERE (`entry`=50123);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(50123, 65373, 49, 1, 0, 1, 1),
(50123, 65368, 48, 1, 0, 1, 1),
(50123, 65375, 48, 1, 0, 1, 1),
(50123, 65374, 44, 1, 0, 1, 1),
(50123, 65369, 41, 1, 0, 1, 1),
(50123, 65370, 40, 1, 0, 1, 1),
(50123, 65376, 40, 1, 0, 1, 1),
(50123, 65371, 37, 1, 0, 1, 1),
(50123, 65377, 37, 1, 0, 1, 1),
(50123, 65367, 36, 1, 0, 1, 1),
(50123, 65372, 36, 1, 0, 1, 1);