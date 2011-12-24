-- DB/GAMEOBJECT: Old Treasure Ches Fix respawn time, this fix a exploit wuth this chest (http://www.wowhead.com/object=176944)
UPDATE `gameobject` SET `spawntimesecs`='7200' WHERE `id`='176944';