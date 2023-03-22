################################
# arcade_opengl LIB
################################

add_library(arcade_opengl SHARED)

set(OpenGL_GL_PREFERENCE GLVND)

# Find OpenGL and GLU libraries
find_package(OpenGL REQUIRED)
if(NOT OpenGL_FOUND)
    message(FATAL_ERROR "OpenGL not found. Please install OpenGL and try again.")
endif()

# Add the source files for the library
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(arcade_opengl
    PRIVATE
        ${SRC_FILES}
)

# Add the include directories for the library
target_include_directories(arcade_opengl
    PUBLIC
        include
        ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(arcade_opengl
    PRIVATE
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
)

# Set the output directory for the library
set_target_properties(arcade_opengl
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME arcade_opengl
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
