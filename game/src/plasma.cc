/*
 * plasma.cc
 *
 * Plasma entity implementation.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "plasma.h"

#include "moving_entity.h"
#include "resident_sprite.h"

using namespace bullet_hell;

ResidentSprite* Plasma::sprite = nullptr;
const float Plasma::startXOffset = -40.0f;
const float Plasma::baseSpeed = 500.0f;

Plasma::Plasma(float x, float y, float dx, float dy)
    : MovingEntity(x, y, dx, dy)
{
}
