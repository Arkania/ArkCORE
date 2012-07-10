RENAME TABLE `vehicle_accessory` TO `vehicle_template_accessory`;

ALTER TABLE `vehicle_template_accessory` 
ADD COLUMN  `summontype` TINYINT(3) UNSIGNED NOT NULL DEFAULT 6 COMMENT 'see enum TempSummonType' AFTER `description`,
ADD COLUMN  `summontimer` INT(10) UNSIGNED NOT NULL DEFAULT 30000 COMMENT 'timer, only relevant for certain summontypes' AFTER `summontype``;