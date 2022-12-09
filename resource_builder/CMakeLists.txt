set(resource_builder_CODE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Properties for configured header
set(resource_builder_DATA_OUTPUT ${RESOURCE_PACK_OUTPUT})
configure_file(${resource_builder_CODE_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h)

set(resource_builder_SOURCES
    main.cc)

list(TRANSFORM resource_builder_SOURCES
    PREPEND ${resource_builder_CODE_SOURCE_DIR}/)

add_executable(${resource_builder_EXECUTABLE} ${resource_builder_SOURCES})

target_include_directories(${resource_builder_EXECUTABLE}
    PRIVATE ${SHARED_SOURCE_DIR}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

if(DEFINED ENGINE_LIBRARIES)
    target_link_libraries(${resource_builder_EXECUTABLE} ${ENGINE_LIBRARIES})
endif()
