-- Use on TrinityCORE 3.3.5a characters database
-- STATUS: 5%


-- account_data
ALTER TABLE `account_data` 
	ADD COLUMN `account` int(10) unsigned   NOT NULL DEFAULT '0' first, 
	CHANGE `type` `type` tinyint(3) unsigned   NOT NULL DEFAULT '0' after `account`, 
	DROP COLUMN `accountId`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`account`,`type`);

-- arena_team_stats
CREATE TABLE `arena_team_stats`(
	`arenateamid` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`rating` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`games` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`wins` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`played` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`wins2` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`rank` int(10) unsigned NOT NULL  DEFAULT '0' , 
	PRIMARY KEY (`arenateamid`) 
) ENGINE=InnoDB DEFAULT CHARSET='utf8';

INSERT INTO `access_requirement` (id, item, item2, heroic_key, heroic_key2, quest_done, quest_failed_text, heroic_quest_done, map) SELECT id, required_item, required_item2, heroic_key, heroic_key2, required_quest_done, required_failed_text, required_quest_done_heroic, target_map FROM `areatrigger_teleport`;


-- character_arena_stats
ALTER TABLE `character_arena_stats` 
	ADD COLUMN `personalRating` smallint(5)   NOT NULL after `matchMakerRating`;

-- character_branchspec
CREATE TABLE `character_branchspec`(
	`guid` int(11) unsigned NOT NULL  DEFAULT '0' , 
	`spec` int(11) unsigned NOT NULL  DEFAULT '0' , 
	`branchSpec` int(11) unsigned NOT NULL  DEFAULT '0' , 
	PRIMARY KEY (`guid`,`spec`) 
) ENGINE=MyISAM DEFAULT CHARSET='latin1';


