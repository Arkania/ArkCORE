ALTER TABLE `characters`
ADD COLUMN `guildId` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `petSlotUsed`;
