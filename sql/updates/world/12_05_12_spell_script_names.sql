-- Reimplement Kill Command.
-- By Nanaki for Arkania.

DELETE FROM `spell_script_names` WHERE `spell_id`=34026;
INSERT INTO `spell_script_names` VALUES (34026, "spell_hun_kill_command");