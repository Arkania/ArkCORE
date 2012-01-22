-- Beauty (Blackrock Caverns) Updates
-- by Naios

-- Updates Runtys Spawn Entry
UPDATE `creature` SET `position_x`=80.893784, `position_y`=613.032349, `position_z`=77.153633, `orientation`=0.766913, `spawndist`=0, `MovementType`=0 WHERE `guid`=1051252 LIMIT 1;

-- Adds Ranty a Sleep Emote
REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(1051252, 0, 0, 0, 1, 0, '78677 0');

-- Updates the Walking Radius for all other Dogs
UPDATE `creature` SET `spawndist`=4.5 WHERE `guid` IN (1051256, 1051250, 1051254, 1051248) LIMIT 4;

-- Buster is al little bit too far away
UPDATE `creature` SET `position_x`=132.782028, `position_y`=566.306030, `position_z`=76.398201, `orientation`=5.994582 WHERE `guid`=1051256 LIMIT 1;
