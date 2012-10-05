-- Teleports
DELETE FROM `npc_text` WHERE `id` BETWEEN 40000 AND 40005;
INSERT INTO `npc_text` (`id`, `text0_0`) VALUES
(40000, 'Teleport to the Light\'s Hammer'),
(40001, 'Teleport to the Oratory of the Damned.'), 
(40002, 'Teleport to the Rampart of Skulls.'),
(40003, 'Teleport to the Deathbringer\'s Rise.'),
(40004, 'Teleport to the Upper Spire.'),
(40005, 'Teleport to the Sindragosa\'s Lair');

DELETE FROM `locales_npc_text` WHERE `entry` BETWEEN 40000 AND 40005;
INSERT INTO `locales_npc_text` (`entry`, `Text0_0_loc6`, `Text0_0_loc7`) VALUES
(40000, 'Teletransporte a El Martillo de luz', 'Teletransporte a El Martillo de luz'),
(40001, 'Teletransporte a El Oratorio de los Caidos', 'Teletransporte a El Oratorio de los Caidos'),
(40002, 'Teletransporte a La Muralla de las Calaveras', 'Teletransporte a La Muralla de las Calaveras'),
(40003, 'Teletransporte a El Alto del Libramorte', 'Teletransporte a El Alto del Libramorte'),
(40004, 'Teletransporte a Los Talleres de la Plaga', 'Teletransporte a Los Talleres de la Plaga'),
(40005, 'Teletransporte a La Guarida de Sindragossa', 'Teletransporte a La Guarida de Sindragossa');