-- Use on TrinityCORE 3.3.5a characters database
-- STATUS: 50%


/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;

-- Clean old currencies, this broken pets bar
DELETE FROM `character_inventory` WHERE `slot` IN ('118','135');
DELETE FROM `item_instance` WHERE `itemEntry` IN (
49426, -- Emblem of Frost
47241, -- Emblem of Triumph
40752, -- Emblem of Heroism
40753, -- Emblem of Valor
45624, -- Emblem of Conquest
20559, -- Arathi Basin Mark of Honor
29024, -- Eye of the Storm Mark of Honor
20560, -- Alterac Valley Mark of Honor
20558, -- Warsong Gulch Mark of Honor
43228, -- Stone Keeper's Shard	
42425, -- Strand of the Ancients Mark of Honor
47395, -- Isle of Conquest Mark of Honor
43308, -- Old Honor Points
43307  -- Old Arena Points 
);


-- account_data
ALTER TABLE `account_data` 
	CHANGE accountId `account` int(10) unsigned   NOT NULL DEFAULT 0 first, 
	CHANGE `type` `type` tinyint(3) unsigned   NOT NULL DEFAULT 0 after `account`;


-- arena_team_stats
CREATE TABLE `arena_team_stats`(
	`arenateamid` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`rating` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`games` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`wins` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`played` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`wins2` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`rank` int(10) unsigned NOT NULL  DEFAULT 0 , 
	PRIMARY KEY (`arenateamid`) 
) ENGINE=InnoDB DEFAULT CHARSET='utf8';


