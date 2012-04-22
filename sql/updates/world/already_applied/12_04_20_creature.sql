-- Sergeant Riannah
-- By Mikadmin for Arknania
-- Fix Spawn Creature

DELETE FROM `creature` WHERE `id`=29137;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(29137, 571, 1, 1, 0, 0, 5191.69, -2199.7, 239.398, 3.77191, 300, 0, 0, 232470, 0, 0, 0, 0, 0, 0);