-- character_cp_weekcap
CREATE TABLE `character_cp_weekcap`(
	`guid` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`source` tinyint(3) unsigned NOT NULL  DEFAULT '0' , 
	`maxWeekRating` smallint(5) unsigned NOT NULL  DEFAULT '0' , 
	`weekCap` smallint(5) unsigned NOT NULL  DEFAULT '0' , 
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
	ADD COLUMN `glyph7` smallint(5) unsigned   NULL DEFAULT '0' after `glyph6`, 
	ADD COLUMN `glyph8` smallint(5) unsigned   NULL DEFAULT '0' after `glyph7`, 
	ADD COLUMN `glyph9` int(11) unsigned   NULL DEFAULT '0' after `glyph8`;

-- character_homebind
ALTER TABLE `character_homebind` 
	ADD COLUMN `map` smallint(5) unsigned   NOT NULL DEFAULT '0' COMMENT 'Map Identifier' after `guid`, 
	ADD COLUMN `zone` smallint(5) unsigned   NOT NULL DEFAULT '0' COMMENT 'Zone Identifier' after `map`, 
	ADD COLUMN `position_x` float   NOT NULL DEFAULT '0' after `zone`, 
	ADD COLUMN `position_y` float   NOT NULL DEFAULT '0' after `position_x`, 
	ADD COLUMN `position_z` float   NOT NULL DEFAULT '0' after `position_y`, 
	DROP COLUMN `mapId`, 
	DROP COLUMN `zoneId`, 
	DROP COLUMN `posX`, 
	DROP COLUMN `posY`, 
	DROP COLUMN `posZ`;

-- character_inventory
ALTER TABLE `character_inventory` 
	DROP KEY `guid`;

-- character_pet
ALTER TABLE `character_pet` 
	ADD COLUMN `resettalents_cost` int(10) unsigned   NULL DEFAULT '0' after `savetime`, 
	ADD COLUMN `resettalents_time` int(10) unsigned   NULL DEFAULT '0' after `resettalents_cost`, 
	CHANGE `abdata` `abdata` text  COLLATE utf8_general_ci NULL after `resettalents_time`, 
	DROP KEY `idx_slot`;

-- character_queststatus
ALTER TABLE `character_queststatus` 
	DROP COLUMN `playercount`;

-- character_stats
ALTER TABLE `character_stats` 
	ADD COLUMN `maxpower8` int(10) unsigned   NOT NULL DEFAULT '0' after `spellPower`, 
	ADD COLUMN `maxpower9` int(10) unsigned   NOT NULL DEFAULT '0' after `maxpower8`, 
	ADD COLUMN `maxpower10` int(10) unsigned   NOT NULL DEFAULT '0' after `maxpower9`, 
	DROP COLUMN `resilience`;

-- character_tutorial
CREATE TABLE `character_tutorial`(
	`account` int(10) unsigned NOT NULL  auto_increment COMMENT 'Account Identifier' , 
	`tut0` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`tut1` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`tut2` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`tut3` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`tut4` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`tut5` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`tut6` int(10) unsigned NOT NULL  DEFAULT '0' , 
	`tut7` int(10) unsigned NOT NULL  DEFAULT '0' , 
	PRIMARY KEY (`account`) 
) ENGINE=InnoDB DEFAULT CHARSET='utf8' COMMENT='Player System';


-- characters
ALTER TABLE `characters` 
	CHANGE `map` `map` int(11) unsigned   NOT NULL DEFAULT '0' COMMENT 'Map Identifier' after `position_z`, 
	ADD COLUMN `power8` int(10) unsigned   NOT NULL DEFAULT '0' after `power7`, 
	ADD COLUMN `power9` int(10) unsigned   NOT NULL DEFAULT '0' after `power8`, 
	ADD COLUMN `power10` int(10) unsigned   NOT NULL DEFAULT '0' after `power9`, 
	CHANGE `latency` `latency` mediumint(8) unsigned   NOT NULL DEFAULT '0' after `power10`, 
	CHANGE `speccount` `speccount` tinyint(3) unsigned   NOT NULL DEFAULT '1' after `latency`, 
	CHANGE `activespec` `activespec` tinyint(3) unsigned   NOT NULL DEFAULT '0' after `speccount`, 
	CHANGE `exploredZones` `exploredZones` longtext  COLLATE utf8_general_ci NULL after `activespec`, 
	CHANGE `equipmentCache` `equipmentCache` longtext  COLLATE utf8_general_ci NULL after `exploredZones`, 
	CHANGE `ammoId` `ammoId` int(10) unsigned   NOT NULL DEFAULT '0' after `equipmentCache`, 
	CHANGE `knownTitles` `knownTitles` longtext  COLLATE utf8_general_ci NULL after `ammoId`, 
	CHANGE `actionBars` `actionBars` tinyint(3) unsigned   NOT NULL DEFAULT '0' after `knownTitles`, 
	CHANGE `deleteInfos_Account` `deleteInfos_Account` int(10) unsigned   NULL after `actionBars`, 
	CHANGE `deleteInfos_Name` `deleteInfos_Name` varchar(12)  COLLATE utf8_general_ci NULL after `deleteInfos_Account`, 
	CHANGE `deleteDate` `deleteDate` int(10) unsigned   NULL after `deleteInfos_Name`, 
	ADD COLUMN `currentPetSlot` int(10)   NULL after `deleteDate`, 
	ADD COLUMN `petSlotUsed` bigint(32)   NULL after `currentPetSlot`, 
	DROP COLUMN `grantableLevels`;

-- corpse
ALTER TABLE `corpse` 
	CHANGE `flags` `flags` tinyint(3) unsigned   NOT NULL DEFAULT '0' after `bytes2`, 
	CHANGE `dynFlags` `dynFlags` tinyint(3) unsigned   NOT NULL DEFAULT '0' after `flags`, 
	CHANGE `time` `time` int(10) unsigned   NOT NULL DEFAULT '0' after `dynFlags`, 
	CHANGE `corpseType` `corpseType` tinyint(3) unsigned   NOT NULL DEFAULT '0' after `time`, 
	CHANGE `instanceId` `instanceId` int(10) unsigned   NOT NULL DEFAULT '0' COMMENT 'Instance Identifier' after `corpseType`, 
	CHANGE `guildId` `guildId` int(10) unsigned   NOT NULL DEFAULT '0' after `instanceId`, 
	DROP KEY `idx_instance`, 
	DROP KEY `idx_player`, 
	ADD KEY `Idx_player`(`guid`), 
	DROP KEY `idx_time`, 
	ADD KEY `Idx_time`(`time`), 
	ADD KEY `instance`(`instanceId`);

-- game_event_condition_save
ALTER TABLE `game_event_condition_save` 
	ADD COLUMN `event_id` smallint(5) unsigned   NOT NULL first, 
	CHANGE `condition_id` `condition_id` int(10) unsigned   NOT NULL DEFAULT '0' after `event_id`, 
	DROP COLUMN `eventEntry`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`event_id`,`condition_id`);

