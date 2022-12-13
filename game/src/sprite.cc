/// @file sprite.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Sprite wrapper implementation.
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

#include "sprite.h"

#include <string>

#include <olcPixelGameEngine.h>

using namespace bullet_hell;

Sprite::Sprite()
{
}

Sprite::Sprite(const std::string& imageFilename, olc::ResourcePack* pack,
               bool setCenterPoint)
    : olc::Sprite(imageFilename, pack)
{
    decal = new olc::Decal(this);
    if (setCenterPoint) {
        centerPoint = {static_cast<float>(width) / 2.0f,
                       static_cast<float>(height) / 2.0f};
    }
}

bool Sprite::checkValidity() const
{
    return width > 0 && height > 0;
}

olc::vf2d Sprite::getSize() const
{
    return olc::vf2d{static_cast<float>(width), static_cast<float>(height)};
}
