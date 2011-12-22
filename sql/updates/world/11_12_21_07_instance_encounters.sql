-- DB/INSTANCE ENCOUNTERS: Fix all error with enconters on start up
-- Deleting some old or hig 4.0.6 encounters
DELETE FROM `instance_encounters` WHERE `entry` IN( '793','280');
DELETE FROM `instance_encounters` WHERE `creditEntry` IN( 58630,68572,68574,59046);