@echo off
::
:: BUILD.CMD: Build chocovirus without VS
:: (on Windows)
::

:: Usage:
:: BUILD (Debug|Release) (x86|x64)

mkdir obj\%2\%1
mkdir %2\%1
..\mingw\amd64\bin\mingw32-make MSBPROJECTNAME=cvvi MSBCONFIG=%1 MSBPLATFORM=%2 SOLDIR=..\ %3 %4 %5