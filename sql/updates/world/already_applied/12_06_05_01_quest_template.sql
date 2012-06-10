-- This chain quest, that takes place in Elwynn Forest, should be available to Humans only.
-- By Nanaki for Arkania.

UPDATE `quest_template` SET `RequiredRaces`='1' WHERE `entry` IN ('26393', '26394', '26395', '26396');

