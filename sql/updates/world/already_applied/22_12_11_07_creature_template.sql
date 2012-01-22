-- Thunderstones (Deepholm) Questfix
-- by Naios for Arkania

/* Note:
The Spawns are not official but currently the official spawning positions of the gob
are not known.
I think it is better to spawn non official questspawns than to do nothing
and the quest is still buggy.

I tried to spawn the gobs as blizzlike as i could from screens etc.
*/

-- The GOB is not spawned yet (prevents double spawn on batch rerun)
DELETE FROM `gameobject` WHERE `id` = 204348 AND `map` = 646;

INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(204348, 646, 1, 1, 503.119, 1664.82, 349.411, 5.41388, 0, 0, 0.421093, -0.907017, 300, 0, 1),
(204348, 646, 1, 1, 503.853, 1663.14, 350.048, 4.57744, 0, 0, 0.753173, -0.657822, 300, 0, 1),
(204348, 646, 1, 1, 524.538, 1711.12, 346.41, 4.93871, 0, 0, 0.622737, -0.782431, 300, 0, 1),
(204348, 646, 1, 1, 524.631, 1713.07, 346.619, 2.00917, 0, 0, 0.843939, 0.53644, 300, 0, 1),
(204348, 646, 1, 1, 499.058, 1729.02, 345.765, 3.83601, 0, 0, 0.940327, -0.340272, 300, 0, 1),
(204348, 646, 1, 1, 462.535, 1713.95, 347.341, 3.21319, 0, 0, 0.999359, -0.0357889, 300, 0, 1),
(204348, 646, 1, 1, 460.808, 1714.04, 347.781, 2.95007, 0, 0, 0.995418, 0.0956138, 300, 0, 1),
(204348, 646, 1, 1, 440.945, 1694.15, 349.648, 0.762739, 0, 0, 0.372192, 0.928156, 300, 0, 1),
(204348, 646, 1, 1, 410.703, 1680.11, 348.632, 3.46059, 0, 0, 0.987307, -0.158825, 300, 0, 1),
(204348, 646, 1, 1, 410.027, 1679.19, 349.017, 3.99074, 0, 0, 0.911215, -0.411931, 300, 0, 1),
(204348, 646, 1, 1, 411.543, 1680.87, 348.245, 3.88863, 0, 0, 0.931048, -0.364896, 300, 0, 1),
(204348, 646, 1, 1, 410.97, 1679.14, 348.784, 3.71585, 0, 0, 0.959062, -0.283198, 300, 0, 1),
(204348, 646, 1, 1, 443.084, 1649.05, 348.734, 3.52107, 0, 0, 0.982053, -0.188603, 300, 0, 1),
(204348, 646, 1, 1, 444.191, 1648.57, 348.668, 3.25404, 0, 0, 0.99842, -0.0561922, 300, 0, 1),
(204348, 646, 1, 1, 442.039, 1648.84, 348.828, 3.19905, 0, 0, 0.999587, -0.0287271, 300, 0, 1);

UPDATE `quest_template` SET `OfferRewardText`='<Clay grumbles to himself.>$BThose\'ll do. Just put them down over$B there.$B<The Earthen looks you up and down with one eye and then spits dust onto the ground.>$BI\'m going to have something for you to do in a moment. Maybe.' WHERE `entry`=26502 LIMIT 1;
