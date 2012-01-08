-- DB/NPC TRAINER: Fix all npc trainer erros on startup
-- NPC: Arthur Huwe Is a rougue triner (http://www.wowhead.com/npc=51998)
UPDATE `creature_template` SET `npcflag`='48' WHERE `entry`='51998';
-- NPC: Calia Hastings Is a trainer (http://www.wowhead.com/npc=23566)
UPDATE `creature_template` SET `npcflag`='19' WHERE `entry`='23566';
-- NPC: Famished Bonepaw Is not a trainer (http://www.wowhead.com/npc=35811)
DELETE FROM `npc_trainer` WHERE (`entry`=35811);
