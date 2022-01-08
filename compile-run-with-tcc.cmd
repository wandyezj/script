@setlocal
@echo off
pushd src
%tools%\programs\tcc\tcc.exe .\script.c -run
popd