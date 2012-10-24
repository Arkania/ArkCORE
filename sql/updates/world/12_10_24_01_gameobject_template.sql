-- assign CPP script
UPDATE `gameobject_template` SET `ScriptName`='go_kajamitedeposit' WHERE `entry`='195488';
-- assign quest to the goober version
UPDATE `gameobject_template` SET `data1`='14124' WHERE `entry`='195488';
-- update the GO spawns with correct goober one
UPDATE `gameobject` SET `id`='195488' WHERE `id`='195489' AND `map`='648';
-- Add a better respawn timer 1 hour was way too long
UPDATE `gameobject` SET `spawntimesecs`='180' WHERE `id`='195488' AND `map`='648';
-- REMOVE pre spawned chunks
DELETE FROM `gameobject` WHERE `id`='195492';
