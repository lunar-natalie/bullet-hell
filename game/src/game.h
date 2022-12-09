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

#include <filesystem>
#include <string>
#include <vector>

#include <olcPixelGameEngine.h>

#include "bullet.h"
#include "gem.h"
#include "resident_sprite.h"
#include "ship.h"
#include "shooter.h"

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

    ResidentSprite* createSprite(const std::string& filename) const;
    bool loadResourcePack();
    void createSprites();

    void addBullets(size_t count, olc::vf2d start);

    std::filesystem::path execPath;

    bool shouldReset;
    bool shouldExit;

    unsigned int screenWidth;
    unsigned int screenHeight;

    float timer;
    unsigned int frames;
    unsigned int fps;

    Ship* ship;
    std::vector<Bullet> bullets;
    std::vector<Shooter> shooters;
    std::vector<Gem> gems;

    float explosionTimer;
    unsigned int explosionFrames;
    unsigned int explosionFrameRate;

    olc::ResourcePack* resourcePack;
    ResidentSprite* backgroundSprite;
    ResidentSprite* explosionSprite;
};

} // namespace bullet_hell

#endif // BULLET_HELL_GAME_H
