#!/bin/bash

readonly ROOT_DIR=`pwd`

mkdir -p build/release

cd build/release

cmake -DCMAKE_BUILD_TYPE=Release $ROOT_DIR
make -j

