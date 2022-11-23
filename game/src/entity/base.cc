/*
 * base.cc
 *
 * Base entity methods.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#include "base.h"

using namespace bullet_hell;

Entity::Entity(float x, float y, float dx, float dy)
{
    position.x = x;
    position.y = y;
    velocity.x = dx;
    velocity.y = dy;
};
