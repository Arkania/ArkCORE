-- Fix error on SQLDriver.log & DBErrors.log
-- By Mikadmin For ARKania
-- For ArkCORE (last-commit) & ArkDB 3.7.0
-- ERROR: [1054] Unknown column 'entry' in 'field list'
-- >> Loaded 0 LoadVehicleAccessor. DB table `vehicle_accessory` is empty.

ALTER TABLE `vehicle_accessory` CHANGE `guid` `entry` MEDIUMINT( 8 ) UNSIGNED NOT NULL DEFAULT '0'