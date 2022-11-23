set(bullet_hell_CODE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

configure_file(${bullet_hell_CODE_SOURCE_DIR}/config.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/config.h)

set(bullet_hell_SOURCES
    draw.cc
    entity/base.cc
    entity/bullet.cc
    entity/gem.cc
    entity/shooter.cc
    events.cc
    game.cc
    input.cc
    main.cc
    process.cc
    resident_sprite.cc)

list(TRANSFORM bullet_hell_SOURCES
     PREPEND "${bullet_hell_CODE_SOURCE_DIR}/")

add_executable(${bullet_hell_EXECUTABLE} ${bullet_hell_SOURCES})

target_include_directories(${bullet_hell_EXECUTABLE}
                           PRIVATE ${SHARED_SOURCE_DIR}
                           PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

if(DEFINED OLC_LIBRARIES)
    target_link_libraries(${bullet_hell_EXECUTABLE} ${OLC_LIBRARIES})
endif()
