-- Narkk`s Handbombs
-- By Mikadmin For Arkania
-- Fix spawn & gameobject_template

REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES 
(204587, 3, 9651, 'Narkk`s Handbombs', '', 'Opening', '', 0, 4, 1, 59524, 0, 0, 0, 0, 0, 43, 204587, 0, 0, 0, 0, 0, 0, 26695, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 13329);

DELETE FROM `gameobject` WHERE `id`=204587;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(4012041, 204587, 0, 1, 1, -14335.4, 428.834, 6.6271, 1.87492, 0, 0, 0.806056, 0.591839, 150, 0, 1);