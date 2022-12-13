/// @file bullet.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Bullet entity implementation.
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

#include "bullet.h"

#include "moving_entity.h"
#include "sprite.h"

using namespace bullet_hell;

Sprite* Bullet::sprite;

Bullet::Bullet(float x, float y, float dx, float dy)
    : MovingEntity(x, y, dx, dy)
{
}
