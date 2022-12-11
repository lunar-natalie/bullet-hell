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

#include <iostream>

#include <olcPixelGameEngine.h>

#include "explosion.h"

using namespace bullet_hell;

void Game::process()
{
    updateScreenDimensions();
    updateFrameProperties();

    if (shouldReset) {
        reset();
        shouldReset = false;
    }

    if (shouldShowStats) {
        std::cout << shooters.size() << " shooters, " << bullets.size()
                  << " bullets, " << gems.size() << " gems." << std::endl;
    }

    if (ship->isAlive) {
        updateShipTrajectory();
        updateShipFire();
    }

    spawnEntities();

    updateNonPlayerEntityTrajectories();

    for (auto i = 0; i < bullets.size();) {
        bool shipHit = checkCollision(ship, bullets[i]);

        if (shipHit || !checkBounds(bullets[i])) {
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
            shooterHit = checkCollision(shooters[j], plasmas[i]);
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

        if (shooterHit || !checkBounds(plasmas[i])) {
            plasmas.erase(plasmas.begin() + i);
        }
        else {
            i++;
        }
    }

    for (auto i = 0; i < gems.size();) {
        bool shipHit = checkCollision(ship, gems[i]);
        if (shipHit || !checkBounds(gems[i])) {
            gems.erase(gems.begin() + i);
        }
        else {
            ++i;
        }
    }

    for (auto& shooter : shooters) {
        shooter->fireTimer -= elapsedTime;
        if (shooter->fireTimer < 0) {
            shooter->fireTimer += 1.0f / shooter->fireRate;
            addBullets(shooter->fireCount, shooter->position);
        }
    }

    for (auto i = 0; i < shooters.size();) {
        if (!checkBounds(shooters[i])) {
            shooters.erase(shooters.begin() + i);
        }
        else {
            ++i;
        }
    }

    for (auto i = 0; i < explosions.size();) {
        if (explosions[i]->update(elapsedTime)) {
            explosions.erase(explosions.begin() + i);
        }
        else {
            ++i;
        }
    }
}
