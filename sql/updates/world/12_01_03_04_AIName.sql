-- DB/AIName: Scriptnames or AI only can be set on normal mode
-- Twilight Hatchling AI or Scriptnames only can be set on normal mode (http://www.wowhead.com/npc=39388)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`='39388';
UPDATE `creature_template` SET `AIName`='' WHERE `entry`='48832';

-- Faceless Corruptor Scriptnames or AI only can be set on normal mode (http://www.wowhead.com/npc=40600)
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`='48844';