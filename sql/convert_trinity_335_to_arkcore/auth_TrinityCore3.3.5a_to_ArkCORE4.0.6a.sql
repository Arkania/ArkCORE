-- Use on TrinityCORE 3.3.5a auth realm
-- STATUS: 90%

/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;

-- account
ALTER TABLE `account` 
	CHANGE `id` `id` int(11) unsigned   NOT NULL auto_increment COMMENT 'Identifier' first, 
	CHANGE `sessionkey` `sessionkey` longtext  COLLATE utf8_general_ci NULL after `sha_pass_hash`, 
	CHANGE `v` `v` longtext  COLLATE utf8_general_ci NULL after `sessionkey`, 
	CHANGE `s` `s` longtext  COLLATE utf8_general_ci NULL after `v`, 
	CHANGE `email` `email` text  COLLATE utf8_general_ci NULL after `s`, 
	CHANGE `last_ip` `last_ip` varchar(30)  COLLATE utf8_general_ci NOT NULL DEFAULT '127.0.0.1' after `joindate`, 
	CHANGE `failed_logins` `failed_logins` int(11) unsigned   NOT NULL DEFAULT 0 after `last_ip`, 
	CHANGE `online` `online` tinyint(4)   NOT NULL DEFAULT 0 after `last_login`, 
	CHANGE `expansion` `expansion` tinyint(3) unsigned   NOT NULL DEFAULT 3 after `online`, 
	CHANGE `mutetime` `mutetime` bigint(40) unsigned   NOT NULL DEFAULT 0 after `expansion`, 
	CHANGE `recruiter` `recruiter` int(11)   NOT NULL DEFAULT 0 after `locale`, 
	DROP COLUMN `os`;


-- account_access
ALTER TABLE `account_access` 
	CHANGE `id` `id` int(11) unsigned   NOT NULL first;


-- account_banned
ALTER TABLE `account_banned` 
	CHANGE `id` `id` int(11)   NOT NULL DEFAULT 0 COMMENT 'Account id' first, 
	CHANGE `bandate` `bandate` bigint(40)   NOT NULL DEFAULT 0 after `id`, 
	CHANGE `unbandate` `unbandate` bigint(40)   NOT NULL DEFAULT 0 after `bandate`, 
	CHANGE `active` `active` tinyint(4)   NOT NULL DEFAULT 1 after `banreason`, ENGINE=MyISAM; 

-- account_premium
CREATE TABLE `account_premium`(
	`id` int(11) NOT NULL  DEFAULT 0 COMMENT 'Account id' , 
	`setdate` bigint(40) NOT NULL  DEFAULT 0 , 
	`unsetdate` bigint(40) NOT NULL  DEFAULT 0 , 
	`premium_type` tinyint(4) unsigned NOT NULL  DEFAULT 1 , 
	`active` tinyint(4) NOT NULL  DEFAULT 1 , 
	PRIMARY KEY (`id`,`setdate`) 
) ENGINE=MyISAM DEFAULT CHARSET='utf8' COMMENT='Premium Accounts';


-- ip_banned
ALTER TABLE `ip_banned` 
	CHANGE `ip` `ip` varchar(32)  COLLATE utf8_general_ci NOT NULL DEFAULT '127.0.0.1' first, 
	CHANGE `bandate` `bandate` bigint(40)   NOT NULL after `ip`, 
	CHANGE `unbandate` `unbandate` bigint(40)   NOT NULL after `bandate`, ENGINE=MyISAM; 

-- logs
ALTER TABLE `logs` 
	CHANGE `time` `time` int(14)   NOT NULL first, 
	CHANGE `realm` `realm` int(4)   NOT NULL after `time`, 
	CHANGE `type` `type` int(4)   NOT NULL after `realm`, ENGINE=MyISAM, DEFAULT CHARSET='latin1';


-- realmcharacters
ALTER TABLE `realmcharacters` 
	CHANGE `realmid` `realmid` int(11) unsigned   NOT NULL DEFAULT 0 first, 
	CHANGE `acctid` `acctid` bigint(20) unsigned   NOT NULL after `realmid`, ENGINE=MyISAM; 

-- realmlist
ALTER TABLE `realmlist` 
	CHANGE `id` `id` int(11) unsigned   NOT NULL auto_increment first, 
	CHANGE `address` `address` varchar(32)  COLLATE utf8_general_ci NOT NULL DEFAULT '127.0.0.1' after `name`, 
	CHANGE `port` `port` int(11)   NOT NULL DEFAULT 8085 after `address`, 
	ADD COLUMN `color` tinyint(3) unsigned   NOT NULL DEFAULT 2 after `icon`, 
	CHANGE `timezone` `timezone` tinyint(3) unsigned   NOT NULL DEFAULT 0 after `color`, 
	ADD COLUMN `online` int(11)   NOT NULL DEFAULT 0 after `population`, 
	CHANGE `gamebuild` `gamebuild` int(11) unsigned   NOT NULL DEFAULT 13623 after `online`, 
	DROP COLUMN `flag`, ENGINE=MyISAM; 

-- uptime
ALTER TABLE `uptime` 
	CHANGE `realmid` `realmid` int(11) unsigned   NOT NULL first, 
	CHANGE `starttime` `starttime` bigint(20) unsigned   NOT NULL DEFAULT 0 after `realmid`, 
	ADD COLUMN `startstring` varchar(64)  COLLATE utf8_general_ci NOT NULL DEFAULT '' after `starttime`, 
	CHANGE `uptime` `uptime` bigint(20) unsigned   NOT NULL DEFAULT 0 after `startstring`, 
	CHANGE `maxplayers` `maxplayers` smallint(5) unsigned   NOT NULL DEFAULT 0 after `uptime`, 
	CHANGE `revision` `revision` varchar(255)  COLLATE utf8_general_ci NOT NULL DEFAULT 'Trinitycore' after `maxplayers`, ENGINE=MyISAM; 
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;