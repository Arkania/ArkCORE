-- Fix achievement Cataclysmically Superior and Cataclysmically Epic.
-- By Nanaki for Arkania.

-- Cataclysmically Superior
UPDATE `achievement_criteria_data` SET `type`=19, `value1`=333, `value2`=3 WHERE `criteria_id` BETWEEN 15346 AND 15361;

-- Cataclysmically Epic
UPDATE `achievement_criteria_data` SET `type`=19, `value1`=359, `value2`=4 WHERE `criteria_id` BETWEEN 15330 AND 15345;