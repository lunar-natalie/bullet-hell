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
    if (loadResourcePack()) {
        createSprites();
    }
    else {
        std::cerr << "Failed to load resource pack.";
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
