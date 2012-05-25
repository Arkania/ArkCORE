-- Quests update for Elwynn Forest
-- For Arkania
-- By Jorex



-- Update position of npc Brother Paxton (951), source WoW Retail
UPDATE creature SET position_x='-8822.09',position_y='-155.91',position_z='80.52',orientation='2.41' WHERE id='951';

-- Update class requirement for quest Fear No Evil (29082)
UPDATE quest_template SET SkillOrClassMask='-64' WHERE entry='29082';

-- Update position for Npc Milly Osworth (9296), source WoW Retail
UPDATE creature SET position_x='-8923.47',position_y='-135.71',position_z='80.97',orientation='1.45' WHERE id='9296';

-- Fix for the quest chain beginning with "A swift message" (26393) in Elwynn Forest
UPDATE quest_template SET RequestItemsText='You look like you''re in a hurry. Well, then you came to the right place!',OfferRewardText='You have to get this note to Stormwind? That''s not a problem, you can take one of my gryphons!' WHERE entry='26393';

UPDATE quest_template SET RequestItemsText='You''ve been traveling, eh? Have you been anywhere interesting?',OfferRewardText='Ah, a note from Smith Argus? I''m not surprised he needs more gear. There are so many new recruits these days.$B$BWell thank you, $N. Here''s some money to cover your travel costs.',QuestFlags='0',QuestLevel='7',Method='2',EndText='Buy a gryphon ride from the gryphon master Bartlett the Brave, then bring Argus Note to Osric Strang, in the shop Limited Immunity, in the Old Town of Stormwind.' WHERE entry='26394';

UPDATE quest_template SET RequestItemsText='Is that sweat on your brow, lad? You''ve been running too much. Next time, take a gryphon!',OfferRewardText='A crate for Goldshire, eh? People sure are getting lazy. Have you been to Goldshire before? If so, then it''s no problem, my friend. I have plenty of gryphons trained to fly that route!' WHERE entry='26395';

UPDATE quest_template SET RequestItemsText='You''re back from Stormwind? Did Osric send the armor?',OfferRewardText='Great, you brought the armor! We''ll get this divvied to those who need it immediately.$B$BThank you, $N. Your efforts have been a great help to us. And now that you''re no stranger to gryphons, I hope you''ll come and lend your aid to Goldshire often!' WHERE entry='26396';


-- Add missing texts for Elwynn Forest quests

UPDATE quest_template SET RequestItemsText='What do you have to report, $N? Have you been to the Fargodeep Mine?',OfferRewardText='This is bad news. What''s next, dragons?!? We''ll have to increase our patrols near that mine. Thanks for your efforts, $N. And hold a moment... I might have another task for you.' WHERE entry='62';

UPDATE quest_template SET RequestItemsText='Psst! You have that Gold Dust for me...for me?',OfferRewardText='Thanks for the dust, $N. Here''s your cash, and...here is a token from associates of mine. You might find it useful...useful.' WHERE entry='47';

UPDATE quest_template SET RequestItemsText='Did you gather those candles yet?',OfferRewardText='You were busy hunting kobolds, were you? Thanks for the candles, $B, and here''s your reward...' WHERE entry='60';

UPDATE quest_template SET RequestItemsText='Hail, $N. What do you have to report? Have you scouted the Jasperlode Mine?',OfferRewardText='Kobolds at the Jasperlode Mine, you say? Curses! The situation is worsening by the minute!$B$BThank you for the report, $N. But I wish that the news you brought was good news.' WHERE entry='76';

UPDATE quest_template SET RequestItemsText='That deadline isn''t getting any further away, $C. Please hurry and collect those bundles of wood.',OfferRewardText='Excellent! Thanks to you, I should be able to complete the order in time. To show my gratitude, I would like to offer some coin as compensation for your troubles.$B$BThank you and farewell.' WHERE entry='5545';

UPDATE quest_template SET RequestItemsText='Have you killed those wolves and bears?',OfferRewardText='Thanks a lot for the help, $N. Something in the forest must be making these animals so bold.$B$BWhatever it is, I hope it stays there.' WHERE entry='52';
UPDATE quest_template SET RequestItemsText='I''m running low on linen, $N. Do you have any for me?',OfferRewardText='Ah, these are nice scraps, if a little rough...$B$BHere you are!' WHERE entry='83';

