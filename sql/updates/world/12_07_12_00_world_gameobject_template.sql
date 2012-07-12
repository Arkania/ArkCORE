-- GAMEOBJECT_TYPE_QUESTGIVER
-- By Mikadmin for ARKania
-- Fix Consol error : Table `gameobject_questrelation` have data gameobject entry (xxxxx) for quest xxxxx, but GO is not GAMEOBJECT_TYPE_QUESTGIVER

UPDATE `gameobject_template` SET `type` = 2, `data1` = 0 WHERE `entry` = 161521;
UPDATE `gameobject_template` SET `type` = 2, `data1` = 0 WHERE `entry` = 161526;
UPDATE `gameobject_template` SET `type` = 2, `data1` = 0 WHERE `entry` = 190097;
UPDATE `gameobject_template` SET `type` = 2, `data1` = 0 WHERE `entry` = 190098;
