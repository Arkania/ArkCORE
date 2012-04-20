-- Quest fixes for all the Hero's Call Boards.
 
-- Alliance quests.
UPDATE `quest_template` SET `RequiredRaces`=2098253 WHERE `entry` IN (27724, 27726, 27727, 28551, 28552, 28558, 28562, 28563, 28564, 28576, 28578, 28579, 28582, 28666, 28673, 28675, 28699, 28702, 28708, 28709, 28716, 28573, 28567, 26542, 28565, 28492, 28490, 28531, 28543, 28511, 28528, 28550, 28539, 28507, 28503, 28525, 28544, 29071);
 
-- Set gossip to boards, otherwise only one quest will be offered (used id 68 in this case, but that may be wrong. Need to confirm gossip from retail).
UPDATE `gameobject_template` SET `data3`=68 WHERE entry IN (206111, 206294, 207320, 207321, 208316);
 
-- http://www.wowhead.com/object=206111
SET @ID := 206111;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 27724), -- Hero's Call: Vashj'ir!
(@ID, 27726), -- Hero's Call: Mount Hyjal!
(@ID, 27727), -- Hero's Call: Deepholm!
(@ID, 28551), -- Hero's Call: Southern Barrens!
(@ID, 28552), -- Hero's Call: Dustwallow Marsh!
(@ID, 28558), -- Hero's Call: Uldum!
(@ID, 28562), -- Hero's Call: Westfall!
(@ID, 28563), -- Hero's Call: Redridge Mountains!
(@ID, 28564), -- Hero's Call: Duskwood!
(@ID, 28576), -- Hero's Call: Western Plaguelands!
(@ID, 28578), -- Hero's Call: Eastern Plaguelands!
(@ID, 28579), -- Hero's Call: Badlands!
(@ID, 28582), -- Hero's Call: Searing Gorge!
(@ID, 28666), -- Hero's Call: Burning Steppes!
(@ID, 28673), -- Hero's Call: Blasted Lands!
(@ID, 28675), -- Hero's Call: Swamp of Sorrows!
(@ID, 28699), -- Hero's Call: Northern Stranglethorn Vale!
(@ID, 28702), -- Hero's Call: The Cape of Stranglethorn!
(@ID, 28708), -- Hero's Call: Outland!
(@ID, 28709), -- Hero's Call: Northrend!
(@ID, 28716); -- Hero's Call: Twilight Highlands!
 
-- http://www.wowhead.com/object=206294
SET @ID := 206294;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 27724), -- Hero's Call: Vashj'ir!
(@ID, 27726), -- Hero's Call: Mount Hyjal!
(@ID, 27727), -- Hero's Call: Deepholm!
(@ID, 28551), -- Hero's Call: Southern Barrens!
(@ID, 28552), -- Hero's Call: Dustwallow Marsh!
(@ID, 28558), -- Hero's Call: Uldum!
(@ID, 28562), -- Hero's Call: Westfall!
(@ID, 28563), -- Hero's Call: Redridge Mountains!
(@ID, 28564), -- Hero's Call: Duskwood!
(@ID, 28576), -- Hero's Call: Western Plaguelands!
(@ID, 28578), -- Hero's Call: Eastern Plaguelands!
(@ID, 28579), -- Hero's Call: Badlands!
(@ID, 28582), -- Hero's Call: Searing Gorge!
(@ID, 28666), -- Hero's Call: Burning Steppes!
(@ID, 28673), -- Hero's Call: Blasted Lands!
(@ID, 28675), -- Hero's Call: Swamp of Sorrows!
(@ID, 28699), -- Hero's Call: Northern Stranglethorn Vale!
(@ID, 28702), -- Hero's Call: The Cape of Stranglethorn!
(@ID, 28708), -- Hero's Call: Outland!
(@ID, 28709), -- Hero's Call: Northrend!
(@ID, 28716); -- Hero's Call: Twilight Highlands!
 
-- http://www.wowhead.com/object=207320
SET @ID := 207320;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 26542), -- Hero's Call: The Hinterlands!
(@ID, 27724), -- Hero's Call: Vashj'ir!
(@ID, 27726), -- Hero's Call: Mount Hyjal!
(@ID, 27727), -- Hero's Call: Deepholm!
(@ID, 28558), -- Hero's Call: Uldum!
(@ID, 28565), -- Hero's Call: Wetlands!
(@ID, 28567), -- Hero's Call: Loch Modan!
(@ID, 28573), -- Hero's Call: Arathi Highlands!
(@ID, 28576), -- Hero's Call: Western Plaguelands!
(@ID, 28578), -- Hero's Call: Eastern Plaguelands!
(@ID, 28579), -- Hero's Call: Badlands!
(@ID, 28582), -- Hero's Call: Searing Gorge!
(@ID, 28666), -- Hero's Call: Burning Steppes!
(@ID, 28673), -- Hero's Call: Blasted Lands!
(@ID, 28675), -- Hero's Call: Swamp of Sorrows!
(@ID, 28708), -- Hero's Call: Outland!
(@ID, 28709), -- Hero's Call: Northrend!
(@ID, 28716); -- Hero's Call: Twilight Highlands!
 
