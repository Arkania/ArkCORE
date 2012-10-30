-- Valiona text
-- By Mikadmin For Arkania

DELETE FROM `creature_text` WHERE `entry` = 45992;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(45992, 0, 0, 'Do as the master commands, Theralion! Kill them!', 14, 0, 0, 0, 0, 21894, 'VO_BT_Valiona_Event01'),
(45992, 1, 0, 'You are worthless, Theralion!', 14, 0, 0, 0, 0, 21895, 'VO_BT_Valiona_Event02'),
(45992, 2, 0, 'Breathe your dying breath!', 14, 0, 0, 0, 0, 21896, 'VO_BT_Valiona_Event03'),
(45992, 3, 0, 'At least... Theralion dies with me...', 14, 0, 0, 0, 0, 21897, 'VO_BT_Valiona_Event04'),
(45992, 4, 0, 'Theralion, I will engulf the hallway. Cover their escape!', 14, 0, 0, 0, 0, 21898, 'VO_BT_Valiona_Event05'),
(45992, 5, 0, 'Enter Twilight!', 14, 0, 0, 0, 0, 21899, 'VO_BT_Valiona_Event06');