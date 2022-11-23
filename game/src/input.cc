/*
 * input.cc
 *
 * Input handler.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#include "game.h"
#include "config.h"

#include <iostream>
#include <olcPixelGameEngine.h>

using namespace bullet_hell;

void Game::input()
{
    shipAcceleration.x = 0;
    shipAcceleration.y = 0;
    if (GetKey(olc::Key::LEFT).bHeld) {
        shipAcceleration.x -= acceleration;
    }
    if (GetKey(olc::Key::RIGHT).bHeld) {
        shipAcceleration.x += acceleration;
    }
    if (GetKey(olc::Key::UP).bHeld) {
        shipAcceleration.y -= acceleration;
    }
    if (GetKey(olc::Key::DOWN).bHeld) {
        shipAcceleration.y += acceleration;
    }

    if (GetKey(olc::Key::R).bPressed) {
        shipAlive = true;
        shipVelocity = olc::vf2d{0, 0};
        shipPosition = olc::vf2d{((float) config::WINDOW_WIDTH) / 2,
                                 ((float) config::WINDOW_HEIGHT) - 100};
        explosionTimer = 0;
    }

    if (GetMouse(0).bHeld) {
        std::cout << "Click!" << std::endl;
    }
}
