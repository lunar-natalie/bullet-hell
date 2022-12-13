/// @file draw.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Frame drawing routines.
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

#include "game.h"

#include <olcPixelGameEngine.h>

#include "bullet.h"
#include "entity.h"
#include "explosion.h"
#include "gem.h"
#include "partial_sprite.h"
#include "plasma.h"
#include "ship.h"
#include "shooter.h"
#include "sprite.h"

using namespace bullet_hell;

void Game::draw()
{
    // Disable transparency.
    SetPixelMode(olc::Pixel::NORMAL);

    // Draw background.
    DrawDecal({0.0f, 0.0f}, backgroundSprite->decal);

    // Draw bullets.
    for (const auto& bullet : bullets) {
        draw(bullet, Bullet::sprite, 0.0333f);
    }

    // Draw plasmas.
    for (const auto& plasma : plasmas) {
        draw(plasma, Plasma::sprite, 0.1333f);
    }

    // Draw shooters.
    for (const auto& shooter : shooters) {
        draw(shooter, Shooter::sprite, 0.0333f);
    }

    // Draw gems, using each gem's type as the current frame to draw.
    for (const auto& gem : gems) {
        drawHorizontalPartial(gem, Gem::sprite,
                              static_cast<unsigned int>(gem->type));
    }

    // Draw ship.
    if (ship->isAlive) {
        draw(ship, Ship::sprite);
    }

    // Draw explosions, using each explosion's frame rate multiplied by the time
    // since the last frame was drawn as the current frame to draw.
    for (const auto& explosion : explosions) {
        unsigned int frameIndex = static_cast<unsigned int>(
            explosion->frameTimer * Explosion::frameRate);
        drawHorizontalPartial(explosion, Explosion::sprite, frameIndex);
    }

    // Draw frames per second text statistic.
    if (fps > 0) {
        auto pos = olc::vf2d(static_cast<float>(screenWidth) - 70.0f,
                             static_cast<float>(screenHeight) - 70.0f);
        DrawStringDecal(pos, "FPS " + std::to_string(fps));
    }
}

void Game::draw(const Entity* entity, Sprite* sprite, float scale)
{
    DrawDecal(
        entity->position - (scale * sprite->centerPoint), // Centered position
        sprite->decal, // GPU-resident storage member
        {scale, scale} // x- and y-scale
    );
}

void Game::drawHorizontalPartial(const Entity* entity, PartialSprite* sprite,
                                 unsigned int frameIndex, float scale)
{
    DrawPartialDecal(
        entity->position - (scale * sprite->centerPoint), // Centered position
        sprite->decal, // GPU-resident storage member
        {
            static_cast<float>(frameIndex)
                * sprite->frameSize.x, // x-offset from source
            0.0f                       // y-offset from source
        },
        sprite->frameSize, // Dimensions for region
        {scale, scale}     // x- and y-scale
    );
}
