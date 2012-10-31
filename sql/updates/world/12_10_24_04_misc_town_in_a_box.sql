-- link quest spells
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='68935';
INSERT INTO `spell_linked_spell` VALUES (68935, 68750, 0, 'It\'s a Town-In-A-Box-Phase-Change');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='-70988';
INSERT INTO `spell_linked_spell` VALUES (-70988, 44795, 0, 'It\'s a Town-In-A-Box-SafeFall');
INSERT INTO `spell_linked_spell` VALUES (-70988, -71094, 0, 'It\'s a Town-In-A-Box-Remove-Smoke-Effect');
 
-- move town NPCs to correct phase
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6620668';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6620409';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6619505';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6620410';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6620750';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6619593';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6619379';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6618899';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6619866';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6619621';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6619581';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6620673';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6621391';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6621372';
UPDATE `creature` SET `phaseMask`='2048' WHERE `guid`='6621380';
 
-- Spawn missing GO town-in-a-box
DELETE FROM `gameobject` WHERE `id`='202166';
INSERT INTO `gameobject` VALUES (NULL, 202166, 648, 1, 2, 907.851, 2327.75, 5.15, 4.95763, 0, 0, 0.615307, -0.788287, 300, 0, 1);
 
-- Spawn missing GO town-in-a-box plunger
DELETE FROM `gameobject` WHERE `id`='201938';
INSERT INTO `gameobject` VALUES (NULL, 201938, 648, 1, 2, 906.976, 2329.43, 11.4925, 4.76914, 0, 0, 0.686759, -0.726885, 300, 0, 1);
 
-- Update GO town-in-a-box
-- make it a goober so a script can be assigned, add spell to lock go if not needed, assign script
UPDATE `gameobject_template` SET `type`='10', `data0`='0', `data1`='14245', `data5`='0', `data10`='68938', `ScriptName`='go_towninabox' WHERE `entry`='201938';
 
 
-- spawn quest end NPC in correct phase (was missing)
-- unable to del before insert due to other copies of this NPC id dif phases
-- need to use GUID for this NPC???
INSERT INTO `creature` VALUES (NULL, 36471, 648, 1, 2048, 0, 36471, 929.36, 2332.28, 5.02209, 2.87129, 300, 0, 0, 102, 0, 0, 0, 0, 0, 0);
 
-- add aura to smoke bunny and phase aura
DELETE FROM `creature_template_addon` WHERE `entry`='38069';
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES ('38069', '71094 0 68750 0');
 
-- Remove some none needed spawns
DELETE FROM  `creature` WHERE `id`='38526';
