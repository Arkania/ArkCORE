-- Fix error consol: invalid entry
-- By Mikadmin For ARKania
-- entry for patch 4.3

DELETE FROM `npc_vendor` WHERE `entry` = 14828;
