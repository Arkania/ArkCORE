-- --------------------------------------------------------
-- for Arkania 2012 - by sharq
-- Server version:               5.1.58-1~dotdeb.0 - (Debian)
-- Server OS:                    debian-linux-gnu
-- HeidiSQL version:             6.0.0.4018
-- Date/time:                    2012-03-01 11:53:45
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- Dumping structure for table world.spell_override
DROP TABLE IF EXISTS `spell_override`;
CREATE TABLE IF NOT EXISTS `spell_override` (
  `overrideSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `affSpell` int(10) NOT NULL DEFAULT '0',
  `aura` int(10) NOT NULL DEFAULT '0',
  `comment` longtext NOT NULL,
  PRIMARY KEY (`overrideSpell`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

-- Dumping data for table world.spell_override: 11 rows
/*!40000 ALTER TABLE `spell_override` DISABLE KEYS */;
INSERT INTO `spell_override` (`overrideSpell`, `affSpell`, `aura`, `comment`) VALUES
	(93402, 8921, 48517, 'Eclipse (Solar)'),
	(91711, 6229, 0, 'Nether Ward Talent'),
	(92315, 11366, 0, 'Pyroblast !'),
	(82928, 19434, 0, 'Fire !'),
	(89420, 689, 0, 'Drain Life'),
	(81170, 6785, 0, 'Ravage'),
	(91183, 82731, 0, 'Frostfire orb'),
	(88625, 2050, 0, 'Chakra Sereinity'),
	(86213, 86121, 0, 'Soul Swap: Exhale'),
	(88684, 88625, 0, 'Chackra'),
	(88685, 88625, 0, 'Chackra');
/*!40000 ALTER TABLE `spell_override` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
