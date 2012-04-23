-- Drake halfus
-- By Mikadmin For Arkania
-- Fix Wrong healt

-- 10/25 = 4.149.700
-- 10Hm = 5.809.580
-- 25Hm = 16.598.800

UPDATE `creature_template` SET `Health_mod` = '50' WHERE `creature_template`.`entry` =46218;
UPDATE `creature_template` SET `Health_mod` = '200' WHERE `creature_template`.`entry` =46220;
UPDATE `creature_template` SET `Health_mod` = '50' WHERE `creature_template`.`entry` =44652;
UPDATE `creature_template` SET `Health_mod` = '50' WHERE `creature_template`.`entry` =46215;
UPDATE `creature_template` SET `Health_mod` = '200' WHERE `creature_template`.`entry` =46217;
UPDATE `creature_template` SET `Health_mod` = '50' WHERE `creature_template`.`entry` =46212;
UPDATE `creature_template` SET `Health_mod` = '200' WHERE `creature_template`.`entry` =46214;
UPDATE `creature_template` SET `Health_mod` = '50' WHERE `creature_template`.`entry` =46221;
UPDATE `creature_template` SET `Health_mod` = '200' WHERE `creature_template`.`entry` =46223;

-- Orphaned Emerald Whelp
-- 10 = 414.970
-- 25 = 1.493.892
-- 10HM = 726.198
-- 25Hm = 2.334.206

UPDATE `creature_template` SET `Health_mod` = '5' WHERE `creature_template`.`entry` =44641;
UPDATE `creature_template` SET `Health_mod` = '18' WHERE `creature_template`.`entry` =46224;
UPDATE `creature_template` SET `Health_mod` = '8.75' WHERE `creature_template`.`entry` =46225;
UPDATE `creature_template` SET `Health_mod` = '28.125' WHERE `creature_template`.`entry` =46226;
