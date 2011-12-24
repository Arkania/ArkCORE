DELETE FROM spell_ranks WHERE spell_id IN (89345, 89347, 89344, 89346, 89343, 89342, 69377, 86507);
INSERT INTO `spell_ranks`(`first_spell_id`, `spell_id`, `rank`) VALUES
(8099, 89345, 9), -- Stamina
(8096, 89347, 9), -- Intelect
(8091, 89344, 9), -- Protection
(8118, 89346, 9), -- Strength
(8115, 89343, 9), -- Agility
(8112, 89342, 9), -- Spirit
(69377, 69377, 1), -- Runescroll of Fortitude I
(69377, 86507, 2); -- Runescroll of Fortitude II