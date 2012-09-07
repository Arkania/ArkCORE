DELETE FROM `spell_bonus_data` WHERE `entry` IN (17);

-- Wild Mushroom
DELETE FROM `spell_bonus_data` WHERE `entry` IN (78777);
insert INTO `spell_bonus_data` VALUES (78777, 0.603200, 0, 0, 0, 'Druid: Wild mushroom damage');

-- Healing Rain
DELETE FROM `spell_bonus_data` WHERE `entry` IN (73921);
insert INTO `spell_bonus_data` VALUES (73921, 0.076000, 0, 0, 0, 'Shaman - Healing Rain');

DELETE FROM `spell_bonus_data` WHERE `entry` IN (779);
insert into `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) values('779','1','0','0.114','0','Druid - Swipe (Bear)');

DELETE FROM `spell_bonus_data` WHERE `entry` IN (5570);
insert into `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) values('5570','0.13','0','0','0','Druid - Insect Swarm');

DELETE FROM `spell_bonus_data` WHERE `entry` IN (77758);
insert into `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) values('77758','1','0.154','0','0','Druid - Thrash');

DELETE FROM `spell_bonus_data` WHERE `entry` IN (379);
insert into `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) values('974','1','-1','-1','-1','Shaman - Earth Shield');