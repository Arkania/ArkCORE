-- HACKY! faction flightmaster was aggressive with 72 (stormwind) wtf?
UPDATE  `creature_template` SET  `faction_A` =  '35', `faction_H` =  '35' WHERE  `creature_template`.`entry` =42406 LIMIT 1 ;


-- lets turn in feast or famine 26230
DELETE FROM `creature_involvedrelation` WHERE `quest` = 26230;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('42497', '26230');
