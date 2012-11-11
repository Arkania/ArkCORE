-- Sethria
-- By mikadmin [www.wow-attitude.com]
-- fix healt

SET @ENTRY := 41255;

UPDATE `creature_template` SET `maxlevel` = 81, `exp` = 3, `Health_mod` = 10, `Mana_mod` = 2 WHERE entry=@ENTRY;