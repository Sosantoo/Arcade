################################
# arcade_sdl2 LIB
################################

add_library(arcade_sdl2 SHARED)

# Add the source files for the library
target_sources(arcade_sdl2
    PRIVATE
        src/sdl2.cpp
)

# Add the include directories for the library
target_include_directories(arcade_sdl2
    PUBLIC
        include
)

# Set the output directory for the library
set_target_properties(arcade_sdl2
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME arcade_sdl2
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
