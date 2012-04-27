-- Fix achievement To All the Squirrels Who Cared for Me (http://www.wowhead.com/achievement=5548)
-- By Nanaki for Arkania.

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (16226, 16225, 16224, 16223, 16222, 16221, 16220, 16219, 16218, 16217, 16216, 16215, 16214);

INSERT INTO achievement_criteria_data (`criteria_id`, `TYPE`, `value1`) VALUES 
(16214, 1, 49779), -- Alpine Chipmunk
(16216, 1, 50419), -- Grotto Vole
(16218, 1, 50496), -- Oasis Moth
(16220, 1, 48686), -- Rattlesnake
(16222, 1, 48848), -- Rockchewer Whelk
(16224, 1, 48802), -- Sea Cucumber
(16226, 1, 48683), -- Yellow-Bellied Marmot
(16215, 1, 48630), -- Baradin Fox Kit
(16217, 1, 48706), -- Highlands Turkey
(16219, 1, 50491), -- Mac Frog
(16221, 1, 50481), -- Rock Viper
(16223, 1, 47682), -- Sassy Cat
(16225, 1, 47667); -- Wharf Rat