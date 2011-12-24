-- DB/SPELL BONUS: Fix all errors with spell bonus on start up
-- Spell: Deep Freeze corrrect Direct Bonus (http://www.wowhead.com/spell=71757) 
UPDATE `spell_bonus_data` SET `direct_bonus`='2.058000' WHERE `entry`='71757';
-- Spell: Vampiric Touch corrrect Direct Bonus (http://www.wowhead.com/spell=34914) 
UPDATE `spell_bonus_data` SET `direct_bonus`='1.000000' WHERE `entry`='34914';
-- Spell: Starfall corrrect Direct Bonus (http://www.wowhead.com/spell=48505) 
UPDATE `spell_bonus_data` SET `direct_bonus`='0.127000' WHERE `entry`='48505';
-- Spell: Mind Spike corrrect Direct Bonus (http://www.wowhead.com/spell=73510) 
UPDATE `spell_bonus_data` SET `direct_bonus`='0.835500' WHERE `entry`='73510';
-- Priest - Mind Flay Correct entry for this spell (http://www.wowhead.com/spell=15407)
UPDATE `spell_bonus_data` SET `entry`='15407' WHERE entry='58381';
UPDATE `spell_bonus_data` SET `direct_bonus`='0.257000' WHERE `entry`='15407';