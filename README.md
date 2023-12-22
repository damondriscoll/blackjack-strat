# blackjack-strat

> cli blackjack with basic strategy warnings

A terminal version of Blackjack that enforces [basic strategy](https://en.wikipedia.org/wiki/Blackjack#Basic_strategy), written in C++

## Installation & Usage

[Download the latest release](https://github.com/damondriscoll/blackjack-strat/releases) compatible with your system

You can then run the executable, and the commands are provided in the application

## Manual Installation

Install a [compatible C++ compiler](https://en.wikipedia.org/wiki/List_of_compilers#C++_compilers), and add to PATH

[Install CMake](https://cmake.org/download/)

[Find your compatible generator](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#introduction), and use the string (e.g. "Visual Studio 17 2022") for CMake -G option

```
mkdir build
cmake -S . -B build -G "<GENERATOR STRING IN QUOTES>"
cmake --build build

./build/blackjack.exe
```

## License

[MIT](https://choosealicense.com/licenses/mit/)
