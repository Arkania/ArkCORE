-- Npc Tank
-- By Mikadmin For Arkania

SET @ENTRY := 46608;
SET @SOURCETYPE := 0;

UPDATE `creature_template` SET `exp` = '3',
`AIName` = 'SmartAI' WHERE `creature_template`.`entry` =@ENTRY;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,20000,20000,20000,20000,11,81173,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Tank - Frenzy"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,10000,10000,10000,10000,11,69203,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"tank - Vicious Bite");