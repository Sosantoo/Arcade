#######################################
#                                     #
#   arcade Epitech                    #
#                                     #
# only for cmake --version >= 3.5.1   #
#######################################

cmake_minimum_required(VERSION 3.5.1)

project(arcade-cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

# #set output directory
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
#get assets
file(COPY ./assets DESTINATION ${CMAKE_BINARY_DIR})

################################
# Core src
################################

include_directories(./Core/include)

file(GLOB_RECURSE SRC_FILES_CORE ${PROJECT_SOURCE_DIR}/Core/src/*.cpp)

set(EXEC arcade)

add_executable(${EXEC} ${SRC_FILES_CORE})
target_compile_options(${EXEC} PRIVATE -Wall -Wextra -fno-gnu-unique -ggdb3)

add_custom_target(core
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target arcade
    COMMENT "Build the core executable only"
    VERBATIM
)

################################
# Games
################################

add_subdirectory(Games/Nibbler)
add_subdirectory(Games/Snake)

add_custom_target(games
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target arcade_nibbler arcade_snake arcade_menu
    DEPENDS arcade_nibbler arcade_snake arcade_menu
    COMMENT "Build the games libraries"
    VERBATIM
)

# Set output directory for game libraries
set_target_properties(arcade_nibbler PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set_target_properties(arcade_snake PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

################################
# Graphicals
################################

add_subdirectory(Graphicals/SDL2)
add_subdirectory(Graphicals/nCurses)
add_subdirectory(Graphicals/SFML)

add_custom_target(graphicals
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target arcade_sdl2 arcade_ncurses arcade_sfml
    DEPENDS arcade_nibbler arcade_snake arcade_menu
    COMMENT "Build the graphicals libraries"
    VERBATIM
)

# # Set output directory for graphical libraries
set_target_properties(arcade_sdl2 PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set_target_properties(arcade_ncurses PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set_target_properties(arcade_sfml PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

################################
# Menus
################################
add_subdirectory(Menu)

set_target_properties(arcade_menu PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

################################
# Tests
################################

find_package(GTest QUIET)

if(GTEST_FOUND)
    list(FILTER SRC_FILES_CORE EXCLUDE REGEX ".*main.cpp$")

    file(GLOB_RECURSE SRC_FILES_CORE_TESTS ${PROJECT_SOURCE_DIR}/Tests/src/*.cpp)

    add_executable(arcadeTEST ${SRC_FILES_CORE_TESTS} ${SRC_FILES_CORE})

    target_link_libraries(arcadeTEST PRIVATE gtest)

    add_custom_target(run_tests
      COMMAND ${CMAKE_CTEST_COMMAND}
      DEPENDS arcadeTEST
      COMMAND ./arcadeTEST
    )

    set_target_properties(arcadeTEST PROPERTIES EXCLUDE_FROM_ALL TRUE)

endif()
