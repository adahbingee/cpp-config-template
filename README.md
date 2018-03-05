# Requirement
* Clang `5.0.0` above environment. [Clang Pre-Built Binaries](http://releases.llvm.org/download.html)
* MinGW-w64 `7.2.0` above. ( windows )
* mingw 7.2.0 `x86_64-w64-mingw32-g++-posix` above. ( linux )

# How to use

1. edit [`src/config/config.cpp`](src/config/config.cpp), the supported config types are described in [ConfigManager](https://github.com/adahbingee/config-manager)
1. run [`gen-config.bat`](gen-config.bat)
1. edit [`makefile`](makefile) as needed
1. compile code use `make` or `mingw32-make`

# Reference

## ConfigMaker

[ConfigMaker](https://gist.github.com/adahbingee/33e539264dc4e23dbddb5776bf25a1c1)

A Clang based front-end C++/C preprocessor for auto generating configuration headers.

## ConfigManager

[ConfigManager](https://github.com/adahbingee/config-manager)

A text based configuration manager for C++/C project
