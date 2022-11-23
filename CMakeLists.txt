cmake_minimum_required(VERSION 3.10)

project(bullet_hell VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_package(X11)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    find_package(Carbon REQUIRED)
    find_package(GLUT REQUIRED)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmacosx-version-min=10.15")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

set(SHARED_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shared)

set(RESOURCE_PACK_FILENAME resources.dat)

set(SYSTEM_SHARED_DATA_DIR ${CMAKE_INSTALL_PREFIX}/share)

set(RESOURCE_PACK_OUTPUT
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${RESOURCE_PACK_FILENAME})

set(bullet_hell_EXECUTABLE bullet-hell)
set(resource_builder_EXECUTABLE resource-builder)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(OLC_LIBRARIES
        GL
        png
        pthread
        stdc++fs
        X11)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(OLC_LIBRARIES
        -framework Carbon
        -framework GLUT
        -framework OpenGL
        png
        stdc++fs)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(OLC_LIBRARIES
        dwmapi
        gdi32
        gdiplus
        opengl32
        Shlwapi
        stdc++fs
        user32)
endif()

add_subdirectory(game)
add_subdirectory(resource_builder)

add_custom_command(
    OUTPUT ${RESOURCE_PACK_OUTPUT}
    DEPENDS ${resource_builder_EXECUTABLE}
    COMMAND ${resource_builder_EXECUTABLE})

add_custom_target(resource_pack DEPENDS ${RESOURCE_PACK_OUTPUT})

add_dependencies(${bullet_hell_EXECUTABLE} resource_pack)

install(TARGETS ${bullet_hell_EXECUTABLE}
        RUNTIME
        DESTINATION bin)

install(FILES ${RESOURCE_PACK_OUTPUT}
    DESTINATION ${SYSTEM_SHARED_DATA_DIR})

if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND
            ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake)
endif()
