UPDATE `creature_template` SET `mechanic_immune_mask` = 1048576 WHERE `entry` IN (39985, 39986, 39708, 39987, 39988, 39994, 40021, 40019, 40017, 40023, 39709, 39980, 39981, 39982, 39978, 39979, 39983, 48143, 40251, 40252, 40808, 40311, 48139, 48140);
UPDATE creature SET spawntimesecs=86400 WHERE map in (644, 645, 755, 670, 725, 657, 33, 36);

UPDATE `arkcore_string` SET `content_default` = '%d (Entry: %d) - |cffffffff|Hgameobject:%d|h[%s X:%f Y:%f Z:%f MapId:%d]|h|r' WHERE `entry` = '517';

insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('192571','644','1','1','-954.292','457.565','51.9705','1.55269','0','0','0.700676','0.713479','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('192570','644','2','1','-954.292','457.565','51.9705','1.55269','0','0','0.700676','0.713479','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('203133','644','3','1','-671.668','319.531','52.9673','4.82682','0','0','0.665514','-0.746385','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('203136','644','3','1','-609.758','322.384','53.1516','4.77576','0','0','0.684349','-0.729155','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('204858','645','2','1','211.429','1138.93','206.146','4.6767','0','0','0.719611','-0.694377','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('204858','0','1','1','-7570.9','-1328.64','245.538','1.638','0','0','0.730463','0.682952','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('204857','0','1','1','-7570.9','-1328.64','245.538','1.638','0','0','0.730463','0.682952','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('204857','645','1','1','211.429','1138.93','206.146','4.6767','0','0','0.719611','-0.694377','300','0','1');

UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `Health_mod` = 8 WHERE `entry` = 39987;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 50284;
UPDATE `creature_template` SET `exp` = 3, `Health_mod` = 24, `Mana_mod` = 50 WHERE `entry` = 39679;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `Health_mod` = 8 WHERE `entry` = 39994;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 40004;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `exp` = 3, `Health_mod` = 20 WHERE `entry` = 39698;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `exp` = 3, `Health_mod` = 20 WHERE `entry` = 39700;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `Health_mod` = 8 WHERE `entry` IN (40011, 40008, 40015, 40013);
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 39980;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 39708;
UPDATE `creature_template` SET `exp` = 3, `Health_mod` = 20 WHERE `entry` = 39665;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `Health_mod` = 8 WHERE `entry` = 39978;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 39982;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 39985;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 40019;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 40017;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 40019;
UPDATE `creature_template` SET `minlevel` = 81, `maxlevel` = 81, `Health_mod` = 8 WHERE `entry` = 40023;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `Health_mod` = 4 WHERE `entry` = 40021;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `faction_A` = 14, `faction_H` = 14, `Health_mod` = 8 WHERE `entry` = 40817;
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `exp` = 3, `Health_mod` = 20 WHERE `entry` = 39705;
UPDATE `creature_template` SET `Health_mod` = 42.40 WHERE `entry` = 39666;
UPDATE `creature_template` SET `exp` = 3, `Health_mod` = 50, `Mana_mod` = 42.3 WHERE `entry` = 39680;
UPDATE `creature_template` SET `exp` = 3, `Health_mod` = 46.3 WHERE `entry` = 39699;
UPDATE `creature_template` SET `minlevel` = 85, `maxlevel` = 85, `exp` = 3, `Health_mod` = 10, `mindmg` = 750, `maxdmg`= 980, `dmg_multiplier` = 15 WHERE `entry` = 40022;
UPDATE `creature_template` SET `exp` = 3, `Health_mod` = 50 WHERE `entry` = 39706;
UPDATE `creature_template` SET `exp` = 3, `Health_mod` = 20 WHERE `entry` = 39701;
UPDATE `creature_template` SET `minlevel` = 85, `maxlevel` = 85, `Health_mod` = 6 WHERE `entry` IN (49308, 49309, 49307);
UPDATE `creature_template` SET `minlevel` = 85, `maxlevel` = 85, `Health_mod` = 12.7 WHERE `entry` = 49310;
UPDATE `creature_template` SET `minlevel` = 85, `maxlevel` = 85, `exp` = 3, `Health_mod` = 1, `dmg_multiplier` = 13 WHERE `entry` = 40810;
UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14, `minlevel` = 85, `maxlevel` = 85, `exp` = 3, `mindmg` = 801, `maxdmg` = 1113, `attackpower` = 1220, `dmg_multiplier` = 13, `Health_mod` = 1 WHERE `entry` = 40458;
UPDATE `creature_template` SET `minlevel` = 87, `maxlevel` = 87, `Health_mod` = 42.8 WHERE `entry` = 48714;
UPDATE `creature_template` SET `minlevel` = 87, `maxlevel` = 87, `Health_mod` = 46.3 WHERE `entry` = 48902;
UPDATE `creature_template` SET `minlevel` = 87, `maxlevel` = 87, `Health_mod` = 46.3 WHERE `entry` = 48815;
UPDATE `creature_template` SET `exp` = 3, `minlevel` = 87, `maxlevel` = 87, `Health_mod` = 35 WHERE `entry` = 48776;
UPDATE `creature_template` SET `exp` = 3, `minlevel` = 87, `maxlevel` = 87, `Health_mod` = 27 WHERE `entry` = 48715;
UPDATE `creature_template` SET `minlevel` = 87, `maxlevel` = 87, `Health_mod` = 27 WHERE `entry` = 48710;

UPDATE creature_template SET equipment_id=39425 WHERE entry in (49262, 39425);
update creature_template set equipment_id=48141 where entry in (48141, 49309);
update creature_template set equipment_id=48139 where entry in (48139, 49307);
update creature_template set equipment_id=48140 where entry in (48140, 49308);
UPDATE creature_template SET equipment_id=40808 WHERE entry in (40808, 49302);
UPDATE creature_template SET equipment_id=39708 WHERE entry IN (39708, 39709);
UPDATE creature_template SET equipment_id=39679 WHERE entry IN (39679, 39680);
UPDATE creature_template SET equipment_id=39698 WHERE entry IN (39698, 39699);
UPDATE creature_template SET equipment_id=39665 WHERE entry IN (39665, 39666);
UPDATE creature_template SET equipment_id=39705 WHERE entry IN (39705, 39706);

delete from `creature_equip_template` where `entry` in (40808, 48139, 48141, 48140, 39679, 39708, 39698, 39665, 39705, 48141, 48139 );
insert into `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) values('40808','55298','0','55298');
insert into `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) values('48139','55304','0','55304');
insert into `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) values('48141','55410','0','0');
insert into `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) values('48140','55388','0','0');
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES('39679','51402','0','0');
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES('39708','42391','0','0');
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES('39698','47233','0','0');
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES('39665','63790','63790','0');
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES('39705','55462','0','0');

UPDATE creature_template SET difficulty_entry_1=48815 WHERE entry=39378;
UPDATE creature_template SET difficulty_entry_1=48715 WHERE entry=39731;
UPDATE creature_template SET dmg_multiplier=13 WHERE entry IN (48715, 48815);

SET @ENTRY := 48140;
SET @SOURCETYPE := 0;
UPDATE creature_template SET Health_mod=9 WHERE entry = @ENTRY; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,2,1000,2000,5000,10000,11,89551,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"48140 - Curse of the runecaster"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,2,1000,1200,4000,4200,11,89554,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"48140- Runic cleave"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,4,1000,2000,5000,10000,11,95181,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"48140 - Curse of the runecaster"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,4,1000,1200,4000,4200,11,91806,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"48140- Runic cleave");

SET @ENTRY := 48141;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,6,1000,1500,12000,20000,11,89560,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Temple Shadowlancer - Cast Pact of Darkness"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,6,2000,3000,20000,30000,11,89555,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Temple Shadowlancer - Cast Shadowlance");

