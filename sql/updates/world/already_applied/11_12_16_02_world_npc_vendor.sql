-- Fix Tamar <Leatherworking Supplies> in Orgrimmar
-- http://www.wowhead.com/npc=3366
-- Remove Pattern: Drakehide Leg Armor which was added in patch 4.2.0
-- http://www.wowhead.com/item=71721
 
DELETE FROM `npc_vendor` WHERE `entry`=3366 AND `item`=71721;
 
-- Fix Isabel Jones <Jewelcrafting Design Vendor> in Stormwind City
-- http://www.wowhead.com/npc=50480
-- Remove Design: Punisher's Band which was added in patch 4.1.0
-- http://www.wowhead.com/item=69853
 
DELETE FROM `npc_vendor` WHERE `entry`=50480 AND `item`=69853;
 
-- By Maibenrai