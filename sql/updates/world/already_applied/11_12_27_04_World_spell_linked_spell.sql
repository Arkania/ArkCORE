-- DB/SPELL: FIX CRASH with with some no liinked spells
-- I saw some one put a neutra spell id, but this spell need to be removed cos is getting a crash to server, so better delete it
-- Righteous Fury - Tank Class Passive Threat
-- Frost Presence - Tank Class Passive Threat
-- Bear Form (Passive2) - Tank Class Passive Threat
-- Defensive Stance Passive - Tank Class Passive Threat
DELETE FROM `spell_linked_spell` WHERE spell_effect IN ('57339','57340');