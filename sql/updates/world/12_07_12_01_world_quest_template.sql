-- quest_template
-- By Mikadmin for ARKania
-- Fix Consol error : 

UPDATE `quest_template` SET `ReqCreatureOrGOId1` = 0 WHERE `entry` = 14293;
UPDATE `quest_template` SET `ReqSpellCast1` = 0 WHERE `entry` = 14276;
UPDATE `quest_template` SET `SpecialFlags` = 2 WHERE `entry` = 14154;
