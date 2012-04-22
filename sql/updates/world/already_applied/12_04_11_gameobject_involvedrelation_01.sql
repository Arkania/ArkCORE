-- The Sentinel's Pawn
-- By mikadmin for arkania
-- Fix gameobject_involvedrelation

DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 27797;
INSERT INTO `gameobject_involvedrelation` (`id`, `quest`) VALUES (206336, 27797);

DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 27884;
INSERT INTO `gameobject_involvedrelation` (`id`, `quest`) VALUES (206336, 27884);