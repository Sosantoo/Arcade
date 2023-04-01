################################
# arcade_snake LIB
################################

add_library(arcade_snake SHARED)

# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_FILES_INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../Interface/src/*.cpp)

target_sources(arcade_snake
    PRIVATE
        ${SRC_FILES}
        ${SRC_FILES_INTERFACE}
)

# Add the include directories for the library
target_include_directories(arcade_snake
    PUBLIC
        include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Interface/include
)

# target_link_libraries(arcade_snake AGameLib)
target_compile_options(arcade_snake PRIVATE -Wall -Wextra -fno-gnu-unique -ggdb3)

# Set the output directory for the library
set_target_properties(arcade_snake
    PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME arcade_snake
)
