/// @file reset.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Game logic reset routine.
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
#include <ctime>

#include "direction.h"
#include "gem.h"
#include "shooter.h"

using namespace bullet_hell;

void Game::reset()
{
    // Seed random number generator with current time to randomize entity spawn
    // properties.
    std::srand(std::time(0));

    // Frame properties.
    frameTimer = 0.0f;
    elapsedFrames = 0;

    // Spawn timers.
    Gem::spawnTimer = 0.0f;
    Shooter::spawnTimer = 0.0f;

    // Ship properties.
    ship->isAlive = true;
    ship->position = {(static_cast<float>(screenWidth) / 2.0f)
                          - (static_cast<float>(ship->sprite->width)
                             / 2.0f), // Horizontal center
                      static_cast<float>(screenHeight)
                          - (static_cast<float>(ship->sprite->height) / 2.0f)
                          - 50.0f}; // Above lower screen bound
    ship->direction = Direction::NONE;
    ship->velocity = {0.0f, 0.0f};
    ship->acceleration = {0.0f, 0.0f};
    ship->isFiring = false;
    ship->reloadTimer = 0.0f;
}
