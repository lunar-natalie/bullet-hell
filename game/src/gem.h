/*
 * gem.h
 *
 * Gem entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_GEM_H
#define BULLET_HELL_GEM_H

#include "moving_entity.h"
#include "partial_sprite.h"

namespace bullet_hell {

struct Gem : MovingEntity {
    static PartialSprite* sprite;
    enum class Type : unsigned int {
        RED = 0,
        YELLOW = 1,
        GREEN = 2,
        BLUE = 3
    } type;
    static constexpr const unsigned int typeCount = 4;
    static float spawnTimer;
    static float spawnInterval;
    static float startY;
    static float defaultXVelocity;
    static float defaultYVelocity;

    Gem(Type type, float x, float y = startY, float dx = defaultXVelocity,
        float dy = defaultYVelocity);

    static Type randomType();
};

} // namespace bullet_hell

#endif // BULLET_HELL_GEM_H
