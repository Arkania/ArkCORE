# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wlasser/prog/ArkCORE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wlasser/prog/ArkCORE/build

# Utility rule file for pch_Generate_worldserver.

src/server/worldserver/CMakeFiles/pch_Generate_worldserver: src/server/worldserver/worldPCH.h.gch/worldserver_Release.gch

src/server/worldserver/worldPCH.h.gch/worldserver_Release.gch: ../src/server/worldserver/PrecompiledHeaders/worldPCH.h
src/server/worldserver/worldPCH.h.gch/worldserver_Release.gch: src/server/worldserver/worldPCH.h
src/server/worldserver/worldPCH.h.gch/worldserver_Release.gch: src/server/worldserver/libworldserver_pch_dephelp.a
	$(CMAKE_COMMAND) -E cmake_progress_report /home/wlasser/prog/ArkCORE/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating worldPCH.h.gch/worldserver_Release.gch"
	cd /home/wlasser/prog/ArkCORE/build/src/server/worldserver && /usr/bin/c++ -O3 -DNDEBUG -I/usr/include -I/home/wlasser/prog/ArkCORE/build/src/server/worldserver -I/home/wlasser/prog/ArkCORE/build -I/home/wlasser/prog/ArkCORE/dep/gsoap -I/home/wlasser/prog/ArkCORE/dep/SFMT -I/home/wlasser/prog/ArkCORE/dep/mersennetwister -I/home/wlasser/prog/ArkCORE/src/server/collision -I/home/wlasser/prog/ArkCORE/src/server/collision/Management -I/home/wlasser/prog/ArkCORE/src/server/shared -I/home/wlasser/prog/ArkCORE/src/server/shared/Configuration -I/home/wlasser/prog/ArkCORE/src/server/shared/Cryptography -I/home/wlasser/prog/ArkCORE/src/server/shared/Cryptography/Authentication -I/home/wlasser/prog/ArkCORE/src/server/shared/Database -I/home/wlasser/prog/ArkCORE/src/server/shared/DataStores -I/home/wlasser/prog/ArkCORE/src/server/shared/Debugging -I/home/wlasser/prog/ArkCORE/src/server/shared/Dynamic/CountedReference -I/home/wlasser/prog/ArkCORE/src/server/shared/Dynamic/LinkedReference -I/home/wlasser/prog/ArkCORE/src/server/shared/Dynamic -I/home/wlasser/prog/ArkCORE/src/server/shared/Logging -I/home/wlasser/prog/ArkCORE/src/server/shared/Packets -I/home/wlasser/prog/ArkCORE/src/server/shared/Policies -I/home/wlasser/prog/ArkCORE/src/server/shared/Threading -I/home/wlasser/prog/ArkCORE/src/server/shared/Utilities -I/home/wlasser/prog/ArkCORE/src/server/game -I/home/wlasser/prog/ArkCORE/src/server/game/Accounts -I/home/wlasser/prog/ArkCORE/src/server/game/Achievements -I/home/wlasser/prog/ArkCORE/src/server/game/Addons -I/home/wlasser/prog/ArkCORE/src/server/game/AI -I/home/wlasser/prog/ArkCORE/src/server/game/AI/CoreAI -I/home/wlasser/prog/ArkCORE/src/server/game/AI/EventAI -I/home/wlasser/prog/ArkCORE/src/server/game/AI/ScriptedAI -I/home/wlasser/prog/ArkCORE/src/server/game/AI/SmartScripts -I/home/wlasser/prog/ArkCORE/src/server/game/AuctionHouse -I/home/wlasser/prog/ArkCORE/src/server/game/AuctionHouse/AuctionHouseBot -I/home/wlasser/prog/ArkCORE/src/server/game/Battlegrounds -I/home/wlasser/prog/ArkCORE/src/server/game/Battlegrounds/Zones -I/home/wlasser/prog/ArkCORE/src/server/game/Calendar -I/home/wlasser/prog/ArkCORE/src/server/game/Chat -I/home/wlasser/prog/ArkCORE/src/server/game/Chat/Channels -I/home/wlasser/prog/ArkCORE/src/server/game/Chat/Commands -I/home/wlasser/prog/ArkCORE/src/server/game/Combat -I/home/wlasser/prog/ArkCORE/src/server/game/Conditions -I/home/wlasser/prog/ArkCORE/src/server/game/DataStores -I/home/wlasser/prog/ArkCORE/src/server/game/DungeonFinding -I/home/wlasser/prog/ArkCORE/src/server/game/Entities -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Creature -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Corpse -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/DynamicObject -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/GameObject -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Item -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Item/Container -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Object -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Object/Updates -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Pet -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Player -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Totem -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Unit -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Vehicle -I/home/wlasser/prog/ArkCORE/src/server/game/Entities/Transport -I/home/wlasser/prog/ArkCORE/src/server/game/Events -I/home/wlasser/prog/ArkCORE/src/server/game/Globals -I/home/wlasser/prog/ArkCORE/src/server/game/Grids/Cells -I/home/wlasser/prog/ArkCORE/src/server/game/Grids/Notifiers -I/home/wlasser/prog/ArkCORE/src/server/game/Grids -I/home/wlasser/prog/ArkCORE/src/server/game/Groups -I/home/wlasser/prog/ArkCORE/src/server/game/Guilds -I/home/wlasser/prog/ArkCORE/src/server/game/Instances -I/home/wlasser/prog/ArkCORE/src/server/game/Loot -I/home/wlasser/prog/ArkCORE/src/server/game/Mails -I/home/wlasser/prog/ArkCORE/src/server/game/Maps -I/home/wlasser/prog/ArkCORE/src/server/game/Miscellaneous -I/home/wlasser/prog/ArkCORE/src/server/game/Movement -I/home/wlasser/prog/ArkCORE/src/server/game/Movement/MovementGenerators -I/home/wlasser/prog/ArkCORE/src/server/game/Movement/Waypoints -I/home/wlasser/prog/ArkCORE/src/server/game/OutdoorPvP -I/home/wlasser/prog/ArkCORE/src/server/game/Pools -I/home/wlasser/prog/ArkCORE/src/server/game/PrecompiledHeaders -I/home/wlasser/prog/ArkCORE/src/server/game/Quests -I/home/wlasser/prog/ArkCORE/src/server/game/Reputation -I/home/wlasser/prog/ArkCORE/src/server/game/Scripting -I/home/wlasser/prog/ArkCORE/src/server/game/Server/Protocol -I/home/wlasser/prog/ArkCORE/src/server/game/Server/Protocol/Handlers -I/home/wlasser/prog/ArkCORE/src/server/game/Server -I/home/wlasser/prog/ArkCORE/src/server/game/Skills -I/home/wlasser/prog/ArkCORE/src/server/game/Spells -I/home/wlasser/prog/ArkCORE/src/server/game/Spells/Auras -I/home/wlasser/prog/ArkCORE/src/server/game/Tools -I/home/wlasser/prog/ArkCORE/src/server/game/Weather -I/home/wlasser/prog/ArkCORE/src/server/game/World -I/home/wlasser/prog/ArkCORE/src/server/authserver/Server -I/home/wlasser/prog/ArkCORE/src/server/worldserver -I/home/wlasser/prog/ArkCORE/src/server/worldserver/CommandLine -I/home/wlasser/prog/ArkCORE/src/server/worldserver/RemoteAccess -I/home/wlasser/prog/ArkCORE/src/server/worldserver/TCSoap -I/home/wlasser/prog/ArkCORE/src/server/worldserver/WorldThread -I/usr/local/include -I/usr/include/mysql -D_BUILD_DIRECTIVE='"Release"' -fno-delete-null-pointer-checks --no-warnings -DSCRIPTS -DARKCORE_COREPCH -fno-delete-null-pointer-checks -D_ARKCORE_CORE_CONFIG='"/home/wlasser/prog/test/etc/worldserver.conf"' -D_BUILD_DIRECTIVE='"Release"' -fno-delete-null-pointer-checks --no-warnings -DSCRIPTS -DARKCORE_COREPCH -x c++-header -o /home/wlasser/prog/ArkCORE/build/src/server/worldserver/worldPCH.h.gch/worldserver_Release.gch /home/wlasser/prog/ArkCORE/build/src/server/worldserver/worldPCH.h

