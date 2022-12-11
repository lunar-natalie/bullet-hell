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

/// @brief Game class containing the main game code; event handlers and runtime
/// properties to run the engine.
class Game : public olc::PixelGameEngine {
public:
    /// @brief Creates a new game instance with the provided program arguments
    /// passed from the program's `main` function.
    /// @param argc Non-negative number of arguments passed to the program from
    /// the environment.
    /// @param argv Pointer to the first element of an array of `argc + 1`
    /// null-terminated argument strings.
    Game(int argc, char* argv[]);

    ////////////////////////////////////////////////////////////////////////////
    // Event hanndlers /////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Called once on application startup to load resources and create
    /// sprites. If the resource pack or any sprites fail to load, messages are
    /// output to stderr and the function returns `false`.
    /// @return `true` to continue the internal engine process, or `false` to
    /// stop the engine and return from the `Start()` routine.
    bool OnUserCreate() override;

    /// @brief Called once per frame to call routines to handle input, perform
    /// game logic and draw to the screen.
    /// @param fElapsedTime Time elapsed in seconds since the last time the
    /// function was called.
    /// @return `true` to continue the internal engine process, or `false` to
    /// stop the engine and return from the `Start()` routine.
    bool OnUserUpdate(float fElapsedTime) override;

    /// @brief Called once on application termination.
    /// @return `true` to continue termination, or `false` to stop the
    /// termination action and continue engine execution.
    bool OnUserDestroy() override;

private:
    ////////////////////////////////////////////////////////////////////////////
    // Per-frame internal routines  ////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Sets action and status properties based on user input.
    void input();

    /// @brief Performs game logic routines, including time-based entity
    /// spawning, positioning, trajectory calculations and other per-frame
    /// operations based on action and status properties.
    void process();

    /// @brief Draws all current objects to the screen.
    void draw();

    ////////////////////////////////////////////////////////////////////////////
    // Loader //////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Loads the resource pack from the first existing configured file
    /// path on the system.
    /// @return `true` if the object was successfully loaded, otherwise
    /// `false` - in which case the value of `resourcePack` will be `nullptr`.
    bool loadResourcePack();

    /// @brief Creates all game sprites using the configured resource names
    /// located in the loaded resource pack.
    /// @return `true` if all sprites were successfully loaded with valid data,
    /// otherwise `false`.
    bool createSprites();

    /// @brief Creates a new sprite.
    /// @param filename Resource filename located within the current resource
    /// pack.
    /// @return Pointer to a new sprite object.
    Sprite* createSprite(const std::string& filename) const;

    /// @brief Creates a new sprite using a partial decal.
    /// @param filename Resource filename located within the current resource
    /// pack.
    /// @return Pointer to a new partial sprite object.
    PartialSprite* createPartialSprite(const std::string& filename) const;

    ////////////////////////////////////////////////////////////////////////////
    // Logic ///////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Sets the `screenWidth` and `screenHeight` properties from the
    /// engine methods.
    void updateScreenDimensions();

    /// @brief Adds the elapsed time for the current frame to the frame timer
    /// and updates the `shouldShowStats` and `fps` properties after each
    /// second.
    void updateFrameProperties();

    /// @brief Resets the current game state, setting frame properties, timers,
    /// trajectories, states and entity flags to their defaults. Re-seeds the
    /// random number generator for spawn routines.
    void reset();

    /// @brief Spawns new entities based on the elapsed time since the last
    /// frame.
    void spawnEntities();

    /// @brief Updates ship acceleration, velocity and position. Uses the ship's
    /// current `direction` flags.
    void updateShipTrajectory();

    /// @brief Updates and checks the ship's reload timer to create new plasma
    /// entities when ready.
    void updateShipFire();

    /// @brief Updates the position of all non-player moving entities based on
    /// the elapsed time since the last frame.
    void updateNonPlayerEntityTrajectories();

    /// @brief Checks if two entities have collided.
    /// @param source First entity.
    /// @param target Second entity.
    /// @return `true` if collided, otherwise `false`.
    bool checkCollision(const Entity* source, const Entity* target) const;

    /// @brief Checks if an entity is within screen bounds.
    /// @param entity Entity to check.
    /// @return `true` if within screen bounds, otherwise `false`.
    bool checkBounds(const Entity* entity) const;

    /// @brief Creates and adds a number of bullets to the bullet entity vector
    /// with a radial velocity pattern centered around an initial position.
    /// @param count Number of bullets.
    /// @param startPosition Initial position for new bullets.
    void addBullets(unsigned int count, olc::vf2d startPosition);

    ////////////////////////////////////////////////////////////////////////////
    // Draw ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Draws an entity to the screen.
    /// @param entity Entity containing the required position data.
    /// @param sprite Sprite representing the entity with its associated
    /// GPU-resident storage.
    /// @param scale Factor by which to multiply the sprite's displayed
    /// dimensions and center point.
    void draw(const Entity* entity, Sprite* sprite, float scale = 1.0f);

    /// @brief Draws an entity with a horiontally positioned partial decal to
    /// the screen. Used to draw entities with multiple frames within the same
    /// sprite decal, positioned sequentially along the horizontal axis of
    /// the original image.
    /// @param entity Entity containing the required position data.
    /// @param sprite Sprite representing the entity with its associated
    /// GPU-resident storage, dimensions for each frame in its decal, and number
    /// of frames in its decal.
    /// @param frameIndex Index of the desired frame to draw from the sprite's
    /// partial decal.
    /// @param scale Factor by which to multiply the sprite's displayed
    /// dimensions and center point.
    void drawHorizontalPartial(const Entity* entity, PartialSprite* sprite,
                               unsigned int frameIndex, float scale = 1.0f);

    ////////////////////////////////////////////////////////////////////////////
    // Properties //////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Path to the running program.
    std::filesystem::path execPath;

    // Flags

    bool shouldReset;
    bool shouldExit;
    bool shouldShowStats;

    // Dimensions, in pixels

    int32_t screenWidth;
    int32_t screenHeight;

    // Frame

    float elapsedTime;
    float frameTimer;
    unsigned int elapsedFrames;
    unsigned int fps;

    /// @brief Resource pack from which sprite assets are loaded.
    olc::ResourcePack* resourcePack;

    // Entities

    Ship* ship;
    std::vector<Bullet*> bullets;
    std::vector<Shooter*> shooters;
    std::vector<Gem*> gems;
    std::vector<Explosion*> explosions;
    std::vector<Plasma*> plasmas;

    // Miscellaneous

    Sprite* backgroundSprite;
};

} // namespace bullet_hell

#endif // BULLET_HELL_GAME_H
