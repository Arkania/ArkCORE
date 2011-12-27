-- DB/CREATURE TEMPLATE: Temporaly fix for spellclick (seems is not working, read note) 
-- PLEASE!!!! Spellclicks are not implemented on core, so don't use it!!!
-- Haiphoon, the Great Tempest Is not a mount or vehicle (http://www.wowhead.com/npc=28985)
UPDATE `creature_template` SET `npcflag`='0', type_flags='0' WHERE `entry`='28985';
-- Haiphoon, the Great Tempest Is not a mount or vehicle (http://www.wowhead.com/npc=28999)
UPDATE `creature_template` SET `npcflag`='0', `unit_flags`='0' WHERE `entry`='28999';
-- Wrong flags_extra, this flag don't exist.
-- Dead Iron Giant
-- Seething Revenant
-- Frostbrood Destroyer
-- Forgotten Depths Slayer
UPDATE `creature_template` SET `flags_extra`='0' WHERE `entry` IN ('29914','30120','30575','30593');
-- Correct units for a few npcs
-- Stonecore Rift Conjurer (http://www.wowhead.com/npc=42691)
UPDATE `creature_template` SET `unit_class`='8' WHERE `entry` IN ('42691','49665');
-- Stonecore Sentry (http://www.wowhead.com/npc=42695)
UPDATE `creature_template` SET `unit_class`='8' WHERE `entry` IN ('42695','49666');
-- Stonecore Sentry (http://www.wowhead.com/npc=42695)
UPDATE `creature_template` SET `unit_class`='8' WHERE `entry` IN ('42789','49664');
-- Scriptnames obnly by set on normal mode not in rest of modes
-- Argaloth (http://www.wowhead.com/npc=47120)
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN ('51350');
-- NPC: Mutated Abomination Miss a difficulty 
DELETE FROM `creature_template` WHERE `entry`='38789';
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(38789, 0, 0, 0, 0, 0, 31008, 0, 0, 0, 'Mutated Abomination (2)', '', '', 0, 82, 82, 2, 14, 14, 0, 1, 1.14286, 1, 1, 452, 678, 0, 169, 2, 2000, 2000, 1, 0, 8, 0, 0, 0, 0, 0, 362, 542, 135, 6, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72527, 72457, 70542, 0, 0, 71516, 0, 0, 0, 591, 0, 0, '', 0, 3, 35, 1, 1, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0, 8388624, 0, '', 12340);

