-- Divine Storm
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 53385;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('53385','54171','0','Divine Storm');