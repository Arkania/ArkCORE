-- Fix error consol: Empty pickpocketing
-- By Mikadmin For ARKania
-- Add datas pickpocketing 

DELETE FROM `pickpocketing_loot_template` WHERE (`entry`=41425);
DELETE FROM `pickpocketing_loot_template` WHERE (`entry`=41426);
DELETE FROM `pickpocketing_loot_template` WHERE (`entry`=42110);
DELETE FROM `pickpocketing_loot_template` WHERE (`entry`=42111);

INSERT INTO `pickpocketing_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
('41425', '16882', '62', '1', '0', '1', '1'),
('41425', '5377', '23', '1', '0', '1', '1'),
('41425', '6308', '22', '1', '0', '1', '2'),
('41425', '929', '7', '1', '0', '1', '1'),
('41425', '5498', '1.2', '1', '0', '1', '1'),
('41425', '1206', '0.8', '1', '0', '1', '1'),
('41426', '16882', '11', '1', '0', '1', '1'),
('41426', '5377', '5', '1', '0', '1', '1'),
('41426', '6308', '4', '1', '0', '1', '2'),
('41426', '929', '1.3', '1', '0', '1', '1'),
('42110', '16882', '57', '1', '0', '1', '1'),
('42110', '5377', '43', '1', '0', '1', '1'),
('42110', '6308', '29', '1', '0', '2', '2'),
('42111', '16882', '4', '1', '0', '1', '1'),
('42111', '5377', '3', '1', '0', '1', '1'),
('42111', '6308', '2', '1', '0', '1', '2'),
('42111', '929', '0.3', '1', '0', '1', '1'),
('42111', '5500', '0.18', '1', '0', '1', '1');