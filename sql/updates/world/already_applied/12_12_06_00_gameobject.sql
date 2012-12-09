-- Fix The Mosh'Ogg Bounty
-- By Mikadmin For Arkania

DELETE FROM `gameobject` WHERE `id`=204087;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(204087, 0, 1, 1, -12497.1, -1012.2, 56.0798, 1.08386, 0, 0, 0.515789, 0.856716, 300, 0, 1);