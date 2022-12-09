/*
 * ship.h
 *
 * Ship entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_SHIP_H
#define BULLET_HELL_SHIP_H

#include <olcPixelGameEngine.h>

#include "direction.h"
#include "moving_entity.h"
#include "resident_sprite.h"

namespace bullet_hell {

struct Ship : public MovingEntity {
    static ResidentSprite* sprite;
    olc::vf2d acceleration;
    Direction direction;
    float accelerationModifier;
    float decelerationModifier;
    float maxSpeed;
    bool isAlive;
    bool isFiring;
    float reloadTimer;

    Ship();
};

} // namespace bullet_hell

#endif // BULLET_HELL_SHIP_H
