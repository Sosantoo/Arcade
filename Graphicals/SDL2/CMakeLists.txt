################################
# arcade_sdl2 LIB
################################

find_package(PkgConfig)

add_library(arcade_sdl2 SHARED)

# Add SDL2 libraries
pkg_check_modules( SDL2 REQUIRED sdl2 )
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(arcade_sdl2
    PRIVATE
        ${SRC_FILES}
)

# Add the include directories for the library
target_include_directories(arcade_sdl2
    PUBLIC
        include
        ${SDL2_INCLUDE_DIRS}
        ${SDL_TTF_INCLUDE_DIRS}
)

target_compile_options(arcade_sdl2 PRIVATE -Wall -Wextra -fno-gnu-unique -ggdb3)

target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARIES})

# Set the output directory for the library
set_target_properties(arcade_sdl2
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME arcade_sdl2
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
