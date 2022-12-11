/*
 * partial_sprite.h
 *
 * Sprite wrapper with partial decal.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_PARTIAL_SPRITE_H
#define BULLET_HELL_PARTIAL_SPRITE_H

#include <string>

#include <olcPixelGameEngine.h>

#include "sprite.h"

namespace bullet_hell {

struct PartialSprite : Sprite {
    olc::vf2d frameSize;
    unsigned int frameCount;

    PartialSprite(const std::string& imageFilename,
                  olc::ResourcePack* pack = nullptr);
};

} // namespace bullet_hell

#endif // BULLET_HELL_PARTIAL_SPRITE_H
