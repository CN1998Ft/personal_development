if ( -Not ( Test-Path ./build) )
{
    mkdir ./build
    echo '*' > ./build/.gitignore
}

if ( $args.Count -eq 0 )
{
    pushd build | Out-Null
    cl.exe -Zi -std:c11 ../chap6.c
    popd | Out-Null
}
elseif (( $args.Count -eq 1 ) -and ( $args[0] -eq "clean" ))
{
    rm -Recurse -Force ./build
}
else
{
    pushd build | Out-Null
    cl.exe -Zi -std:c11 ../chap6.c
    popd | Out-Null
}
