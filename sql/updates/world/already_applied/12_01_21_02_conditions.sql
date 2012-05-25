-- Wrath of the Fungalmancer (Deepholm) Questfix
-- by Naios for Arkania

REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`)
VALUES (15, 43503, 0, 1, 9, 26583, 0, 0, 0, '', 'show gossip option if Player has Quest 26583 taken');

