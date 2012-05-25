ALTER TABLE `characters`
	CHANGE COLUMN `petSlotUsed` `petSlotUsed` BIGINT(32) NULL DEFAULT NULL AFTER `currentPetSlot`;