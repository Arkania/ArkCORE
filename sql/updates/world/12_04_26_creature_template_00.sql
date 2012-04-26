-- Corrupting Adherent
-- By Mikadmin for Arkania
-- Fix Damage

UPDATE `creature_template` SET `mindmg` = '1007',
`maxdmg` = '1354.7',
`attackpower` = '1571',
`dmg_multiplier` = '7.5',
`baseattacktime` = '2000' WHERE `creature_template`.`entry` =43622;

UPDATE `creature_template` SET `mindmg` = '1007',
`maxdmg` = '1354.7',
`attackpower` = '1571',
`dmg_multiplier` = '35',
`baseattacktime` = '2000' WHERE `creature_template`.`entry` =50184;

UPDATE `creature_template` SET `mindmg` = '1007',
`maxdmg` = '1354.7',
`attackpower` = '1571',
`dmg_multiplier` = '15',
`baseattacktime` = '2000' WHERE `creature_template`.`entry` =50185;

UPDATE `creature_template` SET `mindmg` = '1007',
`maxdmg` = '1354.7',
`attackpower` = '1571',
`dmg_multiplier` = '70',
`baseattacktime` = '2000' WHERE `creature_template`.`entry` =50186;