SET @ENTRY := 48139;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,2,1000,2000,15000,20000,11,89571,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Temple Swiftstalker cast Charged Shot"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,5000,10000,10000,20000,11,84836,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Type a script description here."),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,500,1000,1000,3000,11,83877,0,0,0,0,0,6,0,0,0,0.0,0.0,0.0,0.0,"Type a script description here."),
(@ENTRY,@SOURCETYPE,3,0,4,0,100,6,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Temple Swiftstalker on aggro stop"),
(@ENTRY,@SOURCETYPE,4,0,0,0,100,4,1000,2000,15000,20000,11,94971,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Temple Swiftstalker cast Charged Shot");

SET @ENTRY := 48143;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,6,5000,5500,24000,25000,11,89547,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Blazing eruption- 48143- Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,1000,1200,7500,8000,11,89538,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Fireball -48143- Normal"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,10000,12000,10000,12000,11,84032,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Meteor-48143-Normal"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,6,15000,16000,40000,45000,11,89542,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Molten Barrier-48143-ALL"),
(@ENTRY,@SOURCETYPE,4,0,0,0,100,0,1000,1200,7500,8000,11,89854,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Fireball -48143- HERO"),
(@ENTRY,@SOURCETYPE,5,0,0,0,100,0,10000,12000,10000,12000,11,90023,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Meteor-48143-HERO"),
(@ENTRY,@SOURCETYPE,6,0,4,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On aggro stop");

SET @ENTRY := 40251;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,2,1000,4000,12000,15000,11,77373,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Clobber-40251-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,4,1000,4000,12000,15000,11,91169,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Clobber-40251-HERO");

SET @ENTRY := 40252;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,2,2000,5000,12000,15000,11,77389,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Stone Throw-40252-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,4,2000,5000,12000,15000,11,91165,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Stone Throw-40252-Normal");

SET @ENTRY := 40808;
SET @SOURCETYPE := 0;
DELETE FROM `creature_equip_template` WHERE (`entry`=40808);
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES (40808, 55298, '0', 55298);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,6,2000,5000,6000,8000,11,75453,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Smash-40808-ALL");

SET @ENTRY := 40311;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,2,3000,4000,10000,12000,11,77357,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Curse of exhaustion-40311-normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,2,1000,1200,4000,6000,11,77570,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Shadow Bolt-40311-Normal"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,4,3000,4000,10000,12000,11,90006,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Curse of exhaustion-40311-HERO"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,4,1000,1200,4000,6000,11,89855,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Shadow Bolt-40311-HERO");

SET @ENTRY := 39373;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,2,1000,3000,5000,7000,11,75241,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Sun-Touched Speaker - Reverberating Stomp - Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,6,3000,7000,7000,9000,11,73861,0,0,0,0,0,6,0,0,0,0.0,0.0,0.0,0.0,"Sun-Touched Speaker - Firestorm - ALL"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,2,1000,3000,5000,7000,11,89851,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Sun-Touched Speaker - Reverberating Stomp - HERO");

SET @ENTRY := 39366;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,2,3000,5000,5000,60000,11,76160,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Sun-Touched Servant - Flame Dispersion - Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,2,2000,3000,4000,5000,11,74101,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Sun-Touched Servant - Searing Flames - Normal"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,4,3000,5000,5000,60000,11,89852,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Sun-Touched Servant - Flame Dispersion - HERO"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,4,2000,3000,4000,5000,11,89849,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Sun-Touched Servant - Searing Flames - HERO");

SET @ENTRY := 39708;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,3000,3200,10000,10000,11,76473,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Blastwave-39708-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,1000,1200,4000,5000,11,89538,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Callflames-39708-Normal-Sustituido por Fireball 89538");

SET @ENTRY := 39980;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,2000,7000,7200,11,76502,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Heart Seeker Blade-39980-Normal"),
(@ENTRY,@SOURCETYPE,1,2,0,0,100,0,4000,5000,6000,7000,11,76500,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Sinister Stryke-39980-Normal"),
(@ENTRY,@SOURCETYPE,2,1,0,0,100,0,1500,2000,10000,10000,11,76497,1,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Inflict Pain-39980-Normal");

SET @ENTRY := 39982;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1000,4000,4000,6000,11,41486,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Frostbolt-76058-Normal-Cambiado por 41486"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,6000,6000,10000,11,76509,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Frost nova-76509-Normal"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,3000,6000,30000,30000,11,54792,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Icy Veins-54792-Normal");

SET @ENTRY := 39978;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,4000,8000,12000,11,76478,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Red-hot Poker-76487-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2000,6000,14000,16000,11,76484,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Shackles-76484-Normal"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,4000,8000,12000,14000,11,76487,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Wild Beatdown-76487-Normal");

SET @ENTRY := 39985;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,4000,5000,10000,14000,11,77568,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Head Crack-77568-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,6000,9000,7000,18000,11,76512,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Infected Wound-76512-Normal"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,40000,45000,120000,180000,11,8599,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Enrage-8599.Normal");

SET @ENTRY := 39987;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,5000,12000,20000,22000,11,82362,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Shadow Strike-82362-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,6000,5000,6000,11,76524,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Grievous Whirl-76524-Normal"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,10000,12000,25000,32000,11,76561,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Gravity Strike-76561-Normal");

SET @ENTRY := 39994;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,2000,5000,8000,14000,11,76618,2,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Inmolate-76618-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2000,6000,7000,12000,11,76617,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Heat Exhaustion-76617-Normal");

SET @ENTRY := 40021;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1500,4000,6000,10000,11,72024,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Fireball-76719-Normal-cambiado por 72024");

SET @ENTRY := 40019;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,4000,8000,10000,13000,11,76688,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Bore-76688-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,5000,8000,10000,11000,11,76686,2,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Shadow prison-76686-Normal");

SET @ENTRY := 40017;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,6000,8000,6000,10000,11,76680,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Chain lighting-76680-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2000,5000,4000,10000,11,76677,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Fire Blast-76677-Normal"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,5000,12000,15000,22000,11,76682,2,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Frostbomb-76682-normal");

SET @ENTRY := 40023;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,10000,15000,22000,25000,11,76717,0,0,0,0,0,5,0,0,0,0.0,0.0,0.0,0.0,"Meteor-76717-Normal"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,5000,10000,12000,15000,11,76716,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Bludgeoning Strike-76716-Normal");

DELETE FROM `creature_loot_template` WHERE `entry` = 39665;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39665,55278,0,1,1,1,1),
(39665,55279,0,1,1,1,1),
(39665,55776,0,1,1,1,1),
(39665,55777,0,1,1,1,1),
(39665,55778,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `entry` = 39666;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39666,56310,0,1,1,1,1),
(39666,56311,0,1,1,1,1),
(39666,56312,0,1,1,1,1),
(39666,56313,0,1,1,1,1),
(39666,56314,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `entry` = 39679;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39679,55263,0,1,1,1,1),
(39679,55264,0,1,1,1,1),
(39679,55265,0,1,1,1,1),
(39679,55266,0,1,1,1,1),
(39679,55267,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `entry` = 39680;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39680,56295,0,1,0,1,1),
(39680,56296,0,1,0,1,1),
(39680,56297,0,1,0,1,1),
(39680,56298,0,1,0,1,1),
(39680,56299,0,1,0,1,1);

DELETE FROM `creature_loot_template` WHERE `entry` = 39698;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39698,55268,0,1,1,1,1),
(39698,55269,0,1,1,1,1),
(39698,55270,0,1,1,1,1),
(39698,55271,0,1,1,1,1),
(39698,55272,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `entry` = 39699;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39699,56300,0,1,1,1,1),
(39699,56301,0,1,1,1,1),
(39699,56302,0,1,1,1,1),
(39699,56303,0,1,1,1,1),
(39699,56304,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `entry` = 39700;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39700,55273,0,1,1,1,1),
(39700,55274,0,1,1,1,1),
(39700,55275,0,1,1,1,1),
(39700,55276,0,1,1,1,1),
(39700,55277,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `entry` = 39701;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39701,56305,0,1,1,1,1),
(39701,56306,0,1,1,1,1),
(39701,56307,0,1,1,1,1),
(39701,56308,0,1,1,1,1),
(39701,56309,0,1,1,1,1);

DELETE FROM `creature_loot_template` WHERE `entry` = 39705;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39705,52506,-100,1,1,1,1),
(39705,55779,0,1,2,1,1),
(39705,55780,0,1,2,1,1),
(39705,55781,0,1,2,1,1),
(39705,55782,0,1,2,1,1),
(39705,55783,0,1,2,1,1),
(39705,55784,0,1,3,1,1),
(39705,55785,0,1,3,1,1),
(39705,55786,0,1,3,1,1),
(39705,55787,0,1,3,1,1),
(39705,55788,0,1,3,1,1);

