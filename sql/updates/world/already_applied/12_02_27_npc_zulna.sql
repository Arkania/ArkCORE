-- spawn vendor zulna
-- By mikadmin For Arkania

UPDATE `creature_template` SET `npcflag` = '128' WHERE `creature_template`.`entry` =52037;

DELETE FROM `creature` WHERE `id`=52037;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(52037, 1, 1, 1, 0, 0, 1659.12, -4352.39, 26.3461, 3.03045, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0);

DELETE FROM `npc_vendor` WHERE (`entry`=52037);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(52037, 0, 42946, 0, 0, 2551),
(52037, 0, 42947, 0, 0, 2551),
(52037, 0, 48718, 0, 0, 2551),
(52037, 0, 42943, 0, 0, 2551),
(52037, 0, 42991, 0, 0, 3319),
(52037, 0, 42948, 0, 0, 3319),
(52037, 0, 42992, 0, 0, 3319),
(52037, 0, 42944, 0, 0, 2550),
(52037, 0, 48677, 0, 0, 2550),
(52037, 0, 48685, 0, 0, 2550),
(52037, 0, 48687, 0, 0, 2550),
(52037, 0, 42945, 0, 0, 2550),
(52037, 0, 42950, 0, 0, 2550),
(52037, 0, 42984, 0, 0, 2550),
(52037, 0, 42951, 0, 0, 2550),
(52037, 0, 48683, 0, 0, 2550),
(52037, 0, 42985, 0, 0, 2550),
(52037, 0, 48716, 0, 0, 2550),
(52037, 0, 48691, 0, 0, 2550),
(52037, 0, 42949, 0, 0, 2550),
(52037, 0, 42952, 0, 0, 2550),
(52037, 0, 48689, 0, 0, 2550);
