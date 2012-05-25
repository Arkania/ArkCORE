ALTER TABLE creature_text
CHANGE COLUMN text content_default longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER id,
ADD content_loc1 longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER sound,
ADD content_loc2 longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER content_loc1,
ADD content_loc3 longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER content_loc2,
ADD content_loc4 longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER content_loc3,
ADD content_loc5 longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER content_loc4,
ADD content_loc6 longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER content_loc5,
ADD content_loc7 longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER content_loc6,
ADD content_loc8 longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER content_loc7;
 
