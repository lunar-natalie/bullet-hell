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

#include <cstdlib>

#include <olcPixelGameEngine.h>

#include "entity.h"
#include "sprite.h"

using namespace bullet_hell;

bool Game::checkCollision(const Entity* source, const Sprite* sourceSprite,
                          const Entity* target,
                          const Sprite* targetSprite) const
{
    auto sourceHitbox = source->getDisplayedSize(sourceSprite) / 3.0f;
    auto targetHitbox = target->getDisplayedSize(targetSprite) / 3.0f;

    // Distance between center of each sprite.
    olc::vf2d combinedHitbox = {sourceHitbox.x + targetHitbox.x,
                                sourceHitbox.y + targetHitbox.y};

    // Distance between on-screen entities.
    olc::vf2d distance = {std::abs(target->position.x - source->position.x),
                          std::abs(target->position.y - source->position.y)};

    // Collided if the on-screen distance falls within the combined hitbox.
    return distance.x < combinedHitbox.x && distance.y < combinedHitbox.y;
}

bool Game::checkBounds(const Entity* entity) const
{
    // `true` if the entity's position fits within the viewport extended by an
    // invisible buffer area with a margin of 20 pixels.
    return entity->position.x >= -20.0f && entity->position.y >= -20.0f
           && entity->position.x <= static_cast<float>(screenWidth) + 20.0f
           && entity->position.y <= static_cast<float>(screenHeight) + 20.0f;
}
