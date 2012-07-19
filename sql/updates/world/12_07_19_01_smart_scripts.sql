-- Fix Smart script error on consol
-- By Mikadmin For ARKania

UPDATE `smart_scripts` SET `event_flags` = '30',`action_param1` = '82636',`comment` = 'Ignacious - Levée de flammes' WHERE `entryorguid` =43686 AND `id` =0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 43686 AND `id` = 6;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 43686 AND `id` = 7;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 43686 AND `id` = 8;