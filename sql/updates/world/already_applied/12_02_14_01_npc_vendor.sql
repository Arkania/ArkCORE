-- Additem 46325
-- By mikadmin for arkania

DELETE FROM `npc_vendor` WHERE (`entry`=33980);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(33980, 1, 46325, 0, 0, 0);