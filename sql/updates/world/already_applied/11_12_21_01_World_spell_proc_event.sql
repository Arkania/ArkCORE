-- DB/SPELL PROC: Fix all errors with spell procs on start up
-- SPELL: Delete don't existed spell
DELETE FROM `spell_proc_event` WHERE `entry` IN (31834);
-- SPELL: Arcane Missiles Aurastate is not a trigger spell (http://www.wowhead.com/spell=79808)
DELETE FROM `spell_proc_event` WHERE `entry` IN (79808);