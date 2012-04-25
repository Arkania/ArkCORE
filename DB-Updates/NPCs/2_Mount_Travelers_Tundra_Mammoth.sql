-- Traveler's Tundra Mammoth Vendor Npc_flags
UPDATE creature_template SET npcflag = 7296 WHERE entry = 32639; -- Gnimo "Adventurous Tinker"
UPDATE creature_template SET npcflag = 896 WHERE entry = 32638; -- Hakmud of Argus "Traveling Trader"
UPDATE creature_template SET npcflag = 7296 WHERE entry = 32641; -- Drix Blackwrench "The Fixer"
UPDATE creature_template SET npcflag = 896 WHERE entry = 32642; -- Mojodishu "Traveling Trader"

-- Traveler's Tundra Mammoth Vendors
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (32640, 32633);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, summontype) VALUES
(32640,32642,1,1, 'Traveler Mammoth (H) - Vendor', 8),
(32640,32641,2,1, 'Traveler Mammoth (H) - Vendor & Repairer', 8),
(32633,32638,1,1, 'Traveler Mammoth (A) - Vendor', 8),
(32633,32639,2,1, 'Traveler Mammoth (A) - Vendor & Repairer', 8);