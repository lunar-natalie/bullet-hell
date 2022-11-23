/*
 * resident_sprite.cc
 *
 * Sprite wrapper methods.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#include "resident_sprite.h"

#include <string>

#include <olcPixelGameEngine.h>

using namespace bullet_hell;

ResidentSprite::ResidentSprite(const std::string& imageFileName,
                               olc::ResourcePack* pack)
    : olc::Sprite(imageFileName, pack)
{
    decal = new olc::Decal(this);
}
