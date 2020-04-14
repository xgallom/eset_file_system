
# ESET File System Searching Application

A simple Linux command-line program for searching for a string in files

## Usage

```
Usage:
  eset_file_system <target_path> <key>
  eset_file_system <target_path> <key> -p

Arguments:
  <target_path> - A path to search in for the key, can be either a single file, or a directory
                  If it's a directory, it will be scanned recursively
  <key>         - A string literal to search for in the path specified by the target_path

Options:
  -p            - Runs the application in multi-threaded processing mode
                  Note that file indexing will still be done synchronously
```

> **_NOTE:_** On my machine, the application had better results working in the default mode (not **-p**).

## Building

Building requires cmake >=3.2 and c++14, build tested on cmake 3.14.1 and gcc 8.2.1.<br>
Program requires Linux `ftw.h` header for directory indexing.

### Getting the sources

```
git clone git@github.com:xgallom/eset_file_system.git
cd eset_file_system
```

### Release Build

If you don't know which build you want, then you want this one.

```
./build-release.sh
```

Program will be located in `build/release/bin`.

### Debug Build

```
./build-debug.sh
```

Program will be located in `build/debug/bin`.

### Installation

There is currently no install script available.
Just run the application directly, or if you want, you can do

```
sudo cp build/release/bin/eset_file_system /usr/local/bin
```

> **_NOTE:_** This requires to be a sudoer, or to have root privileges

## Documentation

I did not actually document the API, I just generated doxygen to
visualize dependencies, call and inheritance graphs.

Current documentation is also available online [here](http://vesmir.xgallom.sk/docs/eset_file_system).

To build the documentation, just run

```
./build_docs.sh
```

You need to have dot (graphviz) installed and in path to generate documentation.

Documentation will be generated in `docs/html`.

## License

Program is licensed under the MIT license, available [here](LICENSE.md).

Copyright 2019 [Milan Gallo](https://www.github.com/xgallom)

