# Functional Programming in C++

This repository contains code and exercises from my workthrough of [Functional
Programming in
C++](https://www.manning.com/books/functional-programming-in-c-plus-plus) by
Ivan Čukić.

This project uses [CMake](https://cmake.org/) as a build system and
[Conan](https://conan.io/) to manage packages. To be able to build these these
individual projects, you will need these tools installed.

You will also need to add the following conan remotes:

```shell
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
```

Build steps within a directory that contains a `CMakeList.txt` and
`conanfile.txt` on Linux:

```shell
mkdir build && cd build
conan install ..
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
```
