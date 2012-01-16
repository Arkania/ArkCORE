-- Stonefather's Boon (Deepholm) Questfix
-- by Naios for Arkania

-- UPDATE `item_template` SET `spellid_1`=80670 WHERE `entry`=58884 LIMIT 1;

UPDATE `creature_template` SET `ScriptName`='npc_stonefathers_banner' WHERE `entry`=43163 LIMIT 1;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 80670;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`)
VALUES (80670, 80658, 1, 'Quest: Stonefathers Boon Spell (Deepholm)');

-- Adds Visual a Aura to the Banner
REPLACE INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`)
VALUES (43163, 0, 0, 0, 0, 0, '80664 0');
