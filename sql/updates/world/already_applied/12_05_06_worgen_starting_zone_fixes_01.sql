-- Last (probably) bunch of fixes for Worgen starting zone.
-- By Nanaki for Arkania.

-- RequestItemsText.
UPDATE `quest_template` SET `RequestItemsText`="It is always good to see you, $Gbrother:sister;." WHERE `entry`=24593;
UPDATE `quest_template` SET `RequestItemsText`="Careful, $N." WHERE `entry`=24592;
UPDATE `quest_template` SET `RequestItemsText`="Have you freed the villagers, $N? I cannot imagine what duress they're enduring under the Forsaken." WHERE `entry`=24575;
UPDATE `quest_template` SET `RequestItemsText`="Did you get what I needed, $N?" WHERE `entry`=24675;
UPDATE `quest_template` SET `RequestItemsText`="Is it done?" WHERE `entry`=24674;
UPDATE `quest_template` SET `RequestItemsText`="You're back, $N." WHERE `entry`=24676;
UPDATE `quest_template` SET `RequestItemsText`="No..." WHERE `entry`=24904;
UPDATE `quest_template` SET `RequestItemsText`="Did you find her, $N?" WHERE `entry`=24902;
UPDATE `quest_template` SET `RequestItemsText`="Is it done, $N?" WHERE `entry`=24920;
UPDATE `quest_template` SET `RequestItemsText`="You're back, $N." WHERE `entry`=24602;
UPDATE `quest_template` SET `RequestItemsText`="Is it done, $N?" WHERE `entry`=24679;
UPDATE `quest_template` SET `RequestItemsText`="You're back!" WHERE `entry`=24681;
UPDATE `quest_template` SET `RequestItemsText`="The only risks worth taking are the ones that lead to victories worth having." WHERE `entry`=26706;

-- OfferRewardText.
UPDATE `quest_template` SET `OfferRewardText`="I knew we could count on you.  You've done well, $N." WHERE `entry`=24646;
UPDATE `quest_template` SET `OfferRewardText`="It is done then, $N. You are one of us now." WHERE `entry`=24593;
UPDATE `quest_template` SET `OfferRewardText`="King Greymane gave me a brief rundown of the plan before he set off for the Blackwald.  Doesn't make it sound any less crazy." WHERE `entry`=24673;
UPDATE `quest_template` SET `OfferRewardText`="$N!$B$BGenn... they've taken Genn... they've taken... our king!" WHERE `entry`=24672;
UPDATE `quest_template` SET `OfferRewardText`="I wish it could've been avoided, $N.  Let us ensure this is resolved without further bloodshed." WHERE `entry`=24592;
UPDATE `quest_template` SET `OfferRewardText`="You've done it again, <name>. The freed villagers are eager to help us against the Forsaken in any way they can." WHERE `entry`=24575;
UPDATE `quest_template` SET `OfferRewardText`="I thank you, $N.  Our men and women will have a last good meal before they set off for battle." WHERE `entry`=24675;
UPDATE `quest_template` SET `OfferRewardText`="I thank you, $N. Our people will no longer suffer under that monstrosity's yolk." WHERE `entry`=24674;
UPDATE `quest_template` SET `OfferRewardText`="We have the people of Emberstone on our side now thanks to you." WHERE `entry`=24676;
UPDATE `quest_template` SET `OfferRewardText`="We've driven the Forsaken back. We hold three out of the four districts.$B$BBut at what cost..." WHERE `entry`=24904;
UPDATE `quest_template` SET `OfferRewardText`="The Plague? Something so heinous that not even the orcs condone its use? I'd say this warrants notifying King Greymane." WHERE `entry`=24902;
UPDATE `quest_template` SET `OfferRewardText`="You present me with the most difficult choice of my life, $N." WHERE `entry`=24903;
UPDATE `quest_template` SET `OfferRewardText`="You've done well, $N. Almost everybody managed to make it through." WHERE `entry`=24920;
UPDATE `quest_template` SET `OfferRewardText`="You're here, $N.  Most everyone made it through, but now we're stuck here... surrounded by our own... dead!" WHERE `entry`=24678;
UPDATE `quest_template` SET `OfferRewardText`="Thank you, $N.  Let us hope this works." WHERE `entry`=24602;
UPDATE `quest_template` SET `OfferRewardText`="It's done, $N. The dead return to their slumber." WHERE `entry`=24679;
UPDATE `quest_template` SET `OfferRewardText`="It's good to see you again, $N." WHERE `entry`=24680;
UPDATE `quest_template` SET `OfferRewardText`="It's almost over, $N. Only one obstacle remains between us and survival." WHERE `entry`=24681;
UPDATE `quest_template` SET `OfferRewardText`="We did it, $N. We've started the evacuation. If we leave soon we'll leave the Forsaken fleet in the dust." WHERE `entry`=26706;
UPDATE `quest_template` SET `OfferRewardText`="Are you ready to set sail, $N? Your people have been granted shelter in the lands of the kaldorei.$B$BDo not worry, $R. Your people will get a chance to fight for Gilneas again. This time, with the full strength of the Alliance." WHERE `entry`=14434;

-- CompletedText.
UPDATE `quest_template` SET `CompletedText`="" WHERE `entry` IN (24593, 24592, 24676, 24920);

-- Details.
UPDATE `quest_template` SET `Details`="Are you ready to set sail, $N?  Your people have been granted shelter in the lands of the kaldorei.$B$BDo not worry, $R.  Your people will get a chance to fight for Gilneas again.  This time, with the full strength of the Alliance." WHERE `entry`=14434;

-- RewSpellCast -> RewSpellHiddenCast.
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=72829 WHERE `entry`=24593;
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=81040 WHERE `entry`=24681;
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=95840 WHERE `entry`=26706;
UPDATE `quest_template` SET `RewSpellCast`=0, `RewSpellHiddenCast`=78107 WHERE `entry`=14434;

-- Teleport players to next quest when turning in The Battle for Gilneas City.
UPDATE quest_template SET CompleteScript=24904 WHERE entry=24904;
INSERT INTO quest_end_scripts VALUES (24904, 2, 6, 654, 0, 0, -1675.20, 1610.68, 20.48, 5.53);

-- Quests needing vehicle/too complex to fix, for the time being set them to autocomplete.
UPDATE `quest_template` SET `ReqCreatureOrGOId1`=0, `ReqCreatureOrGOId2`=0, `ReqCreatureOrGOCount1`=0, `ReqCreatureOrGOCount2`=0 WHERE entry=24920;
UPDATE `quest_template` SET `ReqCreatureOrGOId1`=0, `ReqCreatureOrGOId2`=0, `ReqCreatureOrGOId3`=0, `ReqCreatureOrGOCount1`=0, `ReqCreatureOrGOCount2`=0, `ReqCreatureOrGOCount3`=0 WHERE entry=24681;

-- Too many creatures for quest Push Them Out (a lot of double-spawns).
DELETE FROM creature WHERE guid IN (6677286, 6677283, 6677290, 6654160, 6654159, 6677532, 6654161, 6677531, 6677272, 6677265, 6677285, 6677275);
DELETE FROM waypoint_data WHERE id IN (6677286, 6677283, 6677290, 6677532, 6677531, 6677272, 6677265, 6677285, 6677275);