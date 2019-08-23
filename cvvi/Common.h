//
// Blitz
// (C) 2019 modeco80.
//
// File:
//		Common.h
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

#ifdef DEVELOPMENT
#define BLITZ_DEBUG_LOG(message, ...) printf("*** " message " (%s:%d) ***\n", ##__VA_ARGS__,  __FILE__, __LINE__);
#else
#define BLITZ_DEBUG_LOG(message, ...)
#endif