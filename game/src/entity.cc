/*
 * entity.cc
 *
 * Base entity implementation.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "entity.h"

using namespace bullet_hell;

Entity::Entity()
{
}

Entity::Entity(float x, float y)
    : position{x, y}
{
}
