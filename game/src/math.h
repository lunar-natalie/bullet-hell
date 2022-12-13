/// @file math.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Mathematical utilities.
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

#ifndef BULLET_HELL_MATH_H
#define BULLET_HELL_MATH_H

#include <cstdlib>

namespace bullet_hell::math {

constexpr const double PI = 3.14159265;
constexpr const double TWO_PI = 2 * PI;

/// @brief Generates a random number from 0 to 1 inclusive.
/// @return Number.
inline float randomMultiplier()
{
    return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
}

} // namespace bullet_hell::math

#endif // BULLET_HELL_MATH_H
