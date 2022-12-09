set(bullet_hell_CODE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

configure_file(${bullet_hell_CODE_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h)

set(bullet_hell_SOURCES
    bullet.cc
    draw.cc
    entity.cc
    events.cc
    explosion.cc
    game.cc
    gem.cc
    input.cc
    loader.cc
    main.cc
    moving_entity.cc
    plasma.cc
    process.cc
    properties.cc
    resident_sprite.cc
    ship.cc
    shooter.cc)

list(TRANSFORM bullet_hell_SOURCES
    PREPEND ${bullet_hell_CODE_SOURCE_DIR}/)

add_executable(${bullet_hell_EXECUTABLE} ${bullet_hell_SOURCES})

target_include_directories(${bullet_hell_EXECUTABLE}
    PRIVATE ${SHARED_SOURCE_DIR}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

if(DEFINED ENGINE_LIBRARIES)
    target_link_libraries(${bullet_hell_EXECUTABLE} ${ENGINE_LIBRARIES})
endif()
