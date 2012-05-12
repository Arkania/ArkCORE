-- Fix portals to Orgrimmar/Stormwind.

UPDATE `spell_target_position` SET `target_position_x`='1773.40', `target_position_y`='-4328.20', `target_position_z`='-8.19111' WHERE `id`=3567 LIMIT 1;
UPDATE `gameobject_template` SET `data1`='0', `data2`='1', `data3`='1' WHERE `entry`=176499 LIMIT 1;
UPDATE `gameobject_template` SET `data1`='0', `data2`='1', `data3`='1' WHERE `entry`=176296 LIMIT 1;