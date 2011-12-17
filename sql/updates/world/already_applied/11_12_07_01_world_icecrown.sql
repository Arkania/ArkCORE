-- Webbed Crusader http://old.wowhead.com/npc=30273 & http://old.wowhead.com/npc=30268
UPDATE `creature_template` SET AIName = '', `ScriptName` = 'npc_webbed_crusader' WHERE `entry` IN (30273,30268);
-- cleaning
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30273,30268);

-- Fix Spell "Drop Off Captured Crusader" http://old.wowhead.com/spell=56684 for Quest "Into The Wild Green Yonder" http://www.wowhead.com/quest=13045
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 17 AND SourceEntry = 56684;
INSERT INTO conditions VALUES
(17,0,56684,0,30,192522,10,0,0,'',''),
(17,0,56684,0,29,30407,10,0,0,'','');

-- Quest "The Last Line Of Defense" http://www.wowhead.com/quest=13086
-- Vehicle for Argent Cannon http://www.wowhead.com/npc=30236
UPDATE creature_template SET VehicleId = 160 WHERE entry = 30236;
-- Spell ScriptName fo Argent Cannon
DELETE FROM spell_script_names WHERE spell_id IN (57385,57412);
INSERT INTO spell_script_names VALUES
(57385,'spell_argent_cannon'),
(57412,'spell_argent_cannon');
-- Spell npc_spellclick_spells Argent Cannon Gunner http://old.wowhead.com/spell=57573
DELETE FROM npc_spellclick_spells WHERE npc_entry = 30236;
INSERT INTO  npc_spellclick_spells VALUES
(30236,57573,13086,1,13086,1,0,0,0);
-- "Forgotten Depths Slayer" http://www.wowhead.com/npc=30593 & "Frostbrood Destroyer" http://www.wowhead.com/npc=30575 spawn quick and movement
UPDATE creature_template SET  flags_extra = flags_extra | 64 | 262144 | 268435456 WHERE entry IN (30593,30575);
UPDATE `creature` SET `spawndist` = 30, `MovementType` = 1 WHERE `id` IN (30593,30575);
UPDATE `creature_template` SET `MovementType` = 1 WHERE `entry` IN (30593,30575);
UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 30575;

-- Quest "The Battle For Crusaders' Pinnacle" http://old.wowhead.com/quest=13141
-- Script for NPC "Blessed Banner of the Crusade" http://www.wowhead.com/npc=30891
UPDATE creature_template SET scriptname = 'npc_blessed_banner' WHERE entry = 30891;
UPDATE creature_template SET faction_A = 2068, faction_H = 2068 WHERE entry IN (30986,30984,30987,30989);
UPDATE creature_template SET faction_A = 2131, faction_H = 2131 WHERE entry IN (31003,30919,30900);
DELETE FROM event_scripts WHERE id = 20082;
INSERT INTO event_scripts VALUES
(20082,0,10,30891,600000,0,6418.31,423.00,511.2,5.945);

-- "Captured Crusader" http://www.wowhead.com/npc=30407	- let him use cpp script, fixes mysterious SmartAI problem
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_captured_crusader' WHERE `entry`=30407;
-- cleaning
DELETE FROM `smart_scripts` WHERE `entryorguid`=30407; 

-- Quest "If He Cannot Be Turned" [A] http://www.wowhead.com/quest=12896 & [H] http://www.wowhead.com/quest=12897
-- Quest "It's All Fun and Games" [A] http://www.wowhead.com/quest=12887 & [B] http://www.wowhead.com/quest=12892
-- "The Ocular" http://www.wowhead.com/npc=29747
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|268435456,`AIName`='',`InhabitType`=`InhabitType`|4,`ScriptName`='npc_the_ocular' WHERE `entry`=29747;
UPDATE `creature_model_info` SET `combat_reach`=100 WHERE `modelid`=26533;
-- cleaning
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=29747;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29747;
/*
DELETE FROM `creature_template_addon` WHERE `entry`=29747;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29747,0,0,0,0,0,'55162'); -- The Ocular: Transform
*/
-- "The Ocular - Eye of Acherus Exterior Shell" http://www.wowhead.com/npc=29790
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|2|33554432 WHERE `entry`=29790;
-- condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=30740;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,30740,0,18,1,29747,0,63,'','Eyesore Blaster only target The Oculus');
-- "General Lightsbane" http://www.wowhead.com/npc=29851
UPDATE `creature_template` SET AIName='', `ScriptName`='npc_general_lightsbane' WHERE `entry` = 29851;

