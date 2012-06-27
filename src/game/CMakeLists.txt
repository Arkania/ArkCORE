# Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
#
# Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
#
# Copyright (C) 2010 - 2012 ArkCORE <http://www.arkania.net/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if( USE_COREPCH )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

file(GLOB_RECURSE sources_Achievements Achievements/*.cpp Achievements/*.h)
file(GLOB_RECURSE sources_Addons Addons/*.cpp Addons/*.h)
file(GLOB_RECURSE sources_AuctionHouse AuctionHouse/*.cpp AuctionHouse/*.h)
file(GLOB_RECURSE sources_AuctionHouseBot AuctionHouse/AuctionHouseBot/*.cpp AuctionHouse/AuctionHouseBot/*.h)
file(GLOB_RECURSE sources_Battlegrounds Battlegrounds/*.cpp Battlegrounds/*.h)
file(GLOB_RECURSE sources_Calendar Calendar/*.cpp Calendar/*.h)
file(GLOB_RECURSE sources_Chat Chat/*.cpp Chat/*.h)
file(GLOB_RECURSE sources_Combat Combat/*.cpp Combat/*.h)
file(GLOB_RECURSE sources_DungeonFinding DungeonFinding/*.cpp DungeonFinding/*.h)
file(GLOB_RECURSE sources_Entities Entities/*.cpp Entities/*.h)
file(GLOB_RECURSE sources_Events Events/*.cpp Events/*.h)
file(GLOB_RECURSE sources_Grids Grids/*.cpp Grids/*.h)
file(GLOB_RECURSE sources_Groups Groups/*.cpp Groups/*.h)
file(GLOB_RECURSE sources_Guilds Guilds/*.cpp Guilds/*.h)
file(GLOB_RECURSE sources_Instances Instances/*.cpp Instances/*.h)
file(GLOB_RECURSE sources_Loot Loot/*.cpp Loot/*.h)
file(GLOB_RECURSE sources_Mails Mails/*.cpp Mails/*.h)
file(GLOB_RECURSE sources_Movement Movement/*.cpp Movement/*.h)
file(GLOB_RECURSE sources_OutdoorPvP OutdoorPvP/*.cpp OutdoorPvP/*.h)
file(GLOB_RECURSE sources_Pools Pools/*.cpp Pools/*.h)
file(GLOB_RECURSE sources_Quests Quests/*.cpp Quests/*.h)
file(GLOB_RECURSE sources_Reputation Reputation/*.cpp Reputation/*.h)
file(GLOB_RECURSE sources_Scripting Scripting/*.cpp Scripting/*.h)
file(GLOB_RECURSE sources_Skills Skills/*.cpp Skills/*.h)
file(GLOB_RECURSE sources_Spells Spells/*.cpp Spells/*.h)
file(GLOB_RECURSE sources_Texts Texts/*.cpp Texts/*.h)
file(GLOB_RECURSE sources_Tickets Tickets/*.cpp Tickets/*.h)
file(GLOB_RECURSE sources_Weather Weather/*.cpp Weather/*.h)
file(GLOB_RECURSE sources_World World/*.cpp World/*.h)

source_group(CMake FILES CMakeLists.txt)
source_group(Achievements FILES ${sources_Achievements})
source_group(Addons FILES ${sources_Addons})
source_group(AuctionHouse FILES ${sources_AuctionHouse})
source_group(AuctionHouseBot FILES ${sources_AuctionHouseBot})
source_group(Battlegrounds FILES ${sources_Battlegrounds})
source_group(Calendar FILES ${sources_Calendar})
source_group(Chat FILES ${sources_Chat})
source_group(Combat FILES ${sources_Combat})
source_group(DungeonFinding FILES ${sources_DungeonFinding})
source_group(PrecompiledHeaders FILES ${sources_PrecompiledHeaders})
source_group(Entities FILES ${sources_Entities})
source_group(Events FILES ${sources_Events})
source_group(Grids FILES ${sources_Grids})
source_group(Groups FILES ${sources_Groups})
source_group(Guilds FILES ${sources_Guilds})
source_group(Instances FILES ${sources_Instances})
source_group(Loot FILES ${sources_Loot})
source_group(Mails FILES ${sources_Mails})
source_group(Movement FILES ${sources_Movement})
source_group(OutdoorPvP FILES ${sources_OutdoorPvP})
source_group(Pools FILES ${sources_Pools})
source_group(Quests FILES ${sources_Quests})
source_group(Reputation FILES ${sources_Reputation})
source_group(Scripting FILES ${sources_Scripting})
source_group(Skills FILES ${sources_Skills})
source_group(Spells FILES ${sources_Spells})
source_group(Texts FILES ${sources_Texts})
source_group(Tickets FILES ${sources_Tickets})
source_group(Weather FILES ${sources_Weather})
source_group(World FILES ${sources_World})

# Create game-libary

if( USE_COREPCH AND MSVC )
  set(game_STAT_SRCS
    PrecompiledHeaders/gamePCH.cpp
  )
endif()

set(game_STAT_SRCS
  ${game_STAT_SRCS}
  PrecompiledHeaders/gamePCH.h
  ${sources_Achievements}
  ${sources_Addons}
  ${sources_AuctionHouse}
  ${sources_AuctionHouseBot}
  ${sources_Battlegrounds}
  ${sources_Calendar}
  ${sources_Chat}
  ${sources_Combat}
  ${sources_DungeonFinding}
  ${sources_Entities}
  ${sources_Events}
  ${sources_Grids}
  ${sources_Groups}
  ${sources_Guilds}
  ${sources_Instances}
  ${sources_Loot}
  ${sources_Mails}
  ${sources_Movement}
  ${sources_OutdoorPvP}
  ${sources_Pools}
  ${sources_Quests}
  ${sources_Reputation}
  ${sources_Scripting}
  ${sources_Skills}
  ${sources_Spells}
  ${sources_Texts}
  ${sources_Tickets}
  ${sources_Weather}
  ${sources_World}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/mersennetwister
  ${CMAKE_SOURCE_DIR}/dep/SFMT
  ${CMAKE_SOURCE_DIR}/dep/zlib
  ${CMAKE_SOURCE_DIR}/src/collision
  ${CMAKE_SOURCE_DIR}/src/collision/Management
  ${CMAKE_SOURCE_DIR}/src/shared
  ${CMAKE_SOURCE_DIR}/src/shared/DataStores
  ${CMAKE_SOURCE_DIR}/src/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/shared/Cryptography/Authentication
  ${CMAKE_SOURCE_DIR}/src/shared/Database
  ${CMAKE_SOURCE_DIR}/src/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/shared/Dynamic/CountedReference
  ${CMAKE_SOURCE_DIR}/src/shared/Dynamic/LinkedReference
  ${CMAKE_SOURCE_DIR}/src/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/shared/Policies
  ${CMAKE_SOURCE_DIR}/src/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/logic
  ${CMAKE_SOURCE_DIR}/src/logic/AI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/CoreAI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/EventAI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/ScriptedAI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/SmartScripts
  ${CMAKE_SOURCE_DIR}/src/logic/Accounts
  ${CMAKE_SOURCE_DIR}/src/logic/Conditions
  ${CMAKE_SOURCE_DIR}/src/logic/DataStores
  ${CMAKE_SOURCE_DIR}/src/logic/Globals
  ${CMAKE_SOURCE_DIR}/src/logic/Handlers
  ${CMAKE_SOURCE_DIR}/src/logic/Maps
  ${CMAKE_SOURCE_DIR}/src/logic/Miscellaneous
  ${CMAKE_SOURCE_DIR}/src/logic/Protocol
  ${CMAKE_SOURCE_DIR}/src/logic/Tools  
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Achievements
  ${CMAKE_CURRENT_SOURCE_DIR}/Addons
  ${CMAKE_CURRENT_SOURCE_DIR}/AuctionHouse
  ${CMAKE_CURRENT_SOURCE_DIR}/AuctionHouse/AuctionHouseBot
  ${CMAKE_CURRENT_SOURCE_DIR}/Battlegrounds
  ${CMAKE_CURRENT_SOURCE_DIR}/Battlegrounds/Zones
  ${CMAKE_CURRENT_SOURCE_DIR}/Calendar
  ${CMAKE_CURRENT_SOURCE_DIR}/Chat
  ${CMAKE_CURRENT_SOURCE_DIR}/Chat/Channels
  ${CMAKE_CURRENT_SOURCE_DIR}/Chat/Commands
  ${CMAKE_CURRENT_SOURCE_DIR}/Combat
  ${CMAKE_CURRENT_SOURCE_DIR}/DungeonFinding
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Creature
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Corpse
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/DynamicObject
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/GameObject
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Item
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Item/Container
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Object
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Object/Updates
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Pet
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Player
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Player/ClassPlayer
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Totem
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Unit
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Vehicle
  ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Transport
  ${CMAKE_CURRENT_SOURCE_DIR}/Events
  ${CMAKE_CURRENT_SOURCE_DIR}/Grids/Cells
  ${CMAKE_CURRENT_SOURCE_DIR}/Grids/Notifiers
  ${CMAKE_CURRENT_SOURCE_DIR}/Grids
  ${CMAKE_CURRENT_SOURCE_DIR}/Groups
  ${CMAKE_CURRENT_SOURCE_DIR}/Guilds
  ${CMAKE_CURRENT_SOURCE_DIR}/Instances
  ${CMAKE_CURRENT_SOURCE_DIR}/Loot
  ${CMAKE_CURRENT_SOURCE_DIR}/Mails
  ${CMAKE_CURRENT_SOURCE_DIR}/Movement
  ${CMAKE_CURRENT_SOURCE_DIR}/Movement/MovementGenerators
  ${CMAKE_CURRENT_SOURCE_DIR}/Movement/Waypoints
  ${CMAKE_CURRENT_SOURCE_DIR}/OutdoorPvP
  ${CMAKE_CURRENT_SOURCE_DIR}/OutdoorPvP/Zones
  ${CMAKE_CURRENT_SOURCE_DIR}/Pools
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
  ${CMAKE_CURRENT_SOURCE_DIR}/Quests
  ${CMAKE_CURRENT_SOURCE_DIR}/Reputation
  ${CMAKE_CURRENT_SOURCE_DIR}/Scripting
  ${CMAKE_CURRENT_SOURCE_DIR}/Skills
  ${CMAKE_CURRENT_SOURCE_DIR}/Spells
  ${CMAKE_CURRENT_SOURCE_DIR}/Spells/Auras
  ${CMAKE_CURRENT_SOURCE_DIR}/Texts
  ${CMAKE_CURRENT_SOURCE_DIR}/Tickets
  ${CMAKE_CURRENT_SOURCE_DIR}/Weather
  ${CMAKE_CURRENT_SOURCE_DIR}/World
  ${CMAKE_SOURCE_DIR}/src/logic/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/scripts/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/scripts/OutdoorPvP
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

add_library(game STATIC ${game_STAT_SRCS})

add_dependencies(game revision.h)

# Generate precompiled header
if( USE_COREPCH )
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_precompiled_header(game ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/gamePCH.h)
  elseif(MSVC)
    add_native_precompiled_header(game ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/gamePCH 0)
  endif()
endif()
