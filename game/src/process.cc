/*
 * process.cc
 *
 * Per-frame logic handler.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
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
    // Add a random amount of extra rotation
    const float offset = (float) math::TWO_PI * math::randomMultiplier();
    
    // Create `count` number of bullets
    for (size_t i = 0; i < count; ++i) {
        // Calculate the rotation required for an even pread of bullets
        const float theta =
            ((float) math::TWO_PI * ((float) i / (float) count)) + offset;
        
        // Spawn bullet
        bullets.push_back(Bullet(start.x, start.y, 100 * cos(theta), 100 * sin(theta)));
    }
}

void Game::process(float elapsedTime)
{
    // Update FPS every second
    timer += elapsedTime;
    ++frames;
    if (timer > 1.0f) {
        // Update the on screen FPS
        fps = frames;
        
        // Reset the FPS counter
        frames = 0;
        
        // Wait for another second to elapse
        --timer;
        
        // Debug information
        std::cout << shooters.size() << " shooters, " << bullets.size()
                  << " bullets, " << gems.size() << " gems." << std::endl;
    }

    // Update the time until another shooter should be spawned
    shooterSpawnTimer -= elapsedTime;
    if (shooterSpawnTimer < 0) {
        // Shooters should spawn every 2 seconds
        shooterSpawnTimer += 2;
        
        // Spawn the new shooter
        shooters.push_back(Shooter(math::randomMultiplier() * screenWidth, -20,
                                   0, 50, 0.25, 10));
    }

    // Update the time until another gem should be spawned
    gemSpawnTimer -= elapsedTime;
    if (gemSpawnTimer < 0) {
        // Gems should spawn every half a second
        gemSpawnTimer += 0.5;
        
        // Spawn the new gem
        gems.push_back(Gem(math::randomMultiplier() * screenHeight, -20, 0, 100,
                           rand() % 4));
    }

    if (shipAlive) {
        // Update ship velocity
        shipVelocity += elapsedTime * shipAcceleration;

        shipVelocity *= 1 - elapsedTime * deceleration;

        // Clamp ship speed
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
        
        // Update ship position
        shipPosition += elapsedTime * shipVelocity;

        // Prevent ship from moving out of bounds
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
    } else {
        // If the ship is dead show an explosion effect
        explosionTimer += elapsedTime;
    }

    // Update all bullets' positions
    for (auto& bullet : bullets) {
        bullet.position += elapsedTime * bullet.velocity;
    }

    // Update all gems' positions
    for (auto& gem : gems) {
        gem.position += elapsedTime * gem.velocity;
    }

    // Check if any bullet has hit the ship
    for (auto i = 0; i < bullets.size();) {
        // Check is the bullet is within 25 pixels of the ship
        bool shipHit = pow(shipPosition.x - bullets[i].position.x, 2)
                           + pow(shipPosition.y - bullets[i].position.y, 2)
                       < pow(25, 2);

        // If the ship has been hit, the ship should die
        if (shipHit) {
            shipAlive = false;
        }

        // Remove any bullets that hit they player or are out of bounds
        if (shipHit || bullets[i].position.x < -20
            || bullets[i].position.y < -20
            || bullets[i].position.x > screenWidth + 20
            || bullets[i].position.y > screenHeight + 20) {
            bullets.erase(bullets.begin() + i);
        } else {
            ++i;
        }
    }

    // Check if the player has collided with any gems
    for (auto i = 0; i < gems.size();) {
        // Check if the gem is within 230 pixels of the ship
        bool shipHit = pow(shipPosition.x - gems[i].position.x, 2)
                           + pow(shipPosition.y - gems[i].position.y, 2)
                       < pow(30, 2);

        // Remove any gems colliding with the ship
        if (shipHit || gems[i].position.x < -20 || gems[i].position.y < -20
            || gems[i].position.x > screenWidth + 20
            || gems[i].position.y > screenHeight + 20) {
            gems.erase(gems.begin() + i);
        } else {
            ++i;
        }
    }

    // Update the shooters' positions
    for (auto& shooter : shooters) {
        shooter.position += elapsedTime * shooter.velocity;
        shooter.timer -= elapsedTime;
        if (shooter.timer < 0) {
            shooter.timer += 1.0f / shooter.fireRate;
            addBullets(shooter.fireCount, shooter.position);
        }
    }

    // Remove any out of bounds shooters
    for (auto i = 0; i < shooters.size();) {
        if (shooters[i].position.x < -20 || shooters[i].position.y < -20
            || shooters[i].position.x > screenWidth + 20
            || shooters[i].position.y > screenHeight + 20) {
            shooters.erase(shooters.begin() + i);
        } else {
            ++i;
        }
    }
}
