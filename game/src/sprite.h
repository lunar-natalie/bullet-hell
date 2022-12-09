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

struct Sprite : public olc::Sprite {
    olc::Decal* decal;

    Sprite(const std::string& imageFilename, olc::ResourcePack* pack = nullptr);
};

} // namespace bullet_hell

#endif // BULLET_HELL_SPRITE_H
