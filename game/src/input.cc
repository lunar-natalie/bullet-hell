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
#include "direction.h"

using namespace bullet_hell;

void Game::input()
{
    if (GetKey(olc::Key::R).bPressed) {
        shouldReset = true;
    }
    if (GetKey(olc::Key::ESCAPE).bPressed) {
        shouldExit = true;
    }

    if (GetKey(olc::Key::LEFT).bHeld) {
        ship->direction |= Direction::LEFT;
    }
    if (GetKey(olc::Key::RIGHT).bHeld) {
        ship->direction |= Direction::RIGHT;
    }
    if (GetKey(olc::Key::UP).bHeld) {
        ship->direction |= Direction::UP;
    }
    if (GetKey(olc::Key::DOWN).bHeld) {
        ship->direction |= Direction::DOWN;
    }

    ship->isFiring = GetKey(olc::Key::SPACE).bHeld;
}
