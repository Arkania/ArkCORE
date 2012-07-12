-- Fix error consol
-- By mikadmin For ARKania

UPDATE `creature_loot_template` SET `groupid` = 0 WHERE `entry` = 50005;

INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(43296, 59221, 17, 1, 0, 1, 1),
(43296, 59223, 16, 1, 0, 1, 1),
(43296, 59224, 21, 1, 0, 1, 1),
(43296, 59225, 16, 1, 0, 1, 1),
(43296, 59233, 10, 1, 0, 1, 1),
(43296, 59234, 16, 1, 0, 1, 1),
(43296, 59310, 16, 1, 0, 1, 1),
(43296, 59311, 16, 1, 0, 1, 1),
(43296, 59313, 16, 1, 0, 1, 1),
(43296, 59314, 17, 1, 0, 1, 1),
(43296, 59355, 16, 1, 0, 1, 1),
(43296, 59451, 17, 1, 0, 1, 1),
(43296, 64663, 11, 1, 0, 1, 1);

