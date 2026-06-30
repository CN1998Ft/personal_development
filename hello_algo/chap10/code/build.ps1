if (-Not (Test-Path ../build))
{
    mkdir ../build | Out-Null
    echo '*' > ../build/.gitignore
}

if (( $args.Count -eq 1) -and ( $args[0] -eq "clean" ))
{
    rm -rf ../build
}
else
{
    pushd ../build | Out-Null
    cl.exe -Zi -FC ../code/chap10.c
    popd | Out-Null
}
