-- gameobject_loot_template
-- By Mikadmin For ARKania
-- Fix error consol

DELETE FROM `gameobject_loot_template` WHERE (`entry`=113768);

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
('113768', '45072', '100', '1', '0', '1', '1');