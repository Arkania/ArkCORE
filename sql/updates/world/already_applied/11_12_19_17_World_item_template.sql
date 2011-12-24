-- DB/ITEMS: Fix some matiral, display etc for item template this fix all items erros.
-- Fix some material on item template
-- Fix some disenchant errors
UPDATE `item_template` SET `material`='3', `displayid`='81262' WHERE `entry`='67130'; -- Dorian's Lost Necklace
UPDATE `item_template` SET `material`='7', `displayid`='88109' WHERE `entry`='67132'; -- Grips of the Failed Immortal
UPDATE `item_template` SET `material`='7', `displayid`='94252' WHERE `entry`='67133'; -- Dizze's Whirling Robe
UPDATE `item_template` SET `material`='7', `class`='4', `subclass`='1', `displayid`='84194' WHERE `entry`='67134'; -- Dory's Finery
UPDATE `item_template` SET `material`='5' WHERE `entry`='67136'; -- Gilnean Ring of Ruination
UPDATE `item_template` SET `material`='5', `displayid`='82143' WHERE `entry`='67136'; -- Don Rodrigo's Fabulous Necklace
UPDATE `item_template` SET `material`='7', `class`='4', `subclass`='1' WHERE `entry`='67140'; -- Dory's Finery
UPDATE `item_template` SET `material`='7', `class`='4', `subclass`='1', `displayid`='84197' WHERE `entry`='67142'; -- Zom's Electrostatic Cloak 
UPDATE `item_template` SET `material`='7', `displayid`='88373' WHERE `entry`='67146'; -- Woundsplicer Handwraps
UPDATE `item_template` SET `material`='7', `displayid`='91275' WHERE `entry`='67147'; -- Je'Tze's Sparkling Tiara
UPDATE `item_template` SET `material`='5', `displayid`='82051' WHERE `entry`='67148'; -- Kilt of Trollish Dreams
UPDATE `item_template` SET `material`='5', `displayid`='88040' WHERE `entry`='67150'; -- Arrowsinger Legguards
UPDATE `item_template` SET `class`='3', `subclass`='10', `material`='4', `displayid`='61011' WHERE `entry`='68660'; -- Mystic Cogwheel
UPDATE `item_template` SET `material`='1', `displayid`='95696', `sheath`='3', `RequiredReputationRank`='6'  WHERE `entry`='68739'; -- Darkheart Hacker
UPDATE `item_template` SET `material`='1', `displayid`='95697', `sheath`='3', `RequiredReputationRank`='6', `RequiredDisenchantSkill`='-1'  WHERE `entry`='68740'; -- Darkheart Hacker
UPDATE `item_template` SET `class`='12', `subclass`='0', `material`='4', `displayid`='95981' WHERE `entry`='68768'; -- Arcanum of Vicious Strength
UPDATE `item_template` SET `class`='12', `subclass`='0', `material`='4', `displayid`='95982' WHERE `entry`='68769'; -- Arcanum of Vicious Agility
UPDATE `item_template` SET `class`='12', `subclass`='0', `material`='4', `displayid`='95979' WHERE `entry`='68770'; -- Arcanum of Vicious Intellect
UPDATE `item_template` SET `class`='12', `subclass`='0', `material`='4' WHERE `entry`='68772'; -- Greater Inscription of Vicious Intellect 
UPDATE `item_template` SET `class`='12', `subclass`='0', `material`='4' WHERE `entry`='68773'; -- Greater Inscription of Vicious Strength
UPDATE `item_template` SET `class`='12', `subclass`='0', `material`='4' WHERE `entry`='68774'; -- Greater Inscription of Vicious Agility
UPDATE `item_template` SET `material`='3', `displayid`='82551' WHERE `entry`='67137'; -- Don Rodrigo's Fabulous Necklace
UPDATE `item_template` SET `material`='5', `displayid`='88637' WHERE `entry`='67148'; -- Kilt of Trollish Dreams

-- Fix material only
-- Design: Agile Shadowspirit Diamond Some wrong data (http://www.wowhead.com/item=68781)
-- Design: Reverberating Shadowspirit Diamond Some wrong data (http://www.wowhead.com/item=68782)
-- Design: Burning Shadowspirit Diamond Some wrong data (http://www.wowhead.com/item=68783)
UPDATE `item_template` SET `material`='4' WHERE `entry` IN ('68781','68782','68783');

-- Disenchat fix
UPDATE `item_template` SET `RequiredDisenchantSkill`='225' WHERE `entry`='23461'; -- High Warlord's Quickblade

-- Morrie's Waywalker Wrap (http://www.wowhead.com/item=67135)
-- Blauvelt's Family Crest (http://www.wowhead.com/item=67139)
-- Kilt of Trollish Dreams (http://www.wowhead.com/item=67148)
-- Corefire Legplates (http://www.wowhead.com/item=67141)
UPDATE `item_template` SET `RequiredDisenchantSkill`='475' WHERE `entry` IN (67135,67139,67141,67148);

-- ITEM: Buc-Zakai Choker Disechan level req. (http://www.wowhead.com/item=67138)
UPDATE `item_template` SET `RequiredDisenchantSkill`='450' WHERE `entry`='67138';

-- ITEM: Icebone Hauberk Disechan level req. (http://www.wowhead.com/item=67143)
UPDATE `item_template` SET `RequiredDisenchantSkill`='450' WHERE `entry`='67143';

-- ITEM: Pauldrons of Edward the Odd Disechan level req. (http://www.wowhead.com/item=67144)
UPDATE `item_template` SET `RequiredDisenchantSkill`='450' WHERE `entry`='67144';

-- ITEM: Blockade's Lost Shield Disechan level req. (http://www.wowhead.com/item=67145)
UPDATE `item_template` SET `RequiredDisenchantSkill`='450' WHERE `entry`='67145';

-- ITEM: Polished Helm of Valor Wrong stats (http://www.wowhead.com/item=61931)
UPDATE `item_template` SET `stat_type1`='4', `stat_value1`='267', `stat_type2`='7', `stat_value2`='401', `stat_type3`='16', `stat_value3`='178', `stat_type4`='19', `stat_value4`='178', `stat_type5`='37', `stat_value5`='10' WHERE `entry`='61931';
-- ITEM: Tarnished Raging Berserker's Helm Wrong stats (http://www.wowhead.com/item=61935)
UPDATE `item_template` SET `stat_type1`='3', `stat_value1`='267', `stat_type2`='7', `stat_value2`='401', `stat_type3`='16', `stat_value3`='178', `stat_type4`='36', `stat_value4`='178', `stat_type5`='37', `stat_value5`='10' WHERE `entry`='61935';
-- ITEM: Mystical Coif of Elements Wrong stats (http://www.wowhead.com/item=61936)
UPDATE `item_template` SET `stat_type1`='7', `stat_value1`='401', `stat_type2`='5', `stat_value2`='267', `stat_type3`='6', `stat_value3`='178', `stat_type4`='21', `stat_value4`='178', `stat_type5`='37', `stat_value5`='10' WHERE `entry`='61936';
-- ITEM: Worn Stoneskin Gargoyle Cape Wrong stats (http://www.wowhead.com/item=62038)
UPDATE `item_template` SET `stat_type1`='4', `stat_value1`='149', `stat_type2`='7', `stat_value2`='224', `stat_type3`='19', `stat_value3`='99', `stat_type4`='28', `stat_value4`='99', `stat_type5`='37', `stat_value5`='10' WHERE `entry`='62038';

-- Deleting a no existed item on pickpocketing loot
DELETE FROM `pickpocketing_loot_template` WHERE (`entry`=46248) AND (`item`=969);