-- Corruption Destruction (Deepholm) Questfix
-- by Naios for Arkania

/* Note:
The Spawns are not official but currently the official spawning positions of the gob
are not known.
I think it is better to spawn non official questspawns than to do nothing
and the quest is still buggy.
*/

-- The GOB is not spawned yet (prevents double spawn on batch rerun)
DELETE FROM `gameobject` WHERE `id` = 204410 AND `map` = 646;

INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(204410, 646, 1, 1, 1822.95, -691.485, 243.283, 1.79698, 0, 0, 0.782386, 0.622794, 300, 0, 1),
(204410, 646, 1, 1, 1874.5, -711.066, 241.122, 1.5064, 0, 0, 0.683975, 0.729505, 300, 0, 1),
(204410, 646, 1, 1, 1845.53, -723.592, 245.343, 5.16084, 0, 0, 0.532179, -0.846632, 300, 0, 1),
(204410, 646, 1, 1, 1882.22, -666.595, 239.931, 4.1791, 0, 0, 0.868438, -0.495799, 300, 0, 1),
(204410, 646, 1, 1, 1879.57, -613.204, 244.501, 5.72241, 0, 0, 0.276729, -0.960948, 300, 0, 1),
(204410, 646, 1, 1, 1844.28, -622.868, 242.906, 6.12688, 0, 0, 0.0780711, -0.996948, 300, 0, 1),
(204410, 646, 1, 1, 1839.41, -659.892, 241.419, 2.51484, 0, 0, 0.951298, 0.308274, 300, 0, 1),
(204410, 646, 1, 1, 1858.88, -718.573, 240.465, 0.00941698, 0, 0, 0.00470847, 0.999989, 300, 0, 1);
