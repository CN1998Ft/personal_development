if (-Not (Test-Path ./build))
{
    mkdir ./build | Out-Null
    echo '*' > ./build/.gitignore | Out-Null
}

if (($args.Count -eq 1) -and ($args[0] -eq "clean"))
{
    rm -Recurse -Force ./build
}
else
{
    pushd ./build | Out-Null
    cl.exe -Zi -std:c11 ../chap7.c
    popd | Out-Null
}
