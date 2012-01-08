-- DB/SCRIPT TEXTS: Some miss text on Human start zone, ths fix a spawn on console.
-- Credits goes to RebaseDB
-- Deleting text
DELETE FROM `script_texts` WHERE `entry` IN (-1000001,-1000002,-1000003,-1000004,-1000005);
INSERT INTO `script_texts` VALUES
('49869','-1000001','Your filthy dogs won\'t be enough!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','1','0','0','Stormwind Infantry - Yell1'),
('49869','-1000002','Your worgs are no match for the might of Stormwind!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','1','0','0','Stormwind Infantry - Yell2'),
('49869','-1000003','Look alive, men! There are orcs and worgs about!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','1','0','0','Stormwind Infantry - Yell3'),
('49869','-1000004','I\'ll kill a hundred more of your battle worgs!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','1','0','22','Stormwind Infantry - Yell4'),
('49869','-1000005','Come, monsters! We will cursh you!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','1','0','0','Stormwind Infantry - Yell5');