-- Halfus Wyrmbreaker
-- By Mikadmin for Arkania
-- Fix Damage

UPDATE `creature_template` SET `mindmg` = '1225.5',
`maxdmg` = '1544.7',
`attackpower` = '1651',
`dmg_multiplier` = '7.5',
`baseattacktime` = '2000' WHERE `creature_template`.`entry` =44600;

UPDATE `creature_template` SET `mindmg` = '1225.5',
`maxdmg` = '1544.7',
`attackpower` = '1651',
`dmg_multiplier` = '35',
`baseattacktime` = '2000' WHERE `creature_template`.`entry` =46209;

UPDATE `creature_template` SET `mindmg` = '1225.5',
`maxdmg` = '1544.7',
`attackpower` = '1651',
`dmg_multiplier` = '15',
`baseattacktime` = '2000' WHERE `creature_template`.`entry` =46210;

UPDATE `creature_template` SET `mindmg` = '1225.5',
`maxdmg` = '1544.7',
`attackpower` = '1651',
`dmg_multiplier` = '70',
`baseattacktime` = '2000' WHERE `creature_template`.`entry` =46211;