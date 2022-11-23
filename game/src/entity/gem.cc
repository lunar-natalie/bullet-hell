/*
 * gem.cc
 *
 * Gem methods.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#include "gem.h"
#include "base.h"

using namespace bullet_hell;

Gem::Gem(float x, float y, float dx, float dy, int type)
    : Entity(x, y, dx, dy), type{type}
{
};
