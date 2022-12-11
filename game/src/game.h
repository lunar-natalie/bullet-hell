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

#include <cstdint>

#include <filesystem>
#include <string>
#include <vector>

#include <olcPixelGameEngine.h>

#include "bullet.h"
#include "entity.h"
#include "explosion.h"
#include "gem.h"
#include "partial_sprite.h"
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
    void process();
    void draw();

    bool loadResourcePack();
    void createSprites();

    Sprite* createSprite(const std::string& filename) const;
    PartialSprite* createPartialSprite(const std::string& filename) const;

    void updateScreenDimensions();
    void updateFrameProperties();
    void reset();
    void spawnEntities();
    void updateShipTrajectory();
    void updateShipFire();
    void updateNonPlayerEntityTrajectories();

    bool checkCollision(const Entity* source, const Entity* target) const;
    bool checkBounds(const Entity* entity) const;

    void addBullets(unsigned int count, olc::vf2d start);

    void draw(const Entity* entity, Sprite* sprite, float scale = 1.0f);
    void drawHorizontalPartial(const Entity* entity, PartialSprite* sprite,
                               unsigned int frameIndex, float scale = 1.0f);

    std::filesystem::path execPath;

    bool shouldReset;
    bool shouldExit;
    bool shouldShowStats;

    int32_t screenWidth;
    int32_t screenHeight;

    float elapsedTime;
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
