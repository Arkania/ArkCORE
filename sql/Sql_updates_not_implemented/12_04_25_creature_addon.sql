-- Spezified Things
-- Addons
-- by Naios

SET @NPC_GUID_START := 18001500;

REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
-- Throngus for Waypoints by Naios
(@NPC_GUID_START + 74, (@NPC_GUID_START + 74)*10, 0, 0, 0, 0, NULL);

-- Throngus Waypoints by Naios
DELETE FROM `waypoint_data` WHERE `id` = (@NPC_GUID_START + 74)*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
((@NPC_GUID_START + 74)*10, 1, -492.303, -489.919, 271.914, 0, 0, 0, 100, 0),
((@NPC_GUID_START + 74)*10, 2, -489.521271, -509.812469, 271.908356, 0, 0, 0, 100, 0),
((@NPC_GUID_START + 74)*10, 3, -489.702423, -550.505005, 271.908264, 0, 0, 0, 100, 0),
((@NPC_GUID_START + 74)*10, 4, -492.251, -570.199, 271.912, 0, 0, 0, 100, 0),
((@NPC_GUID_START + 74)*10, 5, -489.702423, -550.505005, 271.908264, 0, 0, 0, 100, 0),
((@NPC_GUID_START + 74)*10, 6, -489.521271, -509.812469, 271.908356, 0, 0, 0, 100, 0);