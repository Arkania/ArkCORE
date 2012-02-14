-- Signet of High Arcanist Savor
-- By Mikadmin for Arkania
-- fix characteristic 

UPDATE `world`.`item_template` SET `stat_type1` = '7',
`stat_value1` = '286',
`stat_type2` = '5',
`stat_value2` = '190',
`stat_type3` = '31',
`stat_value3` = '121',
`stat_type4` = '32',
`stat_value4` = '131' WHERE `item_template`.`entry` =67129;