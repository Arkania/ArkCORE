-- DB/VERSION: We miis db version field on version table, so this fix it
ALTER TABLE `version` ADD COLUMN `script_version` VARCHAR (360) AFTER `db_version`;
INSERT INTO `version`  (`db_version`) VALUES 
('ArkDB r2.3.0 CATA 4.0.6a 19 12 2011');