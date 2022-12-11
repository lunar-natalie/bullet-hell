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
const float Ship::defaultAccelerationModifier = 3000.0f;
const float Ship::defaultDecelerationModifier = 7.5f;
const float Ship::defaultMaxSpeed = 1000.0f;

Ship::Ship()
    : accelerationModifier{defaultAccelerationModifier},
      decelerationModifier{defaultDecelerationModifier},
      maxSpeed{defaultMaxSpeed}
{
}
