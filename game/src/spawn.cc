/// @file spawn.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Entity spawning routines.
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

#include "gem.h"
#include "math.h"
#include "shooter.h"

using namespace bullet_hell;

void Game::spawnEntities()
{
    // Decrement shooter timer before spawning a new shooter with a random
    // x-position when the timer passes 0 seconds, or when the spawn interval
    // has passed.
    Shooter::spawnTimer -= elapsedTime;
    if (Shooter::spawnTimer < 0.0f) {
        Shooter::spawnTimer += Shooter::spawnInterval;
        shooters.push_back(new Shooter(
            math::randomMultiplier() * static_cast<float>(screenWidth),
            Shooter::startY, Shooter::defaultXVelocity,
            Shooter::defaultYVelocity, Shooter::defaultFireRate,
            Shooter::defaultFireCount, {0.0333f, 0.0333f}));
    }

    // Decrement gem timer before spawning a new gem with a random type and
    // random x-position when the timer passes 0 seconds, or when the spawn
    // interval has passed.
    Gem::spawnTimer -= elapsedTime;
    if (Gem::spawnTimer < 0.0f) {
        Gem::spawnTimer += Gem::spawnInterval;
        gems.push_back(
            new Gem(math::randomMultiplier() * static_cast<float>(screenWidth),
                    Gem ::startY, Gem::defaultXVelocity, Gem::defaultYVelocity,
                    Gem::randomType()));
    }
}
