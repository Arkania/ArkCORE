-- Fix recent issues with npcs in Tol Barad, Vortex Pinnacle, Blackrock Caverns and Grim Batol.
-- By Nanaki for Arkania

UPDATE creature SET `npcflag`=0, `unit_flags`=0, `dynamicflags`=0 WHERE `map` IN (645, 657, 670, 732);