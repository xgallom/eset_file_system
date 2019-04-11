#!/bin/bash

readonly ROOT_DIR=`pwd`

mkdir -p build/debug

cd build/debug

cmake -DCMAKE_BUILD_TYPE=Debug $ROOT_DIR
make -j

