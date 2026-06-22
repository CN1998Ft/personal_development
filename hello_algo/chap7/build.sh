#!/usr/bin/env bash

if [[ ! -d ./build ]]; then
    mkdir ./build
    echo '*' > ./build/.gitignore
fi

if [[ $# == 1 && $1 == "clean" ]]; then
    rm -rf ./build
else
    pushd ./build > /dev/null 2>&1
    gcc -Wall -g ../chap7.c
    popd > /dev/null 2>&1
fi
