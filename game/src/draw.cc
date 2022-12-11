/*
 * draw.cc
 *
 * Per-frame drawing routine.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

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
    SetPixelMode(olc::Pixel::NORMAL);

    DrawDecal({0.0f, 0.0f}, backgroundSprite->decal);

    float scale;
    olc::vf2d centerPoint;

    for (const auto& bullet : bullets) {
        draw(bullet, Bullet::sprite, 0.0333f);
    }

    for (const auto& plasma : plasmas) {
        draw(plasma, Plasma::sprite, 0.1333f);
    }

    for (const auto& shooter : shooters) {
        draw(shooter, Shooter::sprite, 0.0333f);
    }

    for (const auto& gem : gems) {
        drawHorizontalPartial(gem, Gem::sprite,
                              static_cast<unsigned int>(gem->type));
    }

    if (ship->isAlive) {
        draw(ship, Ship::sprite);
    }

    for (const auto& explosion : explosions) {
        unsigned int frameIndex = static_cast<unsigned int>(
            explosion->frameTimer * Explosion::frameRate);
        drawHorizontalPartial(explosion, Explosion::sprite, frameIndex);
    }

    if (fps > 0) {
        auto pos = olc::vf2d(static_cast<float>(screenWidth) - 70.0f,
                             static_cast<float>(screenHeight) - 70.0f);
        DrawStringDecal(pos, "FPS " + std::to_string(fps));
    }
}

void Game::draw(const Entity* entity, Sprite* sprite, float scale)
{
    DrawDecal(entity->position - (scale * sprite->centerPoint), sprite->decal,
              {scale, scale});
}

void Game::drawHorizontalPartial(const Entity* entity, PartialSprite* sprite,
                                 unsigned int frameIndex, float scale)
{
    DrawPartialDecal(
        entity->position - (scale * sprite->centerPoint), sprite->decal,
        {static_cast<float>(frameIndex) * sprite->frameSize.x, 0.0f},
        sprite->frameSize, {scale, scale});
}
