CREATE TABLE IF NOT EXISTS `factures` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `from_uid` varchar(255) DEFAULT NULL,
  `to_uid` varchar(255) DEFAULT NULL,
  `name_from` varchar(255) DEFAULT NULL,
  `name_to` varchar(255) DEFAULT NULL,
  `details` varchar(10000) DEFAULT NULL,
  `price` int(11) DEFAULT NULL,
  `payed` int(11) NOT NULL DEFAULT '1',
  `create_date` varchar(50) DEFAULT NULL,
  `payed_date` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4;
