-- Arcane Missiles
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (79683,-79683,5143);
INSERT INTO `spell_linked_spell` VALUES 
(79683, 79808, 0, 'Arcane Missiles aurastate link'),
(-79683, -79808, 0, 'Arcane Missiles aurastate link'),
-- On retail, you lose the 79683 aura by just clicking on arcane missiles
(5143,-79683,0,'Arcane missiles! aura removal due to arcane missiles cast');