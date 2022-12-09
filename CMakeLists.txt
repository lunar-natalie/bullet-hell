cmake_minimum_required(VERSION 3.10)

project(bullet_hell VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE GLVND)

# External dependencies
find_package(OpenGL REQUIRED)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_package(X11)
    # TODO(Natalie): Support Wayland natively, if possible with GLUT.
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    find_package(Carbon REQUIRED) # TODO(Natalie): Verify dependency
    find_package(GLUT REQUIRED)
endif()

# Flags
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # TODO(Natalie): Verify minimum macOS version. This could probably be 10.14.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmacosx-version-min=10.15")
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Directory properties. Referenced in subdirectories.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(SHARED_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shared)
# The following property is used in the installation target and also referenced
# in the configured game header to locate auxiliary files at runtime.
set(SYSTEM_SHARED_DATA_DIR ${CMAKE_INSTALL_PREFIX}/share)

# Resource pack properties. Referenced in configured headers.
set(RESOURCE_PACK_FILENAME resources.dat)
set(RESOURCE_PACK_OUTPUT
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${RESOURCE_PACK_FILENAME})
set(resource_builder_ASSET_DIR ${CMAKE_SOURCE_DIR}/assets)

# Executables built by subdirectory targets
set(bullet_hell_EXECUTABLE bullet-hell)
set(resource_builder_EXECUTABLE resource-builder)

# olcPixelGameEngine libraries
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(ENGINE_LIBRARIES
        GL
        png
        pthread
        stdc++fs
        X11)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(ENGINE_LIBRARIES
        -framework Carbon # TODO(Natalie): Verify dependency
        -framework GLUT
        -framework OpenGL
        png
        stdc++fs)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    # TODO(Natalie): Verify dependencies
    set(ENGINE_LIBRARIES
        dwmapi
        gdi32
        gdiplus
        opengl32
        Shlwapi
        stdc++fs
        user32)
endif()

# Process subdirectories
add_subdirectory(game)
add_subdirectory(resource_builder)

# Command and phony target to build resource pack when required
add_custom_command(
    OUTPUT ${RESOURCE_PACK_OUTPUT}
    DEPENDS ${resource_builder_EXECUTABLE} ${resource_builder_ASSET_DIR}
    COMMAND ${resource_builder_EXECUTABLE})
add_custom_target(resource_pack
    DEPENDS ${RESOURCE_PACK_OUTPUT})
# Build pack with game executable
add_dependencies(${bullet_hell_EXECUTABLE} resource_pack)

# Add targets and files to install
install(TARGETS ${bullet_hell_EXECUTABLE}
    RUNTIME
    DESTINATION bin)
install(FILES ${RESOURCE_PACK_OUTPUT}
    DESTINATION ${SYSTEM_SHARED_DATA_DIR})

# Add uninstallation target
if(NOT TARGET uninstall)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND
            ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake)
endif()
