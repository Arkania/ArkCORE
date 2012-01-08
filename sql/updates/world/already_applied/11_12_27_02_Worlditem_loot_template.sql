-- DB/ITEM LOOT: Fix all item loots template erros on startup
-- Mysterious Egg Don't need any loot is controling be script
-- Script: Item::GenerateItemRandomPropertyId(39883));
DELETE FROM `item_loot_template` WHERE entry=39878;