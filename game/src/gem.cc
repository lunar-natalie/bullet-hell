/// @file gem.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Gem entity implementation.
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

#include "gem.h"

#include <cstdlib>

#include <olcPixelGameEngine.h>

#include "moving_entity.h"
#include "partial_sprite.h"

using namespace bullet_hell;

PartialSprite* Gem::sprite;
float Gem::spawnTimer;
float Gem::spawnInterval = 0.5f;
float Gem::startY = -20.0f;
float Gem::defaultXVelocity = 0.0f;
float Gem::defaultYVelocity = 100.0f;

Gem::Gem(float x, float y, float dx, float dy, Type type, olc::vf2d scale)
    : MovingEntity(x, y, dx, dy, scale),
      type{type}
{
}

Gem::Type Gem::randomType()
{
    return static_cast<Type>(rand() % typeCount);
}
