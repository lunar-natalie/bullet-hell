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

#include "direction.h"
#include "gem.h"
#include "math.h"
#include "plasma.h"
#include "shooter.h"

using namespace bullet_hell;

void Game::addBullets(size_t count, olc::vf2d start)
{
    const float offset = (float) math::TWO_PI * math::randomMultiplier();
    for (size_t i = 0; i < count; ++i) {
        const float x =
            ((float) math::TWO_PI * ((float) i / (float) count)) + offset;
        bullets.push_back(
            new Bullet(start.x, start.y, 100 * cos(x), 100 * sin(x)));
    }
}

void Game::process(float elapsedTime)
{
    if (shouldReset) {
        srand(time(NULL));

        timer = 0.0f;
        frames = 0;

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

        shouldReset = false;
    }

    timer += elapsedTime;
    ++frames;
    if (timer > 1.0f) {
        fps = frames;
        frames = 0;
        --timer;
        std::cout << shooters.size() << " shooters, " << bullets.size()
                  << " bullets, " << gems.size() << " gems." << std::endl;
    }

    Shooter::spawnTimer -= elapsedTime;
    if (Shooter::spawnTimer < 0) {
        Shooter::spawnTimer += 2;
        shooters.push_back(new Shooter(math::randomMultiplier() * screenWidth,
                                       -20, 0, 50, 0.25, 10));
    }

    Gem::spawnTimer -= elapsedTime;
    if (Gem::spawnTimer < 0) {
        Gem::spawnTimer += 0.5;
        gems.push_back(new Gem(math::randomMultiplier() * screenWidth, -20, 0,
                               100, Gem::randomType()));
    }

    if (ship->isAlive) {
        ship->acceleration.x = 0.0f;
        ship->acceleration.y = 0.0f;
        if (ship->direction != Direction::NONE) {
            if (ship->direction & Direction::LEFT) {
                ship->acceleration.x -= ship->accelerationModifier;
            }
            if (ship->direction & Direction::RIGHT) {
                ship->acceleration.x += ship->accelerationModifier;
            }
            if (ship->direction & Direction::UP) {
                ship->acceleration.y -= ship->accelerationModifier;
            }
            if (ship->direction & Direction::DOWN) {
                ship->acceleration.y += ship->accelerationModifier;
            }
            ship->direction = Direction::NONE;
        }

        ship->velocity += elapsedTime * ship->acceleration;

        ship->velocity *= 1 - elapsedTime * ship->decelerationModifier;

        if (ship->velocity.x < -ship->maxSpeed) {
            ship->velocity.x = -ship->maxSpeed;
        }
        if (ship->velocity.y < -ship->maxSpeed) {
            ship->velocity.y = -ship->maxSpeed;
        }
        if (ship->velocity.x > ship->maxSpeed) {
            ship->velocity.x = ship->maxSpeed;
        }
        if (ship->velocity.y > ship->maxSpeed) {
            ship->velocity.y = ship->maxSpeed;
        }
        ship->position += elapsedTime * ship->velocity;

        if (ship->position.x < 25) {
            ship->position.x = 25;
            ship->velocity.x = 0;
        }
        if (ship->position.y < 25) {
            ship->position.y = 25;
            ship->velocity.y = 0;
        }
        if (ship->position.x > screenWidth - 25) {
            ship->position.x = screenWidth - 25;
            ship->velocity.x = 0;
        }
        if (ship->position.y > screenHeight - 25) {
            ship->position.y = screenHeight - 25;
            ship->velocity.y = 0;
        }

        ship->reloadTimer -= elapsedTime;
        if (ship->isFiring && ship->reloadTimer < 0.0f) {
            ship->reloadTimer = 0.1f;
            plasmas.push_back(new Plasma(
                ship->position.x, ship->position.y + Plasma::startXOffset, 0.0f,
                -Plasma::baseSpeed));
        }
    }

    for (auto& bullet : bullets) {
        bullet->position += elapsedTime * bullet->velocity;
    }

    for (auto& gem : gems) {
        gem->position += elapsedTime * gem->velocity;
    }

    for (auto& plasma : plasmas) {
        plasma->position += elapsedTime * plasma->velocity;
    }

    for (auto i = 0; i < explosions.size();) {
        if (explosions[i]->update(elapsedTime)) {
            explosions.erase(explosions.begin() + i);
        }
        else {
            ++i;
        }
    }

    for (auto i = 0; i < bullets.size();) {
        bool shipHit = pow(ship->position.x - bullets[i]->position.x, 2)
                           + pow(ship->position.y - bullets[i]->position.y, 2)
                       < pow(25, 2);

        if (shipHit || bullets[i]->position.x < -20
            || bullets[i]->position.y < -20
            || bullets[i]->position.x > screenWidth + 20
            || bullets[i]->position.y > screenHeight + 20) {
            bullets.erase(bullets.begin() + i);
        }
        else {
            ++i;
        }

        if (shipHit && ship->isAlive) {
            ship->isAlive = false;
            explosions.push_back(
                new Explosion(ship->position.x, ship->position.y));
            break;
        }
    }

    for (auto i = 0; i < plasmas.size();) {
        bool shooterHit = false;

        for (auto j = 0; j < shooters.size();) {
            shooterHit =
                pow(shooters[j]->position.x - plasmas[i]->position.x, 2)
                    + pow(shooters[j]->position.y - plasmas[i]->position.y, 2)
                < pow(25, 2);
            if (shooterHit) {
                explosions.push_back(new Explosion{shooters[j]->position.x,
                                                   shooters[j]->position.y});
                shooters.erase(shooters.begin() + j);
                break;
            }
            else {
                j++;
            }
        }

        if (shooterHit || plasmas[i]->position.x < -20
            || plasmas[i]->position.y < -20
            || plasmas[i]->position.x > screenWidth + 20
            || plasmas[i]->position.y > screenHeight + 20) {
            plasmas.erase(plasmas.begin() + i);
        }
        else {
            i++;
        }
    }

    for (auto i = 0; i < gems.size();) {
        bool shipHit = pow(ship->position.x - gems[i]->position.x, 2)
                           + pow(ship->position.y - gems[i]->position.y, 2)
                       < pow(30, 2);

        if (shipHit || gems[i]->position.x < -20 || gems[i]->position.y < -20
            || gems[i]->position.x > screenWidth + 20
            || gems[i]->position.y > screenHeight + 20) {
            gems.erase(gems.begin() + i);
        }
        else {
            ++i;
        }
    }

    for (auto& shooter : shooters) {
        shooter->position += elapsedTime * shooter->velocity;
        shooter->fireTimer -= elapsedTime;
        if (shooter->fireTimer < 0) {
            shooter->fireTimer += 1.0f / shooter->fireRate;
            addBullets(shooter->fireCount, shooter->position);
        }
    }

    for (auto i = 0; i < shooters.size();) {
        if (shooters[i]->position.x < -20 || shooters[i]->position.y < -20
            || shooters[i]->position.x > screenWidth + 20
            || shooters[i]->position.y > screenHeight + 20) {
            shooters.erase(shooters.begin() + i);
        }
        else {
            ++i;
        }
    }
}
