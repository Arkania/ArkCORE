-- Aspect_of_the_hawk
-- By Mikadmin For ARKania
-- fix error consol : Scriptname:`spell_hun_aspect_of_the_beast` spell (spell_id:13161) does not exist in `Spell.dbc`

UPDATE `spell_script_names` SET `spell_id` = '13165',
`ScriptName` = 'spell_hun_aspect_of_the_hawk' WHERE `spell_id` =13161;