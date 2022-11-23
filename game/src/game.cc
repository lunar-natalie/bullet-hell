/*
 * game.h
 *
 * Main game handler.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: MIT
 */

#include "game.h"
#include "config.h"
#include "entity/bullet.h"
#include "entity/shooter.h"
#include "math.h"

#include <cmath>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <olcPixelGameEngine.h>
#include <string>
#include <vector>

using namespace bullet_hell;

Game::Game(int argc, char* argv[])
{
    sAppName = std::string(config::APP_NAME);

    execPath = std::filesystem::path();
    if (argc > 0) {
        execPath = std::filesystem::path(argv[0]);
    }

    timer = 0;
    frames = 0;

    bullets = std::vector<Bullet>();
    shooters = std::vector<Shooter>();
    shooterSpawnTimer = 0;
    gemSpawnTimer = 0;

    shipPosition = {((float) config::WINDOW_WIDTH) / 2,
                    ((float) config::WINDOW_HEIGHT) - 100};
    shipVelocity = {0, 0};

    acceleration = 3000;
    deceleration = 7.5;
    maxSpeed = 1000;

    shipAlive = true;
    explosionTimer = 0;
    explosionFrames = 25;
    explosionFrameRate = 20;
}

bool Game::OnUserCreate()
{
    // Load resources

    resourcePack = new olc::ResourcePack();
    std::filesystem::path resourcePackPath;
    std::error_code pathError;
    auto currentPath = std::filesystem::current_path(pathError);
    // Try working directory
    resourcePackPath = currentPath.append(config::RESOURCE_PACK_FILENAME);
    if (!std::filesystem::exists(resourcePackPath)) {
        // Try parent directory of executable
        resourcePackPath =
            execPath.parent_path().append(config::RESOURCE_PACK_FILENAME);
        if (!std::filesystem::exists(resourcePackPath)) {
            // Try system data directory
            resourcePackPath = std::filesystem::path(config::DATA_DIR)
                                   .append(config::RESOURCE_PACK_FILENAME);
        }
    }

    if (std::filesystem::exists(resourcePackPath)) {
        resourcePack->LoadPack(resourcePackPath.string(), "");
    } else {
        std::cerr << "Failed to load resource pack.";
    }

    backgroundSprite = new olc::Sprite("background.png", resourcePack);
    backgroundDecal = new olc::Decal(backgroundSprite);

    bulletSprite = new olc::Sprite("bullet.png", resourcePack);
    bulletDecal = new olc::Decal(bulletSprite);

    shooterSprite = new olc::Sprite("shooter.png", resourcePack);
    shooterDecal = new olc::Decal(shooterSprite);

    shipSprite = new olc::Sprite("ship.png", resourcePack);
    shipDecal = new olc::Decal(shipSprite);

    explosionSprite = new olc::Sprite("explosion.png", resourcePack);
    explosionDecal = new olc::Decal(explosionSprite);

    gemSprite = new olc::Sprite("gems.png", resourcePack);
    gemDecal = new olc::Decal(gemSprite);

    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    timer += fElapsedTime;
    ++frames;
    if (timer > 1.0) {
        fps = frames;
        frames = 0;
        timer -= 1;
        std::cout << shooters.size() << " shooters, " << bullets.size()
                  << " bullets, " << gems.size() << " gems." << std::endl;
    }

    shooterSpawnTimer -= fElapsedTime;
    if (shooterSpawnTimer < 0) {
        shooterSpawnTimer += 2;
        shooters.push_back(
            Shooter(((float) rand() / (float) RAND_MAX) * config::WINDOW_WIDTH,
                    -20, 0, 50, 0.25, 10));
    }

    gemSpawnTimer -= fElapsedTime;
    if (gemSpawnTimer < 0) {
        gemSpawnTimer += 0.5;
        gems.push_back(
            Gem(((float) rand() / (float) RAND_MAX) * config::WINDOW_HEIGHT,
                -20, 0, 100, rand() % 4));
    }

    input();
    process(fElapsedTime);
    draw();

    if (GetKey(olc::Key::ESCAPE).bPressed) {
        return false;
    } else {
        return true;
    }
}

void Game::input()
{
    // Check game controls

    shipAcceleration.x = 0;
    shipAcceleration.y = 0;
    if (GetKey(olc::Key::LEFT).bHeld) {
        shipAcceleration.x -= acceleration;
    }
    if (GetKey(olc::Key::RIGHT).bHeld) {
        shipAcceleration.x += acceleration;
    }
    if (GetKey(olc::Key::UP).bHeld) {
        shipAcceleration.y -= acceleration;
    }
    if (GetKey(olc::Key::DOWN).bHeld) {
        shipAcceleration.y += acceleration;
    }

    if (GetKey(olc::Key::R).bPressed) {
        shipAlive = true;
        shipVelocity = olc::vf2d{0, 0};
        shipPosition = olc::vf2d{((float) config::WINDOW_WIDTH) / 2,
                                 ((float) config::WINDOW_HEIGHT) - 100};
        explosionTimer = 0;
    }

    if (GetMouse(0).bHeld) {
        std::cout << "Click!" << std::endl;
    }
}

