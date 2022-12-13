/// @file shooter.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Shooter entity implementation.
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

#include "shooter.h"

#include "moving_entity.h"
#include "sprite.h"

using namespace bullet_hell;

Sprite* Shooter::sprite;
float Shooter::spawnTimer;
float Shooter::spawnInterval = 2.0f;
float Shooter::startY = -20.0f;
float Shooter::defaultXVelocity = 0.0f;
float Shooter::defaultYVelocity = 50.0f;
float Shooter::defaultFireRate = 0.25f;
unsigned int Shooter::defaultFireCount = 10;

Shooter::Shooter(float x, float y, float dx, float dy, float fireRate,
                 unsigned int fireCount)
    : MovingEntity(x, y, dx, dy),
      fireRate{fireRate},
      fireCount{fireCount}
{
    fireTimer = 1.0f / fireRate;
}
