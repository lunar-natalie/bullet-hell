/// @file explosion.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Explosion entity implementation.
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

#include "explosion.h"

#include <olcPixelGameEngine.h>

#include "entity.h"
#include "partial_sprite.h"

using namespace bullet_hell;

PartialSprite* Explosion::sprite;
float Explosion::frameRate = 20.0f;

Explosion::Explosion(float x, float y, olc::vf2d scale)
    : Entity(x, y, scale),
      frameTimer{0.0f}
{
}

bool Explosion::update(float elapsedTime)
{
    frameTimer += elapsedTime;
    return frameTimer > static_cast<float>(sprite->frameCount) / frameRate;
}
