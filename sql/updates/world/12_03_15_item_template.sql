-- Fix disenchant item 
-- By Mikadmin for Arkania

SET @SKILL := 475;
SET @ITEM := 52722;
SET @ENTRY1 := 59326;
SET @ENTRY2 := 65053;
SET @ENTRY3 := 59516;
SET @ENTRY4 := 65108;
SET @ENTRY5 := 59514;
SET @ENTRY6 := 65110;
SET @ENTRY7 := 59349;
SET @ENTRY8 := 65034;
SET @ENTRY9 := 63534;
SET @ENTRY10 := 65093;
SET @ENTRY11 := 59472;
SET @ENTRY12 := 65141;
SET @ENTRY13 := 59510;
SET @ENTRY14 := 65114;
SET @ENTRY15 := 59343;
SET @ENTRY16 := 65039;
SET @ENTRY17 := 59350;
SET @ENTRY18 := 65033;
SET @ENTRY19 := 63540;
SET @ENTRY20 := 65004;
SET @ENTRY21 := 59490;
SET @ENTRY22 := 65129;
SET @ENTRY23 := 60201;
SET @ENTRY24 := 65100;
SET @ENTRY25 := 59476;
SET @ENTRY26 := 65137;
SET @ENTRY27 := 62386;
SET @ENTRY28 := 60253;
SET @ENTRY29 := 65238;
SET @ENTRY30 := 59482;
SET @ENTRY31 := 65135;
SET @ENTRY32 := 59217;
SET @ENTRY33 := 65079;
SET @ENTRY34 := 63498;
SET @ENTRY35 := 65376;
SET @ENTRY36 := 54504;
SET @ENTRY37 := 65066;
SET @ENTRY38 := 59312;

UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY1 WHERE `item_template`.`entry` =@ENTRY1;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY2 WHERE `item_template`.`entry` =@ENTRY2;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY3 WHERE `item_template`.`entry` =@ENTRY3;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY4 WHERE `item_template`.`entry` =@ENTRY4;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY5 WHERE `item_template`.`entry` =@ENTRY5;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY6 WHERE `item_template`.`entry` =@ENTRY6;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY7 WHERE `item_template`.`entry` =@ENTRY7;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY8 WHERE `item_template`.`entry` =@ENTRY8;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY9 WHERE `item_template`.`entry` =@ENTRY9;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY10 WHERE `item_template`.`entry` =@ENTRY10;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY11 WHERE `item_template`.`entry` =@ENTRY11;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY12 WHERE `item_template`.`entry` =@ENTRY12;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY13 WHERE `item_template`.`entry` =@ENTRY13;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY14 WHERE `item_template`.`entry` =@ENTRY14;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY15 WHERE `item_template`.`entry` =@ENTRY15;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY16 WHERE `item_template`.`entry` =@ENTRY16;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY17 WHERE `item_template`.`entry` =@ENTRY17;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY18 WHERE `item_template`.`entry` =@ENTRY18;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY19 WHERE `item_template`.`entry` =@ENTRY19;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY20 WHERE `item_template`.`entry` =@ENTRY20;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY21 WHERE `item_template`.`entry` =@ENTRY21;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY22 WHERE `item_template`.`entry` =@ENTRY22;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY23 WHERE `item_template`.`entry` =@ENTRY23;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY24 WHERE `item_template`.`entry` =@ENTRY24;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY25 WHERE `item_template`.`entry` =@ENTRY25;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY26 WHERE `item_template`.`entry` =@ENTRY26;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY27 WHERE `item_template`.`entry` =@ENTRY27;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY28 WHERE `item_template`.`entry` =@ENTRY28;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY29 WHERE `item_template`.`entry` =@ENTRY29;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY30 WHERE `item_template`.`entry` =@ENTRY30;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY31 WHERE `item_template`.`entry` =@ENTRY31;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY32 WHERE `item_template`.`entry` =@ENTRY32;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY33 WHERE `item_template`.`entry` =@ENTRY33;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY34 WHERE `item_template`.`entry` =@ENTRY34;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY35 WHERE `item_template`.`entry` =@ENTRY35;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY36 WHERE `item_template`.`entry` =@ENTRY36;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY37 WHERE `item_template`.`entry` =@ENTRY37;
UPDATE `item_template` SET `RequiredDisenchantSkill` = @SKILL,
`DisenchantID` = @ENTRY38 WHERE `item_template`.`entry` =@ENTRY38;


REPLACE INTO `disenchant_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(@ENTRY1, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY2, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY3, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY4, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY5, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY6, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY7, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY8, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY9, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY10, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY11, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY12, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY13, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY14, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY15, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY16, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY17, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY18, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY19, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY20, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY21, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY22, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY23, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY24, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY25, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY26, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY27, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY28, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY29, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY30, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY31, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY32, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY33, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY34, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY35, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY36, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY37, @ITEM, 100, 1, 0, 1, 2),
(@ENTRY38, @ITEM, 100, 1, 0, 1, 2);

