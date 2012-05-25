-- Fix Quests in Dun Morogh (missing texts and some bugs)
-- For Arkania
-- By Jorex

-- Missing quest texts for "Hold the Line!" (24469)
UPDATE quest_template SET RequestItemsText='How many of ''em did ya get?',OfferRewardText='Impressive work, $Gladdie:lass. We can hold the perimeter from here on out.$B$BHere, take this for yer troubles. It might come in handy, as I''ve got something more important to ask of ye...' WHERE entry='24469';


-- Missing quest texts for "Give 'em What-For" (24470)
UPDATE quest_template SET RequestItemsText='Well, what''re ye waitin'' for, $C?',OfferRewardText='Hm... they blame us for destryoying their home, ye say? Well, that wasn''t us, that was the horrible earthquake we had earlier today. Are they that dense that they can''t see we nearly lost our camp too?$B$BCan''t blame a trogg for fightin'' for his home, though.' WHERE entry='24470';


-- Missing quest texts for "Aid for the Wounded" (24471)
UPDATE quest_template SET RequestItemsText='Thanks for yer help, $N.',OfferRewardText='Many of those that y''saved have already made it back to camp. The wounds''re well-dressed! Ye might have a future in first aid, if ye''re into that sorta thing.' WHERE entry='24471';


-- Missing quest texts for "Arcane Rune" (24496)
UPDATE quest_template
SET RequestItemsText='I see that Jona''s given you my runic message.  Do you still have it with you?',OfferRewardText='The power of the arcane is everywhere, $N.  Only some of us have the ability to see it, and fewer still possess the ability to master it.$B$BYou are one of those few.'
WHERE entry='24496' ;

-- Missing quest texts for "Filling Up the Spellbook" (24526)
UPDATE quest_template SET OfferRewardText='There we go!  One spell down, many many more to go.  Come back to me after you''ve had some experience casting this spell, and I''ll show you some more tricks.' WHERE entry='24526';


-- Missing quest texts for "Hallowed Rune" (3110)
UPDATE quest_template SET RequestItemsText='Ach! Ya made it, $N! Wonderful!$B$BI was gonna say, I was about to lose faith that ye''d arrive at all... get it, lose faith? It''s a joke, lad... aww, nevermind. Ya didn''t come here for me bad jokes anyway.',OfferRewardText='I''m the one who can train ya as you start to find your way around Coldridge Valley. When ya feel yer ready, come back to me and we''ll see about maybe teaching you a new spell or two to fend off the valley from them blasted troggs.$B$BYa got the Light on yer side, along with all of Ironforge, $N... no pressure on ya to become somethin'' special.' WHERE entry='3110';

-- Missing quest texts for "Words of Power" (24533)
UPDATE quest_template SET OfferRewardText='Well done, $N.  You''ll make a fine $C in due time.$B$BReturn to me after you''ve proven yourself a bit more, and I''ll reward you by teaching you another spell or two.' WHERE entry='24533';


-- Missing quest texts for "Consecrated Rune" (3107)
UPDATE quest_template SET RequestItemsText='So, you''ve made it! And not a second too soon. There''s much to be done in Coldridge Valley and beyond. I''m gonna need your help as much as you''re gonna need mine!$B$BYou''re a Knight of the Silver Hand now, be ready to play the part.',OfferRewardText='The humans have taught us a great deal about the Holy Light and how important their order is to them... and to protecting all of Azeroth. We have a great respect for how it is steeped in tradition, and how just one figure, one sacrifice, can make the difference between pain and salvation.$B$BThe two of us are gonna be working together for a bit.' WHERE entry='3107';

-- Missing quest texts for "The Power of the Light" (24528)
UPDATE quest_template SET OfferRewardText='There, ya did it.  The Light favors quick learners like you.  Come back to me after you''ve spent some time using what I''ve taught ya, and I''ll show ya something new.' WHERE entry='24528';


-- Missing quest texts for "Empowered Rune" (24494)
UPDATE quest_template SET RequestItemsText='The sprits have forewarned me of your arrival, $N.  Have you heard them too?',OfferRewardText='These are dark days, friend.  Look around you... even here in remote Coldridge, the sprits are rebelling.  The land is crying out for help.  Yet still, even in times such as these, the spirits will always turn an ear to those who ask for their assistance.' WHERE entry='24494';

-- Missing quest texts for "Your Path Begins Here" (24527)
UPDATE quest_template SET OfferRewardText='This has been but one of many footfalls on the long path of the $C.  Come back to me after you''ve had some experience in the field, and I will help guide you on your next step.' WHERE entry='24527';


