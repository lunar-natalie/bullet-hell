/// @file game.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Base game methods.
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
