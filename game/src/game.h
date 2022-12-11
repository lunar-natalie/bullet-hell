/*
 * game.h
 *
 * Game class.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef BULLET_HELL_GAME_H
#define BULLET_HELL_GAME_H

#include <cstddef>
#include <cstdint>

#include <filesystem>
#include <string>
#include <vector>

#include <olcPixelGameEngine.h>

#include "bullet.h"
#include "explosion.h"
#include "gem.h"
#include "plasma.h"
#include "ship.h"
#include "shooter.h"
#include "sprite.h"

namespace bullet_hell {

class Game : public olc::PixelGameEngine {
public:
    Game(int argc, char* argv[]);

    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserDestroy() override;

private:
    void input();
    void process(float elapsedTime);
    void draw();

    void updateScreenDimensions();

    bool loadResourcePack();
    void createSprites();
    Sprite* createSprite(const std::string& filename) const;

    void addBullets(size_t count, olc::vf2d start);

    std::filesystem::path execPath;

    bool shouldReset;
    bool shouldExit;

    int32_t screenWidth;
    int32_t screenHeight;

    float frameTimer;
    unsigned int elapsedFrames;
    unsigned int fps;

    Ship* ship;
    std::vector<Bullet*> bullets;
    std::vector<Shooter*> shooters;
    std::vector<Gem*> gems;
    std::vector<Explosion*> explosions;
    std::vector<Plasma*> plasmas;

    olc::ResourcePack* resourcePack;
    Sprite* backgroundSprite;
};

} // namespace bullet_hell

#endif // BULLET_HELL_GAME_H