-- auctionhousebot
CREATE TABLE `auctionhousebot`(
	`auctionhouse` int(11) NOT NULL  DEFAULT 0 COMMENT 'mapID of the auctionhouse.' , 
	`name` char(25) COLLATE latin1_swedish_ci NULL  COMMENT 'Text name of the auctionhouse.' , 
	`minitems` int(11) NULL  DEFAULT 0 COMMENT 'This is the minimum number of items you want to keep in the auction house. a 0 here will make it the same as the maximum.' , 
	`maxitems` int(11) NULL  DEFAULT 0 COMMENT 'This is the number of items you want to keep in the auction house.' , 
	`percentgreytradegoods` int(11) NULL  DEFAULT 0 COMMENT 'Sets the percentage of the Grey Trade Goods auction items' , 
	`percentwhitetradegoods` int(11) NULL  DEFAULT 27 COMMENT 'Sets the percentage of the White Trade Goods auction items' , 
	`percentgreentradegoods` int(11) NULL  DEFAULT 12 COMMENT 'Sets the percentage of the Green Trade Goods auction items' , 
	`percentbluetradegoods` int(11) NULL  DEFAULT 10 COMMENT 'Sets the percentage of the Blue Trade Goods auction items' , 
	`percentpurpletradegoods` int(11) NULL  DEFAULT 1 COMMENT 'Sets the percentage of the Purple Trade Goods auction items' , 
	`percentorangetradegoods` int(11) NULL  DEFAULT 0 COMMENT 'Sets the percentage of the Orange Trade Goods auction items' , 
	`percentyellowtradegoods` int(11) NULL  DEFAULT 0 COMMENT 'Sets the percentage of the Yellow Trade Goods auction items' , 
	`percentgreyitems` int(11) NULL  DEFAULT 0 COMMENT 'Sets the percentage of the non trade Grey auction items' , 
	`percentwhiteitems` int(11) NULL  DEFAULT 10 COMMENT 'Sets the percentage of the non trade White auction items' , 
	`percentgreenitems` int(11) NULL  DEFAULT 30 COMMENT 'Sets the percentage of the non trade Green auction items' , 
	`percentblueitems` int(11) NULL  DEFAULT 8 COMMENT 'Sets the percentage of the non trade Blue auction items' , 
	`percentpurpleitems` int(11) NULL  DEFAULT 2 COMMENT 'Sets the percentage of the non trade Purple auction items' , 
	`percentorangeitems` int(11) NULL  DEFAULT 0 COMMENT 'Sets the percentage of the non trade Orange auction items' , 
	`percentyellowitems` int(11) NULL  DEFAULT 0 COMMENT 'Sets the percentage of the non trade Yellow auction items' , 
	`minpricegrey` int(11) NULL  DEFAULT 100 COMMENT 'Minimum price of Grey items (percentage).' , 
	`maxpricegrey` int(11) NULL  DEFAULT 150 COMMENT 'Maximum price of Grey items (percentage).' , 
	`minpricewhite` int(11) NULL  DEFAULT 150 COMMENT 'Minimum price of White items (percentage).' , 
	`maxpricewhite` int(11) NULL  DEFAULT 250 COMMENT 'Maximum price of White items (percentage).' , 
	`minpricegreen` int(11) NULL  DEFAULT 800 COMMENT 'Minimum price of Green items (percentage).' , 
	`maxpricegreen` int(11) NULL  DEFAULT 1400 COMMENT 'Maximum price of Green items (percentage).' , 
	`minpriceblue` int(11) NULL  DEFAULT 1250 COMMENT 'Minimum price of Blue items (percentage).' , 
	`maxpriceblue` int(11) NULL  DEFAULT 1750 COMMENT 'Maximum price of Blue items (percentage).' , 
	`minpricepurple` int(11) NULL  DEFAULT 2250 COMMENT 'Minimum price of Purple items (percentage).' , 
	`maxpricepurple` int(11) NULL  DEFAULT 4550 COMMENT 'Maximum price of Purple items (percentage).' , 
	`minpriceorange` int(11) NULL  DEFAULT 3250 COMMENT 'Minimum price of Orange items (percentage).' , 
	`maxpriceorange` int(11) NULL  DEFAULT 5550 COMMENT 'Maximum price of Orange items (percentage).' , 
	`minpriceyellow` int(11) NULL  DEFAULT 5250 COMMENT 'Minimum price of Yellow items (percentage).' , 
	`maxpriceyellow` int(11) NULL  DEFAULT 6550 COMMENT 'Maximum price of Yellow items (percentage).' , 
	`minbidpricegrey` int(11) NULL  DEFAULT 70 COMMENT 'Starting bid price of Grey items as a percentage of the randomly chosen buyout price. Default: 70' , 
	`maxbidpricegrey` int(11) NULL  DEFAULT 100 COMMENT 'Starting bid price of Grey items as a percentage of the randomly chosen buyout price. Default: 100' , 
	`minbidpricewhite` int(11) NULL  DEFAULT 70 COMMENT 'Starting bid price of White items as a percentage of the randomly chosen buyout price. Default: 70' , 
	`maxbidpricewhite` int(11) NULL  DEFAULT 100 COMMENT 'Starting bid price of White items as a percentage of the randomly chosen buyout price. Default: 100' , 
	`minbidpricegreen` int(11) NULL  DEFAULT 80 COMMENT 'Starting bid price of Green items as a percentage of the randomly chosen buyout price. Default: 80' , 
	`maxbidpricegreen` int(11) NULL  DEFAULT 100 COMMENT 'Starting bid price of Green items as a percentage of the randomly chosen buyout price. Default: 100' , 
	`minbidpriceblue` int(11) NULL  DEFAULT 75 COMMENT 'Starting bid price of Blue items as a percentage of the randomly chosen buyout price. Default: 75' , 
	`maxbidpriceblue` int(11) NULL  DEFAULT 100 COMMENT 'Starting bid price of Blue items as a percentage of the randomly chosen buyout price. Default: 100' , 
	`minbidpricepurple` int(11) NULL  DEFAULT 80 COMMENT 'Starting bid price of Purple items as a percentage of the randomly chosen buyout price. Default: 80' , 
	`maxbidpricepurple` int(11) NULL  DEFAULT 100 COMMENT 'Starting bid price of Purple items as a percentage of the randomly chosen buyout price. Default: 100' , 
	`minbidpriceorange` int(11) NULL  DEFAULT 80 COMMENT 'Starting bid price of Orange items as a percentage of the randomly chosen buyout price. Default: 80' , 
	`maxbidpriceorange` int(11) NULL  DEFAULT 100 COMMENT 'Starting bid price of Orange items as a percentage of the randomly chosen buyout price. Default: 100' , 
	`minbidpriceyellow` int(11) NULL  DEFAULT 80 COMMENT 'Starting bid price of Yellow items as a percentage of the randomly chosen buyout price. Default: 80' , 
	`maxbidpriceyellow` int(11) NULL  DEFAULT 100 COMMENT 'Starting bid price of Yellow items as a percentage of the randomly chosen buyout price. Default: 100' , 
	`maxstackgrey` int(11) NULL  DEFAULT 0 COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.' , 
	`maxstackwhite` int(11) NULL  DEFAULT 0 COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.' , 
	`maxstackgreen` int(11) NULL  DEFAULT 0 COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.' , 
	`maxstackblue` int(11) NULL  DEFAULT 0 COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.' , 
	`maxstackpurple` int(11) NULL  DEFAULT 0 COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.' , 
	`maxstackorange` int(11) NULL  DEFAULT 0 COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.' , 
	`maxstackyellow` int(11) NULL  DEFAULT 0 COMMENT 'Stack size limits for item qualities - a value of 0 will disable a maximum stack size for that quality, which will allow the bot to create items in stack as large as the item allows.' , 
	`buyerpricegrey` int(11) NULL  DEFAULT 1 COMMENT 'Multiplier to vendorprice when buying grey items from auctionhouse' , 
	`buyerpricewhite` int(11) NULL  DEFAULT 3 COMMENT 'Multiplier to vendorprice when buying white items from auctionhouse' , 
	`buyerpricegreen` int(11) NULL  DEFAULT 5 COMMENT 'Multiplier to vendorprice when buying green items from auctionhouse' , 
	`buyerpriceblue` int(11) NULL  DEFAULT 12 COMMENT 'Multiplier to vendorprice when buying blue items from auctionhouse' , 
	`buyerpricepurple` int(11) NULL  DEFAULT 15 COMMENT 'Multiplier to vendorprice when buying purple items from auctionhouse' , 
	`buyerpriceorange` int(11) NULL  DEFAULT 20 COMMENT 'Multiplier to vendorprice when buying orange items from auctionhouse' , 
	`buyerpriceyellow` int(11) NULL  DEFAULT 22 COMMENT 'Multiplier to vendorprice when buying yellow items from auctionhouse' , 
	`buyerbiddinginterval` int(11) NULL  DEFAULT 1 COMMENT 'Interval how frequently AHB bids on each AH. Time in minutes' , 
	`buyerbidsperinterval` int(11) NULL  DEFAULT 1 COMMENT 'number of bids to put in per bidding interval' , 
	PRIMARY KEY (`auctionhouse`) 
) ENGINE=InnoDB DEFAULT CHARSET='latin1';


