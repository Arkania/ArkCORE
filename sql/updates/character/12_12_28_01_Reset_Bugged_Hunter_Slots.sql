-- Run this to fix the issue of no slots available but the pet(s) do not appear.
-- The player(s) must log out after this query has been run.
UPDATE characters  SET `currentPetSlot`= 100, `petSlotUsed`=0 WHERE `guid` = xxx;
UPDATE character_pet SET `slot` = 100 WHERE `owner` = xxx;