DELETE FROM `creature_loot_template` WHERE `entry` = 39706;
INSERT INTO `creature_loot_template` (`entry`,`item`,`chanceOrQuestChance`,`lootmode`,`groupid`,`mincountorref`,`maxcount`) VALUES 
(39706,52506,-100,1,1,1,1),
(39706,52078,100,1,2,1,1),
(39706,56315,0,1,3,1,1),
(39706,56316,0,1,3,1,1),
(39706,56317,0,1,3,1,1),
(39706,56318,0,1,3,1,1),
(39706,56319,0,1,3,1,1),
(39706,56320,0,1,4,1,1),
(39706,56321,0,1,4,1,1),
(39706,56322,0,1,4,1,1),
(39706,56323,0,1,4,1,1),
(39706,56324,0,1,4,1,1);

UPDATE vehicle_accessory SET minion=1  WHERE entry IN (32633, 32640);
DELETE FROM creature_loot_template WHERE item IN (45624, 49426, 40752, 47241, 40753, 43228, 29434);
DELETE FROM gameobject_loot_template WHERE item IN (45624, 49426, 40752, 47241, 40753, 43228, 29434);
DELETE FROM `spell_proc_event` WHERE `entry` IN (35104, 35110);
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) values
('35104','0','9','4096','0','0','0','2','0','0','0');
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) values
('35110','0','9','4096','0','0','0','2','0','0','0');
UPDATE spell_proc_event SET SpellFamilyMask0=1792 WHERE entry IN (51632, 91023);
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) values('84800','0','10','1073741824','0','1024','0','0','0','0','0');
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) values('85511','0','10','1073741824','0','1024','0','0','0','0','0');
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) values('85512','0','10','1073741824','0','1024','0','0','0','0','0');
UPDATE creature_template SET flags_extra=1 WHERE entry IN (48815,49262,48714,48710,39666,39680,39699,39701,39706,48715,48776,48902,49079,49064,49082,48951,49043,43874,43876,43879,48932,51088,49045);

