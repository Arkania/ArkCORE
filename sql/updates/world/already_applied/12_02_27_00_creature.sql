-- spawn kadu
-- By mikadmin for Arkania

DELETE FROM `creature` WHERE `id`=50306;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(50306, 530, 1, 1, 0, 0, -3869.15, -11643.2, -137.667, 2.17947, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0);