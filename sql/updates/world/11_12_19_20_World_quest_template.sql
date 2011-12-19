-- DB/QUEST fix all error related qith quest templates
-- Remove old quest from DB
-- Fix 22 quest
-- QUEST: The Scrimshank Redemption Remove quest from game (http://www.wowhead.com/quest=10)
DELETE FROM `creature_questrelation` WHERE `quest`='10';
DELETE FROM `gameobject_questrelation` WHERE `quest`='10';
DELETE FROM `creature_involvedrelation` WHERE `quest`='10';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='10';
DELETE FROM `quest_template` WHERE `entry`='10';

-- QUEST: The Legend of Stalvan Remove quest from game (http://www.wowhead.com/quest=67)
DELETE FROM `creature_questrelation` WHERE `quest`='67';
DELETE FROM `gameobject_questrelation` WHERE `quest`='67';
DELETE FROM `creature_involvedrelation` WHERE `quest`='67';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='67';
DELETE FROM `quest_template` WHERE `entry`='67';

-- QUEST: The Legend of Stalvan Remove quest from game (http://www.wowhead.com/quest=134)
DELETE FROM `creature_questrelation` WHERE `quest`='134';
DELETE FROM `gameobject_questrelation` WHERE `quest`='134';
DELETE FROM `creature_involvedrelation` WHERE `quest`='134';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='134';
DELETE FROM `quest_template` WHERE `entry`='134';

-- QUEST: Jungle Secrets Remove quest from game (http://www.wowhead.com/quest=215)
DELETE FROM `creature_questrelation` WHERE `quest`='215';
DELETE FROM `gameobject_questrelation` WHERE `quest`='215';
DELETE FROM `creature_involvedrelation` WHERE `quest`='215';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='215';
DELETE FROM `quest_template` WHERE `entry`='215';

-- QUEST: Down the Scarlet Path Remove quest from game (http://www.wowhead.com/quest=261)
DELETE FROM `creature_questrelation` WHERE `quest`='261';
DELETE FROM `gameobject_questrelation` WHERE `quest`='261';
DELETE FROM `creature_involvedrelation` WHERE `quest`='261';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='261';
DELETE FROM `quest_template` WHERE `entry`='261';

-- QUEST: Claws from the Deep Remove quest from game (http://www.wowhead.com/quest=279)
DELETE FROM `creature_questrelation` WHERE `quest`='279';
DELETE FROM `gameobject_questrelation` WHERE `quest`='279';
DELETE FROM `creature_involvedrelation` WHERE `quest`='279';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='279';
DELETE FROM `quest_template` WHERE `entry`='279';

-- QUEST: The Stockade Riots Remove quest from game (http://www.wowhead.com/quest=391)
DELETE FROM `creature_questrelation` WHERE `quest`='391';
DELETE FROM `gameobject_questrelation` WHERE `quest`='391';
DELETE FROM `creature_involvedrelation` WHERE `quest`='391';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='391';
DELETE FROM `quest_template` WHERE `entry`='391';

-- QUEST: The Stockade Riots Remove quest from game (http://www.wowhead.com/quest=405)
DELETE FROM `creature_questrelation` WHERE `quest`='405';
DELETE FROM `gameobject_questrelation` WHERE `quest`='405';
DELETE FROM `creature_involvedrelation` WHERE `quest`='405';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='405';
DELETE FROM `quest_template` WHERE `entry`='405';

-- QUEST: Wild Hearts Remove quest from game (http://www.wowhead.com/quest=429)
DELETE FROM `creature_questrelation` WHERE `quest`='429';
DELETE FROM `gameobject_questrelation` WHERE `quest`='429';
DELETE FROM `creature_involvedrelation` WHERE `quest`='429';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='429';
DELETE FROM `quest_template` WHERE `entry`='429';

-- QUEST: The Woodland Protector quest from game (http://www.wowhead.com/quest=458)
DELETE FROM `creature_questrelation` WHERE `quest`='458';
DELETE FROM `gameobject_questrelation` WHERE `quest`='458';
DELETE FROM `creature_involvedrelation` WHERE `quest`='458';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='458';
DELETE FROM `quest_template` WHERE `entry`='458';

-- QUEST: Elixir of Suffering quest from game (http://www.wowhead.com/quest=496)
DELETE FROM `creature_questrelation` WHERE `quest`='496';
DELETE FROM `gameobject_questrelation` WHERE `quest`='496';
DELETE FROM `creature_involvedrelation` WHERE `quest`='496';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='496';
DELETE FROM `quest_template` WHERE `entry`='496';

-- QUEST: The Rescue quest from game (http://www.wowhead.com/quest=498)
DELETE FROM `creature_questrelation` WHERE `quest`='498';
DELETE FROM `gameobject_questrelation` WHERE `quest`='498';
DELETE FROM `creature_involvedrelation` WHERE `quest`='498';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='498';
DELETE FROM `quest_template` WHERE `entry`='498';

-- QUEST: Gol'dir quest from game (http://www.wowhead.com/quest=503)
DELETE FROM `creature_questrelation` WHERE `quest`='503';
DELETE FROM `gameobject_questrelation` WHERE `quest`='503';
DELETE FROM `creature_involvedrelation` WHERE `quest`='503';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='503';
DELETE FROM `quest_template` WHERE `entry`='503';

-- QUEST: Battle of Hillsbrad quest from game (http://www.wowhead.com/quest=527)
DELETE FROM `creature_questrelation` WHERE `quest`='527';
DELETE FROM `gameobject_questrelation` WHERE `quest`='527';
DELETE FROM `creature_involvedrelation` WHERE `quest`='527';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='527';
DELETE FROM `quest_template` WHERE `entry`='527';

-- QUEST: Battle of Hillsbrad quest from game (http://www.wowhead.com/quest=532)
DELETE FROM `creature_questrelation` WHERE `quest`='532';
DELETE FROM `gameobject_questrelation` WHERE `quest`='532';
DELETE FROM `creature_involvedrelation` WHERE `quest`='532';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='532';
DELETE FROM `quest_template` WHERE `entry`='532';

-- QUEST: Preserving Knowledge quest from game (http://www.wowhead.com/quest=540)
DELETE FROM `creature_questrelation` WHERE `quest`='540';
DELETE FROM `gameobject_questrelation` WHERE `quest`='540';
DELETE FROM `creature_involvedrelation` WHERE `quest`='540';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='540';
DELETE FROM `quest_template` WHERE `entry`='540';

-- QUEST: Helcular's Revenge quest from game (http://www.wowhead.com/quest=553)
DELETE FROM `creature_questrelation` WHERE `quest`='553';
DELETE FROM `gameobject_questrelation` WHERE `quest`='553';
DELETE FROM `creature_involvedrelation` WHERE `quest`='553';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='553';
DELETE FROM `quest_template` WHERE `entry`='553';

-- QUEST: The Bloodsail Buccaneers quest from game (http://www.wowhead.com/quest=595)
DELETE FROM `creature_questrelation` WHERE `quest`='595';
DELETE FROM `gameobject_questrelation` WHERE `quest`='595';
DELETE FROM `creature_involvedrelation` WHERE `quest`='595';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='595';
DELETE FROM `quest_template` WHERE `entry`='595';

-- QUEST: The Bloodsail Buccaneers quest from game (http://www.wowhead.com/quest=606)
DELETE FROM `creature_questrelation` WHERE `quest`='606';
DELETE FROM `gameobject_questrelation` WHERE `quest`='606';
DELETE FROM `creature_involvedrelation` WHERE `quest`='606';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='606';
DELETE FROM `quest_template` WHERE `entry`='606';

-- QUEST: Favor for Krazek quest from game (http://www.wowhead.com/quest=627)
DELETE FROM `creature_questrelation` WHERE `quest`='627';
DELETE FROM `gameobject_questrelation` WHERE `quest`='627';
DELETE FROM `creature_involvedrelation` WHERE `quest`='627';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='627';
DELETE FROM `quest_template` WHERE `entry`='627';

-- QUEST: Sunken Treasure quest from game (http://www.wowhead.com/quest=666)
DELETE FROM `creature_questrelation` WHERE `quest`='666';
DELETE FROM `gameobject_questrelation` WHERE `quest`='666';
DELETE FROM `creature_involvedrelation` WHERE `quest`='666';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='666';
DELETE FROM `quest_template` WHERE `entry`='666';

-- QUEST: Study of the Elements: Rock from game (http://www.wowhead.com/quest=710)
DELETE FROM `creature_questrelation` WHERE `quest`='710';
DELETE FROM `gameobject_questrelation` WHERE `quest`='710';
DELETE FROM `creature_involvedrelation` WHERE `quest`='710';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='710';
DELETE FROM `quest_template` WHERE `entry`='710';

-- QUEST: A Threat Within Reemove from game (http://www.wowhead.com/quest=783)
DELETE FROM `creature_questrelation` WHERE `quest`='783';
DELETE FROM `gameobject_questrelation` WHERE `quest`='783';
DELETE FROM `creature_involvedrelation` WHERE `quest`='783';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='783';
DELETE FROM `quest_template` WHERE `entry`='783';

-- QUEST: Betrayal from Within Reemove from game (http://www.wowhead.com/quest=879)
DELETE FROM `creature_questrelation` WHERE `quest`='879';
DELETE FROM `gameobject_questrelation` WHERE `quest`='879';
DELETE FROM `creature_involvedrelation` WHERE `quest`='879';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='879';
DELETE FROM `quest_template` WHERE `entry`='879';

-- QUEST: The Demon Seed Reemove from game (http://www.wowhead.com/quest=924)
DELETE FROM `creature_questrelation` WHERE `quest`='924';
DELETE FROM `gameobject_questrelation` WHERE `quest`='924';
DELETE FROM `creature_involvedrelation` WHERE `quest`='924';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='924';
DELETE FROM `quest_template` WHERE `entry`='924';

-- QUEST: Flute of Xavaric Reemove from game (http://www.wowhead.com/quest=939)
DELETE FROM `creature_questrelation` WHERE `quest`='939';
DELETE FROM `gameobject_questrelation` WHERE `quest`='939';
DELETE FROM `creature_involvedrelation` WHERE `quest`='939';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='939';
DELETE FROM `quest_template` WHERE `entry`='939';

-- QUEST: On Guard in Stonetalon Reemove from game (http://www.wowhead.com/quest=1070)
DELETE FROM `creature_questrelation` WHERE `quest`='1070';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1070';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1070';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1070';
DELETE FROM `quest_template` WHERE `entry`='1070';

-- QUEST: Gerenzo's Orders Reemove from game (http://www.wowhead.com/quest=1090)
DELETE FROM `creature_questrelation` WHERE `quest`='1090';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1090';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1090';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1090';
DELETE FROM `quest_template` WHERE `entry`='1090';

-- QUEST: The Tower of Althalaxx Reemove from game (http://www.wowhead.com/quest=1140)
DELETE FROM `creature_questrelation` WHERE `quest`='1140';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1140';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1140';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1140';
DELETE FROM `quest_template` WHERE `entry`='1140';

-- QUEST: The Brood of Onyxia Reemove from game (http://www.wowhead.com/quest=1170)
DELETE FROM `creature_questrelation` WHERE `quest`='1170';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1170';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1170';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1170';
DELETE FROM `quest_template` WHERE `entry`='1170';

-- QUEST: The Brood of Onyxia Reemove from game (http://www.wowhead.com/quest=1172)
DELETE FROM `creature_questrelation` WHERE `quest`='1172';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1172';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1172';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1172';
DELETE FROM `quest_template` WHERE `entry`='1172';

-- QUEST: Razzeric's Tweaking Reemove from game (http://www.wowhead.com/quest=1187)
DELETE FROM `creature_questrelation` WHERE `quest`='1187';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1187';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1187';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1187';
DELETE FROM `quest_template` WHERE `entry`='1187';

-- QUEST: The Black Shield Reemove from game (http://www.wowhead.com/quest=1253)
DELETE FROM `creature_questrelation` WHERE `quest`='1253';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1253';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1253';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1253';
DELETE FROM `quest_template` WHERE `entry`='1253';

-- QUEST: Lieutenant Paval Reethe Reemove from game (http://www.wowhead.com/quest=1259)
DELETE FROM `creature_questrelation` WHERE `quest`='1259';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1259';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1259';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1259';
DELETE FROM `quest_template` WHERE `entry`='1259';

-- QUEST: The Lost Caravan Reemove from game (http://www.wowhead.com/quest=1421)
DELETE FROM `creature_questrelation` WHERE `quest`='1421';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1421';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1421';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1421';
DELETE FROM `quest_template` WHERE `entry`='1421';

-- QUEST: Threat From the Sea Reemove from game (http://www.wowhead.com/quest=1426)
DELETE FROM `creature_questrelation` WHERE `quest`='1426';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1426';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1426';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1426';
DELETE FROM `quest_template` WHERE `entry`='1426';

-- QUEST: Call of Water Reemove from game (http://www.wowhead.com/quest=1528)
DELETE FROM `creature_questrelation` WHERE `quest`='1528';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1528';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1528';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1528';
DELETE FROM `quest_template` WHERE `entry`='1528';

-- QUEST: Call of Water Reemove from game (http://www.wowhead.com/quest=2041)
DELETE FROM `creature_questrelation` WHERE `quest`='2041';
DELETE FROM `gameobject_questrelation` WHERE `quest`='2041';
DELETE FROM `creature_involvedrelation` WHERE `quest`='2041';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='2041';
DELETE FROM `quest_template` WHERE `entry`='2041';

-- QUEST: Tran'rek Reemove from game (http://www.wowhead.com/quest=2864)
DELETE FROM `creature_questrelation` WHERE `quest`='2864';
DELETE FROM `gameobject_questrelation` WHERE `quest`='2864';
DELETE FROM `creature_involvedrelation` WHERE `quest`='2864';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='2864';
DELETE FROM `quest_template` WHERE `entry`='2864';

-- QUEST: Undamaged Venom Sac Reemove from game (http://www.wowhead.com/quest=2934)
DELETE FROM `creature_questrelation` WHERE `quest`='2934';
DELETE FROM `gameobject_questrelation` WHERE `quest`='2934';
DELETE FROM `creature_involvedrelation` WHERE `quest`='2934';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='2934';
DELETE FROM `quest_template` WHERE `entry`='2934';

-- QUEST: Loramus Reemove from game (http://www.wowhead.com/quest=3141)
DELETE FROM `creature_questrelation` WHERE `quest`='3141';
DELETE FROM `gameobject_questrelation` WHERE `quest`='3141';
DELETE FROM `creature_involvedrelation` WHERE `quest`='3141';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='3141';
DELETE FROM `quest_template` WHERE `entry`='3141';

-- QUEST: Ogre Head On A Stick = Party Reemove from game (http://www.wowhead.com/quest=3825)
DELETE FROM `creature_questrelation` WHERE `quest`='3825';
DELETE FROM `gameobject_questrelation` WHERE `quest`='3825';
DELETE FROM `creature_involvedrelation` WHERE `quest`='3825';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='3825';
DELETE FROM `quest_template` WHERE `entry`='3825';

-- QUEST: Commander Gor'shak Reemove from game (http://www.wowhead.com/quest=3981)
DELETE FROM `creature_questrelation` WHERE `quest`='3981';
DELETE FROM `gameobject_questrelation` WHERE `quest`='3981';
DELETE FROM `creature_involvedrelation` WHERE `quest`='3981';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='3981';
DELETE FROM `quest_template` WHERE `entry`='3981';

-- QUEST: Freed from the Hive Reemove from game (http://www.wowhead.com/quest=4265)
DELETE FROM `creature_questrelation` WHERE `quest`='4265';
DELETE FROM `gameobject_questrelation` WHERE `quest`='4265';
DELETE FROM `creature_involvedrelation` WHERE `quest`='4265';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='4265';
DELETE FROM `quest_template` WHERE `entry`='4265';

-- QUEST: Bijou's Belongings Reemove from game (http://www.wowhead.com/quest=5001)
DELETE FROM `creature_questrelation` WHERE `quest`='5001';
DELETE FROM `gameobject_questrelation` WHERE `quest`='5001';
DELETE FROM `creature_involvedrelation` WHERE `quest`='5001';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='5001';
DELETE FROM `quest_template` WHERE `entry`='5001';

-- QUEST: Falling to Corruption Reemove from game (http://www.wowhead.com/quest=5084)
DELETE FROM `creature_questrelation` WHERE `quest`='5084';
DELETE FROM `gameobject_questrelation` WHERE `quest`='5084';
DELETE FROM `creature_involvedrelation` WHERE `quest`='5084';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='5084';
DELETE FROM `quest_template` WHERE `entry`='5084';

-- QUEST: Dousing the Flames of Protection Reemove from game (http://www.wowhead.com/quest=5165)
DELETE FROM `creature_questrelation` WHERE `quest`='5165';
DELETE FROM `gameobject_questrelation` WHERE `quest`='5165';
DELETE FROM `creature_involvedrelation` WHERE `quest`='5165';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='5165';
DELETE FROM `quest_template` WHERE `entry`='5165';

-- QUEST: To Winterspring! Reemove from game (http://www.wowhead.com/quest=5249)
DELETE FROM `creature_questrelation` WHERE `quest`='5249';
DELETE FROM `gameobject_questrelation` WHERE `quest`='5249';
DELETE FROM `creature_involvedrelation` WHERE `quest`='5249';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='5249';
DELETE FROM `quest_template` WHERE `entry`='5249';

-- QUEST: Leonid Barthalomew Reemove from game (http://www.wowhead.com/quest=5522)
DELETE FROM `creature_questrelation` WHERE `quest`='5522';
DELETE FROM `gameobject_questrelation` WHERE `quest`='5522';
DELETE FROM `creature_involvedrelation` WHERE `quest`='5522';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='5522';
DELETE FROM `quest_template` WHERE `entry`='5522';

-- QUEST: Honor the Dead Reemove from game (http://www.wowhead.com/quest=6183)
DELETE FROM `creature_questrelation` WHERE `quest`='6183';
DELETE FROM `gameobject_questrelation` WHERE `quest`='6183';
DELETE FROM `creature_involvedrelation` WHERE `quest`='6183';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='6183';
DELETE FROM `quest_template` WHERE `entry`='6183';

-- QUEST: What the Wind Carries Reemove from game (http://www.wowhead.com/quest=6566)
DELETE FROM `creature_questrelation` WHERE `quest`='6566';
DELETE FROM `gameobject_questrelation` WHERE `quest`='6566';
DELETE FROM `creature_involvedrelation` WHERE `quest`='6566';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='6566';
DELETE FROM `quest_template` WHERE `entry`='6566';

-- QUEST: The Madness Within Reemove from game (http://www.wowhead.com/quest=7461)
DELETE FROM `creature_questrelation` WHERE `quest`='7461';
DELETE FROM `gameobject_questrelation` WHERE `quest`='7461';
DELETE FROM `creature_involvedrelation` WHERE `quest`='7461';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='7461';
DELETE FROM `quest_template` WHERE `entry`='7461';

-- QUEST: Chillwind Camp Reemove from game (http://www.wowhead.com/quest=8415)
DELETE FROM `creature_questrelation` WHERE `quest`='8415';
DELETE FROM `gameobject_questrelation` WHERE `quest`='8415';
DELETE FROM `creature_involvedrelation` WHERE `quest`='8415';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='8415';
DELETE FROM `quest_template` WHERE `entry`='8415';

-- QUEST: Just Compensation Reemove from game (http://www.wowhead.com/quest=8944)
DELETE FROM `creature_questrelation` WHERE `quest`='8944';
DELETE FROM `gameobject_questrelation` WHERE `quest`='8944';
DELETE FROM `creature_involvedrelation` WHERE `quest`='8944';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='8944';
DELETE FROM `quest_template` WHERE `entry`='8944';

-- QUEST: Call of Fire Reemove from game (http://www.wowhead.com/quest=9468)
DELETE FROM `creature_questrelation` WHERE `quest`='9468';
DELETE FROM `gameobject_questrelation` WHERE `quest`='9468';
DELETE FROM `creature_involvedrelation` WHERE `quest`='9468';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='9468';
DELETE FROM `quest_template` WHERE `entry`='9468';

-- QUEST: Jol Reemove from game (http://www.wowhead.com/quest=10366)
DELETE FROM `creature_questrelation` WHERE `quest`='10366';
DELETE FROM `gameobject_questrelation` WHERE `quest`='10366';
DELETE FROM `creature_involvedrelation` WHERE `quest`='10366';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='10366';
DELETE FROM `quest_template` WHERE `entry`='10366';

-- QUEST: Onward to Ashenvale Reemove from game (http://www.wowhead.com/quest=10752)
DELETE FROM `creature_questrelation` WHERE `quest`='10752';
DELETE FROM `gameobject_questrelation` WHERE `quest`='10752';
DELETE FROM `creature_involvedrelation` WHERE `quest`='10752';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='10752';
DELETE FROM `quest_template` WHERE `entry`='10752';

-- QUEST: Defias in Dustwallow? Reemove from game (http://www.wowhead.com/quest=11137)
DELETE FROM `creature_questrelation` WHERE `quest`='11137';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11137';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11137';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11137';
DELETE FROM `quest_template` WHERE `entry`='11137';

-- QUEST: Jaina Must Know Reemove from game (http://www.wowhead.com/quest=11141)
DELETE FROM `creature_questrelation` WHERE `quest`='11141';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11141';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11141';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11141';
DELETE FROM `quest_template` WHERE `entry`='11141';

-- QUEST: Justice for the Hyals Reemove from game (http://www.wowhead.com/quest=11151)
DELETE FROM `creature_questrelation` WHERE `quest`='11151';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11151';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11151';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11151';
DELETE FROM `quest_template` WHERE `entry`='11151';

-- QUEST: Spirits of Stonemaul Hold Reemove from game (http://www.wowhead.com/quest=11159)
DELETE FROM `creature_questrelation` WHERE `quest`='11159';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11159';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11159';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11159';
DELETE FROM `quest_template` WHERE `entry`='11159';

-- QUEST: Thresher Oil Reemove from game (http://www.wowhead.com/quest=11192)
DELETE FROM `creature_questrelation` WHERE `quest`='11192';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11192';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11192';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11192';
DELETE FROM `quest_template` WHERE `entry`='11192';

-- QUEST: Nat's Bargain Reemove from game (http://www.wowhead.com/quest=11209)
DELETE FROM `creature_questrelation` WHERE `quest`='11209';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11209';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11209';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11209';
DELETE FROM `quest_template` WHERE `entry`='11209';

-- QUEST: Recalling Reemove from game (http://www.wowhead.com/quest=28896)
DELETE FROM `creature_questrelation` WHERE `quest`='28896';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28896';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28896';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28896';
DELETE FROM `quest_template` WHERE `entry`='28896';

-- QUEST: Secretion and Subterfuge Reemove from game (http://www.wowhead.com/quest=28898)
DELETE FROM `creature_questrelation` WHERE `quest`='28898';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28898';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28898';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28898';
DELETE FROM `quest_template` WHERE `entry`='28898';

-- QUEST: Riding in Plain Sight Reemove from game (http://www.wowhead.com/quest=28899)
DELETE FROM `creature_questrelation` WHERE `quest`='28899';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28899';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28899';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28899';
DELETE FROM `quest_template` WHERE `entry`='28899';

-- QUEST: Mysteries of the Twilight Hive Reemove from game (http://www.wowhead.com/quest=28900)
DELETE FROM `creature_questrelation` WHERE `quest`='28900';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28900';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28900';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28900';
DELETE FROM `quest_template` WHERE `entry`='28900';

-- QUEST: Unknow quest Reemove from game (http://www.wowhead.com/quest=987654)
DELETE FROM `creature_questrelation` WHERE `quest`='987654';
DELETE FROM `gameobject_questrelation` WHERE `quest`='987654';
DELETE FROM `creature_involvedrelation` WHERE `quest`='987654';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='987654';
DELETE FROM `quest_template` WHERE `entry`='987654';

-- QUEST: Battle of Hillsbrad Reemove from game (http://www.wowhead.com/quest=529)
DELETE FROM `creature_questrelation` WHERE `quest`='529';
DELETE FROM `gameobject_questrelation` WHERE `quest`='529';
DELETE FROM `creature_involvedrelation` WHERE `quest`='529';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='529';
DELETE FROM `quest_template` WHERE `entry`='529';

-- QUEST: Infiltration Reemove from game (http://www.wowhead.com/quest=533)
DELETE FROM `creature_questrelation` WHERE `quest`='533';
DELETE FROM `gameobject_questrelation` WHERE `quest`='533';
DELETE FROM `creature_involvedrelation` WHERE `quest`='533';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='533';
DELETE FROM `quest_template` WHERE `entry`='533';

-- QUEST: Helcular's Revenge Reemove from game (http://www.wowhead.com/quest=552)
DELETE FROM `creature_questrelation` WHERE `quest`='552';
DELETE FROM `gameobject_questrelation` WHERE `quest`='552';
DELETE FROM `creature_involvedrelation` WHERE `quest`='552';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='552';
DELETE FROM `quest_template` WHERE `entry`='552';

-- QUEST: Sunken Treasure Reemove from game (http://www.wowhead.com/quest=665)
DELETE FROM `creature_questrelation` WHERE `quest`='665';
DELETE FROM `gameobject_questrelation` WHERE `quest`='665';
DELETE FROM `creature_involvedrelation` WHERE `quest`='665';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='665';
DELETE FROM `quest_template` WHERE `entry`='665';

-- QUEST: Lieutenant Paval Reethe Reemove from game (http://www.wowhead.com/quest=1252)
DELETE FROM `creature_questrelation` WHERE `quest`='1252';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1252';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1252';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1252';
DELETE FROM `quest_template` WHERE `entry`='1252';

-- QUEST: Threat From the Sea Reemove from game (http://www.wowhead.com/quest=1422)
DELETE FROM `creature_questrelation` WHERE `quest`='1422';
DELETE FROM `gameobject_questrelation` WHERE `quest`='1422';
DELETE FROM `creature_involvedrelation` WHERE `quest`='1422';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='1422';
DELETE FROM `quest_template` WHERE `entry`='1422';

-- QUEST: Venom Bottles Reemove from game (http://www.wowhead.com/quest=2933)
DELETE FROM `creature_questrelation` WHERE `quest`='2933';
DELETE FROM `gameobject_questrelation` WHERE `quest`='2933';
DELETE FROM `creature_involvedrelation` WHERE `quest`='2933';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='2933';
DELETE FROM `quest_template` WHERE `entry`='2933';

-- QUEST: Cleansed Water Returns to Felwood Reemove from game (http://www.wowhead.com/quest=5159)
DELETE FROM `creature_questrelation` WHERE `quest`='5159';
DELETE FROM `gameobject_questrelation` WHERE `quest`='5159';
DELETE FROM `creature_involvedrelation` WHERE `quest`='5159';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='5159';
DELETE FROM `quest_template` WHERE `entry`='5159';

-- QUEST: Brother Anton Reemove from game (http://www.wowhead.com/quest=6141)
DELETE FROM `creature_questrelation` WHERE `quest`='6141';
DELETE FROM `gameobject_questrelation` WHERE `quest`='6141';
DELETE FROM `creature_involvedrelation` WHERE `quest`='6141';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='6141';
DELETE FROM `quest_template` WHERE `entry`='6141';

-- QUEST: The First and the Last Reemove from game (http://www.wowhead.com/quest=6182)
DELETE FROM `creature_questrelation` WHERE `quest`='6182';
DELETE FROM `gameobject_questrelation` WHERE `quest`='6182';
DELETE FROM `creature_involvedrelation` WHERE `quest`='6182';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='6182';
DELETE FROM `quest_template` WHERE `entry`='6182';

-- QUEST: Raze Direhorn Post! Reemove from game (http://www.wowhead.com/quest=11150)
DELETE FROM `creature_questrelation` WHERE `quest`='11150';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11150';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11150';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11150';
DELETE FROM `quest_template` WHERE `entry`='11150';

-- QUEST: This Old Lighthouse Reemove from game (http://www.wowhead.com/quest=11191)
DELETE FROM `creature_questrelation` WHERE `quest`='11191';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11191';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11191';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11191';
DELETE FROM `quest_template` WHERE `entry`='11191';

-- QUEST: Is it Real? Reemove from game (http://www.wowhead.com/quest=11194)
DELETE FROM `creature_questrelation` WHERE `quest`='11194';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11194';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11194';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11194';
DELETE FROM `quest_template` WHERE `entry`='11194';

-- QUEST: Baristolth's Plan Reemove from game (http://www.wowhead.com/quest=28897)
DELETE FROM `creature_questrelation` WHERE `quest`='28897';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28897';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28897';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28897';
DELETE FROM `quest_template` WHERE `entry`='28897';

-- QUEST: Prisoners of Madness Reemove from game (http://www.wowhead.com/quest=28901)
DELETE FROM `creature_questrelation` WHERE `quest`='28901';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28901';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28901';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28901';
DELETE FROM `quest_template` WHERE `entry`='28901';

-- QUEST: Bad Stuff Reemove from game (http://www.wowhead.com/quest=28904)
DELETE FROM `creature_questrelation` WHERE `quest`='28904';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28904';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28904';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28904';
DELETE FROM `quest_template` WHERE `entry`='28904';

-- QUEST: Diva Dilemma Reemove from game (http://www.wowhead.com/quest=28936)
DELETE FROM `creature_questrelation` WHERE `quest`='28936';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28936';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28936';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28936';
DELETE FROM `quest_template` WHERE `entry`='28936';

-- QUEST: Save the Children Reemove from game (http://www.wowhead.com/quest=28938)
DELETE FROM `creature_questrelation` WHERE `quest`='28938';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28938';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28938';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28938';
DELETE FROM `quest_template` WHERE `entry`='28938';

-- QUEST: Beware of Strangers Reemove from game (http://www.wowhead.com/quest=28939)
DELETE FROM `creature_questrelation` WHERE `quest`='28939';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28939';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28939';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28939';
DELETE FROM `quest_template` WHERE `entry`='28939';

-- QUEST: Get Antidote Reemove from game (http://www.wowhead.com/quest=28940)
DELETE FROM `creature_questrelation` WHERE `quest`='28940';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28940';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28940';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28940';
DELETE FROM `quest_template` WHERE `entry`='28940';

-- QUEST: Transformation Reemove from game (http://www.wowhead.com/quest=28941)
DELETE FROM `creature_questrelation` WHERE `quest`='28941';
DELETE FROM `gameobject_questrelation` WHERE `quest`='28941';
DELETE FROM `creature_involvedrelation` WHERE `quest`='28941';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='28941';
DELETE FROM `quest_template` WHERE `entry`='28941';

-- QUEST: Kitchen Clean-Up Reemove from game (http://www.wowhead.com/quest=29042)
DELETE FROM `creature_questrelation` WHERE `quest`='29042';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29042';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29042';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29042';
DELETE FROM `quest_template` WHERE `entry`='29042';

-- QUEST: Lunch Break Reemove from game (http://www.wowhead.com/quest=29043)
DELETE FROM `creature_questrelation` WHERE `quest`='29043';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29043';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29043';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29043';
DELETE FROM `quest_template` WHERE `entry`='29043';

-- QUEST: No Child of Mine Reemove from game (http://www.wowhead.com/quest=29044)
DELETE FROM `creature_questrelation` WHERE `quest`='29044';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29044';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29044';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29044';
DELETE FROM `quest_template` WHERE `entry`='29044';

-- QUEST: Fit for a King Reemove from game (http://www.wowhead.com/quest=29045)
DELETE FROM `creature_questrelation` WHERE `quest`='29045';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29045';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29045';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29045';
DELETE FROM `quest_template` WHERE `entry`='29045';

-- QUEST: Chef's Challenge: Steelback Reemove from game (http://www.wowhead.com/quest=29046)
DELETE FROM `creature_questrelation` WHERE `quest`='29046';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29046';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29046';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29046';
DELETE FROM `quest_template` WHERE `entry`='29046';

-- QUEST: Chef's Challenge: Faewing Reemove from game (http://www.wowhead.com/quest=29047)
DELETE FROM `creature_questrelation` WHERE `quest`='29047';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29047';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29047';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29047';
DELETE FROM `quest_template` WHERE `entry`='29047';

-- QUEST: Chef's Challenge: Grumpfin Reemove from game (http://www.wowhead.com/quest=29048)
DELETE FROM `creature_questrelation` WHERE `quest`='29048';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29048';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29048';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29048';
DELETE FROM `quest_template` WHERE `entry`='29048';

-- QUEST: Out of Gas Reemove from game (http://www.wowhead.com/quest=29050)
DELETE FROM `creature_questrelation` WHERE `quest`='29050';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29050';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29050';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29050';
DELETE FROM `quest_template` WHERE `entry`='29050';

-- QUEST: Float My Boat Reemove from game (http://www.wowhead.com/quest=29055)
DELETE FROM `creature_questrelation` WHERE `quest`='29055';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29055';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29055';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29055';
DELETE FROM `quest_template` WHERE `entry`='29055';

-- QUEST: Fruit Round-Up Reemove from game (http://www.wowhead.com/quest=29056)
DELETE FROM `creature_questrelation` WHERE `quest`='29056';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29056';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29056';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29056';
DELETE FROM `quest_template` WHERE `entry`='29056';

-- QUEST: Firebeak Reemove from game (http://www.wowhead.com/quest=29057)
DELETE FROM `creature_questrelation` WHERE `quest`='29057';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29057';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29057';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29057';
DELETE FROM `quest_template` WHERE `entry`='29057';

-- QUEST: Roc Collection Reemove from game (http://www.wowhead.com/quest=29058)
DELETE FROM `creature_questrelation` WHERE `quest`='29058';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29058';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29058';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29058';
DELETE FROM `quest_template` WHERE `entry`='29058';

-- QUEST: Save 'Em Reemove from game (http://www.wowhead.com/quest=29059)
DELETE FROM `creature_questrelation` WHERE `quest`='29059';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29059';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29059';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29059';
DELETE FROM `quest_template` WHERE `entry`='29059';

-- QUEST: At Your Service Remove from game (http://www.wowhead.com/quest=29060)
DELETE FROM `creature_questrelation` WHERE `quest`='29060';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29060';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29060';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29060';
DELETE FROM `quest_template` WHERE `entry`='29060';

-- QUEST: Finding the Cultist Remove from game (http://www.wowhead.com/quest=29062)
DELETE FROM `creature_questrelation` WHERE `quest`='29062';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29062';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29062';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29062';
DELETE FROM `quest_template` WHERE `entry`='29062';

-- QUEST: Out of This World Remove from game (http://www.wowhead.com/quest=29065)
DELETE FROM `creature_questrelation` WHERE `quest`='29065';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29065';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29065';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29065';
DELETE FROM `quest_template` WHERE `entry`='29065';

-- QUEST: Kevin's Test Quest Remove from game (http://www.wowhead.com/quest=29076)
DELETE FROM `creature_questrelation` WHERE `quest`='29076';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29076';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29076';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29076';
DELETE FROM `quest_template` WHERE `entry`='29076';

-- QUEST: Mor'shan Caravan Pick-Up Remove from game (http://www.wowhead.com/quest=29096)
DELETE FROM `creature_questrelation` WHERE `quest`='29096';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29096';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29096';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29096';
DELETE FROM `quest_template` WHERE `entry`='29096';

-- QUEST: Follow That Cat Remove from game (http://www.wowhead.com/quest=29116)
DELETE FROM `creature_questrelation` WHERE `quest`='29116';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29116';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29116';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29116';
DELETE FROM `quest_template` WHERE `entry`='29116';

-- QUEST: Under the Skylord's Gaze Remove from game (http://www.wowhead.com/quest=29140)
DELETE FROM `creature_questrelation` WHERE `quest`='29140';
DELETE FROM `gameobject_questrelation` WHERE `quest`='29140';
DELETE FROM `creature_involvedrelation` WHERE `quest`='29140';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='29140';
DELETE FROM `quest_template` WHERE `entry`='29140';

-- QUEST: Warlord of the Amani Remove from game, this quest is for 4.1.0 client (http://www.wowhead.com/quest=11196)
DELETE FROM `creature_questrelation` WHERE `quest`='11196';
DELETE FROM `gameobject_questrelation` WHERE `quest`='11196';
DELETE FROM `creature_involvedrelation` WHERE `quest`='11196';
DELETE FROM `gameobject_involvedrelation` WHERE `quest`='11196';
DELETE FROM `quest_template` WHERE `entry`='11196';

-- QUEST_ Remove from game old quest (DEPRECATED) from game that's finish all ques errors
-- http://www.wowhead.com/quest=29212
-- http://www.wowhead.com/quest=29216
-- http://www.wowhead.com/quest=29218
-- http://www.wowhead.com/quest=29224
-- http://www.wowhead.com/quest=29228
-- http://www.wowhead.com/quest=29256
-- http://www.wowhead.com/quest=29258
-- http://www.wowhead.com/quest=29259
-- http://www.wowhead.com/quest=29260
-- http://www.wowhead.com/quest=29266
-- http://www.wowhead.com/quest=29271
-- http://www.wowhead.com/quest=29277
-- http://www.wowhead.com/quest=29286
-- http://www.wowhead.com/quest=29291
-- http://www.wowhead.com/quest=29292
-- http://www.wowhead.com/quest=29294
-- http://www.wowhead.com/quest=29378
-- http://www.wowhead.com/quest=29379
-- http://www.wowhead.com/quest=29380
-- http://www.wowhead.com/quest=29381
-- http://www.wowhead.com/quest=29395
-- http://www.wowhead.com/quest=29212
-- http://www.wowhead.com/quest=29216
-- http://www.wowhead.com/quest=29218
-- http://www.wowhead.com/quest=29224
-- http://www.wowhead.com/quest=4118
-- http://www.wowhead.com/quest=4444
-- http://www.wowhead.com/quest=699
DELETE FROM `creature_questrelation` WHERE `quest` IN (698,699,29228,29256,29258,29259,29260,29266,29271,29277,29286,29291,29292,29294,29378,29379,29380,29381,29395,29212,29216,29218,29224,4118,4444);
DELETE FROM `gameobject_questrelation` WHERE `quest` IN (698,699,29228,29256,29258,29259,29260,29266,29271,29277,29286,29291,29292,29294,29378,29379,29380,29381,29395,29212,29216,29218,29224,4118,4444);
DELETE FROM `creature_involvedrelation` WHERE `quest` IN (698,699,29228,29256,29258,29259,29260,29266,29271,29277,29286,29291,29292,29294,29378,29379,29380,29381,29395,29212,29216,29218,29224,4118,4444);
DELETE FROM `gameobject_involvedrelation` WHERE `quest` IN (698,699,29228,29256,29258,29259,29260,29266,29271,29277,29286,29291,29292,29294,29378,29379,29380,29381,29395,29212,29216,29218,29224,4118,4444);
DELETE FROM `quest_template` WHERE `entry` IN (698,699,29228,29256,29258,29259,29260,29266,29271,29277,29286,29291,29292,29294,29378,29379,29380,29381,29395,29212,29216,29218,29224,4118,4444);

-- Gasping for Breath Fix requeriments (http://www.wowhead.com/quest=14395)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='4' WHERE `entry`='14395';

-- You Can't Take 'Em Alone Fix quest for worgen area (http://www.wowhead.com/quest=14348)
UPDATE `quest_template` SET `ReqCreatureOrGOId1` = 36231, `ReqCreatureOrGOCount1`='4', `ReqSpellCast1`='69094' WHERE `entry`='14348';

-- QUEST: Save Krennan Aranas Fix quest (http://www.wowhead.com/quet=14293)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='14293';

-- QUEST: Immolate Fix quest (http://www.wowhead.com/quet=14274)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='14274';

-- QUEST: Flash Heal Fix quest (http://www.wowhead.com/quet=14279)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='2' WHERE `entry`='14279';

-- QUEST: Charge Fix quest (http://www.wowhead.com/quet=14266)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='14266';

-- QUEST: Eviscerate Fix quest (http://www.wowhead.com/quet=14272)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='14272';

-- QUEST: Sacrifices Fix quest (http://www.wowhead.com/quet=14212)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='30' WHERE `entry`='14212';

-- QUEST: Nibbler! No! Fix quest (http://www.wowhead.com/quet=25158)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`='52086' WHERE `entry`='25158';

-- QUEST:A Present for Lila Fix quest (http://www.wowhead.com/quet=25160)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`='0', `ReqCreatureOrGOCount1`='0', `ReqItemId1`='52098', `ReqItemCount1`='2', `ReqItemId2`='0', `ReqItemCount2`='0' WHERE `entry`='25160';

-- QUEST: Ogrezonians in the Mood Fix quest (http://www.wowhead.com/quet=25161)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`='0', `ReqCreatureOrGOCount1`='0', `ReqItemId1`='52121', `ReqItemCount1`='2', `ReqItemId2`='0', `ReqItemCount2`='0' WHERE `entry`='25161';

-- QUEST: Firebeard Bellows Fix quest (http://www.wowhead.com/quet=27809)
UPDATE `quest_template` SET `NextQuestId`='27810' WHERE `entry`='27809';

-- QUEST: Steady Shot Fix quest (http://www.wowhead.com/quet=14276)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='2' WHERE `entry`='14276';

-- QUEST: Preparations quest (http://www.wowhead.com/quet=24628)
UPDATE `quest_template` SET `ReqItemCount1`='4' WHERE `entry`='24628';

-- QUEST: Patriarch's Blessing Fix  quest (http://www.wowhead.com/quet=24679)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='24679';

-- QUEST: They Have Allies, But So Do We Fix  quest (http://www.wowhead.com/quet=24681)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='40',`ReqCreatureOrGOCount2`='8', `ReqCreatureOrGOCount3`='4' WHERE `entry`='24681';

-- QUEST: Patriarch's Blessing Fix  quest (http://www.wowhead.com/quet=24679)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='24679';

-- QUEST: The Battle for Gilneas City Fix  quest (http://www.wowhead.com/quet=24904)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='24904';

-- QUEST: Slowing the Inevitable Fix  quest (http://www.wowhead.com/quet=24920)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='6',`ReqCreatureOrGOCount2`='4' WHERE `entry`='24920';

-- QUEST: Endgame Fix  quest (http://www.wowhead.com/quet=26706)
UPDATE `quest_template` SET `ReqCreatureOrGOCount1`='1' WHERE `entry`='26706';

-- QUEST: Samophlange in the Mood Fix quest (http://www.wowhead.com/quet=29022)
UPDATE `quest_template` SET `ReqCreatureOrGOId1`='-4072', `ReqCreatureOrGOId2`='-61936', `ReqCreatureOrGOId3`='-61935' WHERE `entry`='29022';

-- QUEST: By the Skin of His Teeth Missing SpecialFlags (http://www.wowhead.com/quest=14154)
UPDATE `quest_template` SET `SpecialFlags`='2' WHERE `entry`='14154';