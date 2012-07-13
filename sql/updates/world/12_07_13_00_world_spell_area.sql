-- Fix error consol: Wrong Spell area
-- By Mikadmin For ARKania
-- spell 58730 remplaced by spell 91604

DELETE FROM `spell_area` WHERE `spell` = 58730 AND `area` = 4197;
DELETE FROM `spell_area` WHERE `spell` = 58730 AND `area` = 4538;
DELETE FROM `spell_area` WHERE `spell` = 58730 AND `area` = 4581;
DELETE FROM `spell_area` WHERE `spell` = 58730 AND `area` = 4582;
DELETE FROM `spell_area` WHERE `spell` = 58730 AND `area` = 4585;
DELETE FROM `spell_area` WHERE `spell` = 58730 AND `area` = 4612;

UPDATE `spell_area` SET `spell` = '91604' WHERE `spell` =58730 AND `area` =4576;
UPDATE `spell_area` SET `spell` = '91604' WHERE `spell` =58730 AND `area` =4578;
UPDATE `spell_area` SET `spell` = '91604' WHERE `spell` =58730 AND `area` =4584;
UPDATE `spell_area` SET `spell` = '91604' WHERE `spell` =58730 AND `area` =4611;