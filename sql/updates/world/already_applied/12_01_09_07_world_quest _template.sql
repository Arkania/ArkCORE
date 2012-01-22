-- Take him to the Earthcaller (Deepholm) Questfix
-- by Naios for Arkania

UPDATE `creature_template` SET `ScriptName`='npc_flint_oremantle' WHERE `entry`=43036 LIMIT 1;
UPDATE `quest_template` SET `OfferRewardText`='We are honored by Flint Oremantle\'s presence.$BI am given to understand that the Stonefather is in possession of a fragment of the World Pillar.' WHERE `entry`=26413 LIMIT 1;