UPDATE quest_template SET OfferRewardText='Marshall Dughan sent you, eh? Well you''re not from the army, but if Dughan sent you then that''s good enough for me!$B$BOur situation is, to say the least, a stressed one. I hope you can give us a hand.' WHERE entry='239';

UPDATE quest_template SET RequestItemsText='Hail, $N. Have you been killing Gnolls...?',OfferRewardText='I see you''ve been busy! You have our thanks, $N.' WHERE entry='11';

UPDATE quest_template SET OfferRewardText='He did WHAT?$B$BGreat, now we have a bloodthirsty beast right beneath the streets of Stormwind, with a whole army of gnolls at his command. Definitely an improvement, I feel safer already.$B$BHere''s your reward, $N. But promise me you''ll check in with the Stockades guards in Stormwind at some point, just to ensure that things are going smoothly.' WHERE entry='176';

UPDATE quest_template SET RequestItemsText='How goes the hunting, $N?',OfferRewardText='You have the fins? Great! Marshal Dughan is anxious about the Murloc situation in eastern Elwynn, and I''d like to tell him that it''s becoming under control.$B$BYour actions have helped realize that.' WHERE entry='46';

UPDATE quest_template SET RequestItemsText='Turning in a bounty?',OfferRewardText='And justice is served!' WHERE entry='26152';

UPDATE quest_template SET RequestItemsText='What?!? We haven''t had our people working the Elwynn mines for months!$B$BLet me see that note you have...',OfferRewardText='Hm... I have heard of this "Collector" but I don''t know whom he''s working for. Thank you for the schedule. It will help us solve this mystery.' WHERE entry='123';

UPDATE quest_template SET RequestItemsText='Did you find the Collector? Did you discover whom he''s working for?',OfferRewardText='You found him? Well done, $N. He won''t be "collecting" from the Elwynn Mines again!$B$BAnd this ring you found is interesting... it''s a membership ring for the old Stonemason''s Guild in Stormwind. I haven''t seen one of these in years, since back in the days when the Defias Brotherhood used to infest this land.' WHERE entry='147';

-- Duplicate npc, source wow retail
DELETE FROM creature WHERE guid='80855';

-- Delete npc not present in wow retail
DELETE FROM creature WHERE guid='6623286';
DELETE FROM creature WHERE guid='6623286';

-- Update loot_template for James Clarks (13159) to drop quest launching item Gold Pickup Schedule (1307), source WoW retail
UPDATE creature_loot_template SET ChanceOrQuestChance = '100',groupid='1' WHERE entry='13159' AND item='1307';


-- Add a gameobject "Bounty board" (203733), source WoW Retail
SET @GO_GUID_Bounty_board='89';
DELETE FROM gameobject WHERE id='203733';
INSERT INTO gameobject(guid,id,position_x,position_y,position_z,orientation,spawntimesecs) VALUES (@GO_GUID_Bounty_board,203733,-9613.166,-1033.3981,40.258,1.679,300);

-- Make the gameobject give quests "Bounty on Murlocs" (46) and "Wanted: James Clark" (26152), source WoW retail
DELETE FROM gameobject_questrelation WHERE id='203733';
INSERT INTO gameobject_questrelation VALUES
(203733,46),(203733,26152);

-- Create the gossip menu that gives the quests
SET @NPC_TEXT_ID='69';
DELETE FROM npc_text WHERE ID=@NPC_TEXT_ID;
INSERT INTO npc_text(ID,text0_1,prob0) VALUES (@NPC_TEXT_ID,'There are bounties on this board.',1);

SET @GOSSIP_MENU_ID='86';
DELETE FROM gossip_menu WHERE entry=@GOSSIP_MENU_ID;
INSERT INTO gossip_menu VALUES (@GOSSIP_MENU_ID,@NPC_TEXT_ID);

DELETE FROM gossip_menu_option WHERE menu_id=@GOSSIP_MENU_ID;
INSERT INTO gossip_menu_option(menu_id,id,option_id) VALUES (@GOSSIP_MENU_ID,1,2);

-- Update the gameobject template with the gossip menu created above
UPDATE gameobject_template SET data3=@GOSSIP_MENU_ID where entry='203733';