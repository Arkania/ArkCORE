-- Flamebreaker
-- By Mikadmin & Loonyx For Arkania
-- fix quest_template & creature_template

UPDATE `quest_template` SET `ReqCreatureOrGOId1` = '40080' WHERE `quest_template`.`entry` =25323;

UPDATE `creature_template` SET `minlevel` = '80',
`maxlevel` = '80',
`exp` = '3',
`faction_A` = '16',
`faction_H` = '16' WHERE `creature_template`.`entry` =40080;
