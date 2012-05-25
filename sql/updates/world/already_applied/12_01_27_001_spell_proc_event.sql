DELETE FROM `spell_proc_event` WHERE `entry` IN (51525, 51526, 51527);
INSERT INTO `spell_proc_event` (`entry`, `SpellFamilyName`, `SpellFamilyMask1`, `SpellFamilyMask2`) VALUES 
(51525, 11, 16777232, 131076), -- Static Shock (Rank 1)
(51526, 11, 16777232, 131076), -- Static Shock (Rank 2)
(51527, 11, 16777232, 131076); -- Static Shock (Rank 3)
