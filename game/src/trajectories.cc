//
// trajectories.cc
//
// Entity position, velocity and acceleration update routines.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#include "game.h"

#include <vector>

#include "direction.h"
#include "moving_entity.h"

using namespace bullet_hell;

void Game::updateShipTrajectory()
{
    // Move by the ship's acceleration modifier in the current direction(s).
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

    // Update ship velocity.
    ship->velocity += elapsedTime * ship->acceleration;

    // Multiply velocity by deceleration, scaled by the elapsed time. The upper
    // bound of the multiplier is 1 (resulting in the current velocity), and the
    // lower bound is determined by the deceleration modifier.
    ship->velocity *= 1.0f - (elapsedTime * ship->decelerationModifier);

    // Limit velocity to the ship's maximum speed value in any direction.
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

    // Update position.
    ship->position += elapsedTime * ship->velocity;

    // Prevent the outer edge of the ship from moving beyond the visible screen
    // area.
    if (ship->position.x < 25.0f) {
        ship->position.x = 25.0f;
        ship->velocity.x = 0.0f;
    }
    if (ship->position.y < 25.0f) {
        ship->position.y = 25.0f;
        ship->velocity.y = 0.0f;
    }
    float maxXPos = static_cast<float>(screenWidth) - 25.0f;
    if (ship->position.x > maxXPos) {
        ship->position.x = maxXPos;
        ship->velocity.x = 0.0f;
    }
    float maxYPos = static_cast<float>(screenHeight) - 25.0f;
    if (ship->position.y > maxYPos) {
        ship->position.y = maxYPos;
        ship->velocity.y = 0.0f;
    }
}

void Game::updateNonPlayerEntityTrajectories()
{
    // Create a combined 2D vector of all entity vectors derived from
    // MovingEntity, using the base type MovingEntity. Each vector in the first
    // dimension is initialized from a list of two iterators pointing to the
    // first and last element of each vector.
    std::vector<std::vector<MovingEntity*>> nonPlayerMovingEntities = {
        {shooters.begin(), shooters.end()},
        {gems.begin(), gems.end()},
        {bullets.begin(), bullets.end()},
        {plasmas.begin(), plasmas.end()}};

    // Update position of all entities using the method on the base type.
    for (auto& v : nonPlayerMovingEntities) {
        for (auto& entity : v) {
            entity->updatePosition(elapsedTime);
        }
    }
}
