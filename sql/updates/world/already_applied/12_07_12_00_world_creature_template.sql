-- Npcflag
-- By Mikadmin For ARKania
-- Fix Error Consol : Creature (Entry: xxxxx) has different `npcflag` in difficulty 1 mode (Entry: xxxxx).

UPDATE `creature_template` SET `npcflag` = '2' WHERE `creature_template`.`entry` =49648;
UPDATE `creature_template` SET `npcflag` = '2' WHERE `creature_template`.`entry` =46613;
UPDATE `creature_template` SET `npcflag` = '2' WHERE `creature_template`.`entry` =48936;
UPDATE `creature_template` SET `npcflag` = '2' WHERE `creature_template`.`entry` =48940;
UPDATE `creature_template` SET `npcflag` = '2' WHERE `creature_template`.`entry` =48944;
