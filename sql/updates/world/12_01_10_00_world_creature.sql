-- Quest http://es.wowhead.com/quest=26101 no questtaker spawn
delete from `creature` where `id` = 42106;
insert into `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) values('42106','1','1','1','0','0','2060.64','1211.56','450.781','3.21539','300','0','0','315','0','0','0','0','0','0');
