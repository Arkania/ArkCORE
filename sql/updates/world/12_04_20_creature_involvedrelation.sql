-- Rocky Relations
-- By Mikadmin for Arkania
-- Fix involvedrelation

DELETE FROM `creature_involvedrelation` WHERE `quest` = 26328;
DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 26328;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (42467, 26328);