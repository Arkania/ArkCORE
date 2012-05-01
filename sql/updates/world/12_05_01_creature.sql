-- Legionnaire Nazgrim
-- By Mikadmin for Arkania
-- Fix spawn creature

DELETE FROM `creature` WHERE `id`=41810;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(41810, 0, 1, 1, 0, 0, -6812.19, 3760.95, -404.094, 0.304538, 300, 0, 0, 126000, 0, 0, 0, 0, 0, 0);