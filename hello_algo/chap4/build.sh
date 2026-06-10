#!/usr/bin/env bash
build()
{
    pushd ./build > /dev/null 2>&1
    gcc -Wall -g ../chap4.c
    popd > /dev/null 2>&1
}

if [[ ! -d ./build ]]; then
    mkdir ./build
    touch ./build/.gitignore && echo '*' > ./build/.gitignore
fi

if [[ $# == 0 ]]; then
    build
elif [[ $# == 1 && $1 == "clean" ]]; then
    # pushd ./build > /dev/null 2>&1
    # rm -rf *.out *.dSYM
    # popd > /dev/null 2>&1
    rm -rf ./build
fi
