-- Lunar Festival - Cataclysm Orgrimmar

--
-- VERY IMPORTANT: Only add one time, if you add more than 2 times, you will see a duplicated event and you will need reinstall the database.
-- Recommended make backup before add this update.
--

-- Lunar Festival Heralds
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`)
VALUES
	(null, 15891, 1, 1, 1, 0, 0, 1545.12, -4373.75, 17.5158, 5.73111, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(null, 15891, 1, 1, 1, 0, 0, 1827.97, -4404.44, 103.735, 2.40445, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(null, 15891, 1, 1, 1, 0, 0, 1824.4, -4402.98, 103.522, 0.138575, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(null, 15891, 1, 1, 1, 0, 0, 1827.41, -4400.64, 103.698, 4.45198, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(null, 15891, 1, 1, 1, 0, 0, 1819.84, -4420.08, 103.208, 0.930837, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(null, 15891, 1, 1, 1, 0, 0, 1825.49, -4419.05, 103.452, 2.53896, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(null, 15891, 1, 1, 1, 0, 0, 1818.82, -4414.2, 103.212, 5.68997, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(null, 15891, 1, 1, 1, 0, 0, 1824.38, -4412.58, 103.495, 4.13567, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(null, 15895, 1, 1, 1, 0, 0, 1807.95, -4418.09, 102.834, 1.57252, 300, 0, 0, 1830, 5502, 0, 0, 0, 0, 0),
	(null, 47897, 1, 1, 1, 0, 0, 1799.14, -4420.84, 103.476, 1.59094, 300, 0, 0, 1830, 5013, 0, 0, 0, 0, 0),
	(null, 15579, 1, 1, 1, 0, 0, 1791.7, -4414.42, 103.353, 0.362423, 300, 0, 0, 2563, 5502, 0, 0, 0, 0, 0),
	(null, 15891, 1, 1, 1, 0, 0, 1801.46, -4400.46, 103.45, 4.56823, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0),
	(null, 15891, 1, 1, 1, 0, 0, 1801, -4403.83, 102.988, 1.49889, 300, 0, 0, 2614, 0, 0, 0, 0, 0, 0);

-- Lunar Festival Vendor Fixes
UPDATE `creature_template` SET `minlevel` = '55', `maxlevel` = '55' WHERE `entry` = 47897;

-- Delete Obsolete Heralds
DELETE FROM `creature` WHERE `GUID` = 91593;
DELETE FROM `creature` WHERE `GUID` = 91610;
DELETE FROM `creature` WHERE `GUID` = 91608;
DELETE FROM `creature` WHERE `GUID` = 91615;