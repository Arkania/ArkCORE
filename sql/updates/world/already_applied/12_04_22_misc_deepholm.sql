-- doomshroom shouldn't move
 UPDATE `creature` SET `spawndist` = 0 WHERE `id` = 43388;

-- decryption made easy alliance, accept worgens, set prevquest, not autocomplete

UPDATE `quest_template` SET `RequiredRaces` = 2098509 WHERE `entry` = 27040;
UPDATE `quest_template` SET `PrevQuestId` = 27004 WHERE `entry` = 27040;
UPDATE `quest_template` SET `QuestFlags` = 262280  WHERE `entry` = 27040;


-- decryption made easy horde, accept goblins, set prevquest, not autocomplete

UPDATE `quest_template` SET `RequiredRaces` = 946 WHERE `entry` = 27041;
UPDATE `quest_template` SET `PrevQuestId` = 27005 WHERE `entry` = 27041;
UPDATE `quest_template` SET `QuestFlags` = 262280  WHERE `entry` = 27041;


-- quest giver / taker, Diamant the Patient (42467)

UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` = 42467;

DELETE FROM `creature_questrelation` WHERE `id` = 42467;
INSERT INTO  `creature_questrelation` (`id` ,`quest`)VALUES ('42467',  '26869');
INSERT INTO  `creature_questrelation` (`id` ,`quest`)VALUES ('42467',  '26436');
INSERT INTO  `creature_questrelation` (`id` ,`quest`)VALUES ('42467',  '26376');
INSERT INTO  `creature_questrelation` (`id` ,`quest`)VALUES ('42467',  '26377');
INSERT INTO  `creature_questrelation` (`id` ,`quest`)VALUES ('42467',  '26426');

DELETE FROM `creature_involvedrelation` WHERE `id` = 42467; 
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('42467', '26328');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('42467', '26871');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('42467', '26376');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('42467', '26377');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('42467', '26426');


-- horde quests, lets make add goblins allowed to them
UPDATE `quest_template` SET `RequiredRaces` = 946 WHERE `RequiredRaces` = 690;


-- same for alliance with worgens
UPDATE `quest_template` SET `RequiredRaces` = 2098509 WHERE `RequiredRaces` = 1357;

