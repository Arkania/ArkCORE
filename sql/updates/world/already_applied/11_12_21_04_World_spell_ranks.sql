-- DB/SPELL RANKS: Fix all errors with spell ranks on start up
-- Bear Form (Passive) rank 2 is not more need it on Cataclyms (http://www.wowhead.com/spell=1178)
-- When spell only have a rank don't need to be present on spell_ranks, so delted
DELETE FROM `spell_ranks` WHERE `first_spell_id` IN ('1178');