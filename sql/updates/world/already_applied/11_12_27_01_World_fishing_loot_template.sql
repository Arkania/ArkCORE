-- ---------
-- DB/FISHING: This fix all error on fix loor template
-- ---------
-- FISHING: Change area 58503 to 5390 Stormwind area (http://www.wowhead.com/item=58503)
UPDATE `fishing_loot_template` SET `entry`='5390' WHERE `entry` IN (58503);