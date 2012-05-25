-- Fix for quest Murder Was The Case That They Gave Me (26209)
-- For Arkania
-- By Jorex


-- The Furlbrow are supposed to be dead (the quest objective is to investigate their deaths !!)
UPDATE creature_template SET dynamicflags='32',AIName='',unit_flags='0',npcflag='0',type_flags='0',flags_extra='0' WHERE entry='237';
UPDATE creature_template_addon SET bytes1='7',bytes2='0',emote='65' WHERE entry='237';
UPDATE creature_template SET dynamicflags='32',AIName='',unit_flags='0',npcflag='0',type_flags='0',flags_extra='0' WHERE entry='238';
UPDATE creature_template_addon SET bytes1='7',bytes2='0',emote='65' WHERE entry='238';

-- Delete duplicate spawn
DELETE FROM creature WHERE guid='305440';

-- Delete scripts for creature 237 (he's dead, he can't speak^^)
DELETE FROM creature_ai_scripts WHERE creature_id='237';
DELETE FROM creature_ai_texts WHERE entry='-160146';

-- Old Blanchy is dead (sniff sniff) and under the cart...
UPDATE creature SET position_x='-9852.06',position_y='909.287',position_z='29.911',DeathState='1' WHERE guid='89773';
DELETE FROM creature_addon WHERE guid='89773';
INSERT INTO creature_addon VALUES (89773,0,0,7,0,65,'');

-- Spawn 2 Stormwind investigators
SET @NPC_Stomwind_investigator1='53';
SET @NPC_Stomwind_investigator2='54';

DELETE FROM creature WHERE guid=@NPC_Stomwind_investigator1;
DELETE FROM creature WHERE guid=@NPC_Stomwind_investigator2;
-- Clean up
DELETE FROM creature WHERE id='42309';

UPDATE creature_template SET minlevel='21',maxlevel='24' WHERE entry='42559';

INSERT INTO creature(guid,id,modelid,position_x,position_y,position_z,orientation) VALUES (@NPC_Stomwind_investigator1,42309,32776,-9854.08,920.595,30.2177,5.45881);

INSERT INTO creature(guid,id,modelid,position_x,position_y,position_z,orientation) VALUES (@NPC_Stomwind_investigator2,42559,32775,-9854.8,908.126,29.865,0.707144);


-- Make the first investigator kneel
DELETE FROM creature_addon WHERE guid=@NPC_Stomwind_investigator1;
INSERT INTO creature_addon(guid,bytes1) VALUES (@NPC_Stomwind_investigator1,8);


-- Activate smartAI
UPDATE creature_template SET AIName='SmartAI' WHERE ENTRY='42559';
UPDATE creature_template SET AIName='SmartAI' WHERE ENTRY='42309';
UPDATE creature_template SET AIName='SmartAI' WHERE ENTRY='42308';


-- Add creature text for npc discussion at the scene, source WoW retail

DELETE FROM creature_text WHERE entry='42559';
DELETE FROM creature_text WHERE entry='42309';
DELETE FROM creature_text WHERE entry='42308';

INSERT INTO creature_text(entry,groupid,id,content_default,`type`,`language`,probability,emote,duration,sound,`comment`)
VALUES
(42559,0,0,'It''s a real bloodshed, lieutenant. They were murdered.',12,0,100,1,3,0,'Stormwind investigator 1st sentence'),
(42309,0,0,'According to body temperature, I''ll say they''ve been dead for less than six hours.',12,0,100,1,3,0,'Stormwind investigator 2nd sentence'),
(42559,1,0,'What they did to Old Blanchy is truly a shame.',12,0,100,1,3,0,'Stormwind investigator 3rd sentence'),
(42308,0,0,'No kidding, Probie...',12,0,100,1,3,0,'Horatio Laine 1st sentence'),
(42308,1,0,'Looks like they really put the cart...',12,0,100,1,3,0,'Horatio Laine 2nd sentence'),
(42308,2,0,'...Before the horse.',12,0,100,1,3,0,'Horatio Laine 3rd sentence');

-- Add smartAI scripts for npc discussion at the Crime Scene, source WoW retail
DELETE FROM smart_scripts WHERE entryorguid='42559';
DELETE FROM smart_scripts WHERE entryorguid='42309';
DELETE FROM smart_scripts WHERE entryorguid='42308';

