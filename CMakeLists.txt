# Metadata
cmake_minimum_required(VERSION 3.10)
project(vb6-discord-rich-presence)

# TODO: This isn't actually necessary yet, but w/e.
# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
    discord-rpc
    GIT_REPOSITORY https://github.com/discord/discord-rpc.git

    # NOTE: Targeting a SHA just in case someone decides to break
    # a several-years-old-deprecated library.
    GIT_TAG        963aa9f3e5ce81a4682c6ca3d136cddda614db33
)

FetchContent_MakeAvailable(discord-rpc)

set(MAIN_TARGET ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/code/*.cpp")

add_library(${MAIN_TARGET} SHARED ${SOURCES})
set_target_properties(${MAIN_TARGET} PROPERTIES LINK_FLAGS "/DEF:../exports.def")
target_link_libraries(${MAIN_TARGET} PRIVATE discord-rpc)
target_include_directories(${MAIN_TARGET} PRIVATE ${discord-rpc_SOURCE_DIR}/include)
