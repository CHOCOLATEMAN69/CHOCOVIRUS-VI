//
// Blitz
// (C) 2019 modeco80.
//
// File:
//		Common.hh
//
// Description:
//		All common definitions and includes for Blitz.
//
#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#ifdef DEBUG
#define DEVELOPMENT
#endif

#ifdef DEVELOPMENT
#include <stdio.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

namespace Blitz {
namespace Util {

	#ifdef DEVELOPMENT
	inline void DebugLog(const char* format, ...) {
		va_list val;
		char* formatted = (char*)calloc(65535, sizeof(char));
		strcat(formatted, "*** Debug: ");
		va_start(val, format);
		vsnprintf(formatted+11, 65519, format, val);
		strcat(formatted, " ***");
		va_end(val);
		puts(formatted);
		free((char*) formatted);
	}
	#else
	inline void DebugLog(const char* format, ...) {
		return;
	}
	#endif

}
}
