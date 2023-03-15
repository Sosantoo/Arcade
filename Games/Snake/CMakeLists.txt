################################
# arcade_snake LIB
################################

add_library(arcade_snake SHARED)

# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(arcade_snake
    PRIVATE
        ${SRC_FILES}
)

# Add the include directories for the library
target_include_directories(arcade_snake
    PUBLIC
        include
)

# Set the output directory for the library
set_target_properties(arcade_snake
    PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME arcade_snake
)
