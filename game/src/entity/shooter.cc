/*
 * shooter.cc
 *
 * Shooter methods.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#include "shooter.h"

#include "base.h"

using namespace bullet_hell;

Shooter::Shooter(float x, float y, float dx, float dy, float fireRate,
                 unsigned int fireCount)
    : Entity(x, y, dx, dy), fireRate{fireRate}, fireCount{fireCount}
{
    timer = 1.0f / fireRate;
}
