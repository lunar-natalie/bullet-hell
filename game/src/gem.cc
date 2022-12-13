//
// gem.cc
//
// Gem entity implementation.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#include "gem.h"

#include <cstdlib>

#include "moving_entity.h"
#include "partial_sprite.h"

using namespace bullet_hell;

PartialSprite* Gem::sprite;
float Gem::spawnTimer;
float Gem::spawnInterval = 0.5f;
float Gem::startY = -20.0f;
float Gem::defaultXVelocity = 0.0f;
float Gem::defaultYVelocity = 100.0f;

Gem::Gem(Type type, float x, float y, float dx, float dy)
    : MovingEntity(x, y, dx, dy),
      type{type}
{
}

Gem::Type Gem::randomType()
{
    return static_cast<Type>(rand() % typeCount);
}