-- game_event_save
ALTER TABLE `game_event_save` 
	ADD COLUMN `event_id` mediumint(8) unsigned   NOT NULL first, 
	CHANGE `state` `state` tinyint(3) unsigned   NOT NULL DEFAULT '1' after `event_id`, 
	CHANGE `next_start` `next_start` bigint(11) unsigned   NOT NULL DEFAULT '0' after `state`, 
	DROP COLUMN `eventEntry`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`event_id`);

-- gm_subsurveys
ALTER TABLE `gm_subsurveys` 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`surveyid`,`subsurveyid`);

-- gm_surveys
ALTER TABLE `gm_surveys` 
	ADD COLUMN `player` int(10) unsigned   NOT NULL DEFAULT '0' after `surveyid`, 
	CHANGE `mainSurvey` `mainSurvey` int(10) unsigned   NOT NULL DEFAULT '0' after `player`, 
	ADD COLUMN `overall_comment` longtext  COLLATE utf8_general_ci NOT NULL after `mainSurvey`, 
	ADD COLUMN `timestamp` int(10) unsigned   NOT NULL DEFAULT '0' after `overall_comment`, 
	DROP COLUMN `guid`, 
	DROP COLUMN `overallComment`, 
	DROP COLUMN `createTime`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`surveyid`);

-- gm_tickets
ALTER TABLE `gm_tickets` 
	CHANGE `guid` `guid` int(10) unsigned   NOT NULL auto_increment first, 
	ADD COLUMN `playerGuid` int(10) unsigned   NOT NULL DEFAULT '0' after `guid`, 
	CHANGE `name` `name` varchar(12)  COLLATE utf8_general_ci NOT NULL after `playerGuid`, 
	ADD COLUMN `map` smallint(5) unsigned   NOT NULL DEFAULT '0' after `createtime`, 
	CHANGE `posX` `posX` float   NOT NULL DEFAULT '0' after `map`, 
	ADD COLUMN `timestamp` int(10) unsigned   NOT NULL DEFAULT '0' after `posZ`, 
	ADD COLUMN `closed` int(11)   NOT NULL DEFAULT '0' after `timestamp`, 
	CHANGE `assignedto` `assignedto` int(10) unsigned   NOT NULL DEFAULT '0' after `closed`, 
	DROP COLUMN `ticketId`, 
	DROP COLUMN `mapId`, 
	DROP COLUMN `lastModifiedTime`, 
	DROP COLUMN `closedBy`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`guid`);

-- guild
ALTER TABLE `guild` 
	ADD COLUMN `xp` bigint(20) unsigned   NOT NULL after `BankMoney`, 
	ADD COLUMN `level` int(10) unsigned   NOT NULL after `xp`;

-- guild_member
ALTER TABLE `guild_member` 
	ADD COLUMN `achievementPoints` int(11) unsigned   NOT NULL DEFAULT '0' after `BankRemSlotsTab5`;

-- lag_reports
ALTER TABLE `lag_reports` 
	ADD COLUMN `report_id` int(10) unsigned   NOT NULL auto_increment first, 
	ADD COLUMN `player` int(10) unsigned   NOT NULL DEFAULT '0' after `report_id`, 
	ADD COLUMN `lag_type` tinyint(3) unsigned   NOT NULL DEFAULT '0' after `player`, 
	ADD COLUMN `map` smallint(5) unsigned   NOT NULL DEFAULT '0' after `lag_type`, 
	CHANGE `posX` `posX` float   NOT NULL DEFAULT '0' after `map`, 
	DROP COLUMN `reportId`, 
	DROP COLUMN `guid`, 
	DROP COLUMN `lagType`, 
	DROP COLUMN `mapId`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`report_id`);

-- mail_items
ALTER TABLE `mail_items` 
	DROP KEY `idx_mail_id`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`mail_id`,`item_guid`);

-- petition
ALTER TABLE `petition` 
	DROP COLUMN `type`, 
	DROP KEY `PRIMARY`, add PRIMARY KEY(`ownerguid`);