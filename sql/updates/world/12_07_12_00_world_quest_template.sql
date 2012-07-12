-- quest_template
-- By Mikadmin for ARKania
-- Fix Consol error : Quest [xxxx] has PrevQuestId [xxxx], but no such quest

-- This quest was marked obsolete by Blizzard and cannot be obtained or completed.
DELETE FROM `quest_template` WHERE (`entry`=558);
DELETE FROM `quest_template` WHERE (`entry`=915);
DELETE FROM `quest_template` WHERE (`entry`=925);