-- DB/ADDONS: Fix all erros on creature, if you delete a creature from world, please be sure you remove de addon aswell
-- PLEASE!!! If you delete any creature from map be sure you delete addons aswell
DELETE FROM `creature_addon` WHERE `guid` IN (126390,137753,137764,137765,137766,137767,203048,203051);
-- If not addons, field must be to be NULL
UPDATE `creature_addon` SET `auras`='' WHERE `guid`='305725';