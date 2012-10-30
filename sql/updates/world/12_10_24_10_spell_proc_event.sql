DELETE FROM `spell_proc_event` WHERE `entry` IN (82898,82899);
INSERT INTO `spell_proc_event` (`entry`,`procFlags`,`Cooldown`) VALUES
(82898,0x8|0x20|0x80|0x200|0x20000,2), -- Rank 1
(82899,0x8|0x20|0x80|0x200|0x20000,2); -- Rank 2