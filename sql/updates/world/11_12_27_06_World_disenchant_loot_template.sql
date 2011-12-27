-- DB/DISENCHANT: This fix all disenchant starup errors
-- DISENCHANT: Deleting double disenchant id
DELETE FROM `disenchant_loot_template` WHERE `entry` IN (18,87,88,89,70004,70005,70006);

-- DISENCHANT: Deleting some disechant for +4.1 items
DELETE FROM `disenchant_loot_template` WHERE `entry` IN (21);