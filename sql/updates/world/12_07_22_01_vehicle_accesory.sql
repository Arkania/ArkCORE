DROP TABLE `vehicle_accessory`;
RENAME TABLE `vehicle_template_accessory` TO `vehicle_accessory`;
ALTER TABLE `vehicle_accessory` 
	DROP COLUMN `summontype`, 
	DROP COLUMN `summontimer`;
