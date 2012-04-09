-- The Lone Hunter
-- By Mikadmin For Arkania
-- Fix Faction and SAI

SET @ENTRY := 45450;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;

UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
UPDATE `creature_template` SET `faction_A` = '16',
`faction_H` = '16' WHERE `creature_template`.`entry` =@ENTRY;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,5000,22000,25000,11,3604,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Tendon Rip"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,0,3000,30000,30000,11,3264,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Blood Howl"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,0,2000,20000,20000,11,32901,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Carnivorous Bite");
