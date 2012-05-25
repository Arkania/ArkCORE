-- More fixes for quests in Worgen starting zone.
-- By Nanaki for Arkania.

UPDATE gameobject_loot_template SET ChanceOrQuestChance = "-100" WHERE entry = 195306 AND item = 46896; -- Quest item (46896) shouldn't be lootable without having the quest (14094).

UPDATE quest_template SET RewSpellCast = 0, RewSpellHiddenCast = 68639, Details = "I need you to pull through, $N. This dosage is strong enough to kill a horse.$B$BBut I know you. I know what you're made of. You will be fine.$B$BTrust me. I know what you're going through.$B$BNow drink up and close your eyes." WHERE entry = 14375; -- Last Chance at Humanity
UPDATE quest_template SET OfferRewardText="Forsaken!  Quick, $N!  We must mount a defense." WHERE entry = 14321; -- Invasion
UPDATE quest_template SET OfferRewardText="$N!!! You ARE alive!$B$BI thought I was having dreams about the old days when I heard your voice..." WHERE entry = 14336; -- Kill or Be Killed
UPDATE quest_template SET OfferRewardText="Yes, $N! Just like old times...$B$BI'm going to have to work hard at not shooting you, but Krennan explained everything to us." WHERE entry = 14347; -- Hold the Line
UPDATE quest_template SET OfferRewardText="You and me, $N.  We make a great team...$B$BIt's good to have you back." WHERE entry = 14348; -- You Can't Take 'Em Alone
UPDATE quest_template SET OfferRewardText="Great news, $N. I've sent the remaining militia to the shore to meet the Forsaken force head on." WHERE entry = 14366; -- Holding Steady
UPDATE quest_template SET OfferRewardText="The Forsaken are here in full strength, $N.  We barely have enough men to hold them back." WHERE entry = 14367; -- The Allens' Storm Cellar
UPDATE quest_template SET OfferRewardText="My children are safe! You've done a wonderful thing, $N. I don't know how to thank you!" WHERE entry = 14368; -- Save the Children!
UPDATE quest_template SET OfferRewardText="Well done, $N. You might be a bloody beast, but you're our beast." WHERE entry = 14382; -- Two By Sea
UPDATE quest_template SET OfferRewardText="Not bad, $N. It's a good thing you're on our side." WHERE entry = 14369; -- Unleash the Beast
UPDATE quest_template SET OfferRewardText="You did it, $N. That should take the wind out of their sails." WHERE entry = 14386; -- Leader of the Pack
UPDATE quest_template SET OfferRewardText="The ocean, $N. It swallowed everything... the land... the Forsaken... our men!" WHERE entry = 14396; -- As the Land Shatters
UPDATE quest_template SET OfferRewardText="You did what you could, $N. With any luck a few others will find their way to shore." WHERE entry = 14395; -- Gasping for Breath
UPDATE quest_template SET OfferRewardText="Liam is right. We must get everyone to higher ground.$B$BYou must help me spread the word while I manage the logistics of the evacuation." WHERE entry = 14397; -- Evacuation
UPDATE quest_template SET OfferRewardText="A visitor! Are you staying for tea, sweetheart?" WHERE entry = 14398; -- Grandma Wahl
UPDATE quest_template SET OfferRewardText="Why thank you, $N. I hope you didn't peek!$B$BWhere are your manners, dear?" WHERE entry = 14399; -- Grandma's Lost It Alright
UPDATE quest_template SET OfferRewardText="You're a peach, $N! Thanks!" WHERE entry = 14400; -- I Can't Wear This
UPDATE quest_template SET OfferRewardText="There he is! Grandma's special boy!$B$BThank you so much for finding him. I hope it wasn't too much trouble.$B$BMy... what manner of dirt found its way underneath my fingernails!" WHERE entry = 14401; -- Grandma's Cat
UPDATE quest_template SET OfferRewardText="You did the impossible, $N. You convinced Grandma Wahl to leave her home.$B$BYou are something else, let me tell you." WHERE entry = 14402; -- Ready to Go
UPDATE quest_template SET OfferRewardText="You here to give us a hand?" WHERE entry = 14403; -- The Hayward Brothers
UPDATE quest_template SET OfferRewardText="This is great, $N. I should be able to finish the repairs in no time." WHERE entry = 14404; -- Not Quite Shipshape
UPDATE quest_template SET OfferRewardText="Excellent! I'm almost done here." WHERE entry = 14412; -- Washed Up
UPDATE quest_template SET OfferRewardText="It's just as well, $N. Maybe the Haywards will fare better than us." WHERE entry = 14405; -- Escape By Sea
UPDATE quest_template SET OfferRewardText="Stay back! Don't make me...$B$BIs it you? By the Light! It's you, $N!" WHERE entry = 14406; -- The Crowley Orchard
UPDATE quest_template SET OfferRewardText="We've got the horses, I'll make sure Duskhaven gets them." WHERE entry = 14416; -- The Hungry Ettin
