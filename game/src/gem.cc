/*
 * gem.cc
 *
 * Gem entity implementation.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "gem.h"

#include <cstdlib>

#include "moving_entity.h"
#include "resident_sprite.h"

using namespace bullet_hell;

ResidentSprite* Gem::sprite = nullptr;
float Gem::spawnTimer;
float Gem::spawnRate;

Gem::Gem(float x, float y, float dx, float dy, Type type)
    : MovingEntity(x, y, dx, dy),
      type{type}
{
}

Gem::Type Gem::randomType()
{
    return static_cast<Type>(rand() % typeCount);
}
