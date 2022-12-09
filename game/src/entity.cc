/*
 * entity.cc
 *
 * Base entity methods.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "entity.h"

using namespace bullet_hell;

Entity::Entity(float x, float y, float dx, float dy)
    : position{x, y},
      velocity{dx, dy}
{
}
