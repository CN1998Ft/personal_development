if (-Not (Test-Path ../build))
{
    mkdir ../build
    touch ../build/.gitignore && echo '*' > ../build/.gitignore
}

if (($args.Count -eq 1) -and ($args[0] -eq "clean"))
{
    rm -Recurse -Force ../build
}
else
{
    pushd ./build | Out-Null
    cl -Zi ../code/chap4.c
    popd | Out-Null
}
