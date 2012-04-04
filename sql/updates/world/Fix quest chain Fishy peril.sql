-- Fix Quest chain "A fishy peril"
-- For Arkania
-- By Jorex

-- Update quests "Find the lost guards" (37) and "Discover Rolf's Fate" for transition between the two

UPDATE quest_template SET PrevQuestId='37' WHERE entry = '45';
UPDATE quest_template SET NextQuestInChain='45' WHERE entry = '37';

-- Add quest relation for gameobject "A half-eaten body" (55) to trigger quest 45

INSERT INTO gameobject_questrelation
VALUES (55,45);

-- Add quest relation for gameobject "Rolf's corpse" (56) to end quest 45 and trigger quest 71

INSERT INTO gameobject_involvedrelation
VALUES (56,45);

INSERT INTO gameobject_questrelation
VALUES (56,71);


-- Update quest template to add missing texts for the quest chain

UPDATE quest_template SET OfferRewardText='Yes, I spoke with Remy.  I respect him as a merchant, though all reports of Murlocs to the east have been sketchy at best. $B $B Your concerns are noted, but unless I receive a military report of a murloc threat, we can''t afford to send more troops east.' WHERE entry = '40';

UPDATE quest_template SET OfferRewardText='Yes, murlocs have settled in and around the streams of eastern Elwynn.  We don''t know why they are here, but they are aggressive and at least semi-intelligent.' WHERE entry='35';

UPDATE quest_template SET OfferRewardText='Although much has been stripped from the corpse, strewn nearby is a medallion with the words: "Footman Malakai Stone" etched upon it.' WHERE entry='37';

UPDATE quest_template SET OfferRewardText='You find around the neck of the corpse a metal medallion inscribed with the words "Footman Rolf Hartford."' WHERE entry='45';

UPDATE quest_template SET OfferRewardText='You have confirmed my fears, $N.  The murlocs are a threat we cannot ignore.',RequestItemsText='Hello, $N.  Have you discovered the fates of Rolf and Malakai?' WHERE entry='71';

UPDATE quest_template SET OfferRewardText='Ah, thank you for the marker.  Please feel free to pick your choice of armor.$B$BLuck to you, brave $C.  And may this armor serve you well.',RequestItemsText='I have been commissioned by the Stormwind Army to supply their people with cloth and leather armor.$B$BIf you have a marker for me, then I''d be happy to make you something.' WHERE entry='59';
