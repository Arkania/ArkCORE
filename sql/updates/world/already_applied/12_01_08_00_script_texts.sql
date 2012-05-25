-- Script Texts for Erudax

DELETE FROM script_texts WHERE npc_Entry = 40484;

INSERT INTO script_texts (npc_entry, entry, content_default, sound, type, comment) VALUES (40484, -1810000, "The darkest days are still ahead!", 18638, 1, "ERUDAX_SAY_AGGRO");
INSERT INTO script_texts (npc_entry, entry, content_default, sound, type, comment) VALUES (40484, -1810001, "Ywaq maq oou/; ywaq maq ssaggh. Yawq ma shg/'fhn.", 18641, 1, "ERUDAX_SAY_DEATH");
INSERT INTO script_texts (npc_entry, entry, content_default, sound, type, comment) VALUES (40484, -1810002, "Come, suffering... Enter, chaos!", 18646, 1, "ERUDAX_SAY_SUMMON");
INSERT INTO script_texts (npc_entry, entry, content_default, sound, type, comment) VALUES (40484, -1810003, "F/'lakh ghet! The shadow/'s hunger cannot be sated!", 18644, 1, "ERUDAX_SAY_GALE");
INSERT INTO script_texts (npc_entry, entry, content_default, sound, type, comment) VALUES (40484, -1810004, "More flesh for the offering!", 18640, 1, "ERUDAX_SAY_SLAY");

