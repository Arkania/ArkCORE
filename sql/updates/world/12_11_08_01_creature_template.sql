-- Sethria
-- By mikadmin [www.wow-attitude.com]
-- fix healt

SET @ENTRY := 41255;

UPDATE `creature_template` SET `maxlevel` = 81, `exp` = 3, `Health_mod` = 4.3295, `Mana_mod` = 1.4835 WHERE entry=@ENTRY;