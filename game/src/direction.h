/// @file direction.h
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Direction flags for controllable entities.
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

#ifndef BULLET_HELL_DIRECTION_H
#define BULLET_HELL_DIRECTION_H

#include <type_traits>

namespace bullet_hell {

/// @brief Direction bit flags.
enum class Direction {
    NONE = 0,
    LEFT = 1,
    RIGHT = 2,
    UP = 4,
    DOWN = 8
};

/// @brief Sets Direction `rhs` in the bit flags of Direction `lhs`.
/// @param lhs lvalue.
/// @param rhs rvalue.
inline constexpr void operator|=(Direction& lhs, const Direction& rhs) noexcept
{
    typedef std::underlying_type<Direction>::type Value;
    lhs = static_cast<Direction>(static_cast<Value>(lhs)
                                 | static_cast<Value>(rhs));
}

/// @brief Checks if Direction `rhs` is set in the bit flags of Direction `lhs`.
/// @param lhs Direction in which to check if `rhs` is set.
/// @param rhs Direction to check for.
/// @return `true` if Direction `rhs` is set in Direction `lhs`, otherwise
/// `false`.
inline constexpr bool operator&(const Direction& lhs,
                                const Direction& rhs) noexcept
{
    typedef std::underlying_type<Direction>::type Value;
    return static_cast<Direction>(static_cast<Value>(lhs)
                                  & static_cast<Value>(rhs))
           == rhs;
}

} // namespace bullet_hell

#endif // BULLET_HELL_DIRECTION_H
