-- Another bunch of fixes for Worgen starting zone.
-- By Nanaki for Arkania.

-- Fix skinning loot for Fox (was giving too many leathers).
UPDATE skinning_loot_template SET maxcount=1 WHERE `entry`=36512;

-- Tune down damage for some creatures.
UPDATE creature_template SET dmg_multiplier=0.1 WHERE `entry` IN (35627, 41015, 36397, 36399, 37884, 36460);
UPDATE creature_template SET dmg_multiplier=0.3 WHERE `entry`=36312;

-- Fix health for Frenzied Stalker.
UPDATE creature_template SET Health_mod=1 WHERE `entry`=35627;

-- RequestItemsText.
UPDATE `quest_template` SET `RequestItemsText`="I... I don't know if I can go on without them." WHERE `entry`= 14368;
UPDATE `quest_template` SET `RequestItemsText`="You're back, $N. How's the situation outside?" WHERE `entry`= 14382;
UPDATE `quest_template` SET `RequestItemsText`="Did you take care of the Forsaken scum, $N?" WHERE `entry`=14369;
UPDATE `quest_template` SET `RequestItemsText`="Is it done yet, $N?" WHERE `entry`=14386;
UPDATE `quest_template` SET `RequestItemsText`="There aren't many of us left, $N. We have to look out for those remaining Gilneans." WHERE `entry`=14395;
UPDATE `quest_template` SET `RequestItemsText`="How goes it, dear? Will you be staying for tea?" WHERE `entry`=14399;
UPDATE `quest_template` SET `RequestItemsText`="Did you find everything okay, dear?" WHERE `entry`=14400;
UPDATE `quest_template` SET `RequestItemsText`="You're such a charming young $Gman:woman;, $N." WHERE `entry`=14401;
UPDATE `quest_template` SET `RequestItemsText`="Do you have my supplies, $N?" WHERE `entry`=14404;
UPDATE `quest_template` SET `RequestItemsText`="Bloody Forsaken! Not even the ocean wants them." WHERE `entry`=14412;
UPDATE `quest_template` SET `RequestItemsText`="How did it go, $N?" WHERE `entry`=24472;
UPDATE `quest_template` SET `RequestItemsText`="Were any of the passengers still alive?" WHERE `entry`=24468;

-- OfferRewardText.
UPDATE `quest_template` SET `OfferRewardText`="$N.  I've heard much about you.$B$BI understand you were crucial in my family's survival during the outbreak in Gilneas City." WHERE `entry`=14465;
UPDATE `quest_template` SET `OfferRewardText`="There you are, $N. I've been expecting you.$B$BI got word of your recovery and... wait -- do you feel that?" WHERE `entry`=14466;
UPDATE `quest_template` SET `OfferRewardText`="Look, $N!  Look at what's become of Duskhaven!$B$BLook at what's become of the last safe place in Gilneas!" WHERE `entry`=14467;
UPDATE `quest_template` SET `OfferRewardText`="Thanks for stopping, $N.  Our carriage got hit pretty bad.$B$BThe one in front of us got it worse." WHERE `entry`=24438;
UPDATE `quest_template` SET `OfferRewardText`="You've done it again, $N. You have my thanks." WHERE `entry`=24468;
UPDATE `quest_template` SET `OfferRewardText`="You definitely got the ettin angry, $N.   I heard him myself.$B$BLet's hope this works." WHERE `entry`=24472;

-- CompletedText.
UPDATE `quest_template` SET `CompletedText`="" WHERE `entry`=14395;

-- RewSpellCast -> RewSpellHiddenCast.
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=69027 WHERE `entry`=14386;
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=82892 WHERE `entry`=14465;
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=68954 WHERE `entry`=14466;
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=69257 WHERE `entry`=14467;
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=95679 WHERE `entry`=24438;
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=95840 WHERE `entry`=24472;
