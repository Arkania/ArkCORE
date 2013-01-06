DELETE FROM `arkcore_string` WHERE `entry` IN (11003, 11004, 11007, 11008, 11009, 11010, 11011, 11012, 11013);
INSERT INTO `arkcore_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(11003, 'Put your items in slot 1 and 2 in your bag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11004, 'Not enough money!  (Cost: %ug)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11007, 'Your item was not found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11008, 'The items are for different slots!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11009, 'Your item is of an invalid type!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11010, 'Put the item in the first slot of your bag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11011, 'The item is of an invalid quality!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11012, 'Item is for a different class!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11013, 'Item is for a different race!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);