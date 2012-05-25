-- SmartAI Xariona
-- By mikadmin for Arkania

-- Xariona
SET @ENTRY := 50061;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,60000,60000,120000,11,93544,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Twilight Breath"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,0,90000,60000,120000,11,93546,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Twilight Fissure"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,60000,90000,60000,120000,11,93556,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Unleashed Magic"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,0,60000,120000,60000,120000,11,93553,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Twilight Zone");

-- Twilight Fissure
SET @ENTRY := 50431;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,3000,5000,5000,11,93545,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Void Blast");