-- Missing quest texts for "Encrypted Rune" (3109)
UPDATE quest_template SET RequestItemsText='You made it! Great!$B$BWe''ve got an influx of activity lately, so I''m glad to count another of the Ironforge clan among our numbers. Nothin'' like a cold blade in your hand and a shadow to keep you one step ahead, and if you''re here, you know exactly what I mean!',OfferRewardText='Anyway, as you start peekin'' around Coldridge you''ll probably have need of training at some point. You just come back to me whenever you feel you need it and I''ll teach you what I know--a trick here, a maneuver there. You know, the stuff that keeps you alive and makin'' a little extra coin.' WHERE entry='3109';

-- Missing quest texts for "Evisceratin' the Enemy" (24532)
UPDATE quest_template SET OfferRewardText='You''ve got the hang of it.  Go get some practice out there... maybe take out a few of those troggs or trolls.  Or rabbits, I don''t care.$B$BReturn after you''ve gotten some practice, and I''ll show you another trick of the trade.' WHERE entry='24532';


-- Missing quest texts for "Etched Rune" (3108) and follow-up quest "Oh, A Hunter's Life For Me" (24530)
UPDATE quest_template SET RequestItemsText='Ya made it! Good to hear! Betcha didn''t have to track me to find the place either. Haha!',OfferRewardText='One thing you should always remember is that you gotta respect the world you''re livin'' in. The beasts that choose to fight along side you; the shine of your weapon; the weight of your ammo; the bite of a bitter wind; all these things you need to know intimately.',NextQuestId='24530' WHERE entry='3108';

-- Missing quest texts for "Oh, A Hunter's Life For Me" (24530)
UPDATE quest_template SET OfferRewardText='Now that ye''ve got a new $C trick under yer belt, and now that I''ve got some of yer money, go out there an'' track some beasts!  Come back sometime in the future, an'' we''ll talk again.' WHERE entry='24530';


-- Missing quest texts for "Tainted Rune" (3115) and follow-up quest "Harnessing the Flames" (26904)
UPDATE quest_template SET RequestItemsText='Wonderful! You obviously got my rune.$B$BIgnore the fools around you, $N. The Holy Light?! The sword and shield?! These aren''t paths for ones as open minded as us.',OfferRewardText='But none of that matters. What matters is that you''ve seen your own Holy Light! You know where power truly comes from. You realize that having our own allies is much more... prudent. Special allies. Allies that, no matter the task, will obey till their last breath.$B$BAnd that''s where I come in, $N. I can train you in the beginnings of those special powers. Seek me out often and I will do what I can to teach you more spells.',NextQuestId='26904' WHERE entry='3115';

-- Missing quest texts for "Harnessing the Flames" (26904)
UPDATE quest_template SET OfferRewardText='As you continue to gain power, return to me and I will teach you new spells and techniques.' WHERE entry='26904';


-- Missing quest texts for "Simple Rune" (3106)
UPDATE quest_template SET RequestItemsText='Blast it''s cold today, ain''t it? It''s like the snow never goes away, $N.',OfferRewardText='If you look around, you''ll see a few interesting things: dwarves using magic in a fight instead of a rifle. Some of us have taken to worshipping the Holy Light like some of the humans, and, last but not least, troggs. You''ll learn more about them later, but what you need to know now is that I''m here to help you.' WHERE entry='3106';

-- Missing quest texts for "Getting Battle-Ready" (24531)
UPDATE quest_template SET OfferRewardText='Now we''re getting somewhere.  You''ve got quite a manly bellow, sir!$B$BCome back to me in a bit, and I''ll teach you something else.' WHERE entry='24531';


-- Missing quest texts for "Lockdown in Anvilmar" (24473)
UPDATE quest_template SET OfferRewardText='Ach... and what do YOU want? Can''t ye see I''m busy in here! Go an'' bother someone else, I haven''t the time.$B$BWait, what''s that ye say? Joren sent you to help? Well why didn''t ye say so?' WHERE entry='24473';


-- Missing quest texts for "First Things First: We're Gonna Need Some Beer" (24474)
UPDATE quest_template SET RequestItemsText='The ale, darling, the ale!',OfferRewardText='<Jona drinks deeply from the Gnomenbrau.>$B$BAhh... that hits the spot. Now we can get some work done around here.' WHERE entry='24474';


-- Missing quest texts for "Dwarven Artifacts" (24477)
UPDATE quest_template SET RequestItemsText='Yes?',OfferRewardText='Wonderful! Look at this one... it must be over 200 years old!$B$BNow, onto other matters...' WHERE entry='24477';


-- Missing quest texts for "All the Other Stuff" (24475)
UPDATE quest_template SET RequestItemsText='The people are gettin'' restless. D''ye have the supplies yet?',OfferRewardText='This''ll have to do for now. We''ve a lot of people to feed here, but we''ve got to make do with what we''ve got. With any luck, King Bronzebeard in Ironforge will send us some help shortly.' WHERE entry='24475';


