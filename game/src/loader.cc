/// @file loader.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Utilities for loading resources into the game instance.
///
/// @section LICENSE
///
/// Copyright (c) 2022 The SFC Project Authors.
///
/// This program is free software: you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with this program. If not, see <https://www.gnu.org/licenses/>.

#include "game.h"

#include <filesystem>
#include <string>
#include <system_error>

#include <olcPixelGameEngine.h>

#include "bullet.h"
#include "config.h"
#include "explosion.h"
#include "gem.h"
#include "partial_sprite.h"
#include "plasma.h"
#include "resources.h"
#include "ship.h"
#include "shooter.h"
#include "sprite.h"

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

bool Game::createSprites()
{
    // Create new sprite objects for all entities and visual objects.

    backgroundSprite = createSprite(resources::image::BACKGROUND);
    Bullet::sprite = createSprite(resources::image::BULLET);
    Shooter::sprite = createSprite(resources::image::SHOOTER);
    Ship::sprite = createSprite(resources::image::SHIP);
    Explosion::sprite = createPartialSprite(resources::image::EXPLOSION);
    Gem::sprite = createPartialSprite(resources::image::GEMS);
    Plasma::sprite = createSprite(resources::image::PLASMA);

    // Set required properties for all partial sprites.

    Explosion::sprite->frameCount = 25;
    Explosion::sprite->frameSize = {
        static_cast<float>(Explosion::sprite->width)
            / static_cast<float>(Explosion::sprite->frameCount),
        static_cast<float>(Explosion::sprite->height)};
    Explosion::sprite->centerPoint = Explosion::sprite->frameSize / 2.0f;

    Gem::sprite->frameCount = Gem::typeCount;
    Gem::sprite->frameSize = {static_cast<float>(Gem::sprite->width)
                                  / static_cast<float>(Gem::sprite->frameCount),
                              static_cast<float>(Gem::sprite->height)};
    Gem::sprite->centerPoint = Gem::sprite->frameSize / 2.0f;

    // Check data is valid.

    std::vector<Sprite*> allSprites = {Bullet::sprite, Shooter::sprite,
                                       Ship::sprite,   Explosion::sprite,
                                       Gem::sprite,    Plasma::sprite};

    for (const auto& sprite : allSprites) {
        if (!sprite->checkValidity()) {
            return false;
        }
    }

    return true;
}

Sprite* Game::createSprite(const std::string& filename) const
{
    return new Sprite(filename, resourcePack);
}

PartialSprite* Game::createPartialSprite(const std::string& filename) const
{
    return new PartialSprite(filename, resourcePack);
}
