-- Fix The Kessel Run [no-Blizz]
-- By Mikadmin For Arkania
-- Add eleek id:34407 for waiting fix core spell 31973

UPDATE `quest_template` SET `LimitTime` = 900, `SrcSpell` = 34407 WHERE `entry` = 9663;