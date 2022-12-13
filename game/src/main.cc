//
// main.cc
//
// Entry point to the Bullet Hell.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#define OLC_PGE_APPLICATION

#include <cstdlib>

#include <olcPixelGameEngine.h>

#include "config.h"
#include "game.h"

using namespace bullet_hell;

int main(int argc, char* argv[])
{
    // Create the game instance using the program arguments before calling the
    // engine routines.
    Game* game = new Game(argc, argv);

    // Construct window and prepare engine internals.
    if (game->Construct(config::WINDOW_WIDTH, config::WINDOW_HEIGHT, 1, 1)) {
        // Create window, create context for internal rendering, and start the
        // main game thread.
        game->Start();
    }

    return EXIT_SUCCESS;
}
