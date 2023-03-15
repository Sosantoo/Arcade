################################
# arcade_menu LIB
################################

add_library(arcade_menu SHARED)

# Add the source files for the library
# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(arcade_menu
    PRIVATE
        ${SRC_FILES}
)

# Add the include directories for the library
target_include_directories(arcade_menu
    PUBLIC
        include
)

# Set the output directory for the library
set_target_properties(arcade_menu
    PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME arcade_menu
)
