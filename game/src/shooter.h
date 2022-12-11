/*
 * shooter.h
 *
 * Shooter entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_SHOOTER_H
#define BULLET_HELL_SHOOTER_H

#include "moving_entity.h"
#include "sprite.h"

namespace bullet_hell {

struct Shooter : MovingEntity {
    static Sprite* sprite;
    static float spawnTimer;
    static float spawnInterval;
    static float startY;
    static float defaultXVelocity;
    static float defaultYVelocity;
    static float defaultFireRate;
    static unsigned int defaultFireCount;
    float fireRate;
    unsigned int fireCount;
    float fireTimer;

    Shooter(float x, float y = startY, float dx = defaultXVelocity,
            float dy = defaultYVelocity, float fireRate = defaultFireRate,
            unsigned int fireCount = defaultFireCount);
};

} // namespace bullet_hell

#endif // BULLET_HELL_SHOOTER_H
