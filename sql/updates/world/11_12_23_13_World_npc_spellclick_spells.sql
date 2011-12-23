-- DB/CREATURE TEMPLATE: Temporaly fix for spellclick (seems is not working, read note) 
-- I fix all spanw on console, but is only a temporaly fix, cos seems npc_spellclick_spells is not working
-- Anyway a few entrys need code
-- Haiphoon, the Great Tempest Is not a mount or vehicle (http://www.wowhead.com/npc=28985)
UPDATE `creature_template` SET `npcflag`='0', type_flags='0' WHERE `entry`='28985';
-- Haiphoon, the Great Tempest Is not a mount or vehicle (http://www.wowhead.com/npc=28999)
UPDATE `creature_template` SET `npcflag`='0', `unit_flags`='0' WHERE `entry`='28999';
-- The RP-GG Is not a mount or vehicle (http://www.wowhead.com/npc=30560)
UPDATE `creature_template` SET `npcflag`='0', type_flags='0' WHERE `entry`='30560';
-- The Turkey Chair need a scriptname (http://www.wowhead.com/npc=30560)
UPDATE `creature_template` SET `npcflag`='0', type_flags='4', `spell1`='61787', `spell2`='66260', `speed_walk`='0', `speed_run`='0' WHERE `entry`='34812';
-- The Stuffing Chair need a scriptname (http://www.wowhead.com/npc=34819)
UPDATE `creature_template` SET `npcflag`='0', type_flags='4', `spell1`='61833', `spell2`='61838', `spell3`='61837', `spell4`='61835', `spell5`='61785', `spell6`='61787', `spell7`='61788', `spell8`='61786', `speed_walk`='0', `speed_run`='0' WHERE `entry`='34819';
-- The Pie Chair need a scriptname (http://www.wowhead.com/npc=34822)
UPDATE `creature_template` SET `npcflag`='0', type_flags='4', `spell1`='61833', `spell2`='61838', `spell3`='61837', `spell4`='61835', `spell5`='61785', `spell6`='61787', `spell7`='61784', `spell8`='66260', `speed_walk`='0', `speed_run`='0' WHERE `entry`='34822';
-- The Cranberry Chair need a scriptname (http://www.wowhead.com/npc=34823)
UPDATE `creature_template` SET `npcflag`='0', type_flags='4', `spell1`='61833', `spell2`='61838', `spell3`='61837', `spell4`='61835', `spell5`='61785', `spell6`='61787', `spell7`='61784', `spell8`='66261', `speed_walk`='0', `speed_run`='0' WHERE `entry`='34823';
-- The Sweet Potato Chair need a scriptname (http://www.wowhead.com/npc=34824)
UPDATE `creature_template` SET `npcflag`='0', type_flags='4', `spell1`='61833', `spell2`='61838', `spell3`='61837', `spell4`='61835', `spell5`='61785', `spell6`='61787', `spell7`='61784', `spell8`='66262', `speed_walk`='0', `speed_run`='0' WHERE `entry`='34824';
-- Injured Stormwind Infantry Is not a mount or vehicle (http://www.wowhead.com/npc=50047)
UPDATE `creature_template` SET `npcflag`='0', type_flags='0' WHERE `entry`='50047';
-- Rebel Cannon Is not need it on creature (http://www.wowhead.com/npc=35317)
UPDATE `creature` SET `npcflag`='0' WHERE `id`='35317';