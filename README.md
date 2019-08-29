# Table of Contents

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [Requirement](#requirement)
- [How to use](#how-to-use)
- [bash running](#bash-running)
- [Reference](#reference)
  - [ConfigMaker](#configmaker)
  - [ConfigManager](#configmanager)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Requirement

* Clang `5.0.0` above environment. [Clang Pre-Built Binaries](http://releases.llvm.org/download.html)
* MinGW-w64 `7.2.0` above with posix thread model. ( windows )
* mingw 7.2.0 `x86_64-w64-mingw32-g++-posix` above. ( linux )

# How to use

1. edit [src/config/config.cpp](src/config/config.cpp), the supported config types are described in [ConfigManager](https://github.com/adahbingee/config-manager)
1. run [gen-config.bat](gen-config.bat)
1. edit [makefile](makefile) as needed
1. compile code use `make` or `mingw32-make`

# bash running

run in different directory, for each directory has its own `config.txt`

```bash
EXE_PATH=D:/workspace/test/out.exe
####################################
cd D:/run-pool/test/01
pwd
$EXE_PATH
####################################
cd D:/run-pool/test/02
pwd
$EXE_PATH
####################################
cd D:/run-pool/test/03
pwd
$EXE_PATH
```

# Reference

## ConfigMaker

[ConfigMaker](https://gist.github.com/adahbingee/33e539264dc4e23dbddb5776bf25a1c1)

A Clang based front-end C++/C preprocessor for auto generating configuration headers.

## ConfigManager

[ConfigManager](https://github.com/adahbingee/config-manager)

A text based configuration manager for C++/C project
