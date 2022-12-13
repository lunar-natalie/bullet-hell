/// @file sprite.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Sprite wrapper.
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

#ifndef BULLET_HELL_SPRITE_H
#define BULLET_HELL_SPRITE_H

#include <string>

#include <olcPixelGameEngine.h>

namespace bullet_hell {

/// @brief Graphical entity data.
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

    /// @brief Gets the unscaled dimensions of the sprite.
    /// @return x- and y-size vector.
    virtual olc::vf2d getSize() const;
};

} // namespace bullet_hell

#endif // BULLET_HELL_SPRITE_H
