/*
 * moving_entity.cc
 *
 * Velocity-based entity implementation.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "moving_entity.h"

#include "entity.h"

using namespace bullet_hell;

MovingEntity::MovingEntity()
{
}

MovingEntity::MovingEntity(float x, float y, float dx, float dy)
    : Entity(x, y),
      velocity{dx, dy}
{
}
