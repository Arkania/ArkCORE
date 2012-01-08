-- Deathbringer's Cache Fix loot id (http://www.wowhead.com/object=202239)
UPDATE `gameobject_template` SET data1='202240' WHERE `entry`='202240';
DELETE FROM `gameobject_loot_template` WHERE (`entry`=202240);
INSERT INTO `gameobject_loot_template` VALUES 
(202240, 49908, 10, 1, 0, 1, 1),
(202240, 50014, 0, 1, 1, 1, 1),
(202240, 50015, 0, 1, 1, 1, 1),
(202240, 50274, 37.5, 1, 0, 1, 1),
(202240, 50333, 0, 1, 1, 1, 1),
(202240, 50362, 0, 1, 1, 1, 1),
(202240, 50412, 0, 1, 1, 1, 1),
(202240, 52025, 100, 1, 0, -52025, 2);

-- Unuset loot is controlling by other loot
DELETE FROM gameobject_loot_template WHERE entry='1685';
-- Marshal Haggard's Chest Fix loot id (http://www.wowhead.com/object=1562)
DELETE FROM `gameobject_loot_template` WHERE (`entry`=1562);
INSERT INTO `gameobject_loot_template` VALUES 
(1562, 921, -100, 1, 0, 1, 1); -- Negative value when is a quest item

-- Unuset loot is controlling by other loot
DELETE FROM gameobject_loot_template WHERE entry='24556';

-- Ice Chest Fix loot id (http://www.wowhead.com/object=187892)
UPDATE `gameobject_template` SET data1='187892' WHERE `entry`='187892';
DELETE FROM `gameobject_loot_template` WHERE `entry` IN ('187892','43761');
INSERT INTO `gameobject_loot_template` VALUES
('187892','35498','3','1','0','1','1'),
('187892','35557','28','1','0','1','2'),
('187892','35720','3','1','0','5','6'),
('187892','35723','12','1','0','1','1'),
('187892','54801','0','1','1','1','1'),
('187892','54802','0','1','1','1','1'),
('187892','54803','0','1','1','1','1'),
('187892','54804','0','1','1','1','1'),
('187892','54805','0','1','1','1','1');

-- Sunken Cargo Fix loot id (http://www.wowhead.com/object=202745)
UPDATE `gameobject_template` SET data1='202745' WHERE `entry`='202745';
DELETE FROM `gameobject_loot_template` WHERE (`entry`=202745);
INSERT INTO `gameobject_loot_template` VALUES 
(202745, 52973, -100, 0, 0, 1, 1); -- Negative value when is a quest item

-- Stormwind Spear Fix loot id (http://www.wowhead.com/object=203014)
UPDATE `gameobject_template` SET data1='203014' WHERE `entry`='203014';
DELETE FROM `gameobject_loot_template` WHERE (`entry`=203014);
INSERT INTO `gameobject_loot_template` VALUES 
(203014, 54958, -100, 0, 0, 1, 1); -- Negative value when is a quest item

-- Stormwind Locker Fix loot id (http://www.wowhead.com/object=203061)
UPDATE `gameobject_template` SET data1='203061' WHERE `entry`='203061';
DELETE FROM `gameobject_loot_template` WHERE (`entry`=203061);
INSERT INTO `gameobject_loot_template` VALUES 
(203061, 54957, -100, 0, 0, 1, 2); -- Negative value when is a quest item

-- Fireplume Shroom Fix loot id (http://www.wowhead.com/object=203453)
UPDATE `gameobject_template` SET data1='203453' WHERE `entry`='203453';
DELETE FROM `gameobject_loot_template` WHERE (`entry`=203453);
INSERT INTO `gameobject_loot_template` VALUES 
(203453, 56810, -100, 0, 0, 1, 1); -- Negative value when is a quest item