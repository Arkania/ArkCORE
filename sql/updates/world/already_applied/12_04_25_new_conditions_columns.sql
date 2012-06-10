-- add column SourceId
ALTER TABLE `conditions` ADD COLUMN `SourceId` INT(10) NOT NULL DEFAULT '0' AFTER SourceEntry;
ALTER TABLE `conditions` DROP PRIMARY KEY,
    ADD PRIMARY KEY (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`);

-- add column NegativeValue
ALTER TABLE `conditions` ADD COLUMN `NegativeValue` tinyint(3) UNSIGNED NOT NULL default '0' AFTER `ConditionValue3`;