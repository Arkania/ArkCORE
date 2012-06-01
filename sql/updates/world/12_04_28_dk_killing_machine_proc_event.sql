-- Killing Machine (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51123);
INSERT INTO `spell_proc_event` VALUES (51123, 0x01, 0x0F, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0, 100, 10);

-- Killing Machine (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51127);
INSERT INTO `spell_proc_event` VALUES (51127, 0x01, 0x0F, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0, 100, 10);

-- Killing Machine (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry` IN (51128);
INSERT INTO `spell_proc_event` VALUES (51128, 0x01, 0x0F, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000000, 0, 100, 10);

