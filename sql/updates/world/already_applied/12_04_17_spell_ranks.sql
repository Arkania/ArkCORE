-- Properly implement rank of Lifeblood (Rank 8) (Herbalism perk).
-- Fixes weird graphical glitch with Professions tab when having Herbalism at 525 skill.
-- By Nanaki, for Arkania.

DELETE FROM `spell_ranks` WHERE `first_spell_id`=81708 AND `spell_id`=74497;
INSERT INTO spell_ranks (`first_spell_id`, `spell_id`, `rank`) VALUES (81708, 74497, 8);
