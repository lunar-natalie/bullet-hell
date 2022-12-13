/// @file partial_sprite.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Sprite wrapper with partial decal.
///
/// @section LICENSE
///
/// Copyright (c) 2022 The SFC Project Authors.
///
/// This program is free software: you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with this program. If not, see <https://www.gnu.org/licenses/>.

#ifndef BULLET_HELL_PARTIAL_SPRITE_H
#define BULLET_HELL_PARTIAL_SPRITE_H

#include <string>

#include <olcPixelGameEngine.h>

#include "sprite.h"

namespace bullet_hell {

/// @brief Representation of a visual game object and its internal attributes,
/// using a partial decal containing multiple frames within a single image.
struct PartialSprite : Sprite {
    /// @brief Size in pixels of an individual frame in the sprite's image.
    olc::vf2d frameSize;

    /// @brief Number of frames in the sprite's image.
    unsigned int frameCount;

    /// @brief Creates a new PartialSprite object.
    /// @param imageFilename Filename of the sprite's image.
    /// @param pack Resource pack from which to load the sprite's image.
    PartialSprite(const std::string& imageFilename,
                  olc::ResourcePack* pack = nullptr);

    /// @brief Gets the unscaled dimensions of the sprite.
    /// @return x- and y-size vector.
    virtual olc::vf2d getSize() const override;
};

} // namespace bullet_hell

#endif // BULLET_HELL_PARTIAL_SPRITE_H
