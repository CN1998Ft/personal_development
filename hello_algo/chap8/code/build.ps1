if (-Not (Test-Path ../build ))
{
    mkdir ../build | Out-Null
    echo '*' > ../build/.gitignore
}

if (($args.Count -eq 1) -and ($args[0] -eq "clean"))
{
    rm -Recurse -Force ../build
}
else
{
    pushd ../build | Out-Null
    cl.exe -FC -Zi ../code/chap8.c
    popd | Out-Null
}
