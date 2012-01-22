-- Clean same spawns
DELETE FROM creature WHERE id IN (539, 565, 569, 213, 909, 923, 531, 1258, 69, 11748);
DELETE FROM creature WHERE guid IN (37556, 15216, 7626); -- SW Catedral
DELETE FROM creature WHERE guid IN (79778, 79779); -- Warrior trainer

