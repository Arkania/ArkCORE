-- Various fixes for Worgen starting zone.
-- By Nanaki for Arkania.

-- Quest experiene fixes for Worgen starting zone.
UPDATE `quest_template` SET `RewXPId`=5 WHERE `entry`= 14078; -- Lockdown!
UPDATE `quest_template` SET `RewXPId`=5 WHERE `entry`= 14091; -- Something's Amiss
UPDATE `quest_template` SET `RewXPId`=6 WHERE `entry`= 14093; -- All Hell Breaks Loose
UPDATE `quest_template` SET `RewXPId`=6 WHERE `entry`= 14098; -- Evacuate the Merchant Square
UPDATE `quest_template` SET `RewXPId`=6 WHERE `entry`= 14094; -- Salvage the Supplies
UPDATE `quest_template` SET `RewXPId`=5 WHERE `entry`= 14099; -- Royal Orders
UPDATE `quest_template` SET `RewXPId`=5 WHERE `entry`= 14278; -- Seek the Sister
UPDATE `quest_template` SET `RewXPId`=4 WHERE `entry`= 24930; -- While You're At It
UPDATE `quest_template` SET `RewXPId`=1 WHERE `entry`= 14157; -- Old Divisions
UPDATE `quest_template` SET `RewXPId`=1 WHERE `entry`= 28850; -- The Prison Rooftop
UPDATE `quest_template` SET `RewXPId`=5 WHERE `entry`= 14154; -- By the Skin of His Teeth
UPDATE `quest_template` SET `RewXPId`=1 WHERE `entry`= 26129; -- Brothers In Arms
UPDATE `quest_template` SET `RewXPId`=0 WHERE `entry`= 14159; -- The Rebel Lord's Arsenal

-- Ready to Go (14402), Escape By Sea (14405), Horses for Duskhaven (14463). Only one of them should be completable.
UPDATE `quest_template` SET `ExclusiveGroup`=14402 WHERE `entry` IN (14402, 14405, 14463);

-- Correct quest flow for All Hell Breaks Loose (14093), Evacuate the Merchant Square (14098) and Salvage the Supplies (14094)
UPDATE `quest_template` SET `PrevQuestId`=14078 WHERE `entry`=14094;
UPDATE `quest_template` SET `PrevQuestId`=14091 WHERE `entry`=14093;
UPDATE `quest_template` SET `PrevQuestId`=14091 WHERE `entry`=14098;
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE entry = 14099;
UPDATE `quest_template` SET `ExclusiveGroup`="-14099" WHERE `entry` IN (14093, 14098, 14094);

-- Correct reward money at max level for All Hell Breaks Loose (14093)
UPDATE `quest_template` SET `RewMoneyMaxLevel`=120 WHERE `entry`=14093;

-- Correct reputation reward for All Hell Breaks Loose (14093)
UPDATE `quest_template` SET `RewRepValueId1`=6, `RewRepValue1`=0 WHERE `entry`=14093;

-- Various quest texts.
UPDATE `quest_template` SET `CompletedText`="" WHERE `entry`=14094;
UPDATE `quest_template` SET `RequestItemsText`="We must take out as many of them as we can, $N." WHERE `entry`=14218;
UPDATE `quest_template` SET `OfferRewardText`="Greymane's right.  These beasts do not give a damn about our politics.$B$BGilneas needs to stand together." WHERE `entry`=28850;
UPDATE `quest_template` SET `RequestItemsText`="What is it then, $N?" WHERE `entry`=24930;

-- Remove Rebel Valor aura when turning in Brothers In Arms (26126), not The Rebel Lord's Arsenal (14159);
UPDATE `quest_end_scripts` SET `id`=26129 WHERE `id`=14159;
UPDATE `quest_template` SET `CompleteScript`=26129 WHERE `entry`=26129;
UPDATE `quest_template` SET `CompleteScript`=0 WHERE `entry`=14159;

-- NPC Tower Scaling Vehicle Seat 01 (36716) should be invisible to players.
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=36716;

-- Damage multipliers that actually allow the quests related to those npcs completable by poor players.
UPDATE `creature_template` SET `dmg_multiplier` = 1 WHERE `entry` IN (36231, 36312);
UPDATE `creature_template` SET `dmg_multiplier` = 0.1 WHERE `entry` IN (35463, 36396);

-- There are too many mobs here after turning in the quest The Rebel Lord's Arsenal (14159), so many that players aren't able to survive.
DELETE FROM `creature` WHERE `guid` IN (15789923, 15789925, 15789929, 15789924, 15789932);