INSERT INTO smart_scripts
VALUES (42559,0,0,0,10,0,100,0,1,3,30000,40000,1,0,5000,0,0,0,0,7,0,0,0,0,0,0,0,'1st Crime Scene sentence'),
(42559,0,1,0,52,0,100,0,0,42559,0,0,1,0,5000,0,0,0,0,10,@NPC_Stomwind_investigator1,42309,0,0,0,0,0,'Dummy effect to trigger TEXT_OVER'),
(42309,0,0,0,52,0,100,0,0,42559,0,0,1,0,5000,0,0,0,0,7,0,0,0,0,0,0,0,'2nd Crime Scene sentence'),
(42309,0,1,0,52,0,100,0,0,42309,0,0,1,0,5000,0,0,0,0,10,@NPC_Stomwind_investigator2,42559,0,0,0,0,0,'Dummy effect to trigger TEXT_OVER'),
(42559,0,2,0,52,0,100,0,0,42309,0,0,1,1,5000,0,0,0,0,7,0,0,0,0,0,0,0,'3rd Crime Scene sentence'),
(42559,0,3,0,52,0,100,0,1,42559,0,0,1,0,5000,0,0,0,0,10,305725,42308,0,0,0,0,0,'Dummy effect to trigger TEXT_OVER'),
(42308,0,0,0,52,0,100,0,0,42559,0,0,1,0,5000,0,0,0,7,0,0,0,0,0,0,0,0,'4th Crime Scene sentence'),
(42559,0,4,0,52,0,100,0,0,42308,0,0,1,1,5000,0,0,0,0,10,305725,42308,0,0,0,0,0,'Dummy effect to trigger TEXT_OVER'),
(42308,0,1,0,52,0,100,0,1,42308,0,0,1,1,5000,0,0,0,0,7,0,0,0,0,0,0,0,'5th Crime Scene sentence'),
(42559,0,5,0,52,0,100,0,1,42308,0,0,1,2,5000,0,0,0,0,10,305725,42308,0,0,0,0,0,'Dummy effect to trigger TEXT_OVER'),
(42308,0,2,0,52,0,100,0,2,42308,0,0,1,2,5000,0,0,0,0,7,0,0,0,0,0,0,0,'6th Crime Scene sentence');


-- Fix the quest chain
UPDATE quest_template SET PrevQuestId='26209' WHERE entry='26213';
UPDATE quest_template SET PrevQuestId='26209' WHERE entry='26214';

-- Wake the hobos up and make them gossip
UPDATE creature_addon SET auras='' WHERE guid='306272';
UPDATE creature SET npcflag='1',dynamicflags='0' WHERE guid='306272';
UPDATE creature_addon SET auras='' WHERE guid='305766';
UPDATE creature SET npcflag='1',dynamicflags='0' WHERE guid='305766';
UPDATE creature_addon SET auras='' WHERE guid='305336';
UPDATE creature SET npcflag='1',dynamicflags='0' WHERE guid='305336';
UPDATE creature_addon SET auras='' WHERE guid='305478';
UPDATE creature SET npcflag='1',dynamicflags='0' WHERE guid='305478';
UPDATE creature_addon SET auras='' WHERE guid='306058';
UPDATE creature SET npcflag='1',dynamicflags='0' WHERE guid='306058';
UPDATE creature_addon SET auras='' WHERE guid='304958';
UPDATE creature SET npcflag='1',dynamicflags='0' WHERE guid='304958';
UPDATE creature_addon SET auras='' WHERE guid='304973';
UPDATE creature SET npcflag='1',dynamicflags='0' WHERE guid='304973';
UPDATE creature_addon SET auras='' WHERE guid='304954';
UPDATE creature SET npcflag='1',dynamicflags='0' WHERE guid='304954';

-- For West Plains Drifter (42391)
-- Create the gossip

SET @NPC_TEXT_GOSSIP1='70';
DELETE FROM npc_text WHERE id=@NPC_TEXT_GOSSIP1;
INSERT INTO npc_text(ID,text0_0,prob0) VALUES (@NPC_TEXT_GOSSIP1,'You wanna talk? Pay up.',100);

SET @GOSSIP_MENU_ID1='87';	
DELETE FROM gossip_menu WHERE entry=@GOSSIP_MENU_ID1;	
INSERT INTO gossip_menu VALUES (@GOSSIP_MENU_ID1,@NPC_TEXT_GOSSIP1);

UPDATE creature_template SET gossip_menu_id=@GOSSIP_MENU_ID1 WHERE entry='42391';

DELETE FROM gossip_menu_option WHERE menu_id=@GOSSIP_MENU_ID1;
INSERT INTO gossip_menu_option
VALUES (@GOSSIP_MENU_ID1,0,0,'Did you see who killed the Furlbrows?',1,1,0,0,0,0,0,''),
 (@GOSSIP_MENU_ID1,1,0,'Maybe a couple copper will loosen your tongue. Now tell me, did you see who killed the Furlbrows?',1,1,0,0,0,0,2,'Are you sure you want to give this hobo money?');

-- Hobo go smartAI
UPDATE creature_template SET AIName='SmartAI' WHERE entry='42391';

