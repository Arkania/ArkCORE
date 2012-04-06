-- Fix for some hunter trainer spellcosts
-- For Arkania
-- By Jorex


-- Fix Hunter trainer wrong cost for spells (source wowhead)
UPDATE npc_trainer SET spellcost='110' WHERE spell='6991';
UPDATE npc_trainer SET spellcost='110' WHERE spell='79682';
UPDATE npc_trainer SET spellcost='110' WHERE spell='2641';
UPDATE npc_trainer SET spellcost='680' WHERE spell='1462';
UPDATE npc_trainer SET spellcost='680' WHERE spell='34026';
UPDATE npc_trainer SET spellcost='1076' WHERE spell='1978';