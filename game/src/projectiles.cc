/*
 * projectiles.cc
 *
 * Entity projectile firing routines.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "game.h"

#include <cmath>

#include "bullet.h"
#include "math.h"
#include "plasma.h"

using namespace bullet_hell;

void Game::updateShipFire()
{
    ship->reloadTimer -= elapsedTime;
    if (ship->isFiring && ship->reloadTimer < 0.0f) {
        ship->reloadTimer = 0.1f;
        plasmas.push_back(new Plasma(ship->position.x,
                                     ship->position.y + Plasma::startXOffset,
                                     0.0f, -Plasma::baseSpeed));
    }
}

void Game::addBullets(unsigned int count, olc::vf2d startPosition)
{
    float offset = static_cast<float>(math::TWO_PI) * math::randomMultiplier();
    for (auto i = 0; i < count; ++i) {
        float x = (static_cast<float>(math::TWO_PI)
                   * (static_cast<float>(i) / static_cast<float>(count)))
                  + offset;
        bullets.push_back(new Bullet(startPosition.x, startPosition.y,
                                     100.0f * cos(x), 100.0f * sin(x)));
    }
}
