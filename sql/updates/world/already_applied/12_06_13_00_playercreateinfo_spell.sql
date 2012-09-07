-- 79684 Offensive State (DND) for goblins and worgens
DELETE FROM `playercreateinfo_spell` WHERE `race` IN (9,22) AND `class` = 8 AND `Spell` = 79684;
INSERT INTO `playercreateinfo_spell` VALUES
(9,8,79684,'Mages - Offensive State (DND) - Enables Arcane Missiles'), -- Goblin
(22,8,79684,'Mages - Offensive State (DND) - Enables Arcane Missiles');-- Worgen
