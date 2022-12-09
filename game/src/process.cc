/*
 * process.cc
 *
 * Per-frame logic handler.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "game.h"

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>

#include <olcPixelGameEngine.h>

#include "math.h"

using namespace bullet_hell;

void Game::addBullets(size_t count, olc::vf2d start)
{
    const float offset = (float) math::TWO_PI * math::randomMultiplier();
    for (size_t i = 0; i < count; ++i) {
        const float x =
            ((float) math::TWO_PI * ((float) i / (float) count)) + offset;
        bullets.push_back(Bullet(start.x, start.y, 100 * cos(x), 100 * sin(x)));
    }
}

void Game::process(float elapsedTime)
{
    timer += elapsedTime;
    ++frames;
    if (timer > 1.0f) {
        fps = frames;
        frames = 0;
        --timer;
        std::cout << shooters.size() << " shooters, " << bullets.size()
                  << " bullets, " << gems.size() << " gems." << std::endl;
    }

    shooterSpawnTimer -= elapsedTime;
    if (shooterSpawnTimer < 0) {
        shooterSpawnTimer += 2;
        shooters.push_back(Shooter(math::randomMultiplier() * screenWidth, -20,
                                   0, 50, 0.25, 10));
    }

    gemSpawnTimer -= elapsedTime;
    if (gemSpawnTimer < 0) {
        gemSpawnTimer += 0.5;
        gems.push_back(Gem(math::randomMultiplier() * screenHeight, -20, 0, 100,
                           rand() % 4));
    }

    if (shipAlive) {
        shipVelocity += elapsedTime * shipAcceleration;

        shipVelocity *= 1 - elapsedTime * deceleration;

        if (shipVelocity.x < -maxSpeed) {
            shipVelocity.x = -maxSpeed;
        }
        if (shipVelocity.y < -maxSpeed) {
            shipVelocity.y = -maxSpeed;
        }
        if (shipVelocity.x > maxSpeed) {
            shipVelocity.x = maxSpeed;
        }
        if (shipVelocity.y > maxSpeed) {
            shipVelocity.y = maxSpeed;
        }
        shipPosition += elapsedTime * shipVelocity;

        if (shipPosition.x < 25) {
            shipPosition.x = 25;
            shipVelocity.x = 0;
        }
        if (shipPosition.y < 25) {
            shipPosition.y = 25;
            shipVelocity.y = 0;
        }
        if (shipPosition.x > screenWidth - 25) {
            shipPosition.x = screenWidth - 25;
            shipVelocity.x = 0;
        }
        if (shipPosition.y > screenHeight - 25) {
            shipPosition.y = screenHeight - 25;
            shipVelocity.y = 0;
        }
    }
    else {
        explosionTimer += elapsedTime;
    }

    for (auto& bullet : bullets) {
        bullet.position += elapsedTime * bullet.velocity;
    }

    for (auto& gem : gems) {
        gem.position += elapsedTime * gem.velocity;
    }

    for (auto i = 0; i < bullets.size();) {
        bool shipHit = pow(shipPosition.x - bullets[i].position.x, 2)
                           + pow(shipPosition.y - bullets[i].position.y, 2)
                       < pow(25, 2);

        if (shipHit) {
            shipAlive = false;
        }

        if (shipHit || bullets[i].position.x < -20
            || bullets[i].position.y < -20
            || bullets[i].position.x > screenWidth + 20
            || bullets[i].position.y > screenHeight + 20) {
            bullets.erase(bullets.begin() + i);
        }
        else {
            ++i;
        }
    }

    for (auto i = 0; i < gems.size();) {
        bool shipHit = pow(shipPosition.x - gems[i].position.x, 2)
                           + pow(shipPosition.y - gems[i].position.y, 2)
                       < pow(30, 2);

        if (shipHit || gems[i].position.x < -20 || gems[i].position.y < -20
            || gems[i].position.x > screenWidth + 20
            || gems[i].position.y > screenHeight + 20) {
            gems.erase(gems.begin() + i);
        }
        else {
            ++i;
        }
    }

    for (auto& shooter : shooters) {
        shooter.position += elapsedTime * shooter.velocity;
        shooter.timer -= elapsedTime;
        if (shooter.timer < 0) {
            shooter.timer += 1.0f / shooter.fireRate;
            addBullets(shooter.fireCount, shooter.position);
        }
    }

    for (auto i = 0; i < shooters.size();) {
        if (shooters[i].position.x < -20 || shooters[i].position.y < -20
            || shooters[i].position.x > screenWidth + 20
            || shooters[i].position.y > screenHeight + 20) {
            shooters.erase(shooters.begin() + i);
        }
        else {
            ++i;
        }
    }
}
