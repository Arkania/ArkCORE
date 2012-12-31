DROP TABLE IF EXISTS `fake_items`;
CREATE TABLE `fake_items` (
  `guid` int(10) unsigned NOT NULL,
  `fakeEntry` mediumint(8) NOT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `fake_items`
  ADD CONSTRAINT `fake_items_ibfk_1` FOREIGN KEY (`guid`) REFERENCES `item_instance` (`guid`) ON DELETE CASCADE ON UPDATE CASCADE;
