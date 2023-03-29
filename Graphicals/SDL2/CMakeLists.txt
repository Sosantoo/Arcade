################################
# arcade_sdl2 LIB
################################

add_library(arcade_sdl2 SHARED)

# Add SDL2 libraries
find_package(SDL2 REQUIRED)
if (NOT SDL2_FOUND)
    message(FATAL_ERROR "SDL2 not found. Please install SDL2 and try again.")
endif()

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
)
target_compile_options(arcade_sdl2 PRIVATE -ggdb3)

target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES})

# Set the output directory for the library
set_target_properties(arcade_sdl2
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME arcade_sdl2
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
