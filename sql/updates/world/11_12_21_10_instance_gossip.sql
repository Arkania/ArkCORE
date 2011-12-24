-- DB/GOSSIPOPTION: Fix all erros with gossip on start up
-- GOSSIPOPTION: Delete some menu options for deleting npcs (4.1 or 4.2 client)
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN ('2177','10189');
-- GOSSIPOPTION: Delete some uused gossip scripts
DELETE FROM `gossip_scripts` WHERE `id` IN ('10857','10858');
