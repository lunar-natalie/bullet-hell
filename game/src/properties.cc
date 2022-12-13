//
// properties.cc
//
// Routines for setting miscellaneous properties on the game instance.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#include "game.h"

#include <olcPixelGameEngine.h>

using namespace bullet_hell;

void Game::updateScreenDimensions()
{
    screenWidth = ScreenWidth();
    screenHeight = ScreenHeight();
}

void Game::updateFrameProperties()
{
    shouldShowStats = false;
    frameTimer += elapsedTime;
    ++elapsedFrames;
    if (frameTimer > 1.0f) {
        shouldShowStats = true;
        fps = elapsedFrames;
        elapsedFrames = 0;
        --frameTimer;
    }
}
