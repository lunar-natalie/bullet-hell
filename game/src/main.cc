/// @file main.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Game entry point.
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
