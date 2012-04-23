-- More quest fixes for Worgen starting zone.
-- By Nanaki for Arkania.

-- Lockdown!
UPDATE `quest_template` SET `Details`="What are you still doing here, citizen? Haven't you heard? The city's under complete lockdown.$B$BGo see Lieutenant Walden -- he'll give you further directions for evacuation." WHERE `entry`=14078;

-- All Hell Breaks Loose
UPDATE `quest_template` SET `Details`="$R! My father had warned me that Archmage Arugal's creations had run amok.$B$BBut where are they coming from?$B$BI suppose it doesn't matter. Help us make quick work of them. We'll show them what we Gilneans are made of!", `OfferRewardText`="It's no use, $N! They're not letting up.", `QuestFlags`=524288, `SpecialFlags`=4, `SoundAccept`=890, `SoundTurnIn`=878 WHERE `entry`=14093;

-- Evacuate the Merchant Square
UPDATE `quest_template` SET `RequestItemsText`="Have you succeeded, $N?" WHERE `entry`=14098;

-- Eviscerate (Worgen Rogue)
UPDATE `quest_template` SET `RequestItemsText`="Don't get ahead of yourself now.  Just remember who taught you everything you know.$N$NAnd now let's see if we can get out of this city with our skins attached." WHERE `entry`=14272; -- Not exactly sure about this, but still better than nothing.

-- Steady Shot (Worgen Hunter)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`=35118, `ReqCreatureOrGOCount1`=2, `ReqSpellCast1`=56641 WHERE `entry`=14276;

-- Arcane Missiles (Worgen Mage)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`=35118, `ReqCreatureOrGOCount1`=1, `ReqSpellCast1`=5143 WHERE `entry`=14281;

-- Flash Heal (Worgen Priest)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`=47091, `ReqCreatureOrGOCount1`=2, `ReqSpellCast1`=2061 WHERE `entry`=14279;

-- Immolate (Worgen Warlock)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`=35118, `ReqCreatureOrGOCount1`=1, `ReqSpellCast1`=348 WHERE `entry`=14274;