DELETE FROM `spell_proc_event` WHERE entry IN (87099, 87100);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(87099, 0, 0, 0, 0, 1088, 0, 0, 0, 0, 0), -- Sin and Punishment (Rank 1)
(87100, 0, 0, 0, 0, 1088, 0, 0, 0, 0, 0); -- Sin and Punishment (Rank 2)