src/server/worldserver/worldPCH.h: ../src/server/worldserver/PrecompiledHeaders/worldPCH.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/wlasser/prog/ArkCORE/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating worldPCH.h"
	cd /home/wlasser/prog/ArkCORE/build/src/server/worldserver && /usr/bin/cmake -E copy /home/wlasser/prog/ArkCORE/src/server/worldserver/PrecompiledHeaders/worldPCH.h /home/wlasser/prog/ArkCORE/build/src/server/worldserver/worldPCH.h

pch_Generate_worldserver: src/server/worldserver/CMakeFiles/pch_Generate_worldserver
pch_Generate_worldserver: src/server/worldserver/worldPCH.h.gch/worldserver_Release.gch
pch_Generate_worldserver: src/server/worldserver/worldPCH.h
pch_Generate_worldserver: src/server/worldserver/CMakeFiles/pch_Generate_worldserver.dir/build.make
.PHONY : pch_Generate_worldserver

# Rule to build all files generated by this target.
src/server/worldserver/CMakeFiles/pch_Generate_worldserver.dir/build: pch_Generate_worldserver
.PHONY : src/server/worldserver/CMakeFiles/pch_Generate_worldserver.dir/build

src/server/worldserver/CMakeFiles/pch_Generate_worldserver.dir/clean:
	cd /home/wlasser/prog/ArkCORE/build/src/server/worldserver && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_worldserver.dir/cmake_clean.cmake
.PHONY : src/server/worldserver/CMakeFiles/pch_Generate_worldserver.dir/clean

src/server/worldserver/CMakeFiles/pch_Generate_worldserver.dir/depend:
	cd /home/wlasser/prog/ArkCORE/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wlasser/prog/ArkCORE /home/wlasser/prog/ArkCORE/src/server/worldserver /home/wlasser/prog/ArkCORE/build /home/wlasser/prog/ArkCORE/build/src/server/worldserver /home/wlasser/prog/ArkCORE/build/src/server/worldserver/CMakeFiles/pch_Generate_worldserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/server/worldserver/CMakeFiles/pch_Generate_worldserver.dir/depend

