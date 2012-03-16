-- The Ring of Blood
-- By Mikadmin for Arkania
-- Fix event

UPDATE `creature_template` SET `AIName` = '' WHERE `creature_template`.`entry` =18471;
UPDATE `creature_template` SET `AIName` = '' WHERE `creature_template`.`entry` =22893;

-- The Ring of Blood: Brokentoe
 
DELETE FROM `gameobject_questrelation` WHERE `quest` = 9962;
DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 9962;
 
UPDATE `item_template` SET `StartQuest`=0 WHERE `StartQuest` = 9962;
 
DELETE FROM `creature_questrelation` WHERE `quest` = 9962;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES
(18471, 9962);
 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 9962;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES
(22893, 9962);
 
 
DELETE FROM `quest_start_scripts` WHERE `id`=9962;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(9962, 10, 10, 18398, 180000, '0', -704.669, 7871.08, 45.0387, 1.59531);
 
REPLACE INTO `quest_template` (`entry`, `Method`, `ZoneOrSort`, `SkillOrClassMask`, `MinLevel`, `MaxLevel`, `QuestLevel`, `Type`, `RequiredRaces`, `RequiredSkillValue`, `RepObjectiveFaction`, `RepObjectiveValue`, `RepObjectiveFaction2`, `RepObjectiveValue2`, `RequiredMinRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepFaction`, `RequiredMaxRepValue`, `SuggestedPlayers`, `LimitTime`, `QuestFlags`, `SpecialFlags`, `CharTitleId`, `PlayersSlain`, `BonusTalents`, `RewardArenaPoints`, `PrevQuestId`, `NextQuestId`, `ExclusiveGroup`, `NextQuestInChain`, `RewXPId`, `SrcItemId`, `SrcItemCount`, `SrcSpell`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `ReqItemId1`, `ReqItemId2`, `ReqItemId3`, `ReqItemId4`, `ReqItemId5`, `ReqItemId6`, `ReqItemCount1`, `ReqItemCount2`, `ReqItemCount3`, `ReqItemCount4`, `ReqItemCount5`, `ReqItemCount6`, `ReqSourceId1`, `ReqSourceId2`, `ReqSourceId3`, `ReqSourceId4`, `ReqSourceCount1`, `ReqSourceCount2`, `ReqSourceCount3`, `ReqSourceCount4`, `ReqCreatureOrGOId1`, `ReqCreatureOrGOId2`, `ReqCreatureOrGOId3`, `ReqCreatureOrGOId4`, `ReqCreatureOrGOCount1`, `ReqCreatureOrGOCount2`, `ReqCreatureOrGOCount3`, `ReqCreatureOrGOCount4`, `ReqSpellCast1`, `ReqSpellCast2`, `ReqSpellCast3`, `ReqSpellCast4`, `RewChoiceItemId1`, `RewChoiceItemId2`, `RewChoiceItemId3`, `RewChoiceItemId4`, `RewChoiceItemId5`, `RewChoiceItemId6`, `RewChoiceItemCount1`, `RewChoiceItemCount2`, `RewChoiceItemCount3`, `RewChoiceItemCount4`, `RewChoiceItemCount5`, `RewChoiceItemCount6`, `RewItemId1`, `RewItemId2`, `RewItemId3`, `RewItemId4`, `RewItemCount1`, `RewItemCount2`, `RewItemCount3`, `RewItemCount4`, `RewRepFaction1`, `RewRepFaction2`, `RewRepFaction3`, `RewRepFaction4`, `RewRepFaction5`, `RewRepValueId1`, `RewRepValueId2`, `RewRepValueId3`, `RewRepValueId4`, `RewRepValueId5`, `RewRepValue1`, `RewRepValue2`, `RewRepValue3`, `RewRepValue4`, `RewRepValue5`, `RewHonorAddition`, `RewHonorMultiplier`, `unk0`, `RewOrReqMoney`, `RewMoneyMaxLevel`, `RewSpell`, `RewSpellCast`, `RewMailTemplateId`, `RewMailDelaySecs`, `PointMapId`, `PointX`, `PointY`, `PointOpt`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4`, `IncompleteEmote`, `CompleteEmote`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `StartScript`, `CompleteScript`, `WDBVerified`) VALUES
(9962, 2, 3518, 0, 65, 0, 67, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 131, 0, 0, 0, 0, 0, 0, 9967, 0, 0, 7, 0, 0, 0, 'The Ring of Blood: Brokentoe', 'So are you ready for your first battle? If you are, let me know and I\'ll get things started. All you have to do is go wait in the Ring of Blood for your opponent to arrive.$B$BThis fight is against Brokentoe, a ferocious clefthoof.$B$BGood luck! I hope you brought friends.$B$BAnd remember, the fight\'s over when either you or your opponent are lying face down on the arena floor.$B', 'Defeat Brokentoe. Should you win, speak with Wodin the Troll-Servant to collect your reward.', '', '', 'Return to Wodin the Troll-Servant at the Laughing Skull Ruins in Nagrand.', 'Brokentoe Defeated', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18398, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 111000, 104700, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9962, 0, 1);

SET @ENTRY := 18398;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1000,1000,9000,11000,11,32023,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Brokentoe - In Combat - Cast Hoof Stomp");

-- The Ring of Blood: The Blue Brothers
 
DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 9967;
DELETE FROM `gameobject_questrelation` WHERE `quest` = 9967;
 
UPDATE `item_template` SET `StartQuest`=0 WHERE `StartQuest` = 9967;
 
DELETE FROM `creature_questrelation` WHERE `quest` = 9967;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (18471, 9967);
 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 9967;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (22893, 9967);
 
DELETE FROM `quest_start_scripts` WHERE `id`=9967;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(9967, 10, 10, 18399, 180000, '0', -708.076, 7870.41, 44.8457, 1.59531),
(9967, 10, 10, 18399, 180000, '0', -704.669, 7871.08, 45.0387, 1.59531);
 
REPLACE INTO `quest_template` (`entry`, `Method`, `ZoneOrSort`, `SkillOrClassMask`, `MinLevel`, `MaxLevel`, `QuestLevel`, `Type`, `RequiredRaces`, `RequiredSkillValue`, `RepObjectiveFaction`, `RepObjectiveValue`, `RepObjectiveFaction2`, `RepObjectiveValue2`, `RequiredMinRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepFaction`, `RequiredMaxRepValue`, `SuggestedPlayers`, `LimitTime`, `QuestFlags`, `SpecialFlags`, `CharTitleId`, `PlayersSlain`, `BonusTalents`, `RewardArenaPoints`, `PrevQuestId`, `NextQuestId`, `ExclusiveGroup`, `NextQuestInChain`, `RewXPId`, `SrcItemId`, `SrcItemCount`, `SrcSpell`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `ReqItemId1`, `ReqItemId2`, `ReqItemId3`, `ReqItemId4`, `ReqItemId5`, `ReqItemId6`, `ReqItemCount1`, `ReqItemCount2`, `ReqItemCount3`, `ReqItemCount4`, `ReqItemCount5`, `ReqItemCount6`, `ReqSourceId1`, `ReqSourceId2`, `ReqSourceId3`, `ReqSourceId4`, `ReqSourceCount1`, `ReqSourceCount2`, `ReqSourceCount3`, `ReqSourceCount4`, `ReqCreatureOrGOId1`, `ReqCreatureOrGOId2`, `ReqCreatureOrGOId3`, `ReqCreatureOrGOId4`, `ReqCreatureOrGOCount1`, `ReqCreatureOrGOCount2`, `ReqCreatureOrGOCount3`, `ReqCreatureOrGOCount4`, `ReqSpellCast1`, `ReqSpellCast2`, `ReqSpellCast3`, `ReqSpellCast4`, `RewChoiceItemId1`, `RewChoiceItemId2`, `RewChoiceItemId3`, `RewChoiceItemId4`, `RewChoiceItemId5`, `RewChoiceItemId6`, `RewChoiceItemCount1`, `RewChoiceItemCount2`, `RewChoiceItemCount3`, `RewChoiceItemCount4`, `RewChoiceItemCount5`, `RewChoiceItemCount6`, `RewItemId1`, `RewItemId2`, `RewItemId3`, `RewItemId4`, `RewItemCount1`, `RewItemCount2`, `RewItemCount3`, `RewItemCount4`, `RewRepFaction1`, `RewRepFaction2`, `RewRepFaction3`, `RewRepFaction4`, `RewRepFaction5`, `RewRepValueId1`, `RewRepValueId2`, `RewRepValueId3`, `RewRepValueId4`, `RewRepValueId5`, `RewRepValue1`, `RewRepValue2`, `RewRepValue3`, `RewRepValue4`, `RewRepValue5`, `RewHonorAddition`, `RewHonorMultiplier`, `unk0`, `RewOrReqMoney`, `RewMoneyMaxLevel`, `RewSpell`, `RewSpellCast`, `RewMailTemplateId`, `RewMailDelaySecs`, `PointMapId`, `PointX`, `PointY`, `PointOpt`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4`, `IncompleteEmote`, `CompleteEmote`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `StartScript`, `CompleteScript`, `WDBVerified`) VALUES
(9967, 2, 3518, 0, 65, 0, 67, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 131, 0, 0, 0, 0, 0, 9962, 9970, 0, 0, 7, 0, 0, 0, 'The Ring of Blood: The Blue Brothers', 'This next battle involves a duo - twin brothers to be precise. They call themselves the "Blue Brothers."$B$BIt\'s not too late to chicken out, $N. I\'d certainly understand.$B$BBut if you\'re ready for some action, step in the Ring of Blood and wait for the Murkblood twins to arrive.$B$BLast one standing is the winner!', 'Defeat the Murkblood Twins that call themselves the Blue Brothers. Should you win, speak with Wodin the Troll-Servant to collect your reward.', '', '', 'Return to Wodin the Troll-Servant at the Laughing Skull Ruins in Nagrand.', 'The Blue Brothers Defeated', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18399, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 111000, 104700, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9967, 0, 1);

