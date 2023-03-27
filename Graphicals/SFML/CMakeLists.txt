################################
# arcade_sfml LIB
################################

add_library(arcade_sfml SHARED)

# Find SFML libraries
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
# if (NOT SFML_FOUND)
#     message(FATAL_ERROR "SMFML not found. Please install SFML and try again.")
# endif()

# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(arcade_sfml
    PRIVATE
        ${SRC_FILES}
)

# Add the include directories for the library
target_include_directories(arcade_sfml
    PUBLIC
        include
        ${SFML_INCLUDE_DIRS}
)

target_link_libraries(arcade_sfml
    PRIVATE
        ${SFML_LIBRARIES}
        sfml-graphics
        sfml-audio
)

# Set the output directory for the library
set_target_properties(arcade_sfml
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME arcade_sfml
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)