-- character_arena_stats
ALTER TABLE `character_arena_stats` 
	ADD COLUMN `personalRating` smallint(5)   NOT NULL after `matchMakerRating`;


-- character_branchspec
CREATE TABLE `character_branchspec`(
	`guid` int(11) unsigned NOT NULL  DEFAULT 0 , 
	`spec` int(11) unsigned NOT NULL  DEFAULT 0 , 
	`branchSpec` int(11) unsigned NOT NULL  DEFAULT 0 , 
	PRIMARY KEY (`guid`,`spec`) 
) ENGINE=MyISAM DEFAULT CHARSET='latin1';


-- character_cp_weekcap
CREATE TABLE `character_cp_weekcap`(
	`guid` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`source` tinyint(3) unsigned NOT NULL  DEFAULT 0 , 
	`maxWeekRating` smallint(5) unsigned NOT NULL  DEFAULT 0 , 
	`weekCap` smallint(5) unsigned NOT NULL  DEFAULT 0 , 
	PRIMARY KEY (`guid`,`source`) 
) ENGINE=InnoDB DEFAULT CHARSET='utf8';


-- character_currency
CREATE TABLE `character_currency`(
	`guid` int(11) unsigned NOT NULL  , 
	`currency` smallint(5) unsigned NOT NULL  , 
	`count` smallint(5) unsigned NOT NULL  , 
	`thisweek` smallint(5) unsigned NOT NULL  , 
	PRIMARY KEY (`guid`,`currency`) 
) ENGINE=InnoDB DEFAULT CHARSET='utf8';


