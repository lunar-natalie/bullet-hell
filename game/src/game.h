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

#include <cstddef>

#include <filesystem>
#include <string>
#include <vector>

#include <olcPixelGameEngine.h>

#include "entity/bullet.h"
#include "entity/gem.h"
#include "entity/shooter.h"
#include "resident_sprite.h"

namespace bullet_hell {

class Game : public olc::PixelGameEngine {
public:
    Game(int argc, char* argv[]);

    // OLC Game engine methods
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserDestroy() override;

private:
    // Main processing
    void input();
    void process(float elapsedTime);
    void draw();

    // Update properties
    void updateScreenDimensions();
    void resetShipPosition();

    // Resource methods
    ResidentSprite* createSprite(const std::string& filename) const;
    bool loadResourcePack();
    void createSprites();

    // Entity creation
    void addBullets(size_t count, olc::vf2d start);

    // Application variables
    std::filesystem::path execPath;

    bool shouldExit;

    unsigned int screenWidth;
    unsigned int screenHeight;

    float timer;
    unsigned int frames;
    unsigned int fps;

    // Game variables
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

    // Rsources
    olc::ResourcePack* resourcePack;
    ResidentSprite* backgroundSprite;
    ResidentSprite* bulletSprite;
    ResidentSprite* shooterSprite;
    ResidentSprite* shipSprite;
    ResidentSprite* explosionSprite;
    ResidentSprite* gemSprite;
};

}; // namespace bullet_hell

#endif // BULLET_HELL_GAME_H
