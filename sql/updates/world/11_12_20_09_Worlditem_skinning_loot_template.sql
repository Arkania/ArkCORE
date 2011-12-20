-- DB/SKINNING: Fix all erros on startup with skinning loot
-- Skinning loot template 70210
DELETE FROM `skinning_loot_template` WHERE `entry`='70210';
INSERT INTO `skinning_loot_template` VALUES
('70210','33568','0','1','1','1','3'),
('70210','38557','25','1','1','1','2'),
('70210','44128','1','1','1','1','1');

-- Skinning loot template 39964
DELETE FROM `skinning_loot_template` WHERE `entry`='39964';
INSERT INTO `skinning_loot_template`  VALUES
('39964','52976','30','0','0','1','6'),
('39964','52977','50','0','0','2','8'),
('39964','52982','20','0','0','1','5'),
('39964','67495','3','0','0','1','1');

-- Skinning loot template 50835
DELETE FROM `skinning_loot_template` WHERE (`entry`='50835');
INSERT INTO `skinning_loot_template` VALUES 
('50835','783','8.8838','1','0','1','1'),
('50835','2318','61.959','1','0','1','2'),
('50835','2319','26.6515','1','0','1','2'),
('50835','4232','2.5057','1','0','1','1');

-- Skinning loot template 50852
DELETE FROM `skinning_loot_template` WHERE (`entry`='50852');
INSERT INTO `skinning_loot_template` VALUES
('50852','2319','64.9701','1','0','1','2'),
('50852','4232','6.2874','1','0','1','1'),
('50852','4234','25.4491','1','0','1','2'),
('50852','4235','3.2934','1','0','1','1');

-- Skinning loot template 51086
DELETE FROM `skinning_loot_template` WHERE (`entry`='51086');
INSERT INTO `skinning_loot_template` VALUES
('51086','783','5.7143','1','0','1','1'),
('51086','2318','37.5','1','0','1','2'),
('51086','2319','50.3571','1','0','1','2'),
('51086','4232','6.4286','1','0','1','1');

-- Skinning loot template 62529
DELETE FROM `skinning_loot_template` WHERE (`entry`='62529');
INSERT INTO `skinning_loot_template` VALUES
('62529','783','3.5451','1','0','1','1'),
('62529','2318','37.6662','1','0','1','2'),
('62529','2319','53.1019','1','0','1','2'),
('62529','4232','5.613','1','0','1','1');

-- Skinning loot template 63851
DELETE FROM `skinning_loot_template` WHERE (`entry`='63851');
INSERT INTO `skinning_loot_template` VALUES
('63851','783','6.3852','1','0','1','1'),
('63851','2318','66.1937','1','0','1','2'),
('63851','2319','24.7251','1','0','1','2'),
('63851','4232','2.696','1','0','1','1');

-- Skinning loot template 63853
DELETE FROM `skinning_loot_template` WHERE (`entry`='63853');
INSERT INTO `skinning_loot_template` VALUES
('63853','783','6.4287','1','0','1','1'),
('63853','2318','65.3809','1','0','1','2'),
('63853','2319','25.1199','1','0','1','2'),
('63853','4232','3.0129','1','0','1','1');

-- Skinning loot template 63854
DELETE FROM `skinning_loot_template` WHERE (`entry`='63854');
INSERT INTO `skinning_loot_template` VALUES
('63854','783','6.3319','1','0','1','1'),
('63854','2318','64.8472','1','0','1','2'),
('63854','2319','25.9825','1','0','1','2'),
('63854','4232','2.8384','1','0','1','1');

-- Skinning loot template 63855
DELETE FROM `skinning_loot_template` WHERE (`entry`='63855');
INSERT INTO `skinning_loot_template` VALUES
('63855','783','6.5024','1','0','1','1'),
('63855','2318','65.2635','1','0','1','2'),
('63855','2319','25.0513','1','0','1','2'),
('63855','4232','3.1828','1','0','1','1');

-- Skinning loot template 63857
DELETE FROM `skinning_loot_template` WHERE (`entry`='63857');
INSERT INTO `skinning_loot_template` VALUES
('63857','783','4.6755','1','0','1','1'),
('63857','2318','34.0544','1','0','1','2'),
('63857','2319','55.2687','1','0','1','2'),
('63857','4232','5.8618','1','0','1','1');

-- Skinning loot template 63859
DELETE FROM `skinning_loot_template` WHERE (`entry`='63859');
INSERT INTO `skinning_loot_template` VALUES
('63859','783','3.585','1','0','1','1'),
('63859','2318','34.5424','1','0','1','2'),
('63859','2319','55.7992','1','0','1','2'),
('63859','4232','5.9469','1','0','1','1');

-- Skinning loot template 63861
DELETE FROM `skinning_loot_template` WHERE (`entry`='63861');
INSERT INTO `skinning_loot_template` VALUES
('63861','783','6.9257','1','0','1','1'),
('63861','2318','65.3714','1','0','1','2'),
('63861','2319','24.9138','1','0','1','2'),
('63861','4232','2.7891','1','0','1','1');

-- Skinning loot template 63862
DELETE FROM `skinning_loot_template` WHERE (`entry`='63862');
INSERT INTO `skinning_loot_template` VALUES
('63862','783','6.9584','1','0','1','1'),
('63862','2318','65.1474','1','0','1','2'),
('63862','2319','25.3115','1','0','1','2'),
('63862','4232','2.5828','1','0','1','1');

-- Skinning loot template 64274
DELETE FROM `skinning_loot_template` WHERE (`entry`='64274');
INSERT INTO `skinning_loot_template` VALUES
('64274','2319','59.8639','1','0','1','2'),
('64274','4232','7.483','1','0','1','1'),
('64274','4234','29.7052','1','0','1','2'),
('64274','4235','2.9478','1','0','1','1');

-- This npc don't hve skin loot
UPDATE `creature_template` SET `skinloot`='0' WHERE `entry` IN ('63852','63860'); 

-- Skinning loot template 52363 for some miss creatures
UPDATE `creature_template` SET `skinloot`='52363' WHERE entry IN ('24138','40290','40309','42181','42824','44189','45788','46158','46925','47263','47372','47769','48724');

-- Gens can't be skinning
DELETE FROM `skinning_loot_template` WHERE entry IN ('80204','80205');