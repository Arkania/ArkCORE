-- Revert Sql_instance_template
-- By Mikadmin For ARKania

ALTER TABLE `instance_template` 
ADD COLUMN `startLocX` FLOAT NULL DEFAULT NULL AFTER `parent`,
ADD COLUMN `startLocY` FLOAT NULL DEFAULT NULL AFTER `startLocX`,
ADD COLUMN `startLocZ` FLOAT NULL DEFAULT NULL AFTER `startLocY`,
ADD COLUMN `startLocO` FLOAT NULL DEFAULT NULL AFTER `startLocZ`;
 