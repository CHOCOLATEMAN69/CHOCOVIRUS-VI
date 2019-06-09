//
// Blitz
// (C) 2019 modeco80.
//
// File:
//		RegUtil.h
//
// Description:
//		Registry abstractions
//
#pragma once
#include "Common.h"

void WINAPI BlitzRegWriteString(HKEY Base, const char* Subkey, const char* ValueName, char* Value);
void WINAPI BlitzRegWriteDword(HKEY Base, const char* Subkey, const char* ValueName, DWORD Value);