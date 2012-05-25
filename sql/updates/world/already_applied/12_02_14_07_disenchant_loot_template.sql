-- Fix disenchant item
-- By Mikadmin For Arkania

SET @ENTRY := 67129;
SET @ENTRY1 := 65020;
SET @ENTRY2 := 59121;
SET @ENTRY3 := 59120;
SET @ITEM := 52172;

DELETE FROM `disenchant_loot_template` WHERE (`entry`=@ENTRY);
DELETE FROM `disenchant_loot_template` WHERE (`entry`=@ENTRY1);
DELETE FROM `disenchant_loot_template` WHERE (`entry`=@ENTRY2);
DELETE FROM `disenchant_loot_template` WHERE (`entry`=@ENTRY3);
INSERT INTO `disenchant_loot_template` VALUES 
(@ENTRY, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY1, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY2, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY3, @ITEM, 100, 1, 0, 1, 2);

UPDATE `item_template` SET `DisenchantID` = '67129' WHERE `item_template`.`entry` =67129;
UPDATE `item_template` SET `RequiredDisenchantSkill` = '475' WHERE `item_template`.`entry` =67129;
UPDATE `item_template` SET `DisenchantID` = '65020' WHERE `item_template`.`entry` =65020;
UPDATE `item_template` SET `RequiredDisenchantSkill` = '475' WHERE `item_template`.`entry` =65020;
UPDATE `item_template` SET `DisenchantID` = '59121' WHERE `item_template`.`entry` =59121;
UPDATE `item_template` SET `RequiredDisenchantSkill` = '475' WHERE `item_template`.`entry` =59121;
UPDATE `item_template` SET `DisenchantID` = '59120' WHERE `item_template`.`entry` =59120;
UPDATE `item_template` SET `RequiredDisenchantSkill` = '475' WHERE `item_template`.`entry` =59120;