-- http://www.wowhead.com/object=207321
SET @ID := 207321;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 27724), -- Hero's Call: Vashj'ir!
(@ID, 27726), -- Hero's Call: Mount Hyjal!
(@ID, 27727), -- Hero's Call: Deepholm!
(@ID, 28490), -- Hero's Call: Darkshore!
(@ID, 28492), -- Hero's Call: Ashenvale!
(@ID, 28503), -- Hero's Call: Thousand Needles!
(@ID, 28507), -- Hero's Call: Tanaris!
(@ID, 28511), -- Hero's Call: Feralas!
(@ID, 28525), -- Hero's Call: Un'Goro Crater!
(@ID, 28528), -- Hero's Call: Silithus!
(@ID, 28531), -- Hero's Call: Desolace!
(@ID, 28539), -- Hero's Call: Stonetalon Mountains!
(@ID, 28543), -- Hero's Call: Felwood!
(@ID, 28544), -- Hero's Call: Winterspring!
(@ID, 28550), -- Hero's Call: Southern Barrens!
(@ID, 28552), -- Hero's Call: Dustwallow Marsh!
(@ID, 28558), -- Hero's Call: Uldum!
(@ID, 28708), -- Hero's Call: Outland!
(@ID, 28709), -- Hero's Call: Northrend!
(@ID, 28716); -- Hero's Call: Twilight Highlands!
 
-- http://www.wowhead.com/object=208316
SET @ID := 208316;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 29071); -- Make Haste to Stormwind!

-- Enable the quests.
UPDATE quest_template SET Method = 2 WHERE entry IN ('26542', '28490', '28492', '28503', '28507', '28511', '28525', '28528', '28531', '28539', '28543', '28544', '28550', '28551', '28552', '28562', '28563', '28564', '28565', '28567', '28573', '28576', '28578', '28579', '28582', '28666', '28673', '28675', '28699', '28702', '28708', '28709', '26365', '26378', '26542', '26728', '27724', '27726', '27727', '28490', '28492', '28503', '28507', '28511', '28525', '28528', '28531', '28539', '28543', '28544', '28550', '28551', '28552', '28558', '28559', '28562', '28563', '28564', '28565', '28567', '28573', '28576', '28578', '28579', '28582', '28666', '28673', '28675', '28699', '28702', '28708', '28709', '28716', '29386');



-- Quest fixes for all the Warchief's Command Boards.
 
-- Enable quests and set them as available only for Horde.
UPDATE `quest_template` SET Method=2, RequiredRaces=946 WHERE entry IN (26964, 27718, 27721, 27722, 28089, 28493, 28494, 28496, 28504, 28509, 28510, 28526, 28527, 28532, 28542, 28545, 28548, 28549, 28554, 28557, 28560, 28568, 28571, 28572, 28574, 28575, 28577, 28580, 28581, 28619, 28667, 28671, 28677, 28688, 28704, 28705, 28711, 28717);
UPDATE `quest_template` SET RequiredRaces=946 WHERE entry=29073;
 
-- Set gossip to boards, otherwise only one quest will be offered (used id 68 in this case, but that may be wrong. Need to confirm gossip from retail).
UPDATE `gameobject_template` SET `data3`=68 WHERE entry IN (206109, 206116, 207324, 207323, 207279, 208317);
 
-- http://www.wowhead.com/object=206109
SET @ID := 206109;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 28493), -- Warchief's Command: Ashenvale!
(@ID, 28496), -- Warchief's Command: Azshara!
(@ID, 27722), -- Warchief's Command: Deepholm!
(@ID, 28548), -- Warchief's Command: Desolace!
(@ID, 28554), -- Warchief's Command: Dustwallow Marsh!
(@ID, 28542), -- Warchief's Command: Felwood!
(@ID, 28510), -- Warchief's Command: Feralas!
(@ID, 27721), -- Warchief's Command: Mount Hyjal!
(@ID, 28494), -- Warchief's Command: Northern Barrens!
(@ID, 28711), -- Warchief's Command: Northrend!
(@ID, 28705), -- Warchief's Command: Outland!
(@ID, 28527), -- Warchief's Command: Silithus!
(@ID, 28549), -- Warchief's Command: Southern Barrens!
(@ID, 28532), -- Warchief's Command: Stonetalon Mountains!
(@ID, 28509), -- Warchief's Command: Tanaris!
(@ID, 28504), -- Warchief's Command: Thousand Needles!
(@ID, 28717), -- Warchief's Command: Twilight Highlands!
(@ID, 28557), -- Warchief's Command: Uldum!
(@ID, 28526), -- Warchief's Command: Un'Goro Crater!
(@ID, 27718), -- Warchief's Command: Vashj'ir!
(@ID, 28545); -- Warchief's Command: Winterspring!
 
