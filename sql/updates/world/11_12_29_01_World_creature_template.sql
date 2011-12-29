-- Forgemaster Throngus (Grim Batol) Updates
-- by Naios

-- Fire Patch
-- Makes the Fire invisible
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=0 WHERE `entry`=48711 LIMIT 1;

-- Twilight Archer
-- Inserts Scriptname
UPDATE `creature_template` SET `ScriptName`='mob_twilight_archer' WHERE `entry`=40197 LIMIT 1;

-- Changes Inhabit Type so that the Twilight Archer are able to Fly
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=40197 LIMIT 1;

-- Makes the Twilight Archer invisible
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=0 WHERE `entry`=40197 LIMIT 1;

-- Faction fix
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry`=40197 LIMIT 1;
