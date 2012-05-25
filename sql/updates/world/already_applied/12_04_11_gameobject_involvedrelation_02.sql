-- The Warden's Pawn
-- By mikadmin for arkania
-- Fix gameobject_involvedrelation

DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 27883;
INSERT INTO `gameobject_involvedrelation` (`id`, `quest`) VALUES (206335, 27883);

DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 27796;
INSERT INTO `gameobject_involvedrelation` (`id`, `quest`) VALUES (206335, 27796);