-- Fix Holy light from paladin trainers (wrong level and cost)
-- For Arkania
-- By Jorex


-- Change level (7) and cost (2s84c) for training for Holy Light (635) http://www.wowhead.com/spell=635

UPDATE npc_trainer SET reqlevel='7',spellcost='284' WHERE spell='635'