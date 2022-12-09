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
    // Load resources from resource pack
    if (loadResourcePack()) {
        createSprites();
    }
    else {
        std::cerr << "Failed to load resource pack.";
    }

    // Set variables after GL initialization
    updateScreenDimensions();

    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    updateScreenDimensions();

    input();
    process(fElapsedTime);
    draw();

    return !shouldExit;
}

bool Game::OnUserDestroy()
{
    std::cerr << "Closing game..." << std::endl;
    return true;
}
