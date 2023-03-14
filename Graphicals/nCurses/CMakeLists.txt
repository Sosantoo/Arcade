################################
# arcade_nCurses LIB
################################

add_library(arcade_ncurses SHARED)

# Add the source files for the library
target_sources(arcade_ncurses
    PRIVATE
        src/nCurses.cpp
)

# Add the include directories for the library
target_include_directories(arcade_ncurses
    PUBLIC
        include
)

# Set the output directory for the library
set_target_properties(arcade_ncurses
    PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME arcade_ncurses
)