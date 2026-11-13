@echo off
setlocal enabledelayedexpansion
cd /D "%~dp0"

if not exist .\build (
    mkdir .\build
    echo * > .\build\.gitignore
)

if "%~1"=="clean" (
    rmdir /S /Q .\build
)

if "%~1"=="" (
    pushd .\build
    cl.exe -Zi -FC ..\chap13.c
    popd
)