SET @ENTRY := 18399;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Murkblood Twin - On Aggro - Say Line 0"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,1000,1000,2000,2000,11,14873,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Murkblood Twin - In Combat - Cast Sinister Strike"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,5000,6000,11000,12000,11,15691,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Murkblood Twin - In Combat - Cast Eviscerate"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,0,8000,9000,15000,16000,11,32319,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Murkblood Twin - In Combat - Cast Gouge");
 
-- The Ring of Blood: Rokdar the Sundered Lord
DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 9970;
DELETE FROM `gameobject_questrelation` WHERE `quest` = 9970;
 
UPDATE `item_template` SET `StartQuest`=0 WHERE `StartQuest` = 9970;
 
DELETE FROM `creature_questrelation` WHERE `quest` = 9970;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (18471, 9970);
 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 9970;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (22893, 9970);
 
DELETE FROM `quest_start_scripts` WHERE `id`=9970;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(9970, 10, 10, 18400, 180000, '0', -704.669, 7871.08, 45.0387, 1.59531);
 
REPLACE INTO `quest_template` (`entry`, `Method`, `ZoneOrSort`, `SkillOrClassMask`, `MinLevel`, `MaxLevel`, `QuestLevel`, `Type`, `RequiredRaces`, `RequiredSkillValue`, `RepObjectiveFaction`, `RepObjectiveValue`, `RepObjectiveFaction2`, `RepObjectiveValue2`, `RequiredMinRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepFaction`, `RequiredMaxRepValue`, `SuggestedPlayers`, `LimitTime`, `QuestFlags`, `SpecialFlags`, `CharTitleId`, `PlayersSlain`, `BonusTalents`, `RewardArenaPoints`, `PrevQuestId`, `NextQuestId`, `ExclusiveGroup`, `NextQuestInChain`, `RewXPId`, `SrcItemId`, `SrcItemCount`, `SrcSpell`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `ReqItemId1`, `ReqItemId2`, `ReqItemId3`, `ReqItemId4`, `ReqItemId5`, `ReqItemId6`, `ReqItemCount1`, `ReqItemCount2`, `ReqItemCount3`, `ReqItemCount4`, `ReqItemCount5`, `ReqItemCount6`, `ReqSourceId1`, `ReqSourceId2`, `ReqSourceId3`, `ReqSourceId4`, `ReqSourceCount1`, `ReqSourceCount2`, `ReqSourceCount3`, `ReqSourceCount4`, `ReqCreatureOrGOId1`, `ReqCreatureOrGOId2`, `ReqCreatureOrGOId3`, `ReqCreatureOrGOId4`, `ReqCreatureOrGOCount1`, `ReqCreatureOrGOCount2`, `ReqCreatureOrGOCount3`, `ReqCreatureOrGOCount4`, `ReqSpellCast1`, `ReqSpellCast2`, `ReqSpellCast3`, `ReqSpellCast4`, `RewChoiceItemId1`, `RewChoiceItemId2`, `RewChoiceItemId3`, `RewChoiceItemId4`, `RewChoiceItemId5`, `RewChoiceItemId6`, `RewChoiceItemCount1`, `RewChoiceItemCount2`, `RewChoiceItemCount3`, `RewChoiceItemCount4`, `RewChoiceItemCount5`, `RewChoiceItemCount6`, `RewItemId1`, `RewItemId2`, `RewItemId3`, `RewItemId4`, `RewItemCount1`, `RewItemCount2`, `RewItemCount3`, `RewItemCount4`, `RewRepFaction1`, `RewRepFaction2`, `RewRepFaction3`, `RewRepFaction4`, `RewRepFaction5`, `RewRepValueId1`, `RewRepValueId2`, `RewRepValueId3`, `RewRepValueId4`, `RewRepValueId5`, `RewRepValue1`, `RewRepValue2`, `RewRepValue3`, `RewRepValue4`, `RewRepValue5`, `RewHonorAddition`, `RewHonorMultiplier`, `unk0`, `RewOrReqMoney`, `RewMoneyMaxLevel`, `RewSpell`, `RewSpellCast`, `RewMailTemplateId`, `RewMailDelaySecs`, `PointMapId`, `PointX`, `PointY`, `PointOpt`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4`, `IncompleteEmote`, `CompleteEmote`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `StartScript`, `CompleteScript`, `WDBVerified`) VALUES
(9970, 2, 3518, 0, 65, 0, 67, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 131, 0, 0, 0, 0, 0, 9967, 9972, 0, 0, 7, 0, 0, 0, 'The Ring of Blood: Rokdar the Sundered Lord', 'This fight is gonna be painful, $N. Do you have any friends that are brave enough to help you out? The ogres managed to get a giant from Blade\'s Edge named Rokdar! Trust me, you\'re gonna need friends, he seems unbeatable! He\'s hard as a rock - literally!$B$BIf you still want to fight him, step into the Ring of Blood and he will come.', 'Defeat Rokdar the Sundered Lord. Should you win, speak with Wodin the Troll-Servant to collect your reward.', '', '', 'Return to Wodin the Troll-Servant at the Laughing Skull Ruins in Nagrand.', 'Rokdar the Sundered Lord Defeated', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18400, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22829, 22832, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 111000, 104700, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9970, 0, 1);

SET @ENTRY := 18400;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Rokdar the Sundered Lord - Out of Combat - Say Line"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,1000,1000,9000,11000,11,16727,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Rokdar the Sundered Lord - In Combat - Cast War Stomp"),
(@ENTRY,@SOURCETYPE,2,0,31,0,100,0,31389,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Rokdar the Sundered Lord - On Target Spellhit War Stomp - Say Line"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,0,6000,6000,12000,12000,11,31389,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Rokdar the Sundered Lord - In Combat - Cast Knock Away"),
(@ENTRY,@SOURCETYPE,4,0,0,0,100,0,20000,20000,25000,25000,11,15976,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Rokdar the Sundered Lord - In Combat - Cast Puncture");
 
-- The Ring of Blood: Skra'gath
DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 9972;
DELETE FROM `gameobject_questrelation` WHERE `quest` = 9972;
 
UPDATE `item_template` SET `StartQuest`=0 WHERE `StartQuest` = 9972;
 
DELETE FROM `creature_questrelation` WHERE `quest` = 9972;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (18471, 9972);
 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 9972;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (22893, 9972);
 
DELETE FROM `quest_start_scripts` WHERE `id`=9972;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(9972, 10, 10, 18401, 180000, '0', -704.669, 7871.08, 45.0387, 1.59531);
 
REPLACE INTO `quest_template` (`entry`, `Method`, `ZoneOrSort`, `SkillOrClassMask`, `MinLevel`, `MaxLevel`, `QuestLevel`, `Type`, `RequiredRaces`, `RequiredSkillValue`, `RepObjectiveFaction`, `RepObjectiveValue`, `RepObjectiveFaction2`, `RepObjectiveValue2`, `RequiredMinRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepFaction`, `RequiredMaxRepValue`, `SuggestedPlayers`, `LimitTime`, `QuestFlags`, `SpecialFlags`, `CharTitleId`, `PlayersSlain`, `BonusTalents`, `RewardArenaPoints`, `PrevQuestId`, `NextQuestId`, `ExclusiveGroup`, `NextQuestInChain`, `RewXPId`, `SrcItemId`, `SrcItemCount`, `SrcSpell`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `ReqItemId1`, `ReqItemId2`, `ReqItemId3`, `ReqItemId4`, `ReqItemId5`, `ReqItemId6`, `ReqItemCount1`, `ReqItemCount2`, `ReqItemCount3`, `ReqItemCount4`, `ReqItemCount5`, `ReqItemCount6`, `ReqSourceId1`, `ReqSourceId2`, `ReqSourceId3`, `ReqSourceId4`, `ReqSourceCount1`, `ReqSourceCount2`, `ReqSourceCount3`, `ReqSourceCount4`, `ReqCreatureOrGOId1`, `ReqCreatureOrGOId2`, `ReqCreatureOrGOId3`, `ReqCreatureOrGOId4`, `ReqCreatureOrGOCount1`, `ReqCreatureOrGOCount2`, `ReqCreatureOrGOCount3`, `ReqCreatureOrGOCount4`, `ReqSpellCast1`, `ReqSpellCast2`, `ReqSpellCast3`, `ReqSpellCast4`, `RewChoiceItemId1`, `RewChoiceItemId2`, `RewChoiceItemId3`, `RewChoiceItemId4`, `RewChoiceItemId5`, `RewChoiceItemId6`, `RewChoiceItemCount1`, `RewChoiceItemCount2`, `RewChoiceItemCount3`, `RewChoiceItemCount4`, `RewChoiceItemCount5`, `RewChoiceItemCount6`, `RewItemId1`, `RewItemId2`, `RewItemId3`, `RewItemId4`, `RewItemCount1`, `RewItemCount2`, `RewItemCount3`, `RewItemCount4`, `RewRepFaction1`, `RewRepFaction2`, `RewRepFaction3`, `RewRepFaction4`, `RewRepFaction5`, `RewRepValueId1`, `RewRepValueId2`, `RewRepValueId3`, `RewRepValueId4`, `RewRepValueId5`, `RewRepValue1`, `RewRepValue2`, `RewRepValue3`, `RewRepValue4`, `RewRepValue5`, `RewHonorAddition`, `RewHonorMultiplier`, `unk0`, `RewOrReqMoney`, `RewMoneyMaxLevel`, `RewSpell`, `RewSpellCast`, `RewMailTemplateId`, `RewMailDelaySecs`, `PointMapId`, `PointX`, `PointY`, `PointOpt`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4`, `IncompleteEmote`, `CompleteEmote`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `StartScript`, `CompleteScript`, `WDBVerified`) VALUES
(9972, 2, 3518, 0, 65, 0, 67, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 131, 0, 0, 0, 0, 0, 9970, 9973, 0, 0, 7, 0, 0, 0, 'The Ring of Blood: Skra\'gath', 'You\'re murderin\' \'em out there, kid! They got a ringer for the next match. They say he\'s a void lord or something... No way do they want you up against their champion. Did you here that palooka, Mogor, yapping at you? The bets are through the roof!$B$BGet in that ring and take this one out fast!', 'Defeat Skra\'gath. Should you win, speak with Wodin the Troll-Servant to collect your reward.', '', '', 'Return to Wodin the Troll-Servant at the Laughing Skull Ruins in Nagrand.', 'Skra\'gath Defeated', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18401, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22829, 22832, 21991, 0, 5, 5, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 111000, 104700, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9972, 0, 1);

