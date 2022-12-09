/*
 * main.cc
 *
 * Entry point to the Bullet Hell resource builder.
 *
 * Copyright (c) 2022 The SFC Project Authors.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#define OLC_PGE_APPLICATION

#include <cstdlib>

#include <filesystem>
#include <system_error>

#include <olcPixelGameEngine.h>

#include "config.h"

using namespace resource_builder;

using recursive_directory_iterator =
    std::filesystem::recursive_directory_iterator;

int main()
{
    std::error_code pathError;
    auto rootPath = std::filesystem::current_path(pathError);

    std::filesystem::current_path(config::ASSET_DIRNAME);
    auto assetsPath = std::filesystem::current_path();

    olc::ResourcePack* pack = new olc::ResourcePack();
    for (const auto& entry : recursive_directory_iterator(assetsPath)) {
        if (entry.is_regular_file()) {
            pack->AddFile(std::filesystem::relative(entry.path(), assetsPath));
        }
    }

    pack->SavePack(config::OUTPUT_FILENAME, "");

    std::filesystem::current_path(rootPath);

    return EXIT_SUCCESS;
}
