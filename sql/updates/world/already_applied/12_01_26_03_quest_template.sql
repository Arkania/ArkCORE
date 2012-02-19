-- Move RewSpellCast to RewSpellHiddenCast : Quest 14159 - The Rebel Lord's Arsenal
UPDATE `quest_template` SET `RewSpellCast`='0', `RewSpellHiddenCast`='72872' WHERE `entry`='14159';

-- Move RewSpellCast to RewSpellHiddenCast : Quest 14204 - From the Shadows
UPDATE `quest_template` SET `RewSpellCast`='0', `RewSpellHiddenCast`='43511' WHERE `entry`='14204';

-- Move RewSpellCast to RewSpellHiddenCast : Quest 14293 - Save Krennan Aranas
UPDATE `quest_template` SET `RewSpellCast`='0', `RewSpellHiddenCast`='76642' WHERE `entry`='14293';

-- Move RewSpellCast to RewSpellHiddenCast : Quest 14221 - Never Surrender, Sometimes Retreat
UPDATE `quest_template` SET `RewSpellCast`='0', `RewSpellHiddenCast`='81040' WHERE `entry`='14221';

-- Move RewSpellCast to RewSpellHiddenCast : Quest 14222 - Last Stand
UPDATE `quest_template` SET `RewSpellCast`='0', `RewSpellHiddenCast`='1645' WHERE `entry`='14222';

-- Corrections to ReqCreatureOrGOCount1 : Quest 14222 - Last Stand
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='8' WHERE `entry`='14222';

-- Corrections to ReqCreatureOrGOCount1 : Quest 14218 - By Blood and Ash
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='80' WHERE `entry`='14218';