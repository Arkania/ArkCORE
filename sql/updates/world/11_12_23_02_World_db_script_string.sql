-- DB/STRING: Deleting some unused strings and adding a miss text
DELETE FROM `db_script_string`  WHERE `entry` IN ('2000000022','2000000423','2000000432','2000000433','2000000434','2000000435','2000000436','2000000022');
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
('2000000022','I think, I\'ll be able to get to Brackenwall. The cargo they carried to the top of the towers. Be careful!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);