/*
 * game.cc
 *
 * Game constructor.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

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
    sAppName = std::string(config::APP_NAME);

    execPath = std::filesystem::path();
    if (argc > 0) {
        execPath = std::filesystem::path(argv[0]);
    }

    shouldExit = false;
    shouldReset = true;

    timer = 0;
    frames = 0;

    ship = new Ship();
    ship->accelerationModifier = 3000.0f;
    ship->decelerationModifier = 7.5f;
    ship->maxSpeed = 1000.0f;

    bullets = std::vector<Bullet*>();
    shooters = std::vector<Shooter*>();
    gems = std::vector<Gem*>();
    explosions = std::vector<Explosion*>();
    plasmas = std::vector<Plasma*>();
}
