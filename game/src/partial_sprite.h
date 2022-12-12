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

/// @brief Visual representation of an entity, using a partial decal with
/// multiple frames in a single image.
struct PartialSprite : Sprite {
    /// @brief Size of an individual frame in the sprite's image, in pixels.
    olc::vf2d frameSize;

    /// @brief Number of frames in the sprite's image.
    unsigned int frameCount;

    /// @brief Creates a new PartialSprite object.
    /// @param imageFilename Filename of the sprite's image.
    /// @param pack Resource pack from which to load the sprite's image.
    PartialSprite(const std::string& imageFilename,
                  olc::ResourcePack* pack = nullptr);
};

} // namespace bullet_hell

#endif // BULLET_HELL_PARTIAL_SPRITE_H
