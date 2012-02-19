-- Fix Reins of Poseidus
-- By mikadmin for Arkania
-- Fix learn wrong spell http://www.wowhead.com/spell=98718

UPDATE `item_template` SET `spellid_2` = '98718' WHERE `item_template`.`entry` =67151;