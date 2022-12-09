/*
 * plasma.h
 *
 * Plasma entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_PLASMA_H
#define BULLET_HELL_PLASMA_H

#include "moving_entity.h"
#include "resident_sprite.h"

namespace bullet_hell {

struct Plasma : public MovingEntity {
    static ResidentSprite* sprite;
    static const float startXOffset;
    static const float baseSpeed;

    Plasma(float x, float y, float dx, float dy);
};

} // namespace bullet_hell

#endif // BULLET_HELL_PLASMA_H
