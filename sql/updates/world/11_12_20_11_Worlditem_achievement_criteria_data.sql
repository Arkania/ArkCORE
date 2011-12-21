-- DB/ACHEVEMENT: Fix all errors with achievement criteria data
-- Deleting type 11, if type 11 this need a scriptname but is not present on core (meaby on Trillum?)
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (13610,13611,13609,13608,16499,13607,16498,16500,13984,16507,16502,16503);
-- Deleting no supporter achievement type 8
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (13598,13597,13596,13594,13595);
-- ACHIEVEMENT: Adding achievement criteria data creteria id 7703
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`='7703';
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
('7703','11','0','0','achievement_wg_didnt_stand_a_chance');
-- ACHIVEMENT: Not correct
DELETE FROM `achievement_reward` WHERE `entry` IN ('4785','4784');
