-- DB/NPC: Fix all startup erros with creature tamplate less UNIT_NPC_FLAG_SPELLCLICK this need a little bir more work
-- NPC: Defias Blackguard Can't have IA on hero mode (http://www.wowhead.com/npc=636)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='636';
UPDATE `creature_template` SET `AIName`='' WHERE `entry`='42698';

-- NPC: Shadowfang Ragetooth Can't have IA on hero mode (http://www.wowhead.com/npc=3859)
UPDATE `creature_template` SET `AIName`='' WHERE `entry`='63859';

-- NPC: Atal'ai Totem Can't Wrong speel ID (http://www.wowhead.com/npc=8510)
UPDATE `creature_template` SET `spell1`='12504' WHERE `entry`='8510';

-- NPC: Tainted Earthgrab Totem Wrong spell ID (http://www.wowhead.com/npc=18176)
UPDATE `creature_template` SET `spell1`='31983' WHERE `entry`='18176';

-- NPC: Corrupted Nova Totem Wrong spell ID (http://www.wowhead.com/npc=18179)
UPDATE `creature_template` SET `spell1`='33132' WHERE `entry`='18179';

-- NPC: Removed some wrong flags extra
UPDATE `creature_template` SET `flags_extra`='0' WHERE `entry` IN ('30575','30593','33438');

-- NPC: Siege Engine Correct unit on hero mode (http://www.wowhead.com/npc=34776)
UPDATE `creature_template` SET `unit_class`='4' WHERE `entry`='35431';

-- NPC: Catapult Correct unit on hero mode (http://www.wowhead.com/npc=34793)
UPDATE `creature_template` SET `unit_class`='4' WHERE `entry`='35413';

-- NPC: Siege Engine unit on hero mode (http://www.wowhead.com/npc=35069)
UPDATE `creature_template` SET `unit_class`='4' WHERE `entry`='35433';

-- NPC: Siege Turret unit on hero mode (http://www.wowhead.com/npc=36355)
UPDATE `creature_template` SET `unit_class`='4' WHERE `entry`='36357';

-- NPC: Charscale Invoker unit on hero mode (http://www.wowhead.com/npc=40417)
UPDATE `creature_template` SET `unit_class`='2' WHERE `entry`='40417';

-- NPC: Gwen Armstead Equiptemplate taking from official (http://www.wowhead.com/npc=34936)
UPDATE `creature_template` SET `equipment_id`='51401' WHERE `entry`='34936';
DELETE FROM `creature_equip_template` WHERE `entry`='51401';
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES
('51401','3364','0','0');

-- NPC: Captain Arnath Correct eqquipment (http://www.wowhead.com/npc=37491)
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry` IN ('37491','38349');

-- NPC: Captain Brandon Correct eqquipment (http://www.wowhead.com/npc=37493)
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry` IN ('37493','38350');

-- NPC: Captain Grondel Correct eqquipment (http://www.wowhead.com/npc=37494)
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry` IN ('37494','38351');

-- NPC: Captain Rupert Correct eqquipment (http://www.wowhead.com/npc=37495)
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`IN ('37495','38352');

-- NPC: Onyx Flamecaller eqquipment (http://www.wowhead.com/npc=39814)
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`IN ('39814');

-- NPC: Baltharus the Warborn Equipment (http://www.wowhead.com/npc=39751)
DELETE FROM `creature_equip_template` WHERE (`entry`=2467);
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES 
(2467, 28365, 0, 0);

-- NPC: Charscale Invoker Equipment (http://www.wowhead.com/npc=40417)
DELETE FROM `creature_equip_template` WHERE (`entry`=2469);
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES 
(2469, 43114, 0, 0);

-- NPC: Charscale Elite Equipment (http://www.wowhead.com/npc=40421)
DELETE FROM `creature_equip_template` WHERE (`entry`=2471);
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES 
(2471, 49737, 49737, 0);

-- NPC: Charscale Commander Equipment (http://www.wowhead.com/npc=40421)
DELETE FROM `creature_equip_template` WHERE (`entry`=2472);
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES 
(2472, 40608, 0, 0);

-- NPC: Lord Walden Wrong Flag is a quest giver (http://www.wowhead.com/npc=45879)
UPDATE `creature_template` SET `npcflag`='3' WHERE `entry` IN (45879,49711);

-- NPC: Glubtok Wrong Flag is a quest giver (http://www.wowhead.com/npc=47162)
UPDATE `creature_template` SET `npcflag`='3' WHERE `entry` IN (47162,48936);

-- NPC: Deathstalker Commander Belmont is a quest giver (http://www.wowhead.com/npc=47293)
UPDATE `creature_template` SET `npcflag`='3' WHERE `entry` IN ('47293','45557');

-- NPC: "Captain" Cookie <Defias Kingpin?> is a quest giver (http://www.wowhead.com/npc=47739)
UPDATE `creature_template` SET `npcflag`='3' WHERE `entry` IN ('47739','48944');

-- NPC: Finkle Einhorn Only is a quest giver (http://www.wowhead.com/npc=49476)
UPDATE `creature_template` SET `npcflag`='3' WHERE `entry` IN ('49476','49477');

-- NPC: Sand-Husk Scarab correct habit type (http://www.wowhead.com/npc=51674)
UPDATE `creature_template` SET `InhabitType`='1' WHERE `entry` IN ('51674');

-- NPC: Nether Scion Wrong class (http://www.wowhead.com/npc=44645)
UPDATE `creature_template` SET `unit_class`='1' WHERE `entry` IN (44645,46212,46213,46214);

-- NPC: Slate Dragon Wrong class (http://www.wowhead.com/npc=44652)
UPDATE `creature_template` SET `unit_class`='1' WHERE `entry` IN (44652,46215,46216,46217);

-- NPC: Time Warden Wrong class (http://www.wowhead.com/npc=44797)
UPDATE `creature_template` SET `unit_class`='1' WHERE `entry` IN (44797,46221,46222,46223);

-- NPC: Erunak Stonespeaker Is a quest giver (http://www.wowhead.com/npc=40825)
UPDATE `creature_template` SET `npcflag`='3' WHERE `entry` IN ('40825','49072');

-- Helix Gearbreaker Fix wrong npflag (http://www.wowhead.com/npc=47296)
UPDATE `creature_template` SET `npcflag`='0' WHERE `entry` IN ('47296','48940');

-- NPC: Karsh Steelbender Deleting this NPC this NPC have a wront entry and exist on db with correct one (www.wowhead.com/npc=49930)
DELETE FROM creature_template WHERE entry='49930';

-- NPC: Rom'ogg Bonecrushe Deleting this NPC this NPC have a wront entry and exist on db with correct one (www.wowhead.com/npc=51398)
DELETE FROM creature_template WHERE entry='51398';

-- NPC: Carrion Bird Correct spell fot this NPC (http://www.wowhead.com/npc=51760)
UPDATE `creature_template` SET `spell1`='55079' WHERE `entry`='51760';

-- NPC: Ramkahen Guardian Correct model fot this NPC (http://www.wowhead.com/npc=51776)
UPDATE `creature_template` SET `modelid1`='35929', `modelid2`='35929', `faction_A`='2331', `faction_H`='2331' WHERE `entry`='51776';

-- NPC: Rayne Feathersong Deelting from template this npc is for 4.2 clients (http://www.wowhead.com/npc=52467)
DELETE FROM `creature_template` WHERE `entry`='52467';

-- NPC: Charred Flamewaker Correct spell fot this NPC (http://www.wowhead.com/npc=52791)
UPDATE `creature_template` SET `spell1`='79846',`spell2`='32707',`spell3`='0',`spell4`='0' WHERE `entry`='52791';

-- NPC: Captain Saynna Stormrunner Deelting from template this npc is for 4.2 clients (http://www.wowhead.com/npc=52844)
DELETE FROM `creature_template` WHERE `entry`='52844';

-- NPC: Eulinda <Reagents> Deleting from template this npc is for 4.1 clients (http://www.wowhead.com/npc=52914)
DELETE FROM `creature_template` WHERE `entry`='52914';

-- NPC: Norkani Deleting from template this npc is for 4.1 clients (http://www.wowhead.com/npc=52943)
DELETE FROM `creature_template` WHERE `entry`='52943';

-- NPC: Grom'gol Grunt Deleting from template this npc is for 4.1 clients (http://www.wowhead.com/npc=53000)
DELETE FROM `creature_template` WHERE `entry`='53000';

-- NPC: Seething Pyrelord Deleting from template this npc is for 4.2 clients (http://www.wowhead.com/npc=52300)
DELETE FROM `creature_template` WHERE `entry`='52300';

-- NPC: Seething Pyrelord Deleting from template this npc is for 4.2 clients (http://www.wowhead.com/npc=52300)
DELETE FROM `creature_template` WHERE `entry`='3680502';

-- NPC: General Zarithrian Fix euip template (http://www.wowhead.com/npc=39746)
DELETE FROM `creature_equip_template` WHERE (`entry`=2466);
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES 
(2466, 43111, 0, 0);

-- NPC: Mutated Abomination Miss a difficulty 
DELETE FROM `creature_template` WHERE `entry`='38789';
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(38789, 0, 0, 0, 0, 0, 31008, 0, 0, 0, 'Mutated Abomination (2)', '', '', 0, 82, 82, 2, 14, 14, 0, 1, 1.14286, 1, 1, 452, 678, 0, 169, 2, 2000, 2000, 1, 0, 8, 0, 0, 0, 0, 0, 362, 542, 135, 6, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72527, 72457, 70542, 0, 0, 71516, 0, 0, 0, 591, 0, 0, '', 0, 3, 35, 1, 1, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0, 8388624, 0, '', 12340);

-- NPC: Deathspeaker Servant Miss a difficulty 
DELETE FROM `creature_template` WHERE `entry`='3680502';
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(3680502, 0, 0, 0, 0, 0, 30323, 30360, 0, 0, 'Deathspeaker Servant (2)', 'Cult of the Damned', '', 0, 82, 82, 2, 16, 16, 0, 3.2, 1.71429, 1, 1, 362, 520, 0, 326, 7.5, 0, 0, 8, 32832, 8, 0, 0, 0, 0, 0, 360, 523, 79, 7, 72, 3680502, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 3, 45, 10, 1, 0, 0, 0, 0, 0, 0, 0, 172, 1, 10050, 613097436, 0, '', 1);

-- Risen Deathspeaker Servant set correct difficulties (http://www.wowhead.com/npc=36844)
UPDATE `creature_template` SET `difficulty_entry_1`='38077', `difficulty_entry_2`='3684402', `difficulty_entry_3`='3684403' WHERE `entry`='36844';
UPDATE `creature_template` SET `unit_class`='8' WHERE `entry` IN ('36844','38077','3684402','3684403');

-- Memory of Heigan set correct difficulties (http://www.wowhead.com/npc=35049)
UPDATE `creature_template` SET `difficulty_entry_1`='0' WHERE `entry`='35049';

-- NPC: Deathspeaker Servant Miss a difficulty 
DELETE FROM `creature_template` WHERE `entry`='38789';
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(38789, 0, 0, 0, 0, 0, 31008, 0, 0, 0, 'Mutated Abomination (2)', '', '', 0, 80, 80, 0, 35, 35, 0, 1, 1.14286, 1, 1, 422, 586, 0, 642, 7.5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 345, 509, 103, 6, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72527, 72457, 70542, 0, 0, 71516, 0, 0, 0, 591, 0, 0, '', 0, 3, 35, 1, 1, 0, 0, 0, 0, 0, 0, 0, 170, 1, 0, 0, 0, '', 12340);
