-- Fix error consol: empty npcflag
-- By Mikadmin For ARKania
-- add flag vendor

UPDATE `creature_template` SET `npcflag` = 128 WHERE `entry` = 8121;
UPDATE `creature_template` SET `npcflag` = 128 WHERE `entry` = 8122;
UPDATE `creature_template` SET `npcflag` = 128 WHERE `entry` = 24780;
UPDATE `creature_template` SET `npcflag` = 128 WHERE `entry` = 42497;