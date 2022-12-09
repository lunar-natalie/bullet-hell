/*
 * loader.cc
 *
 * Utilities for loading resources into the game instance.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "game.h"

#include <filesystem>
#include <string>
#include <system_error>

#include <olcPixelGameEngine.h>

#include "bullet.h"
#include "config.h"
#include "explosion.h"
#include "gem.h"
#include "plasma.h"
#include "resident_sprite.h"
#include "resources.h"
#include "ship.h"
#include "shooter.h"

using namespace bullet_hell;

bool Game::loadResourcePack()
{
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
        return true;
    }

    return false;
}

void Game::createSprites()
{
    backgroundSprite = createSprite(resources::image::BACKGROUND);
    Bullet::sprite = createSprite(resources::image::BULLET);
    Shooter::sprite = createSprite(resources::image::SHOOTER);
    Ship::sprite = createSprite(resources::image::SHIP);
    Explosion::sprite = createSprite(resources::image::EXPLOSION);
    Gem::sprite = createSprite(resources::image::GEMS);
    Plasma::sprite = createSprite(resources::image::PLASMA);

    Explosion::frameCount = 25;
}

ResidentSprite* Game::createSprite(const std::string& filename) const
{
    return new ResidentSprite(filename, resourcePack);
}
