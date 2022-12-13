//
// sprite.cc
//
// Sprite wrapper implementation.
//
// Copyright (c) 2022 The SFC Project Authors.
//
// SPDX-License-Identifier: GPL-3.0-only
//

#include "sprite.h"

#include <string>

#include <olcPixelGameEngine.h>

using namespace bullet_hell;

Sprite::Sprite()
{
}

Sprite::Sprite(const std::string& imageFilename, olc::ResourcePack* pack,
               bool setCenterPoint)
    : olc::Sprite(imageFilename, pack)
{
    decal = new olc::Decal(this);
    if (setCenterPoint) {
        centerPoint = {static_cast<float>(width) / 2.0f,
                       static_cast<float>(height) / 2.0f};
    }
}

bool Sprite::checkValidity() const
{
    return width > 0 && height > 0;
}
