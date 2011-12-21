-- DB/AREATRIIGER: Fix all erros with areatrigger involvedrelation & areatrigger tavern on start up
-- AREATRIIGER: Deleting aretrigger for old quest The Affray (http://www.wowhead.com/quest=1719)
DELETE FROM `areatrigger_involvedrelation` WHERE id='522';
-- AREATRIIGER: Deleting no needed area for quest Rolling with my Homies (http://www.wowhead.com/quest=14071)
DELETE FROM `areatrigger_involvedrelation` WHERE id='0';
-- AREATRIIGER: Deleting no needed area Thousand Needles (now is a whater region)
DELETE FROM `areatrigger_tavern` WHERE id='2286';