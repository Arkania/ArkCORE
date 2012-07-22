-- By Oracraft for ARKania
-- Revert for ArkCORE_Stable_4.0.6

ALTER TABLE `guild` 
	DROP COLUMN totalXP, 
	DROP COLUMN todayXP, 
	DROP COLUMN XPCap, 
	CHANGE `xp` `xp` bigint(20) unsigned NOT NULL, 
	CHANGE `level` `level` int(10) unsigned NOT NULL;


ALTER TABLE `characters` 
	ADD COLUMN `stable_slots` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `extra_flags`,
	ADD COLUMN `ammoId` int(10) unsigned NOT NULL DEFAULT '0' AFTER `equipmentCache`;


ALTER TABLE `characters`
	DROP COLUMN guildId;
