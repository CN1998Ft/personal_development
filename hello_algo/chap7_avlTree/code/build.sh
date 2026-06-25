#!/usr/bin/env bash
if [[ ! -d ../build ]]; then
    mkdir ../build
    echo '*' > ../build/.gitignore
fi

if [[ $# == 1 && $1 == "clean" ]]; then
    rm ../build
else
    pushd > /dev/null 2>&1
    gcc -Wall -g ../code/avlTree.c
    popd > /dev/null 2>&1
fi
