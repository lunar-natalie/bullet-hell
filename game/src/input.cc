/*
 * input.cc
 *
 * Per-frame input handler.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "game.h"

#include <iostream>

#include <olcPixelGameEngine.h>

#include "config.h"

using namespace bullet_hell;

void Game::input()
{
    if (GetKey(olc::Key::ESCAPE).bPressed) {
        shouldExit = true;
    }

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
        resetShipPosition();
        explosionTimer = 0;
    }

    if (GetMouse(0).bHeld) {
        std::cout << "Click!" << std::endl;
    }
}
