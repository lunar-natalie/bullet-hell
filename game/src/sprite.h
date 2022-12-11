/*
 * sprite.h
 *
 * Sprite wrapper.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_SPRITE_H
#define BULLET_HELL_SPRITE_H

#include <string>

#include <olcPixelGameEngine.h>

namespace bullet_hell {

struct Sprite : olc::Sprite {
    olc::Decal* decal;
    olc::vf2d centerPoint;

    Sprite();

    Sprite(const std::string& imageFilename, olc::ResourcePack* pack = nullptr,
           bool setCenterPoint = true);

    bool checkValidity() const;
};

} // namespace bullet_hell

#endif // BULLET_HELL_SPRITE_H
