/*
 * explosion.cc
 *
 * Explosion entity implementation.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "explosion.h"

#include <olcPixelGameEngine.h>

#include "entity.h"
#include "resident_sprite.h"

using namespace bullet_hell;

ResidentSprite* Explosion::sprite = nullptr;
unsigned int Explosion::frameCount;
float Explosion::frameRate = 20.0f;

Explosion::Explosion(float x, float y)
    : Entity(x, y),
      timer{0.0f}
{
}

bool Explosion::update(float elapsedTime)
{
    timer += elapsedTime;
    return timer > static_cast<float>(frameCount) / frameRate;
}
