CREATE TABLE IF NOT EXISTS `spell_override` (
	`overrideSpell` int(10) unsigned NOT NULL default '0',
	`affSpell` int(10) NOT NULL default '0', 
	`aura` int(10) NOT NULL default '0', 
	`comment` longtext NOT NULL default '',
	PRIMARY KEY	(`overrideSpell`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

REPLACE INTO spell_override VALUES
(93402, 8921, 48517, "Eclipse (Solar)"),
(91711, 6229, 9173,  "Nether Ward Talent"),
(92315, 11366, 0,  "Pyroblast !"),
(82928, 19434, 0, "Fire !"),
(89420, 689,  0,  "Drain Life"),
(81170, 6785, 0,  "Ravage"),
(91183, 82731, 0,  "Frostfire orb"),
(88625, 2050, 0,  "Chakra Sereinity"),
(86213, 86121, 0,  "Soul Swap: Exhale"),
(88684, 88625, 0,  "Chackra"),
(88685, 88625, 0,  "Chackra");