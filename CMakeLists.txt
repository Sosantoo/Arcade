#######################################
#                                     #
#   arcade Epitech                    #
#                                     #
# only for cmake --version >= 3.5.1   #
#######################################

cmake_minimum_required(VERSION 3.5.1)

project(arcade-cmake)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -fno-gnu-unique)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

################################
# Core src
################################

include_directories(./Core/include)

file(GLOB_RECURSE SRC_FILES_CORE ${PROJECT_SOURCE_DIR}/Core/src/*.cpp)

set(EXEC arcade)

add_executable(${EXEC} ${SRC_FILES_CORE})

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
add_subdirectory(Games/Menu)

add_custom_target(games
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target nibbler PacMan
    COMMENT "Build the games libraries"
    VERBATIM
)


################################
# Graphicals
################################

add_subdirectory(Graphicals/SDL2)
add_subdirectory(Graphicals/nCurses)
add_subdirectory(Graphicals/OpenGL)

add_custom_target(graphicals
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target nCurses SDL2
    COMMENT "Build the graphicals libraries"
    VERBATIM
)


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
