-- creature_template
-- By Mikadmin For ARKania
-- Fix error consol

-- Error: Table 'skinning_loot_template' entry 721 (creature skinning id) not exist but used as loot id in DB.
UPDATE `creature_template` SET `skinloot` = '0' WHERE `creature_template`.`entry` =722;