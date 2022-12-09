/*
 * shooter.h
 *
 * Shooter entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_ENTITY_SHOOTER_H
#define BULLET_HELL_ENTITY_SHOOTER_H

#include "entity.h"

namespace bullet_hell {

struct Shooter : public Entity {
    float fireRate;
    unsigned int fireCount;
    float timer;

    Shooter(float x, float y, float dx, float dy, float fireRate,
            unsigned int fireCount);
};

} // namespace bullet_hell

#endif // BULLET_HELL_ENTITY_SHOOTER_H
