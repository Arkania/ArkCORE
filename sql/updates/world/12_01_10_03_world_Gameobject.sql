-- Link to Dazzling Destruction 10N
delete from `spell_linked_spell` where `spell_trigger` in (86406, 86408);
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('86408','86406','0','Dazzling Destruction');

-- Link to Devouring Flames 10N
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (86840, 86844);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES('86840','86844','1','Devouring Flames');

-- Portal
delete from `gameobject`  where `id` in (207341, 207342, 207340, 207339);
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('207340','0','1','65534','-4901.71','-4222.85','827.762','5.1811','0','0','0.523576','-0.851979','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('207339','0','1','65534','-4901.71','-4222.85','827.762','5.1811','0','0','0.523576','-0.851979','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('207342','0','1','65534','-4901.71','-4222.85','827.762','5.1811','0','0','0.523576','-0.851979','300','0','1');
insert into `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('207341','0','1','65534','-4901.71','-4222.85','827.762','5.1811','0','0','0.523576','-0.851979','300','0','1');
