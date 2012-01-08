-- Drahga Shadowburner (Grim Batol) Updates
-- by Naios

-- Valiona spawning is now handled over the Script
DELETE FROM `creature` WHERE `id` = 40320 AND `map` = 670;

-- Who added SmartAI to Valiona? ^^
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_valiona_gb' WHERE `entry`=40320 LIMIT 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40320;

-- Changes Inhabit Type so that Valiona is able to Fly
UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=40320 LIMIT 1;

-- Add Scriptname to the invoked Flame Spirit
UPDATE `creature_template` SET `ScriptName`='mob_invoked_flame_spirit' WHERE `entry`=40357 LIMIT 1;

-- Fixes wrong Faction & Display ID of the Invocation of FLame and the Portal Trigger
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=0 WHERE `entry`=40355 LIMIT 1; -- (now it is invisible)
UPDATE `creature_template` SET `modelid2`=0, `faction_A`=14, `faction_H`=14 WHERE `entry`=40357 LIMIT 1;

-- Sets Vehicle ID for Valiona
UPDATE `creature_template` SET `VehicleId`="0" WHERE `entry`=40320 LIMIT 1;

-- Updates Healt of the Invocation of Flame to Blizzlike Values
UPDATE `creature_template` SET `Health_mod`=0.4174, `exp`=3 WHERE `entry`=40357 LIMIT 1;

-- Updates Level and Rank of the Invocation of Flame
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `rank`=3 WHERE `entry`=40357 LIMIT 1;

-- Updates Model ID of Seeping Twilight (now it is invisible)
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=0 WHERE `entry`=40365 LIMIT 1;
