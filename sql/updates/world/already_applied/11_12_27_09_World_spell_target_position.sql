-- DB/TARGER POSITION: Fix all target position erros on startup
-- After a while I dono why this spell targer are there, sobetter delete it, maybe is for 4.1 or orther clients
DELETE FROM `spell_target_position` WHERE `id` IN (11011,35376,35727,55554,88775);
