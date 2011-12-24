-- DB/QUESTRELATIONS: Fix all quest relation on startup
-- This npc don't give any quest, wowhead error, real quest giver are:
-- The Carpenter (http://www.wowhead.com/quest=27758)
-- Slinky Sharpshiv (http://www.wowhead.com/npc=46906)
-- Helix Gearbreaker Fix wrong npflag (http://www.wowhead.com/npc=47296)
UPDATE `creature_template` SET `npcflag`='0' WHERE `entry` IN ('47296');
-- Helix Gearbreaker Is not a quest giver (http://www.wowhead.com/npc=47296)
DELETE FROM `creature_questrelation` WHERE `id`=(47296);

-- Humphrey Digsong is only a quest giver (http://www.wowhead.com/npc=41910)
UPDATE `creature_template` SET `npcflag`='3' WHERE `entry`=41910;
-- Mekgineer Mixeltweed Is not a quest giver (http://www.wowhead.com/npc=46592)
DELETE FROM `creature_involvedrelation` WHERE `id`=(46592);