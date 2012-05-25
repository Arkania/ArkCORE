-- The Biggest Egg Ever
-- By mikadmin for Arkania
-- Fix spawn and loot_template

DELETE FROM `gameobject` WHERE `id`=201977;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(201977, 648, 1, 1, 1164.76, 2374.27, 0.668408, 5.03218, 0, 0, 0.585504, -0.81067, 300, 0, 1),
(201977, 648, 1, 1, 1227.88, 2421.21, 0.372657, 3.41034, 0, 0, 0.990986, -0.133969, 300, 0, 1),
(201977, 648, 1, 1, 1252.69, 2372.01, 0.905444, 4.69839, 0, 0, 0.712039, -0.70214, 300, 0, 1),
(201977, 648, 1, 1, 1181.46, 2320.14, 0.720153, 2.83778, 0, 0, 0.988485, 0.151322, 300, 0, 1);

DELETE FROM `gameobject_loot_template` WHERE (`entry`=201977);
INSERT INTO `gameobject_loot_template` VALUES 
(201977, 50261, -100, 1, 0, 1, 1);