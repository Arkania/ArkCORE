-- Fix loot for ww.wowhead.com/spell=78866
DELETE FROM spell_loot_template WHERE entry=78866;
INSERT INTO spell_loot_template VALUES 
(78866, 52325, 0,1,1,14,16),
(78866, 52326, 0,1,1,14,16),
(78866, 52327, 0,1,1,14,16),
(78866, 52328, 0,1,1,14,16);
