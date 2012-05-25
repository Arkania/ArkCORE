-- DB/SPELL GROUO: Fix all errors with spell group & spell bonus data on start up
-- If not exist better remove it (Remenber this is 4.0.6)
DELETE FROM `spell_group` WHERE `spell_id` IN ('51726','51734','51735','60431','60432');
DELETE FROM `spell_group` WHERE `spell_id` IN ('-1093','-2008','-1094');
DELETE FROM `spell_bonus_data` WHERE `entry` IN ('50294');