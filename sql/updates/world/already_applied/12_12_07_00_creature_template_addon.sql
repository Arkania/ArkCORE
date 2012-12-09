-- Fix wrong aura Tortolla
-- By Mikadmin for arkania

DELETE FROM `creature_template_addon` WHERE (`entry`=41504);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (41504, 0, 0, 65536, 1, 0, '');

-- Fix wrong aura Alysra
DELETE FROM `creature_template_addon` WHERE (`entry`=38917);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (38917, 0, 0, 50397184, 1, 0, '');