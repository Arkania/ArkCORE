-- Priest: Lightwell fix
-- by Naios for Arkania

-- Fixes the problem that the Lightwell is death on summon
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-59907 AND `spell_effect`=7 AND `type`=0 LIMIT 1;