-- http://www.wowhead.com/object=206116
SET @ID := 206116;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 28493), -- Warchief's Command: Ashenvale!
(@ID, 28496), -- Warchief's Command: Azshara!
(@ID, 27722), -- Warchief's Command: Deepholm!
(@ID, 28548), -- Warchief's Command: Desolace!
(@ID, 28554), -- Warchief's Command: Dustwallow Marsh!
(@ID, 28542), -- Warchief's Command: Felwood!
(@ID, 28510), -- Warchief's Command: Feralas!
(@ID, 27721), -- Warchief's Command: Mount Hyjal!
(@ID, 28494), -- Warchief's Command: Northern Barrens!
(@ID, 28711), -- Warchief's Command: Northrend!
(@ID, 28705), -- Warchief's Command: Outland!
(@ID, 28527), -- Warchief's Command: Silithus!
(@ID, 28549), -- Warchief's Command: Southern Barrens!
(@ID, 28532), -- Warchief's Command: Stonetalon Mountains!
(@ID, 28509), -- Warchief's Command: Tanaris!
(@ID, 28504), -- Warchief's Command: Thousand Needles!
(@ID, 28717), -- Warchief's Command: Twilight Highlands!
(@ID, 28557), -- Warchief's Command: Uldum!
(@ID, 28526), -- Warchief's Command: Un'Goro Crater!
(@ID, 27718), -- Warchief's Command: Vashj'ir!
(@ID, 28545); -- Warchief's Command: Winterspring!
 
-- http://www.wowhead.com/object=207324
SET @ID := 207324;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 28572), -- Warchief's Command: Arathi Highlands!
(@ID, 28580), -- Warchief's Command: Badlands!
(@ID, 28671), -- Warchief's Command: Blasted Lands!
(@ID, 28667), -- Warchief's Command: Burning Steppes!
(@ID, 27722), -- Warchief's Command: Deepholm!
(@ID, 28577), -- Warchief's Command: Eastern Plaguelands!
(@ID, 28571), -- Warchief's Command: Hillsbrad Foothills!
(@ID, 27721), -- Warchief's Command: Mount Hyjal!
(@ID, 28688), -- Warchief's Command: Northern Stranglethorn Vale!
(@ID, 28711), -- Warchief's Command: Northrend!
(@ID, 28705), -- Warchief's Command: Outland!
(@ID, 28581), -- Warchief's Command: Searing Gorge!
(@ID, 28568), -- Warchief's Command: Silverpine Forest!
(@ID, 28677), -- Warchief's Command: Swamp of Sorrows!
(@ID, 28704), -- Warchief's Command: The Cape of Stranglethorn!
(@ID, 28574), -- Warchief's Command: The Hinterlands!
(@ID, 28717), -- Warchief's Command: Twilight Highlands!
(@ID, 28557), -- Warchief's Command: Uldum!
(@ID, 27718), -- Warchief's Command: Vashj'ir!
(@ID, 28575); -- Warchief's Command: Western Plaguelands!
 
-- http://www.wowhead.com/object=207323
SET @ID := 207323;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 28493), -- Warchief's Command: Ashenvale!
(@ID, 28496), -- Warchief's Command: Azshara!
(@ID, 27722), -- Warchief's Command: Deepholm!
(@ID, 28548), -- Warchief's Command: Desolace!
(@ID, 28554), -- Warchief's Command: Dustwallow Marsh!
(@ID, 28542), -- Warchief's Command: Felwood!
(@ID, 28510), -- Warchief's Command: Feralas!
(@ID, 27721), -- Warchief's Command: Mount Hyjal!
(@ID, 28494), -- Warchief's Command: Northern Barrens!
(@ID, 28711), -- Warchief's Command: Northrend!
(@ID, 28705), -- Warchief's Command: Outland!
(@ID, 28527), -- Warchief's Command: Silithus!
(@ID, 28549), -- Warchief's Command: Southern Barrens!
(@ID, 28532), -- Warchief's Command: Stonetalon Mountains!
(@ID, 28509), -- Warchief's Command: Tanaris!
(@ID, 28504), -- Warchief's Command: Thousand Needles!
(@ID, 28717), -- Warchief's Command: Twilight Highlands!
(@ID, 28557), -- Warchief's Command: Uldum!
(@ID, 28526), -- Warchief's Command: Un'Goro Crater!
(@ID, 27718), -- Warchief's Command: Vashj'ir!
(@ID, 28545); -- Warchief's Command: Winterspring!
 
-- http://www.wowhead.com/object=207279
SET @ID := 207279;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 28619); -- Warchief's Command: Arathi Highlands!
 
-- http://www.wowhead.com/object=208317
SET @ID := 208317;
DELETE FROM `gameobject_questrelation` WHERE id=@ID;
INSERT INTO `gameobject_questrelation` (id, quest) VALUES
(@ID, 29073); -- Make Haste to Orgrimmar!

