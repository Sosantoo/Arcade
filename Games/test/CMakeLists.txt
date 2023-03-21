################################
# testGame LIB
################################

add_library(testGame SHARED)

# Add the source files for the library
# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(testGame
    PRIVATE
        ${SRC_FILES}
)

# Add the include directories for the library
target_include_directories(testGame
    PUBLIC
        include
)

# Set the output directory for the library
set_target_properties(testGame
    PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME testGame
)
