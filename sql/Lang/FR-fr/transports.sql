/*
Navicat MySQL Data Transfer

Source Server         : Wylandra
Source Server Version : 50515
Source Host           : 127.0.0.1:3306
Source Database       : world

Target Server Type    : MYSQL
Target Server Version : 50515
File Encoding         : 65001

Date: 2011-09-14 19:29:58
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `transports`
-- ----------------------------
DROP TABLE IF EXISTS `transports`;
CREATE TABLE `transports` (
  `guid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `entry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `name` text,
  `period` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ScriptName` char(64) NOT NULL DEFAULT '',
  PRIMARY KEY (`guid`),
  UNIQUE KEY `idx_entry` (`entry`)
) ENGINE=MyISAM AUTO_INCREMENT=21 DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Transports';

-- ----------------------------
-- Records of transports
-- ----------------------------
INSERT INTO `transports` VALUES ('1', '176495', 'Campement Grom\'Gol et Fossoyeuse (\"The Purple Princess\")', '315026', '');
INSERT INTO `transports` VALUES ('2', '176310', 'Port de Hurlevent et Auberdine (\"Ship (The Bravery)\")', '234510', '');
INSERT INTO `transports` VALUES ('3', '176244', 'Teldrassil et Auberdine (\"The Moonspray\")', '312317', '');
INSERT INTO `transports` VALUES ('4', '176231', 'Port de Menethil et L\'ile de Theramore (\"The Lady Mehley\")', '230162', '');
INSERT INTO `transports` VALUES ('5', '175080', 'Campement Grom\'Gol et Orgrimmar (\"The Iron Eagle\")', '248990', '');
INSERT INTO `transports` VALUES ('6', '164871', 'Orgrimmar et Fossoyeuse (\"The Thundercaller\")', '239253', '');
INSERT INTO `transports` VALUES ('7', '20808', 'Cabestan et Baie-du-butin (\"The Maiden\'s Fancy\")', '231236', '');
INSERT INTO `transports` VALUES ('8', '177233', 'La cote oubliée et l\'ile de sardor (\"Feathermoon Ferry\")', '259747', '');
INSERT INTO `transports` VALUES ('9', '181646', 'ile de brume-azur et Auberdine (\"Elune\'s Blessing\")', '238707', '');
INSERT INTO `transports` VALUES ('10', '181688', 'Valgarde et Port de Menethil (\"Northspear\")', '445534', '');
INSERT INTO `transports` VALUES ('11', '181689', 'Fossoyeuse et Accostage de la Vengeance (\"Zeppelin, Horde (Cloudkisser)\")', '214579', '');
INSERT INTO `transports` VALUES ('12', '186238', 'Orgrimmar et Bastion Chanteguerre (\"Zeppelin, Horde (The Mighty Wind)\")', '302705', '');
INSERT INTO `transports` VALUES ('13', '186371', 'Zeppelin Voler (\"Zeppelin\")', '484211', '');
INSERT INTO `transports` VALUES ('14', '187038', 'Bateau Pirate (\"Sister Mercy\")', '307953', '');
INSERT INTO `transports` VALUES ('15', '187568', 'Navire Tortue du port Moa\'ki (\"Turtle (Walker of Waves)\")', '445220', '');
INSERT INTO `transports` VALUES ('16', '188511', 'Navire Tortue Unu\'pe (\"Turtle (Green Island)\")', '502354', '');
INSERT INTO `transports` VALUES ('17', '190536', 'Porte d\'Hurlevent et Donjon de la bravoure, Toundra Boreenne (\"Le Kraken\") ', '271979', '');
INSERT INTO `transports` VALUES ('18', '192241', 'Not boardable - Horde gunship patrolling above Icecrown (\"Orgrim\'s Hammer\")', '1424158', '');
INSERT INTO `transports` VALUES ('19', '192242', 'Not boardable - Alliance gunship patrolling above Icecrown (\"Le Brise-ciel\")', '1051387', '');
INSERT INTO `transports` VALUES ('20', '190549', 'Orgrimmar et Les Pitons du Tonnerre', '566000', '');