-- Quest "Free Your Mind" http://www.wowhead.com/quest=12893
-- "Vile" http://www.wowhead.com/npc=29769, "Lady Nightswood" http://www.wowhead.com/npc=29770 & "The Leaper" http://www.wowhead.com/npc=29840 
UPDATE `creature_template` SET ScriptName = 'npc_free_your_mind' WHERE `entry` IN (29769,29770,29840);
 
-- Quest "Slaves to Saronite" [A] http://www.wowhead.com/quest=13300 & [H] http://www.wowhead.com/quest=13302
-- "Saronite Mine Slave" http://www.wowhead.com/npc=31397
UPDATE `creature_template` SET ScriptName = 'npc_saronite_mine_slave' WHERE `entry` = 31397;


-- Fix Missions Quel'Delar Chain: Thalorien Buscalba
-- Gossip Text
SET @ENTRY := 37552;
SET @TEXTID := 537552;
DELETE FROM gossip_menu WHERE entry=@ENTRY;
INSERT INTO gossip_menu VALUES (@ENTRY, @TEXTID);

-- need more TEXT Not complete
DELETE FROM npc_text WHERE id = @TEXTID;
INSERT INTO npc_text (ID, text0_0) VALUES (@TEXTID, 'It seems that these are remnants Buscalba Thalorien you, the last bearer of Quel\Delar');

-- NPCs
DELETE FROM `creature_template` WHERE `entry` IN (37552, 37205, 37542, 37541, 37539, 37538);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(37552, 0, 0, 0, 0, 0, 30659, 0, 0, 0, 'Thalorien Dawnseeker\'s Remains', '', '', 0, 80, 80, 0, 35, 35, 1, 1, 1.14286, 1, 1, 0, 0, 0, 0, 1, 0, 0, 2, 32772, 44, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_thalorien', 12340),
(37205, 0, 0, 0, 0, 0, 30570, 0, 0, 0, 'Thalorien Dawnseeker', '', '', 0, 80, 80, 0, 35, 35, 0, 1, 1.14286, 1, 1, 400, 600, 0, 472, 2, 1500, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 4096, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 10.3181, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 12340),
(37542, 0, 0, 0, 0, 0, 30657, 0, 0, 0, 'Morlen Coldgrip', '', '', 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 1, 400, 600, 0, 472, 1, 1500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 7.076, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340),
(37541, 0, 0, 0, 0, 0, 30651, 30653, 30654, 0, 'Crypt Raider', '', '', 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 0, 400, 600, 0, 472, 1, 1500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 3.538, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340),
(37539, 0, 0, 0, 0, 0, 30647, 30648, 30649, 30650, 'Ghoul Invader', '', '', 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 0, 400, 600, 0, 472, 1, 1500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 2.9483, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340),
(37538, 0, 0, 0, 0, 0, 30645, 30644, 30643, 30646, 'Scourge Zombie', '', '', 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 0, 400, 600, 0, 472, 1, 1500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 1.887, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340);

DELETE FROM `creature_template_addon` WHERE (`entry`=@ENTRY);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@ENTRY, 0, 0, 0, 0, 0, '25824 31261 31261');

DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (37552, 37205, 37542, 37541, 37539, 37538) AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(37205, 0, 0, 0, 0, 0, 100, 30, 5000, 7000, 15000, 15000, 11, 67541, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thalorien - Filotormenta'),
(37205, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 13000, 13000, 11, 67542, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thalorien - Golpe mortal'),
(37205, 0, 2, 0, 0, 0, 100, 0, 19000, 19000, 19000, 19000, 11, 67716, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thalorien - Torbellino'),
(37205, 0, 3, 0, 0, 0, 100, 0, 1000, 1000, 8000, 8000, 11, 57846, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thalorien - Golpe heroico'),
(37542, 0, 0, 0, 0, 0, 100, 30, 2000, 3000, 9000, 10000, 11, 50688, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Morlen Manosfrias - Golpe de peste'),
(37541, 0, 0, 0, 0, 0, 100, 30, 1000, 2000, 4000, 5000, 11, 31600, 2, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Asaltante de la cripta - Escarabajos de la cripta'),
(37539, 0, 0, 0, 0, 0, 100, 30, 1000, 2000, 9000, 10000, 11, 38056, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Invasor necrofago - Desgarrar carne'),
(37538, 0, 0, 0, 0, 0, 100, 30, 1000, 2000, 9000, 10000, 11, 49861, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Zombi de la plaga - Mordedura infectada');
