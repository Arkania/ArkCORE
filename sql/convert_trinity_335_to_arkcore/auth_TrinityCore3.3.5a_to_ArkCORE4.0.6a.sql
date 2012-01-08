-- Use on TrinityCORE 3.3.5a auth realm
-- STATUS: 50%

-- account
ALTER TABLE `account` 
	CHANGE `expansion` `expansion` tinyint(3) unsigned   NOT NULL DEFAULT '3' after `online`, 
	CHANGE `mutetime` `mutetime` bigint(40) unsigned   NOT NULL DEFAULT '0' after `expansion`, ENGINE=InnoDB; 

-- account_access
ALTER TABLE `account_access` ENGINE=InnoDB; 

-- realmlist
ALTER TABLE `realmlist` 
	ADD COLUMN `online` int(11)   NOT NULL DEFAULT '0' after `population`, 
	CHANGE `gamebuild` `gamebuild` int(11) unsigned   NOT NULL DEFAULT '13623' after `online`;