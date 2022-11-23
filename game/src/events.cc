/*
 * events.cc
 *
 * Event handlers.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#include "game.h"

#include <cstdlib>

#include <filesystem>
#include <iostream>
#include <string>
#include <system_error>

#include <olcPixelGameEngine.h>

#include "config.h"
#include "resources.h"

using namespace bullet_hell;

bool Game::OnUserCreate()
{
    // Load resources

    resourcePack = new olc::ResourcePack();
    std::filesystem::path resourcePackPath;
    std::error_code pathError;
    auto currentPath = std::filesystem::current_path(pathError);
    // Try working directory
    resourcePackPath = currentPath.append(config::RESOURCE_PACK_FILENAME);
    if (!std::filesystem::exists(resourcePackPath)) {
        // Try parent directory of executable
        resourcePackPath =
            execPath.parent_path().append(config::RESOURCE_PACK_FILENAME);
        if (!std::filesystem::exists(resourcePackPath)) {
            // Try system data directory
            resourcePackPath = std::filesystem::path(config::DATA_DIR)
                                   .append(config::RESOURCE_PACK_FILENAME);
        }
    }

    if (std::filesystem::exists(resourcePackPath)) {
        resourcePack->LoadPack(resourcePackPath.string(), "");
    } else {
        std::cerr << "Failed to load resource pack.";
    }

    backgroundSprite = createSprite(resources::image::BACKGROUND);
    bulletSprite = createSprite(resources::image::BULLET);
    shooterSprite = createSprite(resources::image::SHOOTER);
    shipSprite = createSprite(resources::image::SHIP);
    explosionSprite = createSprite(resources::image::EXPLOSION);
    gemSprite = createSprite(resources::image::GEMS);

    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    timer += fElapsedTime;
    ++frames;
    if (timer > 1.0) {
        fps = frames;
        frames = 0;
        timer -= 1;
        std::cout << shooters.size() << " shooters, " << bullets.size()
                  << " bullets, " << gems.size() << " gems." << std::endl;
    }

    shooterSpawnTimer -= fElapsedTime;
    if (shooterSpawnTimer < 0) {
        shooterSpawnTimer += 2;
        shooters.push_back(
            Shooter(((float) rand() / (float) RAND_MAX) * config::WINDOW_WIDTH,
                    -20, 0, 50, 0.25, 10));
    }

    gemSpawnTimer -= fElapsedTime;
    if (gemSpawnTimer < 0) {
        gemSpawnTimer += 0.5;
        gems.push_back(
            Gem(((float) rand() / (float) RAND_MAX) * config::WINDOW_HEIGHT,
                -20, 0, 100, rand() % 4));
    }

    input();
    process(fElapsedTime);
    draw();

    if (GetKey(olc::Key::ESCAPE).bPressed) {
        return false;
    } else {
        return true;
    }
}

bool Game::OnUserDestroy()
{
    std::cout << "Closing game..." << std::endl;
    return true;
}
