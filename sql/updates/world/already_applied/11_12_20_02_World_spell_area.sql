-- DB/SPELL AREAS: Fixx al erros on spell area
-- SPELL AREA: Deleting double spell area
DELETE FROM `spell_area` WHERE `spell`='35481' AND `area`='4100' AND `racemask`='690';
DELETE FROM `spell_area` WHERE `spell`='35480' AND `AREA`='4100' AND `racemask`='690';

-- SPELL AREA: Survey Alcaz Island Deleting area for this old quest (http://www.wowhead.com/quest=11142)
DELETE FROM `spell_area` WHERE `quest_start`='11142';