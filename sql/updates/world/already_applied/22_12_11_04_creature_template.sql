-- Battlefront Triage (Deepholm) Questfix
-- by Naios for Arkania

UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35 WHERE `entry`=43229 LIMIT 1;

-- Injured Earthen
SET @ENTRY := 43229;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,1,8,0,100,0,80987,0,0,0,33,43229,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Give Kill Monster Credit on Quest item Heal"),
(@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Despawn - Bad style but prevents that a Player ca finish the Quest with the same Creature");
