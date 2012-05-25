-- Malaise
-- By mikadmin For Arkania
-- Fix gameobject_involvedrelation

DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 10555;
INSERT INTO `gameobject_involvedrelation` (`id`, `quest`) VALUES (184825, 10555);