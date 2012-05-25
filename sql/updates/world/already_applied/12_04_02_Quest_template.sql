-- Smoked Desert Dumplings
-- By Mikadmin For Arkania
-- Fix Usebugg

UPDATE `quest_template` SET `RequiredSkillValue` = '285' WHERE `quest_template`.`entry` =8307;
UPDATE `quest_template` SET `RequiredSkillValue` = '285',
`PrevQuestId` = '8307' WHERE `quest_template`.`entry` =8313;
UPDATE `quest_template` SET `RequiredSkillValue` = '285',
`PrevQuestId` = '8313' WHERE `quest_template`.`entry` =8317;