/// @file plasma.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Plasma entity.
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

#ifndef BULLET_HELL_PLASMA_H
#define BULLET_HELL_PLASMA_H

#include "moving_entity.h"
#include "sprite.h"

namespace bullet_hell {

/// @brief Plasma projectile entity fired by the ship.
struct Plasma : MovingEntity {
    static Sprite* sprite;

    /// @brief Offset from the y-position of the firing ship in pixels. Used to
    /// set the position of newly spawned plasmas.
    static float initialYOffset;

    /// @brief Positive speed used to set the Plasma's velocity.
    static float baseSpeed;

    /// @brief Creates a new Plasma object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param dx x-velocity in pixels per second.
    /// @param dy y-velocity in pixels per second.
    Plasma(float x, float y, float dx, float dy);
};

} // namespace bullet_hell

#endif // BULLET_HELL_PLASMA_H
