//
// entity.h
//
// Base position-only entity object.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#ifndef BULLET_HELL_ENTITY_H
#define BULLET_HELL_ENTITY_H

#include <olcPixelGameEngine.h>

namespace bullet_hell {

/// @brief Representation of a visible object in the game.
struct Entity {
    /// @brief Position of the object in the screen, in pixels.
    olc::vf2d position;

    /// @brief Creates a new empty Entity object.
    Entity();

    /// @brief Creates a new Entity object.
    /// @param x x-position in pixels.
    /// @param y y-position in pixels.
    Entity(float x, float y);
};

} // namespace bullet_hell

#endif // BULLET_HELL_ENTITY_H
