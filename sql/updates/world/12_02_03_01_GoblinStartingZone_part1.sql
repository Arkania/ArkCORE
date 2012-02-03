-- Goblin Starting Zone
-- by Walkum for Arkcore

-- Part 1: Fixed order of quest sequence

-- Quest 25473 unleashed when 14069 and 14075 has been finished
UPDATE `quest_template` SET `ExclusiveGroup` = '-14069' WHERE `entry` = 14069;
UPDATE `quest_template` SET `ExclusiveGroup` = '-14069' WHERE `entry` = 14075;

-- Quest 25473 whith NextQuestInChain 28349
UPDATE `quest_template` SET `NextQuestInChain` = '28349' WHERE `entry` = 25473;

-- Quest 28349 whith NextQuestInChain 14071
UPDATE `quest_template` SET `NextQuestInChain` = '14071' WHERE `entry` = 28349;

-- Quest 14071 whith NextQuestInChain 24567
UPDATE `quest_template` SET `NextQuestInChain` = '24567' WHERE `entry` = 14071;

-- Quest 24567 whith NextQuestInChain 24488
UPDATE `quest_template` SET `NextQuestInChain` = '24488' WHERE `entry` = 24567;

-- Quest 24488 whith NextQuestInChain 24502
UPDATE `quest_template` SET `NextQuestInChain` = '24502' WHERE `entry` = 24488;

-- Quest 24502 whith NextQuestInChain 24503
UPDATE `quest_template` SET `NextQuestInChain` = '24503' WHERE `entry` = 24502;

-- Quest 24503 whith NextQuestInChain 24520
UPDATE `quest_template` SET `NextQuestInChain` = '24520' WHERE `entry` = 24503;

-- Quest 24520 whith NextQuestInChain 14070
UPDATE `quest_template` SET `NextQuestInChain` = '14070' WHERE `entry` = 24520;

-- Move RewSpellCast to RewSpellHiddenCast on quest 24520
UPDATE `quest_template` SET `RewSpellCast` = '0', `RewSpellHiddenCast` = '59073' WHERE `entry` = 24520;

-- Quest 28607 unleashed when 14071 has been finished
UPDATE `quest_template` SET `PrevQuestId` = '14071' WHERE `entry` = 28607;

-- Quest 28414 unleashed when 24502 has been finished
UPDATE `quest_template` SET `PrevQuestId` = '24502' WHERE `entry` = 28414;

-- Quest 14070 unleashed when 24520 has been finished
UPDATE `quest_template` SET `PrevQuestId` = '24520' WHERE `entry` = 14070;

-- Quests 26711 & 26712 when 24520 has been finished and added The new you NextQuestId
UPDATE `quest_template` SET `PrevQuestId` = '24520', `NextQuestId` = '14110' WHERE `entry` = 26711;
UPDATE `quest_template` SET `PrevQuestId` = '24520', `NextQuestId` = '14109' WHERE `entry` = 26712;

-- Class training quests unleashed when 24520 has been finished
UPDATE `quest_template` SET `PrevQuestId` = '24520' WHERE `entry` = 14007;
UPDATE `quest_template` SET `PrevQuestId` = '24520' WHERE `entry` = 14013;
UPDATE `quest_template` SET `PrevQuestId` = '24520' WHERE `entry` = 14012;
UPDATE `quest_template` SET `PrevQuestId` = '24520' WHERE `entry` = 14010;
UPDATE `quest_template` SET `PrevQuestId` = '24520' WHERE `entry` = 14009;
UPDATE `quest_template` SET `PrevQuestId` = '24520' WHERE `entry` = 14011;
UPDATE `quest_template` SET `PrevQuestId` = '24520' WHERE `entry` = 14008;

-- Quests 14110 & 14109 unleashed when 26711 has been finished
UPDATE `quest_template` SET `PrevQuestId` = '26711' WHERE `entry` = 14110;
UPDATE `quest_template` SET `PrevQuestId` = '26712' WHERE `entry` = 14109;

-- Quests 14153 & 14113 unleashed when 14110 or 14109 has been finished and added to NPCs 34668 and 35715
DELETE FROM `creature_questrelation` WHERE `quest` = 14153;
DELETE FROM `creature_questrelation` WHERE `quest` = 14113;
INSERT INTO `creature_questrelation` (`id`, `quest`)
VALUES
	(34668, 14153),
	(35175, 14153),
	(34668, 14113),
	(35175, 14113);
	
UPDATE `quest_template` SET `PrevQuestId` = '0' WHERE `entry` = 14115;
UPDATE `quest_template` SET `PrevQuestId` = '14110', `NextQuestId` = '14115', `ExclusiveGroup` = '14153', `NextQuestInChain` = '14115' WHERE `entry` = 14153;
UPDATE `quest_template` SET `PrevQuestId` = '14109', `NextQuestId` = '14115', `ExclusiveGroup` = '14153', `NextQuestInChain` = '14115' WHERE `entry` = 14113;

-- Much quests unleashed when 14122 has been finished
UPDATE `quest_template` SET `PrevQuestId` = '14122', `NextQuestId` = '14125', `ExclusiveGroup` = '-14121', `NextQuestInChain` = '14125'  WHERE `entry` = 14121;
UPDATE `quest_template` SET `PrevQuestId` = '14122', `NextQuestId` = '14125', `ExclusiveGroup` = '-14121', `NextQuestInChain` = '14125'  WHERE `entry` = 14123;
UPDATE `quest_template` SET `PrevQuestId` = '14122', `NextQuestId` = '14125', `ExclusiveGroup` = '-14121', `NextQuestInChain` = '14125'  WHERE `entry` = 14124;

-- Quest 14122 don't have the end spell 69010 of Kezan phase and CompleteScript 14122
UPDATE `quest_template` SET `RewSpellCast` = '0', `CompleteScript` = '14122' WHERE `entry` = 14122;

-- Quest 14125 with NextQuestId and added to NPC 34668
DELETE FROM `creature_questrelation` WHERE `quest` = 14125;
INSERT INTO `creature_questrelation` (`id`, `quest`)
VALUES
	(34668, 14125);
	
UPDATE `quest_template` SET `NextQuestId` = '14126' WHERE `entry` = 14125;
	
-- Quest 14126 with PrevQuestId, moved RewSpellCast to RewSpellHiddenCast, and added improved end script
DELETE FROM `creature_questrelation` WHERE `quest` = 14126;
INSERT INTO `creature_questrelation` (`id`, `quest`)
VALUES
	(34668, 14126);
	
UPDATE `quest_template` SET `PrevQuestId` = '14125', `RewSpellCast` = '0', `RewSpellHiddenCast` = '91847', `CompleteScript` = '14126' WHERE `entry` = 14126;
DELETE FROM `quest_end_scripts` WHERE `id` = 14122;
DELETE FROM `quest_end_scripts` WHERE `id` = 14126;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`)
VALUES
	(14126, 2, 6, 648, 0, 0, 533.77, 3274.62, 0.198194, 4.90527),
	(14126, 3, 34, 22, 0, 0, 0, 0, 0, 0),
	(14126, 30, 14, 69010, 0, 0, 0, 0, 0, 0);