-- DB/GHOST ZONES: This fix all ghost zones errors on start up
-- GHOSTZONES: Deleting ghost zones for 4.1 or 4.2 clients
DELETE FROM `game_graveyard_zone` WHERE ghost_zone IN('33','36','5583','5702','3535');