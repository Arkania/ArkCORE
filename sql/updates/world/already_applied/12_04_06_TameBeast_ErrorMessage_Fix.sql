-- Fix for the error message when trying to tame a beast without the necessary slot
-- For Arkania
-- By Jorex


-- Fix for an error message when taming a beast
DELETE FROM arkcore_string where entry='11002';
INSERT INTO arkcore_string (entry,content_default) VALUES ('11002', 'You must have another pet slot available to do this.');