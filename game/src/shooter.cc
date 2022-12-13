//
// shooter.cc
//
// Shooter entity implementation.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#include "shooter.h"

#include "moving_entity.h"
#include "sprite.h"

using namespace bullet_hell;

Sprite* Shooter::sprite;
float Shooter::spawnTimer;
float Shooter::spawnInterval = 2.0f;
float Shooter::startY = -20.0f;
float Shooter::defaultXVelocity = 0.0f;
float Shooter::defaultYVelocity = 50.0f;
float Shooter::defaultFireRate = 0.25f;
unsigned int Shooter::defaultFireCount = 10;

Shooter::Shooter(float x, float y, float dx, float dy, float fireRate,
                 unsigned int fireCount)
    : MovingEntity(x, y, dx, dy),
      fireRate{fireRate},
      fireCount{fireCount}
{
    fireTimer = 1.0f / fireRate;
}
