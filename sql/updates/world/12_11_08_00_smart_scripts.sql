-- Sethria
-- By mikadmin [www.wow-attitude.com]
-- add mod morph between 50% and 20%.

SET @ENTRY := 41255;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1000,4000,7000,10000,11,78129,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Sethria"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,6000,7000,12000,13000,11,78143,1,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Sethria"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,14000,16000,21000,23000,11,78160,1,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Sethria"),
(@ENTRY,@SOURCETYPE,3,0,2,0,100,0,30,50,0,0,3,41261,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"morph draconide");
