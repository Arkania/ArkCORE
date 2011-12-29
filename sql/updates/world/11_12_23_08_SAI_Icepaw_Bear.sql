-- SAI: Icepaw Bear (http://www.wowhead.com/npc=29319)
SET @ENTRY := 29319;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1000,1000,8000,11000,11,54632,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Icepaw Bear - In Combat - Cast Claws of Ice"),
(@ENTRY,@SOURCETYPE,1,0,25,0,100,0,0,0,0,0,2,16,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Icepaw Bear - On Reset - Set Faction Back"),
(@ENTRY,@SOURCETYPE,2,0,8,0,100,1,62105,0,0,0,80,2931900,0,2,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Icepaw Bear - On Spellhit - Run Script"),
(@ENTRY,@SOURCETYPE,3,0,62,0,100,0,55000,0,0,0,88,2931901,2931903,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Icepaw Bear - On Gossip Select - Run Random Script");
