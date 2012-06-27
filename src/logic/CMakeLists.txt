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

file(GLOB_RECURSE sources_Accounts Accounts/*.cpp Accounts/*.h)
file(GLOB_RECURSE sources_AI AI/*.cpp AI/*.h)
file(GLOB_RECURSE sources_Conditions Conditions/*.cpp Conditions/*.h)
file(GLOB_RECURSE sources_DataStores DataStores/*.cpp DataStores/*.h)
file(GLOB_RECURSE sources_Globals Globals/*.cpp Globals/*.h)
file(GLOB_RECURSE sources_Handlers Handlers/*.cpp Handlers/*.h)
file(GLOB_RECURSE sources_Maps Maps/*.cpp Maps/*.h)
file(GLOB_RECURSE sources_Miscellaneous Miscellaneous/*.cpp Miscellaneous/*.h)
file(GLOB_RECURSE sources_Protocol Protocol/*.cpp Protocol/*.h)
file(GLOB_RECURSE sources_Tools Tools/*.cpp Tools/*.h)


source_group(CMake FILES CMakeLists.txt)
source_group(Accounts FILES ${sources_Accounts})
source_group(AI FILES ${sources_AI})
source_group(AI\\ScriptedAI FILES ${sources_AI})
source_group(Conditions FILES ${sources_Conditions})
source_group(DataStores FILES ${sources_DataStores})
source_group(Globals FILES ${sources_Globals})
source_group(Handlers FILES ${sources_Handlers})
source_group(Maps FILES ${sources_Maps})
source_group(Miscellaneous FILES ${sources_Miscellaneous})
source_group(PrecompiledHeaders FILES ${sources_PrecompiledHeaders})
source_group(Protocol FILES ${sources_Protocol})
source_group(Tools FILES ${sources_Tools})

# Create logic-libary

if( USE_COREPCH AND MSVC )
  set(logic_STAT_SRCS
    PrecompiledHeaders/logicPCH.cpp
  )
endif()

set(logic_STAT_SRCS
  ${logic_STAT_SRCS}
  PrecompiledHeaders/logicPCH.h
  ${sources_Accounts}
  ${sources_AI}
  ${sources_Conditions}
  ${sources_DataStores}
  ${sources_Globals}
  ${sources_Handlers}
  ${sources_Maps}
  ${sources_Miscellaneous}
  ${sources_Protocol}
  ${sources_Tools}  
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/mersennetwister
  ${CMAKE_SOURCE_DIR}/dep/SFMT
  ${CMAKE_SOURCE_DIR}/dep/zlib
  ${CMAKE_SOURCE_DIR}/src/collision
  ${CMAKE_SOURCE_DIR}/src/collision/Management
  ${CMAKE_SOURCE_DIR}/src/shared
  ${CMAKE_SOURCE_DIR}/src/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/shared/Cryptography/Authentication
  ${CMAKE_SOURCE_DIR}/src/shared/Database
  ${CMAKE_SOURCE_DIR}/src/shared/DataStores
  ${CMAKE_SOURCE_DIR}/src/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/shared/Dynamic/CountedReference
  ${CMAKE_SOURCE_DIR}/src/shared/Dynamic/LinkedReference
  ${CMAKE_SOURCE_DIR}/src/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/shared/Policies
  ${CMAKE_SOURCE_DIR}/src/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/game/Achievements
  ${CMAKE_SOURCE_DIR}/src/game/Addons
  ${CMAKE_SOURCE_DIR}/src/game/AuctionHouse
  ${CMAKE_SOURCE_DIR}/src/game/AuctionHouse/AuctionHouseBot
  ${CMAKE_SOURCE_DIR}/src/game/Battlegrounds
  ${CMAKE_SOURCE_DIR}/src/game/Battlegrounds/Zones
  ${CMAKE_SOURCE_DIR}/src/game/Calendar
  ${CMAKE_SOURCE_DIR}/src/game/Chat
  ${CMAKE_SOURCE_DIR}/src/game/Chat/Channels
  ${CMAKE_SOURCE_DIR}/src/game/Chat/Commands
  ${CMAKE_SOURCE_DIR}/src/game/Combat
  ${CMAKE_SOURCE_DIR}/src/game/DungeonFinding
  ${CMAKE_SOURCE_DIR}/src/game/Entities
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Creature
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Corpse
  ${CMAKE_SOURCE_DIR}/src/game/Entities/DynamicObject
  ${CMAKE_SOURCE_DIR}/src/game/Entities/GameObject
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Item
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Item/Container
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Object
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Object/Updates
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Pet
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Player
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Player/ClassPlayer
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Totem
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Unit
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Vehicle
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Transport
  ${CMAKE_SOURCE_DIR}/src/game/Events
  ${CMAKE_SOURCE_DIR}/src/game/Grids/Cells
  ${CMAKE_SOURCE_DIR}/src/game/Grids/Notifiers
  ${CMAKE_SOURCE_DIR}/src/game/Grids
  ${CMAKE_SOURCE_DIR}/src/game/Groups
  ${CMAKE_SOURCE_DIR}/src/game/Guilds
  ${CMAKE_SOURCE_DIR}/src/game/Instances
  ${CMAKE_SOURCE_DIR}/src/game/Loot
  ${CMAKE_SOURCE_DIR}/src/game/Mails
  ${CMAKE_SOURCE_DIR}/src/game/Movement
  ${CMAKE_SOURCE_DIR}/src/game/Movement/MovementGenerators
  ${CMAKE_SOURCE_DIR}/src/game/Movement/Waypoints
  ${CMAKE_SOURCE_DIR}/src/game/OutdoorPvP
  ${CMAKE_SOURCE_DIR}/src/game/OutdoorPvP/Zones
  ${CMAKE_SOURCE_DIR}/src/game/Pools
  ${CMAKE_SOURCE_DIR}/src/game/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/game/Quests
  ${CMAKE_SOURCE_DIR}/src/game/Reputation
  ${CMAKE_SOURCE_DIR}/src/game/Scripting
  ${CMAKE_SOURCE_DIR}/src/game/Skills
  ${CMAKE_SOURCE_DIR}/src/game/Spells
  ${CMAKE_SOURCE_DIR}/src/game/Spells/Auras
  ${CMAKE_SOURCE_DIR}/src/game/Texts
  ${CMAKE_SOURCE_DIR}/src/game/Tickets
  ${CMAKE_SOURCE_DIR}/src/game/Weather
  ${CMAKE_SOURCE_DIR}/src/game/World
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
  ${CMAKE_CURRENT_SOURCE_DIR}/Accounts
  ${CMAKE_CURRENT_SOURCE_DIR}/AI
  ${CMAKE_CURRENT_SOURCE_DIR}/AI/CoreAI
  ${CMAKE_CURRENT_SOURCE_DIR}/AI/EventAI
  ${CMAKE_CURRENT_SOURCE_DIR}/AI/ScriptedAI
  ${CMAKE_CURRENT_SOURCE_DIR}/AI/SmartScripts
  ${CMAKE_CURRENT_SOURCE_DIR}/Conditions 
  ${CMAKE_CURRENT_SOURCE_DIR}/DataStores
  ${CMAKE_CURRENT_SOURCE_DIR}/Globals
  ${CMAKE_CURRENT_SOURCE_DIR}/Handlers
  ${CMAKE_CURRENT_SOURCE_DIR}/Maps
  ${CMAKE_CURRENT_SOURCE_DIR}/Miscellaneous
  ${CMAKE_CURRENT_SOURCE_DIR}/Protocol
  ${CMAKE_CURRENT_SOURCE_DIR}/Tools  
  ${CMAKE_SOURCE_DIR}/src/game/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/scripts/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/scripts/OutdoorPvP
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

add_library(logic STATIC ${logic_STAT_SRCS})

add_dependencies(logic revision.h)

# Generate precompiled header
if( USE_COREPCH )
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_precompiled_header(logic ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/logicPCH.h)
  elseif(MSVC)
    add_native_precompiled_header(logic ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/logicPCH 0)
  endif()
endif()
