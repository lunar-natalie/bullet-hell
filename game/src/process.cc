/// @file process.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Frame logic handler.
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

#include <iostream>

#include <olcPixelGameEngine.h>

#include "bullet.h"
#include "explosion.h"
#include "gem.h"
#include "plasma.h"
#include "ship.h"
#include "shooter.h"

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

    // Check collision between ship and bullets, and limit stored bullets to
    // rendering bounds.
    for (auto i = 0; i < bullets.size();) {
        bool shipHit =
            checkCollision(ship, Ship::sprite, bullets[i], Bullet::sprite);

        // Erase bullet if collided or out of bounds.
        if (shipHit || !checkBounds(bullets[i])) {
            bullets.erase(bullets.begin() + i);
        }
        else {
            ++i;
        }

        // Kill ship and create a new explosion starting from the ship's final
        // position if collided. Will only execute a maximum of 1 times in the
        // loop.
        if (shipHit && ship->isAlive) {
            ship->isAlive = false;
            explosions.push_back(
                new Explosion(ship->position.x, ship->position.y));
        }
    }

    // Check collision between shooters and plasmas, and limit stored plasmas to
    // rendering bounds.
    for (auto i = 0; i < plasmas.size();) {
        bool shooterHit = false;

        for (auto j = 0; j < shooters.size();) {
            shooterHit = checkCollision(shooters[j], Shooter::sprite,
                                        plasmas[i], Plasma::sprite);

            // Kill shooter and create a new explosion starting from the
            // shooter's final position if the plasma collided with the shooter.
            if (shooterHit) {
                explosions.push_back(new Explosion{shooters[j]->position.x,
                                                   shooters[j]->position.y});
                shooters.erase(shooters.begin() + j);
            }
            else {
                j++;
            }
        }

        // Erase plasma if collided or out of bounds.
        if (shooterHit || !checkBounds(plasmas[i])) {
            plasmas.erase(plasmas.begin() + i);
        }
        else {
            i++;
        }
    }

    // Check collision between gems and the ship, and limit stored gems to
    // rendering bounds.
    for (auto i = 0; i < gems.size();) {
        bool shipHit = checkCollision(ship, Ship::sprite, gems[i], Gem::sprite);

        // Erase gem if collided with ship or out of bounds.
        if (shipHit || !checkBounds(gems[i])) {
            gems.erase(gems.begin() + i);
        }
        else {
            ++i;
        }
    }

    // Limit stored shooters to rendering bounds.
    for (auto i = 0; i < shooters.size();) {
        if (!checkBounds(shooters[i])) {
            shooters.erase(shooters.begin() + i);
        }
        else {
            ++i;
        }
    }

    // Limit stored explosions to rendering bounds.
    for (auto i = 0; i < explosions.size();) {
        if (explosions[i]->update(elapsedTime)) {
            explosions.erase(explosions.begin() + i);
        }
        else {
            ++i;
        }
    }

    // Update shooter fire timers.
    for (auto& shooter : shooters) {
        shooter->fireTimer -= elapsedTime;
        if (shooter->fireTimer < 0) {
            // Fire
            shooter->fireTimer += 1.0f / shooter->fireRate;
            addBullets(shooter->fireCount, shooter->position);
        }
    }
}
