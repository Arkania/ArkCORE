-- GAMEOBJECT_TYPE_QUESTGIVER
-- By Mikadmin for ARKania
-- Fix Consol error : Table `gameobject_questrelation` have data gameobject entry (xxxxx) for quest xxxxx, but GO is not GAMEOBJECT_TYPE_QUESTGIVER

DELETE FROM `gameobject_loot_template` WHERE (`entry`=161521);
DELETE FROM `gameobject_loot_template` WHERE (`entry`=161526);