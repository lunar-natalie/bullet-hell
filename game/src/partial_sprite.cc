/*
 * partial_sprite.cc
 *
 * Implementation for sprite wrapper with partial decal.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "partial_sprite.h"

#include <string>

#include <olcPixelGameEngine.h>

using namespace bullet_hell;

PartialSprite::PartialSprite(const std::string& imageFilename,
                             olc::ResourcePack* pack)
    : Sprite(imageFilename, pack, false)
{
}
