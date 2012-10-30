DELETE FROM `smart_scripts` WHERE `entryorguid`='44902' AND `source_type`='0';
INSERT INTO `smart_scripts` VALUES (44902, 0, 0, 1, 8, 0, 100, 1, 8070, 0, 0, 0, 33, 44902, 0, 0, 0, 0, 0, 17, 1, 10, 0, 0, 0, 0, 0, '');
INSERT INTO `smart_scripts` VALUES (44902, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 12000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='44902';
