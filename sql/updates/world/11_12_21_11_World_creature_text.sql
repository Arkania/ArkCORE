-- DB/CREATURE TEXT: Fix all erros with creature text on start up
-- Please remenber that, ArkCore is a old TC so we need to use old values from TC you can use this query in comvertor
-- Skyfire Only: Taking old values for types on creature text
UPDATE `creature_text` SET `type`='0' WHERE `type`='12'; -- Say
UPDATE `creature_text` SET `type`='2' WHERE `type`='16'; -- Emote
UPDATE `creature_text` SET `type`='1' WHERE `type`='14'; -- Yell
UPDATE `creature_text` SET `type`='3' WHERE `type`='41'; -- Normal
UPDATE `creature_text` SET `type`='5' WHERE `type`='42'; -- Boss Whisper 
UPDATE `creature_text` SET `type`='4' WHERE `type`='15'; -- Whisper
-- CREATURETEXT: Remove sound for unknow entrys
UPDATE `creature_text` SET `sound`='0' WHERE `Entry` IN (23863);
-- SCRIPTEXTS: change type 12 to 6
UPDATE `script_texts` SET `type`='6' WHERE `entry` IN (-1610001);