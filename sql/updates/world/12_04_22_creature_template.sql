-- Stillwater Slitherer
-- By mikadmin for Arknania
-- Fix Focus

UPDATE `creature_template` SET `InhabitType` = '2',
`exp` = '3',
`Health_mod` = '0.8323' WHERE `creature_template`.`entry` =46868;

DELETE FROM `skinning_loot_template` WHERE (`entry`=46868);
INSERT INTO `skinning_loot_template` VALUES 
(46868, 52976, 50, 1, 0, 1, 6),
(46868, 52977, 25, 1, 0, 2, 9),
(46868, 52982, 25, 1, 0, 1, 6),
(46868, 67495, 3, 1, 0, 1, 1);

