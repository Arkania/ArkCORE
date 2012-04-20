-- Add cutscene on turn-in of quest Last Stand (14222).

DELETE FROM `quest_end_scripts` WHERE `id`=14222 AND `command`=34;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES ('14222','3','34','21','0','0','0','0','0','0');