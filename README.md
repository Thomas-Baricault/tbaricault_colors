# tbaricault/colors

[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
![C++23](https://img.shields.io/badge/C%2B%2B-23-blue)
![CMake](https://img.shields.io/badge/CMake-3.20%2B-blue)

## Description

This is a C++23 library providing color features like a RGBA color class and a few color constants already defined.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
    - [Download and install](#download-and-install)
    - [Uninstall](#uninstall)
    - [CMake](#cmake)
    - [Include](#include)
    - [Environment](#environment)
- [Documentation](#documentation)
- [Examples](#examples)
    - [Color creation](#color-creation)
- [License](#license)

## Features

- RGBA color class
- Set of color constants

## Requirements

- C++23 or later
- CMake 3.20 or later
- [tbaricault/str](https://github.com/Thomas-Baricault/tbaricault_str)
- [tbaricault/uniconvert](https://github.com/Thomas-Baricault/tbaricault_uniconvert)

## Usage

### Download and install

```bash
git clone https://github.com/Thomas-Baricault/tbaricault_colors.git
cd tbaricault_colors
make install
```

### Uninstall

```bash
make uninstall
```

### CMake

Add the library to your project:

```cmake
find_package(tbaricault_colors REQUIRED)

target_link_libraries(
    my_target
    PRIVATE
        tbaricault::colors
)
```

### Include

```cpp
#include <tbaricault/colors.hpp>
```

### Environment

If you have a custom C++ installation, you can edit the `ENV` variable in the `Makefile` to specify your environment path.

Example on Windows with MSYS2/MinGW64:

```makefile
ENV = C:/msys64/mingw64
```

## Documentation

Read the complete documentation at [https://docs.thomas-baricault.fr/colors](https://docs.thomas-baricault.fr/colors).

## Examples

### Color creation

```cpp
#include <iostream>
#include <tbaricault/colors.hpp>


int main()
{
    tbaricault::colors::Color red(255, 0, 0);
    std::cout << static_cast<std::string>(red) << std::endl;

    tbaricault::colors::Color green = 0xff00ff00;
    std::cout << static_cast<std::string>(green) << std::endl;

    tbaricault::colors::Color blue("#0000ff");
    std::cout << static_cast<std::string>(blue) << std::endl;

    return (0);
}
```

Output:

```text
#ff0000
#00ff00
#0000ff
```

## Roadmap

- Color interpolation

## License

This project is licensed under the MIT License.

See [LICENSE](LICENSE) for details.
