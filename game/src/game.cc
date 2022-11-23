/*
 * game.cc
 *
 * Game constructor.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#include "game.h"
#include "config.h"
#include "entity/bullet.h"
#include "entity/shooter.h"

#include <filesystem>
#include <vector>

using namespace bullet_hell;

Game::Game(int argc, char* argv[])
{
    sAppName = std::string(config::APP_NAME);

    execPath = std::filesystem::path();
    if (argc > 0) {
        execPath = std::filesystem::path(argv[0]);
    }

    timer = 0;
    frames = 0;

    bullets = std::vector<Bullet>();
    shooters = std::vector<Shooter>();
    shooterSpawnTimer = 0;
    gemSpawnTimer = 0;

    shipPosition = {((float) config::WINDOW_WIDTH) / 2,
                    ((float) config::WINDOW_HEIGHT) - 100};
    shipVelocity = {0, 0};

    acceleration = 3000;
    deceleration = 7.5;
    maxSpeed = 1000;

    shipAlive = true;
    explosionTimer = 0;
    explosionFrames = 25;
    explosionFrameRate = 20;
}
