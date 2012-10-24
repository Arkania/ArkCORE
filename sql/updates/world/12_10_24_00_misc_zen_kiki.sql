UPDATE `creature_template` SET `ScriptName`='npc_zenkiki' WHERE `entry`='44904';

DELETE FROM `script_texts` WHERE `npc_entry`='44904';
INSERT INTO `script_texts` VALUES 
(44904, -1799999, 'Youch!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799998, 'Cut it out!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799997, 'Zen\'Kiki is in control!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799996, 'Shapeshift! Over here, nom!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799995, 'Shapeshift! Time for cat form!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799994, 'Shapeshift! On no! Not again...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799993, 'Can Zen\'Kiki get a little nudge?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799992, 'Leap!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799991, 'Pounce!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799990, 'Rawr!!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799989, 'It Burns!!!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799988, 'Ow, mon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
(44904, -1799987, 'Meow!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL);



UPDATE `quest_template` SET `StartScript`='26953', `CompleteScript`='26953' WHERE `entry`='26953';
DELETE FROM `quest_start_scripts` WHERE `id`='26953';
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`) VALUES ('26953', '1', '15', '83819', '2');


DELETE FROM `quest_end_scripts` WHERE `id`='26953';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`) VALUES ('26953', '1', '14', '83819');


--  Adrine Towhide
SET @ENTRY  := 44456;
SET @GOSSIP := 44456;
SET @QUEST := 26953;
SET @QUEST2 := 26954;
SET @SOURCETYPE := 0;
SET @TEXTO := 'Iv Lost Zen\'Kiki';
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@Gossip;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,0,0,9,@QUEST,0,0,0,'','show gossip option if Player has Quest 26953 Taken'),
(15,@GOSSIP,0,0,9,@QUEST2,0,0,0,'','show gossip option if Player has Quest 26954 Taken');
DELETE FROM `gossip_menu_option` WHERE `menu_id` = @GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP,'0','0',@TEXTO,'1','1','0','0','0','0','0',NULL);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI", `npcflag` = 3, `equipment_id`='44863', `gossip_menu_id` = @GOSSIP WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,1,62,0,100,0,@GOSSIP,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0," Adrine Towhide  - On gossip option select - Close gossip"),
(@ENTRY,@SOURCETYPE,1,2,61,0,100,0,0,0,0,0,85,83819,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0," Adrine Towhide - Cast");

