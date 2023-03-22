################################
# arcade_Nibbler LIB
################################

add_library(arcade_nibbler SHARED)

# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_FILES_INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../Interface/src/*.cpp)

target_sources(arcade_nibbler
    PRIVATE
        ${SRC_FILES}
        ${SRC_FILES_INTERFACE}
)

# Add the include directories for the library
target_include_directories(arcade_nibbler
    PUBLIC
        include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Interface/include
)

# target_link_libraries(arcade_nibbler AGameLib)

# Set the output directory for the library
set_target_properties(arcade_nibbler
    PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME arcade_nibbler
)
