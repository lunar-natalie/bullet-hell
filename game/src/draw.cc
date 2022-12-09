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

#include "math.h"

using namespace bullet_hell;

void Game::draw()
{
    SetPixelMode(olc::Pixel::NORMAL);

    DrawDecal(olc::vf2d(0, 0), backgroundSprite->decal);

    float scale = 0.0333;
    auto centrePoint = scale
                       * olc::vf2d{(float) bulletSprite->width / 2,
                                   (float) bulletSprite->height / 2};

    for (const auto& bullet : bullets) {
        DrawDecal(bullet.position - centrePoint, bulletSprite->decal,
                  olc::vf2d{scale, scale});
    }

    scale = 0.0333;
    centrePoint = scale
                  * olc::vf2d{(float) shooterSprite->width / 2,
                              (float) shooterSprite->height / 2};

    for (const auto& shooter : shooters) {
        DrawDecal(shooter.position - centrePoint, shooterSprite->decal,
                  olc::vf2d{scale, scale});
    }

    scale = 1;
    float gemSize = (float) gemSprite->width / 4;
    centrePoint = scale * olc::vf2d{gemSize / 2, (float) gemSprite->height / 2};

    for (const auto& gem : gems) {
        DrawPartialDecal(gem.position - centrePoint, gemSprite->decal,
                         olc::vf2d{gem.type * gemSize, 0},
                         olc::vf2d{gemSize * scale, gemSprite->height * scale});
    }

    if (shipAlive) {
        scale = 1;
        centrePoint = scale
                      * olc::vf2d{(float) shipSprite->width / 2,
                                  (float) shipSprite->height / 2};

        DrawDecal(shipPosition - centrePoint, shipSprite->decal,
                  olc::vf2d{scale, scale});
    } else if (explosionTimer < explosionFrames / explosionFrameRate) {
        float explosionSize = (float) explosionSprite->width / explosionFrames;
        int explosionFrame = explosionTimer * explosionFrameRate;
        centrePoint = olc::vf2d{explosionSize / 2, explosionSize / 2};

        DrawPartialDecal(shipPosition - centrePoint,
                         olc::vf2d{explosionSize, explosionSize},
                         explosionSprite->decal,
                         olc::vf2d{explosionFrame * explosionSize, 0},
                         olc::vf2d{explosionSize, explosionSize});
    }

    if (fps > 0) {
        auto fpsPosition = olc::vi2d(screenWidth - 70, screenHeight - 70);
        DrawStringDecal(fpsPosition, "FPS " + std::to_string(fps));
    }
}
