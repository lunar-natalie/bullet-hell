/// @file input.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Frame input handler.
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

#include <olcPixelGameEngine.h>

#include "direction.h"

using namespace bullet_hell;

void Game::input()
{
    if (GetKey(olc::Key::R).bPressed) {
        shouldReset = true;
    }
    if (GetKey(olc::Key::ESCAPE).bPressed) {
        shouldExit = true;
    }

    if (GetKey(olc::Key::LEFT).bHeld) {
        ship->direction |= Direction::LEFT;
    }
    if (GetKey(olc::Key::RIGHT).bHeld) {
        ship->direction |= Direction::RIGHT;
    }
    if (GetKey(olc::Key::UP).bHeld) {
        ship->direction |= Direction::UP;
    }
    if (GetKey(olc::Key::DOWN).bHeld) {
        ship->direction |= Direction::DOWN;
    }

    ship->isFiring = GetKey(olc::Key::SPACE).bHeld;
}
