-- DB/QUEST START SCRIPTS: Fix all errors with quest start scripts on start up
-- Quest entry don't exist, so delete it (http://www.wowhead.com/quest=142220)
DELETE FROM `quest_start_scripts` WHERE `id`='142220';