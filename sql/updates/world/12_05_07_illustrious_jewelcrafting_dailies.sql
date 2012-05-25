-- Fix for Jewelcrafting daily quests in Stormwind/Orgrimmar

-- Quests are available only from 475 skill upwards (before this, any player with or without Jewelcrafting was able to accept them).
UPDATE quest_template SET RequiredSkillValue = 475 WHERE entry IN (25154, 25160, 25156, 25162, 25105, 25158, 25155, 25161, 25157, 25159);

-- Pooling for Stormwind dailies.
DELETE FROM pool_quest WHERE pool_entry = 523;
INSERT INTO pool_quest VALUES
(25105, 523, "Stormwind Jewelcrafting quests"),
(25154, 523, "Stormwind Jewelcrafting quests"),
(25155, 523, "Stormwind Jewelcrafting quests"),
(25156, 523, "Stormwind Jewelcrafting quests"),
(25157, 523, "Stormwind Jewelcrafting quests");

-- Pooling for Orgrimmar dailies.
DELETE FROM pool_quest WHERE pool_entry = 524;
INSERT INTO pool_quest VALUES
(25158, 524, "Orgrimmar Jewelcrafting quests"),
(25159, 524, "Orgrimmar Jewelcrafting quests"),
(25160, 524, "Orgrimmar Jewelcrafting quests"),
(25161, 524, "Orgrimmar Jewelcrafting quests"),
(25162, 524, "Orgrimmar Jewelcrafting quests");