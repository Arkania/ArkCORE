-- DB/SAY ACTION: Fix phases for Pusillin timers
-- Pusillin Phase mask 5
SET @ENTRY := 1435402;
SET @SOURCETYPE := 9;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 3 - Close Gossip"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 3 - Turn Off Gossip Flags"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 3 - Say Text 2"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,22,5,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 3 - Set Phase to 5"),
(@ENTRY,@SOURCETYPE,4,0,0,0,100,0,0,0,0,0,53,1,287080,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 3 - Start Waypoint Movement");

-- Pusillin Phase mask 6
SET @ENTRY := 1435403;
SET @SOURCETYPE := 9;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 4 - Close Gossip"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 4 - Turn Off Gossip Flags"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 4 - Say Text 3"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,0,0,0,0,0,22,6,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 4 - Set Phase to 16"),
(@ENTRY,@SOURCETYPE,4,0,0,0,100,0,0,0,0,0,53,1,430620,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Pusillin - On Script 4 - Start Waypoint Movement");