@echo off
setlocal enabledelayedexpansion
cd /D "%~dp0"

if not exist ..\build (
    mkdir ..\build
    echo * > ..\build\.gitignore
)

if "%~1"=="clean" (
    del /S /Q /F ..\build
    rmdir ..\build
)
if "%~1"=="" (
    pushd ..\build
    cl.exe -FC -Zi ..\code\chap12.c
    popd
)
