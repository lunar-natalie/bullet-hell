/*
 * gem.h
 *
 * Gem entity.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef BULLET_HELL_ENTITY_GEM_H
#define BULLET_HELL_ENTITY_GEM_H

#include "base.h"

namespace bullet_hell {

struct Gem : public Entity {
    int type;

    Gem(float x, float y, float dx, float dy, int type);
};

}; // namespace bullet_hell

#endif // BULLET_HELL_ENTITY_GEM_H
