-- Full cleanup of the Lunar Festival event and re-add it, now its possible use this SQL how times that you want, no more duplicated event for accidentaly doble add :D

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 321000 AND 321012;
INSERT INTO `game_event_creature` (`guid`, `event`)
VALUES
	(321000, 7),
	(321001, 7),
	(321002, 7),
	(321003, 7),
	(321004, 7),
	(321005, 7),
	(321006, 7),
	(321007, 7),
	(321008, 7),
	(321009, 7),
	(321010, 7),
	(321011, 7),
	(321012, 7);

DELETE FROM `creature` WHERE `guid` BETWEEN 321000 AND 321012;

DELETE FROM `creature` WHERE `id` = 47897;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`)
VALUES
	(321012, 47897, 1, 1, 1, 0, 0, 1799.14, -4420.84, 103.476, 1.59094, 300, 0, 0, 1830, 5013, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `id` = 15579;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`)
VALUES
	(321011, 15579, 1, 1, 1, 0, 0, 1791.7, -4414.42, 103.353, 0.362423, 300, 0, 0, 2563, 5502, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `id` = 15895;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`)
VALUES
	(91572, 15895, 0, 1, 1, 15865, 0, 1647.51, 243.693, 62.6749, 5.8294, 180, 0, 0, 1830, 5013, 0, 0, 0, 0, 0),
	(91613, 15895, 1, 1, 1, 15865, 0, -1046.25, -225.606, 160.053, 2.86234, 180, 0, 0, 1830, 5013, 0, 0, 0, 0, 0),
	(91626, 15895, 0, 1, 1, 15871, 0, -4654.88, -941.656, 502.229, 1.29154, 180, 0, 0, 1830, 5013, 0, 0, 0, 0, 0),
	(321010, 15895, 1, 1, 1, 0, 0, 1807.95, -4418.09, 102.834, 1.57252, 300, 0, 0, 1830, 5502, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `id` = 15891;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`)
VALUES
	(91595, 15891, 1, 1, 1, 15875, 0, 1614.23, -4395.6, 10.3837, 3.29867, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(91597, 15891, 1, 1, 1, 15863, 0, -1036.33, -233.698, 160.017, 0.680678, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(91599, 15891, 1, 1, 1, 15877, 0, -1291.3, 116.18, 131.217, 5.14872, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(91601, 15891, 0, 1, 1, 15876, 0, 1638, 239.886, 62.6749, 6.26573, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(91604, 15891, 1, 1, 1, 15877, 0, -1032.32, -224.263, 160.518, 4.76475, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(91605, 15891, 0, 1, 1, 15877, 0, 1600.35, 232.99, -52.0698, 5.25344, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(91606, 15891, 0, 1, 1, 15876, 0, 1643.96, 243.095, 62.6749, 4.18879, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(91607, 15891, 0, 1, 1, 15877, 0, 1643.94, 236.545, 62.6749, 2.11185, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(91611, 15891, 1, 1, 1, 15875, 0, 1988.41, -4252.62, 31.6401, 3.7001, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(91614, 15891, 1, 1, 1, 15876, 0, -1027.03, -233.016, 160.063, 2.58309, 180, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321000, 15891, 1, 1, 1, 0, 0, 1545.12, -4373.75, 17.5158, 5.73111, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321001, 15891, 1, 1, 1, 0, 0, 1827.97, -4404.44, 103.735, 2.40445, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321002, 15891, 1, 1, 1, 0, 0, 1824.4, -4402.98, 103.522, 0.138575, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321003, 15891, 1, 1, 1, 0, 0, 1827.41, -4400.64, 103.698, 4.45198, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321004, 15891, 1, 1, 1, 0, 0, 1819.84, -4420.08, 103.208, 0.930837, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321005, 15891, 1, 1, 1, 0, 0, 1825.49, -4419.05, 103.452, 2.53896, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321006, 15891, 1, 1, 1, 0, 0, 1818.82, -4414.2, 103.212, 5.68997, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321007, 15891, 1, 1, 1, 0, 0, 1824.38, -4412.58, 103.495, 4.13567, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321008, 15891, 1, 1, 1, 0, 0, 1801.46, -4400.46, 103.45, 4.56823, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(321009, 15891, 1, 1, 1, 0, 0, 1801, -4403.83, 102.988, 1.49889, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0);