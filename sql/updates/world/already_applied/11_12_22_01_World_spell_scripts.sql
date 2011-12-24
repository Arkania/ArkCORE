-- DB/SPELL SCRIPTS: This fix all errors with spell scripts on startup
-- SPELL SCRIPT: Remove new format for spell script don't support on SkyFire
DELETE FROM `spell_scripts` WHERE `id` IN (43709,51662);
-- EVENTSCRIPTS: Deleting some event scripts for +4.1 items
DELETE FROM `event_scripts` WHERE `id` IN (2609);