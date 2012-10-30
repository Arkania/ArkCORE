
SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `IRC_AutoAnnounce`
-- ----------------------------
DROP TABLE IF EXISTS `IRC_AutoAnnounce`;
CREATE TABLE `IRC_AutoAnnounce` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `message` longtext NOT NULL,
  `addedby` varchar(12) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COMMENT='IRC Module System';

-- ----------------------------
-- Records of IRC_AutoAnnounce
-- ----------------------------

-- ----------------------------
-- Table structure for `IRC_Commands`
-- ----------------------------
DROP TABLE IF EXISTS `IRC_Commands`;
CREATE TABLE `IRC_Commands` (
  `Command` varchar(10) NOT NULL DEFAULT '',
  `Description` varchar(350) DEFAULT NULL,
  `gmlevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`Command`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='IRC Module System';

-- ----------------------------
-- Records of IRC_Commands
-- ----------------------------
INSERT INTO `IRC_Commands` VALUES ('acct', '[acct <Player> <(un)lock/mail/pass/rename/gmlevel>] : Perform Action To <Player> Account.', '2');
INSERT INTO `IRC_Commands` VALUES ('ban', '[ban <Player/IP> <ip/acct/unban/reason>] : Ban/Unban <Player>', '2');
INSERT INTO `IRC_Commands` VALUES ('chan', '[chan <op/deop/voice/devoice> <*IRC Nick*>] : Set Mode On Yourself, If <IRC Nick> Is Specified Then Set mode On Nick.', '2');
INSERT INTO `IRC_Commands` VALUES ('char', '[char <Player> <mailcheat/taxicheat/maxskill/setskill/combatstop/quest/mod>] : Perform Action To Character.', '2');
INSERT INTO `IRC_Commands` VALUES ('fun', '[fun <Player> <Sound/Say>] : Do Selected Fun Action To <Player>.', '3');
INSERT INTO `IRC_Commands` VALUES ('help', '[help Command] : Use No Paramaters For List Of Available Commands.', '0');
INSERT INTO `IRC_Commands` VALUES ('inchan', '[inchan <Channel>] : Display Users In Selected In Game <Channel>', '0');
INSERT INTO `IRC_Commands` VALUES ('info', '[info] : Display Server Info. (Number Of Players Online/Max Since Last Restart/Uptime)', '0');
INSERT INTO `IRC_Commands` VALUES ('item', '[item <Player> <add> <ItemID/[ItemName]> <Amount>] : Additem To <Player>, Use <ItemID> Or <[Exact Item Name]>.', '2');
INSERT INTO `IRC_Commands` VALUES ('jail', '[jail <Player> <release/Reason>] : Jail Selected <Player> For <Reason>. Using release As <Reason> Releases Player.', '1');
INSERT INTO `IRC_Commands` VALUES ('kick', '[kick <Player> <Reason>] : Kick <Player> For <Reason>.', '1');
INSERT INTO `IRC_Commands` VALUES ('kill', '[kill <Player> <Reason>] : Kill <Player> For <Reason>.', '2');
INSERT INTO `IRC_Commands` VALUES ('level', '[level <Player> <NewLevel>] : Level <Player> To <NewLevel>. *Can Be Done Offline*', '2');
INSERT INTO `IRC_Commands` VALUES ('lookup', '[lookup <acct/char/creature/faction/go/item/quest/skill/spell/tele> <ID/Name>] : ', '3');
INSERT INTO `IRC_Commands` VALUES ('login', '[login <UserName> <Password>] : Login To TriniChat Admin Mode.  (Must Be Done In A PM)', '0');
INSERT INTO `IRC_Commands` VALUES ('logout', '[logout] : Logout Of TriniChat Admin Mode.', '0');
INSERT INTO `IRC_Commands` VALUES ('money', '[money <Player> <(-)Money>] : Give Money To <Player>, Use - To Take Money. *Can Be Done Offline*', '2');
INSERT INTO `IRC_Commands` VALUES ('mute', '[mute <Player> <release/TimeInMins> <Reason>] : Mute Player For Reason, For <TimeInMins>. Using release As Time Releases Player. *Can Be Done Offline*', '1');
INSERT INTO `IRC_Commands` VALUES ('online', '[online] : Display All Users Logged In Game.', '0');
INSERT INTO `IRC_Commands` VALUES ('pm', '[pm <Player> <Message>] : Whisper <Player> In WoW <Message>.', '2');
INSERT INTO `IRC_Commands` VALUES ('reload', '[reload] : Reload TriniChat Config Options And Security Level From DataBase.', '3');
INSERT INTO `IRC_Commands` VALUES ('restart', '[restart] : Restart TriniChat, NOT Trinity Core World Server Itself. Forces Reconnection To IRC Server.', '3');
INSERT INTO `IRC_Commands` VALUES ('revive', '[revive <Player>] : Revive <Player>.', '2');
INSERT INTO `IRC_Commands` VALUES ('saveall', '[saveall] : Forces Trinity Core To Save All Players.', '2');
INSERT INTO `IRC_Commands` VALUES ('server', '[server setmotd [<motd>]/flusharenapoints]', '3');
INSERT INTO `IRC_Commands` VALUES ('shutdown', '[shutdown <TimeInSeconds>] : Shuts The Server Down In <TimeInSeconds>, Use 0 For Immediate Shut Down', '3');
INSERT INTO `IRC_Commands` VALUES ('spell', '[spell <Player> <Cast/Learn/UnLearn> <SpellID>] : Make <Player> <Learn> Or <UnLearn> A Spell, Or <Cast> A Spell On A <Player>.', '3');
INSERT INTO `IRC_Commands` VALUES ('sysmsg', '[sysmsg <a/n/e/add/del/list> <Message>] : Broadcasts A System Message. (a-Broadcast System Message)(n-Broadcast Notify Message)(e-Event Message)', '1');
INSERT INTO `IRC_Commands` VALUES ('tele', '[tele <Player> <l/c/r/to/cr/go/homebind> <Loc.Name/MAPID X Y Z/Recall/Player/Creature GUID/Gameobject GUID>] : Teleport Player To Location, Coords, Recall Location, Another Player, Creature or Gameobject. (l-Location)(c-Coords)', '2');
INSERT INTO `IRC_Commands` VALUES ('top', '[top <accttime/chartime/money> <limit>] : Display top stats for given option. Only GM Higher Than Config Option Can Use Limit.', '3');
INSERT INTO `IRC_Commands` VALUES ('who', '[who] : Displays Users Currently Logged In To TriniChat.', '1');
INSERT INTO `IRC_Commands` VALUES ('wg', '[wg] : Wintergrasp Info', '0');
INSERT INTO `IRC_Commands` VALUES ('unaura', '[unaura] : remove all auras form select player', '3');

-- ----------------------------
-- Table structure for `IRC_Inchan`
-- ----------------------------
DROP TABLE IF EXISTS `IRC_Inchan`;
CREATE TABLE `IRC_Inchan` (
  `guid` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `name` varchar(12) NOT NULL DEFAULT '',
  `channel` varchar(15) NOT NULL DEFAULT '',
  PRIMARY KEY (`guid`,`channel`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='IRC Module System';

-- ----------------------------
-- Records of IRC_Inchan
-- ----------------------------

DELETE FROM `arkcore_string` WHERE `entry` in (11996,11997,11998,11999,20000,20001,20002);
INSERT INTO `arkcore_string` VALUES (11996, '|cff60ff00[ArkCore Bar Keep]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `arkcore_string` VALUES (11997, '|cffffff00[System Message]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `arkcore_string` VALUES (11998, '|cffffff00[Server Event]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `arkcore_string` VALUES (11999, '|cfffffC00[ArkCore Announcer]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `arkcore_string` VALUES (20000, '|cffffff00[System Message]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `arkcore_string` VALUES (20001, '|cffffff00[Server Event]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `arkcore_string` VALUES (20002, '|cffffff00[Automatic]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);