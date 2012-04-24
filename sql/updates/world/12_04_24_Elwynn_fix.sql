-- More Elwynn Forest fix
-- For Arkania
-- By Jorex

-- Missing text
UPDATE quest_template SET OfferRewardtext='With your help we have managed to secure the northern and western sectors of Northshire. We still have a rather large contingency of Blackrock orcs to the east and they''ve begun burning down the forest!' WHERE entry IN (28817,28818,28819,28820,28821,28822,28823,29083);

-- Wrong text in a scroll
UPDATE page_text SET `text`='REPORT: Kobolds$B$BThe activity of kobolds has decreased in Northshire Valley. All kobolds were driven off by the rampaging Blackrock orcs.' WHERE entry='209';
UPDATE page_text SET `text`='REPORT: BLACKROCK ORCS$B$BAn invasion force of Blackrock orcs has emerged in the valley. This attack seems to be a precursor to something far more insidious. Warn Magistrate Solomon of Lakeshire.' WHERE entry='210';
UPDATE page_text SET `text`='COMMENDATION:$B$BThe bearer of these documents is to be awarded Deputy status with the Stormwind Army, having served Northshire with eagerness and distinction.  I am confident you will find this person useful in Elwynn Forest.$B$Bsigned:$B-Marshal Douglas McBride,$BStormwind Army, Northshire' WHERE entry='211';
UPDATE page_text SET next_page='0' WHERE entry='211';
DELETE FROM page_text WHERE entry='212'; 

-- Update kill creadit
UPDATE creature_template SET KillCredit1='118' WHERE entry='1922';

-- Clean up
DELETE FROM creature WHERE guid='6623288';

