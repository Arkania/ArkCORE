-- Fix error consol
-- By Mikadmin For ARKania
-- Table `gameobject` have gameobject (GUID: 4024279 Entry: 207209) with invalid `state` (24) value, skip

UPDATE `gameobject` SET `state` = '1' WHERE `guid` =4024279;
