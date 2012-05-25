-- Cleanup for duplicate doors (Quest 14098 - Evacuate the Merchant Square)
DELETE FROM `gameobject` WHERE `guid` IN ('208580', '208577', '208579', '208575', '208578', '208569');

-- Move RewSpellCast to RewSpellHiddenCast to avoid showing phase spell (Quest 14098 - Evacuate the Merchant Square)
UPDATE `quest_template` SET `RewSpellCast`='0', `RewSpellHiddenCast`='59074' WHERE `entry`='14098';