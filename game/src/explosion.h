/*
 * explosion.h
 *
 * Explosion entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_EXPLOSION_H
#define BULLET_HELL_EXPLOSION_H

#include <olcPixelGameEngine.h>

#include "entity.h"
#include "partial_sprite.h"

namespace bullet_hell {

struct Explosion : Entity {
    static PartialSprite* sprite;
    static float frameRate;
    float frameTimer;

    Explosion(float x, float y);

    bool update(float elapsedTime);
};

} // namespace bullet_hell

#endif // BULLET_HELL_EXPLOSION_H
