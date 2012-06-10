-- This fixes the races required for quests.

-- horde
UPDATE `quest_template` SET `RequiredRaces` = 18 WHERE `entry` = 28428;
UPDATE `quest_template` SET `RequiredRaces` = 32 WHERE `entry` = 28429;
UPDATE `quest_template` SET `RequiredRaces` = 256 WHERE `entry` = 28430;
UPDATE `quest_template` SET `RequiredRaces` = 640 WHERE `entry` = 28431;

-- alliance
UPDATE `quest_template` SET `RequiredRaces` = 8 WHERE `entry` = 28205;
UPDATE `quest_template` SET `RequiredRaces` = 2098176 WHERE `entry` = 28203;
UPDATE `quest_template` SET `RequiredRaces` = 64 WHERE `entry` = 28204;
UPDATE `quest_template` SET `RequiredRaces` = 4 WHERE `entry` = 28202;
