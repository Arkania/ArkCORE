-- Various quest texts. Some taken from Wowhead, some from retail.
-- By Nanaki for Arkania.

-- RequestItemsText
UPDATE `quest_template` SET `RequestItemsText`="Greetings, $N." WHERE `entry`=1582;
UPDATE `quest_template` SET `RequestItemsText`="Were you able to find the falls?" WHERE `entry`=26536;
UPDATE `quest_template` SET `RequestItemsText`="Have you beaten back the Blackrock battle worgs?" WHERE `entry` IN (28757, 28762, 28763, 28764, 28765, 28766, 28767, 29078);
UPDATE `quest_template` SET `RequestItemsText`="Kill the spies!" WHERE `entry` IN (28759, 28769, 28770, 28771, 28772, 28773, 28774, 29079);
UPDATE `quest_template` SET `RequestItemsText`="Well, did you give it a try?" WHERE `entry` IN (26913, 26914, 26915, 26916, 26917, 26918, 26919);
UPDATE `quest_template` SET `RequestItemsText`="Kill the goblin assassins!" WHERE `entry` IN (28791, 28792, 28793, 28794, 28795, 28796, 28797, 29081);
UPDATE `quest_template` SET `RequestItemsText`="Rescue our soldiers!" WHERE `entry` IN (28806, 28808, 28809, 28810, 28811, 28812, 28813, 29082);
UPDATE `quest_template` SET `RequestItemsText`="Have you put out the fires?" WHERE `entry`=26391;
UPDATE `quest_template` SET `RequestItemsText`="Did you see her yet?  Did you get her?" WHERE `entry`=88;
UPDATE `quest_template` SET `RequestItemsText`="I don't think it's right feeding the boy who stole my necklace in the first place, but if that's what it takes to get back what's mine, then so be it!$B$BDo you have that boar meat?" WHERE `entry`=86;
UPDATE `quest_template` SET `RequestItemsText`="Farming is thirsty work, and I'm always looking for refreshing spring water.$B$BIf you have any, then I'm willing to make a trade." WHERE `entry`=16;
UPDATE `quest_template` SET `RequestItemsText`="Ugh... I'm starving!  Do you have that pie for me, $N?" WHERE `entry`=84;
UPDATE `quest_template` SET `RequestItemsText`="Hello, $N.  Have you found my necklace?" WHERE `entry`=87;
UPDATE `quest_template` SET `RequestItemsText`="Were you able to find my locket?" WHERE `entry`=26488;
UPDATE `quest_template` SET `RequestItemsText`="You must have fast hands!  I can't believe you caught all those crabs so quickly!" WHERE `entry`=26177;

-- OfferRewardText
UPDATE `quest_template` SET `OfferRewardText`="Yes, these are good pieces. You have a skilled hand and an eye for detail. Your future as a leatherworker is promising.$B$BHere, $N. Let me show you the pattern to make the Moonglow Vest." WHERE `entry`=1582;
UPDATE `quest_template` SET `OfferRewardText`="These perch look great $N.  Why don't you join us for a fish fry tonight?" WHERE `entry`=26536;
UPDATE `quest_template` SET `OfferRewardText`="You lost a what?  Well I didn't take no necklace, because I ain't no thief!$B$BI might know who did but...<grin>...I'm too hungry to remember." WHERE `entry`=85;
UPDATE `quest_template` SET `OfferRewardText`="Though this wild boar meat is tough, simmer it enough and it sure does make for some tasty pie!" WHERE `entry`=86;
UPDATE `quest_template` SET `OfferRewardText`="Thanks, $N!  And come back if you want to trade again." WHERE `entry`=16;
UPDATE `quest_template` SET `OfferRewardText`="Thank goodness!  That pig was getting so big she'd have eaten our whole crop!  Thank you, $N.$B$BNow, do any of these suit you?" WHERE `entry`=88;
UPDATE `quest_template` SET `OfferRewardText`="Mm, yum!  This pie is the best!$B$BI think my memory is coming back to me..." WHERE `entry`=84;
UPDATE `quest_template` SET `OfferRewardText`="Oh, you found it!  Thank you, thank you dear!$B$BHere, take this.  It was my husband's and he always said it was lucky.  If only he didn't forget it on his last campaign! *sniff*" WHERE `entry`=87;
UPDATE `quest_template` SET `OfferRewardText`="You were busy hunting kobolds, were you? Thanks for the candles, $N, and here's your reward..." WHERE `entry`=60;
UPDATE `quest_template` SET `OfferRewardText`="You found it!  I can't believe it was down there all those years!  You have no idea how much this means to me $N." WHERE `entry`=26488;
UPDATE `quest_template` SET `OfferRewardText`="These crabs look great!  I will clean these up and make sure that the King hears about your contribution.  Thanks!" WHERE `entry`=26177;