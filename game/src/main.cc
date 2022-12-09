/*
 * main.cc
 *
 * Entry point to the Bullet Hell.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#define OLC_PGE_APPLICATION

#include <cstdlib>

#include <olcPixelGameEngine.h>

#include "config.h"
#include "game.h"

using namespace bullet_hell;

int main(int argc, char* argv[])
{
    Game game(argc, argv);
    if (game.Construct(config::WINDOW_WIDTH, config::WINDOW_HEIGHT, 1, 1)) {
        game.Start();
    }

    return EXIT_SUCCESS;
}
