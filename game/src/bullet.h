/// @file bullet.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Bullet entity implementation.
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

#ifndef BULLET_HELL_BULLET_H
#define BULLET_HELL_BULLET_H

#include <olcPixelGameEngine.h>

#include "moving_entity.h"
#include "sprite.h"

namespace bullet_hell {

/// @brief Bullet projectile entity fired by shooters.
struct Bullet : MovingEntity {
    static Sprite* sprite;

    /// @brief Creates a new Bullet object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param dx x-velocity in pixels per second.
    /// @param dy y-velocity in pixels per second.
    /// @param scale x- and y-factors to multiply the entity's sprite size by
    /// when drawing or performing hitbox calculations.
    Bullet(float x, float y, float dx, float dy,
           olc::vf2d scale = {1.0f, 1.0f});
};

} // namespace bullet_hell

#endif // BULLET_HELL_BULLET_H
