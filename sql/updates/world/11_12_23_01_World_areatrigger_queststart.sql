-- DB/AREATRIGGER QUESTSTART: Redona table (is empthy so is not a problem)
-- SQL: SELECT trigger_ID, quest_ID FROM areatrigger_queststart
-- ERROR: [1054] Unknown column 'trigger_ID' in 'field list'
DROP TABLE IF EXISTS `areatrigger_queststart`;
CREATE TABLE `areatrigger_queststart` (
 `trigger_ID` INT ,
 `quest_ID` INT 
);