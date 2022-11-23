/*
 * process.cc
 *
 * Continuous logic.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#include "game.h"

#include <cmath>

#include "config.h"

using namespace bullet_hell;

void Game::process(float elapsedTime)
{
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
        if (shipPosition.x > config::WINDOW_WIDTH - 25) {
            shipPosition.x = config::WINDOW_WIDTH - 25;
            shipVelocity.x = 0;
        }
        if (shipPosition.y > config::WINDOW_HEIGHT - 25) {
            shipPosition.y = config::WINDOW_HEIGHT - 25;
            shipVelocity.y = 0;
        }
    } else {
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
            || bullets[i].position.x > config::WINDOW_WIDTH + 20
            || bullets[i].position.y > config::WINDOW_HEIGHT + 20) {
            bullets.erase(bullets.begin() + i);
        } else {
            ++i;
        }
    }

    for (auto i = 0; i < gems.size();) {
        bool shipHit = pow(shipPosition.x - gems[i].position.x, 2)
                           + pow(shipPosition.y - gems[i].position.y, 2)
                       < pow(30, 2);

        if (shipHit || gems[i].position.x < -20 || gems[i].position.y < -20
            || gems[i].position.x > config::WINDOW_WIDTH + 20
            || gems[i].position.y > config::WINDOW_HEIGHT + 20) {
            gems.erase(gems.begin() + i);
        } else {
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
            || shooters[i].position.x > config::WINDOW_WIDTH + 20
            || shooters[i].position.y > config::WINDOW_HEIGHT + 20) {
            shooters.erase(shooters.begin() + i);
        } else {
            ++i;
        }
    }
}
