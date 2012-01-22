-- Fixer Upper (Deepholm) Questfix
-- by Naios for Arkania

/* Note:
The Spawns are not official but currently the official spawning positions of the gob
are not known.
I think it is better to spawn non official questspawns than to do nothing
and the quest is still buggy.
*/

-- The GOB is not spawned yet (prevents double spawn on batch rerun)
DELETE FROM `gameobject` WHERE `id` = 204374 AND `map` = 646;

INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(204374, 646, 1, 1, 723.734, 1965.62, 329.993, 3.91616, 0, 0, 0.925938, -0.377675, 300, 0, 1),
(204374, 646, 1, 1, 842.242, 2004.02, 323.974, 2.82053, 0, 0, 0.987142, 0.159844, 300, 0, 1),
(204374, 646, 1, 1, 808.532, 1947.14, 328.241, 2.93048, 0, 0, 0.994434, 0.10536, 300, 0, 1),
(204374, 646, 1, 1, 907.478, 1804.73, 316.399, 4.76831, 0, 0, 0.68706, -0.726601, 300, 0, 1),
(204374, 646, 1, 1, 968.675, 1970.47, 316.019, 5.76184, 0, 0, 0.25773, -0.966217, 300, 0, 1),
(204374, 646, 1, 1, 650.729, 1896.72, 338.157, 0.982706, 0, 0, 0.471819, 0.881695, 300, 0, 1),
(204374, 646, 1, 1, 630.162, 1684.13, 341.604, 4.1675, 0, 0, 0.8713, -0.490751, 300, 0, 1),
(204374, 646, 1, 1, 770.841, 1694.7, 315.047, 3.82977, 0, 0, 0.941383, -0.337341, 300, 0, 1),
(204374, 646, 1, 1, 755.008, 1861.5, 326.175, 0.774553, 0, 0, 0.377668, 0.925941, 300, 0, 1),
(204374, 646, 1, 1, 675.553, 1779.84, 335.422, 2.13721, 0, 0, 0.876531, 0.481346, 300, 0, 1),
(204374, 646, 1, 1, 683.301, 1778.86, 334.255, 1.93694, 0, 0, 0.824019, 0.566562, 300, 0, 1);


