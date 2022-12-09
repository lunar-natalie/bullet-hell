/*
 * shooter.cc
 *
 * Shooter methods.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "shooter.h"

#include "entity.h"

using namespace bullet_hell;

Shooter::Shooter(float x, float y, float dx, float dy, float fireRate,
                 unsigned int fireCount)
    : Entity(x, y, dx, dy),
      fireRate{fireRate},
      fireCount{fireCount}
{
    timer = 1.0f / fireRate;
}
