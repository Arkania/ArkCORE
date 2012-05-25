-- Karsh Steelbender (Blackrock Caverns) Updates
-- by Naios

-- Quecksilver Updates
UPDATE `creature_template` SET `unit_flags`=33686022 WHERE `entry`=40004 LIMIT 1;

-- Karsh
UPDATE `creature_template` SET `AIName`='', `ScriptName`='boss_karsh_steelbender' WHERE `entry`=39698 LIMIT 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39698;

DELETE FROM `smart_scripts` WHERE `entryorguid`=50417;


INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
-- (50417,0,0,0,6,0,100,31,0,0,0,0,11,93666,4,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast lava doll on death"), -- I don't know weather this is the Blizzlike spell but it looks similar
(50417,0,1,0,54,0,100,31,0,0,0,0,49,0,0,0,0,0,0,17,0,50,0,0.0,0.0,0.0,0.0,"attack any player in 50 y range");

-- Spawns the FLame Trigger
DELETE FROM `creature` WHERE `id`=49529 AND `map` = 645;

INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(49529, 645, 3, 1, 0, 0, 216.941, 808.943, 95.35, 0.638911, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 210.184, 800.841, 95.3497, 0.984487, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 206.005, 789.778, 95.3491, 1.31043, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 206.636, 779.558, 95.3483, 1.71098, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 210.169, 768.761, 95.3494, 2.00158, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 217.187, 760.728, 95.3488, 2.3825, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 226.707, 754.725, 95.3501, 2.75163, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 237.891, 752.869, 95.3513, 3.07365, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 249.187, 755.259, 95.3501, 3.5174, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 257.883, 760.663, 95.3496, 3.82763, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 264.938, 769.164, 95.3496, 4.16928, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 268.842, 779.417, 95.351, 4.56589, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 268.717, 789.984, 95.3499, 4.86041, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 264.773, 800.198, 95.3491, 5.15887, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 257.802, 809.024, 95.3505, 5.51229, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 248.221, 814.93, 95.3507, 5.84216, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 237.282, 816.377, 95.3503, 6.28198, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(49529, 645, 3, 1, 0, 0, 226.104, 814.205, 95.35, 0.367926, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0);

-- Unbound Flame Updates
UPDATE `creature_template` SET `minlevel`=86, `maxlevel`=86, `exp`=3, `faction_A`=14, `faction_H`=14 WHERE `entry`=50417 LIMIT 1;
