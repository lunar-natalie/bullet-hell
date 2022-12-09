/*
 * bullet.cc
 *
 * Bullet entity implementation.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "bullet.h"

#include "moving_entity.h"
#include "resident_sprite.h"

using namespace bullet_hell;

ResidentSprite* Bullet::sprite = nullptr;

Bullet::Bullet(float x, float y, float dx, float dy)
    : MovingEntity(x, y, dx, dy)
{
}
