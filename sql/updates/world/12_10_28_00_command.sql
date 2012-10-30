DELETE FROM `command` WHERE `name`='jail';
INSERT INTO `command` VALUES ('jail', 2, 'Syntax: .jail $name');
DELETE FROM `command` WHERE `name`='unjail';
INSERT INTO `command` VALUES ('unjail', 2, 'Syntax: .unjail $name');
