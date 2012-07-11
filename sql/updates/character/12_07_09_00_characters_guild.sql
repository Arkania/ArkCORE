/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;

-- guild
ALTER TABLE `guild` 
	ADD COLUMN `totalXP` BIGINT(20) UNSIGNED   NOT NULL DEFAULT 0 AFTER `BankMoney`, 
	ADD COLUMN `todayXP` BIGINT(20) UNSIGNED   NOT NULL DEFAULT 0 AFTER `totalXP`, 
	ADD COLUMN `XPCap` BIGINT(20) UNSIGNED   NOT NULL DEFAULT 0 AFTER `todayXP`, 
	CHANGE `xp` `xp` BIGINT(20) UNSIGNED   NOT NULL DEFAULT 0 AFTER `XPCap`, 
	CHANGE `level` `level` INT(10) UNSIGNED   NOT NULL AFTER `xp`;

-- #########################################
-- ## OPTION: NOT IN ARKDB 3.5.0 or 3.6.0 ##
-- ##                                     ##
-- ## To use, uncomment the line below    ##
-- #########################################

-- ##################
-- ## guild_member ##
-- ##################

-- ALTER TABLE `guild_member` 
--	DROP COLUMN `FirstProffLevel`, 
--	DROP COLUMN `FirstProffSkill`, 
--	DROP COLUMN `FirstProffRank`, 
--	DROP COLUMN `SecondProffLevel`, 
--	DROP COLUMN `SecondProffSkill`, 
--	DROP COLUMN `SecondProffRank`;

/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
