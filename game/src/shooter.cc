/*
 * shooter.cc
 *
 * Shooter entity implementation.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "shooter.h"

#include "moving_entity.h"
#include "resident_sprite.h"

using namespace bullet_hell;

ResidentSprite* Shooter::sprite = nullptr;
float Shooter::spawnTimer;
float Shooter::spawnRate;

Shooter::Shooter(float x, float y, float dx, float dy, float fireRate,
                 unsigned int fireCount)
    : MovingEntity(x, y, dx, dy),
      fireRate{fireRate},
      fireCount{fireCount}
{
    fireTimer = 1.0f / fireRate;
}
