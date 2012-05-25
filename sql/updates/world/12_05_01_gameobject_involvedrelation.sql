-- Broken Prong
-- By Mikadmin for Arkania
-- Fix involvedrelation

DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 27394;
INSERT INTO `gameobject_involvedrelation` (`id`, `quest`) VALUES (203140, 27394);