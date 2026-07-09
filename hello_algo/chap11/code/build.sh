#!/usr/bin/env bash
cd "$(dirname "$0")" && echo "[Current dir: $PWD]"

if [[ ! -d ../build ]]; then
    mkdir ../build > /dev/null 2>&1
    echo '*' > ../build/.gitignore
fi

if [[ "$#" == 1 && "$1" == "clean" ]]; then
    rm -rf ../build > /dev/null 2>&1
else
    pushd ../build > /dev/null 2>&1
    gcc -Wall -g ../code/chap11.c
    popd > /dev/null 2>&1
fi
