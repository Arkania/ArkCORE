-- Arena season 9
DELETE FROM `game_event` WHERE `EventEntry` IN (132);
INSERT  INTO `game_event`(`EventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`) VALUES (132,'0000-00-00 00:00:00','0000-00-00 00:00:00',5184000,2592000,0,'Arena Season 9',0);
