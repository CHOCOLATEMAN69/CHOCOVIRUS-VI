//
// Blitz
// (C) 2019 modeco80.
//
// File:
//		RegUtil.c
//
// Description:
//		Registry abstractions
//

#include "Common.h"
#include <stdlib.h>

void WINAPI BlitzRegWriteString(HKEY Base, const char* Subkey, const char* ValueName, char* Value) {
	HKEY key;
	if (RegOpenKeyExA(Base, Subkey, 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &key) == ERROR_SUCCESS) {
		RegSetValueExA(key, ValueName, 0, REG_SZ, (BYTE*)Value, (strlen(Value) + 1));
		RegCloseKey(key);
	}
}

void WINAPI BlitzRegWriteDword(HKEY Base, const char* Subkey, const char* ValueName, DWORD Value) {
	HKEY key;
	if (RegOpenKeyExA(Base, Subkey, 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &key) == ERROR_SUCCESS) {
		RegSetValueExA(key, ValueName, 0, REG_DWORD, (BYTE*)&Value, sizeof(DWORD));
		RegCloseKey(key);
	}
}