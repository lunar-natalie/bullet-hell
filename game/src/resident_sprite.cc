/*
 * resident_sprite.cc
 *
 * Sprite wrapper methods.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include "resident_sprite.h"

#include <string>

#include <olcPixelGameEngine.h>

using namespace bullet_hell;

ResidentSprite::ResidentSprite(const std::string& imageFilename,
                               olc::ResourcePack* pack)
    : olc::Sprite(imageFilename, pack)
{
    decal = new olc::Decal(this);
}
