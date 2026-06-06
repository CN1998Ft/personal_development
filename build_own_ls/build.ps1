if ($args.Count -eq 0)
{
    cl.exe -Zi -Fe:own_ls.exe -Fo:own_ls.obj ls.c
}
elseif (($args.Count -eq 1) -and ($args[0] -eq "clean"))
{
    Remove-Item -Force -Recurse *.obj, *.ilk, *.pdb, *.exe
}
