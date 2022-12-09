/*
 * direction.h
 *
 * Direction control flags.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_DIRECTION_H
#define BULLET_HELL_DIRECTION_H

#include <type_traits>

namespace bullet_hell {

enum class Direction {
    NONE = 0,
    LEFT = 1,
    RIGHT = 2,
    UP = 4,
    DOWN = 8
};

inline constexpr void operator|=(Direction& a, const Direction& b) noexcept
{
    typedef std::underlying_type<Direction>::type Value;
    a = static_cast<Direction>(static_cast<Value>(a) | static_cast<Value>(b));
}

inline constexpr bool operator&(const Direction& a, const Direction& b) noexcept
{
    typedef std::underlying_type<Direction>::type Value;
    return static_cast<Direction>(static_cast<Value>(a) & static_cast<Value>(b))
           == b;
}

} // namespace bullet_hell

#endif // BULLET_HELL_DIRECTION_H
