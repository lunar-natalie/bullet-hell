/*
 * reset.cc
 *
 * Game logic reset routine.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "game.h"

#include <cstdlib>
#include <ctime>

#include "direction.h"
#include "gem.h"
#include "shooter.h"

using namespace bullet_hell;

void Game::reset()
{
    srand(time(NULL));

    frameTimer = 0.0f;
    elapsedFrames = 0;

    Gem::spawnTimer = 0.0f;
    Shooter::spawnTimer = 0.0f;

    ship->isAlive = true;
    ship->position = {static_cast<float>(screenWidth) / 2.0f,
                      static_cast<float>(screenHeight) - 100.0f};
    ship->direction = Direction::NONE;
    ship->velocity = {0.0f, 0.0f};
    ship->acceleration = {0.0f, 0.0f};
    ship->isFiring = false;
    ship->reloadTimer = 0.0f;
}
