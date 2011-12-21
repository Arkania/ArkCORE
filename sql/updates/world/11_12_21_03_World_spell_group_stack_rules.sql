-- DB/SPELL GROUO: Fix all errors with spell group stack rules on start up
-- If not exist better remove it
DELETE FROM `spell_group_stack_rules` WHERE `group_id` IN ('1094');
DELETE FROM `spell_group_stack_rules` WHERE `stack_rule` IN ('3');