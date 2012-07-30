 
  /* Dungeon Normal & Heroic for 5 people */
 /* Trash Mobs */
 
-- Bonesnapper Scorpid
SET @ENTRY := 45063;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,4500,15000,16000,11,84125,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Paralytic Venom'),
(@ENTRY,0,1,0,0,0,100,4,3000,4500,15000,16000,11,90022,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Paralytic Venom');

-- Frenzied Crocolisk
SET @ENTRY := 43658;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4500,11000,12000,11,81677,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite'),
(@ENTRY,0,1,0,0,0,100,4,4000,4500,11000,12000,11,89999,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite');

-- Harbinger of Darkness
SET @ENTRY := 43927;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,9000,22000,26000,11,82255,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Sever'),
(@ENTRY,0,1,0,0,0,100,2,4000,5000,15000,16000,11,82533,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wail of Darkness'),
(@ENTRY,0,2,0,0,0,100,4,4000,5000,15000,16000,11,90038,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wail of Darkness');

-- Minion of Siamat
SET @ENTRY := 44704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,3000,11000,13000,11,83455,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,0,0,100,4,2000,3000,11000,13000,11,90027,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chain Lightning');

-- Neferset Darkcaster
SET @ENTRY := 44982;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,4,1,100,3,0,0,0,0,11,82765,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4700,11,82765,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,9,1,100,2,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@ENTRY,0,5,0,9,1,100,2,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,6,0,9,1,100,2,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@ENTRY,0,7,0,3,1,100,2,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@ENTRY,0,8,0,3,2,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@ENTRY,0,10,0,4,0,100,5,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,11,0,4,1,100,5,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,12,0,4,1,100,5,0,0,0,0,11,90036,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@ENTRY,0,13,0,9,1,100,4,0,40,3400,4700,11,90036,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,14,0,9,1,100,4,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@ENTRY,0,15,0,9,1,100,4,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,16,0,9,1,100,4,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@ENTRY,0,17,0,3,1,100,4,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@ENTRY,0,18,0,3,2,100,4,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@ENTRY,0,19,0,3,2,100,4,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@ENTRY,0,20,0,0,1,100,2,8000,12000,25000,28000,11,84032,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Meteor'),
(@ENTRY,0,21,0,0,1,100,6,5000,9000,26000,32000,11,82760,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hex'),
(@ENTRY,0,22,0,0,1,100,4,8000,12000,25000,28000,11,90023,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Meteor');

-- Neferset Plaguebringer
SET @ENTRY := 44976;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,15000,19000,11,73976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disease Breath'),
(@ENTRY,0,1,0,0,0,100,4,5000,7000,15000,19000,11,90005,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disease Breath'),
(@ENTRY,0,2,0,0,0,100,4,3000,4000,13000,22000,11,82768,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infectious Plague');

-- Neferset Theurgist
SET @ENTRY := 44980;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,82759,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mixture of Harnessed Rage at 30% HP'),
(@ENTRY,0,1,0,0,0,100,2,2000,3500,12000,13000,11,82753,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ritual of Bloodletting'),
(@ENTRY,0,2,0,0,0,100,4,2000,3500,12000,13000,11,89993,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ritual of Bloodletting'),
(@ENTRY,0,3,0,0,0,100,6,8000,12000,26000,33000,11,82757,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Vicious Leeches');

-- Neferset Torturer
SET @ENTRY := 44977;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,12000,16000,11,82744,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Branded Tongue'),
(@ENTRY,0,1,0,0,0,100,4,3000,5000,12000,16000,11,90037,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Branded Tongue'),
(@ENTRY,0,2,0,0,0,100,2,8000,11000,26000,33000,11,82750,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Serum of Torment'),
(@ENTRY,0,3,0,0,0,100,4,8000,11000,26000,33000,11,89994,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Serum of Torment');

-- Oathsworn Axemaster
SET @ENTRY := 44922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4500,12000,13000,11,84256,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skull Crush'),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,18000,23000,11,82763,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam');

-- Oathsworn Captain
SET @ENTRY := 45122;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,6000,14000,17000,11,82670,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skull Crush');

-- Oathsworn Myrmidon
SET @ENTRY := 44924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,16000,22000,11,82671,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bladed Shield Spike'),
(@ENTRY,0,1,0,0,0,100,4,5000,7000,16000,22000,11,95184,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bladed Shield Spike'),
(@ENTRY,0,2,0,2,0,100,6,0,40,22000,27000,11,82673,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Resistance at 40% HP');

-- Oathsworn Pathfinder
SET @ENTRY := 44932;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,2,61,0,100,7,0,0,0,0,11,83877,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot on Aggro'),
(@ENTRY,0,2,3,61,0,100,7,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Melee Attack on Aggro'),
(@ENTRY,0,3,0,61,0,100,7,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,4,5,9,1,100,6,5,30,2300,3900,11,83877,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
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
(@ENTRY,0,16,0,1,0,100,7,3000,5000,0,0,11,82792,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Call Falcon on Spawn'),
(@ENTRY,0,17,0,9,1,100,6,0,5,15000,18000,11,82764,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip on Close');

-- Oathsworn Scorpid Keeper
SET @ENTRY := 45062;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,3000,5000,0,0,11,84126,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Call Scorpid on Spawn'),
(@ENTRY,0,1,0,0,0,100,6,7000,8000,17000,20000,11,84123,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blink'),
(@ENTRY,0,2,0,2,0,100,6,0,40,16000,24000,11,84122,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion at 40% HP');

-- Oathsworn Skinner
SET @ENTRY := 44981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,15000,17000,11,82789,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,10,15000,17000,11,90034,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,2,0,0,0,100,6,4000,7000,12000,22000,11,84031,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spinal Pierce');

-- Oathsworn Tamer
SET @ENTRY := 45097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,11000,19000,11,84230,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Feral Spirit Link');

-- Oathsworn Wanderer
SET @ENTRY := 44926;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,2,61,0,100,7,0,0,0,0,11,83877,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot on Aggro'),
(@ENTRY,0,2,3,61,0,100,7,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Melee Attack on Aggro'),
(@ENTRY,0,3,0,61,0,100,7,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,4,5,9,1,100,6,5,30,2300,3900,11,83877,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
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
(@ENTRY,0,16,0,1,0,100,7,3000,5000,0,0,11,82791,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Call Crocolisk on Spawn'),
(@ENTRY,0,17,0,9,1,100,2,5,10,15000,15000,11,82794,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Forked Fire-Shot on Close'),
(@ENTRY,0,18,0,9,1,100,4,5,10,15000,15000,11,89992,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Forked Fire-Shot on Close');

-- Pygmy Brute
SET @ENTRY := 44896;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,3000,11000,14000,11,83783,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale'),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,17000,22000,11,83785,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,2,0,0,0,100,4,2000,3000,11000,14000,11,89990,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale'),
(@ENTRY,0,3,0,0,0,100,4,6000,9000,17000,22000,11,90024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave');

-- Pygmy Firebreather
SET @ENTRY := 44898;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,12000,14000,11,83778,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,1,0,0,0,100,2,7500,8000,19000,22000,11,83776,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dragon\'s Breath'),
(@ENTRY,0,2,0,0,0,100,4,3000,5000,12000,14000,11,90025,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,3,0,0,0,100,4,7500,8000,19000,22000,11,90026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dragon\'s Breath');

-- Pygmy Scout
SET @ENTRY := 44897;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3500,10000,13000,11,83780,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Blow Dart'),
(@ENTRY,0,1,0,0,0,100,4,3000,3500,10000,13000,11,89991,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Blow Dart');

-- Sharptalon Eagle
SET @ENTRY := 44261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,3500,15000,20000,11,89212,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eagle Claw'),
(@ENTRY,0,1,0,0,0,100,4,2000,3500,15000,20000,11,89988,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eagle Claw');

-- Soul Fragment
SET @ENTRY := 43934;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,18000,26000,11,82263,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Merged Souls');

-- Venomfang Crocolisk
SET @ENTRY := 44260;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,11000,12000,11,82767,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite');
