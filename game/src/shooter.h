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
#include "resident_sprite.h"

namespace bullet_hell {

struct Shooter : public MovingEntity {
    static ResidentSprite* sprite;
    static float spawnTimer;
    static float spawnRate;
    float fireRate;
    unsigned int fireCount;
    float fireTimer;

    Shooter(float x, float y, float dx, float dy, float fireRate,
            unsigned int fireCount);
};

} // namespace bullet_hell

#endif // BULLET_HELL_SHOOTER_H
