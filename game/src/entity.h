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

#include "sprite.h"

namespace bullet_hell {

/// @brief Representation of a visible object in the game.
struct Entity {
    /// @brief Position of the object in the screen, in pixels.
    olc::vf2d position;

    /// @brief Factor to multiply the entity's sprite size by to get the
    /// displayed entity size. Set to {1.0f, 1.0f} by default in all
    /// constructors.
    olc::vf2d scale;

    /// @brief Creates a new Entity object with no set position.
    Entity();

    /// @brief Creates a new Entity object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    /// @param scale x- and y-factors to multiply the entity's sprite size by
    /// when drawing or performing hitbox calculations.
    Entity(float x, float y, olc::vf2d scale = {1.0f, 1.0f});

    /// @brief Gets the scaled dimensions of the entity on screen.
    /// @param sprite Sprite containing the unscaled dimensions.
    /// @return x- and y-size vector.
    olc::vf2d getDisplayedSize(const Sprite* sprite) const;
};

} // namespace bullet_hell

#endif // BULLET_HELL_ENTITY_H
