-- Fix error consol: invalid quest
-- By Mikadmin For ARKania
-- Deleted PrevQuestId

UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `entry` = 171;
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `entry` = 5502;

