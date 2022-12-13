/// @file collision.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Entity collision checking routines.
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

#include "game.h"

#include <cmath>

#include "entity.h"

using namespace bullet_hell;

bool Game::checkCollision(const Entity* source, const Entity* target) const
{
    // Using `source` and `target` as positions on an x- and y-coordinate grid,
    // Pythagoras' Theorem tells us that where:
    //      * `xs` is the x-coordinate of the source
    //      * `xt` is the x-coordinate of the target
    //      * `ys` is the y-coordinate of the source
    //      * `yt` is the y-coordinate of the target
    //      * `d` is the distance between the source and target;
    // The following is true:
    //      (xt - xs)^2 + (yt - ys)^2 = d^2
    // If the distance `d` is less than 25 pixels squared, the entities have
    // collided.
    return pow(target->position.x - source->position.x, 2)
               + pow(target->position.y - source->position.y, 2)
           < pow(25.0f, 2);
}

bool Game::checkBounds(const Entity* entity) const
{
    // `true` if the entity's position fits within the viewport extended by an
    // invisible buffer area with a margin of 20 pixels.
    return entity->position.x >= -20.0f && entity->position.y >= -20.0f
           && entity->position.x <= static_cast<float>(screenWidth) + 20.0f
           && entity->position.y <= static_cast<float>(screenHeight) + 20.0f;
}
