//
// spawn.cc
//
// Entity spawning routines.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

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
        shooters.push_back(new Shooter(math::randomMultiplier()
                                       * static_cast<float>(screenWidth)));
    }

    // Decrement gem timer before spawning a new gem with a random type and
    // random x-position when the timer passes 0 seconds, or when the spawn
    // interval has passed.
    Gem::spawnTimer -= elapsedTime;
    if (Gem::spawnTimer < 0.0f) {
        Gem::spawnTimer += Gem::spawnInterval;
        gems.push_back(
            new Gem(Gem::randomType(), math::randomMultiplier()
                                           * static_cast<float>(screenWidth)));
    }
}
