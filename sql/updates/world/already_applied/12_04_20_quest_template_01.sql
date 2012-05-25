-- Fix for quest Charge (14266, for Worgen Warriors).

UPDATE `quest_template` SET `ReqCreatureOrGOId1`=35118, `ReqCreatureOrGOCount1`=1, `ReqSpellCast1`=100 WHERE `entry`=14266;