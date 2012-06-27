# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_CommandLine CommandLine/*.cpp CommandLine/*.h)
file(GLOB_RECURSE sources_RemoteAccess RemoteAccess/*.cpp RemoteAccess/*.h)
file(GLOB_RECURSE sources_TCSoap TCSoap/*.cpp TCSoap/*.h)
file(GLOB_RECURSE sources_WorldThread WorldThread/*.cpp WorldThread/*.h)
file(GLOB sources_localdir *.cpp *.h)

if( USE_COREPCH )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

if ( USE_COREPCH AND MSVC )
  set(worldserver_SRCS
    PrecompiledHeaders/worldPCH.cpp
    PrecompiledHeaders/worldPCH.h
  )
endif()

set(worldserver_SRCS
  ${worldserver_SRCS}
  ${sources_CommandLine}
  ${sources_RemoteAccess}
  ${sources_TCSoap}
  ${sources_WorldThread}
  ${sources_localdir}
)

if( WIN32 )
  set(worldserver_SRCS
    ${worldserver_SRCS}
    ${sources_Debugging}
    worldserver.rc
  )
endif()

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/gsoap
  ${CMAKE_SOURCE_DIR}/dep/SFMT
  ${CMAKE_SOURCE_DIR}/dep/mersennetwister
  ${CMAKE_SOURCE_DIR}/src/collision
  ${CMAKE_SOURCE_DIR}/src/collision/Management
  ${CMAKE_SOURCE_DIR}/src/shared
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
  ${CMAKE_SOURCE_DIR}/src/shared/DataStores
  ${CMAKE_SOURCE_DIR}/src/game
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
  ${CMAKE_SOURCE_DIR}/src/game/Pools
  ${CMAKE_SOURCE_DIR}/src/game/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/game/Quests
  ${CMAKE_SOURCE_DIR}/src/game/Reputation
  ${CMAKE_SOURCE_DIR}/src/game/Scripting
  ${CMAKE_SOURCE_DIR}/src/game/Skills
  ${CMAKE_SOURCE_DIR}/src/game/Spells
  ${CMAKE_SOURCE_DIR}/src/game/Spells/Auras
  ${CMAKE_SOURCE_DIR}/src/game/Weather
  ${CMAKE_SOURCE_DIR}/src/game/World
  ${CMAKE_SOURCE_DIR}/src/authserver/Server
  ${CMAKE_SOURCE_DIR}/src/logic/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/logic/Accounts
  ${CMAKE_SOURCE_DIR}/src/logic/AI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/CoreAI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/EventAI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/ScriptedAI
  ${CMAKE_SOURCE_DIR}/src/logic/AI/SmartScripts
  ${CMAKE_SOURCE_DIR}/src/logic/Conditions
  ${CMAKE_SOURCE_DIR}/src/logic/DataStores
  ${CMAKE_SOURCE_DIR}/src/logic/Globals
  ${CMAKE_SOURCE_DIR}/src/logic/Protocol
  ${CMAKE_SOURCE_DIR}/src/logic/Handlers
  ${CMAKE_SOURCE_DIR}/src/logic/Maps
  ${CMAKE_SOURCE_DIR}/src/logic/Miscellaneous
  ${CMAKE_SOURCE_DIR}/src/logic/Tools
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/CommandLine
  ${CMAKE_CURRENT_SOURCE_DIR}/RemoteAccess
  ${CMAKE_CURRENT_SOURCE_DIR}/TCSoap
  ${CMAKE_CURRENT_SOURCE_DIR}/WorldThread
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

set(worldserver_LINK_FLAGS "")

add_executable(worldserver ${worldserver_SRCS})

if( NOT WIN32 )
  add_definitions(-D_ARKCORE_CORE_CONFIG='"${CONF_DIR}/worldserver.conf"')
endif()

add_dependencies(worldserver revision.h)

if( UNIX )
  set(worldserver_LINK_FLAGS "-pthread -lncurses ${worldserver_LINK_FLAGS}")
endif()

set_target_properties(worldserver PROPERTIES LINK_FLAGS "${worldserver_LINK_FLAGS}")

target_link_libraries(worldserver
  game
  logic
  shared
  scripts
  collision
  g3dlib
  gsoap
  ${JEMALLOC_LIBRARY}
  ${READLINE_LIBRARY}
  ${TERMCAP_LIBRARY}
  ${ACE_LIBRARY}
  ${MYSQL_LIBRARY}
  ${OPENSSL_LIBRARIES}
  ${OPENSSL_EXTRA_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${OSX_LIBS}
)

if( WIN32 )
  add_custom_command(TARGET worldserver
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/worldserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
  )
endif()

if( UNIX )
  install(TARGETS worldserver DESTINATION bin)
  install(FILES worldserver.conf.dist DESTINATION etc)
elseif( WIN32 )
  install(TARGETS worldserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
  install(FILES worldserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()

# Generate precompiled header
if( USE_COREPCH )
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_precompiled_header(worldserver ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/worldPCH.h)
  elseif(MSVC)
    add_native_precompiled_header(worldserver ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/worldPCH)
  endif()
endif()

