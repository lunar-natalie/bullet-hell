/// @file entity.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Base entity implementation.
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

#include "entity.h"

#include <olcPixelGameEngine.h>

#include "sprite.h"

using namespace bullet_hell;

Entity::Entity()
    : scale{1.0f, 1.0f}
{
}

Entity::Entity(float x, float y, olc::vf2d scale)
    : position{x, y},
      scale{scale}
{
}

olc::vf2d Entity::getDisplayedSize(const Sprite* sprite) const
{
    return sprite->getSize() * scale;
}
