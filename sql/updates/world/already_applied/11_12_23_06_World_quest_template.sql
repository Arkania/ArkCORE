-- DB/QUEST TEMPLATE: Some quest need a special flag 2 (Exploration or Event) controlling by SAI
-- Diplomatic Measures Alliance (http://www.wowhead.com/quest=10108)
-- Diplomatic Measures Horde (http://www.wowhead.com/quest=10107)
-- Mystery of the Infinite (http://www.wowhead.com/quest=12470)
-- Mystery of the Infinite, Redux (http://www.wowhead.com/quest=13343)
-- The Might of the Horde (http://www.wowhead.com/quest=12053)
UPDATE `quest_template` SET `SpecialFlags`='2' WHERE `entry` IN (10108,10107,12470,13343,12053);
