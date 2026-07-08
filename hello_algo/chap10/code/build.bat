@echo off

pushd ..\build
cl.exe -FC -Zi ..\code\chap10.c
popd
