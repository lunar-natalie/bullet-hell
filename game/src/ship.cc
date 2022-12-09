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

#include "resident_sprite.h"

using namespace bullet_hell;

ResidentSprite* Ship::sprite = nullptr;

Ship::Ship()
{
}
