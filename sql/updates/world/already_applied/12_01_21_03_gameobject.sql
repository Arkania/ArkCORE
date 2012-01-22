-- Throne of the Four Winds Updates
-- by Naios

DELETE FROM `game_tele` WHERE `name` = 'throneofthefourwinds';
INSERT INTO `game_tele` (`position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`)
VALUES (-301.544, 817.184, 198.405, 6.28036, 754, 'throneofthefourwinds');

-- First we wipe out all spawned GOBs in the Throne of the Four Winds (non Blizzlike Platforms & Mobs etc.)
DELETE FROM `gameobject` WHERE `map` = 754;
DELETE FROM `creature` WHERE `map` = 754;

-- The gameobjects must be fixed
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `AIName`, `ScriptName`, `WDBVerified`)
VALUES (207737, 14, 10369, 'Skywall Raid Center Platform', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '', '', 1);

-- Fixes Djing Effect objects
UPDATE `gameobject_template` SET `type`=14 WHERE `entry`IN (206699, 206700, 206701);

-- Spawns the NPCS
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
-- Conclave of Wind
-- Anshal
(45870, 754, 15, 1, 0, 0, -48.5569, 1054.37, 198.456, 4.70171, 300, 0, 0, 4294600, 0, 0, 0, 0, 0, 0),
-- Nezir
(45871, 754, 15, 1, 0, 0, 188.114, 813.822, 198.456, 3.12542, 300, 0, 0, 7300820, 0, 0, 0, 0, 0, 0),
-- Rohash
(45872, 754, 15, 1, 0, 0, -52.8208, 577.173, 198.456, 1.56596, 300, 0, 0, 4294600, 0, 0, 0, 0, 0, 0),

-- Al'Akir
(46753, 754, 15, 1, 0, 0, -50.4909, 815.868, 189.984, 3.944043, 300, 0, 0, 4294600, 0, 0, 0, 0, 0, 0);

-- Slipstream fixes

UPDATE `creature_template` SET `ScriptName`='npc_slipstream_raid', `InhabitType`=7 WHERE `entry`=47066 LIMIT 1;
-- Spawns the Slipstreams
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(47066, 754, 15, 1, 0, 0, -240.162, 769.122, 195.846, 5.49923, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(47066, 754, 15, 1, 0, 0, -101.552, 626.445, 195.848, 2.35436, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(47066, 754, 15, 1, 0, 0, -3.43208, 626.723, 195.846, 0.816079, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(47066, 754, 15, 1, 0, 0, 138.67, 764.981, 195.846, 3.92453, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(47066, 754, 15, 1, 0, 0, 138.693, 862.983, 195.847, 2.36697, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(47066, 754, 15, 1, 0, 0, 0.51813, 1004.95, 195.846, 5.50298, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(47066, 754, 15, 1, 0, 0, -97.3398, 1005.53, 195.846, 3.93802, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(47066, 754, 15, 1, 0, 0, -239.742, 867.066, 195.846, 0.784143, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0);

-- Creature Template fixes
UPDATE `creature_template` SET `InhabitType`=7, `faction_A`=14, `faction_H`=14
WHERE `entry` IN (45870, 45871, 45872, 46753) LIMIT 5;

-- GOB Spawn
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
-- Raid Platform
(207737, 754,15, 1, -272.076, 816.277, 202, 3.140180, 0, 0, 0.999898, -0.0280381, 300, 0, 1),

-- Anshal Effect
(206699, 754, 15, 1, -48.5569, 1054.37,  200.527603, 4.70171, 0, 0, 0.999898, -0.0280381, 300, 0, 1),
-- Nezir Effect
(206700, 754, 15, 1, 188.114, 813.822,  202.527603, 3.12542, 0, 0, 0.999898, -0.0280381, 300, 0, 1),
-- Rohash Effect
(206701, 754, 15, 1, -52.8208, 577.173,  200.527603, 1.56596, 0, 0, 0.999898, -0.0280381, 300, 0, 1),
--  Al'Akir Effect
(207922, 754, 15, 1, -50.4909, 815.868, 189.984, 3.11662, 0, 0, 0.999898, -0.0280381, 300, 0, 1),

-- Slipstream Effects
(207930, 754, 15, 1, -247.607, 776.485, 198.458, 2.35754, 0, 0, 0.924137, 0.38206, 300, 0, 1),
(207929, 754, 15, 1, -94.2481, 619.219, 198.458, 5.50306, 0, 0, 0.380245, -0.924886, 300, 0, 1),
(207928, 754, 15, 1, -11.2602, 618.869, 198.458, 3.93226, 0, 0, 0.922867, -0.385118, 300, 0, 1),
(207927, 754, 15, 1, 146.138, 772.356, 198.458, 0.826014, 0, 0, 0.401365, 0.915918, 300, 0, 1),
(207926, 754, 15, 1, 146.203, 855.315, 198.458, 5.49834, 0, 0, 0.382429, -0.923985, 300, 0, 1),
(207925, 754, 15, 1, -7.08924, 1012.53, 198.458, 2.3489, 0, 0, 0.922478, 0.386049, 300, 0, 1),
(207924, 754, 15, 1, -90.0826, 1012.85, 198.458, 0.772608, 0, 0, 0.376767, 0.926308, 300, 0, 1),
(207923, 754, 15, 1, -247.379, 859.524, 198.458, 3.92598, 0, 0, 0.924073, -0.382215, 300, 0, 1);

-- Repairs the Instnce Template and sets the Scriptname
REPLACE INTO `instance_template` (`map`, `parent`, `startLocX`, `startLocY`, `startLocZ`, `startLocO`, `script`, `allowMount`)
VALUES (754, 0, NULL, NULL, NULL, NULL, 'instance_throne_of_the_four_winds', 1);
