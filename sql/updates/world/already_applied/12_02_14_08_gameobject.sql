-- Schematic: Field Repair Bot 74A
-- By Mikadmin for Arkania
-- Fix spawn gobject

DELETE FROM `gameobject` WHERE (`id`=179552);
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (179552, 230, 1, 1, 849.798, 36.8788, -53.6446, 3.53743, 0, 0, 0.980478, -0.19663, 300, 0, 1);