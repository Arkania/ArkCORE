-- Fix Smart script error on consol
-- By Mikadmin For ARKania

-- fix error : SmartAIMgr::LoadSmartAIFromDB: Creature guid (66975) does not exist, skipped loading.
DELETE FROM `smart_scripts` WHERE `entryorguid` = -66975;

-- fix error : SmartAIMgr: Entry 18402 SourceType 0 Event 4 Action 15 SpecialFlags for Quest entry 9973 does not include FLAGS_EXPLORATION_OR_EVENT(2), skipped.
UPDATE `quest_template` SET `SpecialFlags` = 2 WHERE `entry` = 9973;
