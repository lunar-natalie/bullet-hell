/// @file moving_entity.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Entity object with velocity.
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

#ifndef BULLET_HELL_MOVING_ENTITY_H
#define BULLET_HELL_MOVING_ENTITY_H

#include <olcPixelGameEngine.h>

#include "entity.h"

namespace bullet_hell {

/// @brief Representation of a moving visible object in the game.
struct MovingEntity : Entity {
    /// @brief Velocity of the object in pixels per second.
    olc::vf2d velocity;

    /// @brief Creates a new empty MovingEntity object.
    MovingEntity();

    /// @brief Creates a new MovingEntity object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param dx x-velocity in pixels per second.
    /// @param dy y-velocity in pixels per second.
    MovingEntity(float x, float y, float dx, float dy);

    /// @brief Increments the entity's position by the provided time multiplied
    /// by the entity's velocity.
    /// @param elapsedTime Time elapsed in seconds since the function was last
    /// called.
    void updatePosition(float elapsedTime);
};

} // namespace bullet_hell

#endif // BULLET_HELL_MOVING_ENTITY_H
