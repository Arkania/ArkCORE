-- Sethria
-- By mikadmin [www.wow-attitude.com]
-- Fix npc position

SET @ENTRY := 41255;

DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(6403681, @ENTRY, 1, 1, 1, 0, 0, 3418.79, -2449.09, 968.038, 0.841985, 7200, 0, 0, 420, 0, 0, 0, 0, 0, 0);