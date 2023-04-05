################################
# arcade_nCurses LIB
################################

add_library(arcade_ncurses SHARED)

find_package(Curses REQUIRED)
if(NOT CURSES_FOUND)
    message(FATAL_ERROR "Curses not found. Please install Curses and try again.")
endif()

# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(arcade_ncurses
    PRIVATE
        ${SRC_FILES}
)

# Add the include directories for the library
target_include_directories(arcade_ncurses
    PUBLIC
        include
        ${CURSES_INCLUDE_DIR}
)

target_compile_options(arcade_ncurses PRIVATE -Wall -Wextra -fno-gnu-unique -ggdb3)

target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})

# Set the output directory for the library
set_target_properties(arcade_ncurses
    PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME arcade_ncurses
)