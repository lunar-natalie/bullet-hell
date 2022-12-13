//
// reset.cc
//
// Game logic reset routine.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

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
    srand(time(NULL));

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
