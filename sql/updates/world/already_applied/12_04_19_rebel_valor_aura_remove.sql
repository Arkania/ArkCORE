-- Removes aura Rebel Valor (www.wowhead.com/spell=67503) when turning in quest The Rebel Lord's Arsenal (http://www.wowhead.com/quest=14159).

UPDATE `quest_template` SET `CompleteScript`=14159 WHERE `entry`=14159;
DELETE FROM `quest_end_scripts` WHERE `id`=14159;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`) VALUES (14159, 0, 14, 67503, 0);