-- Hobos don't have money, or loot and don't give XP (nothing rewarding in killing a hobo^^)
UPDATE creature_template SET mingold='0',maxgold='0',flags_extra='64' WHERE entry='42391';

-- Create the texts
DELETE FROM creature_text WHERE entry='42391';

INSERT INTO creature_text(entry,groupid,id,content_default,`type`,`language`,probability,emote,duration,sound,`comment`)
VALUES
(42391,0,0,'I ain''t tellin'' you a damn thing!',12,0,100,1,3000,0,'Murder was the case 1st aggro sentence'),
(42391,0,1,'You rich punks are all the same!',12,0,100,1,3000,0,'Murder was the case 2nd aggro sentence'),
(42391,0,2,'Now you''v''e gone and done it! TIME FOR THE FIST!',12,0,100,1,3000,0,'Murder was the case 3rd aggro sentence'),
(42391,1,0,'Listen, pal. I don''t want any trouble, ok? I didn''t see who murdered ''em, but I sure heard it! Lots of yelling. Human voices... you dig? Now get out of here before I change my mind about beating you up and takin'' your shoes.',12,0,100,1,5000,0,'Murder was the case 1st clue'),
(42391,2,0,'I didn''t see who killed ''em, $Gbub:sis , but I got a whiff. Smelled rich, kinda like you. Damn shame too. Furlbrows were a fixture around here. Nice people, always willin'' to share a meal or a patch of dirt.',12,0,100,1,5000,0,'Murder was the case 2nd clue'),
(42391,3,0,'Who killed the Furlbrows? I''ll tell you who killed the Furlbrows: KING VARIAN WRYNN. THAT''S WHO! And he''s killin'' the rest of us too. Once bum at a time. The only thing I can tell you is that I saw some gnolls leavin'' the place a few hours before the law arrived.',12,0,100,1,5000,0,'Murder was the case 3rd clue'),
(42391,4,0,'Between you, me, and the tree, murlocs killed the Furlbrows. Yep, saw ''em with my own two eyes. Think they''d been casin'' the joint for days, maybe months. They left in a hurry once they got wind of "Johnny Law" and the idiot brigade over there...',12,0,100,1,6000,0,'Murder was the case 4th clue');

