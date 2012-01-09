-- Elemental Energy (Deepholm) Questfix
-- by Naios for Arkania

UPDATE `creature_template` SET `ScriptName`='npc_lodestone' WHERE `entry` IN (43258, 43254) LIMIT 2;
UPDATE `creature_template` SET `unit_flags`=4 WHERE `entry`=45088 LIMIT 1;
