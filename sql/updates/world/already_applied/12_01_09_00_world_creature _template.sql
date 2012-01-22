-- Ascendant Lord Obsidius (Blackrock Caverns) Updates
-- by Naios

SET @OBSIDIUS_GUID := 1051169;

UPDATE `creature_template` SET `AIName`='', `ScriptName`='boss_ascendant_lord_obsidius' WHERE `entry`=39705 LIMIT 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39705;

-- Deletes Obsidius and his Shadows to spawn them on a more blizzlike looking place
DELETE FROM `creature` WHERE `guid`=@OBSIDIUS_GUID LIMIT 1;
DELETE FROM `creature_addon` WHERE `guid`=@OBSIDIUS_GUID LIMIT 1;

DELETE FROM `creature` WHERE `id`=40817 AND `map` = 645;

DELETE FROM `creature_addon` WHERE `guid`=1051175 LIMIT 1;
DELETE FROM `creature_addon` WHERE `guid`=1051173 LIMIT 1;
DELETE FROM `creature_addon` WHERE `guid`=1051171 LIMIT 1;

-- Fixes the Problem that Obsidius is spawned twice if you rerun the Script
DELETE FROM `creature` WHERE `id`=39705 AND `map` = 645;

-- Spawns Obsidius new on a Blizzlike looking Place
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(39705, 645, 3, 1, 0, 0, 350.159, 561.722, 66.0078, 3.09457, 300, 0, 0, 104264, 0, 0, 0, 0, 0, 0);


-- Updates the Smart Script
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40817;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (40817, 0, 0, 0, 0, 0, 100, 6, 2500, 2500, 2500, 2500, 75, 76189, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Shadow of Obsidius');

-- Twitch Buff for the Shadows
REPLACE INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(40817, 0, 0, 0, 0, 0, '76167 0');
