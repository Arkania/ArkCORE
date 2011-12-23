-- DB/CREATURE AI TEXTS: Deleting entry 0, entry cant be 0 or -0 this is reserved entry from mysql
DELETE FROM `creature_ai_texts`  WHERE `entry` IN ('0');