-- character_glyphs
ALTER TABLE `character_glyphs` 
	ADD COLUMN `glyph7` smallint(5) unsigned   NULL DEFAULT 0 after `glyph6`, 
	ADD COLUMN `glyph8` smallint(5) unsigned   NULL DEFAULT 0 after `glyph7`, 
	ADD COLUMN `glyph9` int(11) unsigned   NULL DEFAULT 0 after `glyph8`;


-- character_homebind
ALTER TABLE `character_homebind` 
	CHANGE `mapId` `map` smallint(5) unsigned   NOT NULL DEFAULT 0 COMMENT 'Map Identifier' after `guid`, 
	CHANGE `zoneId` `zone` smallint(5) unsigned   NOT NULL DEFAULT 0 COMMENT 'Zone Identifier' after `map`, 
	CHANGE `posX` `position_x` float   NOT NULL DEFAULT 0 after `zone`, 
	CHANGE `posY` `position_y` float   NOT NULL DEFAULT 0 after `position_x`, 
	CHANGE `posZ` `position_z` float   NOT NULL DEFAULT 0 after `position_y`;


-- character_inventory
ALTER TABLE `character_inventory` 
	DROP KEY `guid`;


-- character_pet
ALTER TABLE `character_pet` 
	ADD COLUMN `resettalents_cost` int(10) unsigned   NULL DEFAULT 0 after `savetime`, 
	ADD COLUMN `resettalents_time` int(10) unsigned   NULL DEFAULT 0 after `resettalents_cost`, 
	CHANGE `abdata` `abdata` text  COLLATE utf8_general_ci NULL after `resettalents_time`, 
	DROP KEY `idx_slot`;


-- character_queststatus
ALTER TABLE `character_queststatus` 
	DROP COLUMN `playercount`;


-- character_stats
ALTER TABLE `character_stats` 
	ADD COLUMN `maxpower8` int(10) unsigned   NOT NULL DEFAULT 0 after `spellPower`, 
	ADD COLUMN `maxpower9` int(10) unsigned   NOT NULL DEFAULT 0 after `maxpower8`, 
	ADD COLUMN `maxpower10` int(10) unsigned   NOT NULL DEFAULT 0 after `maxpower9`, 
	DROP COLUMN `resilience`;


-- character_tutorial
CREATE TABLE `character_tutorial`(
	`account` int(10) unsigned NOT NULL  auto_increment COMMENT 'Account Identifier' , 
	`tut0` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`tut1` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`tut2` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`tut3` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`tut4` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`tut5` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`tut6` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`tut7` int(10) unsigned NOT NULL  DEFAULT 0 , 
	PRIMARY KEY (`account`) 
) ENGINE=InnoDB DEFAULT CHARSET='utf8' COMMENT='Player System';


