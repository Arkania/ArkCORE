-- DB/AREATRIIGER: Fix all erros with areatrigger teleport on start up
-- AREATRIIGER: Deleting no needed area Zul'Gurub (This dungeon is for 4.1 client)
DELETE FROM `areatrigger_teleport` WHERE id='3928';
-- AREATRIGGER: Deleting 2 area trigger from 4.2 Clients
DELETE FROM areatrigger_teleport WHERE `id` IN ('6866','6864');