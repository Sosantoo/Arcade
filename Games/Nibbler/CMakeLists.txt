################################
# arcade_Nibbler LIB
################################

add_library(arcade_nibbler SHARED)

# Add the source files for the library
target_sources(arcade_nibbler
    PRIVATE
        src/nibbler.cpp
)

# Add the include directories for the library
target_include_directories(arcade_nibbler
    PUBLIC
        include
)

# Set the output directory for the library
set_target_properties(arcade_nibbler
    PROPERTIES
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME arcade_nibbler
)
