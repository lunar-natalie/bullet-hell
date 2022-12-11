/*
 * collision.cc
 *
 * Collision checking routines.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "game.h"

#include <cmath>

#include "entity.h"

using namespace bullet_hell;

bool Game::checkCollision(const Entity* source, const Entity* target) const
{
    return pow(source->position.x - target->position.x, 2)
               + pow(source->position.y - target->position.y, 2)
           < pow(25.0f, 2);
}

bool Game::checkBounds(const Entity* entity) const
{
    return entity->position.x >= -20.0f && entity->position.y >= -20.0f
           && entity->position.x <= static_cast<float>(screenWidth) + 20.0f
           && entity->position.y <= static_cast<float>(screenHeight) + 20.0f;
}
