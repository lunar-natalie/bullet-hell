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

#include "config.h"
#include "bullet.h"
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

    timer = 0;
    frames = 0;

    bullets = std::vector<Bullet>();
    shooters = std::vector<Shooter>();
    shooterSpawnTimer = 0;
    gemSpawnTimer = 0;

    shipVelocity = {0, 0};

    acceleration = 3000;
    deceleration = 7.5;
    maxSpeed = 1000;

    shipAlive = true;
    explosionTimer = 0;
    explosionFrames = 25;
    explosionFrameRate = 20;
}
