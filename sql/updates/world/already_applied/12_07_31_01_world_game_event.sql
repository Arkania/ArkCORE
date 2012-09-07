-- Fix error consol: game_event_save includes event save for non-worldevent id [xx]
-- By Mikadmin For ARKania

UPDATE `game_event` SET `world_event` = '1' WHERE `entry` IN (33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47);