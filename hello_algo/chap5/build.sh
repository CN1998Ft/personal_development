#!/usr/bin/env bash
if [[ ! -d ./build ]]; then
    mkdir ./build
    echo '*' > ./build/.gitignore
fi

if [[ $# == 0 ]]; then
    pushd ./build > /dev/null 2>&1
    gcc -Wall -g ../chap5.c
    popd > /dev/null 2>&1
elif [[ $# == 1 && $1 == "clean" ]]; then
    rm -rf ./build
fi
