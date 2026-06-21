#!/usr/bin/env bash

if [[ ! -d ./build ]]; then
    mkdir ./build
    echo '*' > ./build/.gitignore
fi

if [[ $# == 1 && $1 == "clean" ]]; then
    rm -rf ./build
else
    pushd ./build
    gcc -Wall -g ../chap7.c
    popd
fi
