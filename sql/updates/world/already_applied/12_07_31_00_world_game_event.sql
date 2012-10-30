-- Fix error consol: `game_event` game event id (435) have not existed holiday id 288.
-- By Mikadmin For ARKania
-- holiday id is 435 on Holidays.dbc

UPDATE `game_event` SET `holiday` = '435' WHERE `entry` =435;