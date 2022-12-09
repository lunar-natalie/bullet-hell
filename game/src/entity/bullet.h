/*
 * bullet.h
 *
 * Bullet entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_ENTITY_BULLET_H
#define BULLET_HELL_ENTITY_BULLET_H

#include "base.h"

namespace bullet_hell {

struct Bullet : public Entity {
    Bullet(float x, float y, float dx, float dy);
};

} // namespace bullet_hell

#endif // BULLET_HELL_ENTITY_BULLET_H
