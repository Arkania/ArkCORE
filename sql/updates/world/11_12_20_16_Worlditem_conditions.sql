-- DB/CONDITIONS: Fix all conditions erros on startup
-- ITEMS: Deleting conditions for Stone Keeper's Shard (http://www.wowhead.com/item=43228)
DELETE FROM `conditions` WHERE `SourceEntry`='43228';
-- CONDITIONS: Dire Bear Form remove from patch 4.0.1 (http://www.wowwiki.com/Dire_Bear_Form)
DELETE FROM `conditions` WHERE `ConditionValue1` IN ('9634');
-- CONDITIONS: Deleting no existed conditions for gameobject
DELETE FROM `conditions` WHERE `Conditionvalue2` IN (7,6,5);
-- CONDITIONS: Deleting some wrong conditions 
DELETE FROM `conditions` WHERE `SourceEntry` IN (46350,44885,54069,56251,47005,99916);
-- CONDITIONS: Steam Cloud remove from patch 4.0.1 (http://www.wowhead.com/npc=32544)
DELETE FROM `conditions` WHERE `ConditionValue2` IN ('32544');
-- CONDITIONS: Cinder Cloud remove from patch 4.0.1 (http://www.wowhead.com/npc=32522)
DELETE FROM `conditions` WHERE `ConditionValue2` IN ('32522');
-- CONDITIONS: Deleteing not needed condition for loot
DELETE FROM `conditions` WHERE `SourceGroup` IN ('13755');
-- CONDITIONS: Deleteing some old fishing loots conditions
DELETE FROM `conditions` WHERE `SourceGroup` IN ('1117','1121','1120');
-- CONDITIONS: Deleteing some old loots conditions
DELETE FROM `conditions` WHERE `SourceGroup` IN ('192052','192053','192054','192057','10189','10854','25671','15521','11026','10016','3862','4362','3140','307','3317','297','440','192050','1108','342','8934','10215','21251','10211','1227','1222','13465','192049','192046','192051','25331','24742');
-- CONDITIONS: Deleting conditions for old quest The Charge of the Dragonflights
DELETE FROM `conditions` WHERE `ConditionValue1`='8555';
-- CONDITIONS: Deleting a not existed spell confition
DELETE FROM `conditions` WHERE `ConditionTypeOrReference` IN (6495);
-- Blackwhelp Net fix target condition
UPDATE `conditions` SET `ConditionTypeOrReference`='24' WHERE `SourceEntry` IN (31129);
-- Wolpertinger Net
UPDATE `conditions` SET `ConditionTypeOrReference`='24' WHERE `SourceEntry` IN (32907);
-- condition type 24 
UPDATE `conditions` SET `ConditionTypeOrReference`='24' WHERE `SourceEntry` IN (33069);
-- Eyesore Blaster only target The Oculus
UPDATE `conditions` SET `ConditionTypeOrReference`='24' WHERE `SourceEntry` IN (30740);
-- Potent Explosive Charge only targets Hulking Jormungar
DELETE FROM `conditions` WHERE `SourceEntry` IN (30740);
-- Potent Explosive Charge requires target to be below 80% HP
DELETE FROM `conditions` WHERE `SourceEntry` IN (47305);
-- Techno-Grenade should only target Repaired Mechano-Tanks
UPDATE `conditions` SET `ConditionTypeOrReference`='24' WHERE `SourceEntry` IN (58200);
-- Get our boys back - target Injured Stormwind Infantry
DELETE FROM `conditions` WHERE `SourceEntry` IN (93072);
-- Wrong item condition target
DELETE FROM `conditions` WHERE `ConditionValue1` IN (21387,23487,4351,42224,4352);
-- Wrong spell item
DELETE FROM `conditions` WHERE `SourceEntry` IN (29818,45005,11170);
-- Deleting not existed spell
DELETE FROM `conditions` WHERE `ConditionValue1` IN (6495);