-- On to the script creation
DELETE FROM smart_scripts WHERE entryorguid='42391';
DELETE FROM smart_scripts WHERE entryorguid='4239101';
DELETE FROM smart_scripts WHERE entryorguid='4239102';
DELETE FROM smart_scripts WHERE entryorguid='4239103';
DELETE FROM smart_scripts WHERE entryorguid='4239104';
INSERT INTO smart_scripts
VALUES
(42391,0,0,0,62,0,100,0,@GOSSIP_MENU_ID1,0,0,0,1,0,2000,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - random aggro sentence'),
(42391,0,1,0,62,0,100,0,@GOSSIP_MENU_ID1,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - close gossip'),
(42391,0,2,0,52,0,100,0,0,42391,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - start attack'),
(42391,0,3,0,52,0,100,0,0,42391,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - npc_flag to 0'),
(42391,0,4,0,52,0,100,0,0,42391,0,0,2,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - change faction to aggressive'),
(42391,0,5,0,25,0,100,0,0,0,0,0,2,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Reset - change faction back to neutral'),
(42391,0,6,0,25,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Reset - change npc_flag back to gossip'),
(42391,0,7,0,62,0,100,0,@GOSSIP_MENU_ID1,1,0,0,87,4239101,4239102,4239103,4239104,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - Tell random clue'),
(4239101,9,0,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - Tell 1st clue'),
(4239102,9,0,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - Tell 2nd clue'),
(4239103,9,0,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - Tell 3rd clue'),
(4239104,9,0,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - Tell 4th clue'),
(42391,0,8,0,52,0,100,0,1,42391,0,0,33,42414,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - validate objective 1'),
(42391,0,9,0,52,0,100,0,2,42391,0,0,33,42415,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - validate objective 2'),
(42391,0,10,0,52,0,100,0,3,42391,0,0,33,42416,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - validate objective 3'),
(42391,0,11,0,52,0,100,0,4,42391,0,0,33,42417,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - validate objective 4'),
(42391,0,12,0,62,0,100,0,@GOSSIP_MENU_ID1,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip 2 - close gossip'),
(42391,0,13,0,62,0,100,0,@GOSSIP_MENU_ID1,1,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - Make the gossiper unavailable'),
(42391,0,14,0,60,0,100,0,30000,30000,30000,30000,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - Reactivate gossiper every 30s');

-- For Homeless Stormwind Citizen (42386)

-- Create gossip

SET @NPC_TEXT_GOSSIP2='71';
DELETE FROM npc_text WHERE id=@NPC_TEXT_GOSSIP2;
INSERT INTO npc_text(ID,text0_0,prob0) VALUES (@NPC_TEXT_GOSSIP2,'Whaddya want?',100);

SET @GOSSIP_MENU_ID2='88';	
DELETE FROM gossip_menu WHERE entry=@GOSSIP_MENU_ID2;	
INSERT INTO gossip_menu VALUES (@GOSSIP_MENU_ID2,@NPC_TEXT_GOSSIP2);

UPDATE creature_template SET gossip_menu_id=@GOSSIP_MENU_ID2 WHERE entry='42386';

DELETE FROM gossip_menu_option WHERE menu_id=@GOSSIP_MENU_ID2;
INSERT INTO gossip_menu_option
VALUES (@GOSSIP_MENU_ID2,0,0,'Did you see who killed the Furlbrows?',1,1,0,0,0,0,0,''),
 (@GOSSIP_MENU_ID2,1,0,'Maybe a couple copper will loosen your tongue. Now tell me, did you see who killed the Furlbrows?',1,1,0,0,0,0,2,'Are you sure you want to give this hobo money?');

-- Hobo go smartAI
UPDATE creature_template SET AIName='SmartAI' WHERE entry='42386';

-- Hobos don't have money, or loot and don't give XP (nothing rewarding in killing a hobo^^)
UPDATE creature_template SET mingold='0',maxgold='0',flags_extra='64' WHERE entry='42386';

-- Create the texts
DELETE FROM creature_text WHERE entry='42386';

INSERT INTO creature_text(entry,groupid,id,content_default,`type`,`language`,probability,emote,duration,sound,`comment`)
VALUES
(42386,0,0,'I ain''t tellin'' you a damn thing!',12,0,100,1,3000,0,'Murder was the case 1st aggro sentence'),
(42386,0,1,'You rich punks are all the same!',12,0,100,1,3000,0,'Murder was the case 2nd aggro sentence'),
(42386,0,2,'Now you''v''e gone and done it! TIME FOR THE FIST!',12,0,100,1,3000,0,'Murder was the case 3rd aggro sentence'),
(42386,1,0,'You can''t buy me! DIE!',12,0,100,1,3000,0,'Murder was the case 4th aggro sentence');

-- On to the script creation
DELETE FROM smart_scripts WHERE entryorguid='42386';
INSERT INTO smart_scripts
VALUES
(42386,0,0,0,62,0,100,0,@GOSSIP_MENU_ID2,0,0,0,1,0,2000,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - random aggro sentence'),
(42386,0,1,0,62,0,100,0,@GOSSIP_MENU_ID2,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - close gossip'),
(42386,0,2,0,52,0,100,0,0,42386,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - start attack'),
(42386,0,3,0,52,0,100,0,0,42386,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - npc_flag to 0'),
(42386,0,4,0,52,0,100,0,0,42386,0,0,2,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - change faction to aggressive'),
(42386,0,5,0,62,0,100,0,@GOSSIP_MENU_ID2,1,0,0,1,1,2000,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip2 - random aggro sentence'),
(42386,0,6,0,62,0,100,0,@GOSSIP_MENU_ID2,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip1 - close gossip'),
(42386,0,7,0,52,0,100,0,1,42386,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murder was the case - On Gossip2 - start attack'),
(42386,0,8,0,52,0,100,0,1,42386,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip2 - npc_flag to 0'),
(42386,0,9,0,52,0,100,0,1,42386,0,0,2,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Gossip2 - change faction to aggressive'),
(42386,0,10,0,25,0,100,0,0,0,0,0,2,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Reset - change faction back to neutral'),
(42386,0,11,0,25,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Murder was the case - On Reset - change npc_flag back to gossip');

-- Add condtions for the quest gossip menu to appear only when the quest is active. When not, the hobos won't talk to you
DELETE FROM conditions WHERE SourceTypeOrReferenceId='15' AND SourceGroup=@GOSSIP_MENU_ID1;
DELETE FROM conditions WHERE SourceTypeOrReferenceId='15' AND SourceGroup=@GOSSIP_MENU_ID2;

INSERT INTO conditions
VALUES
(15,@GOSSIP_MENU_ID1,0,0,9,26209,0,0,0,0,'Show gossip 0 only with quest 26209 active'),
(15,@GOSSIP_MENU_ID1,1,0,9,26209,0,0,0,0,'Show gossip 1 only with quest 26209 active'),
(15,@GOSSIP_MENU_ID2,0,0,9,26209,0,0,0,0,'Show gossip 0 only with quest 26209 active'),
(15,@GOSSIP_MENU_ID2,1,0,9,26209,0,0,0,0,'Show gossip 1 only with quest 26209 active');

-- Miscellanious
-- Sack of Oats : quest obsolete, GO untargetable on retail
UPDATE gameobject_template SET flags='16' WHERE entry='2724';
