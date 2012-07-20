-- spell_script_names
-- By Mikadmin For ARKania
-- Fix error consol : Scriptname:`xxxxxx` spell (spell_id:xxxxxx) does not exist in `Spell.dbc`.

DELETE FROM `spell_script_names` WHERE `spell_id` IN (5698, 58630, 59046, 59450, 64899, 64985, 65074, 65195, 68184, 68572, 68574);