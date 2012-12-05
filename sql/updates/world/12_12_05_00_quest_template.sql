-- more fix skettis
-- By Mikadmin For Arkania
-- Fix Terokk's Downfall suite

UPDATE `quest_template` SET `PrevQuestId` = 11021 WHERE `entry` = 11024;
UPDATE `quest_template` SET `PrevQuestId` = 11024, `NextQuestId` = 11056 WHERE `entry` = 11028;
UPDATE `quest_template` SET `PrevQuestId` = 11028 WHERE `entry` = 11056;
UPDATE `quest_template` SET `PrevQuestId` = 11056 WHERE `entry` = 11029;
UPDATE `quest_template` SET `PrevQuestId` = 11029 WHERE `entry` = 11885;
UPDATE `quest_template` SET `Method` = 2 WHERE `entry` = 11074;