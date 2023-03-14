################################
# arcade_PacMan LIB
################################

add_library(arcade_pacman SHARED)

# Add the source files for the library
target_sources(arcade_pacman
    PRIVATE
        src/pacman.cpp
)

# Add the include directories for the library
target_include_directories(arcade_pacman
    PUBLIC
        include
)

# Set the output directory for the library
set_target_properties(arcade_pacman
    PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME arcade_pacman
)
