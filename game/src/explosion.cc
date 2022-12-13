//
// explosion.cc
//
// Explosion entity implementation.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#include "explosion.h"

#include <olcPixelGameEngine.h>

#include "entity.h"
#include "partial_sprite.h"

using namespace bullet_hell;

PartialSprite* Explosion::sprite;
float Explosion::frameRate = 20.0f;

Explosion::Explosion(float x, float y)
    : Entity(x, y),
      frameTimer{0.0f}
{
}

bool Explosion::update(float elapsedTime)
{
    frameTimer += elapsedTime;
    return frameTimer > static_cast<float>(sprite->frameCount) / frameRate;
}
