/// @file entity.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Base position-only entity object.
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

#ifndef BULLET_HELL_ENTITY_H
#define BULLET_HELL_ENTITY_H

#include <olcPixelGameEngine.h>

namespace bullet_hell {

/// @brief Representation of a visible object in the game.
struct Entity {
    /// @brief Position of the object in the screen, in pixels.
    olc::vf2d position;

    /// @brief Creates a new empty Entity object.
    Entity();

    /// @brief Creates a new Entity object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    Entity(float x, float y);
};

} // namespace bullet_hell

#endif // BULLET_HELL_ENTITY_H