delete from spell_proc_event where entry=89086;
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) values('89086','0','0','0','0','0','0','0','0','0','45');
delete from spell_proc_event where entry=92044;
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) values('92044','0','0','0','0','0','0','0','0','0','45');
DELETE FROM spell_proc_event WHERE entry IN (92097, 92095);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES('92097','0','0','0','0','0','0','0','0','0','45');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES('92095','0','0','0','0','0','0','0','0','0','45');
DELETE FROM spell_proc_event WHERE entry IN (91369, 91366);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES('91369','0','0','0','0','0','0','0','0','0','45');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES('91366','0','0','0','0','0','0','0','0','0','45');
DELETE FROM spell_proc_event WHERE entry IN (92070, 92093);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES('92070','0','0','0','0','0','0','0','0','0','45');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES('92093','0','0','0','0','0','0','0','0','0','45');
SET @SPELL :=92164;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','0','80');
SET @SPELL :=92175;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','0','80');
SET @SPELL :=91137;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','0','75');
SET @SPELL :=91140;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','0','75');
SET @SPELL :=91366;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','0','50');
SET @SPELL :=91369;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','0','50');
SET @SPELL :=92056;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','30','45');
SET @SPELL :=91142;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','10','45');
SET @SPELL :=91144;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','10','45');
SET @SPELL :=92180;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','0','45');
SET @SPELL :=92185;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','0','45');
SET @SPELL :=92221;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','15','60');
SET @SPELL :=91193;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','10','40');
SET @SPELL :=91148;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','20','105');
SET @SPELL :=91150;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','20','105');
SET @SPELL :=92217;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','15','60');
DELETE FROM spell_proc_event WHERE entry IN (90888, 90886);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
('90888','0','0','0','0','0','0','0','0','0','75');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
('90886','0','0','0','0','0','0','0','0','0','75');
DELETE FROM spell_proc_event WHERE entry=89088;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
('89088','0','0','0','0','0','0','0','0','30','45');
SET @SPELL :=90892;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','10','120');
SET @SPELL :=91048;
DELETE FROM spell_proc_event WHERE entry=@SPELL;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(@SPELL,'0','0','0','0','0','0','0','0','10','75');
