-- Hidden Spell Casts at completiton of quests
ALTER TABLE `quest_template` ADD COLUMN `RewSpellHiddenCast` INT(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `RewSpellCast`;

-- Example: Lockdown! - First Worgen Quest
UPDATE `quest_template` SET `RewSpellCast`='0', `RewSpellHiddenCast`='59073' WHERE `entry`='14078';