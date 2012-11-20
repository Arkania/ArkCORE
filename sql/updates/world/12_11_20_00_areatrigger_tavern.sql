/*
SQLyog Community v10.3 
MySQL - 5.5.24-0ubuntu0.12.04.1 : Database - 22dev_ark
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `areatrigger_tavern` */

DROP TABLE IF EXISTS `areatrigger_tavern`;

CREATE TABLE `areatrigger_tavern` (
  `id` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Identifier',
  `name` text,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='CTDB Trigger System';

/*Data for the table `areatrigger_tavern` */

insert  into `areatrigger_tavern`(`id`,`name`) values (71,'Westfall - Sentinel Hill Inn'),(562,'Elwynn Forest - Goldshire - Lion\'s Pride Inn'),(682,'Redridge Mountains - Lakeshire Inn'),(707,'Duskwood - Darkshire - Scarlet Raven Inn'),(708,'Hillsbrad Foothills - Southshore Inn'),(709,'Dustwallow Marsh - Theramore Isle'),(710,'Dun Morogh - Kharanos - Thunderbrew Distillery'),(712,'Loch Modan - Thelsamar - Stoutlager Inn'),(715,'Teldrassil - Dolanaar'),(717,'Ashenvale - Astranaar'),(719,'Tirisfal Glades - Brill - Gallows\' End Tavern'),(721,'Hillsbrad Foothills '),(722,'Mulgore '),(742,'The Barrens '),(743,'The Barrens '),(843,'Durotar '),(844,'Swamp of Sorrows '),(862,'Stranglethorn Vale '),(4241,'Bloodmyst Isle Blood Watch Inn'),(1022,'Stonetalon Mountains '),(1023,'Tanaris '),(1024,'Feralas '),(1606,'Badlands '),(1646,'Arathi Highlands '),(2266,'Desolace '),(2267,'Desolace '),(2287,'Winterspring '),(2610,'Ashenvale '),(2786,'Stormwind backup rest'),(4108,'Tranquillien Inn'),(4240,'Auzre Watch Inn'),(4336,'Thrallmar Inn'),(4337,'Honor Hold Inn'),(4373,'Zabra jin Inn'),(4375,'Garadar Inn'),(4376,'Telaar Inn'),(4377,'Allerian Stronghold Inn'),(4382,'Cenarion Refuge'),(4526,'Shadowmoon Village Inn'),(4528,'Wildhammer Stronghold Inn'),(4595,'Mok\'Nathal Village Inn'),(4607,'Sanctum of the Stars Inn'),(4374,'Telredor Inn'),(4383,'Orebor Harborage Inn'),(4381,'Temple Of Thelamat Inn'),(4499,'Sylvanaar Inn'),(4558,'Toshlay\'s Station Inn'),(4494,'Thunderlord Stronghold Inn'),(4640,'Evergrove Inn'),(4521,'Area 52 Inn'),(4555,'The Stormspire Inn'),(4577,'Altar of Sha\'tar Inn'),(178,'Strahnbrad'),(1042,'Wildhammer Keep'),(3690,'Revantusk Village'),(3886,'Grom\'gol Base Camp'),(4058,'Light\'s Hope Chapel'),(3985,'Cenarion Hold'),(4090,'Stonetalon Peak'),(3547,'The Undercity'),(4769,'The City of Ironforge'),(4714,'Mudsprocket Inn'),(4775,'Brackenwall Village Inn'),(4847,'Isle of Quel\'Danas, Sun\'s Reach Harbor Inn'),(4961,'Valiance Keep Inn'),(4867,'Fizzcrank Airstrip Inn'),(4977,'Unu\'pe Inn'),(4868,'Taunka\'le Village Inn'),(4910,'Warsong Hold'),(4861,'Bor\'gorok Outpost Inn'),(4755,'Camp Winterhoof Inn'),(4756,'Fort Wildervar Inn'),(5045,'Agmar\'s Hammer'),(4964,'Stars\'s Rest'),(4965,'Amberpine Lodge Inn'),(4966,'Westfall Brigae Encampment'),(4967,'Camp Oneqwah'),(4970,'Conquest Hold'),(4975,'Moa\'Ki Harbor'),(4976,'Kamagua'),(4979,'Venomspite'),(4993,'Wintergarde Keep'),(5030,'Spearborn Encampment'),(5062,'The Argent Strand'),(5164,'Zim\'Torga'),(5182,'Frosthold'),(5183,'K3'),(5200,'Brunnhildar Village'),(5204,'Bouldercrag\'s Refugee'),(5217,'Nesingwary Base Camp'),(5227,'Argent Vanguard'),(5323,'Camp Tunka\'lo'),(5327,'Krasus\' Landing'),(4753,'Westguard Inn'),(4265,'Fairbreeze Village Inn'),(2746,'Stormwind City'),(98,'Nesingwary\'s Expedition'),(262,'Razorfen Kraul'),(4109,'Ghostlands, Tranquillen, Top of Inn'),(4300,'Zangarmarsh, Cenarion Refugee, Outside Inn'),(4378,'Terokkar Forest, Stonebreaker Hold, Inn'),(4380,'Hellfire Peninsula, Falcon Watch, Inn'),(4498,'Old Hillsbrad Foothills, Inn'),(4502,'Old Hillsbrad Foothills, behind Inn'),(4529,'Shadowmoon Valley, Wildhammer Stronghold, Inn bedroom'),(4608,'Shadowmoon Valley, Sanctum Of The Stars, Inn, in air'),(5314,'Wyrmrest - Dragonblight inn'),(5315,'Wyrmrest Temple'),(5316,'Wyrmrest Temple'),(5317,'Wyrmrest Temple'),(2286,'Thousand Needles ');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
