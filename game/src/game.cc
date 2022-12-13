//
// game.cc
//
// Game constructor.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#include "game.h"

#include <filesystem>
#include <vector>

#include "bullet.h"
#include "config.h"
#include "explosion.h"
#include "gem.h"
#include "plasma.h"
#include "ship.h"
#include "shooter.h"

using namespace bullet_hell;

Game::Game(int argc, char* argv[])
{
    // Name displayed in the window titlebar.
    sAppName = std::string(config::APP_NAME);

    // Get path to executable. Used as a fallback for finding the resource pack.
    execPath = std::filesystem::path();
    if (argc > 0) {
        execPath = std::filesystem::path(argv[0]);
    }

    // Set initial flags before the update routine.
    shouldExit = false;
    shouldReset = true;

    // Create entity storage.
    ship = new Ship();
    bullets = std::vector<Bullet*>();
    shooters = std::vector<Shooter*>();
    gems = std::vector<Gem*>();
    explosions = std::vector<Explosion*>();
    plasmas = std::vector<Plasma*>();
}
