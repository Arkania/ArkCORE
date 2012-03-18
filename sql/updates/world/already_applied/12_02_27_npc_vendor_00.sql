-- Fix wrong guild page
-- By mikadmin for Arkania

UPDATE `npc_vendor` SET `item` = '65362' WHERE `npc_vendor`.`entry` =46572 AND `npc_vendor`.`item` =65361 AND `npc_vendor`.`ExtendedCost` =0;