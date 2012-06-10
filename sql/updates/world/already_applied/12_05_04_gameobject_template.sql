-- Portal Tol-Barad
-- By mikadmin & loonix For Arkania
-- Fix portal to Stormwind & Orgrimmar

-- stormwind
UPDATE `gameobject_template` SET `data0` = '17334' WHERE `gameobject_template`.`entry` =208227;

-- Orgrimmar
UPDATE `gameobject_template` SET `data0` = '17609' WHERE `gameobject_template`.`entry` =208226; 