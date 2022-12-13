/// @file ship.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Ship entity.
///
/// @section LICENSE
///
/// Copyright (c) 2022 The SFC Project Authors.
///
/// This program is free software: you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with this program. If not, see <https://www.gnu.org/licenses/>.

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

    /// @brief Creates a new Ship object with default values.
    Ship();
};

} // namespace bullet_hell

#endif // BULLET_HELL_SHIP_H
