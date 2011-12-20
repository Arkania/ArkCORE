-- DB/MILLING: This fix all milling error on startup
-- Gems is not a herb
DELETE FROM `milling_loot_template` WHERE `entry` IN ('52183','52185','53038');