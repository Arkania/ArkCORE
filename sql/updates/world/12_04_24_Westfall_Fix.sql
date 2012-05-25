-- Westfall fix
-- For Arkania
-- By Jorex


-- Bye bye Defias Profiteer
DELETE FROM creature WHERE id='1669';

-- Change the timing in the smart_scripts
SET @NPC_RISE1='29';
DELETE FROM smart_scripts WHERE entryorguid='-66975' AND id>'10';
DELETE FROM smart_scripts WHERE entryorguid='-304721';
DELETE FROM smart_scripts WHERE entryorguid='-42778';
DELETE FROM smart_scripts WHERE entryorguid=-@NPC_RISE1;
INSERT INTO smart_scripts
VALUES
(-66975,0,11,0,19,0,100,0,26322,0,0,0,75,59087,0,0,0,0,0,18,30,0,0,0,0,0,0,'Rise of the Brotherhood phase change'),
(-@NPC_RISE1,0,0,0,10,0,100,0,1,3,120000,120000,12,42749,3,35000,0,0,0,8,0,0,0,-10506.26,1038.91,60.52,1.98,'Rise of the Brotherhood spawn npc Hope'),
(-@NPC_RISE1,0,15,0,10,0,100,0,1,3,120000,120000,12,42635,3,50000,0,0,0,8,0,0,0,-10514.8,1045.6,60.8075,0.488692,'Rise of the Brotherhood spawn npc Ripsnarl'),
(-@NPC_RISE1,0,1,0,10,0,100,0,1,3,120000,120000,1,7,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Rise of the Brotherhood 1st sentence - Dummy'),
(-@NPC_RISE1,0,2,0,52,0,100,0,7,42750,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Rise of the Brotherhood 1st sentence'),
(-@NPC_RISE1,0,3,0,52,0,100,0,4,42750,0,0,1,0,5000,0,0,0,0,11,42749,10,0,0,0,0,0,'Rise of the Brotherhood 2nd sentence'),
(-@NPC_RISE1,0,4,0,52,0,100,0,0,42749,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Rise of the Brotherhood 3rd sentence'),
(-@NPC_RISE1,0,5,0,52,0,100,0,5,42750,0,0,1,1,5000,0,0,0,0,11,42749,10,0,0,0,0,0,'Rise of the Brotherhood 4th sentence'),
(-@NPC_RISE1,0,6,0,52,0,100,0,1,42749,0,0,1,2,5000,0,0,0,0,11,42749,10,0,0,0,0,0,'Rise of the Brotherhood 5th sentence'),
(-@NPC_RISE1,0,7,0,52,0,100,0,2,42749,0,0,12,42372,3,80000,0,0,0,8,0,0,0,-10506.26,1038.91,60.52,1.98,'Rise of the Brotherhood spawn npc Vanessa'),
(-@NPC_RISE1,0,8,0,52,0,100,0,2,42749,0,0,1,0,5000,0,0,0,0,11,42372,10,0,0,0,0,0,'Rise of the Brotherhood 6th sentence'),
(-@NPC_RISE1,0,9,0,52,0,100,0,0,42372,0,0,12,42769,3,75000,0,0,0,8,0,0,0,-10514.1,1040.35,60.5179,0.641156,'Rise of the Brotherhood spawn npc Defias Blackguard'),
(-@NPC_RISE1,0,10,0,52,0,100,0,0,42372,0,0,12,42769,3,75000,0,0,0,8,0,0,0,-10501.6,1045.06,60.5179,2.95415,'Rise of the Brotherhood spawn npc Defias Blackguard'),
(-@NPC_RISE1,0,11,0,52,0,100,0,0,42372,0,0,12,42769,3,75000,0,0,0,8,0,0,0,-10507.4,1052.16,60.0023,4.72522,'Rise of the Brotherhood spawn npc Defias Blackguard'),
(-@NPC_RISE1,0,12,0,52,0,100,0,0,42372,0,0,12,42769,3,75000,0,0,0,8,0,0,0,-10514.4,1049.72,59.8991,5.34231,'Rise of the Brotherhood spawn npc Defias Blackguard'),
(-@NPC_RISE1,0,13,0,52,0,100,0,0,42372,0,0,1,1,5000,0,0,0,0,11,42372,10,0,0,0,0,0,'Rise of the Brotherhood 7th sentence'),
(-@NPC_RISE1,0,14,0,52,0,100,0,1,42372,0,0,1,2,5000,0,0,0,0,11,42372,10,0,0,0,0,0,'Rise of the Brotherhood 8th sentence'),
(-@NPC_RISE1,0,16,0,52,0,100,0,2,42372,0,0,12,42778,3,75000,0,0,0,8,0,0,0,-10514.8,1045.6,60.8075,0.488692,'Rise of the Brotherhood npc spawn Admiral Ripsnarl'),
(-@NPC_RISE1,0,25,0,52,0,100,0,2,42372,0,0,1,0,5000,0,0,0,0,11,42778,10,0,0,0,0,0,'Rise of the Brotherhood 9th sentence'),
(-@NPC_RISE1,0,17,0,52,0,100,0,0,42778,0,0,1,3,7000,0,0,0,0,11,42372,10,0,0,0,0,0,'Rise of the Brotherhood 10th sentence'),
(-@NPC_RISE1,0,18,0,52,0,100,0,3,42372,0,0,1,13,5000,0,0,0,0,11,42308,10,0,0,0,0,0,'Rise of the Brotherhood 11th sentence'),
(-@NPC_RISE1,0,19,0,52,0,100,0,13,42308,0,0,1,14,5000,0,0,0,0,11,42308,10,0,0,0,0,0,'Rise of the Brotherhood 12th sentence'),
(-@NPC_RISE1,0,20,0,52,0,100,0,14,42308,0,0,1,4,5000,0,0,0,0,11,42372,10,0,0,0,0,0,'Rise of the Brotherhood 13th sentence'),
(-@NPC_RISE1,0,21,0,52,0,100,0,4,42372,0,0,1,5,5000,0,0,0,0,11,42372,10,0,0,0,0,0,'Rise of the Brotherhood 14th sentence'),
(-@NPC_RISE1,0,22,0,52,0,100,0,5,42372,0,0,1,6,5000,0,0,0,0,11,42372,10,0,0,0,0,0,'Rise of the Brotherhood 15th sentence'),
(-@NPC_RISE1,0,23,0,52,0,100,0,6,42372,0,0,1,6,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Rise of the Brotherhood 16th sentence'),
(-@NPC_RISE1,0,24,0,52,0,100,0,6,42750,0,0,15,26322,0,0,0,0,0,18,30,0,0,0,0,0,0,'Rise of the Brotherhood validate objective'),
(-304721,0,0,0,1,0,100,0,1,3,3000,3000,28,59087,0,0,0,0,0,18,3,0,0,0,0,0,0,'Rise of the Brotherhood phase change back on taking fly');