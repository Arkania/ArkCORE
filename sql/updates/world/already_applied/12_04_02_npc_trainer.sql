-- Control Demon
-- By Mikadmin For Arkania
-- Fix Learn Wrong spell

UPDATE `npc_trainer` SET `spell` = '93375' WHERE `npc_trainer`.`spell` =80388;