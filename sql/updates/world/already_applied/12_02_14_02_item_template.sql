-- Fix price item
-- By mikadmin for Arkania

UPDATE `item_template` SET `BuyPrice` = '5000',
`SellPrice` = '0' WHERE `item_template`.`entry` =46325;