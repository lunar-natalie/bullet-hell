//
// sprite.h
//
// Sprite wrapper.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#ifndef BULLET_HELL_SPRITE_H
#define BULLET_HELL_SPRITE_H

#include <string>

#include <olcPixelGameEngine.h>

namespace bullet_hell {

/// @brief Visual representation of an entity.
struct Sprite : olc::Sprite {
    /// @brief GPU-resident storage of the sprite's image.
    olc::Decal* decal;

    /// @brief The center point in pixels from which the sprite should be
    /// positioned on screen.
    olc::vf2d centerPoint;

    /// @brief Creates a new empty Sprite object.
    Sprite();

    /// @brief Creates a new Sprite object.
    /// @param imageFilename Filename of the sprite's image.
    /// @param pack Resource pack from which to load the sprite's image.
    /// @param setCenterPoint Set to `false` to prevent automatic calculation of
    /// the sprite's center point.
    Sprite(const std::string& imageFilename, olc::ResourcePack* pack = nullptr,
           bool setCenterPoint = true);

    /// @brief Checks if the sprite contains valid data.
    /// @return `true` if valid, otherwise `false`.
    bool checkValidity() const;
};

} // namespace bullet_hell

#endif // BULLET_HELL_SPRITE_H
