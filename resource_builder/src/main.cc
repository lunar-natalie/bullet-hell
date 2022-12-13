/// @file main.cc
/// @authors The SFC Project Authors
/// @version 1.0
/// @brief Resource builder entry point.
///
/// @section LICENSE
///
/// Copyright (c) 2022 The SFC Project Authors.
///
/// This program is free software: you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with this program. If not, see <https://www.gnu.org/licenses/>.

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
