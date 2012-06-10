-- Westfall Quest Update Version 2
-- For Arkania
-- By Jorex

-- Add a gameobject as a spellfocus for Two-shoed Lou's Old House
DELETE FROM gameobject_template WHERE entry='410000';
INSERT INTO gameobject_template(entry,`type`,NAME,data0,data1,data4) VALUES (410000,8,'Jangolode',1672,30,26228);
DELETE FROM gameobject WHERE id='410000';
SET @GO_JANGOLODE_TRIGGER='8';
INSERT INTO gameobject VALUES (@GO_JANGOLODE_TRIGGER,'410000','0','1','1','-9845.54','1397.84','37.178','0.885095','0','0','0.428243','0.903664','300','0','1');

-- Delete the SAI scripts, as the scripts is now a C++ one

-- Quest 26228
UPDATE creature_template SET VehicleId='899',AIName='',ScriptName='npc_OldHouse',unit_flags='16777216' WHERE entry='42500';
UPDATE creature_template SET unit_flags='33554432' WHERE entry='42515';
DELETE FROM creature WHERE id='42500';
UPDATE creature_template SET AIName='' WHERE entry IN (42515,42492);
DELETE FROM creature_text WHERE entry IN (42515,42492);
DELETE FROM smart_scripts WHERE entryOrGuid IN (42500,42515,42492);

-- Quest 26271
DELETE FROM creature_text WHERE entry='42384' AND groupid>'0';
DELETE FROM creature_text WHERE entry='42386';
DELETE FROM creature_text WHERE entry='42617';
UPDATE creature_template SET AIName='' WHERE entry='42617';
DELETE FROM smart_scripts WHERE entryorguid='42617';