-- characters
ALTER TABLE `characters` 
	CHANGE `map` `map` int(11) unsigned   NOT NULL DEFAULT 0 COMMENT 'Map Identifier' after `position_z`, 
	ADD COLUMN `power8` int(10) unsigned   NOT NULL DEFAULT 0 after `power7`, 
	ADD COLUMN `power9` int(10) unsigned   NOT NULL DEFAULT 0 after `power8`, 
	ADD COLUMN `power10` int(10) unsigned   NOT NULL DEFAULT 0 after `power9`, 
	CHANGE `latency` `latency` mediumint(8) unsigned   NOT NULL DEFAULT 0 after `power10`, 
	CHANGE `speccount` `speccount` tinyint(3) unsigned   NOT NULL DEFAULT 1 after `latency`, 
	CHANGE `activespec` `activespec` tinyint(3) unsigned   NOT NULL DEFAULT 0 after `speccount`, 
	CHANGE `exploredZones` `exploredZones` longtext  COLLATE utf8_general_ci NULL after `activespec`, 
	CHANGE `equipmentCache` `equipmentCache` longtext  COLLATE utf8_general_ci NULL after `exploredZones`, 
	CHANGE `ammoId` `ammoId` int(10) unsigned   NOT NULL DEFAULT 0 after `equipmentCache`, 
	CHANGE `knownTitles` `knownTitles` longtext  COLLATE utf8_general_ci NULL after `ammoId`, 
	CHANGE `actionBars` `actionBars` tinyint(3) unsigned   NOT NULL DEFAULT 0 after `knownTitles`, 
	CHANGE `deleteInfos_Account` `deleteInfos_Account` int(10) unsigned   NULL after `actionBars`, 
	CHANGE `deleteInfos_Name` `deleteInfos_Name` varchar(12)  COLLATE utf8_general_ci NULL after `deleteInfos_Account`, 
	CHANGE `deleteDate` `deleteDate` int(10) unsigned   NULL after `deleteInfos_Name`, 
	ADD COLUMN `currentPetSlot` int(10)   NULL after `deleteDate`, 
	ADD COLUMN `petSlotUsed` bigint(32)   NULL after `currentPetSlot`, 
	DROP COLUMN `grantableLevels`;


-- corpse
ALTER TABLE `corpse` 
	CHANGE `flags` `flags` tinyint(3) unsigned   NOT NULL DEFAULT 0 after `bytes2`, 
	CHANGE `dynFlags` `dynFlags` tinyint(3) unsigned   NOT NULL DEFAULT 0 after `flags`, 
	CHANGE `time` `time` int(10) unsigned   NOT NULL DEFAULT 0 after `dynFlags`, 
	CHANGE `corpseType` `corpseType` tinyint(3) unsigned   NOT NULL DEFAULT 0 after `time`, 
	CHANGE `instanceId` `instanceId` int(10) unsigned   NOT NULL DEFAULT 0 COMMENT 'Instance Identifier' after `corpseType`, 
	CHANGE `guildId` `guildId` int(10) unsigned   NOT NULL DEFAULT 0 after `instanceId`, 
	DROP KEY `idx_instance`, 
	DROP KEY `idx_player`, 
	ADD KEY `Idx_player`(`guid`), 
	DROP KEY `idx_time`, 
	ADD KEY `Idx_time`(`time`), 
	ADD KEY `instance`(`instanceId`);


-- game_event_condition_save
ALTER TABLE `game_event_condition_save` 
	CHANGE `eventEntry` `event_id` smallint(5) unsigned   NOT NULL first, 
	CHANGE `condition_id` `condition_id` int(10) unsigned   NOT NULL DEFAULT 0 after `event_id`;


-- game_event_save
ALTER TABLE `game_event_save` 
	CHANGE `eventEntry` `event_id` mediumint(8) unsigned   NOT NULL first, 
	CHANGE `state` `state` tinyint(3) unsigned   NOT NULL DEFAULT 1 after `event_id`, 
	CHANGE `next_start` `next_start` bigint(11) unsigned   NOT NULL DEFAULT 0 after `state`;


-- gm_subsurveys
ALTER TABLE `gm_subsurveys` 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`surveyid`,`subsurveyid`);


