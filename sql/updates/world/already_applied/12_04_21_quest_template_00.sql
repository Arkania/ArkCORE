-- Cleanup and fixes for Worgen quests up to Invasion (14321).

-- RewspellCast -> RewSpellHiddenCast.
UPDATE quest_template SET RewSpellCast = 0, RewSpellHiddenCast = 59073 WHERE entry = 14078; -- Lockdown!
UPDATE quest_template SET RewSpellCast = 0, RewSpellHiddenCast = 59074 WHERE entry = 14098; -- Evacuate the Merchant Square
UPDATE quest_template SET RewSpellCast = 0, RewSpellHiddenCast = 72872 WHERE entry = 14159; -- The Rebel Lord's Arsenal
UPDATE quest_template SET RewSpellCast = 0, RewSpellHiddenCast = 43511 WHERE entry = 14204; -- From the Shadows
UPDATE quest_template SET RewSpellCast = 0, RewSpellHiddenCast = 76642 WHERE entry = 14293; -- Save Krennan Aranas
UPDATE quest_template SET RewSpellCast = 0, RewSpellHiddenCast = 81040 WHERE entry = 14221; -- Never Surrender, Sometimes Retreat
UPDATE quest_template SET RewSpellCast = 0, RewSpellHiddenCast = 1645 WHERE entry = 14222; -- Last Stand
UPDATE quest_template SET RewSpellCast = 0, RewSpellHiddenCast = 69296 WHERE entry = 14320; -- In Need of Ingredients

-- Quest Completition
UPDATE quest_template SET ReqCreatureOrGOId1 = 0, ReqCreatureOrGOCount1 = 0 WHERE entry = 14222; -- Last Stand, needs more work. Friendly NPC's are killing all the quest mobs.

-- OfferRewardText
UPDATE quest_template SET OfferRewardText="It worked! By the Light, it worked!" WHERE entry = 14313; -- Among Humans Again
UPDATE quest_template SET OfferRewardText="The crate has been smashed and the vials inside of it appear to have been broken.", SoundAccept=890, SoundTurnIn=878 WHERE entry = 14320; -- In Need of Ingredients
UPDATE quest_template SET OfferRewardText="Forsaken!  Quick, <name>!  We must mount a defense." WHERE entry = 14321; -- Invasion