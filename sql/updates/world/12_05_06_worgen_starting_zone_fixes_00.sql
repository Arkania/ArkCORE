-- More fixes for Worgen starting zone.
-- By Nanaki for Arkania.

-- RequestItemsText.
UPDATE `quest_template` SET `RequestItemsText`="You're back, $N. Have the spiders been taken care of?" WHERE `entry`=24484;
UPDATE `quest_template` SET `RequestItemsText`="Any luck finding those pages?" WHERE `entry`=24495;
UPDATE `quest_template` SET `RequestItemsText`="Did you take care of Rygna, $N?" WHERE `entry`=24501;
UPDATE `quest_template` SET `RequestItemsText`="Is it done, $N?" WHERE `entry`=24616;
UPDATE `quest_template` SET `RequestItemsText`="You're back, $N." WHERE `entry`=24627;
UPDATE `quest_template` SET `RequestItemsText`="You've returned, $N." WHERE `entry`=24628;
UPDATE `quest_template` SET `RequestItemsText`="Do you have the scythe, $N?" WHERE `entry`=24646;

-- OfferRewardText.
UPDATE `quest_template` SET `OfferRewardText`="It's good to see you made it, $N. It looks like most everybody did.$B$BWe're not doing too bad so far for an emergency evacuation." WHERE `entry`=24483;
UPDATE `quest_template` SET `OfferRewardText`="Thank you, $N.  It will take some time, but I'll try to make sense of what we have." WHERE `entry`=24495;
UPDATE `quest_template` SET `OfferRewardText`="You've done well, $N.  The spiders are everywhere, however, and I'm afraid we've barely put a dent in their numbers." WHERE `entry`=24484;
UPDATE `quest_template` SET `OfferRewardText`="Great job, $N. We've heard rumors of survivors further in the mountains. Now we'll be able to send scouts there." WHERE `entry`=24501;
UPDATE `quest_template` SET `OfferRewardText`="I've been expecting you, $N. Do not be alarmed.$B$BMy name is Belrysa. I am a priestess of the moon... a night elf.$B$BYou might not know my people, but the destinies of our two races have been linked since the Curse befell you." WHERE `entry`=24578;
UPDATE `quest_template` SET `OfferRewardText`="Well done, $N.  The scout never had a chance." WHERE `entry`=24616;
UPDATE `quest_template` SET `OfferRewardText`="You're all right, $N!  I've been waiting for this day for a long time, it truly is great to see you friend.$B$BI've heard of what you've done and I'm thankful... especially for Lorna -- she's all I've left.  I will send for her right away." WHERE `entry`=24617;
UPDATE `quest_template` SET `OfferRewardText`="You are as good as I remember, $N.  It is good to have you back." WHERE `entry`=24627;
UPDATE `quest_template` SET `OfferRewardText`="These simple leaves grow by Elune's grace.  They will help your mind understand the need for balance and your soul will permanently earn mastery over the beast." WHERE `entry`=24628;

-- CompletedText.
UPDATE `quest_template` SET `CompletedText`="" WHERE `entry` IN (24484, 24501, 24616, 24627, 24628);

-- RewSpellCast -> RewSpellHiddenCast.
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=71042 WHERE `entry`=24627;

-- Moonleaf is a quest item.
UPDATE `gameobject_loot_template` SET ChanceOrQuestChance="-100" WHERE `item`=50017;