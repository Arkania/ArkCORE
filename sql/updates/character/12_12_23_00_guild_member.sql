ALTER TABLE `guild_member` 
	ADD COLUMN `FirstProffLevel` int(11) unsigned   NOT NULL DEFAULT 0 after `BankRemSlotsTab7`, 
	ADD COLUMN `FirstProffSkill` int(11) unsigned   NOT NULL DEFAULT 0 after `FirstProffLevel`, 
	ADD COLUMN `FirstProffRank` int(11) unsigned   NOT NULL DEFAULT 0 after `FirstProffSkill`, 
	ADD COLUMN `SecondProffLevel` int(11) unsigned   NOT NULL DEFAULT 0 after `FirstProffRank`, 
	ADD COLUMN `SecondProffSkill` int(11) unsigned   NOT NULL DEFAULT 0 after `SecondProffLevel`, 
	ADD COLUMN `SecondProffRank` int(11) unsigned   NOT NULL DEFAULT 0 after `SecondProffSkill`;