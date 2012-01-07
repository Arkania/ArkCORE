-- DB/VISUAL: Fire for Orc start zone taking from official
DELETE FROM `gameobject` WHERE `guid`='22' AND `id`='3084';
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES 
(22, 3084, 1, 1, 1, -602.844, -4250.48, 38.9559, 1.29846, 0, 0, 0.604571, 0.796551, 300, 0, 1);