-- gm_surveys
DROP TABLE IF EXISTS `gm_surveys`;
CREATE TABLE `gm_surveys` (
	`surveyid` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
	`player` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`mainSurvey` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`overall_comment` LONGTEXT NOT NULL,
	`timestamp` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	PRIMARY KEY (`surveyid`)
)
COMMENT='Player System'
COLLATE='utf8_general_ci'
ENGINE=InnoDB;


-- gm_tickets
DROP TABLE IF EXISTS `gm_tickets`;
CREATE TABLE `gm_tickets` (
	`guid` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
	`playerGuid` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`name` VARCHAR(12) NOT NULL,
	`message` TEXT NOT NULL,
	`createtime` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`map` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
	`posX` FLOAT NOT NULL DEFAULT '0',
	`posY` FLOAT NOT NULL DEFAULT '0',
	`posZ` FLOAT NOT NULL DEFAULT '0',
	`timestamp` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`closed` INT(11) NOT NULL DEFAULT '0',
	`assignedto` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`comment` TEXT NOT NULL,
	`completed` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`escalated` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`viewed` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	PRIMARY KEY (`guid`)
)
COMMENT='Player System'
COLLATE='utf8_general_ci'
ENGINE=InnoDB;

-- guild
ALTER TABLE `guild` 
	ADD COLUMN `xp` bigint(20) unsigned   NOT NULL after `BankMoney`, 
	ADD COLUMN `level` int(10) unsigned   NOT NULL after `xp`;


-- guild_member
ALTER TABLE `guild_member` 
	ADD COLUMN `BankResetTimeTab6` int(10) unsigned   NOT NULL DEFAULT 0 after `BankRemSlotsTab5`, 
	ADD COLUMN `BankRemSlotsTab6` int(10) unsigned   NOT NULL DEFAULT 0 after `BankResetTimeTab6`, 
	ADD COLUMN `BankResetTimeTab7` int(10) unsigned   NOT NULL DEFAULT 0 after `BankRemSlotsTab6`, 
	ADD COLUMN `BankRemSlotsTab7` int(10) unsigned   NOT NULL DEFAULT 0 after `BankResetTimeTab7`, 
	ADD COLUMN `achievementPoints` int(11) unsigned   NOT NULL DEFAULT 0 after `BankRemSlotsTab7`;


-- lag_reports
DROP TABLE IF EXISTS `lag_reports`;
CREATE TABLE `lag_reports` (
	`report_id` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
	`player` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`lag_type` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
	`map` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
	`posX` FLOAT NOT NULL DEFAULT '0',
	`posY` FLOAT NOT NULL DEFAULT '0',
	`posZ` FLOAT NOT NULL DEFAULT '0',
	PRIMARY KEY (`report_id`)
)
COMMENT='Player System'
COLLATE='utf8_general_ci'
ENGINE=InnoDB;

-- mail_items
ALTER TABLE `mail_items` 
	DROP KEY `idx_mail_id`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`mail_id`,`item_guid`);


-- petition
ALTER TABLE `petition` 
	DROP COLUMN `type`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`ownerguid`);


-- players_reports_status
CREATE TABLE `players_reports_status`(
	`guid` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`creation_time` int(10) unsigned NOT NULL  DEFAULT 0 , 
	`average` bigint(20) unsigned NOT NULL  DEFAULT 0 , 
	`total_reports` bigint(20) unsigned NOT NULL  DEFAULT 0 , 
	`speed_reports` bigint(20) unsigned NOT NULL  DEFAULT 0 , 
	`fly_reports` bigint(20) unsigned NOT NULL  DEFAULT 0 , 
	`jump_reports` bigint(20) unsigned NOT NULL  DEFAULT 0 , 
	`waterwalk_reports` bigint(20) unsigned NOT NULL  DEFAULT 0 , 
	`teleportplane_reports` bigint(20) unsigned NOT NULL  DEFAULT 0 , 
	PRIMARY KEY (`guid`) 
) ENGINE=InnoDB DEFAULT CHARSET='utf8';

/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;