-- Valiona & Theralion
-- By Mikadmin for Arkania
-- Fix wrong health

-- 10 = 25.767.600
-- 25 = 78.333.504
-- 10H = 48.099.520
-- 25H = 164.912.640

UPDATE `creature_template` SET `Health_mod` = '300' WHERE `creature_template`.`entry` = 45992;
UPDATE `creature_template` SET `Health_mod` = '912' WHERE `creature_template`.`entry` = 49897;
UPDATE `creature_template` SET `Health_mod` = '560' WHERE `creature_template`.`entry` = 49898;
UPDATE `creature_template` SET `Health_mod` = '1920' WHERE `creature_template`.`entry` = 49899;

UPDATE `creature_template` SET `Health_mod` = '300' WHERE `creature_template`.`entry` = 45993;
UPDATE `creature_template` SET `Health_mod` = '912' WHERE `creature_template`.`entry` = 49903;
UPDATE `creature_template` SET `Health_mod` = '560' WHERE `creature_template`.`entry` = 49904;
UPDATE `creature_template` SET `Health_mod` = '1920' WHERE `creature_template`.`entry` = 49905;