-- Crazed Guard
-- By Mikadmin for Arkania
-- Fix template & SmartAI

SET @ENTRY := 47130;
SET @SOURCETYPE := 0;

UPDATE `creature_template` SET `minlevel` = '82',
`exp` = '3',
`AIName`="SmartAI" WHERE `creature_template`.`entry` =@ENTRY LIMIT 1;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,500,4900,9000,19000,11,79721,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Crazed Guard"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,500,4900,9000,19000,11,6660,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Crazed Guard");
