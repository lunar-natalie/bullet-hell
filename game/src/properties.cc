/// @file properties.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Routines for setting game instance properties.
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
