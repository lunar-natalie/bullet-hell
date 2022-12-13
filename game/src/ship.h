//
// ship.h
//
// Ship entity.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#ifndef BULLET_HELL_SHIP_H
#define BULLET_HELL_SHIP_H

#include <olcPixelGameEngine.h>

#include "direction.h"
#include "moving_entity.h"
#include "sprite.h"

namespace bullet_hell {

/// @brief Player-controlled ship entity.
struct Ship : MovingEntity {
    static Sprite* sprite;

    /// @brief Acceleration of the object on the screen, in pixels per second
    /// squared.
    olc::vf2d acceleration;

    /// @brief All current ship directions combined with the Direction's
    /// `operator|=`.
    Direction direction;

    /// @brief Value added to or subtracted from the ship's previous
    /// acceleration value when moving.
    float accelerationModifier;

    /// @brief Value added to or subtracted from the ship's previous
    /// deceleration value when coming to a halt.
    float decelerationModifier;

    /// @brief Maximum positive speed in any direction. Compared with the ship's
    /// velocity value to determine when acceleration or deceleration should
    /// stop.
    float maxSpeed;

    bool isAlive;
    bool isFiring;

    /// @brief Time elapsed in seconds since the ship was last able to fire.
    float reloadTimer;

    /// @brief Number of seconds between reloads until the ship can fire.
    float reloadInterval;

    Ship();
};

} // namespace bullet_hell

#endif // BULLET_HELL_SHIP_H
