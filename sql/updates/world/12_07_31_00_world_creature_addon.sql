-- Fix error consol: Creature (GUID: xxxxxx) has wrong `auras` data in `creature_addon`.
-- By Mikadmin For ARKania
-- Replace invalid entry (0 or "") by NULL

UPDATE `creature_addon` SET `auras` = NULL WHERE `guid` IN (280414, 311380, 6406389, 15426953);
UPDATE `creature_addon` SET `auras` = NULL WHERE `auras` ="";