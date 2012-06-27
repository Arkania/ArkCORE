/*
Navicat MySQL Data Transfer

Source Server         : Wylandra
Source Server Version : 50515
Source Host           : 127.0.0.1:3306
Source Database       : world

Target Server Type    : MYSQL
Target Server Version : 50515
File Encoding         : 65001

Date: 2011-09-14 19:28:55
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `locales_achievement_reward`
-- ----------------------------
DROP TABLE IF EXISTS `locales_achievement_reward`;
CREATE TABLE `locales_achievement_reward` (
  `entry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `subject_loc1` varchar(100) NOT NULL DEFAULT '',
  `subject_loc2` varchar(100) NOT NULL DEFAULT '',
  `subject_loc3` varchar(100) NOT NULL DEFAULT '',
  `subject_loc4` varchar(100) NOT NULL DEFAULT '',
  `subject_loc5` varchar(100) NOT NULL DEFAULT '',
  `subject_loc6` varchar(100) NOT NULL DEFAULT '',
  `subject_loc7` varchar(100) NOT NULL DEFAULT '',
  `subject_loc8` varchar(100) NOT NULL DEFAULT '',
  `text_loc1` text,
  `text_loc2` text,
  `text_loc3` text,
  `text_loc4` text,
  `text_loc5` text,
  `text_loc6` text,
  `text_loc7` text,
  `text_loc8` text,
  PRIMARY KEY (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of locales_achievement_reward
-- ----------------------------
INSERT INTO `locales_achievement_reward` VALUES ('45', '', 'Vous avez bien bourlingué !', '', '', '', '', '', '', null, 'Eh ben, vous !\n\nEt moi qui croyais avoir tout vu sur ces terres gelées ! Le feu de l\'exploration brûle en vous. Cela saute à mes yeux de nain.\n\nPortez ce tabard avec fierté. De cette façon, vos amis sauront toujours à qui demander leur chemin en temps voulu !\n\nRestez bien en selle !\n\nBrann Barbe-de-bronze', null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('46', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('230', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('456', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('614', '', 'Pour l\'Alliance !', '', '', '', '', '', '', null, 'La guerre fait rage sur nos terres. Seuls les héros les plus courageux osent frapper la Horde en ses points les plus sensibles. Vous êtes l\'un d\'eux.\n\nLes coups que vous avez portés au commandement de la Horde vont nous permettre de lancer notre assaut final. La Horde fléchira sous la puissance de l\'Alliance.\n\nVos actes seront récompensés. Chevauchez avec fierté !\n\n— Votre roi', null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('619', '', 'Pour la Horde !', '', '', '', '', '', '', null, 'En ces temps troublés, nos souffrances engendrent de vrais héros. Vous êtes l\'un d\'eux.\n\nNous sommes en guerre. Vos efforts soutiennent notre cause en Azeroth. Vos hautes actions seront récompensées. Prenez ce prix d\'Orgrimmar et chevauchez vers la gloire.\n\nPour la Horde !\n\nChef de guerre Thrall', null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('714', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('762', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('870', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('871', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('876', '', 'Je vous surveille , enfent.', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('907', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('913', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('942', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('943', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('945', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('948', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('953', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('978', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1015', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1021', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1038', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1039', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1174', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1175', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1250', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1400', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1402', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1516', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1563', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1656', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1657', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1658', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1681', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1682', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1683', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1684', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1691', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1692', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1693', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1707', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1784', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1793', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('1956', '', 'Lectures studieuses', '', '', '', '', '', '', null, 'Félicitations ! Vous avez terminé d\'étudier « Les écoles de magie des arcanes ». En récompense de votre dévouement, veuillez trouver ci-joint le volume spécial qui termine la collection.\n\nJe pense que vous trouverez ce tome particulièrement divertissant. Mais je vous laisse le découvrir par vous-même.\n\nCordialement,\n\nRhonin', null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2051', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2054', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2096', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2136', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2143', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2144', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2145', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2186', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2187', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2188', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2336', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2516', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2536', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2537', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2760', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2761', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2762', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2763', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2764', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2765', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2766', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2767', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2768', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2769', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2797', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2798', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2816', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2817', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2903', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2904', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2957', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('2958', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('3036', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('3037', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('3117', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('3259', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('3316', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('3478', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('3656', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('3857', '', 'Maître de l\'île des Conquérants', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('3957', '', 'Maître de l\'île des Conquérants', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4078', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4079', '', 'Une offrande à l\'immortalité', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4080', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4156', '', 'Une offrande à l\'immortalité', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4477', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4478', '', 'Groupe improvisé', '', '', '', '', '', '', null, '$gCher membre assidu:Chère membre assidue;,\n\nnous aimerions récompenser votre ténacité à parcourir les donjons avec des personnes que vous n\'aviez probablement jamais rencontrées auparavant. Vous avez peut-être même appris les ficelles du métier à quelques petits nouveaux.\n\nBref, nous avons entendu dire que vous aimiez les groupes improvisés. Alors voici le petit Groopy, qui proclamera à tout le monde : « Vous savez quoi ? J\'suis groupé ! »\n\nAvec toute notre affection,\n\nVos amis de l\'équipe de développement de WoW', null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4530', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4583', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4584', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4597', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4598', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4602', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4603', '', 'Gloire à l\'écumeur de raids de la Couronne de glace', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4784', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
INSERT INTO `locales_achievement_reward` VALUES ('4785', '', '', '', '', '', '', '', '', null, null, null, null, null, null, null, null);
