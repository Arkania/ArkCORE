-- Gar'gol's Gotta Go
-- By Mikadmin & Loonyx For Arkania
-- Fix quest chance & spawn chest

UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = '-0.4' WHERE `creature_loot_template`.`entry` =39646 AND `creature_loot_template`.`item` =52789;

DELETE FROM `gameobject` WHERE `id`=204580;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(204580, 1, 1, 1, 5104.19, -2054.99, 1275.39, 1.88801, 0, 0, 0.809912, 0.586551, 300, 0, 1);
