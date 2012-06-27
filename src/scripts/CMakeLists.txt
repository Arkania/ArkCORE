# Copyright (C) 2008 - 2012 ArkCORE <http://www.arkania.net/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE scripts_easternkingdoms EasternKingdoms/*.cpp EasternKingdoms/*.h)
file(GLOB_RECURSE scripts_kalimdor Kalimdor/*.cpp Kalimdor/*.h)
file(GLOB_RECURSE scripts_northrend Northrend/*.cpp Northrend/*.h)
file(GLOB_RECURSE scripts_maelstrom Maelstrom/*.cpp Maelstrom/*.h)
file(GLOB_RECURSE scripts_outland Outland/*.cpp Outland/*.h)
file(GLOB_RECURSE scripts_world World/*.cpp World/*.h)
file(GLOB_RECURSE scripts_spells Spells/*.cpp Spells/*.h)
file(GLOB_RECURSE scripts_outdoorpvp OutdoorPvP/*.cpp OutdoorPvP/*.h)
file(GLOB_RECURSE scripts_commands Commands/*.cpp Commands/*.h)
file(GLOB_RECURSE scripts_custom Custom/*.cpp Custom/*.h)
file(GLOB_RECURSE scripts_examples Examples/*.cpp Examples/*.h)

source_group(EasternKingdoms FILES ${scripts_easternkingdoms})
source_group(Kalimdor FILES ${scripts_kalimdor})
source_group(Northrend FILES ${scripts_northrend})
source_group(Maelstrom FILES ${scripts_maelstrom})
source_group(Outland FILES ${scripts_outland})
source_group(World FILES ${scripts_world})
source_group(Spells FILES ${scripts_spells})
source_group(OutdoorPvP FILES ${scripts_outdoorpvp})
source_group(Commands FILES ${scripts_commands})
source_group(Custom FILES ${scripts_custom})
source_group(Examples FILES ${scripts_examples})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

  set(scripts_STAT_SRCS
    PrecompiledHeaders/ScriptPCH.cpp
  PrecompiledHeaders/ScriptPCH.h)

message(STATUS "SCRIPT PREPARATIONS")

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_easternkingdoms}
  ${scripts_kalimdor}
  ${scripts_northrend}
  ${scripts_maelstrom}
  ${scripts_outland}
  ${scripts_world}
  ${scripts_spells}
  ${scripts_outdoorpvp}
  ${scripts_commands}
  ${scripts_custom}
  ${scripts_examples}
  ../logic/AI/ScriptedAI/ScriptedEscortAI.cpp
  ../logic/AI/ScriptedAI/ScriptedCreature.cpp
  ../logic/AI/ScriptedAI/ScriptedFollowerAI.cpp
  ../logic/AI/ScriptedAI/ScriptedSimpleAI.cpp
)

message(STATUS "SCRIPT PREPARATION COMPLETE")
message("")

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/SFMT
  ${CMAKE_SOURCE_DIR}/dep/mersennetwister
  ${CMAKE_SOURCE_DIR}/dep/zlib
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
  ${CMAKE_SOURCE_DIR}/src/collision
  ${CMAKE_SOURCE_DIR}/src/collision/Management
  ${CMAKE_SOURCE_DIR}/src/shared
  ${CMAKE_SOURCE_DIR}/src/shared/Database
  ${CMAKE_SOURCE_DIR}/src/game/Achievements
  ${CMAKE_SOURCE_DIR}/src/game/Addons
  ${CMAKE_SOURCE_DIR}/src/logic/AI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/CoreAI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/EventAI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/ScriptedAI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/SmartScripts
  ${CMAKE_SOURCE_DIR}/src/game/AuctionHouse
  ${CMAKE_SOURCE_DIR}/src/game/Battlegrounds
  ${CMAKE_SOURCE_DIR}/src/game/Battlegrounds/Zones
  ${CMAKE_SOURCE_DIR}/src/game/Calendar
  ${CMAKE_SOURCE_DIR}/src/game/Chat
  ${CMAKE_SOURCE_DIR}/src/game/Chat/Channels
  ${CMAKE_SOURCE_DIR}/src/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/game/Combat
  ${CMAKE_SOURCE_DIR}/src/game/DungeonFinding
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Corpse
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Creature
  ${CMAKE_SOURCE_DIR}/src/game/Entities/DynamicObject
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Item
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Item/Container
  ${CMAKE_SOURCE_DIR}/src/game/Entities/GameObject
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Object
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Object/Updates
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Pet
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Player
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Transport
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Unit
  ${CMAKE_SOURCE_DIR}/src/game/Entities/Vehicle
  ${CMAKE_SOURCE_DIR}/src/game/Events
  ${CMAKE_SOURCE_DIR}/src/game/Grids
  ${CMAKE_SOURCE_DIR}/src/game/Grids/Cells
  ${CMAKE_SOURCE_DIR}/src/game/Grids/Notifiers
  ${CMAKE_SOURCE_DIR}/src/game/Groups
  ${CMAKE_SOURCE_DIR}/src/game/Guilds
  ${CMAKE_SOURCE_DIR}/src/game/Instances
  ${CMAKE_SOURCE_DIR}/src/game/LookingForGroup
  ${CMAKE_SOURCE_DIR}/src/game/Loot
  ${CMAKE_SOURCE_DIR}/src/game/Mails
  ${CMAKE_SOURCE_DIR}/src/game/Movement
  ${CMAKE_SOURCE_DIR}/src/game/Movement/MovementGenerators
  ${CMAKE_SOURCE_DIR}/src/game/Movement/Waypoints
  ${CMAKE_SOURCE_DIR}/src/game/Opcodes
  ${CMAKE_SOURCE_DIR}/src/game/OutdoorPvP
  ${CMAKE_SOURCE_DIR}/src/scripts/OutdoorPvP  
  ${CMAKE_SOURCE_DIR}/src/game/Pools
  ${CMAKE_SOURCE_DIR}/src/game/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/game/Quests
  ${CMAKE_SOURCE_DIR}/src/game/Reputation
  ${CMAKE_SOURCE_DIR}/src/game/Scripting
  ${CMAKE_SOURCE_DIR}/src/game/Skills
  ${CMAKE_SOURCE_DIR}/src/game/Spells
  ${CMAKE_SOURCE_DIR}/src/game/Spells/Auras
  ${CMAKE_SOURCE_DIR}/src/game/Tickets
  ${CMAKE_SOURCE_DIR}/src/game/Texts
  ${CMAKE_SOURCE_DIR}/src/game/Weather
  ${CMAKE_SOURCE_DIR}/src/game/World
  ${CMAKE_SOURCE_DIR}/src/logic/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/logic/Accounts
  ${CMAKE_SOURCE_DIR}/src/logic/Conditions
  ${CMAKE_SOURCE_DIR}/src/logic/DataStores
  ${CMAKE_SOURCE_DIR}/src/logic/Globals
  ${CMAKE_SOURCE_DIR}/src/logic/Handlers
  ${CMAKE_SOURCE_DIR}/src/logic/Maps
  ${CMAKE_SOURCE_DIR}/src/logic/Miscellaneous
  ${CMAKE_SOURCE_DIR}/src/logic/Protocol
  ${CMAKE_SOURCE_DIR}/src/logic/Tools
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

add_library(scripts STATIC ${scripts_STAT_SRCS})

add_dependencies(scripts revision.h)

# Generate precompiled header
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_precompiled_header(scripts ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/ScriptPCH.h)
  elseif(MSVC)
    add_native_precompiled_header(scripts ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/ScriptPCH)
  endif()