-- Missing quest texts for "Make Hay While the Sun Shines" (24486)
UPDATE quest_template SET RequestItemsText='Did you manage to pry any artifacts away from the troggs?',OfferRewardText='Well, would you look at this! An axe blade, a couple of arrowheads, and what appears to be some sort of rudimentary spoon. This is indeed fascinating.
Thanks again for your help, $N. I''ve much studying to keep myself occupied while Joren''s got us under lockdown.' WHERE entry='24486';


-- Missing quest texts for "Whitebeard Needs Ye" (24487)
UPDATE quest_template SET OfferRewardText='Welcome, $C. Are you ready to get to work?' WHERE entry='24487';


-- Missing quest texts for "The Troll Menace" (182)
UPDATE quest_template SET RequestItemsText='From what I''ve learned, these trolls hail from the Frostmane clan. I''m afraid I don''t know much else about them that would be of any use to you, $N.',OfferRewardText='Hopefully that did the trick. Anvilmar will be safe from trolls for the time being. Now, to find out what it is that has the trolls so agitated.' WHERE entry='182';


-- Missing quest texts for "A Refugee's Quandry" (3361)
UPDATE quest_template SET RequestItemsText='Once I get my tools, I''m outta here.',OfferRewardText='Huzzah, you''ve found them! Get ready, women of Gnomeregan: here comes Felix!$B$BNow, which road takes me out of here...' WHERE entry='3361';


-- Missing quest texts for "A Trip to Ironforge" (24490)
UPDATE quest_template SET OfferRewardText='To Ironforge? Well first, you''ll need to go through Kharanos, and before that, you''ll have to go through this tunnel.' WHERE entry='24490';


-- Quick fix for NPC Hands Springsprocket (6782) who should talk when rewarding and giving its quests
UPDATE creature_template SET AIName='SmartAI' WHERE entry='6782';

DELETE FROM creature_text WHERE entry = 6782;
INSERT INTO creature_text 
VALUES 
	(6782,0,0,'Alright, so you''re just going to head through this tunnel and whaaaaa....?',12,0,100,1,3,0,'Hands Springsprocket 1st sentence'),
	(6782,1,0,'I recommend that you return to Anvilmar, $N... and quickly! I''ll send the signal to the Gnomeregan Airmen.',12,0,100,1,3,0,'Hands Springsprocket 2nd sentence'),
	(6782,2,0,'Look for a fellow by the name of Milo Geartwinge. I suppose I''ll see what I can do about this cave-in.',12,0,100,1,3,0,'Hands Springsprocket 3rd sentence');

DELETE FROM creature_text WHERE entry = 6782;
INSERT INTO smart_scripts 
VALUES 
	(6782,0,0,0,20,0,100,0,24490,0,0,0,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,'Say when quest 24490 rewarded'),
	(6782,0,1,0,19,0,100,0,24491,0,0,0,1,1,4000,0,0,0,0,7,0,0,0,0,0,0,0,'Say when quest 24491 accepted'),
	(6782,0,2,0,52,0,100,0,1,6782,0,0,1,2,4000,0,0,0,0,7,0,0,0,0,0,0,0,'Second sentence when quest 24491 accepted');

UPDATE quest_template SET QuestFlags='262144' where entry='24491';


-- Missing quest texts for "Follow that Gyro-Copter!" (24491)
UPDATE quest_template SET OfferRewardText='Milo Geartwinge, reporting for duty. You sent up a distress signal?' WHERE entry='24491';


-- Missing quest texts for "Pack Your Bags" (24492)
UPDATE quest_template SET RequestItemsText='Are you absolutely certain you''ve taken care of everything? You won''t have time to turn back.',OfferRewardText='Took you long enough. Hold on tight, and take a good look! Chances are you won''t be coming back here for quite some time.' WHERE entry='24492';


-- Missing quest texts for "Don't Forget About Us" (24493)
UPDATE quest_template SET OfferRewardText='Coldridge Valley? I''ve got my own problems here! What, they can''t deal with a couple of troggs? And trolls? And incursions from the elemental plane?$B$BActually, on second thought, that''s kind of a lot. I''m surprised they''re doing as well as they are. I''ll see what I can do.',PrevQuestId='24491'WHERE entry='24493';


-- Fixing "Pack Your Bags" quest reward

DELETE FROM item_loot_template WHERE entry = 57540;
INSERT INTO item_loot_template
VALUES
	(57540,57541,100,1,1,1,1),
	(57540,57542,100,1,2,1,1),
	(57540,57543,100,1,3,3,3),
	(57540,57544,100,1,4,5,5);
