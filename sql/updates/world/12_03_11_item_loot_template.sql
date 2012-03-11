-- Big-Mouth Clam
-- By Mikadmin For Arkania
-- Fix Loot Item

DELETE FROM `item_loot_template` WHERE (`entry`=7973);
INSERT INTO `item_loot_template` VALUES 
(7973, 7974, 80, 1, 0, 1, 1),
(7973, 5498, 34, 1, 0, 1, 1),
(7973, 5500, 24, 1, 0, 1, 1),
(7973, 13926, 5, 1, 0, 1, 1),
(7973, 7971, 4, 1, 0, 1, 1);