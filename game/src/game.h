/*
 * game.h
 *
 * Game class.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef BULLET_HELL_GAME_H
#define BULLET_HELL_GAME_H

#include "entity/bullet.h"
#include "entity/gem.h"
#include "entity/shooter.h"

#include <filesystem>
#include <olcPixelGameEngine.h>
#include <vector>

namespace bullet_hell {

class Game : public olc::PixelGameEngine {
public:
    Game(int argc, char* argv[]);

    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserDestroy() override;

    void input();
    void process(float elapsedTime);
    void draw();

private:
    void addBullets(size_t count, olc::vf2d start);

    std::filesystem::path execPath;
    olc::ResourcePack* resourcePack;

    float timer;
    unsigned int frames;
    unsigned int fps;

    std::vector<Bullet> bullets;
    std::vector<Shooter> shooters;
    float shooterSpawnTimer;

    std::vector<Gem> gems;
    float gemSpawnTimer;

    olc::vf2d shipPosition;
    olc::vf2d shipVelocity;
    olc::vf2d shipAcceleration;

    float acceleration;
    float deceleration;
    float maxSpeed;

    bool shipAlive;
    float explosionTimer;
    unsigned int explosionFrames;
    unsigned int explosionFrameRate;

    olc::Sprite* backgroundSprite;
    olc::Decal* backgroundDecal;

    olc::Sprite* bulletSprite;
    olc::Decal* bulletDecal;

    olc::Sprite* shooterSprite;
    olc::Decal* shooterDecal;

    olc::Sprite* shipSprite;
    olc::Decal* shipDecal;

    olc::Sprite* explosionSprite;
    olc::Decal* explosionDecal;

    olc::Sprite* gemSprite;
    olc::Decal* gemDecal;
};

}; // namespace bullet_hell

#endif // BULLET_HELL_GAME_H
