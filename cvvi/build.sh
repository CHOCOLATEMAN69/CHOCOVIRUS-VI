#!/bin/sh

#
# build.sh: Build chocovirus without VS
# (on Linux)
#

# Usage:
# ./build.sh (Debug|Release) (x86|x64)

mkdir -p obj/$2/$1
mkdir -p $2/$1

# Hack to use default MinGW-w64 tooling on Linux
# It sucks but it work
if [ "$2" == "x86" ]; then
	CC="i686-w64-mingw32-gcc"
	WINDRES="i686-w64-mingw32-windres -O coff"
	make MSBPROJECTNAME=cvvi MSBCONFIG=$1 MSBPLATFORM=$2 WINDRES=$WINDRES CC=$CC
else
	if [ "$2" == "x64" ]; then
		CC="x86_64-w64-mingw32-gcc"
		WINDRES="x86_64-w64-mingw32-windres -O coff"
		make MSBPROJECTNAME=cvvi MSBCONFIG=$1 MSBPLATFORM=$2 WINDRES=$WINDRES CC=$CC
	fi
fi
