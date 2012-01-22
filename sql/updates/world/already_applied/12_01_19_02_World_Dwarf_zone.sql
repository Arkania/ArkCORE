-- -------------
-- Dwaarf Zone
-- -------------
-- VISUAL: Ragged Young Wolf worng scale valeu(http://www.wowhead.com/npc=705)
UPDATE `creature_template` SET `scale`='0.5' WHERE `entry`='705';

-- NPC: Balir Frosthammer Was remove on 4.0.3 (http://www.wowhead.com/npc=713)
DELETE FROM `creature` WHERE `id`='713';

-- NPC: Felix Whindlebolt Double spanw, remove one, and new loc (http://www.wowhead.com/npc=8416)
DELETE FROM `creature` WHERE `id`=8416;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(412, 8416, 0, 1, 1, 7852, 8416, -6370.29, 570.136, 385.789, 2.5722, 600, 0, 0, 55, 0, 0, 0, 0, 0, 0);

-- NPC: Nori Pridedrift Is not present on Cata (http://www.wowhead.com/npc=12738)
DELETE FROM `creature` WHERE `id`=12738;

-- VISUAL: Ragged Timber Wolf worng scale valeu(http://www.wowhead.com/npc=704)
UPDATE `creature_template` SET `scale`='0.5' WHERE `entry`='704';

-- NPC: Jona Ironstock New loc taking from official (http://www.wowhead.com/npc=37087)
DELETE FROM `creature` WHERE `id`=37087;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(244853, 37087, 0, 1, 1, 30506, 37087, -6108.68, 385.738, 395.544, 4.97474, 600, 0, 0, 102, 0, 0, 0, 0, 0, 0);

-- NPC: Coldridge Citizen New loc taking from official (http://www.wowhead.com/npc=37218)
DELETE FROM `creature` WHERE `guid`='244233';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(244233, 37218, 0, 1, 1, 30586, 37218, -6097.72, 402.625, 395.539, 1.57006, 600, 0, 0, 102, 0, 0, 0, 0, 0, 0);

-- NPC: Gwen Armstead Equiptemplate taking from official (http://www.wowhead.com/npc=34936)
UPDATE `creature_template` SET `equipment_id`='51401' WHERE `entry`='34936';
DELETE FROM `creature_equip_template` WHERE `entry`='51401';
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES
('51401','3364','0','0');

-- NPC: Coldridge Citizen Fix loc and movements taking from offiial (http://www.wowhead.com/npc=37218)
DELETE FROM `creature` WHERE `guid` ='243802' AND `id`='37218';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(243802, 37218, 0, 1, 1, 30585, 37218, -6106.51, 371.738, 395.542, 5.30772, 600, 4, 0, 102, 0, 0, 1, 0, 0, 0);

-- NPC: Marryk Nurribit <Mage Trainer> Is not present on Cata, not in Dwarf area (http://www.wowhead.com/npc=944)
DELETE FROM `creature` WHERE `id`=944;

-- NPC: Wren Darkspring Is not present on Cata, not in Dwarf area (http://www.wowhead.com/npc=6376)
DELETE FROM `creature` WHERE `id`=6376;

-- NPC: Alamar Grimm <Warlock Trainer> Is not present on Cata, not in Dwarf area (http://www.wowhead.com/npc=6376)
DELETE FROM `creature` WHERE `id`=460;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(1024, 460, 0, 1, 1, 1930, 460, -5195.21, 509.182, 387.856, 0, 600, 0, 0, 102, 0, 0, 0, 0, 0, 0);

-- NPC: Coldridge Citizen Fix loc, movements and gender taking from offiial (http://www.wowhead.com/npc=37218)
DELETE FROM `creature` WHERE `guid` ='244064' AND `id`='37218';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(244064, 37218, 0, 1, 1, 30587, 37218, -6109.18, 379.636, 395.541, 1.17652, 600, 4, 0, 102, 0, 0, 1, 0, 0, 0);

-- NPC: Coldridge Citizen Fix loc, movements and gender taking from offiial (http://www.wowhead.com/npc=37218)
DELETE FROM `creature` WHERE `guid` ='243562' AND `id`='37218';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(243562, 37218, 0, 1, 1, 30587, 37218, -6107.15, 397.527, 395.541, 4.78071, 600, 3, 0, 102, 0, 0, 1, 0, 0, 0);

-- NPC: Coldridge Citizen Fix loc and movements taking from offiial (http://www.wowhead.com/npc=37218)
DELETE FROM `creature` WHERE `guid` ='244054' AND `id`='37218';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(244054, 37218, 0, 1, 1, 30588, 37218, -6077.55, 384.927, 393.602, 2.20708, 600, 3, 0, 102, 0, 0, 1, 0, 0, 0);

-- NPC: Coldridge Mountaineer Fix loc taking from offiial (http://www.wowhead.com/npc=853)
DELETE FROM `creature` WHERE `guid` ='411' AND `id`='853';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(411, 853, 0, 1, 1, 0, 0, -6109.82, 398.037, 395.544, 1.22286, 600, 0, 1, 11828, 0, 0, 2, 0, 0, 0);

-- NPC: Coldridge Citizen Fix loc and model taking from offiial (http://www.wowhead.com/npc=37218)
DELETE FROM `creature` WHERE `guid` ='243317' AND `id`='37218';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(243317, 37218, 0, 1, 1, 30586, 37218, -6052.05, 380.654, 398.875, 1.56529, 600, 0, 0, 102, 0, 0, 0, 0, 0, 0);

-- NPC: Coldridge Citizen Fix loc and model taking from offiial (http://www.wowhead.com/npc=37218)
DELETE FROM `creature` WHERE `guid` ='243814' AND `id`='37218';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(243814, 37218, 0, 1, 1, 30586, 37218, -6068.39, 393.841, 392.762, 1.53232, 600, 0, 0, 102, 0, 0, 0, 0, 0, 0);

-- NPC: Coldridge Citizen Fix loc and movements taking from offiial (http://www.wowhead.com/npc=37218)
DELETE FROM `creature` WHERE `guid` ='244004' AND `id`='37218';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(244004, 37218, 0, 1, 1, 30587, 37218, -6060.8, 378.273, 392.764, 5.63052, 600, 2, 0, 102, 0, 0, 1, 0, 0, 0);

-- NPC: Coldridge Citizen Fix loc, gender and movements taking from offiial (http://www.wowhead.com/npc=37218)
DELETE FROM `creature` WHERE `guid` ='243067' AND `id`='37218';
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(243067, 37218, 0, 1, 1, 30586, 37218, -6060, 390.047, 392.762, 2.11194, 600, 0, 0, 102, 0, 0, 0, 0, 0, 0);

-- NPC: Coldridge Defender No all Defenders got this emote, so disable for entry and  we will give only to npcs than need it (http://www.wowhead.com/npc=37177)
DELETE FROM `creature_template_addon` WHERE (`entry`=37177);

-- NPC:Rockjaw Invader Too much spawn with wrings locs (http://www.wowhead.com/npc=37070)
DELETE FROM `creature` WHERE `id`=37070;

-- NPC:Rockjaw Invader New locs taking from official (http://www.wowhead.com/npc=37070)
DELETE FROM `creature` WHERE `id`=37070;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(242797, 37070, 0, 1, 1, 0, 37070, -6270.19, 298.933, 382.455, 1.03125, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(243470, 37070, 0, 1, 1, 0, 37070, -6289.61, 370.204, 380.445, 1.60461, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(243660, 37070, 0, 1, 1, 0, 37070, -6308.91, 296.319, 379.249, 0.994346, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(243706, 37070, 0, 1, 1, 0, 37070, -6285.6, 315.531, 376.711, 0.850619, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(243721, 37070, 0, 1, 1, 0, 37070, -6311.35, 327.87, 377.946, 0.135906, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(243774, 37070, 0, 1, 1, 0, 37070, -6291.98, 344.618, 376.456, 3.9553, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(243888, 37070, 0, 1, 1, 0, 37070, -6260.36, 366.857, 383.891, 0.0330229, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(244032, 37070, 0, 1, 1, 0, 37070, -6256.16, 395.177, 383.291, 5.93922, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(244127, 37070, 0, 1, 1, 0, 37070, -6236.9, 413.755, 386.42, 5.99105, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(244272, 37070, 0, 1, 1, 0, 37070, -6266.81, 416.094, 385.174, 5.93058, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(244315, 37070, 0, 1, 1, 0, 37070, -6281.16, 380.162, 382.173, 1.63288, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0);

-- NPC: Wounded Coldridge Mountaineer New locs taking from official (http://www.wowhead.com/npc=37080)
DELETE FROM `creature` WHERE `id`=37080;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(245005, 37080, 0, 1, 1, 0, 37080, -6359.64, 300.715, 381.592, 4.15323, 300, 0, 0, 102, 0, 0, 0, 0, 0, 0),
(244896, 37080, 0, 1, 1, 1608, 37080, -6291.15, 411.457, 384.023, 2.07694, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(244843, 37080, 0, 1, 1, 1608, 37080, -6305.57, 253.106, 383.25, 3.82227, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(244412, 37080, 0, 1, 1, 0, 37080, -6343.99, 387.596, 377.607, 5.76016, 300, 0, 0, 102, 0, 0, 0, 0, 0, 0),
(244740, 37080, 0, 1, 1, 1598, 37080, -6281.63, 432.672, 384.337, 3.82227, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(244664, 37080, 0, 1, 1, 1608, 37080, -6247.52, 430.635, 385.9, 2.07694, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(243013, 37080, 0, 1, 1, 0, 37080, -6344.29, 364.168, 378.464, 5.02974, 300, 0, 0, 102, 0, 0, 0, 0, 0, 0),
(244444, 37080, 0, 1, 1, 1598, 37080, -6280.7, 351.55, 378.384, 0, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(244388, 37080, 0, 1, 1, 1598, 37080, -6268.46, 392.943, 382.318, 0, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(244014, 37080, 0, 1, 1, 1598, 37080, -6292.69, 304.205, 375.812, 2.07694, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(244001, 37080, 0, 1, 1, 1608, 37080, -6294.95, 378.092, 380.485, 5.14872, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(243756, 37080, 0, 1, 1, 1598, 37080, -6242.48, 449.585, 385.825, 5.14872, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(243505, 37080, 0, 1, 1, 1608, 37080, -6330.2, 301.783, 379.723, 1.02974, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(243213, 37080, 0, 1, 1, 1598, 37080, -6290.46, 245.658, 392.829, 2.07694, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(243101, 37080, 0, 1, 1, 1598, 37080, -6293.07, 272.248, 381.498, 4.20624, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(242707, 37080, 0, 1, 1, 0, 37080, -6357.64, 332.747, 380.879, 0.245091, 300, 0, 0, 102, 0, 0, 0, 0, 0, 0),
(242948, 37080, 0, 1, 1, 1608, 37080, -6321.38, 273.097, 379.88, 5.34071, 600, 0, 0, 10, 0, 0, 0, 0, 0, 0),
(242845, 37080, 0, 1, 1, 0, 37080, -6328.25, 415.598, 380.548, 2.47876, 300, 0, 0, 102, 0, 0, 0, 0, 0, 0);

-- NPC: Coldridge Defender New locs taking from official (http://www.wowhead.com/npc=37177)
DELETE FROM `creature` WHERE `id`=37177;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(6638426, 37177, 0, 1, 1, 0, 0, -6306.83, 299.02, 378.324, 4.15479, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(244989, 37177, 0, 1, 1, 1598, 37177, -6258.04, 366.812, 384.264, 2.97355, 600, 0, 0, 38, 0, 0, 0, 0, 0, 0),
(244944, 37177, 0, 1, 1, 1608, 37177, -6234.47, 413.267, 386.878, 2.89725, 600, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(244884, 37177, 0, 1, 1, 1608, 37177, -6278.35, 378.922, 382.434, 2.81727, 600, 0, 0, 32, 0, 0, 0, 0, 0, 0),
(244697, 37177, 0, 1, 1, 1598, 37177, -6280.63, 399.004, 381.826, 4.65431, 600, 0, 0, 32, 0, 0, 0, 0, 0, 0),
(244482, 37177, 0, 1, 1, 1608, 37177, -6280.36, 377.478, 382.304, 1.86222, 600, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(244445, 37177, 0, 1, 1, 1608, 37177, -6281.34, 383.975, 381.836, 4.71714, 600, 0, 0, 33, 0, 0, 0, 0, 0, 0),
(243709, 37177, 0, 1, 1, 1598, 37177, -6282.31, 377.575, 382.135, 1.23862, 600, 0, 0, 32, 0, 0, 0, 0, 0, 0),
(243459, 37177, 0, 1, 1, 1598, 37177, -6283.84, 317.419, 376.623, 4.10999, 600, 0, 0, 34, 0, 0, 0, 0, 0, 0),
(243091, 37177, 0, 1, 1, 1598, 37177, -6309.11, 328.575, 377.75, 3.43458, 600, 0, 0, 32, 0, 0, 0, 0, 0, 0),
(242830, 37177, 0, 1, 1, 1598, 37177, -6293.53, 342.741, 376.327, 1.11844, 600, 0, 0, 33, 0, 0, 0, 0, 0, 0),
(242789, 37177, 0, 1, 1, 1598, 37177, -6283.41, 378.202, 382.026, 0.846702, 600, 0, 0, 33, 0, 0, 0, 0, 0, 0),
(6638415, 37177, 0, 1, 1, 0, 37177, -6268.96, 301.984, 382.708, 3.73851, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(6638430, 37177, 0, 1, 1, 0, 0, -6253.8, 394.522, 383.389, 2.97277, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(243045, 37177, 0, 1, 1, 0, 0, -6263.2, 415.55, 385.341, 3.02225, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(6638432, 37177, 0, 1, 1, 0, 0, -6289.85, 372.342, 380.669, 4.86873, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(1, 37177, 0, 1, 1, 0, 0, -6267.71, 368.535, 382.532, 2.38373, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(6638434, 37177, 0, 1, 1, 0, 37177, -6267.73, 301.081, 382.885, 3.47776, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0);

-- NPC: Talin Keeneye Was removed on Cataclism (http://www.wowhead.com/npc=714)
DELETE FROM `creature` WHERE `id`=714;

-- NPC: Small Crag Boar removed some locs and moved some ones to new locs (http://www.wowhead.com/npc=708)
DELETE FROM `creature` WHERE guid IN 
(471,473,474,475,477,488,493,495,508,509,511,512,513,701,714,860,861,893,1017,245004,244442,244270,243874,243857,243535,243385,243338,243337,242841,242787);

DELETE FROM `creature` WHERE guid IN  (413,244681,243290,243029);
INSERT INTO `creature` VALUES
(413, 708, 0, 1, 1, 0, 0, -6282.71, 420.801, 384.079, 0.423397, 180, 4, 0, 71, 0, 0, 1, 0, 0, 0),
(244681, 708, 0, 1, 1, 607, 708, -6290.09, 248.062, 391.642, 4.47727, 600, 4, 0, 71, 0, 0, 1, 0, 0, 0),
(243290, 708, 0, 1, 1, 607, 708, -6178.3, 696.613, 386.896, 1.44932, 600, 4, 0, 71, 0, 0, 1, 0, 0, 0),
(243029, 708, 0, 1, 1, 607, 708, -6287.29, 283.778, 382.128, 0.997856, 600, 4, 0, 71, 0, 0, 1, 0, 0, 0);

-- NPC: Rockjaw Goon removed some locs (http://www.wowhead.com/npc=37073)
DELETE FROM `creature` WHERE guid IN 
(243274);

-- NPC: Ragged Young Wolf removed some locs and moved some ones to new locs (http://www.wowhead.com/npc=705)
DELETE FROM `creature` WHERE guid IN 
(338,344,345,346,347,400,418,419,428,1000,1002,1010,1012,1013,1014,1015,1016,1018,1032,1033,1034,1036,1053,1515,1516,1517,1518,1519,1525,1526,1527,1530,1539,1541,244375,243776,243022);

DELETE FROM `creature` WHERE guid IN  (1032,244874,244503,244026,243592,243575);
INSERT INTO `creature` VALUES
(1032, 705, 0, 1, 1, 0, 0, -6373.54, 279.287, 386.804, 0.555339, 370, 5, 0, 42, 0, 0, 1, 0, 0, 0),
(244874, 705, 0, 1, 1, 855, 705, -6295.39, 243.473, 392.517, 5.11395, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(244503, 705, 0, 1, 1, 855, 705, -6318.04, 214.879, 393.623, 3.40219, 600, 4, 0, 71, 0, 0, 1, 0, 0, 0),
(244026, 705, 0, 1, 1, 855, 705, -6346.18, 195.867, 394.92, 2.11824, 600, 4, 0, 71, 0, 0, 1, 0, 0, 0),
(243592, 705, 0, 1, 1, 855, 705, -6401.98, 336.142, 387.65, 3.15344, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(243575, 705, 0, 1, 1, 855, 705, -6401.89, 289.38, 394.7, 1.47488, 600, 4, 0, 71, 0, 0, 1, 0, 0, 0);

-- NPC: Burly Rockjaw Trogg removed some locs and moved some ones to new locs (http://www.wowhead.com/npc=724)
DELETE FROM `creature` WHERE guid IN 
(332,337,338,344,345,346,347,358,400,402,416,418,419,428,430,431,432,884,892,972,998,999,1000,1002,1010,1012,1013,1014,1015,1016,1018,1020,1031,1032,1033,1034,336,417,422,423,424,426,427,433,448,450,451,453,454,455,459,464,467,479,480,482,483,486,487,497,498,504,863,864,876,877,882,883,896,929,937,938,939,955,956,958,960,1045,1048,1058,1512,1514,1523,1536,1537,1538,1544,1547);

DELETE FROM `creature` WHERE guid IN  (1523,1544);
INSERT INTO `creature` VALUES
(1523, 724, 0, 1, 1, 0, 0, -6346.33, 288.676, 380.931, 4.59857, 370, 5, 0, 55, 0, 0, 1, 0, 0, 0),
(1544, 724, 0, 1, 1, 0, 0, -6397.44, 240.061, 399.291, 0.186212, 370, 0, 0, 55, 0, 0, 0, 0, 0, 0);

-- NPC: Rabbit removed some locs and moved some ones to new locs (http://www.wowhead.com/npc=721)
DELETE FROM `creature` WHERE guid IN 
(245103,243886,243518,243159,243023);

DELETE FROM `creature` WHERE guid IN  (244239);
INSERT INTO `creature` VALUES
(244239, 721, 0, 1, 1, 328, 721, -6303.6, 272.187, 380.32, 3.32857, 600, 10, 0, 1, 0, 0, 1, 0, 0, 0);

-- NPC: Rockjaw Scavenger Moved some ones to new locs (http://www.wowhead.com/npc=37105)
DELETE FROM `creature` WHERE guid IN  (244621);
INSERT INTO `creature` VALUES
(244621, 37105, 0, 1, 1, 611, 37105, -6290.09, 470.355, 386.123, 5.86882, 600, 4, 0, 55, 0, 0, 1, 0, 0, 0);

-- NPC: Frostmane Troll Whelp Need a addon in this guid (http://www.wowhead.com/npc=706)
DELETE FROM `creature_addon` WHERE (`guid`=936);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(936, 0, 0, 8, 1, 0, '');

-- NPC: Frostmane Troll Whelp Moved some ones to new locs (http://www.wowhead.com/npc=706)
DELETE FROM `creature` WHERE guid IN 
(865,866,868,869,874,879,887,974,1065,1075,244858,243267,243072,243009,242958,242753,242747,242741);

DELETE FROM `creature` WHERE guid IN  (888,936,978,1080,1084,1085,1492,1506,243985);
INSERT INTO `creature` VALUES
(888, 706, 0, 1, 1, 0, 0, -6477.07, 701.281, 390.643, 2.17705, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(936, 706, 0, 1, 1, 0, 0, -6510.08, 685.565, 387.457, 5.44543, 180, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(978, 706, 0, 1, 1, 0, 0, -6518.71, 466.018, 387.506, 5.07879, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(1080, 706, 0, 1, 1, 0, 0, -6477.3, 389.722, 383.13, 2.87478, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(1084, 706, 0, 1, 1, 0, 0, -6496.07, 398.316, 386.692, 3.45881, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(1085, 706, 0, 1, 1, 0, 0, -6539.19, 473.222, 385.998, 4.62916, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(1492, 706, 0, 1, 1, 0, 0, -6472.68, 358.09, 377.506, 3.4828, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(1506, 706, 0, 1, 1, 0, 0, -6527.04, 302.087, 382.4, 0.146395, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(243985, 706, 0, 1, 1, 27503, 706, -6494.15, 696.028, 390.102, 6.23082, 600, 0, 0, 86, 0, 0, 0, 0, 0, 0);

-- NPC: Grik'nir the Cold New loc taking from official (http://www.wowhead.com/npc=808)
DELETE FROM `creature` WHERE `id`=808;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(1502, 808, 0, 1, 1, 0, 0, -6506.82, 297.182, 370.161, 0.854523, 180, 0, 0, 98, 115, 0, 0, 0, 0, 0);

-- NPC: Wayward Fire Elemental New loc taking from official (http://www.wowhead.com/npc=37112)
DELETE FROM `creature` WHERE `id`=37112;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(6614475, 37112, 0, 1, 1, 0, 0, -6495.7, 328.227, 368.467, 1.66623, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0);

-- NPC: Frostmane Troll Whelp Remove wrong flags (http://www.wowhead.com/npc=706)
UPDATE `creature_template` SET `npcflag`='0' WHERE `entry`='706';

-- NPC: Frostmane Troll Whelp removed some locs and moved some ones to new locs (http://www.wowhead.com/npc=706)
DELETE FROM `creature` WHERE guid IN 
(975,865,866,868,869,874,879,887,974,1065,1075,1080,1084,1492,244858,243267,243072,243009,242958,242753,242747,242741);

DELETE FROM `creature` WHERE guid IN  (888,978,1080,1084,243985,1506,1492);
INSERT INTO `creature` VALUES
(888, 706, 0, 1, 1, 0, 0, -6477.07, 701.281, 390.643, 2.17705, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(978, 706, 0, 1, 1, 0, 0, -6518.71, 466.018, 387.506, 5.07879, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(1080, 706, 0, 1, 1, 0, 0, -6477.3, 389.722, 383.13, 2.87478, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(1084, 706, 0, 1, 1, 0, 0, -6496.07, 398.316, 386.692, 3.45881, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(243985, 706, 0, 1, 1, 27503, 706, -6494.15, 696.028, 390.102, 6.23082, 600, 0, 0, 86, 0, 0, 0, 0, 0, 0),
(1506, 706, 0, 1, 1, 0, 0, -6527.04, 302.087, 382.4, 0.146395, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(1492, 706, 0, 1, 1, 0, 0, -6472.68, 358.09, 377.506, 3.4828, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0);

-- NPC: Wayward Fire Elemental Wrong level and damanges (http://www.wowhead.com/npc=37112)
UPDATE `creature_template` SET `minlevel`='5', `maxlevel`='5', `mindmg`='5', `maxdmg`='6', `attackpower`='2', `dmg_multiplier`='1', `baseattacktime`='2000', `minrangedmg`='4', `maxrangedmg`='5', `dmgschool`='0', `rangeattacktime`='2000' WHERE `entry`='37112';

-- LOOT: Remove Priceless Rockjaw Artifact this item is taking with SAI from NPC I made it and is working (http://www.wowhead.com/item=49751) 
DELETE FROM `creature_loot_template` WHERE (`entry`=37105) AND (`item`=49751);

-- Monster - Spear, Rusty (http://www.wowhead.com/item=2023)
-- Monster - Gun (http://www.wowhead.com/item=2552)
-- NPC: Coldridge Defender Need a equipment (http://www.wowhead.com/npc=37177)
DELETE FROM `creature_equip_template` WHERE (`entry`=37177);
INSERT INTO `creature_equip_template` (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES
(37177, 2023, '0', 2552);

-- NPC: Webwood Spider Fix locs taking from official (http://www.wowhead.com/npc=1986)
DELETE FROM `creature` WHERE `id`=1986;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(46958, 1986, 1, 1, 1, 709, 0, 10901.5, 877.607, 1330.02, 4.54922, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(46971, 1986, 1, 1, 1, 709, 0, 10948.4, 894.388, 1337.57, 2.37731, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(46972, 1986, 1, 1, 1, 709, 0, 10946.9, 868.31, 1333.54, 2.07776, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(46974, 1986, 1, 1, 1, 709, 0, 10934.6, 866.205, 1332.33, 0.647587, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(46996, 1986, 1, 1, 1, 709, 0, 10874.1, 918.134, 1330.3, 0.060572, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(46997, 1986, 1, 1, 1, 709, 0, 10898.4, 899.52, 1323.7, 2.03641, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(47000, 1986, 1, 1, 1, 709, 0, 10860.8, 860.262, 1327.82, 5.9069, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(47005, 1986, 1, 1, 1, 709, 0, 10975.4, 977.036, 1335.02, 3.14551, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(47008, 1986, 1, 1, 1, 709, 0, 10953.2, 941.028, 1340.61, 0.306411, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(47017, 1986, 1, 1, 1, 709, 0, 10829.9, 938.924, 1336.01, 2.86993, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(47018, 1986, 1, 1, 1, 709, 0, 10846.5, 966.492, 1335.8, 1.04653, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(47024, 1986, 1, 1, 1, 709, 0, 10931.6, 949.188, 1322.1, 2.95782, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(47038, 1986, 1, 1, 1, 709, 0, 10665.8, 934.3, 1322, 1.40995, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(47039, 1986, 1, 1, 1, 709, 0, 10972.9, 937.654, 1337.93, 3.62358, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(47054, 1986, 1, 1, 1, 709, 0, 10681.9, 882.404, 1320.55, 5.86431, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(47055, 1986, 1, 1, 1, 709, 0, 10704.6, 944.455, 1328.3, 4.38078, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(47062, 1986, 1, 1, 1, 709, 0, 10679.8, 900.103, 1320.82, 4.15732, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(47208, 1986, 1, 1, 1, 709, 0, 10727, 952.523, 1332.22, 1.0757, 600, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(47263, 1986, 1, 1, 1, 709, 0, 10864.9, 979.124, 1336.56, 3.40339, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(47271, 1986, 1, 1, 1, 709, 0, 10911.8, 969.353, 1338.93, 0.314159, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(246873, 1986, 1, 1, 1, 709, 1986, 10911.3, 867.345, 1329.03, 4.09205, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(246862, 1986, 1, 1, 1, 709, 1986, 10776, 928.734, 1338.68, 1.73771, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(246848, 1986, 1, 1, 1, 709, 1986, 10963.6, 914.224, 1340.78, 5.02655, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(246731, 1986, 1, 1, 1, 709, 1986, 10885.2, 878.474, 1325.65, 0.02836, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(246306, 1986, 1, 1, 1, 709, 1986, 10866.9, 870.509, 1327.34, 4.71073, 600, 0, 0, 86, 0, 0, 0, 0, 0, 0),
(245935, 1986, 1, 1, 1, 709, 1986, 10839.4, 887.524, 1333.53, 3.95788, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(245818, 1986, 1, 1, 1, 709, 1986, 10914.4, 925.208, 1321.85, 3.88825, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(245550, 1986, 1, 1, 1, 709, 1986, 10819.6, 901.707, 1336.11, 6.11774, 600, 0, 0, 86, 0, 0, 0, 0, 0, 0),
(245225, 1986, 1, 1, 1, 709, 1986, 10797.4, 936.481, 1336.61, 0.179768, 600, 0, 0, 86, 0, 0, 0, 0, 0, 0),
(245171, 1986, 1, 1, 1, 709, 1986, 10887.1, 987.507, 1336.93, 1.24316, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(245137, 1986, 1, 1, 1, 709, 1986, 10921.7, 951.733, 1340.09, 1.43885, 600, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(245126, 1986, 1, 1, 1, 709, 1986, 10937.1, 974.208, 1327.17, 0.768863, 600, 0, 0, 86, 0, 0, 0, 0, 0, 0);

-- NPC: Githyiss the Vile Fix locs taking from official and double spawn (http://www.wowhead.com/npc=1994)
DELETE FROM `creature` WHERE `id`=1994;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(245172, 1994, 1, 1, 1, 759, 1994, 10943.2, 924.796, 1340.79, 0.60286, 600, 0, 0, 255, 0, 0, 0, 0, 0, 0);

-- NPC: Gnarlpine Corruption Totem Can't move and scale (http://www.wowhead.com/npc=49598)
UPDATE `creature` SET `spawndist`='0', `MovementType`='0' WHERE `guid`='246655';
UPDATE `creature_template` SET `scale`='1.5' WHERE `entry`='49598';

-- Frostmane Blade <Grik'nir's Servant> Fix locs taking from official (http://www.wowhead.com/npc=1986)
DELETE FROM `creature` WHERE `guid` IN (978,1085,1309,1087,1091,1088,1084,1487,1486,1485,1484,1311,1078,1080,1492,1493,1501,1507,1505,1494,1503,1504,1495,1490,1491,1488,1473,1483,1474,1349,1478,1479,1497,1498,1499,1500,1506);
DELETE FROM `creature` WHERE `id`=37507;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(1084, 37507, 0, 1, 1, 0, 0, -6489.5, 397.26, 384.352, 3.29161, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1078, 37507, 0, 1, 1, 0, 0, -6528.63, 399.69, 382.037, 0.679748, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1085, 37507, 0, 1, 1, 0, 0, -6534.02, 467.802, 386.308, 2.59574, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1087, 37507, 0, 1, 1, 0, 0, -6538.08, 425.747, 386.04, 4.03616, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1088, 37507, 0, 1, 1, 0, 0, -6511.86, 418.936, 386.521, 4.5332, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1091, 37507, 0, 1, 1, 0, 0, -6520.7, 422.008, 386.238, 4.12884, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1309, 37507, 0, 1, 1, 0, 0, -6532.21, 441.461, 385.135, 1.31105, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1349, 37507, 0, 1, 1, 0, 0, -6582.05, 373.76, 389.408, 5.5457, 180, 2, 0, 69, 79, 0, 1, 0, 0, 0),
(1478, 37507, 0, 1, 1, 0, 0, -6568.07, 365.826, 391.152, 2.51327, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1479, 37507, 0, 1, 1, 0, 0, -6541.91, 371.584, 396.573, 0.509134, 180, 0, 0, 69, 79, 0, 0, 0, 0, 0),
(1483, 37507, 0, 1, 1, 0, 0, -6601.49, 394.644, 388.461, 3.92385, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1484, 37507, 0, 1, 1, 0, 0, -6537.85, 389.46, 381.749, 5.70587, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1485, 37507, 0, 1, 1, 0, 0, -6533.38, 375.865, 382.545, 0.72174, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1486, 37507, 0, 1, 1, 0, 0, -6522.79, 383.491, 383.047, 6.02372, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1487, 37507, 0, 1, 1, 0, 0, -6506.69, 385.506, 385.346, 3.34341, 180, 5, 0, 71, 0, 0, 1, 0, 0, 0),
(1488, 37507, 0, 1, 1, 0, 0, -6574.32, 409.03, 387.516, 0.005852, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1490, 37507, 0, 1, 1, 0, 0, -6515.74, 345.666, 371.934, 5.08914, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1491, 37507, 0, 1, 1, 0, 0, -6503.81, 350.279, 373.755, 5.84651, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1494, 37507, 0, 1, 1, 0, 37507, -6501.63, 335.876, 368.087, 2.73639, 180, 5, 0, 86, 0, 1, 1, 0, 0, 0),
(1495, 37507, 0, 1, 1, 0, 0, -6518.02, 332.052, 373.123, 4.0484, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1497, 37507, 0, 1, 1, 0, 0, -6581.86, 319.805, 386.769, 5.19229, 180, 2, 0, 69, 79, 0, 1, 0, 0, 0),
(1498, 37507, 0, 1, 1, 0, 0, -6566.28, 295.361, 387.955, 1.55334, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1499, 37507, 0, 1, 1, 0, 0, -6546.19, 298.689, 383.98, 5.78063, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1500, 37507, 0, 1, 1, 0, 0, -6532.19, 304.589, 382.438, 3.77789, 180, 2, 0, 69, 79, 0, 1, 0, 0, 0),
(1501, 37507, 0, 1, 1, 0, 0, -6480.12, 320.714, 375.095, 4.2176, 180, 2, 0, 71, 0, 0, 1, 0, 0, 0),
(1503, 37507, 0, 1, 1, 0, 0, -6504.5, 295.569, 370.05, 0.855211, 180, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(1504, 37507, 0, 1, 1, 0, 0, -6512.54, 313.134, 372.942, 5.95282, 180, 2, 0, 69, 79, 0, 1, 0, 0, 0),
(1505, 37507, 0, 1, 1, 0, 37507, -6497.38, 319.891, 368.677, 2.22797, 180, 5, 0, 86, 0, 1, 1, 0, 0, 0),
(1507, 37507, 0, 1, 1, 0, 0, -6486.41, 306.785, 372.023, 4.53097, 180, 2, 0, 69, 79, 0, 1, 0, 0, 0),
(244976, 37507, 0, 1, 1, 27500, 37507, -6494.62, 483.508, 388.505, 0.3228, 600, 0, 0, 86, 0, 0, 0, 0, 0, 0),
(244512, 37507, 0, 1, 1, 27500, 37507, -6466.64, 359.877, 378.35, 4.93624, 600, 2, 0, 86, 0, 0, 1, 0, 0, 0),
(244212, 37507, 0, 1, 1, 27500, 37507, -6473.54, 339.097, 375.753, 4.41316, 600, 2, 0, 86, 0, 0, 1, 0, 0, 0),
(244165, 37507, 0, 1, 1, 27500, 37507, -6538.17, 475.98, 385.653, 2.00905, 600, 2, 0, 86, 0, 0, 1, 0, 0, 0),
(243346, 37507, 0, 1, 1, 27500, 37507, -6518.75, 469.656, 388, 2.40332, 600, 2, 0, 86, 0, 0, 1, 0, 0, 0),
(243276, 37507, 0, 1, 1, 27501, 37507, -6471.1, 383.212, 381.076, 5.70906, 600, 2, 0, 86, 0, 0, 1, 0, 0, 0);

-- --------------
-- WAYPOINTS
-- --------------
-- VISUAL: Sten Stoutarm wp taking from oficcial (http://www.wowhead.com/npc=658)
UPDATE `creature_template` SET `MovementType`='2' WHERE `entry`='658';
-- Creating addon for Sten Stoutarm
DELETE FROM `creature_addon` WHERE (`guid`=242905);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(242905, '658', 0, 0, 0, 0, '');
-- Update creature Sten Stoutarm form wp
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 242905;
-- WP for Sten Stoutarm raking WP from oficcial
DELETE FROM waypoint_data WHERE id='658';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('658','1','-6240.07','347.343','383.841','900000','0','0','100','0'),
('658','2','-6243.17','346.692','383.435','0','0','0','100','0'),
('658','3','-6244.83','345.971','383.121','0','0','0','100','0'),
('658','4','-6242.29','346.731','383.57','0','0','0','100','0'),
('658','5','-6240.21','347.357','383.837','0','0','0','100','0'),
('658','6','-6237.14','347.644','383.935','0','0','0','100','0'),
('658','7','-6232.81','348.05','383.899','0','0','0','100','0'),
('658','8','-6230.22','348.293','383.854','0','0','0','100','0'),
('658','9','-6232.43','348.016','383.876','0','0','0','100','0'),
('658','10','-6236.46','347.51','383.894','0','0','0','100','0'),
('658','11','-6239.14','347.173','383.809','0','0','0','100','0'),
('658','12','-6240.04','347.242','383.823','0','0','0','100','0'),
('658','13','-6242.28','347.413','383.624','0','0','0','100','0'),
('658','14','-6244.06','347.549','383.377','0','0','0','100','0'),
('658','15','-6244.7','346.66','383.201','0','0','0','100','0'),
('658','16','-6243.07','347.326','383.505','0','0','0','100','0'),
('658','17','-6240.04','347.333','383.84','0','0','0','100','0'),
('658','18','-6235.26','347.345','383.852','0','0','0','100','0'),
('658','19','-6230.93','347.355','383.742','0','0','0','100','0'),
('658','20','-6227.89','347.362','383.684','0','0','0','100','0'),
('658','21','-6230.12','347.273','383.734','0','0','0','100','0'),
('658','22','-6233.68','347.13','383.788','0','0','0','100','0'),
('658','23','-6236.81','347.005','383.797','0','0','0','100','0'),
('658','24','-6239.91','347.403','383.851','0','0','0','100','0');

-- VISUAL: Felix Whindlebolt wp taking from oficcial (http://www.wowhead.com/npc=8416)
UPDATE `creature_template` SET `MovementType`='2' WHERE `entry`='8416';
-- Creating addon for Felix Whindlebolt
DELETE FROM `creature_addon` WHERE (`guid`=412);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(412, '412', 0, 0, 0, 0, '');
-- Update creature Felix Whindlebolt form wp
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 412;
DELETE FROM waypoint_data WHERE id='412';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('412','1','-6370.25','570.149','385.792','300000','0','0','100','0'),
('412','2','-6372.35','569.243','385.68','0','0','0','100','0'),
('412','3','-6371.98','565.579','385.619','0','0','0','100','0'),
('412','4','-6370.16','565.588','385.703','0','0','0','100','0'),
('412','5','-6369.13','568.626','385.849','0','0','0','100','0'),
('412','6','-6369.51','573.16','385.774','0','0','0','100','0'),
('412','7','-6369.77','576.313','385.808','0','0','0','100','0'),
('412','8','-6367.2','578.201','385.94','0','0','0','100','0'),
('412','9','-6368.3','576.188','385.898','0','0','0','100','0'),
('412','10','-6366','572.223','386.021','0','0','0','100','0'),
('412','11','-6368.39','569.432','385.876','0','0','0','100','0'),
('412','12','-6370.1','570.118','385.8','0','0','0','100','0');

-- VISUAL: Jona Ironstock wp taking from oficcial (http://www.wowhead.com/npc=37087)
UPDATE `creature_template` SET `MovementType`='2' WHERE `entry`='37087';
-- Creating addon for Sten Stoutarm
DELETE FROM `creature_addon` WHERE (`guid`=244853);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(244853, '244853', 0, 0, 0, 0, '');
-- Update creature Jona Ironstock form wp
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 244853;
-- WP for Jona Ironstock raking WP from oficcial
DELETE FROM waypoint_data WHERE id='244853';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('244853','1','-6108.68','385.846','395.544','0','0','0','100','0'),
('244853','2','-6108.6','381.458','395.544','0','0','0','100','0'),
('244853','3','-6107.08','378.305','395.544','0','0','0','100','0'),
('244853','4','-6104.5','375.322','395.544','0','0','0','100','0'),
('244853','5','-6100.52','373.37','395.544','0','0','0','100','0'),
('244853','6','-6097.75','372.007','395.542','0','0','0','100','0'),
('244853','7','-6092.28','373.968','395.542','0','0','0','100','0'),
('244853','8','-6089','376.987','395.542','0','0','0','100','0'),
('244853','9','-6087.79','382.181','395.542','0','0','0','100','0'),
('244853','10','-6086.67','386.945','395.542','0','0','0','100','0'),
('244853','11','-6089.33','391.047','395.542','0','0','0','100','0'),
('244853','12','-6093.01','393.552','395.542','0','0','0','100','0'),
('244853','13','-6099.16','394.812','395.542','0','0','0','100','0'),
('244853','14','-6102.19','395.431','395.542','0','0','0','100','0'),
('244853','15','-6104.65','392.797','395.542','0','0','0','100','0'),
('244853','16','-6107.75','389.483','395.542','0','0','0','100','0'),
('244853','17','-6108.68','385.624','395.542','0','0','0','100','0');

-- VISUAL: Coldridge Citizen wp taking from oficcial (http://www.wowhead.com/npc=37218)
UPDATE `creature_template` SET `MovementType`='2' WHERE `entry`='37218';
-- Creating addon for Sten Stoutarm
DELETE FROM `creature_addon` WHERE (`guid`=244233);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(244233, '244233', 0, 0, 0, 0, '');
-- Update creature Coldridge Citizen form wp
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 244233;
-- WP for Coldridge Citizen raking WP from oficcial
DELETE FROM waypoint_data WHERE id='244233';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('244233','1','-6097.64','402.669','395.539','10000','0','60000','100','0'),
('244233','2','-6095.87','402.624','395.539','0','0','0','100','0'),
('244233','3','-6092.21','400.993','395.539','0','0','0','100','0'),
('244233','4','-6088.56','399.369','395.541','0','0','0','100','0'),
('244233','5','-6085.31','397.066','394.946','0','0','0','100','0'),
('244233','6','-6082.95','394.554','394.322','0','0','0','100','0'),
('244233','7','-6080.53','391.97','393.599','0','0','0','100','0'),
('244233','8','-6078.39','386.12','393.6','0','0','0','100','0'),
('244233','9','-6069.22','384.261','393.602','0','0','0','100','0'),
('244233','10','-6068.14','386.698','393.602','0','0','0','100','0'),
('244233','11','-6068.1','389.365','393.597','0','0','0','100','0'),
('244233','12','-6068.08','390.246','393.107','0','0','0','100','0'),
('244233','13','-6068.03','393.354','392.762','0','0','0','100','0'),
('244233','14','-6067.96','397.784','392.76','0','0','0','100','0'),
('244233','15','-6066.37','399.293','392.759','0','0','0','100','0'),
('244233','16','-6064.17','399.668','392.757','0','0','0','100','0'),
('244233','17','-6060.94','398.221','392.757','0','0','0','100','0'),
('244233','18','-6057.42','398.141','392.757','50000','0','60001','100','0'),
('244233','19','-6060.5','398.782','392.757','0','0','0','100','0'),
('244233','20','-6063.65','399.436','392.757','0','0','0','100','0'),
('244233','21','-6065.34','399.789','392.757','0','0','0','100','0'),
('244233','22','-6066.97','399.136','392.757','0','0','0','100','0'),
('244233','23','-6067.66','395.621','392.759','0','0','0','100','0'),
('244233','24','-6067.67','391.631','392.761','0','0','0','100','0'),
('244233','25','-6067.67','390.294','393.076','0','0','0','100','0'),
('244233','26','-6067.67','387.634','393.599','0','0','0','100','0'),
('244233','27','-6067.71','384.961','393.6','0','0','0','100','0'),
('244233','28','-6072.06','383.963','393.6','0','0','0','100','0'),
('244233','29','-6075.14','384.503','393.599','0','0','0','100','0'),
('244233','30','-6077.7','387.002','393.599','0','0','0','100','0'),
('244233','31','-6080.53','391.528','393.6','0','0','0','100','0'),
('244233','32','-6083.38','394.339','394.327','0','0','0','100','0'),
('244233','33','-6084.96','395.904','394.796','0','0','0','100','0'),
('244233','34','-6087.2','398.124','395.299','0','0','0','100','0'),
('244233','35','-6088.47','399.379','395.544','0','0','0','100','0'),
('244233','36','-6093.26','398.249','395.542','0','0','0','100','0'),
('244233','37','-6095.92','397.622','395.541','0','0','0','100','0'),
('244233','38','-6097.16','400.448','395.539','0','0','0','100','0'),
('244233','39','-6097.64','402.617','395.539','0','0','0','100','0');
-- Coldridge Citizen special emots on some points
DELETE FROM waypoint_scripts WHERE id IN ('60000','60001');
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(60000,0,1,423,0,0,0,0,0,0,244233),
(60001,0,1,69,0,0,0,0,0,0,244234);

-- VISUAL: Coldridge Mountaineer wp taking from oficcial (http://www.wowhead.com/npc=853)
-- Creating addon for Sten Stoutarm
DELETE FROM `creature_addon` WHERE (`guid`=245003);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(245003, 245003, 0, 0, 257, 0, '');
-- Update creature Coldridge Mountaineer form wp
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 244853;
-- WP for Coldridge Mountaineer raking WP from oficcial
DELETE FROM waypoint_data WHERE id='245003';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('245003','1','-6098.98','375.603','395.542','18000','0','0','100','0'),
('245003','2','-6094.75','374.63','395.542','0','0','0','100','0'),
('245003','3','-6090.95','374.538','395.542','0','0','0','100','0'),
('245003','4','-6089.14','377.997','395.542','0','0','0','100','0'),
('245003','5','-6086.63','383.042','395.542','0','0','0','100','0'),
('245003','6','-6088.94','388.616','395.542','0','0','0','100','0'),
('245003','7','-6091.23','393.795','395.542','0','0','0','100','0'),
('245003','8','-6094.82','396.109','395.542','0','0','0','100','0'),
('245003','9','-6100.46','396.65','395.542','0','0','0','100','0'),
('245003','10','-6105.11','395.503','395.542','0','0','0','100','0'),
('245003','11','-6109.74','394.39','395.542','0','0','0','100','0'),
('245003','12','-6115.72','393.786','395.542','0','0','0','100','0'),
('245003','13','-6122.21','393.132','395.542','0','0','0','100','0'),
('245003','14','-6128.31','392.517','395.542','0','0','0','100','0'),
('245003','15','-6130.18','386.936','395.544','0','0','0','100','0'),
('245003','16','-6130.85','384.945','395.544','0','0','0','100','0'),
('245003','17','-6138.58','384.434','395.544','0','0','0','100','0'),
('245003','18','-6146.77','383.893','395.544','0','0','0','100','0'),
('245003','19','-6151.76','383.563','395.544','0','0','0','100','0'),
('245003','20','-6156.17','383.272','395.544','0','0','0','100','0'),
('245003','21','-6159.69','383.751','397.414','0','0','0','100','0'),
('245003','22','-6162.32','384.108','398.728','0','0','0','100','0'),
('245003','23','-6164.09','384.349','399.154','0','0','0','100','0'),
('245003','24','-6165.43','382.573','399.154','0','0','0','100','0'),
('245003','25','-6169.77','376.829','398.839','28000','0','0','100','0'),
('245003','26','-6169.66','383.737','398.647','0','0','0','100','0'),
('245003','27','-6164.11','383.458','399.154','0','0','0','100','0'),
('245003','28','-6160.69','383.379','397.912','0','0','0','100','0'),
('245003','29','-6157.32','383.408','396.229','0','0','0','100','0'),
('245003','30','-6153.92','383.381','395.543','0','0','0','100','0'),
('245003','31','-6131.14','383.202','395.543','0','0','0','100','0'),
('245003','32','-6129.42','379.353','395.547','0','0','0','100','0'),
('245003','33','-6128.22','376.655','395.545','0','0','0','100','0'),
('245003','34','-6124.46','375.906','395.545','0','0','0','100','0'),
('245003','35','-6119.77','375.243','395.544','0','0','0','100','0'),
('245003','36','-6114.56','374.73','395.544','0','0','0','100','0'),
('245003','37','-6109.79','374.26','395.544','0','0','0','100','0'),
('245003','38','-6104.18','373.69','395.544','0','0','0','100','0'),
('245003','39','-6099.85','373.25','395.544','0','0','0','100','0'),
('245003','40','-6099.02','375.574','395.544','0','0','0','100','0');

-- VISUAL: Coldridge Mountaineer wp taking from oficcial (http://www.wowhead.com/npc=853)
-- Creating addon for Sten Stoutarm
DELETE FROM `creature_addon` WHERE (`guid`=411);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(411, 411, 0, 0, 0, 0, '');
-- Update creature Coldridge Mountaineer form wp
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 411;
-- WP for Coldridge Mountaineer raking WP from oficcial
DELETE FROM waypoint_data WHERE id='411';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('411','1','-6109.83','397.777','395.544','70000','0','0','100','0'),
('411','2','-6111.63','398.981','395.544','0','0','0','100','0'),
('411','3','-6109.48','394.098','395.544','0','0','0','100','0'),
('411','4','-6108.07','390.88','395.544','0','0','0','100','0'),
('411','5','-6110.07','385.559','395.544','0','0','0','100','0'),
('411','6','-6109.09','381.322','395.544','0','0','0','100','0'),
('411','7','-6108.13','377.112','395.544','0','0','0','100','0'),
('411','8','-6103.76','372.899','395.544','0','0','0','100','0'),
('411','9','-6099.39','368.68','395.541','0','0','0','100','0'),
('411','10','-6095.36','367.054','395.539','0','0','0','100','0'),
('411','11','-6092.35','367.675','395.539','0','0','0','100','0'),
('411','12','-6088.89','368.389','395.541','0','0','0','100','0'),
('411','13','-6086.73','369.859','395.242','0','0','0','100','0'),
('411','14','-6084.95','371.103','394.89','0','0','0','100','0'),
('411','15','-6083.14','373.561','394.34','0','0','0','100','0'),
('411','16','-6081.08','376.358','393.599','0','0','0','100','0'),
('411','17','-6077.99','380.552','393.599','0','0','0','100','0'),
('411','18','-6078.14','384.394','393.599','0','0','0','100','0'),
('411','19','-6072.07','384.088','393.599','0','0','0','100','0'),
('411','20','-6065.56','383.761','393.598','10000','0','0','100','0'),
('411','21','-6066.35','384.133','393.598','0','0','0','100','0'),
('411','22','-6068.49','384.052','393.599','0','0','0','100','0'),
('411','23','-6073.66','384.247','393.599','0','0','0','100','0'),
('411','24','-6074.96','384.297','393.599','0','0','0','100','0'),
('411','25','-6077.08','386.581','393.599','0','0','0','100','0'),
('411','26','-6079.14','389.941','393.6','0','0','0','100','0'),
('411','27','-6080.64','391.558','393.6','0','0','0','100','0'),
('411','28','-6083.04','394.15','394.255','0','0','0','100','0'),
('411','29','-6084.83','396.075','394.798','0','0','0','100','0'),
('411','30','-6086.6','397.989','395.203','0','0','0','100','0'),
('411','31','-6088.38','399.904','395.543','0','0','0','100','0'),
('411','32','-6091.82','399.38','395.542','0','0','0','100','0'),
('411','33','-6094.35','395.739','395.542','0','0','0','100','0'),
('411','34','-6097.57','397.155','395.542','0','0','0','100','0'),
('411','35','-6101.06','396.546','395.542','0','0','0','100','0'),
('411','36','-6104.13','396.009','395.542','0','0','0','100','0'),
('411','37','-6106.63','393.461','395.542','0','0','0','100','0'),
('411','38','-6108.82','395.592','395.542','0','0','0','100','0'),
('411','39','-6109.91','397.648','395.542','0','0','0','100','0');

-- VISUAL: Coldridge Citizen wp taking from oficcial (http://www.wowhead.com/npc=853)
-- Creating addon for Coldridge Citizen
DELETE FROM `creature_addon` WHERE (`guid`=243317);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(243317, 243317, 0, 0, 1, 0, '');
-- Update creature Coldridge Citizenr form wp
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 243317;
-- WP for Coldridge Citizen raking WP from oficcial
DELETE FROM waypoint_data WHERE id='243317';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('243317','1','-6052.1','380.735','398.875','0','0','0','100','0'),
('243317','2','-6052.18','378.581','398.875','0','0','0','100','0'),
('243317','3','-6052.25','376.44','397.618','0','0','0','100','0'),
('243317','4','-6052.36','373.439','395.618','0','0','0','100','0'),
('243317','5','-6052.45','370.872','395.263','0','0','0','100','0'),
('243317','6','-6054.62','370.875','395.263','0','0','0','100','0'),
('243317','7','-6056.36','370.878','394.589','0','0','0','100','0'),
('243317','8','-6058.98','370.882','393.597','0','0','0','100','0'),
('243317','9','-6060.71','370.885','393.597','0','0','0','100','0'),
('243317','10','-6061.05','372.6','393.597','0','0','0','100','0'),
('243317','11','-6061.56','375.094','392.763','0','0','0','100','0'),
('243317','12','-6061.57','378.16','392.763','0','0','0','100','0'),
('243317','13','-6061.59','383.018','392.763','0','0','0','100','0'),
('243317','14','-6061.26','384.735','392.763','0','0','0','100','0'),
('243317','15','-6061.01','386.02','392.763','0','0','0','100','0'),
('243317','16','-6061.53','388.593','392.763','0','0','0','100','0'),
('243317','17','-6060.08','390.78','392.763','0','0','0','100','0'),
('243317','18','-6061.11','393.178','392.761','0','0','0','100','0'),
('243317','19','-6062.75','393.835','392.761','0','0','0','100','0'),
('243317','20','-6065.15','392.791','392.761','0','0','0','100','0'),
('243317','21','-6066.78','392.08','392.761','0','0','0','100','0'),
('243317','22','-6067.4','391.446','392.761','0','0','0','100','0'),
('243317','23','-6067.66','389.969','393.292','0','0','0','100','0'),
('243317','24','-6067.61','386.918','393.6','0','0','0','100','0'),
('243317','25','-6067.57','384.741','393.6','0','0','0','100','0'),
('243317','26','-6070.1','384.163','393.603','0','0','0','100','0'),
('243317','27','-6080.55','383.916','393.599','0','0','0','100','0'),
('243317','28','-6080.56','386.59','393.599','0','0','0','100','0'),
('243317','29','-6080.58','389.173','393.599','0','0','0','100','0'),
('243317','30','-6082.29','391.723','393.599','0','0','0','100','0'),
('243317','31','-6083.02','392.815','394.001','0','0','0','100','0'),
('243317','32','-6084','394.261','394.38','0','0','0','100','0'),
('243317','33','-6085.22','396.085','394.854','0','0','0','100','0'),
('243317','34','-6087.08','397.944','395.266','0','0','0','100','0'),
('243317','35','-6088.6','399.471','395.543','0','0','0','100','0'),
('243317','36','-6091.24','399.4','395.541','0','0','0','100','0'),
('243317','37','-6094.53','397.869','395.541','0','0','0','100','0'),
('243317','38','-6097.73','396.216','395.541','0','0','0','100','0'),
('243317','39','-6095.54','394.8','395.541','0','0','0','100','0'),
('243317','40','-6090.78','391.728','395.541','0','0','0','100','0'),
('243317','41','-6088.22','390.076','395.541','0','0','0','100','0'),
('243317','42','-6089.02','387.58','395.541','0','0','0','100','0'),
('243317','43','-6088.14','381.102','395.541','0','0','0','100','0'),
('243317','44','-6091.01','375.222','395.541','0','0','0','100','0'),
('243317','45','-6093.33','372.208','395.542','0','0','0','100','0'),
('243317','46','-6098.94','371.143','395.542','0','0','0','100','0'),
('243317','47','-6103.76','371.389','395.542','0','0','0','100','0'),
('243317','48','-6108.95','373.956','395.542','0','0','0','100','0'),
('243317','49','-6110.95','374.909','395.542','0','0','0','100','0'),
('243317','50','-6118.24','374.296','395.542','0','0','0','100','0'),
('243317','51','-6122.5','373.937','395.542','0','0','0','100','0'),
('243317','52','-6126','374.304','395.545','0','0','0','100','0'),
('243317','53','-6128.58','374.575','395.545','0','0','0','100','0'),
('243317','54','-6129.75','378.208','395.545','0','0','0','100','0'),
('243317','55','-6131.31','383.081','395.545','0','0','0','100','0'),
('243317','56','-6134.82','383.349','395.545','0','0','0','100','0'),
('243317','57','-6136.49','383.811','395.545','0','0','0','100','0'),
('243317','58','-6142.53','384.253','395.544','0','0','0','100','0'),
('243317','59','-6136.28','384.013','395.544','0','0','0','100','0'),
('243317','60','-6131.43','383.826','395.544','0','0','0','100','0'),
('243317','61','-6128.49','376.514','395.545','0','0','0','100','0'),
('243317','62','-6126.14','375.466','395.545','0','0','0','100','0'),
('243317','63','-6120.48','375.284','395.544','0','0','0','100','0'),
('243317','64','-6116.11','375.143','395.544','0','0','0','100','0'),
('243317','65','-6114.36','373.876','395.544','0','0','0','100','0'),
('243317','66','-6110.01','373.709','395.544','0','0','0','100','0'),
('243317','67','-6106.08','373.557','395.544','0','0','0','100','0'),
('243317','68','-6102.54','369.767','395.544','0','0','0','100','0'),
('243317','69','-6099.62','366.633','395.54','0','0','0','100','0'),
('243317','70','-6095.32','367.339','395.54','0','0','0','100','0'),
('243317','71','-6092.74','367.763','395.54','0','0','0','100','0'),
('243317','72','-6093.51','369.806','395.54','0','0','0','100','0'),
('243317','73','-6090.18','374.501','395.542','0','0','0','100','0'),
('243317','74','-6087.11','379.285','395.542','0','0','0','100','0'),
('243317','75','-6087.51','384.499','395.542','0','0','0','100','0'),
('243317','76','-6089.04','389.944','395.542','0','0','0','100','0'),
('243317','77','-6093.1','395.098','395.542','0','0','0','100','0'),
('243317','78','-6094.71','397.155','395.54','0','0','0','100','0'),
('243317','79','-6091.7','400.806','395.54','0','0','0','100','0'),
('243317','80','-6089.77','399.809','395.541','0','0','0','100','0'),
('243317','81','-6087.47','398.622','395.377','0','0','0','100','0'),
('243317','82','-6084.89','395.6','394.732','0','0','0','100','0'),
('243317','83','-6082.64','392.951','393.985','0','0','0','100','0'),
('243317','84','-6079.82','389.636','393.599','0','0','0','100','0'),
('243317','85','-6079.3','385.291','393.599','0','0','0','100','0'),
('243317','86','-6073.86','383.737','393.599','0','0','0','100','0'),
('243317','87','-6068.62','384.373','393.601','0','0','0','100','0'),
('243317','88','-6068.29','388.693','393.601','0','0','0','100','0'),
('243317','89','-6068.05','391.757','392.763','0','0','0','100','0'),
('243317','90','-6064.27','393.045','392.762','0','0','0','100','0'),
('243317','91','-6061.7','393.383','392.762','0','0','0','100','0'),
('243317','92','-6060.39','391.115','392.762','0','0','0','100','0'),
('243317','93','-6061.29','387.725','392.762','0','0','0','100','0'),
('243317','94','-6061.95','376.875','392.762','0','0','0','100','0'),
('243317','95','-6061.55','373.898','392.762','0','0','0','100','0'),
('243317','96','-6061.5','373.475','393.216','0','0','0','100','0'),
('243317','97','-6061.32','372.185','393.597','0','0','0','100','0'),
('243317','98','-6059.61','370.229','393.597','0','0','0','100','0'),
('243317','99','-6057.88','370.101','393.597','0','0','0','100','0'),
('243317','100','-6057.02','370.037','394.15','0','0','0','100','0'),
('243317','101','-6056.24','369.979','394.67','0','0','0','100','0'),
('243317','102','-6055.38','369.915','395.242','0','0','0','100','0'),
('243317','103','-6052.38','369.693','395.264','0','0','0','100','0'),
('243317','104','-6052.06','372.701','395.264','0','0','0','100','0'),
('243317','105','-6052.18','374.011','396','0','0','0','100','0'),
('243317','106','-6052.29','375.315','396.868','0','0','0','100','0'),
('243317','107','-6052.21','376.193','397.453','0','0','0','100','0'),
('243317','108','-6052.08','377.503','398.326','0','0','0','100','0'),
('243317','109','-6052','378.374','398.874','0','0','0','100','0'),
('243317','110','-6052','380.713','398.874','0','0','0','100','0');

-- VISUAL: Coldridge Citizen wp taking from oficcial (http://www.wowhead.com/npc=853)
-- Creating addon for Coldridge Citizen
DELETE FROM `creature_addon` WHERE (`guid`=243814);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(243814, 243814, 0, 0, 1, 0, '');
-- Update creature Coldridge Citizenr form wp
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 243814;
-- WP for Coldridge Citizen raking WP from oficcial
DELETE FROM waypoint_data WHERE id='243814';
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
('243814','1','-6068.35','393.964','392.762','0','0','0','100','0'),
('243814','2','-6068.15','396.125','392.76','0','0','0','100','0'),
('243814','3','-6067.96','398.293','392.758','0','0','0','100','0'),
('243814','4','-6066.31','399.705','392.758','0','0','0','100','0'),
('243814','5','-6065','399.6','392.758','0','0','0','100','0'),
('243814','6','-6062.4','399.391','392.758','0','0','0','100','0'),
('243814','7','-6058.17','398.633','392.758','10000','0','0','100','0'),
('243814','8','-6058.17','398.633','392.758','1000','0','60003','100','0'),
('243814','9','-6060.3','398.906','392.758','0','0','0','100','0'),
('243814','10','-6061.06','399.336','392.758','0','0','0','100','0'),
('243814','11','-6064.48','399.783','392.758','0','0','0','100','0'),
('243814','12','-6067.52','399.597','392.758','0','0','0','100','0'),
('243814','13','-6067.98','396.558','392.758','0','0','0','100','0'),
('243814','14','-6068.37','393.962','392.76','0','0','0','100','0'),
('243814','15','-6068.21','390.508','392.762','0','0','0','100','0'),
('243814','16','-6068.19','390.067','393.227','0','0','0','100','0'),
('243814','17','-6068.13','388.76','393.6','0','0','0','100','0'),
('243814','18','-6068.03','386.592','393.6','0','0','0','100','0'),
('243814','19','-6070.13','385.023','393.603','0','0','0','100','0'),
('243814','20','-6073.15','384.847','393.599','0','0','0','100','0'),
('243814','21','-6075.82','386.386','393.599','0','0','0','100','0'),
('243814','22','-6079.11','389.259','393.599','0','0','0','100','0'),
('243814','23','-6079.54','384.892','393.599','0','0','0','100','0'),
('243814','24','-6080.24','377.891','393.599','0','0','0','100','0'),
('243814','25','-6080.41','376.143','393.599','0','0','0','100','0'),
('243814','26','-6081.77','375.033','393.913','0','0','0','100','0'),
('243814','27','-6083.49','372.961','394.492','0','0','0','100','0'),
('243814','28','-6086.08','370.601','395.09','0','0','0','100','0'),
('243814','29','-6088.03','368.824','395.509','0','0','0','100','0'),
('243814','30','-6092.38','368.183','395.542','0','0','0','100','0'),
('243814','31','-6096.72','367.545','395.54','0','0','0','100','0'),
('243814','32','-6098.67','365.772','395.54','0','0','0','100','0'),
('243814','33','-6100.6','364.023','395.539','10000','0','0','100','0'),
('243814','34','-6101.35','363.571','395.539','30000','0','60002','100','0'),
('243814','35','-6099.4','367.535','395.539','0','0','0','100','0'),
('243814','36','-6095.41','368.007','395.539','0','0','0','100','0'),
('243814','37','-6089.7','368.683','395.541','0','0','0','100','0'),
('243814','38','-6085.29','371.661','394.892','0','0','0','100','0'),
('243814','39','-6081.93','374.544','394.021','0','0','0','100','0'),
('243814','40','-6080.29','375.944','393.598','0','0','0','100','0'),
('243814','41','-6078.72','379.094','393.599','0','0','0','100','0'),
('243814','42','-6076.77','382.995','393.599','0','0','0','100','0'),
('243814','43','-6070.25','383.808','393.604','0','0','0','100','0'),
('243814','44','-6069.3','387.633','393.604','0','0','0','100','0'),
('243814','45','-6068.88','389.332','393.598','0','0','0','100','0'),
('243814','46','-6068.41','393.643','392.761','0','0','0','100','0');

DELETE FROM waypoint_scripts WHERE id IN ('60002','60003');
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(60002,0,1,10,0,0,0,0,0,0,243814),
(60003,0,1,69,0,0,0,0,0,0,243815);

-- ----------------
-- QUEST
-- ----------------
-- Remove wrong flag for creature Rockjaw Invader (http://www.wowhead.com/npc=37070)
UPDATE `creature_template` SET `npcflag`='0' WHERE `entry`='37070';
-- Remove from questrelation creature Rockjaw Invader (http://www.wowhead.com/npc=37070)
DELETE FROM `creature_questrelation` WHERE `quest`='24469' AND `id`='37070';

-- QUEST: Give 'em What-For Wrong prev quest (http://www.wowhead.com/quest=24470)
UPDATE `quest_template` SET `PrevQuestId`='24470' WHERE `entry`='24473';

-- QUEST: PrevQuest for Aid for the Wounded Taking from official (http://www.wowhead.com/quest=24471)
UPDATE `quest_template` SET `PrevQuestId`='24469' WHERE `entry`='24471';

-- QUEST: PrevQuest for Lockdown in Anvilmar Taking from official (http://www.wowhead.com/quest=24473)
UPDATE `quest_template` SET `PrevQuestId`='24471', `nextquestid`='24474' WHERE `entry`='24473';

-- QUEST: PrevQuest for Dwarven Artifacts Taking from official (http://www.wowhead.com/quest=24477)
UPDATE `quest_template` SET `PrevQuestId`='24473' WHERE `entry`='24477';

-- QUEST: Wrong quest giver for Etched Rune (http://www.wowhead.com/quest=3108)
DELETE FROM `creature_questrelation`  WHERE `quest`='3108' AND id='658';

-- QUEST: Etched Rune Is for Dwarf race not for hordes races (http://www.wowhead.com/quest=3108)
UPDATE `quest_template` SET `RequiredRaces`='4' WHERE `entry`='3108';

-- QUEST: Encrypted Rune Is for Dwarf race not for hordes races (http://www.wowhead.com/quest=3109)
UPDATE `quest_template` SET `RequiredRaces`='4' WHERE `entry`='3109';

-- QUEST: Empowered Rune Is for Dwarf race not for hordes races (http://www.wowhead.com/quest=24494)
UPDATE `quest_template` SET `RequiredRaces`='4' WHERE `entry`='24494';

-- QUEST: Tainted Rune Is for Dwarf race not for hordes races (http://www.wowhead.com/quest=3115)
UPDATE `quest_template` SET `RequiredRaces`='4' WHERE `entry`='3115';

-- QUEST: Consecrated Rune Is for Dwarf race not for hordes races (http://www.wowhead.com/quest=3107)
UPDATE `quest_template` SET `RequiredRaces`='4' WHERE `entry`='3107';

-- QUEST: Arcane Rune Is for Dwarf race not for hordes races (http://www.wowhead.com/quest=24496)
UPDATE `quest_template` SET `RequiredRaces`='4' WHERE `entry`='24496';

-- QUEST: Simple Rune Is for Dwarf race not for hordes races (http://www.wowhead.com/quest=3106)
UPDATE `quest_template` SET `RequiredRaces`='4' WHERE `entry`='3106';

-- QUEST: Make Hay While the Sun Shines next quest Whitebeard Needs Ye (http://es.wowhead.com/quest=24486)
UPDATE `quest_template` SET `NextQuestId`='24487' WHERE `entry`='24486';

-- QUEST: The Power of the Light Is for Dwarf race not for Orcs (http://www.wowhead.com/quest=24528)
UPDATE `quest_template` SET `RequiredRaces`='4' WHERE `entry`='24528';

-- QUEST: PrevQuest for Trolling for Information Taking from official (http://www.wowhead.com/quest=24489)
UPDATE `quest_template` SET `PrevQuestId`='24487' WHERE `entry`='24489';

-- QUEST: PrevQuest for A Refugee's Quandary Taking from official (http://www.wowhead.com/quest=3361)
UPDATE `quest_template` SET `PrevQuestId`='24487' WHERE `entry`='3361';

-- QUEST: PrevQuest for Ice and Fire Taking from official (http://www.wowhead.com/quest=218)
UPDATE `quest_template` SET `PrevQuestId`='24487' WHERE `entry`='218';

-- QUEST: NextQuest for A Trip to Ironforge Taking from official (http://www.wowhead.com/quest=24490)
UPDATE `quest_template` SET `NextQuestId`='24491' WHERE `entry`='24490';

-- OBJECT: Beer Barrel (http://www.wowhead.com/object=201706) For quest Pack Your Bags
DELETE FROM `gameobject` WHERE `id`=201706;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(2, 201706, 0, 1, 1, -6068.73, 400.01, 392.757, 5.33838, 0, 0, 0.455026, -0.890478, 300, 0, 1);

-- OBJECT: Wolf-Hide Cloaks (http://www.wowhead.com/object=201706) For quest Pack Your Bags
DELETE FROM `gameobject` WHERE `id`=201705;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(3, 201705, 0, 1, 1, -6047.67, 384.772, 398.876, 3.4228, 0, 0, 0.990132, -0.140141, 300, 0, 1);

-- OBJECT: Leftover Boar Meat (http://www.wowhead.com/object=201706) For quest Pack Your Bags
DELETE FROM `gameobject` WHERE `id`=201704;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(4, 201704, 0, 1, 1, -6096.96, 404.515, 396.412, 3.95058, 0, 0, 0.919302, -0.393553, 300, 0, 1);

-- QUEST: PrevQuest for Don't Forget About Us Taking from official (http://www.wowhead.com/quest=24493)
UPDATE `quest_template` SET `PrevQuestId`='24492' WHERE `entry`='24493';

-- QUEST: Save Krennan Aranas Fix quest (http://www.wowhead.com/quet=14293)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='14293';

-- QUEST: Immolate Fix quest (http://www.wowhead.com/quet=14274)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='14274';

-- QUEST: Flash Heal Fix quest (http://www.wowhead.com/quet=14279)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='2' WHERE `entry`='14279';

-- QUEST: Charge Fix quest (http://www.wowhead.com/quet=14266)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='14266';

-- QUEST: Eviscerate Fix quest (http://www.wowhead.com/quet=14272)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='14272';

-- QUEST: Sacrifices Fix quest (http://www.wowhead.com/quet=14212)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='30' WHERE `entry`='14212';

-- QUEST: Nibbler! No! Fix quest (http://www.wowhead.com/quet=25158)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`='52086' WHERE `entry`='25158';

-- QUEST:A Present for Lila Fix quest (http://www.wowhead.com/quet=25160)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`='0', `ReqCreatureOrGOCount1`='0', `ReqItemId1`='52098', `ReqItemCount1`='2', `ReqItemId2`='0', `ReqItemCount2`='0' WHERE `entry`='25160';

-- QUEST: Ogrezonians in the Mood Fix quest (http://www.wowhead.com/quet=25161)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`='0', `ReqCreatureOrGOCount1`='0', `ReqItemId1`='52121', `ReqItemCount1`='2', `ReqItemId2`='0', `ReqItemCount2`='0' WHERE `entry`='25161';

-- QUEST: Firebeard Bellows Fix quest (http://www.wowhead.com/quet=27809)
UPDATE `quest_template` SET `NextQuestId`='27810' WHERE `entry`='27809';

-- QUEST: Steady Shot Fix quest (http://www.wowhead.com/quet=14276)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='2' WHERE `entry`='14276';

-- QUEST: The Troll Menace remove wrong quest giver The Troll Menace
DELETE FROM `creature_questrelation` WHERE `quest` IN (182) AND `id`='706';

-- ------
-- SAI
-- ------
-- SAI: Jona Ironstock taking data from oficcial
SET @ENTRY := 37087;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,1,0,6000,7000,65000,850000,1,0,500,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Jona Ironstock - Talk");

-- type es el tipo de mensaje que dice
DELETE FROM `creature_text`WHERE `entry` IN ('37087'); 
INSERT INTO `creature_text` VALUES
('37087','0','0','Let\'s keep this fire going, dwarves!','0','0','1','0','0','0','Jona Ironstock - Text 1'),
('37087','0','1','What\'s Joren doin\' out there, anyhow?','0','0','1','0','0','0','Jona Ironstock - Text 2'),
('37087','0','2','Don\'t fret, we\'ll be outta here soon.','0','0','1','0','0','0','Jona Ironstock - Text 3'),
('37087','0','3','Get ta work, boys!','0','0','1','0','0','0','Jona Ironstock - Text 4');

-- SAI: Wayward Fire Elemental (http://www.wowhead.com/npc=37112)
SET @ENTRY := 37112;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,1,0,6000,7000,65000,850000,1,0,1900,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"TEXT - OOC Text "),
(@ENTRY,@SOURCETYPE,1,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"TEXT - On Aggro"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,4000,14000,38000,42000,11,69608,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast - Fireball");

-- Text for Wayward Fire Elemental
DELETE FROM `creature_text`WHERE `entry` IN ('37112'); 
INSERT INTO `creature_text` VALUES
('37112','0','0','Torin Kir talsa Krast\'ven!','1','0','1','0','0','0','OCC Text for Wayward Fire Elemental'),
('37112','1','0','TORIN KIR TALSA KRAST\'VEN','0','0','1','0','0','0','Aggro Text for Wayward Fire Elemental');

-- SAI: Grik'nir the Cold (http://www.wowhead.com/npc=808)
SET @ENTRY := 808;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Text - On aggro for Grik'nir the Cold"),
(@ENTRY,@SOURCETYPE,1,0,4,0,100,0,0,0,1,1,11,6957,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"ON agrro - Cast Frostmane Strength"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,4000,14000,38000,42000,11,79895,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"On combat - Frost Strike");

--  Text for Grik'nir the Cold 
DELETE FROM `creature_text`WHERE `entry` IN ('808'); 
INSERT INTO `creature_text` VALUES
('808','0','0','First da fire, and now da $R! You gonna die!','0','0','1','0','0','0','OCC Text for Grik\'nir the Cold');

-- SAI: Wounded Coldridge Mountaineer (http://www.wowhead.com/npc=37080)
SET @ENTRY := 37080;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,8,0,100,0,69855,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Remove addon - Wounded Coldridge Mountaineer"),
(@ENTRY,@SOURCETYPE,1,0,8,0,100,0,69855,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Radom text for - Wounded Coldridge Mountaineer"),
(@ENTRY,@SOURCETYPE,2,0,8,0,100,0,69855,0,0,0,46,15,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Run away - Wounded Coldridge Mountaineer"),
(@ENTRY,@SOURCETYPE,3,0,52,0,100,0,0,37080,0,0,41,10000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Force  despawn - Wounded Coldridge Mountaineer");

--  Text for Wounded Coldridge Mountaineer
DELETE FROM `creature_text`WHERE `entry` IN ('37080'); 
INSERT INTO `creature_text` VALUES
('37080','0','0','Yer a lifesaver! For Ironforge!','0','0','1','0','0','0','Text 1 - Wounded Coldridge Mountaineer'),
('37080','0','1','Thanks! I can make it from here.','0','0','1','0','0','0','Text 2 - Wounded Coldridge Mountaineer'),
('37080','0','2','Ahh, much better. I owe ya one.','0','0','1','0','0','0','Text 3 - Wounded Coldridge Mountaineer');

-- SAI: Rockjaw Goon (http://www.wowhead.com/npc=37073)
SET @ENTRY := 37073;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Ramdom text - Rockjaw Goon"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,4000,14000,38000,42000,11,69851,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Club - Rockjaw Goon");

--  Text for Rockjaw Goon
DELETE FROM `creature_text`WHERE `entry` IN ('37073'); 
INSERT INTO `creature_text` VALUES
('37073','0','0','You break our cave, I break your skull!','0','0','1','0','0','0','Text 1 - Rockjaw Goon'),
('37073','0','1','Why you break our home?!','0','0','1','0','0','0','Text 2 - Rockjaw Goon');

-- SAI: Small Crag Boar (http://www.wowhead.com/npc=708)
SET @ENTRY := 708;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,4,0,100,0,1,14000,38000,42000,11,44530,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Boar Charge - Small Crag Boar");

-- SAI: Rockjaw Scavenger (http://www.wowhead.com/npc=37105)
SET @ENTRY := 37105;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,4,0,100,0,0,15,0,0,11,69897,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Throw Priceless Artifact - Rockjaw Scavenger");

