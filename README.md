# Bullet Hell
A prototype GL-based arcade-style shooter. Part of the Sixth Form College
Farnborough C++ (SFC) Project.

## Table of contents
* [Bullet Hell](#bullet-hell)
  * [Table of contents](#table-of-contents)
  * [Documentation](#documentation)
  * [Supported platforms](#supported-platforms)
  * [Requirements](#requirements)
  * [Building](#building)
    * [Requirements](#requirements-1)
    * [VS Code](#vs-code)
    * [Standalone](#standalone)
  * [Running from the development environmennt](#running-from-the-development-environmennt)
    * [VS Code](#vs-code-1)
    * [Standalone](#standalone-1)
  * [Debugging from the development environmennt](#debugging-from-the-development-environmennt)
    * [Requirements](#requirements-2)
    * [VS Code](#vs-code-2)
  * [Installation](#installation)
    * [Uninstallation](#uninstallation)
  * [Structure](#structure)
  * [Coding style](#coding-style)
  * [License](#license)
  * [Library licenses](#library-licenses)
    * [olcPixelGameEngine (OLC-3)](#olcpixelgameengine-olc-3)
  * [Asset licenses](#asset-licenses)

## Documentation
* Documentation and code is written in United States English for integration
  with other programs.
* The documented development envrionments are [Visual Studio Code][www-vs-code]
  and standalone [POSIX shell][www-man-page-sh-1p].
* 'Visual Studio Code' and 'Code - OSS' are collectively abbreviated to VS Code.
* POSIX shell commands to be run as user from the project's root directory are
  denoted by shell code blocks.
* Commands listed in VS Code sections are denoted by 'Workflow' and can be run
  via the [Command Palette][www-vs-code-cmd-palette] or with the specified
  default keyboard shortcuts.

## Supported platforms
* Linux
* Windows 7 or newer
  * Use [MinGW][www-mingw] or [Cygwin][www-cygwin] for the development
    toolchain.
* macOS Catalina (10.15) or newer
  * The development toolchain can be installed using the
    [Xcode command line tools][www-xcode-resources].
  * Required development packages for macOS can be installed using
    [Homebrew][www-homebrew].
  * Note: OpenGL was deprecated in macOS 10.14 and official support from Apple
    has been retired (see [About OpenGL for OS X][www-apple-opengl]).

## Requirements
* [OpenGL][www-opengl] >= 1.0
  * [Mesa][www-mesa] (Recommended implementation for Linux)
* [X11][www-x-org] (Linux)
* [libpng][www-libpng] (Linux, macOS)

## Building
### Requirements
* [C++17][www-open-std-wg21-standards] compiler ([Clang][www-clang] >= 5,
  [GCC][www-gcc] >= 5)
* [CMake][www-cmake] >= 3.10

### VS Code
Required extensions:
* [C/C++][www-vs-code-c-cxx]
* [CMake Tools][www-vs-code-cmake-tools]

Debugging is enabled in the default workflow when building using VS Code.

Workflow:
* Configure the workspace for CMake when prompted, or run the `CMake: Configure`
  command. Use `bullet_hell` as the default target.
* `Tasks: Run Build Task`
  * Default shortcut: `Ctrl/Cmd+Shift+B`

Cleaning the build environment:
* `CMake: Clean` or `CMake: Clean Rebuild`

### Standalone
Configure:
* Debug
  ```shell
  mkdir -p build && \
  cmake -DCMAKE_BUILD_TYPE=Debug -S. -Bbuild
  ```
* Release
  ```shell
  mkdir -p build && \
  cmake -S. -Bbuild
  ```

Build:
```shell
cmake --build build
```

The executable will be written to `build/bullet-hell` and the required resource
pack to `build/resources.dat`.

Cleaning the build environment:
```shell
rm -rf build
```

## Running from the development environmennt
### VS Code
Workflow:
* `CMake: Run Without Debugging`
  * Default shortcut: `Shift+F5`

### Standalone
```shell
build/bullet-hell
```

## Debugging from the development environmennt
### Requirements
* [GDB][www-gdb]

### VS Code
Workflow:
* `CMake: Debug`
  * Default shortcut: `Ctrl/Cmd+F5`

## Installation
See the following instructions to install or uninstall the game after
[building](#building).

Installation and uninstallation to/from a system directory requires sufficient
privelleges (requires `sudo`, and commands to be prefixed with `sudo`, on
Linux/BSD/macOS).

```shell
cmake --install build
```

### Uninstallation
```shell
cmake --build build --target uninstall
```

## Structure
* Source code is located in [`game/src`](game/src/). To add more source files to
  the program, modify the `bullet_hell_SOURCES` variable in
  [`game/CMakeLists.txt`](game/CMakeLists.txt).
* Resources are loaded at runtime from a resource pack. Source assets are
  located in the [`assets`](assets/) directory and are bundled by the source
  code in the [`resource_builder`](resource_builder/) directory at build time.
* C++ source files have the extension `.cc`.
* C/C++ header files have the extension `.h`.
* Headers configured by CMake at build time have the extension `.h.in`.
* Headers shared by both the game and the resource builder are located in
  the [`shared`](shared/) directory.

## Coding style
* Lines should be no longer than 80 characters, unless readability or
  functionality is significantly affected.
* Each source file should begin with a comment formatted as follows:
  ```
  <filename>

  <description>

  Copyright (c) <year> <authors>.

  SPDX-License-Identifier: <identifier>
  ```
* Code should fit the conditions specified in [`.editorconfig`](.editorconfig)
  and [`.clang-format`](.clang-format) (see the
  [ClangFormat documentation][www-clang-format] for more information).

## License
Copyright (c) 2022 The SFC Project Authors.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.

See [`LICENSE`](LICENSE) and [`AUTHORS`](AUTHORS) for more information.

## Library licenses
### olcPixelGameEngine (OLC-3)
Source: [`shared/olcPixelGameEngine.h`](shared/olcPixelGameEngine.h)

Copyright 2018-2022 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions or derivations of source code must retain the above
   copyright notice, this list of conditions and the following disclaimer.

2. Redistributions or derivative works in binary form must reproduce
   the above copyright notice. This list of conditions and the following
   disclaimer must be reproduced in the documentation and/or other
   materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

## Asset licenses
Listed paths are relative to the [`assets`](assets/) directory in the source
distribution, and are relative to the default resource pack at runtime:
* [`background.png`](assets/background.png)
  * Image by [Jeremy Thomas][www-jeremy-thomas]
  * License: [Unsplash][www-unsplash-license]
* [`bullet.png`](assets/bullet.png)
  * Artist: Unknown
  * License: Public domain
* [`explosion.png`](assets/explosion.png)
  * Artist: Unknown
  * License: Unknown / Public domain
* [`gems.png`](assets/gems.png)
  * Artist: Unknown
  * License: Unknown / Public domain
* [`plasma.png`](assets/plasma.png)
  * Artist: Unknown
  * License: Free for non-commercial use
* [`ship.png`](assets/ship.png)
  * Artist: Unknown
  * License: Unknown / Public domain
* [`shooter.png`](assets/shooter.png)
  * Artist: Unknown
  * License: Free for non-commercial use


[www-apple-opengl]: https://developer.apple.com/library/archive/documentation/GraphicsImaging/Conceptual/OpenGL-MacProgGuide/opengl_intro/opengl_intro.html#//apple_ref/doc/uid/TP40001987-CH207-TP9
[www-clang-format]: https://clang.llvm.org/docs/ClangFormat.html
[www-clang]: https://clang.llvm.org/
[www-cmake]: https://cmake.org/
[www-cygwin]: https://www.cygwin.com/
[www-gcc]: https://gcc.gnu.org/
[www-gdb]: https://sourceware.org/gdb/
[www-homebrew]: https://brew.sh/
[www-jeremy-thomas]: https://unsplash.com/@jeremythomasphoto
[www-libpng]: http://www.libpng.org/pub/png/libpng.html
[www-man-page-sh-1p]: https://man7.org/linux/man-pages/man1/sh.1p.html
[www-mesa]: https://mesa3d.org/
[www-mingw]: https://sourceforge.net/projects/mingw/
[www-open-std-wg21-standards]: https://open-std.org/JTC1/SC22/WG21/docs/standards
[www-opengl]: https://www.opengl.org/
[www-unsplash-license]: https://unsplash.com/license
[www-vs-code-c-cxx]: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools
[www-vs-code-cmake-tools]: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools
[www-vs-code-cmd-palette]: https://code.visualstudio.com/docs/getstarted/userinterface#_command-palette
[www-vs-code]: https://code.visualstudio.com/
[www-x-org]: https://www.x.org/wiki/
[www-xcode-resources]: https://developer.apple.com/xcode/resources/
