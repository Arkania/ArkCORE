-- Nibbler!  No!
-- By Mikadmin [www.wow-attitude.com]
-- Fix wrong data

UPDATE `quest_template` SET `ReqCreatureOrGOId1` = 0, `ReqCreatureOrGOCount1` = 0 WHERE `entry` = 25158;