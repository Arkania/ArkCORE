-- DB/REFERENCES LOOT: Fix all reference loots on startup
-- Please if you delete some ref loot be sure you delete on reference_loot_template as well
DELETE FROM `reference_loot_template` WHERE `entry` IN (10006,10008,10009,10010,10011,10020,34172,34241,34252,34278,34285,34286,34287,34288,34289,34290,34291,34292,34293,35037,35041,45010,50012);
-- Deleting un used disenchant reference loot
DELETE FROM `disenchant_loot_template` WHERE `mincountOrRef` IN (-44012);
