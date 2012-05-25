-- DB/CREATURE: Fix loc for Zureetha Fargaze & Foreman Thazz'ril
-- Zureetha Fargaze Correct loc taking from official (http://www.wowhead.com/npc=3444)
DELETE FROM `creature` WHERE `id`=3145;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(3444, 3145, 1, 1, 1, 1875, 0, -570.444, -4259.98, 38.4273, 5.16581, 600, 0, 0, 247, 0, 0, 0, 0, 0, 0);

-- Foreman Thazz'ril Correct loc taking from official (http://www.wowhead.com/npc=11378)
DELETE FROM `creature` WHERE `id`=11378;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(1067886, 11378, 1, 1, 1, 0, 11378, -568.634, -4263.77, 38.7134, 1.88599, 600, 0, 0, 86, 0, 0, 0, 0, 0, 0);

-- Foreman Thazz'ril
SET @ENTRY := 11378;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,0,5000,6000,19000,20000,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On OCC do emote (radom time)");

-- Zureetha Fargaze
SET @ENTRY := 3145;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,0,5500,6500,19500,25000,5,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On OCC do emote (radom time)");