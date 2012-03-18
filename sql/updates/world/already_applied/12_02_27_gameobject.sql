-- spawn black forge
-- By mikadmin for Arkania

DELETE FROM `gameobject` WHERE `id`=174045;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(174045, 230, 1, 1, 1212.4, -443.102, -100.502, 3.20754, 0, 0, 0.999456, -0.0329687, 300, 0, 1);