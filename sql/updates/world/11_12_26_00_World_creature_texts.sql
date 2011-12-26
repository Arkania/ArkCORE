-- DB/SCRIPT TEX: This fix a miss script text on DB still flineas.ccp is on core, so we neeed the texts.
-- Credits goes to Espargon
-- Deleting text
DELETE FROM `script_texts` WHERE `entry` IN (-1638000,-1638001,-1638002,-1638025,-1638026,-1638027,-1638028,-1638029,-1638003,-1638004,-1638005,-1638006,-1638007,-1638008,-1638009,-1638010,-1638011,-1638012,-1638013,-1638014,-1638015,-1638016,-1638017,-1638018,-1638019,-1638020,-1638021,-1638022,-1638023,-1638024);

-- Prince Liam Greymane Phase 1
INSERT INTO `script_texts` VALUES (34850, -1638000, 'I want the perimeter secured and the gates manned by two guards at all times. No one gets in, no one gets out.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 19615, 0, 0, 1, 'SAY_PRINCE_LIAM_GREYMANE_1 - Say OOC');
INSERT INTO `script_texts` VALUES (34850, -1638001, 'We protected Gilneas from the Scourge. We protected Gilneas during the Northgate rebellion. We will protect Gilneas from whatever this new threat may be.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 19616, 0, 0, 25, 'SAY_PRINCE_LIAM_GREYMANE_2 - Say OOC');
INSERT INTO `script_texts` VALUES (34850, -1638002, 'Stand ready, guards! We don\'t know how many intruders we\'re dealing with, but the Headlands are overrun and we\'re cut off from the harbor towns. Expect to be outnumbered.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 19614, 0, 0, 1, 'SAY_PRINCE_LIAM_GREYMANE_3 - Say OOC');

-- Prince Liam Greymane Phase 2
INSERT INTO `script_texts` VALUES (34913, -1638025, 'Stand your ground, men!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 19617, 1, 0, 0, 'SAY_PRINCE_LIAM_GREYMANE - Phase 2 OOC');
INSERT INTO `script_texts` VALUES (34913, -1638026, 'Defeat these foul beasts!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 19618, 1, 0, 0, 'SAY_PRINCE_LIAM_GREYMANE - Phase 2 OOC');
INSERT INTO `script_texts` VALUES (34913, -1638027, 'Protect the civilians!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 19619, 1, 0, 0, 'SAY_PRINCE_LIAM_GREYMANE - Phase 2 OOC');
INSERT INTO `script_texts` VALUES (34913, -1638028, 'Push them back!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 19620, 1, 0, 0, 'SAY_PRINCE_LIAM_GREYMANE - Phase 2 OOC');
INSERT INTO `script_texts` VALUES (34913, -1638029, 'Take heart, men! We must protect our city!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 19621, 1, 0, 0, 'SAY_PRINCE_LIAM_GREYMANE - Phase 2 OOC');

-- Frightened Citizen 34981 with no worgen behind
INSERT INTO `script_texts` VALUES (34981, -1638003, 'Protect me, please!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 1, 'SAY_FRIGHTENED_CITIZEN_1a - No worgen behind');
INSERT INTO `script_texts` VALUES (34981, -1638004, 'What in the world? Let\'s get out of here!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 1, 'SAY_FRIGHTENED_CITIZEN_2a - No worgen behind');
INSERT INTO `script_texts` VALUES (34981, -1638005, 'Worgen! Worgen everywhere!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 1, 'SAY_FRIGHTENED_CITIZEN_3a - No worgen behind');
INSERT INTO `script_texts` VALUES (34981, -1638006, 'Flee! They\'re everywhere!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 1, 'SAY_FRIGHTENED_CITIZEN_4a - No worgen behind');
INSERT INTO `script_texts` VALUES (34981, -1638007, 'No time to Waste!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 1, 'SAY_FRIGHTENED_CITIZEN_5a - No worgen behind');
INSERT INTO `script_texts` VALUES (34981, -1638008, 'This place isn\'t safe. Let\'s Leave!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 1, 'SAY_FRIGHTENED_CITIZEN_6a - No worgen behind');
INSERT INTO `script_texts` VALUES (34981, -1638009, 'Let\'s go!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 1, 'SAY_FRIGHTENED_CITIZEN_7a - No worgen behind');
INSERT INTO `script_texts` VALUES (34981, -1638010, 'Thank you!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 1, 'SAY_FRIGHTENED_CITIZEN_8a - No worgen behind');
-- Frightened Citizen when worgen is behind them
INSERT INTO `script_texts` VALUES (35836, -1638011, 'I don\'t want to die!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 430, 'SAY_FRIGHTENED_CITIZEN_1b - Worgen behind');
INSERT INTO `script_texts` VALUES (35836, -1638012, 'There\'s one after me!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 430, 'SAY_FRIGHTENED_CITIZEN_2b - Worgen behind');
INSERT INTO `script_texts` VALUES (35836, -1638013, 'It\'s coming right for me!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 430, 'SAY_FRIGHTENED_CITIZEN_3b - Worgen behind');
INSERT INTO `script_texts` VALUES (35836, -1638014, 'Help!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 430, 'SAY_FRIGHTENED_CITIZEN_4b - Worgen behind');
INSERT INTO `script_texts` VALUES (35836, -1638015, 'Help me, please!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 430, 'SAY_FRIGHTENED_CITIZEN_5b - Worgen behind');

-- Panicked Citizen at gate
INSERT INTO `script_texts` VALUES (44086, -1638016, 'What\'s going on? I thought I saw something on the rooftops.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'SAY_PANICKED_CITIZEN_1 - Phase 1 at gate');
INSERT INTO `script_texts` VALUES (44086, -1638017, 'My children are in Stormglen alone! I have to get to them!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'SAY_PANICKED_CITIZEN_2 - Phase 1 at gate');
INSERT INTO `script_texts` VALUES (44086, -1638018, 'You can\'t do this to us!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'SAY_PANICKED_CITIZEN_3 - Phase 1 at gate');
INSERT INTO `script_texts` VALUES (44086, -1638019, 'What... what are those things on the rooftops?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'SAY_PANICKED_CITIZEN_4 - Phase 1 at gate');

-- Panicked Citizen, millitary distrcit
INSERT INTO `script_texts` VALUES (44086, -1638020, 'We have to get out of here! The howling gets louder every night.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'SAY_PANICKED_CITIZEN - Military distrcit');
INSERT INTO `script_texts` VALUES (44086, -1638021, 'They told us Gilneas City was safe...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'SAY_PANICKED_CITIZEN - Military distrcit');

-- Gilneas City Guard
INSERT INTO `script_texts` VALUES (34864, -1638022, 'No one\'s allowed to leave. Prince Liam\'s orders.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'SAY_GILNEAS_CITY_GUARD_1 - At gate');
INSERT INTO `script_texts` VALUES (34864, -1638023, 'Stay calm. We have everything under control.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'SAY_GILNEAS_CITY_GUARD_2 - At gate');
INSERT INTO `script_texts` VALUES (34864, -1638024, 'It isn\'t safe to leave, there\'s something lurking out there in the woods.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'SAY_GILNEAS_CITY_GUARD_3 - At gate');