SET @ENTRY := 18401;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,1,0,100,1,0,0,0,0,11,29299,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Skra'gath - Out of Combat - Cast Draining Touch"),
(@ENTRY,@SOURCETYPE,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Skra'gath - On Aggro - Say Line"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,6000,6000,12000,12000,11,32324,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Skra'gath - In Combat - Cast Shadow Burst");
 
-- The Ring of Blood: The Warmaul Champion
DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 9973;
DELETE FROM `gameobject_questrelation` WHERE `quest` = 9973;
 
UPDATE `item_template` SET `StartQuest`=0 WHERE `StartQuest` = 9973;
 
DELETE FROM `creature_questrelation` WHERE `quest` = 9973;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (18471, 9973);
 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 9973;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (22893, 9973);
 
DELETE FROM `quest_start_scripts` WHERE `id`=9973;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(9973, 10, 10, 18402, 180000, '0', -704.669, 7871.08, 45.0387, 1.59531);
 
REPLACE INTO `quest_template` (`entry`, `Method`, `ZoneOrSort`, `SkillOrClassMask`, `MinLevel`, `MaxLevel`, `QuestLevel`, `Type`, `RequiredRaces`, `RequiredSkillValue`, `RepObjectiveFaction`, `RepObjectiveValue`, `RepObjectiveFaction2`, `RepObjectiveValue2`, `RequiredMinRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepFaction`, `RequiredMaxRepValue`, `SuggestedPlayers`, `LimitTime`, `QuestFlags`, `SpecialFlags`, `CharTitleId`, `PlayersSlain`, `BonusTalents`, `RewardArenaPoints`, `PrevQuestId`, `NextQuestId`, `ExclusiveGroup`, `NextQuestInChain`, `RewXPId`, `SrcItemId`, `SrcItemCount`, `SrcSpell`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `ReqItemId1`, `ReqItemId2`, `ReqItemId3`, `ReqItemId4`, `ReqItemId5`, `ReqItemId6`, `ReqItemCount1`, `ReqItemCount2`, `ReqItemCount3`, `ReqItemCount4`, `ReqItemCount5`, `ReqItemCount6`, `ReqSourceId1`, `ReqSourceId2`, `ReqSourceId3`, `ReqSourceId4`, `ReqSourceCount1`, `ReqSourceCount2`, `ReqSourceCount3`, `ReqSourceCount4`, `ReqCreatureOrGOId1`, `ReqCreatureOrGOId2`, `ReqCreatureOrGOId3`, `ReqCreatureOrGOId4`, `ReqCreatureOrGOCount1`, `ReqCreatureOrGOCount2`, `ReqCreatureOrGOCount3`, `ReqCreatureOrGOCount4`, `ReqSpellCast1`, `ReqSpellCast2`, `ReqSpellCast3`, `ReqSpellCast4`, `RewChoiceItemId1`, `RewChoiceItemId2`, `RewChoiceItemId3`, `RewChoiceItemId4`, `RewChoiceItemId5`, `RewChoiceItemId6`, `RewChoiceItemCount1`, `RewChoiceItemCount2`, `RewChoiceItemCount3`, `RewChoiceItemCount4`, `RewChoiceItemCount5`, `RewChoiceItemCount6`, `RewItemId1`, `RewItemId2`, `RewItemId3`, `RewItemId4`, `RewItemCount1`, `RewItemCount2`, `RewItemCount3`, `RewItemCount4`, `RewRepFaction1`, `RewRepFaction2`, `RewRepFaction3`, `RewRepFaction4`, `RewRepFaction5`, `RewRepValueId1`, `RewRepValueId2`, `RewRepValueId3`, `RewRepValueId4`, `RewRepValueId5`, `RewRepValue1`, `RewRepValue2`, `RewRepValue3`, `RewRepValue4`, `RewRepValue5`, `RewHonorAddition`, `RewHonorMultiplier`, `unk0`, `RewOrReqMoney`, `RewMoneyMaxLevel`, `RewSpell`, `RewSpellCast`, `RewMailTemplateId`, `RewMailDelaySecs`, `PointMapId`, `PointX`, `PointY`, `PointOpt`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4`, `IncompleteEmote`, `CompleteEmote`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `StartScript`, `CompleteScript`, `WDBVerified`) VALUES
(9973, 2, 3518, 0, 65, 0, 67, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 131, 0, 0, 0, 0, 0, 9972, 9977, 0, 0, 7, 0, 0, 0, 'The Ring of Blood: The Warmaul Champion', 'They had to ship the champion in from the Blade\'s Edge gladiator pits. He was training on mountain giants - three at a time.$B$BIf you win this one, you become the new champion. What do you think your odds are, kid? Do you have a shot? Just give me the word and I\'ll bet the house on you.$B$BNow get in there and win!', 'Defeat the Warmaul Champion. Should you win, speak with Wodin the Troll-Servant to collect your reward.', '', '', 'Return to Wodin the Troll-Servant at the Laughing Skull Ruins in Nagrand.', 'The Warmaul Champion Defeated', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18402, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 111000, 104700, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9973, 0, 1);

SET @ENTRY := 18402;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Warmaul Champion - On Aggro - Say Line"),
(@ENTRY,@SOURCETYPE,1,0,4,0,100,0,0,0,0,0,11,31403,1,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Warmaul Champion - On Aggro - Cast Battle Shout"),
(@ENTRY,@SOURCETYPE,2,0,9,0,100,1,5,30,1500,2000,11,32323,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Warmaul Champion - On Player Range - Cast Charge"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,0,3000,4000,6000,7000,11,15708,1,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Warmaul Champion - In Combat - Cast Mortal Strike"),
(@ENTRY,@SOURCETYPE,4,5,6,0,100,1,0,0,0,0,15,9973,0,0,0,0,0,24,0,0,0,0.0,0.0,0.0,0.0,"Warmaul Champion - On Death - Give Quest Credit");
 
-- The Ring of Blood: The Final Challenge
DELETE FROM `creature` WHERE `id`=18069;

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(18069, 0, 0, 0, 0, 0, 18047, 0, 0, 0, 'Mogor', 'Hero of the Warmaul', '', 0, 67, 67, 1, 16, 16, 0, 1.48, 1.14286, 1, 1, 244.8, 344.4, 0, 326, 4.6, 2000, 0, 2, 64, 8, 0, 0, 0, 0, 0, 204, 303.6, 47, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15982, 39529, 18975, 16033, 0, 0, 0, 0, 0, 0, 220, 446, 'SmartAI', 1, 3, 12, 10, 1, 0, 0, 0, 0, 0, 0, 0, 180, 1, 0, 613097436, 0, '', 12340);

DELETE FROM `gameobject_questrelation` WHERE `quest` = 9977;
DELETE FROM `gameobject_involvedrelation` WHERE `quest` = 9977;
 
UPDATE `item_template` SET `StartQuest`=0 WHERE `StartQuest` = 9977;
 
DELETE FROM `creature_questrelation` WHERE `quest` = 9977;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (18471, 9977);
 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 9977;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (22893, 9977);
 
DELETE FROM `quest_start_scripts` WHERE `id`=9977;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(9977, 10, 10, 18069, 180000, '0', -704.669, 7871.08, 45.0387, 1.59531);
 
REPLACE INTO `quest_template` (`entry`, `Method`, `ZoneOrSort`, `SkillOrClassMask`, `MinLevel`, `MaxLevel`, `QuestLevel`, `Type`, `RequiredRaces`, `RequiredSkillValue`, `RepObjectiveFaction`, `RepObjectiveValue`, `RepObjectiveFaction2`, `RepObjectiveValue2`, `RequiredMinRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepFaction`, `RequiredMaxRepValue`, `SuggestedPlayers`, `LimitTime`, `QuestFlags`, `SpecialFlags`, `CharTitleId`, `PlayersSlain`, `BonusTalents`, `RewardArenaPoints`, `PrevQuestId`, `NextQuestId`, `ExclusiveGroup`, `NextQuestInChain`, `RewXPId`, `SrcItemId`, `SrcItemCount`, `SrcSpell`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RequestItemsText`, `EndText`, `CompletedText`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `ReqItemId1`, `ReqItemId2`, `ReqItemId3`, `ReqItemId4`, `ReqItemId5`, `ReqItemId6`, `ReqItemCount1`, `ReqItemCount2`, `ReqItemCount3`, `ReqItemCount4`, `ReqItemCount5`, `ReqItemCount6`, `ReqSourceId1`, `ReqSourceId2`, `ReqSourceId3`, `ReqSourceId4`, `ReqSourceCount1`, `ReqSourceCount2`, `ReqSourceCount3`, `ReqSourceCount4`, `ReqCreatureOrGOId1`, `ReqCreatureOrGOId2`, `ReqCreatureOrGOId3`, `ReqCreatureOrGOId4`, `ReqCreatureOrGOCount1`, `ReqCreatureOrGOCount2`, `ReqCreatureOrGOCount3`, `ReqCreatureOrGOCount4`, `ReqSpellCast1`, `ReqSpellCast2`, `ReqSpellCast3`, `ReqSpellCast4`, `RewChoiceItemId1`, `RewChoiceItemId2`, `RewChoiceItemId3`, `RewChoiceItemId4`, `RewChoiceItemId5`, `RewChoiceItemId6`, `RewChoiceItemCount1`, `RewChoiceItemCount2`, `RewChoiceItemCount3`, `RewChoiceItemCount4`, `RewChoiceItemCount5`, `RewChoiceItemCount6`, `RewItemId1`, `RewItemId2`, `RewItemId3`, `RewItemId4`, `RewItemCount1`, `RewItemCount2`, `RewItemCount3`, `RewItemCount4`, `RewRepFaction1`, `RewRepFaction2`, `RewRepFaction3`, `RewRepFaction4`, `RewRepFaction5`, `RewRepValueId1`, `RewRepValueId2`, `RewRepValueId3`, `RewRepValueId4`, `RewRepValueId5`, `RewRepValue1`, `RewRepValue2`, `RewRepValue3`, `RewRepValue4`, `RewRepValue5`, `RewHonorAddition`, `RewHonorMultiplier`, `unk0`, `RewOrReqMoney`, `RewMoneyMaxLevel`, `RewSpell`, `RewSpellCast`, `RewMailTemplateId`, `RewMailDelaySecs`, `PointMapId`, `PointX`, `PointY`, `PointOpt`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4`, `IncompleteEmote`, `CompleteEmote`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `StartScript`, `CompleteScript`, `WDBVerified`) VALUES
(9977, 2, 3518, 0, 65, 0, 68, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 131, 0, 0, 0, 0, 0, 9973, 0, 0, 0, 7, 0, 0, 0, 'The Ring of Blood: The Final Challenge', '<Gurgthock is counting his massive pile of gold.>$B$BYou\'ve made me a lot of money, kid. If you can defeat Mogor, I promise to make it worth your while. All that pain you suffered in the Ring of Blood is gonna end up paying off.$B$BNow get in there and show these ogres what you\'re made of!', 'Defeat Mogor, Hero of the Warmaul. Should you win, speak with Wodin the Troll-Servant to collect your reward.', '', '', 'Return to Wodin the Troll-Servant at the Laughing Skull Ruins in Nagrand.', 'Mogor, Hero of the Warmaul Defeated', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18069, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 25762, 25760, 25763, 25761, 25764, 25759, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 117000, 107700, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9977, 0, 1);

SET @ENTRY := 18069;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,1000,1000,3500,3500,11,16033,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Mogor - In Combat - Cast Chain Lightning"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,4000,4000,11000,13000,11,39529,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Mogor - In Combat - Cast Flame Shock"),
(@ENTRY,@SOURCETYPE,2,0,2,0,100,1,0,60,0,0,11,15982,1,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mogor - At 60% HP - Cast Healing Wave"),
(@ENTRY,@SOURCETYPE,3,0,2,0,100,1,0,30,0,0,11,28747,1,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mogor - At 30% HP - Cast Frenzy"),
(@ENTRY,@SOURCETYPE,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Mogor - At 30% HP - Say Line 0"),
(@ENTRY,@SOURCETYPE,6,0,38,0,100,0,12,12,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mogor - On Data Set - Say Line 1"),
(@ENTRY,@SOURCETYPE,7,0,38,0,100,0,13,13,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mogor - On Data Set - Say Line 2"),
(@ENTRY,@SOURCETYPE,8,0,38,0,100,0,14,14,0,0,1,6,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mogor - On Data Set - Say Line 6"),
(@ENTRY,@SOURCETYPE,9,10,38,0,100,0,1,1,0,0,53,0,18069,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mogor - On Data Set - Start WP"),
(@ENTRY,@SOURCETYPE,10,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Mogor - On Data Set - Say Line 3"),
(@ENTRY,@SOURCETYPE,11,12,40,0,100,0,4,18069,0,0,54,100000,0,2,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mogor - At WP 4 - Pause Path"),
(@ENTRY,@SOURCETYPE,12,0,61,0,100,0,0,0,0,0,80,1806900,0,2,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mogor - At WP 4 - Run Script"),
(@ENTRY,@SOURCETYPE,13,0,21,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Mogor - Reached Home - Set Faction Friendly");