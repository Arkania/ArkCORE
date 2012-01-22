-- DB/CREATURE: New locs for Huklah, Rarc, Kzan Thornslash, Hraug & Nartok and more
-- Huklah New loc taking for official (http://www.wowhead.com/npc=3160)
DELETE FROM `creature` WHERE `id`=3160;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(4796, 3160, 1, 1, 1, 1881, 0, -591.19, -4229.78, 38.3707, 0.987861, 600, 0, 0, 222, 0, 0, 0, 0, 0, 0);

-- Rarc New loc taking for official (http://www.wowhead.com/npc=3161)
DELETE FROM `creature` WHERE `id`=3161;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(1067887, 3161, 1, 1, 1, 0, 3161, -587.988, -4228.33, 38.4948, 3.36282, 600, 0, 0, 198, 0, 0, 0, 0, 0, 0);

-- Kzan Thornslash New loc taking for official (http://www.wowhead.com/npc=3159)
DELETE FROM `creature` WHERE `id`=3159;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(4797, 3159, 1, 1, 1, 1883, 0, -590.576, -4226.76, 38.3641, 4.53768, 600, 0, 0, 1279, 0, 0, 0, 0, 0, 0);

-- Hraug New loc taking for official (http://www.wowhead.com/npc=12776)
DELETE FROM `creature` WHERE `id`=12776;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(4799, 12776, 1, 1, 1, 14371, 0, -587.747, -4206.14, 38.7766, 3.0751, 600, 0, 0, 176, 0, 0, 0, 0, 0, 0);

-- Nartok New loc taking for official (http://www.wowhead.com/npc=3156)
DELETE FROM `creature` WHERE `id`=3156;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(4800, 3156, 1, 1, 1, 1884, 0, -591.124, -4205.99, 38.6286, 6.27464, 600, 0, 0, 176, 0, 0, 0, 0, 0, 0);

-- Rwag <Rogue Trainer> New loc taking for official (http://www.wowhead.com/npc=3155)
DELETE FROM `creature` WHERE `id`=3155;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(7284, 3155, 1, 1, 1, 1886, 0, -617.395, -4202.4, 38.134, 4.86947, 600, 0, 0, 156, 0, 0, 0, 0, 0, 0);

-- Mai'ah <Mage Trainer> Is not ingame so deleted it (http://www.wowhead.com/npc=5884)
DELETE FROM `creature` WHERE `id`=5884;

-- Ken'jai <Priest Trainer> Is not ingame so deleted it (http://www.wowhead.com/npc=3707)
DELETE FROM `creature` WHERE `id`=3707;

-- Ruzan Is not ingame so deleted it (http://www.wowhead.com/npc=5765)
DELETE FROM `creature` WHERE `id`=5765;

-- Magga Is not ingame so deleted it (http://www.wowhead.com/npc=11943)
DELETE FROM `creature` WHERE `id`=11943 AND `guid`='3416';

-- Huklah
SET @ENTRY := 3160;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,0,5000,6000,19000,20000,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On OCC do emote (radom time)");

-- Rarc
SET @ENTRY := 3161;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,0,5500,6500,19500,25000,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On OCC do emote (radom time)");

-- Kzan Thornslash
SET @ENTRY := 3159;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,0,6000,7000,20000,26000,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On OCC do emote (radom time)");

-- Hraug
SET @ENTRY := 12776;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,0,5000,6000,19000,20000,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On OCC do emote (radom time)");

-- Nartok
SET @ENTRY := 3156;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,0,5500,6500,19500,25000,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On OCC do emote (radom time)");

-- Den Cage Miss some ownes locs (http://www.wowhead.com/object=202580)
DELETE FROM `gameobject` WHERE `id`=202580;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(156, 202580, 1, 1, 1, -585.264, -4125.97, 43.1105, 1.88495, 0, 0, 0, 1, 180, 100, 1),
(157, 202580, 1, 1, 1, -600.599, -4111.46, 43.7663, -0.767944, 0, 0, 0, 1, 180, 100, 1),
(158, 202580, 1, 1, 1, -583.175, -4105.33, 42.6931, 2.19912, 0, 0, 0, 1, 180, 100, 1),
(160, 202580, 1, 1, 1, -582.946, -4114.75, 43.4067, 1.18682, 0, 0, 0, 1, 180, 100, 1),
(161, 202580, 1, 1, 1, -582.541, -4114.78, 43.6113, 2.88251, 0, 0, 0.991621, 0.12918, 300, 0, 1),
(162, 202580, 1, 1, 1, -583.092, -4105.53, 43.1966, 4.99209, 0, 0, 0.601635, -0.798771, 300, 0, 1);

-- New loc and WP for Den Grunt
DELETE FROM `creature` WHERE `id`=5952 AND `guid`='241867';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(241867, 5952, 1, 1, 1, 9794, 5952, -606.807, -4111.33, 42.9134, 0.282059, 600, 0, 0, 265080, 0, 0, 0, 0, 0, 0);

-- VISUAL: Den Grunt Waypoints and enotes Taking from oficial
-- Set wp for creature
DELETE FROM `creature_addon` WHERE (`guid`=241867);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(241867, '241867', 0, 0, 1, 0, '');

-- Waypoint movement type
UPDATE `creature` SET `MovementType`='2' WHERE `guid`='241867';

-- Waypoint data
DELETE FROM `waypoint_data` WHERE `id`='241867';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('241867','1','-606.807','-4111.33','42.9134','0','0','0','100','0'),
('241867','2','-604.215','-4109.34','43.2133','0','0','0','100','0'),
('241867','3','-602.366','-4107.92','43.7409','0','0','0','100','0'),
('241867','4','-598.867','-4107.85','43.8431','0','0','0','100','0'),
('241867','5','-597.446','-4107.82','43.749','0','0','0','100','0'),
('241867','6','-591.249','-4111.08','44.055','0','0','0','100','0'),
('241867','7','-587.525','-4113.04','43.821','0','0','0','100','0'),
('241867','8','-586.663','-4116.9','43.6456','0','0','0','100','0'),
('241867','9','-586.663','-4116.9','43.6456','0','0','0','100','0'),
('241867','10','-588.621','-4123.62','43.7438','0','0','0','100','0'),
('241867','11','-589.6','-4126.98','43.3538','0','0','0','100','0'),
('241867','12','-591.084','-4135.46','41.7406','0','0','0','100','0'),
('241867','13','-591.638','-4142.43','41.6204','0','0','0','100','0'),
('241867','14','-596.769','-4151.94','42.9678','0','0','0','100','0'),
('241867','15','-604.146','-4156.81','43.36','0','0','0','100','0'),
('241867','16','-606.638','-4162.89','42.3198','0','0','0','100','0'),
('241867','17','-605.434','-4169.78','41.1612','0','0','0','100','0'),
('241867','18','-603.932','-4177.56','41.4049','0','0','0','100','0'),
('241867','19','-603.932','-4177.56','41.4049','0','0','0','100','0'),
('241867','20','-604.512','-4170.58','40.9567','0','0','0','100','0'),
('241867','21','-605.602','-4163.67','42.1083','0','0','0','100','0'),
('241867','22','-606.001','-4157.2','43.0328','0','0','0','100','0'),
('241867','23','-602.709','-4151.82','43.114','0','0','0','100','0'),
('241867','24','-600.425','-4150.19','43.0844','0','0','0','100','0'),
('241867','25','-592.921','-4145.55','41.7823','0','0','0','100','0'),
('241867','26','-591.018','-4142.4','41.4766','0','0','0','100','0'),
('241867','27','-590.331','-4138.02','41.6574','0','0','0','100','0'),
('241867','28','-589.925','-4131.04','42.2893','0','0','0','100','0'),
('241867','29','-588.924','-4124.12','43.6761','0','0','0','100','0'),
('241867','30','-587.947','-4118.61','43.9199','0','0','0','100','0'),
('241867','31','-588.194','-4113.97','43.947','0','0','0','100','0'),
('241867','32','-588.194','-4113.97','43.947','0','0','0','100','0'),
('241867','33','-594.416','-4110.77','43.8947','0','0','0','100','0'),
('241867','34','-600.285','-4107.91','43.9434','0','0','0','100','0'),
('241867','35','-601.423','-4107.68','43.9133','0','0','0','100','0'),
('241867','36','-604.36','-4112.73','43.4776','0','0','0','100','0'),
('241867','37','-604.836','-4113.24','43.4393','0','0','0','100','0'),
('241867','38','-607.841','-4113.78','42.8689','0','0','0','100','0'),
('241867','39','-608.513','-4112.83','42.6138','0','0','0','100','0'),
('241867','40','-607.869','-4112.16','42.7172','0','0','0','100','0');

-- VISUAL: Duokna <General Goods> Waypoints and enotes Taking from oficial (http://www.wowhead.com/npc=3158)
-- Set wp for creature
DELETE FROM `creature_addon` WHERE (`guid`=241142);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(241142, '241142', 0, 0, 1, 0, '');

-- Waypoint movement type
UPDATE `creature` SET `MovementType`='2' WHERE `guid`='241142';

-- Waypoint data
DELETE FROM `waypoint_data` WHERE `id`='241142';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('241142','1','-565.394','-4213.93','41.5907','50000','0','0','100','0'),
('241142','2','-564.592','-4214.96','41.5907','0','0','0','100','0'),
('241142','3','-563.072','-4216.3','42.5347', '8000','0','241142','100','0'),
('241142','4','-563.95','-4215.27','41.5908','0','0','0','100','0'),
('241142','5','-566.263','-4213.13','41.5908','0','0','0','100','0'),
('241142','6','-565.987','-4213.38','41.5908','0','0','0','100','0');

-- Waypoint Script
DELETE FROM waypoint_scripts WHERE id='241142';
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
('241142','1','1','10','1','0','0','0','0','0','241142');

-- Galgar
SET @ENTRY := 9796;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,0,51000,51000,60000,62000,1,0,58000,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On Duokna Dance Galbar talk");

-- type es el tipo de mensaje que dice
DELETE FROM `creature_text`WHERE `entry` IN ('9796'); 
INSERT INTO `creature_text` VALUES
('9796','0','0','Duokna... this is embarrassing.','0','0','1','0','0','0','Galbar');

-- VISUAL: Zlack Waypoints and enotes Taking from oficial (http://www.wowhead.com/npc=3882)
-- Set wp for creature
DELETE FROM `creature_addon` WHERE (`guid`=242610);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(242610, '242610', 0, 0, 1, 0, '');

-- Waypoint movement type
UPDATE `creature` SET `MovementType`='2' WHERE `guid`='242610';

-- Waypoint data
DELETE FROM `waypoint_data` WHERE `id`='242610';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('242610','1','-560.125','-4217.2','41.5906','10000','0','242610','100','0'),
('242610','2','-559.408','-4216.28','41.5906','0','0','0','100','0'),
('242610','3','-561.054','-4217.5','41.5906','10000','0','242611','100','0'),
('242610','4','-560.413','-4217.22','41.5906','0','0','0','100','0');
-- Waypoint Script
DELETE FROM waypoint_scripts WHERE id IN ('242610','242611');
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
('242610','1','1','233','1','0','0','0','0','0','242610'),
('242611','1','1','69','1','0','0','0','0','0','242611');