@echo off
setlocal enabledelayedexpansion
cd /D "%~dp0"

if not exist ..\build (
    mkdir ..\build
    echo * > ..\build\.gitignore
)

if "%~1"=="clean" (
    rmdir /s /q ..\build
) else (
    pushd ..\build
    cl.exe -FC -Zi ..\code\chap11.c
    popd
)
