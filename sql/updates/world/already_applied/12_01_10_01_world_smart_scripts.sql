-- QUEST http://www.wowhead.com/quest=28201 
SET @ENTRY  := 46333;
SET @KILLC := 46333;
UPDATE `creature_template` SET `AIName`= 'SmartAI', `npcflag`=1 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY, 0 ,0, 1, 64, 0, 100, 0 ,0, 0, 0, 0, 33, @KILLC, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0,'On gossip hello credit for quest 28201'),
(@ENTRY, 0 ,1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ramkahen Laborer - despawn');