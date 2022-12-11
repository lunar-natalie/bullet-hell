/*
 * events.cc
 *
 * Event handlers.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "game.h"

#include <iostream>

using namespace bullet_hell;

bool Game::OnUserCreate()
{
    if (!loadResourcePack()) {
        std::cerr << "Failed to load resource pack." << std::endl;
        return false;
    }

    if (!createSprites()) {
        std::cerr << "Failed to load sprites." << std::endl;
        return false;
    }

    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    elapsedTime = fElapsedTime;

    input();
    process();
    draw();

    return !shouldExit;
}

bool Game::OnUserDestroy()
{
    std::cerr << "Closing game..." << std::endl;
    return true;
}
