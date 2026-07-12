#!/usr/bin/env bash
cd "$(dirname "$0")" && echo "[Current dir: $PWD]"

x=0
while read -r line; do
    ((x++))
    if (( x==10 )); then
        echo "$line"
    fi
done < ./file.txt