void Game::process(float elapsedTime)
{
    // Run game logic

    if (shipAlive) {
        shipVelocity += elapsedTime * shipAcceleration;

        shipVelocity *= 1 - elapsedTime * deceleration;

        if (shipVelocity.x < -maxSpeed) {
            shipVelocity.x = -maxSpeed;
        }
        if (shipVelocity.y < -maxSpeed) {
            shipVelocity.y = -maxSpeed;
        }
        if (shipVelocity.x > maxSpeed) {
            shipVelocity.x = maxSpeed;
        }
        if (shipVelocity.y > maxSpeed) {
            shipVelocity.y = maxSpeed;
        }
        shipPosition += elapsedTime * shipVelocity;

        if (shipPosition.x < 25) {
            shipPosition.x = 25;
            shipVelocity.x = 0;
        }
        if (shipPosition.y < 25) {
            shipPosition.y = 25;
            shipVelocity.y = 0;
        }
        if (shipPosition.x > config::WINDOW_WIDTH - 25) {
            shipPosition.x = config::WINDOW_WIDTH - 25;
            shipVelocity.x = 0;
        }
        if (shipPosition.y > config::WINDOW_HEIGHT - 25) {
            shipPosition.y = config::WINDOW_HEIGHT - 25;
            shipVelocity.y = 0;
        }
    } else {
        explosionTimer += elapsedTime;
    }

    for (auto& bullet : bullets) {
        bullet.position += elapsedTime * bullet.velocity;
    }

    for (auto& gem : gems) {
        gem.position += elapsedTime * gem.velocity;
    }

    for (auto i = 0; i < bullets.size();) {
        bool shipHit = pow(shipPosition.x - bullets[i].position.x, 2)
                           + pow(shipPosition.y - bullets[i].position.y, 2)
                       < pow(25, 2);

        if (shipHit) {
            shipAlive = false;
        }

        if (shipHit || bullets[i].position.x < -20
            || bullets[i].position.y < -20
            || bullets[i].position.x > config::WINDOW_WIDTH + 20
            || bullets[i].position.y > config::WINDOW_HEIGHT + 20) {
            bullets.erase(bullets.begin() + i);
        } else {
            ++i;
        }
    }

    for (auto i = 0; i < gems.size();) {
        bool shipHit = pow(shipPosition.x - gems[i].position.x, 2)
                           + pow(shipPosition.y - gems[i].position.y, 2)
                       < pow(30, 2);

        if (shipHit || gems[i].position.x < -20 || gems[i].position.y < -20
            || gems[i].position.x > config::WINDOW_WIDTH + 20
            || gems[i].position.y > config::WINDOW_HEIGHT + 20) {
            gems.erase(gems.begin() + i);
        } else {
            ++i;
        }
    }

    for (auto& shooter : shooters) {
        shooter.position += elapsedTime * shooter.velocity;
        shooter.timer -= elapsedTime;
        if (shooter.timer < 0) {
            shooter.timer += 1.0f / shooter.fireRate;
            addBullets(shooter.fireCount, shooter.position);
        }
    }

    for (auto i = 0; i < shooters.size();) {
        if (shooters[i].position.x < -20 || shooters[i].position.y < -20
            || shooters[i].position.x > config::WINDOW_WIDTH + 20
            || shooters[i].position.y > config::WINDOW_HEIGHT + 20) {
            shooters.erase(shooters.begin() + i);
        } else {
            ++i;
        }
    }
}

void Game::addBullets(size_t count, olc::vf2d start)
{
    float offset = math::TWO_PI * ((float) rand() / (float) RAND_MAX);
    for (auto i = 0; i < count; ++i) {
        const double x = (math::TWO_PI * ((double) i / count)) + offset;
        bullets.push_back(Bullet(start.x, start.y, 100 * cos(x), 100 * sin(x)));
    }
}

void Game::draw()
{
    SetPixelMode(olc::Pixel::NORMAL);

    // Draw graphics.

    DrawDecal(olc::vf2d(0, 0), backgroundDecal);

    float scale = 0.0333;
    auto centrePoint = scale
                       * olc::vf2d{(float) bulletSprite->width / 2,
                                   (float) bulletSprite->height / 2};

    for (const auto& bullet : bullets) {
        DrawDecal(bullet.position - centrePoint, bulletDecal,
                  olc::vf2d{scale, scale});
    }

    scale = 0.0333;
    centrePoint = scale
                  * olc::vf2d{(float) shooterSprite->width / 2,
                              (float) shooterSprite->height / 2};

    for (const auto& shooter : shooters) {
        DrawDecal(shooter.position - centrePoint, shooterDecal,
                  olc::vf2d{scale, scale});
    }

    scale = 1;
    float gemSize = (float) gemSprite->width / 4;
    centrePoint = scale * olc::vf2d{gemSize / 2, (float) gemSprite->height / 2};

    for (const auto& gem : gems) {
        DrawPartialDecal(gem.position - centrePoint, gemDecal,
                         olc::vf2d{gem.type * gemSize, 0},
                         olc::vf2d{gemSize * scale, gemSprite->height * scale});
    }

    if (shipAlive) {
        scale = 1;
        centrePoint = scale
                      * olc::vf2d{(float) shipSprite->width / 2,
                                  (float) shipSprite->height / 2};

        DrawDecal(shipPosition - centrePoint, shipDecal,
                  olc::vf2d{scale, scale});
    } else if (explosionTimer < explosionFrames / explosionFrameRate) {
        float explosionSize = (float) explosionSprite->width / explosionFrames;
        int explosionFrame = explosionTimer * explosionFrameRate;
        centrePoint = olc::vf2d{explosionSize / 2, explosionSize / 2};

        DrawPartialDecal(
            shipPosition - centrePoint, olc::vf2d{explosionSize, explosionSize},
            explosionDecal, olc::vf2d{explosionFrame * explosionSize, 0},
            olc::vf2d{explosionSize, explosionSize});
    }

    if (fps > 0) {
        auto fpsPosition =
            olc::vi2d(config::WINDOW_WIDTH - 70, config::WINDOW_HEIGHT - 70);
        DrawStringDecal(fpsPosition, "FPS " + std::to_string(fps));
    }
}

bool Game::OnUserDestroy()
{
    std::cout << "Closing game..." << std::endl;
    return true;
}
