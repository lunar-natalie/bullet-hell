/*
 * math.h
 *
 * Mathematical definitions.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

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
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

} // namespace bullet_hell::math

#endif // BULLET_HELL_MATH_H
