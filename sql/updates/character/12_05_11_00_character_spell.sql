-- Aquaticform speed fix
INSERT INTO `character_spell` (SELECT guid,5421,1,0 FROM `characters` WHERE CLASS = 11);
