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
/*Table structure for table `areatrigger_involvedrelation` */

DROP TABLE IF EXISTS `areatrigger_involvedrelation`;

CREATE TABLE `areatrigger_involvedrelation` (
  `id` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Identifier',
  `quest` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Quest Identifier',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='CTDB Trigger System';

/*Data for the table `areatrigger_involvedrelation` */

insert  into `areatrigger_involvedrelation`(`id`,`quest`) values (2946,6421),(3367,6025),(482,1699),(216,870),(98,201),(78,155),(87,76),(88,62),(3986,8286),(4071,9193),(4200,9607),(4201,9608),(4291,9701),(4293,9716),(4298,9731),(4300,9752),(4301,9786),(175,455),(4473,10269),(4475,10275),(2926,25),(171,273),(4064,9160),(4170,9400),(4280,9700),(4581,10750),(4588,10772),(4963,11652),(4899,11890),(4950,12036),(4986,12263),(5003,12506),(2486,4811),(1205,2989),(231,984),(246,1149),(232,984),(235,984),(173,437),(5500,14016),(169,287),(522,1719),(6126,26258),(6221,27007),(6216,27006),(0,14071);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
