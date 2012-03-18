-- Spawn Dormus the Camel-Hoarder
-- By mikadmin for arkania

DELETE FROM `creature` WHERE `id`=50245;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(50245, 1, 1, 1, 0, 0, -5719.45, 663.315, 163.297, 1.4418, 300, 0, 0, 774900, 0, 0, 0, 0, 0, 0);
