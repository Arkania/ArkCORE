-- DB/GAMEOBJECTS: This fix all errors with gameobject template on startup
-- 22,"Archaeology","Fragments",466,0, (Extract from locktypes DBC)
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208751';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208676';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208679';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208682';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208685';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208688';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208691';
-- Need correct openid
UPDATE `gameobject_template` SET `data0`='1479', `data1`='0' WHERE `entry`='208694';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208691';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208697';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208700';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `entry`='208703';
-- Correct global openid
UPDATE `gameobject_template` SET `data1`='1479' WHERE `data1`='1956';
-- Need correct openid
UPDATE `gameobject_template` SET `data1`='0', `data1`='0', `data5`='0', `type`='5'  WHERE `entry`='204422';
-- Correct type and flags.
UPDATE `gameobject_template` SET `data0`='0', `type`='10', `flags`='4' WHERE `entry`='208715';
-- Correct type and flags.
UPDATE `gameobject_template` SET `data0`='1479', `flags`='4' WHERE `entry`='208757';
-- Correct type and flags.
UPDATE `gameobject_template` SET `data0`='1479', `flags`='4' WHERE `entry`='208775';
-- Correct type and flags.
UPDATE `gameobject_template` SET `data0`='1479', `flags`='4' WHERE `entry`='208779';
-- Correct type and flags.
UPDATE `gameobject_template` SET `data0`='1479', `flags`='4' WHERE `entry`='208829';
-- Correct type and flags.
UPDATE `gameobject_template` SET `data0`='1479', `flags`='4' WHERE `entry`='208880';
-- Correct type and flags.
UPDATE `gameobject_template` SET `data0`='1479',`flags`='4' WHERE `entry`='207406';
-- Is a quest giver so need correct data and loctype 22 (Archaeology)
UPDATE `gameobject_template` SET `data0`='22', `data1`='28799' WHERE `entry`='207407';
-- Is a quest giver so need correct data and loctype 22 (Archaeology) 
UPDATE `gameobject_template` SET `data0`='22', `data1`='28800' WHERE `entry`='207408';
-- Is a quest giver so need correct data and loctype 22 (Archaeology) 
UPDATE `gameobject_template` SET `data0`='22', `data1`='28801' WHERE `entry`='207409';
-- Is a quest giver so need correct data and loctype 22 (Archaeology) 
UPDATE `gameobject_template` SET `data0`='22', `data1`='28802' WHERE `entry`='207410';
-- Spell effect
UPDATE `gameobject_template` SET `data0`='85040' WHERE `entry`='207690';
-- Spell effect
UPDATE `gameobject_template` SET `data0`='59065' WHERE `entry`='209080';
-- Spell effect
UPDATE `gameobject_template` SET `data0`='17609' WHERE `entry`='209081';
-- Spell effect
UPDATE `gameobject_template` SET `data0`='1', `data1`='0' WHERE `entry`='500001';
-- GOB: Zanzil's Cauldron of Burning Blood deleting objetc for 4.1 clients
DELETE FROM `gameobject_template` WHERE `entry`='208313';
-- GOB: Zanzil's Cauldron of Toxic Torment deleting objetc for 4.1 clients
DELETE FROM `gameobject_template` WHERE `entry`='208315';
-- GOB: Zanzil's Cauldron of Frostburn Formula deleting objetc for 4.1 clients
DELETE FROM `gameobject_template` WHERE `entry`='208314';
-- GOB: Extra Parachutes deleting no existing GOB
DELETE FROM `gameobject_template` WHERE `entry`='208325';
-- GOB: Pile of Ash deleting objetc for 4.1 clients
DELETE FROM `gameobject_template` WHERE `entry`='208381';
-- GOB: Fool's Gold deleting objetc for 4.1 clients
DELETE FROM `gameobject_template` WHERE `entry`='208436';
-- GOB: Rappelling Rope deleting objetc for 4.1 clients
DELETE FROM `gameobject_template` WHERE `entry`='208570';
-- GOB: Haunted War Drum deleting objetc for 4.1 clients
DELETE FROM `gameobject_template` WHERE `entry`='208591';
-- GOB: Empty Plaque deleting objetc for 4.1 clients
DELETE FROM `gameobject_template` WHERE `entry`='208860';
-- GOB: Mulgore Sweet Potatoes deleting objetc is a item no a gob
DELETE FROM `gameobject_template` WHERE `entry`='208887';
-- GOB: Savory Spice Herbs deleting objetc for 4.1 clients
DELETE FROM `gameobject_template` WHERE `entry`='208888';
-- GOB: Fresh-Caught Fish deleting objetc is a item no a gob (4.1 client)
DELETE FROM `gameobject_template` WHERE `entry`='208889';
-- GOB: Fresh-Hunted Fowl deleting objetc is a item no a gob (4.1 client)
DELETE FROM `gameobject_template` WHERE `entry`='208890';
-- GOB: Portal to the Firelands Deleting Firelands are for 4.2 clients
DELETE FROM `gameobject_template` WHERE `entry`='208900';
-- GOB: Portal to the Firelands Deleting Firelands are for 4.2 clients
DELETE FROM `gameobject_template` WHERE `entry`='208552';
-- GOB: Portal to the Firelands Deleting Firelands are for 4.2 clients
DELETE FROM `gameobject_template` WHERE `entry`='208552';