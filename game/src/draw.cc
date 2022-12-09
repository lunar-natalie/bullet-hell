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

#include <cmath>
#include <cstddef>

#include <olcPixelGameEngine.h>

#include "bullet.h"
#include "explosion.h"
#include "gem.h"
#include "math.h"
#include "plasma.h"
#include "ship.h"
#include "shooter.h"

using namespace bullet_hell;

void Game::draw()
{
    SetPixelMode(olc::Pixel::NORMAL);

    DrawDecal(olc::vf2d(0, 0), backgroundSprite->decal);

    float scale = 0.0333;
    auto centrePoint = scale
                       * olc::vf2d{(float) Bullet::sprite->width / 2,
                                   (float) Bullet::sprite->height / 2};

    for (const auto& bullet : bullets) {
        DrawDecal(bullet->position - centrePoint, Bullet::sprite->decal,
                  olc::vf2d{scale, scale});
    }

    scale = 0.1333;
    centrePoint = scale
                  * olc::vf2d{(float) Plasma::sprite->width / 2,
                              (float) Plasma::sprite->height / 2};

    for (const auto& plasma : plasmas) {
        DrawDecal(plasma->position - centrePoint, Plasma::sprite->decal,
                  olc::vf2d{scale, scale});
    }

    scale = 0.0333;
    centrePoint = scale
                  * olc::vf2d{(float) Shooter::sprite->width / 2,
                              (float) Shooter::sprite->height / 2};

    for (const auto& shooter : shooters) {
        DrawDecal(shooter->position - centrePoint, Shooter::sprite->decal,
                  olc::vf2d{scale, scale});
    }

    scale = 1;
    float gemSize = (float) Gem::sprite->width / 4;
    centrePoint =
        scale * olc::vf2d{gemSize / 2, (float) Gem::sprite->height / 2};

    for (const auto& gem : gems) {
        DrawPartialDecal(
            gem->position - centrePoint, Gem::sprite->decal,
            olc::vf2d{static_cast<float>(gem->type) * gemSize, 0},
            olc::vf2d{gemSize * scale, Gem::sprite->height * scale});
    }

    if (ship->isAlive) {
        scale = 1;
        centrePoint = scale
                      * olc::vf2d{(float) Ship::sprite->width / 2,
                                  (float) Ship::sprite->height / 2};

        DrawDecal(ship->position - centrePoint, Ship::sprite->decal,
                  olc::vf2d{scale, scale});
    }

    for (const auto& explosion : explosions) {
        float explosionSize =
            (float) Explosion::sprite->width / Explosion::frameCount;
        int explosionFrame = explosion->timer * Explosion::frameRate;
        centrePoint = olc::vf2d{explosionSize / 2, explosionSize / 2};

        DrawPartialDecal(explosion->position - centrePoint,
                         olc::vf2d{explosionSize, explosionSize},
                         Explosion::sprite->decal,
                         olc::vf2d{explosionFrame * explosionSize, 0},
                         olc::vf2d{explosionSize, explosionSize});
    }

    if (fps > 0) {
        auto fpsPosition = olc::vi2d(screenWidth - 70, screenHeight - 70);
        DrawStringDecal(fpsPosition, "FPS " + std::to_string(fps));
    }
}
