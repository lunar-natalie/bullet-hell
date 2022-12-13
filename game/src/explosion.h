/// @file explosion.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Explosion entity.
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

#ifndef BULLET_HELL_EXPLOSION_H
#define BULLET_HELL_EXPLOSION_H

#include <olcPixelGameEngine.h>

#include "entity.h"
#include "partial_sprite.h"

namespace bullet_hell {

/// @brief Animated explosion entity.
struct Explosion : Entity {
    static PartialSprite* sprite;

    /// @brief Number of frames to show per second.
    static float frameRate;

    /// @brief Time elapsed in seconds since the last frame was drawn.
    float frameTimer;

    /// @brief Creates a new Explosion object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param scale x- and y-factors to multiply the entity's sprite size by
    /// when drawing or performing hitbox calculations.
    Explosion(float x, float y, olc::vf2d scale = {1.0f, 1.0f});

    /// @brief Updates `frameTimer` and checks whether the next frame should be
    /// drawn.
    /// @param elapsedTime Time elapsed in seconds since the function was last
    /// called.
    /// @return `true` if the next frame should be drawn, otherwise `false`.
    bool update(float elapsedTime);
};

} // namespace bullet_hell

#endif // BULLET_HELL_EXPLOSION_H
