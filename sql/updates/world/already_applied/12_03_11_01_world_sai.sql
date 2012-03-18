 
   /* Dungeon Normal-Heroic for 5 people */
    /* Trash Mobs */
	
-- Bleeding Hollow Archer
SET @ENTRY := 17270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,2,61,0,100,7,0,0,0,0,11,18651,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot on Aggro'),
(@ENTRY,0,2,3,61,0,100,7,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Melee Attack on Aggro'),
(@ENTRY,0,3,0,61,0,100,7,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,4,5,9,1,100,6,5,30,2300,3900,11,18651,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,5,0,61,1,100,6,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Ranged Weapon Model'),
(@ENTRY,0,6,7,9,1,100,6,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Shoot Range'),
(@ENTRY,0,7,0,61,1,100,6,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Melee Attack when not in Shoot Range'),
(@ENTRY,0,8,9,9,1,100,6,0,10,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Shoot Range'),
(@ENTRY,0,9,10,61,1,100,6,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Melee Weapon Model when not in Shoot Range'),
(@ENTRY,0,10,0,61,1,100,6,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Melee Attack when not in Shoot Range'),
(@ENTRY,0,11,12,9,1,100,6,11,25,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 25 Yards'),
(@ENTRY,0,12,13,61,1,100,6,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Melee Attack at 25 Yards'),
(@ENTRY,0,13,0,61,1,100,6,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Ranged Weapon Model at 25 Yards'),
(@ENTRY,0,14,15,7,1,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Melee Weapon Model on Evade'),
(@ENTRY,0,15,0,61,1,100,7,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,16,5,9,1,100,6,5,30,15000,19000,11,18651,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,17,0,4,0,10,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 17270;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The blood is our power!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'We are the true Horde!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'This world is OURS!',1,0,50,0,0,0, 'on Aggro Text');

-- Bleeding Hollow Darkcaster
SET @ENTRY := 17269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,9000,12000,11,15241,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,30,9000,12000,11,36807,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch on Close'),
(@ENTRY,0,2,0,0,0,100,2,11000,31000,22000,45000,11,31598,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,3,0,0,0,100,4,11000,31000,22000,45000,11,36808,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire');

-- Bleeding Hollow Scryer
SET @ENTRY := 17478;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,4,1,100,3,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4700,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,9,1,100,2,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@ENTRY,0,5,0,9,1,100,2,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,6,0,9,1,100,2,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@ENTRY,0,7,0,3,1,100,2,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@ENTRY,0,8,0,3,2,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@ENTRY,0,10,0,4,0,100,5,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,11,0,4,1,100,5,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,12,0,4,1,100,5,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@ENTRY,0,13,0,9,1,100,4,0,40,3400,4700,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,14,0,9,1,100,4,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@ENTRY,0,15,0,9,1,100,4,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,16,0,9,1,100,4,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@ENTRY,0,17,0,3,1,100,4,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@ENTRY,0,18,0,3,2,100,4,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@ENTRY,0,19,0,3,2,100,4,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@ENTRY,0,20,0,0,1,100,6,6000,23000,17000,23000,11,30615,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Fear'),
(@ENTRY,0,21,0,6,1,100,7,0,0,0,0,11,30659,3,0,0,0,0,11,17281,30,0,0,0,0,0,'Cast Fel Infusion on Death'),
(@ENTRY,0,22,0,1,1,100,7,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Aura on Spawn'),
(@ENTRY,0,23,0,4,1,10,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 17478;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The blood is our power!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'We are the true Horde!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'This world is OURS!',1,0,50,0,0,0, 'on Aggro Text');

-- Bonechewer Beastmaster
SET @ENTRY := 17455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,4500,12000,15000,20000,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,2,0,0,0,100,6,2000,10000,11000,21000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut'),
(@ENTRY,0,3,4,0,0,100,7,20000,20000,0,0,32,17280,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summon Warhounds'),
(@ENTRY,0,4,5,61,0,100,7,0,0,0,0,32,17280,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summon Warhounds'),
(@ENTRY,0,5,6,61,0,100,7,0,0,0,0,32,17280,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summon Warhounds'),
(@ENTRY,0,6,0,61,0,100,7,0,0,0,0,32,17280,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summon Warhounds'),
(@ENTRY,0,7,0,0,0,100,7,20000,20000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Text on Summon Warhounds');
-- NPC talk text insert
SET @ENTRY := 17455;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Hold them back while I release the warhounds!',1,0,100,0,0,10160, 'on Aggro Text'),
(@ENTRY,1,0, 'My pets are hungry and they will dine on your flesh!',1,0,100,0,0,10161, 'on Aggro Text');

-- Bonechewer Destroyer
SET @ENTRY := 17271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,6000,21000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,19000,31000,12000,32000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away'),
(@ENTRY,0,2,0,4,0,10,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 17271;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The blood is our power!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'We are the true Horde!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'This world is OURS!',1,0,50,0,0,0, 'on Aggro Text');

-- Bonechewer Hungerer
SET @ENTRY := 17259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,3000,6000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,2000,9000,30000,34000,11,16244,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout'),
(@ENTRY,0,2,0,4,0,10,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,3,0,0,0,100,6,4000,15000,5000,24000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarm'),
(@ENTRY,0,4,0,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,5,0,2,0,100,7,0,15,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP');
-- NPC talk text insert
SET @ENTRY := 17259;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The blood is our power!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'We are the true Horde!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'This world is OURS!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, '%s attempts to run away in fear!',2,0,100,0,0,0, 'combat Flee');

-- Bonechewer Ravener
SET @ENTRY := 17264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,180000,240000,180000,240000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,1,0,0,0,100,6,3000,8000,20000,30000,11,30621,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kidney Shot'),
(@ENTRY,0,2,0,4,0,10,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 17264;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The blood is our power!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'We are the true Horde!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'This world is OURS!',1,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'You there!  Keep a close watch on these ramparts, intruders could approach at any time!',1,0,100,0,0,0, 'OOC Text');

-- Bonechewer Ripper
SET @ENTRY := 17281;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,18501,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17281;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',2,0,100,0,0,0, 'combat Enrage');

-- Fiendish Hound
SET @ENTRY := 17540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,8000,11000,13000,11,15785,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mana Burn'),
(@ENTRY,0,1,0,2,0,100,6,0,30,7000,10000,11,35748,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drain Life at 30% HP');

-- Hellfire Sentry <Herald's Sentry>
SET @ENTRY := 17517;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,8000,20000,24000,11,30621,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kidney Shot');

-- Hellfire Watcher <Watchkeeper's Subordinate>
SET @ENTRY := 17517;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,10000,10000,31000,11,14032,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,1,0,14,0,100,2,15000,40,12000,20000,11,12039,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,2,0,14,0,100,4,50000,40,12000,20000,11,30643,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,3,0,2,0,100,6,0,50,20000,25000,11,8362,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew at 50% HP');

-- Shattered Hand Warhound
SET @ENTRY := 17280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,13000,25000,11,30636,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Howl'),
(@ENTRY,0,1,0,0,0,100,6,3000,7500,4000,8000,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite');

