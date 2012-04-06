-- Fix Quest "Trolling for information" (24489)
-- For Arkania
-- By Jorex

-- Change quest objective and add missing text

UPDATE quest_template SET ReqCreatureOrGoId1=37108,ReqCreatureOrGoId2=37173,ReqCreatureOrGoId3=37174,RequestItemsText='I can''t even begin to imagine what would make the trolls act like this.',OfferRewardText='Hmm... interesting. From what you''re saying, it looks like a fire elemental might have snuck in from Searing Gorge. Or, the earthquake opened up a crack to the elemental plane... $B $B <Soren laughs uncomfortably.> $B $B Either way, this is bad news. You should probably report this information to Grelin.'
WHERE entry='24489';

-- Update quest chain, Ice and Fire (218) needs Trolling for information (24489) completed and add missing text

UPDATE quest_template
SET PrevQuestId='24489',RequestItemsText='$N ! Any luck?',OfferRewardText='I''m glad you''ve returned safely, $N. While it may not look like it now, you''ve proven to be a tremendous asset in the protection of Anvilmar. $B $B Here, take this as a symbol of my gratitude.'
WHERE entry='218';


-- Add creature text for Soothsayer Rikkari

INSERT INTO creature_text
VALUES (37173,0,0,'What we gon'' do now, you ask ? We wait.',12,0,100,1,3,0,'Soothsayer Rikkari 1st sentence');

INSERT INTO creature_text
VALUES (37173,1,0,'Grik''nir says he gon'' talk to the elemental, get it to fight on our side.',12,0,100,1,3,0,'Soothsayer Rikkari 2nd sentence');

INSERT INTO creature_text
VALUES (37173,2,0,'Soon enough we take over dis valley. Soon enough.',12,0,100,1,3,0,'Soothsayer Rikkari 3rd sentence');


-- Add script for Soothsayer Rikkari

INSERT INTO smart_scripts
VALUES (37173,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,'Start 1st sentence when in range');

INSERT INTO smart_scripts
VALUES (37173,0,1,0,52,0,100,0,0,37173,0,0,1,1,4000,0,0,0,7,0,0,0,0,0,0,0,0,'Start 2nd sentence after TEXT_OVER');

INSERT INTO smart_scripts
VALUES (37173,0,2,0,52,0,100,0,1,37173,0,0,1,2,4000,0,0,0,7,0,0,0,0,0,0,0,0,'Start 2nd sentence after TEXT_OVER');


-- Add script for objective check

INSERT INTO smart_scripts
VALUES (37173,0,3,0,52,0,100,0,2,37173,0,0,33,37173,0,0,0,0,7,0,0,0,0,0,0,0,0,'Validate objective');


-- Switch AI type for Soothsayer Rikkari to SmartAI

UPDATE creature_template SET AIName='SmartAI' WHERE entry='37173';


-- Add creature text for Soothsayer Shi'kala

INSERT INTO creature_text
VALUES (37108,0,0,'Da spirits be angry with us.',12,0,100,1,3,0,'Soothsayer Shi''kala 1st sentence');

INSERT INTO creature_text
VALUES (37108,1,0,'I don'' know why the spirits be rejectin'' us so.',12,0,100,1,3,0,'Soothsayer Shi''kala 2nd sentence');

INSERT INTO creature_text
VALUES (37108,2,0,'Don'' worry, child. Grik''nir gonna help us get through this.',12,0,100,1,3,0,'Soothsayer Shi''kala 3rd sentence');


-- Add script for Soothsayer Shi'kala

INSERT INTO smart_scripts
VALUES (37108,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,'Start 1st sentence when in range');

INSERT INTO smart_scripts
VALUES (37108,0,1,0,52,0,100,0,0,37108,0,0,1,1,4000,0,0,0,7,0,0,0,0,0,0,0,0,'Start 2nd sentence after TEXT_OVER');

INSERT INTO smart_scripts
VALUES (37108,0,2,0,52,0,100,0,1,37108,0,0,1,2,4000,0,0,0,7,0,0,0,0,0,0,0,0,'Start 2nd sentence after TEXT_OVER');


-- Add script for objective check

INSERT INTO smart_scripts
VALUES (37108,0,3,0,52,0,100,0,2,37108,0,0,33,37108,0,0,0,0,7,0,0,0,0,0,0,0,0,'Validate objective');


-- Switch AI type for Soothsayer Shi'kala to SmartAI

UPDATE creature_template SET AIName='SmartAI' WHERE entry='37108';



-- Add creature text for Soothsayer Mirim'koa

INSERT INTO creature_text
VALUES (37174,0,0,'Our land be a land of ice an'' snow',12,0,100,1,3,0,'Soothsayer Mirim''koa 1st sentence');

INSERT INTO creature_text
VALUES (37174,1,0,'But beneath the earth, child, there always be fire.',12,0,100,1,3,0,'Soothsayer Mirim''koa 2nd sentence');

INSERT INTO creature_text
VALUES (37174,2,0,'De spirit come from deep down to talk with Grik''nir.',12,0,100,1,3,0,'Soothsayer Mirim''koa 3rd sentence');


-- Add script for Soothsayer Mirim'koa

INSERT INTO smart_scripts
VALUES (37174,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,'Start 1st sentence when in range');

INSERT INTO smart_scripts
VALUES (37174,0,1,0,52,0,100,0,0,37174,0,0,1,1,4000,0,0,0,7,0,0,0,0,0,0,0,0,'Start 2nd sentence after TEXT_OVER');

INSERT INTO smart_scripts
VALUES (37174,0,2,0,52,0,100,0,1,37174,0,0,1,2,4000,0,0,0,7,0,0,0,0,0,0,0,0,'Start 2nd sentence after TEXT_OVER');


-- Add script for objective check

INSERT INTO smart_scripts
VALUES (37174,0,3,0,52,0,100,0,2,37174,0,0,33,37174,0,0,0,0,7,0,0,0,0,0,0,0,0,'Validate objective');


-- Switch AI type for Soothsayer Mirim'koa to SmartAI

UPDATE creature_template SET AIName='SmartAI' WHERE entry='37174';

