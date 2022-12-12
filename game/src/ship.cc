/*
 * ship.h
 *
 * Ship entity implementation.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "ship.h"

#include "sprite.h"

using namespace bullet_hell;

Sprite* Ship::sprite;

Ship::Ship()
    : accelerationModifier{3000.0f},
      decelerationModifier{7.5f},
      maxSpeed{1000.0f},
      reloadInterval{0.1f}
{
}
